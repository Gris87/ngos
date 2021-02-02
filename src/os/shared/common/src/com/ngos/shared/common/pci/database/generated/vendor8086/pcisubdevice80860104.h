// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860104_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860104_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860104: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804A3 = 0x102804A3,
    SUBDEVICE_102804B2 = 0x102804B2,
    SUBDEVICE_102804DA = 0x102804DA,
    SUBDEVICE_106B00DC = 0x106B00DC,
    SUBDEVICE_144DC652 = 0x144DC652,
    SUBDEVICE_17AA21CF = 0x17AA21CF
};



inline const char8* enumToString(PciSubDevice80860104 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860104::NONE:               return "NONE";
        case PciSubDevice80860104::SUBDEVICE_102804A3: return "SUBDEVICE_102804A3";
        case PciSubDevice80860104::SUBDEVICE_102804B2: return "SUBDEVICE_102804B2";
        case PciSubDevice80860104::SUBDEVICE_102804DA: return "SUBDEVICE_102804DA";
        case PciSubDevice80860104::SUBDEVICE_106B00DC: return "SUBDEVICE_106B00DC";
        case PciSubDevice80860104::SUBDEVICE_144DC652: return "SUBDEVICE_144DC652";
        case PciSubDevice80860104::SUBDEVICE_17AA21CF: return "SUBDEVICE_17AA21CF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860104 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860104 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860104::SUBDEVICE_102804A3: return "Precision M4600";
        case PciSubDevice80860104::SUBDEVICE_102804B2: return "Vostro 3350";
        case PciSubDevice80860104::SUBDEVICE_102804DA: return "Vostro 3750";
        case PciSubDevice80860104::SUBDEVICE_106B00DC: return "MacBookPro8, 2 [Core i7, 15\", 2011]";
        case PciSubDevice80860104::SUBDEVICE_144DC652: return "NP300E5C series laptop";
        case PciSubDevice80860104::SUBDEVICE_17AA21CF: return "ThinkPad T520";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860104_H
