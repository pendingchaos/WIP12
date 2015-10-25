#include <cstring>
#include <iostream>

#include "scripting/script.h"

#include "application.h"
#include "logging.h"
#include "backtrace.h"
#include "error.h"
#include "filesystem.h"
#include "globals.h"
#include "platform.h"
#include "math/matrix4x4.h"

void run(const char *dir)
{
    {
        Application app_(dir);

        setApplication(&app_);

        Script *script = resMgr->load<Script>("resources/scripts/main.rkt");
        app->setNextScript(script);
        script->release();

        app->mainloop();
    }

    setApplication(nullptr);
}

int unsafeMain(int argc, const char *argv[])
{
    if (argc >= 2)
    {
        run(argv[1]);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include "scripting/vm/bytecode.h"
#include "scripting/vm/types.h"
#include "scripting/parser.h"
#include "scripting/bytecodegen.h"
#include "scripting/bindings.h"
#include "scripting/disasm.h"

#include <iostream>

/*void printAST(size_t indent, scripting::ASTNode *node)
{
    std::cout << "--------------------------------\n";

    for (size_t i = 0; i < indent; ++i)
    {
        std::cout << "    ";
    }

    switch (node->type)
    {
    case scripting::ASTNode::Call:
    {
        scripting::CallNode *cnode = (scripting::CallNode *)node;
        std::cout << "Call:\n";

        for (size_t i = 0; i < cnode->nodes.getCount(); ++i)
        {
            printAST(indent+1, cnode->nodes[i]);
        }
        break;
    }
    case scripting::ASTNode::Identifier:
    {
        std::cout << "Identifier:\n";

        for (size_t j = 0; j <= indent; ++j)
        {
            std::cout << "    ";
        }

        scripting::IdentifierNode *ids = (scripting::IdentifierNode *)node;

        for (size_t j = 0; j < ids->names.getCount(); ++j)
        {
            std::cout << ids->names[j].getData() << ' ';
        }

        std::cout << '\n';
        break;
    }
    case scripting::ASTNode::Integer:
    {
        std::cout << "Integer:\n";

        for (size_t j = 0; j <= indent; ++j)
        {
            std::cout << "    ";
        }

        std::cout << ((scripting::IntegerNode *)node)->value << std::endl;
        break;
    }
    case scripting::ASTNode::Float:
    {
        std::cout << "Float:\n";

        for (size_t j = 0; j <= indent; ++j)
        {
            std::cout << "    ";
        }

        std::cout << ((scripting::FloatNode *)node)->value << std::endl;
        break;
    }
    case scripting::ASTNode::String:
    {
        std::cout << "String:\n";

        for (size_t j = 0; j <= indent; ++j)
        {
            std::cout << "    ";
        }

        std::cout << ((scripting::StringNode *)node)->content.getData() << std::endl;
        break;
    }
    case scripting::ASTNode::Statements:
    {
        std::cout << "Statements:\n";

        scripting::StatementsNode *snode = (scripting::StatementsNode *)node;

        for (size_t i = 0; i < snode->statements.getCount(); ++i)
        {
            printAST(indent+1, snode->statements[i]);
        }
        break;
    }
    }
}*/

static void printAST(size_t indent, scripting::ASTNode *node)
{
    std::cout << "--------------------------------\n";

    for (size_t i = 0; i < indent; ++i)
    {
        std::cout << "    ";
    }

    switch (node->type)
    {
    case scripting::ASTNode::Assign:
    {
        std::cout << "Assign:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Add:
    {
        std::cout << "Add:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Subtract:
    {
        std::cout << "Subtract:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Multiply:
    {
        std::cout << "Multiply:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Divide:
    {
        std::cout << "Divide:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Modulo:
    {
        std::cout << "Modulo:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Less:
    {
        std::cout << "Less:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Greater:
    {
        std::cout << "Greater:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Equal:
    {
        std::cout << "Equal:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::NotEqual:
    {
        std::cout << "NotEqual:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::LessEqual:
    {
        std::cout << "LessEqual:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::GreaterEqual:
    {
        std::cout << "GreaterEqual:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::BoolAnd:
    {
        std::cout << "BoolAnd:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::BoolOr:
    {
        std::cout << "BoolOr:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::BitAnd:
    {
        std::cout << "BitAnd:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::BitOr:
    {
        std::cout << "BitOr:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::BitXOr:
    {
        std::cout << "BitXOr:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::LeftShift:
    {
        std::cout << "LeftShift:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::RightShift:
    {
        std::cout << "RightShift:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Comma:
    {
        std::cout << "Comma (should not be here):\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::StatementSplit:
    {
        std::cout << "StatementSplit (should not be here):\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::GetMember:
    {
        std::cout << "GetMember:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::GetMethod:
    {
        std::cout << "GetMethod:\n";
        printAST(indent+1, ((scripting::LROpNode *)node)->left);
        printAST(indent+1, ((scripting::LROpNode *)node)->right);
        break;
    }
    case scripting::ASTNode::Call:
    {
        scripting::CallNode *cnode = (scripting::CallNode *)node;
        std::cout << "Call:\n";

        printAST(indent+1, cnode->callable);

        for (size_t i = 0; i < cnode->args.getCount(); ++i)
        {
            printAST(indent+1, cnode->args[i]);
        }
        break;
    }
    case scripting::ASTNode::BoolNot:
    {
        std::cout << "BoolNot:\n";
        printAST(indent+1, ((scripting::SingleOperandNode *)node)->operand);
        break;
    }
    case scripting::ASTNode::BitNot:
    {
        std::cout << "BitNot:\n";
        printAST(indent+1, ((scripting::SingleOperandNode *)node)->operand);
        break;
    }
    case scripting::ASTNode::Class:
    {
        std::cout << "Class:\n";
        printAST(indent+1, ((scripting::SingleOperandNode *)node)->operand);
        break;
    }
    case scripting::ASTNode::Throw:
    {
        std::cout << "Throw:\n";
        printAST(indent+1, ((scripting::SingleOperandNode *)node)->operand);
        break;
    }
    case scripting::ASTNode::Return:
    {
        std::cout << "Return:\n";
        printAST(indent+1, ((scripting::SingleOperandNode *)node)->operand);
        break;
    }
    case scripting::ASTNode::Negate:
    {
        std::cout << "Negate:\n";
        printAST(indent+1, ((scripting::SingleOperandNode *)node)->operand);
        break;
    }
    case scripting::ASTNode::Function:
    {
        std::cout << "Function:\n";

        scripting::FunctionNode *fnode = (scripting::FunctionNode *)node;

        for (size_t i = 0; i < fnode->args.getCount(); ++i)
        {
            for (size_t j = 0; j <= indent; ++j)
            {
                std::cout << "    ";
            }

            std::cout << fnode->args[i].getData() << '\n';
        }

        printAST(indent+1, fnode->body);
        break;
    }
    case scripting::ASTNode::TryExcept:
    {
        std::cout << "TryExcept:\n";

        scripting::TryExceptNode *tenode = (scripting::TryExceptNode *)node;

        printAST(indent+1, tenode->try_);
        printAST(indent+1, tenode->except);
        break;
    }
    case scripting::ASTNode::If:
    {
        std::cout << "If:\n";

        scripting::IfNode *inode = (scripting::IfNode *)node;

        printAST(indent+1, inode->ifCond);
        printAST(indent+1, inode->if_);

        for (size_t i = 0; i < inode->elifs.getCount(); ++i)
        {
            printAST(indent+1, inode->elifConds[i]);
            printAST(indent+1, inode->elifs[i]);
        }

        if (inode->else_ != nullptr)
        {
            printAST(indent+1, inode->else_);
        }
        break;
    }
    case scripting::ASTNode::While:
    {
        std::cout << "While:\n";

        scripting::WhileNode *whileNode = (scripting::WhileNode *)node;

        printAST(indent+1, whileNode->cond);
        printAST(indent+1, whileNode->block);
        break;
    }
    case scripting::ASTNode::Identifier:
    {
        std::cout << "Identifier:\n";

        for (size_t j = 0; j <= indent; ++j)
        {
            std::cout << "    ";
        }

        std::cout << ((scripting::IdentifierNode *)node)->name.getData() << std::endl;
        break;
    }
    case scripting::ASTNode::Integer:
    {
        std::cout << "Integer:\n";

        for (size_t j = 0; j <= indent; ++j)
        {
            std::cout << "    ";
        }

        std::cout << ((scripting::IntegerNode *)node)->value << std::endl;
        break;
    }
    case scripting::ASTNode::Float:
    {
        std::cout << "Float:\n";

        for (size_t j = 0; j <= indent; ++j)
        {
            std::cout << "    ";
        }

        std::cout << ((scripting::FloatNode *)node)->value << std::endl;
        break;
    }
    case scripting::ASTNode::String:
    {
        std::cout << "String:\n";

        for (size_t j = 0; j <= indent; ++j)
        {
            std::cout << "    ";
        }

        std::cout << ((scripting::StringNode *)node)->content.getData() << std::endl;
        break;
    }
    case scripting::ASTNode::Statements:
    {
        std::cout << "Statements:\n";

        scripting::StatementsNode *snode = (scripting::StatementsNode *)node;

        for (size_t i = 0; i < snode->statements.getCount(); ++i)
        {
            printAST(indent+1, snode->statements[i]);
        }
        break;
    }
    case scripting::ASTNode::True:
    {
        std::cout << "True\n";
        break;
    }
    case scripting::ASTNode::False:
    {
        std::cout << "False\n";
        break;
    }
    case scripting::ASTNode::Nil:
    {
        std::cout << "Nil\n";
        break;
    }
    }
}

Matrix4x4 fastMul(const Matrix4x4& a, const Matrix4x4& b)
{
    Matrix4x4 result(Matrix4x4::NoInit);

    __m128 otherRow0 __attribute__((aligned(16))) = _mm_loadu_ps(b.data[0]);
    __m128 otherRow1 __attribute__((aligned(16))) = _mm_loadu_ps(b.data[1]);
    __m128 otherRow2 __attribute__((aligned(16))) = _mm_loadu_ps(b.data[2]);
    __m128 otherRow3 __attribute__((aligned(16))) = _mm_loadu_ps(b.data[3]);

    __m128 newRow0 __attribute__((aligned(16))) = _mm_mul_ps(otherRow0, _mm_set1_ps(a.data[0][0]));
    newRow0 = _mm_add_ps(newRow0, _mm_mul_ps(otherRow1, _mm_set1_ps(a.data[0][1])));
    newRow0 = _mm_add_ps(newRow0, _mm_mul_ps(otherRow2, _mm_set1_ps(a.data[0][2])));
    newRow0 = _mm_add_ps(newRow0, _mm_mul_ps(otherRow3, _mm_set1_ps(a.data[0][3])));

    __m128 newRow1 __attribute__((aligned(16))) = _mm_mul_ps(otherRow0, _mm_set1_ps(a.data[1][0]));
    newRow1 = _mm_add_ps(newRow1, _mm_mul_ps(otherRow1, _mm_set1_ps(a.data[1][1])));
    newRow1 = _mm_add_ps(newRow1, _mm_mul_ps(otherRow2, _mm_set1_ps(a.data[1][2])));
    newRow1 = _mm_add_ps(newRow1, _mm_mul_ps(otherRow3, _mm_set1_ps(a.data[1][3])));

    __m128 newRow2 __attribute__((aligned(16))) = _mm_mul_ps(otherRow0, _mm_set1_ps(a.data[2][0]));
    newRow2 = _mm_add_ps(newRow2, _mm_mul_ps(otherRow1, _mm_set1_ps(a.data[2][1])));
    newRow2 = _mm_add_ps(newRow2, _mm_mul_ps(otherRow2, _mm_set1_ps(a.data[2][2])));
    newRow2 = _mm_add_ps(newRow2, _mm_mul_ps(otherRow3, _mm_set1_ps(a.data[2][3])));

    __m128 newRow3 __attribute__((aligned(16))) = _mm_mul_ps(otherRow0, _mm_set1_ps(a.data[3][0]));
    newRow3 = _mm_add_ps(newRow3, _mm_mul_ps(otherRow1, _mm_set1_ps(a.data[3][1])));
    newRow3 = _mm_add_ps(newRow3, _mm_mul_ps(otherRow2, _mm_set1_ps(a.data[3][2])));
    newRow3 = _mm_add_ps(newRow3, _mm_mul_ps(otherRow3, _mm_set1_ps(a.data[3][3])));

    _mm_store_ps(result.data[0], newRow0);
    _mm_store_ps(result.data[1], newRow1);
    _mm_store_ps(result.data[2], newRow2);
    _mm_store_ps(result.data[3], newRow3);

    return result;
}

extern "C"
{
int main(int argc, const char *argv[])
{
    #if 0
    ResizableData data;

    int64_t a = 40;
    double b = 2.0;
    uint8_t trueValue = 1;
    uint8_t falseValue = 0;
    int32_t jumpSuccess = -11;
    int32_t jumpFailure = 0;
    int32_t jumpOffset = -5;
    int32_t stackMoveSrc = -1;
    int32_t stackMoveDst = 0;
    int32_t tryEndEnd = 30;
    uint8_t opPushI = (uint8_t)scripting::Opcode::PushInt;
    uint8_t opPushF = (uint8_t)scripting::Opcode::PushFloat;
    uint8_t opPushS = (uint8_t)scripting::Opcode::PushString;
    uint8_t opPushO = (uint8_t)scripting::Opcode::PushObject;
    uint8_t opPushB = (uint8_t)scripting::Opcode::PushBoolean;
    uint8_t opPushN = (uint8_t)scripting::Opcode::PushNil;
    uint8_t opPushL = (uint8_t)scripting::Opcode::PushList;
    uint8_t opPushE = (uint8_t)scripting::Opcode::PushException;
    uint8_t opPushFunc = (uint8_t)scripting::Opcode::PushFunc;
    uint8_t opGetType = (uint8_t)scripting::Opcode::GetType;
    uint8_t opStackMove = (uint8_t)scripting::Opcode::StackMove;
    uint8_t opAdd = (uint8_t)scripting::Opcode::Add;
    uint8_t opStoreVar = (uint8_t)scripting::Opcode::StoreVar;
    uint8_t opLoadVar = (uint8_t)scripting::Opcode::LoadVar;
    uint8_t opGetMem = (uint8_t)scripting::Opcode::GetMember;
    uint8_t opSetMem = (uint8_t)scripting::Opcode::SetMember;
    uint8_t opDeref = (uint8_t)scripting::Opcode::Deref;
    uint8_t opJumpIf = (uint8_t)scripting::Opcode::JumpIf;
    uint8_t opJump = (uint8_t)scripting::Opcode::Jump;
    uint8_t opStackRemove = (uint8_t)scripting::Opcode::StackRemove;
    uint8_t opStackCopy = (uint8_t)scripting::Opcode::StackCopy;
    uint8_t opCreateRef = (uint8_t)scripting::Opcode::CreateRef;
    uint8_t opDeleteRef = (uint8_t)scripting::Opcode::DeleteRef;
    uint8_t opReplaceRef = (uint8_t)scripting::Opcode::ReplaceRef;
    uint8_t opTry = (uint8_t)scripting::Opcode::Try;
    uint8_t opEndTry = (uint8_t)scripting::Opcode::EndTry;
    uint8_t opThrow = (uint8_t)scripting::Opcode::Throw;
    uint8_t excType = (uint8_t)scripting::ExcType::TypeError;
    uint8_t opIsRefValid = (uint8_t)scripting::Opcode::IsRefValid;
    uint8_t opReturn = (uint8_t)scripting::Opcode::Return;
    uint8_t opCall = (uint8_t)scripting::Opcode::Call;
    uint32_t length = 4;

    /*data.append(1, &opPushI);
    data.append(8, &a);

    data.append(1, &opPushF);
    data.append(8, &b);

    data.append(1, &opAdd);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");

    data.append(1, &opStoreVar);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");

    data.append(1, &opLoadVar);
    data.append(1, &opDeref);*/

    /*//Create the object.
    data.append(1, &opPushO);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opStoreVar);

    //Set the member.
    data.append(1, &opPushI); //The value
    data.append(8, &a);
    data.append(1, &opPushS); //The name
    data.append(4, &length);
    data.append(4, "3.14");

    data.append(1, &opPushS); //Get the object.
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opLoadVar);
    data.append(1, &opSetMem);

    data.append(1, &opPushS); //The name
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opStoreVar);

    //Get the member.
    data.append(1, &opPushS); //Get the object.
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opLoadVar);

    data.append(1, &opPushS); //The name
    data.append(4, &length);
    data.append(4, "3.14");

    data.append(1, &opGetMem);*/

    /*data.append(1, &opPushB);
    data.append(1, &trueValue);

    data.append(1, &opJumpIf);
    data.append(4, &jumpSuccess);
    data.append(4, &jumpFailure);*/

    /*data.append(1, &opJump);
    data.append(4, &jumpOffset);*/

    /*data.append(1, &opPushE);
    data.append(1, &excType);
    data.append(4, &length);
    data.append(4, "eror");*/

    /*data.append(1, &opPushI);
    data.append(8, &a);

    data.append(1, &opPushF);
    data.append(8, &b);

    data.append(1, &opStackMove);
    data.append(4, &stackMoveSrc);
    data.append(4, &stackMoveDst);*/

    /*data.append(1, &opPushI);
    data.append(8, &a);

    data.append(1, &opPushF);
    data.append(8, &b);

    data.append(1, &opStackRemove);
    data.append(4, &stackMoveSrc);

    data.append(1, &opStackRemove);
    data.append(4, &stackMoveDst);*/

    /*data.append(1, &opPushI);
    data.append(8, &a);

    data.append(1, &opStackCopy);
    data.append(4, &stackMoveSrc);
    data.append(4, &stackMoveDst);*/

    /*data.append(1, &opPushN);
    data.append(1, &opCreateRef);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opStoreVar);

    data.append(1, &opPushI);
    data.append(8, &a);
    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opLoadVar);
    data.append(1, &opDeref);
    data.append(1, &opReplaceRef);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opLoadVar);
    data.append(1, &opDeref);
    data.append(1, &opDeref);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "!40-");
    data.append(1, &opStoreVar);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opLoadVar);
    data.append(1, &opDeref);
    data.append(1, &opDeleteRef);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opLoadVar);
    data.append(1, &opDeref);
    data.append(1, &opIsRefValid);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opLoadVar);
    data.append(1, &opIsRefValid);*/

    /*data.append(1, &opPushI);
    data.append(8, &a);
    data.append(1, &opGetType);

    data.append(1, &opPushF);
    data.append(8, &b);
    data.append(1, &opGetType);

    data.append(1, &opPushB);
    data.append(1, &trueValue);
    data.append(1, &opGetType);

    data.append(1, &opPushN);
    data.append(1, &opGetType);

    data.append(1, &opPushO);
    data.append(1, &opGetType);

    //Memory leak.
    data.append(1, &opPushN);
    data.append(1, &opCreateRef);
    data.append(1, &opGetType);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "3.14");
    data.append(1, &opGetType);

    data.append(1, &opPushL);
    data.append(1, &opGetType);

    data.append(1, &opPushE);
    data.append(1, &excType);
    data.append(4, &length);
    data.append(4, "eror");
    data.append(1, &opGetType);*/

    /*data.append(1, &opTry);
    data.append(4, &tryEndEnd);
    {
        data.append(1, &opPushS);
        data.append(4, &length);
        data.append(4, "fal1");

        data.append(1, &opPushE);
        data.append(1, &excType);
        data.append(4, &length);
        data.append(4, "eror");

        data.append(1, &opThrow);

        data.append(1, &opPushS);
        data.append(4, &length);
        data.append(4, "fal2");

        data.append(1, &opEndTry);
    }

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "suc1");*/

    /*uint32_t funcSize = 10;
    int64_t argCount = 0;

    data.append(1, &opPushI);
    data.append(8, &argCount);

    data.append(1, &opPushFunc);
    data.append(4, &funcSize);

    data.append(1, &opPushS);
    data.append(4, &length);
    data.append(4, "func");
    data.append(1, &opReturn);

    data.append(1, &opCall);*/

    int64_t argCount = 1;
    uint32_t funcLen = 5;
    uint32_t helloLen = 13;

    data.append(1, &opPushS);
    data.append(4, &helloLen);
    data.append(13, "Hello world!\n");

    data.append(1, &opPushI);
    data.append(8, &argCount);

    data.append(1, &opPushS);
    data.append(4, &funcLen);
    data.append(5, "print");

    data.append(1, &opLoadVar);
    data.append(1, &opDeref);

    data.append(1, &opCall);

    scripting::Bytecode code(data);

    scripting::Engine *engine = NEW(scripting::Engine);

    engine->getGlobalVars().set("print", engine->getRefMgr()->createNativeFunction(print));

    {
        scripting::Context *context = NEW(scripting::Context, engine);

        scripting::Ref result = context->run(code, List<scripting::Ref>());

        engine->getRefMgr()->destroy(context, result);
    }

    DELETE(engine);
    #elif 0
    try
    {
        scripting::ASTNode *ast = scripting::parse("(+ (Float2 5.0 2.0) (Float2 3.0 4.0))"/*"(meth (Float2Ref 5.0 2.0) refset (Float2))"*/);

        printAST(0, ast);

        ResizableData data = generateBytecode(ast);

        std::cout << "Compiled program takes up " << data.getSize() << " bytes\n";

        DELETE(ast);

        scripting::Bytecode code(data);

        scripting::Engine *engine = NEW(scripting::Engine);

        scripting::registerBindings(engine);

        engine->getGlobalVars().set("print", scripting::createNativeFunction(print));

        {
            scripting::Context *context = NEW(scripting::Context, engine);

            try
            {
                scripting::Value *result = context->run(code, List<scripting::Value *>());

                scripting::destroy(context, result);
            } catch (scripting::UnhandledExcException& e)
            {
                scripting::Value *exc = e.getException();

                std::cout << "Unhandled script exception: ";

                if (exc->type == scripting::ValueType::Exception)
                {
                    std::cout << ((scripting::ExceptionValue *)exc)->error.getData();
                }
            }

            DELETE(context);
        }

        DELETE(engine);
    } catch (scripting::ParseException& e)
    {
        std::printf("Failed to parse input at %zu:%zu: %s\n", e.scriptLine, e.scriptColumn, e.message);
    } catch (scripting::ByteCodeGenException& e)
    {
        std::printf("Failed to generate bytecode: %s\n", e.message);
    }
    #elif 0
    try
    {
        scripting::ASTNode *ast = scripting::parse(
        #if 0
        "(+ 30.5 (+ 0.5 2e+1) (+ 0b11 0x6))"
        #elif 0
        "(print \"\x48ullo World!\n\")"
        #elif 0
        "(+ 1 2) (+ 3 4)"
        #else
"(= some_module (import \"some_module.???\"))\n"
"\n"
"(= vec2 (class\n"
"          (= __init__ (function (self ...args)\n"
"                        (if (== args.len 0) ((= self.x 0.0)\n"
"                                             (= self.y 0.0))\n"
"                            (== args.len 1) ((= self.x (float (get args 0)))\n"
"                                             (= self.y (float (get args 0))))\n"
"                            (== args.len 2) ((= self.x (float (get args 0)))\n"
"                                             (= self.y (float (get args 1))))\n"
"                            (throw (ValueException \"vec2.__init__ takes 0, 1 or 2 arguments.\")))))\n"
"\n"
"          (= __add__ (function (self other)\n"
"                       (if (isinstance other vec2) \n"
"                           (vec2 (+ self.x other.x) (+ self.y other.y)))\n"
"                           (vec2 (+ self.x other) (+ self.y other))))))\n"
"          \n"
"          hello (function (self)\n"
"                  (print "Hello!")))))\n"
"\n"
"(scope \n"
"  (= variable 42))\n"
"\n"
"(some_module.some_function)\n"
"\n"
"(= adder (function (x x2 x3 x4)\n"
"           (with (function () (+ inc inc2 x3 x4))\n"
"                 (x inc) x4 (x2 inc2) x3)))\n"
"\n"
"(= obj (newobj (= member1 5)\n"
"               (= member1 (+ member1 1))\n"
"               (= temp \"Hello world!\")\n"
"               (= member2 temp)\n"
"               (delvar temp)))\n"
"\n"
"(= counter_r (newref))\n"
"(= vec2_1_r (newref))\n"
"(:= vec2_1_r (vec2))\n"
"\n"
"(= vec2_2_r (newref))\n"
"(:= vec2_2_r (vec2 *vec2_1_r))\n"
"\n"
"(= vec_1_r.x (+ vec2_1_r.x 1))\n"
"(:= counter_r 5)\n"
"\n"
"(delref vec2_1_r)\n"
"(delref vec2_2_r)\n"
"(delref counter_r)\n"
        #endif
        );

        printAST(0, ast);

        DELETE(ast);
    } catch (scripting::ParseException& e)
    {
        std::printf("Failed to parse input at %zu:%zu: %s\n", e.scriptLine, e.scriptColumn, e.message);
    }
    #elif 0
    try
    {
        scripting::ASTNode *ast = scripting::parse(
"some_module = import(\"some_module.rkt\");\n"
"\n"
"vec2 = class {\n"
"    __init__ = function(self) {\n"
"        if args.len == 0 {\n"
"            self.x = 0.0;\n"
"            self.y = 0.0;\n"
"        } elif args.len == 1 {\n"
"            self.x = float(args[0]);\n"
"            self.y = float(args[0]);\n"
"        } elif args.len == 2 {\n"
"            self.x = float(args[0]);\n"
"            self.y = float(args[1]);\n"
"        } else {\n"
"            throw ValueException(\"vec2.__init__ takes 0, 1 or 2 arguments.\");\n"
"        }\n"
"    };\n"
"    \n"
"    __add__ = function(self, other) {\n"
"        if std.isInstance(other, vec2) {\n"
"            return vec2(self.x + other.x, self.y + other.y);\n"
"        } else {\n"
"            return vec2(self.x + other, self.y + other);\n"
"        }\n"
"    };\n"
"};\n"
"\n"
"# Comment\n"
"\n"
"some_module.some_function();\n"
"\n"
"adder = function(x, x2, x3, x4) {\n"
"    return function() {\n"
"        return x + inc + inc2 + x3 + x4;\n"
"    }\n"
"};\n"
"\n"
);

        printAST(0, ast);

        DELETE(ast);
    } catch (scripting::ParseException& e)
    {
        std::printf("Failed to parse input at %zu:%zu: %s\n", e.scriptLine, e.scriptColumn, e.message);
    }
    #elif 0
    try
    {
        scripting::ASTNode *ast = scripting::parse(
        //"print(\"Hello world!\", 5 + 10*15, \"= 155\");\n"
        //"if false {print(5);} elif false {print(10);} else {print(15);}"
        //"i = 0; while i < 10 {print(i); i = i + 1;}"
/*"vec2 = class {\n"
"    __init__ = function(self) {\n"
"        if args.len == 0 {\n"
"            self.x = 0.0;\n"
"            self.y = 0.0;\n"
"        } elif args.len == 1 {\n"
"            self.x = float(args[0]);\n"
"            self.y = float(args[0]);\n"
"        } elif args.len == 2 {\n"
"            self.x = float(args[0]);\n"
"            self.y = float(args[1]);\n"
"        } else {\n"
"            throw ValueException(\"vec2.__init__ takes 0, 1 or 2 arguments.\");\n"
"        }\n"
"    };\n"
"    \n"
"    __add__ = function(self, other) {\n"
"        if std.isInstance(other, vec2) {\n"
"            return vec2(self.x + other.x, self.y + other.y);\n"
"        } else {\n"
"            return vec2(self.x + other, self.y + other);\n"
"        }\n"
"    };\n"
"};\n"
"\n"
"# Comment\n"
"\n"
"adder = function(x, x2, x3, x4) {\n"
"    return function() {\n"
"        return x + inc + inc2 + x3 + x4;\n"
"    }\n"
"};\n"
"\n"*/
"s = \"Hello %v!\"; print(s.format(s, \"world\")); print(s.format(s, \"you\"));"
        );

        printAST(0, ast);

        ResizableData data = generateBytecode(ast);

        Str disasm = scripting::disasm(data);

        std::cout << disasm.getData();

        std::cout << "Compiled program takes up " << data.getSize() << " bytes\n";

        DELETE(ast);

        scripting::Bytecode code(data);

        scripting::Engine *engine = NEW(scripting::Engine);

        engine->getGlobalVars().set("print", scripting::createNativeFunction(print));

        {
            scripting::Context *context = NEW(scripting::Context, engine);

            try
            {
                scripting::Value *result = context->run(code, List<scripting::Value *>());

                scripting::destroy(context, result);
            } catch (scripting::UnhandledExcException& e)
            {
                scripting::Value *exc = e.getException();

                std::cout << "Unhandled script exception: ";

                if (exc->type == scripting::ValueType::Exception)
                {
                    std::cout << ((scripting::ExceptionValue *)exc)->error.getData();
                }
            }

            DELETE(context);
        }

        DELETE(engine);
    } catch (scripting::ParseException& e)
    {
        std::printf("Failed to parse input at %zu:%zu: %s\n", e.scriptLine, e.scriptColumn, e.message);
    } catch (scripting::ByteCodeGenException& e)
    {
        std::printf("Failed to generate bytecode: %s\n", e.message);
    }
    #else
    initBacktrace();
    initLoggingSystem();

    int result = EXIT_FAILURE;

    try
    {
        result = unsafeMain(argc, argv);
    } catch (std::exception& e)
    {
        log("Unhandled exception caught: %s\n", e.what());
    } catch (scripting::UnhandledExcException& e)
    {
        scripting::Value exc = e.getException();

        log("Unhandled script exception:\n");

        if (exc.type == scripting::ValueType::Exception)
        {
            log("    %s\n", ((scripting::ExceptionData *)exc.p)->error.getData());
        }
    } catch (const Exception& e)
    {
        log("Unhandled exception caught: %s\n", e.getString());
        log("    File: %s\n", e.getFile());
        log("    Line: %d\n", e.getLine());
        log("    Function: %s\n", e.getFunction());
    } catch (...)
    {
        log("Unhandled exception caught.");
    }

    deinitLoggingSystem();
    deinitBacktrace();

    return result;
    #endif
}
}
