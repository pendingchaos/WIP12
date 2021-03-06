#define TEST int testStartCounter = __COUNTER__;
#define REQUIRE(cond) if (not (cond)) {return __COUNTER__ - testStartCounter;}
#define FAIL() REQUIRE(false)

#define RUN_TEST(test, ...)\
{\
    int cond = test(__VA_ARGS__);\
    \
    if (cond == -1)\
    {\
        ++succeeded;\
    } else\
    {\
        ++failed;\
        \
        log("Test \"%s\" failed (condition %d)\n", STR(test), cond);\
    }\
}

#include "tests/list.h"
#include "tests/hashmap.h"
#include "tests/t2.h"
#include "tests/t3.h"
#include "tests/t4.h"
#include "tests/gfxbuffer.h"

BEGIN_INSTANCE(Main, InstanceBase)
    virtual void init()
    {
        size_t succeeded = 0;
        size_t failed = 0;
        
        HASHMAP_TESTS
        LIST_TESTS
        T2_TESTS
        T3_TESTS
        T4_TESTS
        GFX_BUFFER_TESTS(gfxApi)
        
        size_t numTests = succeeded + failed;
        
        log("%zu out of %zu tests failed (%f%c).\n",
            failed,
            numTests,
            float(failed)/float(numTests)*100.0f,
            '%');
        
        app->running = false;
    }
END_INSTANCE(Main)
