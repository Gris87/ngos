// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2539_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2539_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B2539: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B0040 = 0x102B0040,
    SUBDEVICE_102B0042 = 0x102B0042,
    SUBDEVICE_102B0043 = 0x102B0043,
    SUBDEVICE_102B0080 = 0x102B0080,
    SUBDEVICE_102B0081 = 0x102B0081,
    SUBDEVICE_102B0082 = 0x102B0082,
    SUBDEVICE_102B00C0 = 0x102B00C0,
    SUBDEVICE_102B00C2 = 0x102B00C2,
    SUBDEVICE_102B00C3 = 0x102B00C3,
    SUBDEVICE_102B0101 = 0x102B0101,
    SUBDEVICE_102B0140 = 0x102B0140,
    SUBDEVICE_102B0180 = 0x102B0180
};



inline const char8* enumToString(PciSubDevice102B2539 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B2539::NONE:               return "NONE";
        case PciSubDevice102B2539::SUBDEVICE_102B0040: return "SUBDEVICE_102B0040";
        case PciSubDevice102B2539::SUBDEVICE_102B0042: return "SUBDEVICE_102B0042";
        case PciSubDevice102B2539::SUBDEVICE_102B0043: return "SUBDEVICE_102B0043";
        case PciSubDevice102B2539::SUBDEVICE_102B0080: return "SUBDEVICE_102B0080";
        case PciSubDevice102B2539::SUBDEVICE_102B0081: return "SUBDEVICE_102B0081";
        case PciSubDevice102B2539::SUBDEVICE_102B0082: return "SUBDEVICE_102B0082";
        case PciSubDevice102B2539::SUBDEVICE_102B00C0: return "SUBDEVICE_102B00C0";
        case PciSubDevice102B2539::SUBDEVICE_102B00C2: return "SUBDEVICE_102B00C2";
        case PciSubDevice102B2539::SUBDEVICE_102B00C3: return "SUBDEVICE_102B00C3";
        case PciSubDevice102B2539::SUBDEVICE_102B0101: return "SUBDEVICE_102B0101";
        case PciSubDevice102B2539::SUBDEVICE_102B0140: return "SUBDEVICE_102B0140";
        case PciSubDevice102B2539::SUBDEVICE_102B0180: return "SUBDEVICE_102B0180";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B2539 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B2539 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B2539::SUBDEVICE_102B0040: return "Millennium P690 PCIe x16";
        case PciSubDevice102B2539::SUBDEVICE_102B0042: return "ONYX";
        case PciSubDevice102B2539::SUBDEVICE_102B0043: return "SPECTRA";
        case PciSubDevice102B2539::SUBDEVICE_102B0080: return "Millennium P690 Plus LP PCIe x16";
        case PciSubDevice102B2539::SUBDEVICE_102B0081: return "Millennium P690 LP PCIe x16";
        case PciSubDevice102B2539::SUBDEVICE_102B0082: return "RAD LPX PCIe x16";
        case PciSubDevice102B2539::SUBDEVICE_102B00C0: return "Millennium P690 Plus LP PCI";
        case PciSubDevice102B2539::SUBDEVICE_102B00C2: return "Millennium P690 LP PCI";
        case PciSubDevice102B2539::SUBDEVICE_102B00C3: return "RAD LPX PCI";
        case PciSubDevice102B2539::SUBDEVICE_102B0101: return "Millennium P690 PCI";
        case PciSubDevice102B2539::SUBDEVICE_102B0140: return "Millennium P690 LP PCIe x1";
        case PciSubDevice102B2539::SUBDEVICE_102B0180: return "Display Wall IP Decode 128 MB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2539_H
