// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A5275_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A5275_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105A5275: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043807E = 0x1043807E,
    SUBDEVICE_105A0275 = 0x105A0275,
    SUBDEVICE_105A1275 = 0x105A1275,
    SUBDEVICE_1458B001 = 0x1458B001
};



inline const char8* enumToString(PciSubDevice105A5275 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A5275::NONE:               return "NONE";
        case PciSubDevice105A5275::SUBDEVICE_1043807E: return "SUBDEVICE_1043807E";
        case PciSubDevice105A5275::SUBDEVICE_105A0275: return "SUBDEVICE_105A0275";
        case PciSubDevice105A5275::SUBDEVICE_105A1275: return "SUBDEVICE_105A1275";
        case PciSubDevice105A5275::SUBDEVICE_1458B001: return "SUBDEVICE_1458B001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105A5275 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105A5275 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A5275::SUBDEVICE_1043807E: return "A7V333 motherboard.";
        case PciSubDevice105A5275::SUBDEVICE_105A0275: return "SuperTrak SX6000 IDE";
        case PciSubDevice105A5275::SUBDEVICE_105A1275: return "MBFastTrak133 Lite (tm) Controller (RAID mode)";
        case PciSubDevice105A5275::SUBDEVICE_1458B001: return "MBUltra 133";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A5275_H
