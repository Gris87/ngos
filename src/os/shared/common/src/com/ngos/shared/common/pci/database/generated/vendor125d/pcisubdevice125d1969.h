// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1969_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1969_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice125D1969: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140166 = 0x10140166,
    SUBDEVICE_125D8888 = 0x125D8888,
    SUBDEVICE_125D8898 = 0x125D8898,
    SUBDEVICE_153B111B = 0x153B111B
};



inline const char8* enumToString(PciSubDevice125D1969 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1969::NONE:               return "NONE";
        case PciSubDevice125D1969::SUBDEVICE_10140166: return "SUBDEVICE_10140166";
        case PciSubDevice125D1969::SUBDEVICE_125D8888: return "SUBDEVICE_125D8888";
        case PciSubDevice125D1969::SUBDEVICE_125D8898: return "SUBDEVICE_125D8898";
        case PciSubDevice125D1969::SUBDEVICE_153B111B: return "SUBDEVICE_153B111B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice125D1969 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice125D1969 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1969::SUBDEVICE_10140166: return "ES1969 SOLO-1 AudioDrive on IBM Aptiva Mainboard";
        case PciSubDevice125D1969::SUBDEVICE_125D8888: return "Solo-1 Audio Adapter";
        case PciSubDevice125D1969::SUBDEVICE_125D8898: return "ES1938S TTSOLO1-SL [TerraTec 128i PCI]";
        case PciSubDevice125D1969::SUBDEVICE_153B111B: return "Terratec 128i PCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1969_H
