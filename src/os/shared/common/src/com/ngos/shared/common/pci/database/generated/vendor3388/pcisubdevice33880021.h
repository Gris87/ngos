// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33880021_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33880021_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice33880021: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1775C200 = 0x1775C200,
    SUBDEVICE_1775CE90 = 0x1775CE90,
    SUBDEVICE_4C531050 = 0x4C531050,
    SUBDEVICE_4C531080 = 0x4C531080,
    SUBDEVICE_4C531090 = 0x4C531090,
    SUBDEVICE_4C5310A0 = 0x4C5310A0,
    SUBDEVICE_4C533010 = 0x4C533010,
    SUBDEVICE_4C533011 = 0x4C533011,
    SUBDEVICE_4C534000 = 0x4C534000
};



inline const char8* enumToString(PciSubDevice33880021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice33880021::NONE:               return "NONE";
        case PciSubDevice33880021::SUBDEVICE_1775C200: return "SUBDEVICE_1775C200";
        case PciSubDevice33880021::SUBDEVICE_1775CE90: return "SUBDEVICE_1775CE90";
        case PciSubDevice33880021::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";
        case PciSubDevice33880021::SUBDEVICE_4C531080: return "SUBDEVICE_4C531080";
        case PciSubDevice33880021::SUBDEVICE_4C531090: return "SUBDEVICE_4C531090";
        case PciSubDevice33880021::SUBDEVICE_4C5310A0: return "SUBDEVICE_4C5310A0";
        case PciSubDevice33880021::SUBDEVICE_4C533010: return "SUBDEVICE_4C533010";
        case PciSubDevice33880021::SUBDEVICE_4C533011: return "SUBDEVICE_4C533011";
        case PciSubDevice33880021::SUBDEVICE_4C534000: return "SUBDEVICE_4C534000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice33880021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice33880021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice33880021::SUBDEVICE_1775C200: return "C2K CompactPCI interface bridge";
        case PciSubDevice33880021::SUBDEVICE_1775CE90: return "CE9";
        case PciSubDevice33880021::SUBDEVICE_4C531050: return "CT7 mainboard";
        case PciSubDevice33880021::SUBDEVICE_4C531080: return "CT8 mainboard";
        case PciSubDevice33880021::SUBDEVICE_4C531090: return "Cx9 mainboard";
        case PciSubDevice33880021::SUBDEVICE_4C5310A0: return "CA3/CR3 mainboard";
        case PciSubDevice33880021::SUBDEVICE_4C533010: return "PPCI mezzanine (32-bit PMC)";
        case PciSubDevice33880021::SUBDEVICE_4C533011: return "PPCI mezzanine (64-bit PMC)";
        case PciSubDevice33880021::SUBDEVICE_4C534000: return "PMCCARR1 carrier board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33880021_H
