// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AF4_PCISUBDEVICE1AF41000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AF4_PCISUBDEVICE1AF41000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1AF41000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_01DEFFFB = 0x01DEFFFB
};



inline const char8* enumToString(PciSubDevice1AF41000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1AF41000::NONE:               return "NONE";
        case PciSubDevice1AF41000::SUBDEVICE_01DEFFFB: return "SUBDEVICE_01DEFFFB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1AF41000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1AF41000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1AF41000::SUBDEVICE_01DEFFFB: return "Propolis Virtio network device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AF4_PCISUBDEVICE1AF41000_H
