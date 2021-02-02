// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE1415C158_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE1415C158_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1415C158: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_E4BFC504 = 0xE4BFC504,
    SUBDEVICE_E4BFD551 = 0xE4BFD551
};



inline const char8* enumToString(PciSubDevice1415C158 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1415C158::NONE:               return "NONE";
        case PciSubDevice1415C158::SUBDEVICE_E4BFC504: return "SUBDEVICE_E4BFC504";
        case PciSubDevice1415C158::SUBDEVICE_E4BFD551: return "SUBDEVICE_E4BFD551";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1415C158 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1415C158 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1415C158::SUBDEVICE_E4BFC504: return "CP4-SCAT Wireless Technologies Carrier Board";
        case PciSubDevice1415C158::SUBDEVICE_E4BFD551: return "DU1-MUSTANG Dual-Port RS-485 Interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE1415C158_H
