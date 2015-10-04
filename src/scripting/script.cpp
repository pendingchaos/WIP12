#include "scripting/script.h"

#include "error.h"
#include "globals.h"
#include "filesystem.h"
#include "logging.h"
#include "platform.h"
#include "scene/entity.h"
#include "scene/scene.h"
#include "scripting/parser.h"
#include "scripting/bytecodegen.h"
#include "scripting/disasm.h"
#include "scripting/bindings2.h"

//TODO: Get rid of this
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

ScriptInstance::ScriptInstance(Script *script_,
                               scripting::Value *obj_,
                               Entity *entity_,
                               Scene *scene_) : script(script_->copyRef<Script>()),
                                                obj(obj_),
                                                entity(entity_),
                                                scene(scene_) {}

ScriptInstance::~ScriptInstance()
{
    destroy();

    script->removeInstance(this);
    script->release();
}

void ScriptInstance::method(const String& name)
{
    scripting::Context *ctx = script->getContext();

    if (obj != nullptr)
    {
        try
        {
            scripting::destroy(ctx, scripting::callMethod(ctx, obj, name, List<scripting::Value *>()));
        } catch (scripting::UnhandledExcException& e)
        {
            scripting::Value *exc = e.getException();

            log("Unhandled script exception in %s\n", script->getFilename().getData());

            if (exc->type == scripting::ValueType::Exception)
            {
                log("    %s\n", ((scripting::ExceptionValue *)exc)->error.getData());
            }
            std::exit(1);
        }
    }
}

void ScriptInstance::method(const String& name, float timestep)
{
    scripting::Context *ctx = script->getContext();

    if (obj != nullptr)
    {
        scripting::Value *arg = scripting::createFloat(timestep);

        List<scripting::Value *> args;
        args.append(arg);

        try
        {
            scripting::destroy(ctx, scripting::callMethod(ctx, obj, name, args));
        } catch (scripting::UnhandledExcException& e)
        {
            scripting::Value *exc = e.getException();

            log("Unhandled script exception in %s\n", script->getFilename().getData());

            if (exc->type == scripting::ValueType::Exception)
            {
                log("    %s\n", ((scripting::ExceptionValue *)exc)->error.getData());
            }
        }

        scripting::destroy(ctx, arg);
    }
}

void ScriptInstance::destroy()
{
    if (obj != nullptr)
    {
        scripting::destroy(script->getContext(), obj);
        obj = nullptr;
    }
}

Script::Script() : Resource(ResType::ScriptType),
                   context(nullptr) {}

Script::Script(const String& filename) : Resource(filename,
                                                  ResType::ScriptType),
                                         context(nullptr) {}

Script::~Script()
{
    removeContent();
}

void Script::removeContent()
{
    if (context != nullptr)
    {
        for (size_t i = 0; i < instances.getCount(); ++i)
        {
            instances[i]->destroy();
        }

        scripting::destroy(context, class_);

        DELETE(context);
        context = nullptr;
    }
}

void Script::_load()
{
    removeContent();

    String source;

    try
    {
        File sourceFile(getFilename().getData(), "r");
        source = String(sourceFile.getSize());
        sourceFile.read(sourceFile.getSize(), source.getData());
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "script",
              getFilename(),
              e.getString());
    }

    scripting::ASTNode *ast;

    try
    {
        ast = scripting::parse(source);
    } catch (const scripting::ParseException& e)
    {
        THROW(ResourceIOException,
              "script",
              getFilename(),
              String::format("%d:%d: %s", e.scriptLine, e.scriptColumn, e.message));
    }

    //printAST(0, ast);

    ResizableData data;

    try
    {
        data = scripting::generateBytecode(ast);
    } catch (const scripting::ByteCodeGenException& e)
    {
        THROW(ResourceIOException,
              "script",
              getFilename(),
              e.message);
    }

    DELETE(ast);

    scripting::Bytecode code(data);

    String disasm = scripting::disasm(code);
    std::cout << disasm.getData() << std::endl;

    {
        context = NEW(scripting::Context, scriptEngine);

        try
        {
            class_ = context->run(code, List<scripting::Value *>());
        } catch (scripting::UnhandledExcException& e)
        {
            scripting::Value *exc = e.getException();

            if (exc->type == scripting::ValueType::Exception)
            {
                THROW(ResourceIOException,
                      "script",
                      getFilename(),
                      ((scripting::ExceptionValue *)exc)->error.getData());
            } else
            {
                THROW(ResourceIOException,
                      "script",
                      getFilename(),
                      "Unhandled exception");
            }
        }
    }
}

ScriptInstance *Script::createInstance(Entity *entity, Scene *scene)
{
    if (entity != nullptr)
    {
        scene = entity->getScene();
    }

    List<scripting::Value *> args;

    if (entity != nullptr)
    {
        args.append(create(context, entity));
    } else if (scene != nullptr)
    {
        args.append(create(context, scene));
    }

    ScriptInstance *result;

    try
    {
        result = NEW(ScriptInstance, this, scripting::call(context, class_, args), entity, scene);
    } catch (scripting::UnhandledExcException& e)
    {
        scripting::Value *exc = e.getException();

        log("Unhandled script exception in %s\n", getFilename().getData());

        if (exc->type == scripting::ValueType::Exception)
        {
            log("    %s\n", ((scripting::ExceptionValue *)exc)->error.getData());
        }

        result = NEW(ScriptInstance, this, nullptr, entity, scene);
    }

    instances.append(result);

    return result;
}

void Script::removeInstance(ScriptInstance *instance)
{
    if (instance->script == this)
    {
        instances.remove(instances.find(instance));
    }
}
