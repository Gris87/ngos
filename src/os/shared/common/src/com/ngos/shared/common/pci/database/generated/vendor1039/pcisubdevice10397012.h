// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397012_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397012_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10397012: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190F05 = 0x10190F05,
    SUBDEVICE_10397012 = 0x10397012,
    SUBDEVICE_1043818F = 0x1043818F,
    SUBDEVICE_13F60300 = 0x13F60300,
    SUBDEVICE_14625850 = 0x14625850,
    SUBDEVICE_14627010 = 0x14627010,
    SUBDEVICE_15BD1001 = 0x15BD1001,
    SUBDEVICE_1734109F = 0x1734109F,
    SUBDEVICE_18497012 = 0x18497012
};



inline const char8* enumToString(PciSubDevice10397012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10397012::NONE:               return "NONE";
        case PciSubDevice10397012::SUBDEVICE_10190F05: return "SUBDEVICE_10190F05";
        case PciSubDevice10397012::SUBDEVICE_10397012: return "SUBDEVICE_10397012";
        case PciSubDevice10397012::SUBDEVICE_1043818F: return "SUBDEVICE_1043818F";
        case PciSubDevice10397012::SUBDEVICE_13F60300: return "SUBDEVICE_13F60300";
        case PciSubDevice10397012::SUBDEVICE_14625850: return "SUBDEVICE_14625850";
        case PciSubDevice10397012::SUBDEVICE_14627010: return "SUBDEVICE_14627010";
        case PciSubDevice10397012::SUBDEVICE_15BD1001: return "SUBDEVICE_15BD1001";
        case PciSubDevice10397012::SUBDEVICE_1734109F: return "SUBDEVICE_1734109F";
        case PciSubDevice10397012::SUBDEVICE_18497012: return "SUBDEVICE_18497012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10397012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10397012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10397012::SUBDEVICE_10190F05: return "A928 (i-Buddie)";
        case PciSubDevice10397012::SUBDEVICE_10397012: return "SiS 7012 onboard [Asus P4SC-EA] AC'97 Sound Controller";
        case PciSubDevice10397012::SUBDEVICE_1043818F: return "A8S-X Motherboard";
        case PciSubDevice10397012::SUBDEVICE_13F60300: return "CMI9739(A) on ECS K7S series motherboard";
        case PciSubDevice10397012::SUBDEVICE_14625850: return "MSI 648 Max (MS-6585)";
        case PciSubDevice10397012::SUBDEVICE_14627010: return "MS-6701 motherboard";
        case PciSubDevice10397012::SUBDEVICE_15BD1001: return "DFI 661FX motherboard";
        case PciSubDevice10397012::SUBDEVICE_1734109F: return "D2030-A1 Motherboard";
        case PciSubDevice10397012::SUBDEVICE_18497012: return "K7S41GX motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397012_H
