// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41679_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41679_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41679: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1707 = 0x103C1707,
    SUBDEVICE_103C170C = 0x103C170C,
    SUBDEVICE_103C703C = 0x103C703C
};



inline const char8* enumToString(PciSubDevice14E41679 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41679::NONE:               return "NONE";
        case PciSubDevice14E41679::SUBDEVICE_103C1707: return "SUBDEVICE_103C1707";
        case PciSubDevice14E41679::SUBDEVICE_103C170C: return "SUBDEVICE_103C170C";
        case PciSubDevice14E41679::SUBDEVICE_103C703C: return "SUBDEVICE_103C703C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41679 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41679 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41679::SUBDEVICE_103C1707: return "NC326m PCIe Dual Port Adapter";
        case PciSubDevice14E41679::SUBDEVICE_103C170C: return "NC325m PCIe Quad Port Adapter";
        case PciSubDevice14E41679::SUBDEVICE_103C703C: return "NC326i PCIe Dual Port Gigabit Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41679_H
