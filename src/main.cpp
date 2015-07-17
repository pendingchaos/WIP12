#include <cstring>
#include <iostream>

#include "scripting/script.h"

#include "application.h"
#include "logging.h"
#include "backtrace.h"
#include "error.h"
#include "filesystem.h"
#include "globals.h"
#include "platform.h"

void run(const char *dir)
{
    {
        Application app_(dir);

        setApplication(&app_);

        app->setNextScript(resMgr->load<Script>("resources/scripts/main.cpp"), "Main");

        app->mainloop();
    }

    setApplication(nullptr);
}

int unsafeMain(int argc, const char *argv[])
{
    if (argc >= 2)
    {
        run(argv[1]);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

extern "C"
{
int main(int argc, const char *argv[])
{
    initBacktrace();
    initLoggingSystem();

    try
    {
        return unsafeMain(argc, argv);
    } catch (std::exception& e)
    {
        log("Unhandled exception caught: %s\n", e.what());
    } catch (const Exception& e)
    {
        log("Unhandled exception caught: %s\n", e.getString());
        log("    File: %s\n", e.getFile());
        log("    Line: %d\n", e.getLine());
        log("    Function: %s\n", e.getFunction());
    }

    deinitLoggingSystem();
    deinitBacktrace();
}
}
