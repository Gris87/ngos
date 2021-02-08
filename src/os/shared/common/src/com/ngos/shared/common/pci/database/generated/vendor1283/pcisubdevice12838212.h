// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCISUBDEVICE12838212_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCISUBDEVICE12838212_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12838212: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12830001 = 0x12830001
};



inline const char8* enumToString(PciSubDevice12838212 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12838212::NONE:               return "NONE";
        case PciSubDevice12838212::SUBDEVICE_12830001: return "SUBDEVICE_12830001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12838212 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12838212 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12838212::SUBDEVICE_12830001: return "IT/ITE8212 Dual channel ATA RAID controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCISUBDEVICE12838212_H
