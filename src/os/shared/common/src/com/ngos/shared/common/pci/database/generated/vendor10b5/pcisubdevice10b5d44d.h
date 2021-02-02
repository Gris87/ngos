// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B5D44D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B5D44D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B5D44D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B517F6 = 0x10B517F6,
    SUBDEVICE_10B517F7 = 0x10B517F7,
    SUBDEVICE_10B517F8 = 0x10B517F8,
    SUBDEVICE_10B59030 = 0x10B59030
};



inline const char8* enumToString(PciSubDevice10B5D44D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B5D44D::NONE:               return "NONE";
        case PciSubDevice10B5D44D::SUBDEVICE_10B517F6: return "SUBDEVICE_10B517F6";
        case PciSubDevice10B5D44D::SUBDEVICE_10B517F7: return "SUBDEVICE_10B517F7";
        case PciSubDevice10B5D44D::SUBDEVICE_10B517F8: return "SUBDEVICE_10B517F8";
        case PciSubDevice10B5D44D::SUBDEVICE_10B59030: return "SUBDEVICE_10B59030";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B5D44D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B5D44D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B5D44D::SUBDEVICE_10B517F6: return "Allo CP100P/E 1-port E1/T1/J1 PCI/PCIe card";
        case PciSubDevice10B5D44D::SUBDEVICE_10B517F7: return "Allo CP400P/E 4-port E1/T1/J1 PCI/PCIe card";
        case PciSubDevice10B5D44D::SUBDEVICE_10B517F8: return "Allo CP200P/E 2-port E1/T1/J1 PCI/PCIe card";
        case PciSubDevice10B5D44D::SUBDEVICE_10B59030: return "Tormenta 3 Varion V401PE Quad E1 PCI card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B5D44D_H
