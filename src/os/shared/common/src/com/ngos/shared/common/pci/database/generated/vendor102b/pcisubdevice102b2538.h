// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2538_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2538_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B2538: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B0847 = 0x102B0847,
    SUBDEVICE_102B08C7 = 0x102B08C7,
    SUBDEVICE_102B0907 = 0x102B0907,
    SUBDEVICE_102B0947 = 0x102B0947,
    SUBDEVICE_102B0987 = 0x102B0987,
    SUBDEVICE_102B1047 = 0x102B1047,
    SUBDEVICE_102B1087 = 0x102B1087,
    SUBDEVICE_102B1801 = 0x102B1801,
    SUBDEVICE_102B2538 = 0x102B2538,
    SUBDEVICE_102B3007 = 0x102B3007,
    SUBDEVICE_102B3087 = 0x102B3087,
    SUBDEVICE_102B30C7 = 0x102B30C7
};



inline const char8* enumToString(PciSubDevice102B2538 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B2538::NONE:               return "NONE";
        case PciSubDevice102B2538::SUBDEVICE_102B0847: return "SUBDEVICE_102B0847";
        case PciSubDevice102B2538::SUBDEVICE_102B08C7: return "SUBDEVICE_102B08C7";
        case PciSubDevice102B2538::SUBDEVICE_102B0907: return "SUBDEVICE_102B0907";
        case PciSubDevice102B2538::SUBDEVICE_102B0947: return "SUBDEVICE_102B0947";
        case PciSubDevice102B2538::SUBDEVICE_102B0987: return "SUBDEVICE_102B0987";
        case PciSubDevice102B2538::SUBDEVICE_102B1047: return "SUBDEVICE_102B1047";
        case PciSubDevice102B2538::SUBDEVICE_102B1087: return "SUBDEVICE_102B1087";
        case PciSubDevice102B2538::SUBDEVICE_102B1801: return "SUBDEVICE_102B1801";
        case PciSubDevice102B2538::SUBDEVICE_102B2538: return "SUBDEVICE_102B2538";
        case PciSubDevice102B2538::SUBDEVICE_102B3007: return "SUBDEVICE_102B3007";
        case PciSubDevice102B2538::SUBDEVICE_102B3087: return "SUBDEVICE_102B3087";
        case PciSubDevice102B2538::SUBDEVICE_102B30C7: return "SUBDEVICE_102B30C7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B2538 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B2538 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B2538::SUBDEVICE_102B0847: return "RAD PCIe";
        case PciSubDevice102B2538::SUBDEVICE_102B08C7: return "Millennium P650 PCIe 128MB";
        case PciSubDevice102B2538::SUBDEVICE_102B0907: return "Millennium P650 PCIe 64MB";
        case PciSubDevice102B2538::SUBDEVICE_102B0947: return "Parhelia APVe";
        case PciSubDevice102B2538::SUBDEVICE_102B0987: return "ATC PCIe 4MP";
        case PciSubDevice102B2538::SUBDEVICE_102B1047: return "Millennium P650 LP PCIe 128MB";
        case PciSubDevice102B2538::SUBDEVICE_102B1087: return "Millennium P650 LP PCIe 64MB";
        case PciSubDevice102B2538::SUBDEVICE_102B1801: return "Millennium P650 PCIe x1";
        case PciSubDevice102B2538::SUBDEVICE_102B2538: return "Parhelia APVe";
        case PciSubDevice102B2538::SUBDEVICE_102B3007: return "QID Low-profile PCIe";
        case PciSubDevice102B2538::SUBDEVICE_102B3087: return "Aurora VX3mp";
        case PciSubDevice102B2538::SUBDEVICE_102B30C7: return "QID LP PCIe";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2538_H
