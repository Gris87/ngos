// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D5348_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D5348_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105D5348: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105D0037 = 0x105D0037,
    SUBDEVICE_11A40028 = 0x11A40028,
    SUBDEVICE_11A40038 = 0x11A40038
};



inline const char8* enumToString(PciSubDevice105D5348 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105D5348::NONE:               return "NONE";
        case PciSubDevice105D5348::SUBDEVICE_105D0037: return "SUBDEVICE_105D0037";
        case PciSubDevice105D5348::SUBDEVICE_11A40028: return "SUBDEVICE_11A40028";
        case PciSubDevice105D5348::SUBDEVICE_11A40038: return "SUBDEVICE_11A40038";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105D5348 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105D5348 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105D5348::SUBDEVICE_105D0037: return "Revolution IV-FP AGP (For SGI 1600SW)";
        case PciSubDevice105D5348::SUBDEVICE_11A40028: return "PVS5600M";
        case PciSubDevice105D5348::SUBDEVICE_11A40038: return "PVS5600D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D5348_H
