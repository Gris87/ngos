#include "testresults.h"

#include <buildconfig.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TestResults::TestResults()
    : mPassed(0)
    , mFailed(0)
{
    UEFI_LT((""));
}

void TestResults::testPassed()
{
    UEFI_LT((""));



    ++mPassed;
}

void TestResults::testFailed(const char8 *filename, u64 line, const char8 *description)
{
    UEFI_LT((" | filename = 0x%p, line = %u, description = 0x%p", filename, line, description));

    UEFI_ASSERT(filename,    "filename is null");
    UEFI_ASSERT(line > 0,    "line is zero");
    UEFI_ASSERT(description, "description is null");



    ++mFailed;



    char8 buffer[1024];

    sprintf(buffer, "%s:%u | %s", filename, line, description);



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
    if (UEFI::canPrint())
    {
        UEFI::println(buffer);
    }
    else
    {
        Serial::println(buffer);
    }
}

NgosStatus TestResults::summary()
{
    UEFI_LT((""));



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
    if (UEFI::canPrint())
    {
        UEFI::println(buffer);
    }
    else
    {
        Serial::println(buffer);
    }



    return !mFailed ? NgosStatus::OK : NgosStatus::FAILED; // mFailed == 0
}



#endif
