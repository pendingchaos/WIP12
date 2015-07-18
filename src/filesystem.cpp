#include "filesystem.h"

#include "file.h"

#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>

Filesystem::Filesystem()
{
    searchPaths.append(List<String >());
}

void Filesystem::pushSearchPaths()
{
    searchPaths.append(searchPaths[searchPaths.getCount()-1].copy());
}

void Filesystem::popSearchPaths()
{
    searchPaths.remove(searchPaths.getCount()-1);
}

void Filesystem::addSearchPath(const String& path)
{
    searchPaths[searchPaths.getCount()-1].append(getAbsolutePath(path.getData()));
}

String Filesystem::getAbsolutePath(const char *path) const
{
    if (searchPaths.getCount() != 0)
    {
        char *workingDir = get_current_dir_name();

        const List<String >& paths = searchPaths[searchPaths.getCount()-1];

        for (size_t i = 0; i < paths.getCount(); ++i)
        {
            chdir(paths[i].getData());

            struct stat status;

            if (stat(path, &status) == -1)
            {
                continue;
            }

            char result[PATH_MAX];
            std::memset(result, '\x00', sizeof(result));
            realpath(path, result);

            chdir(workingDir);
            free(workingDir);

            return result;
        }

        chdir(workingDir);
        free(workingDir);
    }

    char result[PATH_MAX];
    std::memset(result, '\x00', sizeof(result));
    if (realpath(path, result) == nullptr)
    {
        return "";
    }

    return result;
}
