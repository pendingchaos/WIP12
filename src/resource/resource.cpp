#include "resource/resource.h"

#include "logging.h"
#include "file.h"
#include "filesystem.h"
#include "globals.h"

Resource::Resource(ResType type_) : filename(""),
                                    type(type_),
                                    refCount(1) {}

Resource::Resource(const String& filename_,
                   ResType type_) : filename(filename_),
                                    type(type_),
                                    refCount(1) {}

Resource::~Resource() {}

void Resource::load()
{
    if (filename.getLength() == 0)
    {
        return;
    }

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

void Resource::save() {}
