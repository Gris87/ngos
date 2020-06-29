#ifndef MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_OTHER_TESTTYPE_H
#define MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_OTHER_TESTTYPE_H



#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class TestType: u8
{
    SEQUENTIAL_READ,
    SEQUENTIAL_WRITE,
    RANDOM_READ,
    RANDOM_WRITE,
    MAXIMUM
};



inline const char8* enumToString(TestType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case TestType::SEQUENTIAL_READ:  return "SEQUENTIAL_READ";
        case TestType::SEQUENTIAL_WRITE: return "SEQUENTIAL_WRITE";
        case TestType::RANDOM_READ:      return "RANDOM_READ";
        case TestType::RANDOM_WRITE:     return "RANDOM_WRITE";
        case TestType::MAXIMUM:          return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(TestType type) // TEST: NO
{
    // UEFI_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_OTHER_TESTTYPE_H
