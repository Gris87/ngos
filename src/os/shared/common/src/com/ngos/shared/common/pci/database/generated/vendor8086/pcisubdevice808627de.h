// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627DE: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801AD = 0x102801AD,
    SUBDEVICE_14627267 = 0x14627267,
    SUBDEVICE_177511CC = 0x177511CC
};



inline const char8* enumToString(PciSubDevice808627DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627DE::NONE:               return "NONE";
        case PciSubDevice808627DE::SUBDEVICE_102801AD: return "SUBDEVICE_102801AD";
        case PciSubDevice808627DE::SUBDEVICE_14627267: return "SUBDEVICE_14627267";
        case PciSubDevice808627DE::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627DE::SUBDEVICE_102801AD: return "OptiPlex GX620";
        case PciSubDevice808627DE::SUBDEVICE_14627267: return "Realtek ALC883 Audio Controller";
        case PciSubDevice808627DE::SUBDEVICE_177511CC: return "CC11 integrated audio (AD1981BL codec)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DE_H
