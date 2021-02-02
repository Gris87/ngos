// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101404DA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101404DA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101404DA: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101404FB = 0x101404FB,
    SUBDEVICE_101404FC = 0x101404FC
};



inline const char8* enumToString(PciSubDevice101404DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101404DA::NONE:               return "NONE";
        case PciSubDevice101404DA::SUBDEVICE_101404FB: return "SUBDEVICE_101404FB";
        case PciSubDevice101404DA::SUBDEVICE_101404FC: return "SUBDEVICE_101404FC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101404DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101404DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101404DA::SUBDEVICE_101404FB: return "PCIe3 x16 20GB Cache 12Gb Quad SAS RAID+ Adapter(580B)";
        case PciSubDevice101404DA::SUBDEVICE_101404FC: return "PCIe3 x8 12Gb Quad SAS RAID+ Adapter(580A)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101404DA_H
