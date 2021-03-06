#ifndef SCRIPTING_ENGINE_H
#define SCRIPTING_ENGINE_H

#include "scripting/vm/types.h"

namespace scripting
{
class Engine;

struct Extension
{
    void *data;
    void *(*init)(Engine *engine, void *data);
    void (*deinit)(Engine *engine, void *data);
};

class Engine
{
    public:
        Engine();
        ~Engine();

        const HashMap<Str, Value>& getGlobalVars() const
        {
            return globalVars;
        }

        HashMap<Str, Value>& getGlobalVars()
        {
            return globalVars;
        }

        void addExtension(const Str& name, const Extension& extension);

        const Extension& getExtension(const Str& name) const
        {
            return extensions.get(name);
        }

        int64_t createNewTypeID()
        {
            return nextTypeID++;
        }
    private:
        HashMap<Str, Value> globalVars;
        HashMap<Str, Extension> extensions;
        int64_t nextTypeID;
};
}

#endif // SCRIPTING_ENGINE_H
