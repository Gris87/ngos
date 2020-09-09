// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135E_PCIDEVICE135E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135E_PCIDEVICE135E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice135E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5101 = 0x5101,
    DEVICE_7101 = 0x7101,
    DEVICE_7201 = 0x7201,
    DEVICE_7202 = 0x7202,
    DEVICE_7401 = 0x7401,
    DEVICE_7402 = 0x7402,
    DEVICE_7801 = 0x7801,
    DEVICE_7804 = 0x7804,
    DEVICE_8001 = 0x8001
};



inline const char8* enumToString(PciDevice135E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice135E::NONE:        return "NONE";
        case PciDevice135E::DEVICE_5101: return "DEVICE_5101";
        case PciDevice135E::DEVICE_7101: return "DEVICE_7101";
        case PciDevice135E::DEVICE_7201: return "DEVICE_7201";
        case PciDevice135E::DEVICE_7202: return "DEVICE_7202";
        case PciDevice135E::DEVICE_7401: return "DEVICE_7401";
        case PciDevice135E::DEVICE_7402: return "DEVICE_7402";
        case PciDevice135E::DEVICE_7801: return "DEVICE_7801";
        case PciDevice135E::DEVICE_7804: return "DEVICE_7804";
        case PciDevice135E::DEVICE_8001: return "DEVICE_8001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice135E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice135E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice135E::DEVICE_5101: return "Route 56.PCI - Multi-Protocol Serial Interface (Zilog Z16C32)";
        case PciDevice135E::DEVICE_7101: return "Single Port RS-232/422/485/530";
        case PciDevice135E::DEVICE_7201: return "Dual Port RS-232/422/485 Interface";
        case PciDevice135E::DEVICE_7202: return "Dual Port RS-232 Interface";
        case PciDevice135E::DEVICE_7401: return "Four Port RS-232 Interface";
        case PciDevice135E::DEVICE_7402: return "Four Port RS-422/485 Interface";
        case PciDevice135E::DEVICE_7801: return "Eight Port RS-232 Interface";
        case PciDevice135E::DEVICE_7804: return "Eight Port RS-232/422/485 Interface";
        case PciDevice135E::DEVICE_8001: return "8001 Digital I/O Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135E_PCIDEVICE135E_H
