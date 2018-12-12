#include "testresults.h"

#include <buildconfig.h>

#include "src/bits64/a_uefi/uefi/uefiassert.h"
#include "src/bits64/a_uefi/uefi/uefilog.h"



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

void TestResults::testFailed(const char *filename, u64 line, const char *description)
{
    UEFI_LT((" | filename = 0x%p, line = %u, description = 0x%p", filename, line, description));

    UEFI_ASSERT(filename,    "filename is null");
    UEFI_ASSERT(line > 0,    "line is zero");
    UEFI_ASSERT(description, "description is null");



    // HACK: Temporary fix for PIE. Try to find another solution
    char *tempBuffer;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    printfBuffer(%%rip), %0" // leaq    printfBuffer(%rip), %rbx   # Get address of printfBuffer variable to RBX. %RBX == tempBuffer
            :                             // Output parameters
                "=r" (tempBuffer)         // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]



    ++mFailed;



    sprintf(tempBuffer, "%s:%u | %s", filename, line, description);

    if (Console::canPrint())
    {
        Serial::println(tempBuffer);
        Console::println(tempBuffer);
    }
    else
    if (UEFI::canPrint())
    {
        UEFI::println(tempBuffer);
    }
    else
    {
        Serial::println(tempBuffer);
    }
}

NgosStatus TestResults::summary()
{
    UEFI_LT((""));



    // HACK: Temporary fix for PIE. Try to find another solution
    char *tempBuffer;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    printfBuffer(%%rip), %0" // leaq    printfBuffer(%rip), %rbp   # Get address of printfBuffer variable to RBP. %RBP == tempBuffer
            :                             // Output parameters
                "=r" (tempBuffer)         // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]



    sprintf(tempBuffer, "\n --- Testing completed. %u passed. %u failed ---\n", mPassed, mFailed);

    if (Console::canPrint())
    {
        Serial::println(tempBuffer);
        Console::println(tempBuffer);
    }
    else
    if (UEFI::canPrint())
    {
        UEFI::println(tempBuffer);
    }
    else
    {
        Serial::println(tempBuffer);
    }



    return !mFailed ? NgosStatus::OK : NgosStatus::FAILED; // mFailed == 0
}



#endif
