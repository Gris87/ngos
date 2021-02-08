#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSDATABUSWIDTH_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSDATABUSWIDTH_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



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
        case DmiSystemSlotsDataBusWidth::_8_BIT:   return "8_BIT";
        case DmiSystemSlotsDataBusWidth::_16_BIT:  return "16_BIT";
        case DmiSystemSlotsDataBusWidth::_32_BIT:  return "32_BIT";
        case DmiSystemSlotsDataBusWidth::_64_BIT:  return "64_BIT";
        case DmiSystemSlotsDataBusWidth::_128_BIT: return "128_BIT";
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

    sprintf(res, "0x%02X (%s)", (u8)width, enumToString(width));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSDATABUSWIDTH_H
