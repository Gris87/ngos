#ifndef MEMORYTEST_SRC_BITS64_OTHER_MEMORYTESTMODE_H
#define MEMORYTEST_SRC_BITS64_OTHER_MEMORYTESTMODE_H



#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class MemoryTestMode: u8
{
    QUICK_TEST,
    FULL_TEST,
    MAXIMUM
};



inline const char8* enumToString(MemoryTestMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    switch (mode)
    {
        case MemoryTestMode::QUICK_TEST: return "QUICK_TEST";
        case MemoryTestMode::FULL_TEST:  return "FULL_TEST";
        case MemoryTestMode::MAXIMUM:    return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(MemoryTestMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", mode, enumToString(mode));

    return res;
}



inline const char8* enumToHumanString(MemoryTestMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    switch (mode)
    {
        case MemoryTestMode::QUICK_TEST: return "Quick test";
        case MemoryTestMode::FULL_TEST:  return "Full test";
        case MemoryTestMode::MAXIMUM:    return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // MEMORYTEST_SRC_BITS64_OTHER_MEMORYTESTMODE_H
