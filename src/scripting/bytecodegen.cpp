#include "scripting/bytecodegen.h"

#include "scripting/vm/bytecode.h"
#include "scripting/parser/ast.h"

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
static const uint8_t opModulo = (uint8_t)Opcode::Modulo;
static const uint8_t opBoolAnd = (uint8_t)Opcode::BoolAnd;
static const uint8_t opBoolOr = (uint8_t)Opcode::BoolOr;
static const uint8_t opBitAnd = (uint8_t)Opcode::BitAnd;
static const uint8_t opBitOr = (uint8_t)Opcode::BitOr;
static const uint8_t opBitXOr = (uint8_t)Opcode::BitXOr;
static const uint8_t opLess = (uint8_t)Opcode::Less;
static const uint8_t opGreater = (uint8_t)Opcode::Greater;
static const uint8_t opEqual = (uint8_t)Opcode::Equal;
static const uint8_t opNotEqual = (uint8_t)Opcode::NotEqual;
static const uint8_t opLessEqual = (uint8_t)Opcode::LessEqual;
static const uint8_t opGreaterEqual = (uint8_t)Opcode::GreaterEqual;
static const uint8_t opShiftLeft = (uint8_t)Opcode::LeftShift;
static const uint8_t opShiftRight = (uint8_t)Opcode::RightShift;
static const uint8_t opBoolNot = (uint8_t)Opcode::BoolNot;
static const uint8_t opBitNot = (uint8_t)Opcode::BitNot;
static const uint8_t opReturn = (uint8_t)Opcode::Return;
static const uint8_t opThrow = (uint8_t)Opcode::Throw;
static const uint8_t opJump = (uint8_t)Opcode::Jump;
static const uint8_t opJumpIf = (uint8_t)Opcode::JumpIf;
static const uint8_t opCall = (uint8_t)Opcode::Call;
static const uint8_t opGetArg = (uint8_t)Opcode::GetArg;
static const uint8_t opStackDup = (uint8_t)Opcode::StackDup;

static bool _generateBytecode(ASTNode *node, ResizableData& data, List<Str>& strings);

static void generateLROp(LROpNode *node, ResizableData& data, uint8_t opcode, List<Str>& strings)
{
    if (not _generateBytecode(node->right, data, strings))
    {
        THROW(ByteCodeGenException, "Argument does not evaluate to anything");
    }

    if (not _generateBytecode(node->left, data, strings))
    {
        THROW(ByteCodeGenException, "Argument does not evaluate to anything");
    }

    data.append(1, &opcode);
}

static void pushString(Str str, ResizableData& data, List<Str>& strings)
{
    int index = strings.find(str);

    if (index == -1)
    {
        uint32_t index2 = TO_LE_U32(strings.getCount());
        data.append(1, &opPushString);
        data.append(4, &index2);
        strings.append(str);
    } else
    {
        uint32_t index2 = TO_LE_U32(index);
        data.append(1, &opPushString);
        data.append(4, &index2);
    }
}

static void generateObject(ASTNode *node, ResizableData& data, List<Str>& strings)
{
    List<ASTNode *> nodes;

    if (node->type == ASTNode::Assign)
    {
        nodes.append(node);
    } else if (node->type == ASTNode::Statements)
    {
        nodes = ((StatementsNode *)node)->statements;
    } else
    {
        THROW(ByteCodeGenException, "Invalid class members.");
    }

    for (auto assign_ : nodes)
    {
        if (assign_->type != ASTNode::Assign)
        {
            THROW(ByteCodeGenException, "Invalid class member.");
        }

        LROpNode *assign = (LROpNode *)assign_;

        if (not _generateBytecode(assign->right, data, strings))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }

        Str memberName = ((IdentifierNode *)assign->left)->name;

        pushString(memberName, data, strings);
    }

    data.append(1, &opPushObject);

    for (size_t i = 0; i < nodes.getCount(); ++i)
    {
        data.append(1, &opSetMember);
    }
}

//Returns true if it pushed something onto the stack.
static bool _generateBytecode(ASTNode *node, ResizableData& data, List<Str>& strings)
{
    switch (node->type)
    {
    case ASTNode::Add:
    {
        generateLROp((LROpNode *)node, data, opAdd, strings);
        return true;
    }
    case ASTNode::Subtract:
    {
        generateLROp((LROpNode *)node, data, opSubtract, strings);
        return true;
    }
    case ASTNode::Multiply:
    {
        generateLROp((LROpNode *)node, data, opMultiply, strings);
        return true;
    }
    case ASTNode::Divide:
    {
        generateLROp((LROpNode *)node, data, opDivide, strings);
        return true;
    }
    case ASTNode::Modulo:
    {
        generateLROp((LROpNode *)node, data, opModulo, strings);
        return true;
    }
    case ASTNode::Less:
    {
        generateLROp((LROpNode *)node, data, opLess, strings);
        return true;
    }
    case ASTNode::Greater:
    {
        generateLROp((LROpNode *)node, data, opGreater, strings);
        return true;
    }
    case ASTNode::Equal:
    {
        generateLROp((LROpNode *)node, data, opEqual, strings);
        return true;
    }
    case ASTNode::NotEqual:
    {
        generateLROp((LROpNode *)node, data, opNotEqual, strings);
        return true;
    }
    case ASTNode::LessEqual:
    {
        generateLROp((LROpNode *)node, data, opLessEqual, strings);
        return true;
    }
    case ASTNode::GreaterEqual:
    {
        generateLROp((LROpNode *)node, data, opGreaterEqual, strings);
        return true;
    }
    case ASTNode::BoolAnd:
    {
        generateLROp((LROpNode *)node, data, opBoolAnd, strings);
        return true;
    }
    case ASTNode::BoolOr:
    {
        generateLROp((LROpNode *)node, data, opBoolOr, strings);
        return true;
    }
    case ASTNode::BitAnd:
    {
        generateLROp((LROpNode *)node, data, opBitAnd, strings);
        return true;
    }
    case ASTNode::BitOr:
    {
        generateLROp((LROpNode *)node, data, opBitOr, strings);
        return true;
    }
    case ASTNode::BitXOr:
    {
        generateLROp((LROpNode *)node, data, opBitXOr, strings);
        return true;
    }
    case ASTNode::LeftShift:
    {
        generateLROp((LROpNode *)node, data, opShiftLeft, strings);
        return true;
    }
    case ASTNode::RightShift:
    {
        generateLROp((LROpNode *)node, data, opShiftRight, strings);
        return true;
    }
    case ASTNode::Call:
    {
        CallNode *cNode = (CallNode *)node;

        for (ptrdiff_t i = cNode->args.getCount()-1; i >= 0; --i)
        {
            if (not _generateBytecode(cNode->args[i], data, strings))
            {
                THROW(ByteCodeGenException, "Argument in function call does not evaluate to anything.");
            }
        }

        int64_t argCount = TO_LE_S64(cNode->args.getCount());

        data.append(1, &opPushInteger);
        data.append(8, &argCount);

        if (not _generateBytecode(cNode->callable, data, strings))
        {
            THROW(ByteCodeGenException, "Function in function call does not evaluate to anything");
        }

        data.append(1, &opCall);
        return true;
    }
    case ASTNode::GetMember:
    {
        LROpNode *lrOp = (LROpNode *)node;

        if (not _generateBytecode(lrOp->left, data, strings))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }

        //TODO: This would not work with a[b]
        if (lrOp->right->type == ASTNode::Identifier)
        {
            Str name = ((IdentifierNode *)lrOp->right)->name;

            pushString(name, data, strings);
        } else
        {
            if (not _generateBytecode(lrOp->right, data, strings))
            {
                THROW(ByteCodeGenException, "Value does not evaluate to anything");
            }
        }

        data.append(1, &opGetMember);
        return true;
    }
    case ASTNode::GetMethod:
    {
        LROpNode *lrOp = (LROpNode *)node;

        if (not _generateBytecode(lrOp->left, data, strings))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }

        data.append(1, &opStackDup);

        if (lrOp->right->type == ASTNode::Identifier)
        {
            Str name = ((IdentifierNode *)lrOp->right)->name;

            pushString(name, data, strings);
        } else
        {
            THROW(ByteCodeGenException, "Invalid method name.");
        }

        data.append(1, &opGetMember);

        int64_t argCount = TO_LE_S64(2);
        data.append(1, &opPushInteger);
        data.append(8, &argCount);

        pushString("__methodify", data, strings);
        data.append(1, &opLoadVar);

        data.append(1, &opCall);
        return true;
    }
    case ASTNode::Assign:
    {
        LROpNode *lrOp = (LROpNode *)node;

        //TODO: Allow stuff like "a.b.c = 5;"
        if (lrOp->left->type == ASTNode::Identifier)
        {
            if (not _generateBytecode(lrOp->right, data, strings))
            {
                THROW(ByteCodeGenException, "Value does not evaluate to anything");
            }

            IdentifierNode *id = (IdentifierNode *)lrOp->left;

            pushString(id->name, data, strings);

            data.append(1, &opStoreVar);
        } else if (lrOp->left->type == ASTNode::GetMember)
        {
            LROpNode *getMember = (LROpNode *)lrOp->left;

            if (getMember->left->type != ASTNode::Identifier)
            {
                THROW(ByteCodeGenException, "Invalid identifier.");
            }

            if (getMember->right->type != ASTNode::Identifier)
            {
                THROW(ByteCodeGenException, "Invalid member name.");
            }

            if (not _generateBytecode(lrOp->right, data, strings))
            {
                THROW(ByteCodeGenException, "Value does not evaluate to anything");
            }

            Str key = ((IdentifierNode *)getMember->right)->name;
            pushString(key, data, strings);

            Str obj = ((IdentifierNode *)getMember->left)->name;
            pushString(obj, data, strings);
            data.append(1, &opLoadVar);

            data.append(1, &opSetMember);
        }

        return false;
    }
    case ASTNode::Negate:
    {
        SingleOperandNode *op = (SingleOperandNode *)node;

        if (not _generateBytecode(op->operand, data, strings))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }

        int64_t i = 0;
        data.append(1, &opPushInteger);
        data.append(8, &i);

        data.append(1, &opSubtract);
        return true;
    }
    case ASTNode::BoolNot:
    {
        SingleOperandNode *op = (SingleOperandNode *)node;
        if (not _generateBytecode(op->operand, data, strings))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }
        data.append(1, &opBoolNot);
        return true;
    }
    case ASTNode::BitNot:
    {
        SingleOperandNode *op = (SingleOperandNode *)node;
        if (not _generateBytecode(op->operand, data, strings))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }
        data.append(1, &opBoolNot);
        return true;
    }
    case ASTNode::Nil:
    {
        data.append(1, &opPushNil);
        return true;
    }
    case ASTNode::True:
    {
        uint8_t v = 1;
        data.append(1, &opPushBoolean);
        data.append(1, &v);
        return true;
    }
    case ASTNode::False:
    {
        uint8_t v = 0;
        data.append(1, &opPushBoolean);
        data.append(1, &v);
        return true;
    }
    case ASTNode::Integer:
    {
        data.append(1, &opPushInteger);
        data.append(8, &((IntegerNode *)node)->value);
        return true;
    }
    case ASTNode::Float:
    {
        data.append(1, &opPushFloat);
        data.append(8, &((FloatNode *)node)->value);
        return true;
    }
    case ASTNode::String:
    {
        StringNode *str = (StringNode *)node;

        pushString(str->content, data, strings);
        return true;
    }
    case ASTNode::Throw:
    {
        SingleOperandNode *op = (SingleOperandNode *)node;
        if (not _generateBytecode(op->operand, data, strings))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }
        data.append(1, &opThrow);
        return false;
    }
    case ASTNode::Return:
    {
        SingleOperandNode *op = (SingleOperandNode *)node;
        if (not _generateBytecode(op->operand, data, strings))
        {
            THROW(ByteCodeGenException, "Value does not evaluate to anything");
        }
        data.append(1, &opReturn);
        return false;
    }
    case ASTNode::Identifier:
    {
        IdentifierNode *id = (IdentifierNode *)node;

        pushString(id->name, data, strings);
        data.append(1, &opLoadVar);
        return true;
    }
    case ASTNode::Function: //TODO: Variadic arguments //TODO: Argument count checking
    {
        FunctionNode *func = (FunctionNode *)node;

        ResizableData bodyData;

        for (size_t i = 0; i < func->args.getCount(); ++i)
        {
            int64_t index = TO_LE_S64(i);
            bodyData.append(1, &opPushInteger);
            bodyData.append(8, &index);

            bodyData.append(1, &opGetArg);

            pushString(func->args[i], bodyData, strings);

            bodyData.append(1, &opStoreVar);
        }

        if (_generateBytecode(func->body, bodyData, strings))
        {
            bodyData.append(1, &opStackPop);
        }

        data.append(1, &opPushFunction);

        uint32_t size = TO_LE_U32(bodyData.getSize());
        data.append(4, &size);
        data.append(bodyData);
        return true;
    }
    case ASTNode::Class:
    {
        SingleOperandNode *op = (SingleOperandNode *)node;
        generateObject(op->operand, data, strings);

        int64_t argCount = TO_LE_S64(1);
        data.append(1, &opPushInteger);
        data.append(8, &argCount);

        pushString("__classify", data, strings);
        data.append(1, &opLoadVar);

        data.append(1, &opCall);

        return true;
    }
    case ASTNode::Statements:
    {
        for (auto statement : ((StatementsNode *)node)->statements)
        {
            if (_generateBytecode(statement, data, strings))
            {
                data.append(1, &opStackPop);
            }
        }
        return false;
    }
    case ASTNode::If:
    {
        IfNode *ifNode = (IfNode *)node;

        List<size_t> endJumpOffsetsPos;

        List<ASTNode *> conds;
        List<ASTNode *> bodies;

        conds.append(ifNode->ifCond);
        bodies.append(ifNode->if_);

        for (size_t i = 0; i < ifNode->elifs.getCount(); ++i)
        {
            conds.append(ifNode->elifConds[i]);
            bodies.append(ifNode->elifs[i]);
        }

        for (size_t i = 0; i < conds.getCount(); ++i)
        {
            ASTNode *cond = conds[i];
            ASTNode *body = bodies[i];

            ResizableData bodyData;
            if (_generateBytecode(body, bodyData, strings))
            {
                bodyData.append(1, &opStackPop);
            }
            bodyData.append(1, &opJump);

            bodyData.resize(bodyData.getSize()+4);

            if (not _generateBytecode(cond, data, strings))
            {
                THROW(ByteCodeGenException, "Condition does not evaluate to anything");
            }
            data.append(1, &opJumpIf);
            int32_t off = 0;
            data.append(4, &off);
            off = bodyData.getSize();
            data.append(4, &off);

            endJumpOffsetsPos.append(data.getSize()+bodyData.getSize()-4);

            data.append(bodyData);
        }

        //Else
        if (ifNode->else_ != nullptr)
        {
            if (_generateBytecode(ifNode->else_, data, strings))
            {
                data.append(1, &opStackPop);
            }
        }

        for (auto pos : endJumpOffsetsPos)
        {
            uint8_t *p = ((uint8_t *)data.getData()) + pos;

            *((int32_t *)p) = data.getSize() - (pos + 4);
        }

        return false;
    }
    case ASTNode::While:
    {
        WhileNode *whileNode = (WhileNode *)node;

        ResizableData condData;
        if (not _generateBytecode(whileNode->cond, condData, strings))
        {
            THROW(ByteCodeGenException, "While condition does not evaluate to anything.");
        }

        ResizableData data2;
        if (_generateBytecode(whileNode->block, data2, strings))
        {
            data2.append(1, &opStackPop);
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
        return false;
    }
    case ASTNode::Comma:
    {
        THROW(ByteCodeGenException, "Trying to generate bytecode for Comma AST node.");
    }
    case ASTNode::StatementSplit:
    {
        THROW(ByteCodeGenException, "Trying to generate bytecode for StatementSplit AST node.");
    }
    case ASTNode::TryExcept:
    {
        //TODO
        THROW(ByteCodeGenException, "Try/except has not been implemented yet.");
        return false;
    }
    }
}

Bytecode generateBytecode(ASTNode *ast)
{
    ResizableData data;
    List<Str> strings;

    if (_generateBytecode(ast, data, strings))
    {
        data.append(1, &opStackPop);
    }

    Bytecode bc(data);
    bc.strings = strings;

    return bc;
}
}
