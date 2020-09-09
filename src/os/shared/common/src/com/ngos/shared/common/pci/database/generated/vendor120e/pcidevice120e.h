// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR120E_PCIDEVICE120E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR120E_PCIDEVICE120E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice120E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0103 = 0x0103,
    DEVICE_0104 = 0x0104,
    DEVICE_0105 = 0x0105,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_0300 = 0x0300,
    DEVICE_0301 = 0x0301,
    DEVICE_0310 = 0x0310,
    DEVICE_0311 = 0x0311,
    DEVICE_0320 = 0x0320,
    DEVICE_0321 = 0x0321,
    DEVICE_0400 = 0x0400
};



inline const char8* enumToString(PciDevice120E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice120E::NONE:        return "NONE";
        case PciDevice120E::DEVICE_0100: return "DEVICE_0100";
        case PciDevice120E::DEVICE_0101: return "DEVICE_0101";
        case PciDevice120E::DEVICE_0102: return "DEVICE_0102";
        case PciDevice120E::DEVICE_0103: return "DEVICE_0103";
        case PciDevice120E::DEVICE_0104: return "DEVICE_0104";
        case PciDevice120E::DEVICE_0105: return "DEVICE_0105";
        case PciDevice120E::DEVICE_0200: return "DEVICE_0200";
        case PciDevice120E::DEVICE_0201: return "DEVICE_0201";
        case PciDevice120E::DEVICE_0300: return "DEVICE_0300";
        case PciDevice120E::DEVICE_0301: return "DEVICE_0301";
        case PciDevice120E::DEVICE_0310: return "DEVICE_0310";
        case PciDevice120E::DEVICE_0311: return "DEVICE_0311";
        case PciDevice120E::DEVICE_0320: return "DEVICE_0320";
        case PciDevice120E::DEVICE_0321: return "DEVICE_0321";
        case PciDevice120E::DEVICE_0400: return "DEVICE_0400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice120E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice120E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice120E::DEVICE_0100: return "Cyclom-Y below first megabyte";
        case PciDevice120E::DEVICE_0101: return "Cyclom-Y above first megabyte";
        case PciDevice120E::DEVICE_0102: return "Cyclom-4Y below first megabyte";
        case PciDevice120E::DEVICE_0103: return "Cyclom-4Y above first megabyte";
        case PciDevice120E::DEVICE_0104: return "Cyclom-8Y below first megabyte";
        case PciDevice120E::DEVICE_0105: return "Cyclom-8Y above first megabyte";
        case PciDevice120E::DEVICE_0200: return "Cyclades-Z below first megabyte";
        case PciDevice120E::DEVICE_0201: return "Cyclades-Z above first megabyte";
        case PciDevice120E::DEVICE_0300: return "PC300/RSV or /X21 (2 ports)";
        case PciDevice120E::DEVICE_0301: return "PC300/RSV or /X21 (1 port)";
        case PciDevice120E::DEVICE_0310: return "PC300/TE (2 ports)";
        case PciDevice120E::DEVICE_0311: return "PC300/TE (1 port)";
        case PciDevice120E::DEVICE_0320: return "PC300/TE-M (2 ports)";
        case PciDevice120E::DEVICE_0321: return "PC300/TE-M (1 port)";
        case PciDevice120E::DEVICE_0400: return "PC400";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR120E_PCIDEVICE120E_H
