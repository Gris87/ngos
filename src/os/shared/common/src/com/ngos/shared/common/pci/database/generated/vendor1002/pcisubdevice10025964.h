// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025964_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025964_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025964: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10025964 = 0x10025964,
    SUBDEVICE_1043C006 = 0x1043C006,
    SUBDEVICE_14584018 = 0x14584018,
    SUBDEVICE_14584032 = 0x14584032,
    SUBDEVICE_147B6191 = 0x147B6191,
    SUBDEVICE_148C2073 = 0x148C2073,
    SUBDEVICE_174B7C13 = 0x174B7C13,
    SUBDEVICE_17875964 = 0x17875964,
    SUBDEVICE_17AF2012 = 0x17AF2012,
    SUBDEVICE_18BC0170 = 0x18BC0170,
    SUBDEVICE_18BC0173 = 0x18BC0173
};



inline const char8* enumToString(PciSubDevice10025964 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025964::NONE:               return "NONE";
        case PciSubDevice10025964::SUBDEVICE_10025964: return "SUBDEVICE_10025964";
        case PciSubDevice10025964::SUBDEVICE_1043C006: return "SUBDEVICE_1043C006";
        case PciSubDevice10025964::SUBDEVICE_14584018: return "SUBDEVICE_14584018";
        case PciSubDevice10025964::SUBDEVICE_14584032: return "SUBDEVICE_14584032";
        case PciSubDevice10025964::SUBDEVICE_147B6191: return "SUBDEVICE_147B6191";
        case PciSubDevice10025964::SUBDEVICE_148C2073: return "SUBDEVICE_148C2073";
        case PciSubDevice10025964::SUBDEVICE_174B7C13: return "SUBDEVICE_174B7C13";
        case PciSubDevice10025964::SUBDEVICE_17875964: return "SUBDEVICE_17875964";
        case PciSubDevice10025964::SUBDEVICE_17AF2012: return "SUBDEVICE_17AF2012";
        case PciSubDevice10025964::SUBDEVICE_18BC0170: return "SUBDEVICE_18BC0170";
        case PciSubDevice10025964::SUBDEVICE_18BC0173: return "SUBDEVICE_18BC0173";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025964 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025964 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025964::SUBDEVICE_10025964: return "Radeon 9200 SE, 64-bit 128MB DDR, 200/166MHz";
        case PciSubDevice10025964::SUBDEVICE_1043C006: return "Radeon 9200 SE / TD / 128M";
        case PciSubDevice10025964::SUBDEVICE_14584018: return "R92S128T (Radeon 9200 SE 128MB)";
        case PciSubDevice10025964::SUBDEVICE_14584032: return "Radeon 9200 SE 128MB";
        case PciSubDevice10025964::SUBDEVICE_147B6191: return "R9200SE-DT";
        case PciSubDevice10025964::SUBDEVICE_148C2073: return "CN-AG92E";
        case PciSubDevice10025964::SUBDEVICE_174B7C13: return "Radeon 9200 SE";
        case PciSubDevice10025964::SUBDEVICE_17875964: return "Excalibur 9200SE VIVO 128M";
        case PciSubDevice10025964::SUBDEVICE_17AF2012: return "Radeon 9200 SE Excalibur";
        case PciSubDevice10025964::SUBDEVICE_18BC0170: return "Sapphire Radeon 9200 SE 128MB Game Buster";
        case PciSubDevice10025964::SUBDEVICE_18BC0173: return "GC-R9200L(SE)-C3H [Radeon 9200 Game Buster]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025964_H
