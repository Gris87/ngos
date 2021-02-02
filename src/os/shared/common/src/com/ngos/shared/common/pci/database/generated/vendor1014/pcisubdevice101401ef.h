// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101401EF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101401EF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101401EF: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1734102B = 0x1734102B,
    SUBDEVICE_173410F8 = 0x173410F8
};



inline const char8* enumToString(PciSubDevice101401EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101401EF::NONE:               return "NONE";
        case PciSubDevice101401EF::SUBDEVICE_1734102B: return "SUBDEVICE_1734102B";
        case PciSubDevice101401EF::SUBDEVICE_173410F8: return "SUBDEVICE_173410F8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101401EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101401EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101401EF::SUBDEVICE_1734102B: return "PCEAS PCI-X Dual Port ESCON Adapter";
        case PciSubDevice101401EF::SUBDEVICE_173410F8: return "PCEAT PCI-Express Dual Port ESCON Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101401EF_H
