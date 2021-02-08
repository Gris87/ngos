// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105E8003 = 0x105E8003,
    SUBDEVICE_14438003 = 0x14438003,
    SUBDEVICE_14438005 = 0x14438005,
    SUBDEVICE_14438006 = 0x14438006,
    SUBDEVICE_E4BF1010 = 0xE4BF1010,
    SUBDEVICE_E4BF1020 = 0xE4BF1020,
    SUBDEVICE_E4BF1040 = 0xE4BF1040
};



inline const char8* enumToString(PciSubDevice104C8000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8000::NONE:               return "NONE";
        case PciSubDevice104C8000::SUBDEVICE_105E8003: return "SUBDEVICE_105E8003";
        case PciSubDevice104C8000::SUBDEVICE_14438003: return "SUBDEVICE_14438003";
        case PciSubDevice104C8000::SUBDEVICE_14438005: return "SUBDEVICE_14438005";
        case PciSubDevice104C8000::SUBDEVICE_14438006: return "SUBDEVICE_14438006";
        case PciSubDevice104C8000::SUBDEVICE_E4BF1010: return "SUBDEVICE_E4BF1010";
        case PciSubDevice104C8000::SUBDEVICE_E4BF1020: return "SUBDEVICE_E4BF1020";
        case PciSubDevice104C8000::SUBDEVICE_E4BF1040: return "SUBDEVICE_E4BF1040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8000::SUBDEVICE_105E8003: return "FireBoard200";
        case PciSubDevice104C8000::SUBDEVICE_14438003: return "FireBoard200";
        case PciSubDevice104C8000::SUBDEVICE_14438005: return "FireBoard400";
        case PciSubDevice104C8000::SUBDEVICE_14438006: return "FireBoard400";
        case PciSubDevice104C8000::SUBDEVICE_E4BF1010: return "CF1-1-SNARE";
        case PciSubDevice104C8000::SUBDEVICE_E4BF1020: return "CF1-2-SNARE";
        case PciSubDevice104C8000::SUBDEVICE_E4BF1040: return "FireCompact400";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8000_H
