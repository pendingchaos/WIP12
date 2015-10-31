#include <SDL2/SDL.h>
#include <cstdio>
#include <signal.h>
#include <mutex>

#include "scripting/script.h"

#include "application.h"
#include "logging.h"
#include "backtrace.h"
#include "error.h"
#include "filesystem.h"
#include "globals.h"
#include "platform.h"
#include "jobsystem.h"

void run(const char *dir)
{
    {
        Application app_(dir);

        setApplication(&app_);

        Script *script = resMgr->load<Script>("resources/scripts/main.rkt");
        app->setNextScript(script);
        script->release();

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

static std::mutex mutex;

void crashHandler(int sig)
{
    std::lock_guard<std::mutex> lock(mutex);

    initLoggingSystem();

    switch (sig)
    {
    case SIGSEGV:
    {
        log("SIGSEGV\nBacktrace:\n");
        break;
    }
    case SIGABRT:
    {
        log("SIGABRT\nBacktrace:\n");
        break;
    }
    }

    unsigned int depth = 0;
    const char **backtrace = getBacktrace(depth);

    for (size_t i = 0; i < depth-1; ++i)
    {
        log("    %s\n", backtrace[i]);
    }

    deinitLoggingSystem();

    std::exit(1);
}

void fpeHandler(int sig)
{
    std::lock_guard<std::mutex> lock(mutex);

    initLoggingSystem();

    log("SIGFPE\nBacktrace:\n");

    unsigned int depth = 0;
    const char **backtrace = getBacktrace(depth);

    for (size_t i = 0; i < depth-1; ++i)
    {
        log("    %s\n", backtrace[i]);
    }
}

int main(int argc, const char *argv[])
{
    signal(SIGSEGV, crashHandler);
    signal(SIGABRT, crashHandler);
    signal(SIGFPE, fpeHandler);

    initBacktrace();
    initLoggingSystem();
    initJobSystem(SDL_GetCPUCount()+2);

    int result = EXIT_FAILURE;

    try
    {
        result = unsafeMain(argc, argv);
    } catch (std::exception& e)
    {
        log("Unhandled exception caught: %s\n", e.what());
    } catch (scripting::UnhandledExcException& e)
    {
        scripting::Value exc = e.getException();

        log("Unhandled script exception:\n");

        if (exc.type == scripting::ValueType::Exception)
        {
            log("    %s\n", ((scripting::ExceptionData *)exc.p)->error.getData());
        }
    } catch (const Exception& e)
    {
        log("Unhandled exception caught: %s\n", e.getString());
        log("    File: %s\n", e.getFile());
        log("    Line: %d\n", e.getLine());
        log("    Function: %s\n", e.getFunction());
    } catch (...)
    {
        log("Unhandled exception caught.");
    }

    deinitJobSystem();
    deinitLoggingSystem();
    deinitBacktrace();

    return result;
}
