// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice9005028C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90050500 = 0x90050500,
    SUBDEVICE_90050501 = 0x90050501,
    SUBDEVICE_90050502 = 0x90050502,
    SUBDEVICE_90050503 = 0x90050503,
    SUBDEVICE_90050504 = 0x90050504,
    SUBDEVICE_90050505 = 0x90050505,
    SUBDEVICE_90050506 = 0x90050506
};



inline const char8* enumToString(PciSubDevice9005028C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005028C::NONE:               return "NONE";
        case PciSubDevice9005028C::SUBDEVICE_90050500: return "SUBDEVICE_90050500";
        case PciSubDevice9005028C::SUBDEVICE_90050501: return "SUBDEVICE_90050501";
        case PciSubDevice9005028C::SUBDEVICE_90050502: return "SUBDEVICE_90050502";
        case PciSubDevice9005028C::SUBDEVICE_90050503: return "SUBDEVICE_90050503";
        case PciSubDevice9005028C::SUBDEVICE_90050504: return "SUBDEVICE_90050504";
        case PciSubDevice9005028C::SUBDEVICE_90050505: return "SUBDEVICE_90050505";
        case PciSubDevice9005028C::SUBDEVICE_90050506: return "SUBDEVICE_90050506";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice9005028C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice9005028C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005028C::SUBDEVICE_90050500: return "Series 7 - ASR-7805 - 8 internal 6G SAS Port/PCIe 3.0";
        case PciSubDevice9005028C::SUBDEVICE_90050501: return "Series 7 - ASR-71605 - 16 internal 6G SAS Port/PCIe 3.0";
        case PciSubDevice9005028C::SUBDEVICE_90050502: return "Series 7 - ASR-71685 - 16 internal 8 external 6G SAS Port/PCIe 3.0";
        case PciSubDevice9005028C::SUBDEVICE_90050503: return "Series 7 - ASR-72405 - 24 internal 0 external 6G SAS Port/PCIe 3.0";
        case PciSubDevice9005028C::SUBDEVICE_90050504: return "Series 7 - ASR-7885 - 8 internal 8 external 6G SAS Port/PCIe 3.0";
        case PciSubDevice9005028C::SUBDEVICE_90050505: return "Series 7 Entry Level - ASR-71685E - 16 internal 8 external 6G SAS Port/PCIe 3.0";
        case PciSubDevice9005028C::SUBDEVICE_90050506: return "Series 7 Entry Level - ASR-72405E - 24 internal 0 external 6G SAS Port/PCIe 3.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028C_H
