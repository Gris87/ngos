#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSDATABUSWIDTH_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSDATABUSWIDTH_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiSystemSlotsDataBusWidth: u8
{
    NONE     = 0,
    OTHER    = 1,
    UNKNOWN  = 2,
    _8_BIT   = 3,
    _16_BIT  = 4,
    _32_BIT  = 5,
    _64_BIT  = 6,
    _128_BIT = 7,
    X1       = 8,
    X2       = 9,
    X4       = 10,
    X8       = 11,
    X12      = 12,
    X16      = 13,
    X32      = 14
};



inline const char8* enumToString(DmiSystemSlotsDataBusWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    switch (width)
    {
        case DmiSystemSlotsDataBusWidth::NONE:     return "NONE";
        case DmiSystemSlotsDataBusWidth::OTHER:    return "OTHER";
        case DmiSystemSlotsDataBusWidth::UNKNOWN:  return "UNKNOWN";
        case DmiSystemSlotsDataBusWidth::_8_BIT:   return "_8_BIT";
        case DmiSystemSlotsDataBusWidth::_16_BIT:  return "_16_BIT";
        case DmiSystemSlotsDataBusWidth::_32_BIT:  return "_32_BIT";
        case DmiSystemSlotsDataBusWidth::_64_BIT:  return "_64_BIT";
        case DmiSystemSlotsDataBusWidth::_128_BIT: return "_128_BIT";
        case DmiSystemSlotsDataBusWidth::X1:       return "X1";
        case DmiSystemSlotsDataBusWidth::X2:       return "X2";
        case DmiSystemSlotsDataBusWidth::X4:       return "X4";
        case DmiSystemSlotsDataBusWidth::X8:       return "X8";
        case DmiSystemSlotsDataBusWidth::X12:      return "X12";
        case DmiSystemSlotsDataBusWidth::X16:      return "X16";
        case DmiSystemSlotsDataBusWidth::X32:      return "X32";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemSlotsDataBusWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", width, enumToString(width));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSDATABUSWIDTH_H
