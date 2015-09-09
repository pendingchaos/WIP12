#include "scripting/bytecodegen.h"

#include "scripting/vm/bytecode.h"

namespace scripting
{
static const uint8_t opPushFloat = (uint8_t)Opcode::PushFloat;
static const uint8_t opPushInteger = (uint8_t)Opcode::PushInt;
static const uint8_t opPushString = (uint8_t)Opcode::PushString;
static const uint8_t opPushNil = (uint8_t)Opcode::PushNil;
static const uint8_t opPushBoolean = (uint8_t)Opcode::PushBoolean;
static const uint8_t opPushFunction = (uint8_t)Opcode::PushFunc;
static const uint8_t opPushObject = (uint8_t)Opcode::PushObject;
static const uint8_t opLoadVar = (uint8_t)Opcode::LoadVar;
static const uint8_t opStoreVar = (uint8_t)Opcode::StoreVar;
static const uint8_t opGetMember = (uint8_t)Opcode::GetMember;
static const uint8_t opSetMember = (uint8_t)Opcode::SetMember;
static const uint8_t opStackPop = (uint8_t)Opcode::StackPop;
static const uint8_t opAdd = (uint8_t)Opcode::Add;
static const uint8_t opSubtract = (uint8_t)Opcode::Subtract;
static const uint8_t opMultiply = (uint8_t)Opcode::Multiply;
static const uint8_t opDivide = (uint8_t)Opcode::Divide;
static const uint8_t opBoolAnd = (uint8_t)Opcode::BoolAnd;
static const uint8_t opBoolOr = (uint8_t)Opcode::BoolOr;
static const uint8_t opBitAnd = (uint8_t)Opcode::BitAnd;
static const uint8_t opBitOr = (uint8_t)Opcode::BitOr;
static const uint8_t opBitXOr = (uint8_t)Opcode::BitXOr;
static const uint8_t opLess = (uint8_t)Opcode::Less;
static const uint8_t opGreater = (uint8_t)Opcode::Greater;
static const uint8_t opEqual = (uint8_t)Opcode::Equal;
static const uint8_t opLessEqual = (uint8_t)Opcode::LessEqual;
static const uint8_t opGreaterEqual = (uint8_t)Opcode::GreaterEqual;
static const uint8_t opShiftLeft = (uint8_t)Opcode::LeftShift;
static const uint8_t opShiftRight = (uint8_t)Opcode::RightShift;
static const uint8_t opBoolNot = (uint8_t)Opcode::BoolNot;
static const uint8_t opBitNot = (uint8_t)Opcode::BitNot;
static const uint8_t opReturn = (uint8_t)Opcode::Return;
static const uint8_t opThrow = (uint8_t)Opcode::Throw;
static const uint8_t opDelVar = (uint8_t)Opcode::DelVar;
static const uint8_t opJump = (uint8_t)Opcode::Jump;
static const uint8_t opJumpIf = (uint8_t)Opcode::JumpIf;
static const uint8_t opCall = (uint8_t)Opcode::Call;
static const uint8_t opCallMethod = (uint8_t)Opcode::CallMethod;
static const uint8_t opGetArg = (uint8_t)Opcode::GetArg;

bool isBuiltin(ASTNode *node, const String& name)
{
    if (node->type != ASTNode::Call)
    {
        return false;
    }

    if (((CallNode *)node)->nodes.getCount() == 0)
    {
        return false;
    }

    if (((CallNode *)node)->nodes[0]->type != ASTNode::Identifier)
    {
        return false;
    }

    IdentifierNode *id = (IdentifierNode *)((CallNode *)node)->nodes[0];

    if (id->names.getCount() != 1)
    {
        return false;
    }

    return id->names[0] == name;
}

bool _generateBytecode(ASTNode *node, ResizableData& data);

void _generateOp(CallNode *node, ResizableData& data, uint8_t opcode)
{
    if (node->nodes.getCount() < 3)
    {
        THROW(ByteCodeGenException, "Must have at least two arguments.");
    }

    for (size_t i = 1; i < node->nodes.getCount(); ++i)
    {
        if (not _generateBytecode(node->nodes[i], data))
        {
            THROW(ByteCodeGenException, "Argument does not evaluate to anything");
        }
    }

    for (size_t i = 1; i < node->nodes.getCount()-1; ++i)
    {
        data.append(1, &opcode);
    }
}

void _generateLROp(CallNode *node, ResizableData& data, uint8_t opcode)
{
    if (node->nodes.getCount() != 3)
    {
        THROW(ByteCodeGenException, "Must have only two arguments.");
    }

    if (not _generateBytecode(node->nodes[1], data))
    {
        THROW(ByteCodeGenException, "Argument does not evaluate to anything");
    }

    if (not _generateBytecode(node->nodes[2], data))
    {
        THROW(ByteCodeGenException, "Argument does not evaluate to anything");
    }

    data.append(1, &opcode);
}

void _generateSingleArgOp(CallNode *node, ResizableData& data, uint8_t opcode)
{
    if (node->nodes.getCount() != 2)
    {
        THROW(ByteCodeGenException, "Must have only one argument.");
    }

    if (not _generateBytecode(node->nodes[1], data))
    {
        THROW(ByteCodeGenException, "Argument does not evaluate to anything");
    }

    data.append(1, &opcode);
}

void _generateObject(CallNode *call, ResizableData& data)
{
    if (call->nodes.getCount()%2 != 1)
    {
        THROW(ByteCodeGenException, "obj/class must have an even number of arguments.");
    }

    for (size_t i = 0; i < (call->nodes.getCount()-1)/2; ++i)
    {
        ASTNode *name_ = call->nodes[i*2+1];
        ASTNode *value = call->nodes[i*2+2];

        if (name_->type != ASTNode::Identifier)
        {
            THROW(ByteCodeGenException, "Object/class member name must be an identifier.");
        }

        IdentifierNode *name = (IdentifierNode *)name_;

        if (name->names.getCount() != 1)
        {
            THROW(ByteCodeGenException, "Invalid object/class member name.");
        }

        if (not _generateBytecode(value, data))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }

        uint32_t length = TO_LE_U32(name->names[0].getLength());

        data.append(1, &opPushString);
        data.append(4, &length);
        data.append(name->names[0].getLength(), name->names[0].getData());
    }

    data.append(1, &opPushObject);

    for (size_t i = 0; i < (call->nodes.getCount()-1)/2; ++i)
    {
        data.append(1, &opSetMember);
    }
}

/*TODO:
Implement these:
    import
    int
    float
    boolean
    get

Finish some TODOs.*/
bool _generateBytecode(ASTNode *node, ResizableData& data) //Returns true if it pushed something onto the stack.
{
    switch (node->type)
    {
    case ASTNode::Float:
    {
        data.append(1, &opPushFloat);
        data.append(8, &((FloatNode *)node)->value);
        return true;
    }
    case ASTNode::Integer:
    {
        data.append(1, &opPushInteger);

        int64_t v = TO_LE_S64(((IntegerNode *)node)->value);

        data.append(8, &v);
        return true;
    }
    case ASTNode::Identifier:
    {
        IdentifierNode *id = (IdentifierNode *)node;

        if (id->names.getCount() == 1 and id->names[0] == "true")
        {
            uint8_t v = 1;

            data.append(1, &opPushBoolean);
            data.append(1, &v);
        } else if (id->names.getCount() == 1 and id->names[0] == "false")
        {
            uint8_t v = 0;

            data.append(1, &opPushBoolean);
            data.append(1, &v);
        } else if (isBuiltin(id, "nil"))
        {
            data.append(1, &opPushNil);
        } else
        {
            String str = id->names[0];
            uint32_t length = TO_LE_U32(str.getLength());

            data.append(1, &opPushString);
            data.append(4, &length);
            data.append(str.getLength(), str.getData());

            data.append(1, &opLoadVar);

            for (size_t i = 1; i < id->names.getCount(); ++i)
            {
                str = id->names[i];
                length = TO_LE_U32(str.getLength());

                data.append(1, &opPushString);
                data.append(4, &length);
                data.append(str.getLength(), str.getData());

                data.append(1, &opGetMember);
            }
        }
        return true;
    }
    case ASTNode::Statements:
    {
        List<ASTNode *> statements = ((StatementsNode *)node)->statements;

        for (size_t i = 0; i < statements.getCount(); ++i)
        {
            if (_generateBytecode(statements[i], data))
            {
                data.append(1, &opStackPop);
            }
        }
        return false;
    }
    case ASTNode::String:
    {
        String str = ((StringNode *)node)->content;
        uint32_t length = TO_LE_U32(str.getLength());

        data.append(1, &opPushString);
        data.append(4, &length);
        data.append(str.getLength(), str.getData());
        return true;
    }
    case ASTNode::Call:
    {
        CallNode *call = (CallNode *)node;

        if (isBuiltin(call, "="))
        {
            if (call->nodes.getCount() != 3)
            {
                THROW(ByteCodeGenException, "= takes two arguments");
            }

            if (call->nodes[1]->type != ASTNode::Identifier)
            {
                THROW(ByteCodeGenException, "Only identifiers can be assigned to");
            }

            IdentifierNode *id = (IdentifierNode *)call->nodes[1];

            if (not _generateBytecode(call->nodes[2], data))
            {
                THROW(ByteCodeGenException, "Argument does not evaluate to anything");
            }

            if (id->names.getCount() > 1)
            {
                String str = id->names[id->names.getCount()-1];
                uint32_t length = TO_LE_U32(str.getLength());
                data.append(1, &opPushString);
                data.append(4, &length);
                data.append(str.getLength(), str.getData());

                str = id->names[0];
                length = TO_LE_U32(str.getLength());
                data.append(1, &opPushString);
                data.append(4, &length);
                data.append(str.getLength(), str.getData());

                data.append(1, &opLoadVar);

                for (size_t i = 1; i < id->names.getCount()-1; ++i)
                {
                    str = id->names[i];
                    length = TO_LE_U32(str.getLength());

                    data.append(1, &opPushString);
                    data.append(4, &length);
                    data.append(str.getLength(), str.getData());

                    data.append(1, &opGetMember);
                }

                data.append(1, &opSetMember);
            } else
            {
                const String& str = id->names[0];
                uint32_t length = TO_LE_U32(str.getLength());

                data.append(1, &opPushString);
                data.append(4, &length);
                data.append(str.getLength(), str.getData());

                data.append(1, &opStoreVar);
            }

            return false;
        } else if (isBuiltin(call, "class"))
        {
            _generateObject(call, data);

            int64_t argCount = TO_LE_S64(1);
            data.append(1, &opPushInteger);
            data.append(8, &argCount);

            data.append(1, &opPushString);
            uint32_t length = TO_LE_U32(10);
            data.append(4, &length);
            data.append(10, "__classify");
            data.append(1, &opLoadVar);

            data.append(1, &opCall);

            return true;
        } else if (isBuiltin(call, "function"))
        {
            if (call->nodes.getCount() < 2)
            {
                THROW(ByteCodeGenException, "Missing args for function.");
            }

            if (call->nodes[1]->type != ASTNode::Call)
            {
                THROW(ByteCodeGenException, "Function arguments must be in ( and ).");
            }

            const List<ASTNode *>& args = ((CallNode *)call->nodes[1])->nodes;
            List<String> argNames;
            String varArgName;
            bool varArgs = false;

            for (size_t i = 0; i < args.getCount(); ++i)
            {
                if (args[i]->type != ASTNode::Identifier)
                {
                    THROW(ByteCodeGenException, "Invalid function argument.");
                }

                IdentifierNode *id = (IdentifierNode *)args[i];

                if (id->names.getCount() == 1)
                {
                    argNames.append(id->names[0]);
                } else if (id->names.getCount() == 4)
                {
                    if (id->names[0] == '.' and id->names[1] == '.' and id->names[2] == '.')
                    {
                        if (i != args.getCount()-1)
                        {
                            THROW(ByteCodeGenException, "Ellipsis argument can only be the last argument.")
                        }

                        varArgName = id->names[3];
                        varArgs = true;
                    } else
                    {
                        THROW(ByteCodeGenException, "Invalid function argument.");
                    }
                } else
                {
                    THROW(ByteCodeGenException, "Invalid function argument.");
                }
            }

            ResizableData bodyData;

            if (not varArgs)
            {
                //TODO: Argument count checking
            }

            for (size_t i = 0; i < argNames.getCount(); ++i)
            {
                int64_t index = TO_LE_S64(i);
                bodyData.append(1, &opPushInteger);
                bodyData.append(8, &index);

                bodyData.append(1, &opGetArg);

                uint32_t length = TO_LE_U32(argNames[i].getLength());

                bodyData.append(1, &opPushString);
                bodyData.append(4, &length);
                bodyData.append(argNames[i].getLength(), argNames[i].getData());

                bodyData.append(1, &opStoreVar);
            }

            for (size_t i = 2; i < call->nodes.getCount(); ++i)
            {
                if (_generateBytecode(call->nodes[i], bodyData))
                {
                    bodyData.append(1, &opStackPop);
                }
            }

            data.append(1, &opPushFunction);

            uint32_t size = TO_LE_U32(bodyData.getSize());
            data.append(4, &size);
            data.append(bodyData);

            return true;
        } else if (isBuiltin(call, "if"))
        {
            List<size_t> endJumpOffsetsPos;

            for (size_t i = 0; i < (call->nodes.getCount()-1)/2; ++i)
            {
                ASTNode *cond = call->nodes[i*2+1];
                ASTNode *body = call->nodes[i*2+2];

                ResizableData bodyData;
                if (_generateBytecode(body, bodyData))
                {
                    bodyData.append(1, &opStackPop);
                }
                bodyData.append(1, &opJump);

                bodyData.resize(bodyData.getSize()+4);

                if (not _generateBytecode(cond, data))
                {
                    THROW(ByteCodeGenException, "Condition does not evaluate to anything");
                }
                data.append(1, &opJumpIf);
                int32_t off = 0;
                data.append(4, &off);
                off = bodyData.getSize();
                data.append(4, &off);

                endJumpOffsetsPos.append(data.getSize()+bodyData.getSize());

                data.append(bodyData);
            }

            //Else
            if ((call->nodes.getCount()-1)%2 != 0)
            {
                ASTNode *body = call->nodes[call->nodes.getCount()-1];

                if (_generateBytecode(body, data))
                {
                    data.append(1, &opStackPop);
                }
            }

            for (size_t i = 0; i < endJumpOffsetsPos.getCount(); ++i)
            {
                uint8_t *p = ((uint8_t *)data.getData())+endJumpOffsetsPos[i];

                *((int32_t *)p) = data.getSize() - (endJumpOffsetsPos[i] + 4);
            }

            return false;
        } else if (isBuiltin(call, "throw"))
        {
            if (call->nodes.getCount() != 2)
            {
                THROW(ByteCodeGenException, "Must have only one argument.");
            }

            if (_generateBytecode(call->nodes[1], data))
            {
                THROW(ByteCodeGenException, "Argument does not evaluate to anything");
            }

            data.append(1, &opThrow);

            return false;
        } else if (isBuiltin(call, "scope"))
        {
            //TODO
        } else if (isBuiltin(call, "with"))
        {
            //TODO
        } else if (isBuiltin(call, "obj"))
        {
            _generateObject(call, data);

            return true;
        } else if (isBuiltin(call, "delmem"))
        {
            if (call->nodes.getCount() != 2)
            {
                THROW(ByteCodeGenException, "delmem takes one argument.");
            }

            if (call->nodes[1]->type != ASTNode::Identifier)
            {
                THROW(ByteCodeGenException, "Only identifiers can be deleted.");
            }

            IdentifierNode *id = (IdentifierNode *)call->nodes[1];

            if (id->names.getCount() != 1)
            {
                //TODO: Support
                THROW(ByteCodeGenException, "Deleting members not supported.")
            }

            String str = id->names[0];
            uint32_t length = TO_LE_U32(str.getLength());

            data.append(1, &opPushString);
            data.append(4, &length);
            data.append(str.getLength(), str.getData());

            data.append(1, &opDelVar);

            return false;
        } else if (isBuiltin(call, "+"))
        {
            _generateOp(call, data, opAdd);
            return true;
        } else if (isBuiltin(call, "-"))
        {
            _generateOp(call, data, opSubtract);
            return true;
        } else if (isBuiltin(call, "*"))
        {
            _generateOp(call, data, opMultiply);
            return true;
        } else if (isBuiltin(call, "/"))
        {
            _generateOp(call, data, opDivide);
            return true;
        } else if (isBuiltin(call, "<"))
        {
            _generateLROp(call, data, opLess);
            return true;
        } else if (isBuiltin(call, ">"))
        {
            _generateLROp(call, data, opGreater);
            return true;
        } else if (isBuiltin(call, "=="))
        {
            _generateLROp(call, data, opEqual);
            return true;
        } else if (isBuiltin(call, "<="))
        {
            _generateLROp(call, data, opLessEqual);
            return true;
        } else if (isBuiltin(call, ">="))
        {
            _generateLROp(call, data, opGreaterEqual);
            return true;
        } else if (isBuiltin(call, "and"))
        {
            _generateOp(call, data, opBoolAnd);
            return true;
        } else if (isBuiltin(call, "or"))
        {
            _generateOp(call, data, opBoolOr);
            return true;
        } else if (isBuiltin(call, "not"))
        {
            _generateSingleArgOp(call, data, opBoolNot);
            return true;
        } else if (isBuiltin(call, "&&"))
        {
            _generateOp(call, data, opBitAnd);
            return true;
        } else if (isBuiltin(call, "||"))
        {
            _generateOp(call, data, opBitOr);
            return true;
        } else if (isBuiltin(call, "^"))
        {
            _generateOp(call, data, opBitXOr);
            return true;
        } else if (isBuiltin(call, "~"))
        {
            _generateSingleArgOp(call, data, opBitNot);
            return true;
        } else if (isBuiltin(call, "<<"))
        {
            _generateLROp(call, data, opShiftLeft);
            return true;
        } else if (isBuiltin(call, ">>"))
        {
            _generateLROp(call, data, opShiftRight);
            return true;
        } else if (isBuiltin(call, "try"))
        {
            //TODO
        } else if (isBuiltin(call, "return"))
        {
            if (call->nodes.getCount() != 2)
            {
                THROW(ByteCodeGenException, "Must have only one argument.");
            }

            if (not _generateBytecode(call->nodes[1], data))
            {
                THROW(ByteCodeGenException, "Return value does not evaluate to anything.");
            }

            data.append(1, &opReturn);
            return false;
        } else if (isBuiltin(call, "isinstance"))
        {
            if (call->nodes.getCount() != 3)
            {
                THROW(ByteCodeGenException, "Must have two arguments.");
            }

            if (not _generateBytecode(call->nodes[1], data))
            {
                THROW(ByteCodeGenException, "Value does not evaluate to anything.");
            }
            uint32_t length = TO_LE_U32(15);
            data.append(1, &opPushString);
            data.append(4, &length);
            data.append(15, "__classTypeID__");
            data.append(1, &opGetMember);

            if (not _generateBytecode(call->nodes[2], data))
            {
                THROW(ByteCodeGenException, "Value does not evaluate to anything.");
            }
            length = TO_LE_U32(10);
            data.append(1, &opPushString);
            data.append(4, &length);
            data.append(10, "__typeID__");
            data.append(1, &opGetMember);

            data.append(1, &opEqual);
        } else if (isBuiltin(call, "while"))
        {
            if (call->nodes.getCount() < 2)
            {
                THROW(ByteCodeGenException, "Must have at least two arguments.");
            }

            ASTNode *cond = call->nodes[1];

            ResizableData data2;

            for (size_t i = 2; i < call->nodes.getCount(); ++i)
            {
                if (_generateBytecode(call->nodes[i], data2))
                {
                    data2.append(1, &opStackPop);
                }
            }

            ResizableData condData;

            if (not _generateBytecode(cond, condData))
            {
                THROW(ByteCodeGenException, "While condition does not evaluate to anything.");
            }

            int32_t off = -(data2.getSize() + 14 + condData.getSize());
            data2.append(1, &opJump);
            data2.append(4, &off);

            off = data2.getSize();
            condData.append(1, &opJumpIf);
            int32_t off2 = 0;
            condData.append(4, &off2);
            condData.append(4, &off);

            data.append(condData);
            data.append(data2);
        } else if (isBuiltin(call, "meth"))
        {
            if (call->nodes.getCount() < 3)
            {
                THROW(ByteCodeGenException, "Must have at least two arguments.");
            }

            for (size_t i = call->nodes.getCount()-1; i >= 3; --i)
            {
                if (not _generateBytecode(call->nodes[i], data))
                {
                    THROW(ByteCodeGenException, "Argument in function call does not evaluate to anything.");
                }
            }

            int64_t argCount = TO_LE_S64(call->nodes.getCount()-3);

            data.append(1, &opPushInteger);
            data.append(8, &argCount);

            if (call->nodes[2]->type != ASTNode::Identifier)
            {
                THROW(ByteCodeGenException, "Method name must be a identifier.");
            }

            IdentifierNode *method = (IdentifierNode *)call->nodes[2];

            if (method->names.getCount() != 1)
            {
                THROW(ByteCodeGenException, "Invalid method name.");
            }

            uint32_t length = TO_LE_U32(method->names[0].getLength());

            data.append(1, &opPushString);
            data.append(4, &length);
            data.append(method->names[0].getLength(), method->names[0].getData());

            if (not _generateBytecode(call->nodes[1], data))
            {
                THROW(ByteCodeGenException, "Object in method call does not evaluate to anything.");
            }

            data.append(1, &opCallMethod);
            return true;
        } else
        {
            if (call->nodes.getCount() < 1)
            {
                THROW(ByteCodeGenException, "Must have at least one argument.");
            }

            for (size_t i = call->nodes.getCount()-1; i >= 1; --i)
            {
                if (not _generateBytecode(call->nodes[i], data))
                {
                    THROW(ByteCodeGenException, "Argument in function call does not evaluate to anything.");
                }
            }

            int64_t argCount = TO_LE_S64(call->nodes.getCount()-1);

            data.append(1, &opPushInteger);
            data.append(8, &argCount);

            if (not _generateBytecode(call->nodes[0], data))
            {
                THROW(ByteCodeGenException, "Function in function call does not evaluate to anything");
            }

            data.append(1, &opCall);
            return true;
        }

        break;
    }
    }

    return false;
}

ResizableData generateBytecode(ASTNode *ast)
{
    ResizableData data;

    if (_generateBytecode(ast, data))
    {
        data.append(1, &opStackPop);
    }

    return data;
}
}
