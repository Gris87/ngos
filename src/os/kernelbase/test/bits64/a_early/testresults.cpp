#include "testresults.h"

#include <buildconfig.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>



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

void TestResults::testFailed(const char *filename, u64 line, const char *description)
{
    EARLY_LT((" | filename = 0x%p, line = %u, description = 0x%p", filename, line, description));

    EARLY_ASSERT(filename,    "filename is null");
    EARLY_ASSERT(line > 0,    "line is zero");
    EARLY_ASSERT(description, "description is null");



    ++mFailed;



    sprintf(printfBuffer, "%s:%u | %s", filename, line, description);

    Serial::println(printfBuffer);

    if (Console::canPrint())
    {
        Console::println(printfBuffer);
    }
}

NgosStatus TestResults::summary()
{
    EARLY_LT((""));



    sprintf(printfBuffer, "\n --- Testing completed. %u passed. %u failed ---\n", mPassed, mFailed);

    Serial::println(printfBuffer);

    if (Console::canPrint())
    {
        Console::println(printfBuffer);
    }



    return !mFailed ? NgosStatus::OK : NgosStatus::FAILED; // mFailed == 0
}



#endif
