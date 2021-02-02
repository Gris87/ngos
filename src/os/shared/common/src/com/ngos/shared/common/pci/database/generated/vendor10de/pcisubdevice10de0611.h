// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0611_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0611_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0611: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107D2AB0 = 0x107D2AB0,
    SUBDEVICE_14621170 = 0x14621170,
    SUBDEVICE_19DA1040 = 0x19DA1040
};



inline const char8* enumToString(PciSubDevice10DE0611 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0611::NONE:               return "NONE";
        case PciSubDevice10DE0611::SUBDEVICE_107D2AB0: return "SUBDEVICE_107D2AB0";
        case PciSubDevice10DE0611::SUBDEVICE_14621170: return "SUBDEVICE_14621170";
        case PciSubDevice10DE0611::SUBDEVICE_19DA1040: return "SUBDEVICE_19DA1040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0611 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0611 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0611::SUBDEVICE_107D2AB0: return "Winfast PX8800 GT PCI-E";
        case PciSubDevice10DE0611::SUBDEVICE_14621170: return "NX8800GT series model V117 2xDVI+TV";
        case PciSubDevice10DE0611::SUBDEVICE_19DA1040: return "ZT-88TES2P-FSP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0611_H
