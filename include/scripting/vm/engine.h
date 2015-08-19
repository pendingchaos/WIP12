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

//TODO: Destroy undeleted references when the Engine quits.
class Engine
{
    public:
        Engine();
        ~Engine();

        inline const RefManager *getRefMgr() const
        {
            return &refMgr;
        }

        inline RefManager *getRefMgr()
        {
            return &refMgr;
        }

        inline const HashMap<String, Ref>& getGlobalVars() const
        {
            return globalVars;
        }

        inline HashMap<String, Ref>& getGlobalVars()
        {
            return globalVars;
        }

        bool debugOutput;

        void addExtension(const String& name, const Extension& extension);

        inline const Extension& getExtension(const String& name) const
        {
            return extensions.get(name);
        }

        int64_t createNewTypeID()
        {
            return nextTypeID++;
        }
    private:
        HashMap<String, Ref> globalVars;
        RefManager refMgr;
        HashMap<String, Extension> extensions;
        int64_t nextTypeID;
};
}

#endif // SCRIPTING_ENGINE_H
