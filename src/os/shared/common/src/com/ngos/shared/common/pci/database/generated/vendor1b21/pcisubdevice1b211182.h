// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCISUBDEVICE1B211182_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCISUBDEVICE1B211182_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1B211182: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1B21118F = 0x1B21118F
};



inline const char8* enumToString(PciSubDevice1B211182 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B211182::NONE:               return "NONE";
        case PciSubDevice1B211182::SUBDEVICE_1B21118F: return "SUBDEVICE_1B21118F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1B211182 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1B211182 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B211182::SUBDEVICE_1B21118F: return "ASM1182e 2-Port PCIe x1 Gen2 Packet Switch";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCISUBDEVICE1B211182_H
