#include "resource/resource.h"

#include "logging.h"
#include "file.h"
#include "filesystem.h"
#include "globals.h"

Resource::Resource(Type type_) : filename(""),
                                 autoReload(true),
                                 type(type_),
                                 loaded(true),
                                 refCount(1) {}

Resource::Resource(const String& filename_,
                   Type type_) : filename(filename_),
                                 autoReload(true),
                                 type(type_),
                                 loaded(false),
                                 refCount(1)
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
    if (filename.getLength() == 0)
    {
        return false;
    }

    return ::getLastFileModification(filename.getData()) != lastFileModification;
}

void Resource::refreshModification()
{
    if (filename.getLength() != 0)
    {
        lastFileModification = ::getLastFileModification(filename.getData());
    }
}
