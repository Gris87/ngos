// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050410_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050410_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050410: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90050410 = 0x90050410,
    SUBDEVICE_90050411 = 0x90050411
};



inline const char8* enumToString(PciSubDevice90050410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050410::NONE:               return "NONE";
        case PciSubDevice90050410::SUBDEVICE_90050410: return "SUBDEVICE_90050410";
        case PciSubDevice90050410::SUBDEVICE_90050411: return "SUBDEVICE_90050411";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050410::SUBDEVICE_90050410: return "ASC-48300(Spirit RAID)";
        case PciSubDevice90050410::SUBDEVICE_90050411: return "ASC-58300 (Oakmont RAID)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050410_H
