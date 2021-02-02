// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8019_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8019_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8019: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11BD000A = 0x11BD000A,
    SUBDEVICE_11BD000E = 0x11BD000E,
    SUBDEVICE_14438010 = 0x14438010,
    SUBDEVICE_E4BF1010 = 0xE4BF1010
};



inline const char8* enumToString(PciSubDevice104C8019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8019::NONE:               return "NONE";
        case PciSubDevice104C8019::SUBDEVICE_11BD000A: return "SUBDEVICE_11BD000A";
        case PciSubDevice104C8019::SUBDEVICE_11BD000E: return "SUBDEVICE_11BD000E";
        case PciSubDevice104C8019::SUBDEVICE_14438010: return "SUBDEVICE_14438010";
        case PciSubDevice104C8019::SUBDEVICE_E4BF1010: return "SUBDEVICE_E4BF1010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8019::SUBDEVICE_11BD000A: return "Studio DV500-1394";
        case PciSubDevice104C8019::SUBDEVICE_11BD000E: return "Studio DV";
        case PciSubDevice104C8019::SUBDEVICE_14438010: return "FireBoard400-OHCI";
        case PciSubDevice104C8019::SUBDEVICE_E4BF1010: return "CF2-1-CYMBAL";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8019_H
