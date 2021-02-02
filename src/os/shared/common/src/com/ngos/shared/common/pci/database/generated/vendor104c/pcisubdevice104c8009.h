// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8009: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104D8032 = 0x104D8032,
    SUBDEVICE_14438010 = 0x14438010
};



inline const char8* enumToString(PciSubDevice104C8009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8009::NONE:               return "NONE";
        case PciSubDevice104C8009::SUBDEVICE_104D8032: return "SUBDEVICE_104D8032";
        case PciSubDevice104C8009::SUBDEVICE_14438010: return "SUBDEVICE_14438010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8009::SUBDEVICE_104D8032: return "8032 OHCI i.LINK (IEEE 1394) Controller";
        case PciSubDevice104C8009::SUBDEVICE_14438010: return "FireBoard400-OHCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8009_H
