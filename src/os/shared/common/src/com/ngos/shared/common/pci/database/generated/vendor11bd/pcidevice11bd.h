// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCIDEVICE11BD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCIDEVICE11BD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11BD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_002E = 0x002E,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0042 = 0x0042,
    DEVICE_0051 = 0x0051,
    DEVICE_BEDE = 0xBEDE
};



inline const char8* enumToString(PciDevice11BD device11BD) // TEST: NO
{
    // COMMON_LT((" | device11BD = %u", device11BD)); // Commented to avoid bad looking logs



    switch (device11BD)
    {
        case PciDevice11BD::NONE:        return "NONE";
        case PciDevice11BD::DEVICE_002E: return "DEVICE_002E";
        case PciDevice11BD::DEVICE_0040: return "DEVICE_0040";
        case PciDevice11BD::DEVICE_0041: return "DEVICE_0041";
        case PciDevice11BD::DEVICE_0042: return "DEVICE_0042";
        case PciDevice11BD::DEVICE_0051: return "DEVICE_0051";
        case PciDevice11BD::DEVICE_BEDE: return "DEVICE_BEDE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11BD device11BD) // TEST: NO
{
    // COMMON_LT((" | device11BD = %u", device11BD)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11BD, enumToString(device11BD));

    return res;
}



inline const char8* enumToHumanString(PciDevice11BD device11BD) // TEST: NO
{
    // COMMON_LT((" | device11BD = %u", device11BD)); // Commented to avoid bad looking logs



    switch (device11BD)
    {
        case PciDevice11BD::DEVICE_002E: return "PCTV 40i";
        case PciDevice11BD::DEVICE_0040: return "Royal TS Function 1";
        case PciDevice11BD::DEVICE_0041: return "RoyalTS Function 2";
        case PciDevice11BD::DEVICE_0042: return "Royal TS Function 3";
        case PciDevice11BD::DEVICE_0051: return "PCTV HD 800i";
        case PciDevice11BD::DEVICE_BEDE: return "AV/DV Studio Capture Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCIDEVICE11BD_H
