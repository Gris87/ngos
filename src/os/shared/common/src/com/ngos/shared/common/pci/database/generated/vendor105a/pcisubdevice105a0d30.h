// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A0D30_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A0D30_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105A0D30: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438042 = 0x10438042,
    SUBDEVICE_105A4D33 = 0x105A4D33
};



inline const char8* enumToString(PciSubDevice105A0D30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A0D30::NONE:               return "NONE";
        case PciSubDevice105A0D30::SUBDEVICE_10438042: return "SUBDEVICE_10438042";
        case PciSubDevice105A0D30::SUBDEVICE_105A4D33: return "SUBDEVICE_105A4D33";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105A0D30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105A0D30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A0D30::SUBDEVICE_10438042: return "AV7266-E South Bridge Promise RAID";
        case PciSubDevice105A0D30::SUBDEVICE_105A4D33: return "Ultra100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A0D30_H
