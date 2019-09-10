#include "testresults.h"

#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TestResults::TestResults()
    : mPassed(0)
    , mFailed(0)
{
    EARLY_LT((""));
}

void TestResults::testPassed()
{
    EARLY_LT((""));



    ++mPassed;
}

void TestResults::testFailed(const char8 *fileName, u64 line, const char8 *description)
{
    EARLY_LT((" | fileName = 0x%p, line = %u, description = 0x%p", fileName, line, description));

    EARLY_ASSERT(fileName,    "fileName is null");
    EARLY_ASSERT(line > 0,    "line is zero");
    EARLY_ASSERT(description, "description is null");



    ++mFailed;



    char8 buffer[1024];

    sprintf(buffer, "%s:%u | %s", fileName, line, description);



    if (GraphicalConsole::canPrint())
    {
        GraphicalConsole::init();

        Serial::println(buffer);
        GraphicalConsole::println(buffer);
    }
    else
    if (Console::canPrint())
    {
        Serial::println(buffer);
        Console::println(buffer);
    }
    else
    {
        Serial::println(buffer);
    }
}

NgosStatus TestResults::summary()
{
    EARLY_LT((""));



    char8 buffer[1024];

    sprintf(buffer, "\n --- Testing completed: %u passed, %u failed ---\n", mPassed, mFailed);



    if (GraphicalConsole::canPrint())
    {
        GraphicalConsole::init();

        Serial::println(buffer);
        GraphicalConsole::println(buffer);
    }
    else
    if (Console::canPrint())
    {
        Serial::println(buffer);
        Console::println(buffer);
    }
    else
    {
        Serial::println(buffer);
    }



    return !mFailed ? NgosStatus::OK : NgosStatus::FAILED; // mFailed == 0
}



#endif
