// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025D44_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025D44_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025D44: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14584019 = 0x14584019,
    SUBDEVICE_14584032 = 0x14584032,
    SUBDEVICE_147B6190 = 0x147B6190,
    SUBDEVICE_174B7C12 = 0x174B7C12,
    SUBDEVICE_17875965 = 0x17875965,
    SUBDEVICE_17AF2013 = 0x17AF2013,
    SUBDEVICE_18BC0171 = 0x18BC0171,
    SUBDEVICE_18BC0172 = 0x18BC0172
};



inline const char8* enumToString(PciSubDevice10025D44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025D44::NONE:               return "NONE";
        case PciSubDevice10025D44::SUBDEVICE_14584019: return "SUBDEVICE_14584019";
        case PciSubDevice10025D44::SUBDEVICE_14584032: return "SUBDEVICE_14584032";
        case PciSubDevice10025D44::SUBDEVICE_147B6190: return "SUBDEVICE_147B6190";
        case PciSubDevice10025D44::SUBDEVICE_174B7C12: return "SUBDEVICE_174B7C12";
        case PciSubDevice10025D44::SUBDEVICE_17875965: return "SUBDEVICE_17875965";
        case PciSubDevice10025D44::SUBDEVICE_17AF2013: return "SUBDEVICE_17AF2013";
        case PciSubDevice10025D44::SUBDEVICE_18BC0171: return "SUBDEVICE_18BC0171";
        case PciSubDevice10025D44::SUBDEVICE_18BC0172: return "SUBDEVICE_18BC0172";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025D44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025D44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025D44::SUBDEVICE_14584019: return "Radeon 9200 SE (Secondary)";
        case PciSubDevice10025D44::SUBDEVICE_14584032: return "Radeon 9200 SE 128MB";
        case PciSubDevice10025D44::SUBDEVICE_147B6190: return "R9200SE-DT (Secondary)";
        case PciSubDevice10025D44::SUBDEVICE_174B7C12: return "Radeon 9200 SE (Secondary)";
        case PciSubDevice10025D44::SUBDEVICE_17875965: return "Excalibur 9200SE VIVO 128M (Secondary)";
        case PciSubDevice10025D44::SUBDEVICE_17AF2013: return "Radeon 9200 SE Excalibur (Secondary)";
        case PciSubDevice10025D44::SUBDEVICE_18BC0171: return "Radeon 9200 SE 128MB Game Buster (Secondary)";
        case PciSubDevice10025D44::SUBDEVICE_18BC0172: return "GC-R9200L(SE)-C3H [Radeon 9200 Game Buster]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025D44_H
