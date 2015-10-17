#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "containers/list.h"
#include "containers/string.h"
#include "misc_macros.h"
#include "file.h"
#include "scripting/bindings.h"

class Filesystem
{
    public:
        Filesystem();

        void pushSearchPaths();
        void popSearchPaths();

        void addSearchPath(const Str& path);

        Str getAbsolutePath(const char *path) const;
    private:
        List<List<Str > > searchPaths;
} BIND;

#endif // FILESYSTEM_H
