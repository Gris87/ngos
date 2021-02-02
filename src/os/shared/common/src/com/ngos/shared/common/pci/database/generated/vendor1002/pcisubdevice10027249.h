// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027249_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027249_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10027249: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020412 = 0x10020412,
    SUBDEVICE_10020B12 = 0x10020B12,
    SUBDEVICE_10020D02 = 0x10020D02,
    SUBDEVICE_10430160 = 0x10430160
};



inline const char8* enumToString(PciSubDevice10027249 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027249::NONE:               return "NONE";
        case PciSubDevice10027249::SUBDEVICE_10020412: return "SUBDEVICE_10020412";
        case PciSubDevice10027249::SUBDEVICE_10020B12: return "SUBDEVICE_10020B12";
        case PciSubDevice10027249::SUBDEVICE_10020D02: return "SUBDEVICE_10020D02";
        case PciSubDevice10027249::SUBDEVICE_10430160: return "SUBDEVICE_10430160";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10027249 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10027249 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027249::SUBDEVICE_10020412: return "All-In-Wonder X1900";
        case PciSubDevice10027249::SUBDEVICE_10020B12: return "Radeon X1900 XT/XTX";
        case PciSubDevice10027249::SUBDEVICE_10020D02: return "Radeon X1900 CrossFire Edition";
        case PciSubDevice10027249::SUBDEVICE_10430160: return "Radeon X1900 XTX 512 MB GDDR3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027249_H
