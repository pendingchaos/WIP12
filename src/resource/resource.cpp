#include "resource/resource.h"

#include "logging.h"
#include "file.h"
#include "filesystem.h"
#include "globals.h"

Resource::Resource(const String& name,
                   Type type_) : filename(""),
                                 autoReload(true),
                                 name(name),
                                 type(type_),
                                 loaded(true),
                                 refCount(0) {}

Resource::Resource(const String& filename_,
                   const String& name_,
                   Type type_) : filename(filename_),
                                 autoReload(true),
                                 name(name_),
                                 type(type_),
                                 loaded(false),
                                 refCount(0)
{
    refreshModification();
}

Resource::~Resource() {}

void Resource::load()
{
    if (filename.getLength() == 0)
    {
        return;
    }

    refreshModification();

    loaded = true;

    fileSys->pushSearchPaths();

    String absFile = fileSys->getAbsolutePath(filename.getData());

    int index = absFile.findLast('/');

    if (index != -1)
    {
        fileSys->addSearchPath(absFile.subStr(0, index));
    }

    _load();

    fileSys->popSearchPaths();
}

void Resource::reload()
{
    load();

    refreshModification();
}

void Resource::save() {}

bool Resource::shouldReload() const
{
    return ::getLastFileModification(filename.getData()) != lastFileModification;
}

void Resource::refreshModification()
{
    lastFileModification = ::getLastFileModification(filename.getData());
}
