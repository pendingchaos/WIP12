#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "containers/list.h"
#include "containers/string.h"
#include "misc_macros.h"
#include "file.h"

class Filesystem
{
    NO_COPY(Filesystem)

    public:
        Filesystem();

        void pushSearchPaths();
        void popSearchPaths();

        void addSearchPath(const String& path);

        String getAbsolutePath(const char *path) const;
    private:
        List<List<String > > searchPaths;
};

#endif // FILESYSTEM_H
