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

ScriptInstance::ScriptInstance(const char *name_,
                               Script *script_,
                               scripting::Value *obj_,
                               Entity *entity_,
                               Scene *scene_) : name(name_),
                                                script(script_->copyRef<Script>()),
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

void ScriptInstance::serialize(Serializable& serialized)
{
}

void ScriptInstance::deserialize(const Serializable& serialized)
{
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

    //String disasm = scripting::disasm(code);
    //std::cout << disasm.getData() << std::endl;

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

ScriptInstance *Script::createInstance(const char *name, Entity *entity, Scene *scene)
{
    if (entity != nullptr)
    {
        scene = entity->getScene();
    }

    //TODO: The arguments.
    ScriptInstance *result = NEW(ScriptInstance, name, this, scripting::call(context, class_, List<scripting::Value *>()), entity, scene);

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
