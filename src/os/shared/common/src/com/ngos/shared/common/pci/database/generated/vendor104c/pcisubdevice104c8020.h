// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8020: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102800D8 = 0x102800D8,
    SUBDEVICE_104D80E2 = 0x104D80E2,
    SUBDEVICE_11BD000F = 0x11BD000F,
    SUBDEVICE_11BD001C = 0x11BD001C,
    SUBDEVICE_14438010 = 0x14438010
};



inline const char8* enumToString(PciSubDevice104C8020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8020::NONE:               return "NONE";
        case PciSubDevice104C8020::SUBDEVICE_102800D8: return "SUBDEVICE_102800D8";
        case PciSubDevice104C8020::SUBDEVICE_104D80E2: return "SUBDEVICE_104D80E2";
        case PciSubDevice104C8020::SUBDEVICE_11BD000F: return "SUBDEVICE_11BD000F";
        case PciSubDevice104C8020::SUBDEVICE_11BD001C: return "SUBDEVICE_11BD001C";
        case PciSubDevice104C8020::SUBDEVICE_14438010: return "SUBDEVICE_14438010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8020::SUBDEVICE_102800D8: return "Precision 530";
        case PciSubDevice104C8020::SUBDEVICE_104D80E2: return "VAIO PCV-J200";
        case PciSubDevice104C8020::SUBDEVICE_11BD000F: return "Studio DV500-1394";
        case PciSubDevice104C8020::SUBDEVICE_11BD001C: return "Excalibur 4.1";
        case PciSubDevice104C8020::SUBDEVICE_14438010: return "FireBoard400-OHCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8020_H
