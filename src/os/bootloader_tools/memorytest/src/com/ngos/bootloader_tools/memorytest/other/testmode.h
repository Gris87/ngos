#ifndef MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_OTHER_TESTMODE_H
#define MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_OTHER_TESTMODE_H



#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class TestMode: u8
{
    QUICK_TEST,
    FULL_TEST,
    MAXIMUM
};



inline const char8* enumToString(TestMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    switch (mode)
    {
        case TestMode::QUICK_TEST: return "QUICK_TEST";
        case TestMode::FULL_TEST:  return "FULL_TEST";
        case TestMode::MAXIMUM:    return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(TestMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", mode, enumToString(mode));

    return res;
}



inline const char8* enumToHumanString(TestMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    switch (mode)
    {
        case TestMode::QUICK_TEST: return "Quick test";
        case TestMode::FULL_TEST:  return "Full test";
        case TestMode::MAXIMUM:    return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_OTHER_TESTMODE_H