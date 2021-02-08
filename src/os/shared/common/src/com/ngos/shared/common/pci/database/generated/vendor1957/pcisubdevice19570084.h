// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE19570084_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE19570084_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19570084: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_110A4074 = 0x110A4074
};



inline const char8* enumToString(PciSubDevice19570084 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19570084::NONE:               return "NONE";
        case PciSubDevice19570084::SUBDEVICE_110A4074: return "SUBDEVICE_110A4074";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19570084 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19570084 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19570084::SUBDEVICE_110A4074: return "SIMATIC NET CP 1628";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE19570084_H
