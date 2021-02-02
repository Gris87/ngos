// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1221_PCIDEVICE1221_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1221_PCIDEVICE1221_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1221: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_9172 = 0x9172,
    DEVICE_91A2 = 0x91A2,
    DEVICE_91C3 = 0x91C3,
    DEVICE_B152 = 0xB152,
    DEVICE_C103 = 0xC103
};



inline const char8* enumToString(PciDevice1221 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1221::NONE:        return "NONE";
        case PciDevice1221::DEVICE_9172: return "DEVICE_9172";
        case PciDevice1221::DEVICE_91A2: return "DEVICE_91A2";
        case PciDevice1221::DEVICE_91C3: return "DEVICE_91C3";
        case PciDevice1221::DEVICE_B152: return "DEVICE_B152";
        case PciDevice1221::DEVICE_C103: return "DEVICE_C103";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1221 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1221 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1221::DEVICE_9172: return "PO-64L(PCI)H [Isolated Digital Output Board for PCI]";
        case PciDevice1221::DEVICE_91A2: return "PO-32L(PCI)H [Isolated Digital Output Board for PCI]";
        case PciDevice1221::DEVICE_91C3: return "DA16-16(LPCI)L [Un-insulated highly precise analog output board for Low Profile PCI]";
        case PciDevice1221::DEVICE_B152: return "DIO-96D2-LPCI";
        case PciDevice1221::DEVICE_C103: return "ADA16-32/2(PCI)F [High-Speed Analog I/O Board for PCI]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1221_PCIDEVICE1221_H
