// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AEA_PCIDEVICE1AEA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AEA_PCIDEVICE1AEA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AEA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6601 = 0x6601,
    DEVICE_6621 = 0x6621,
    DEVICE_6625 = 0x6625
};



inline const char8* enumToString(PciDevice1AEA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AEA::NONE:        return "NONE";
        case PciDevice1AEA::DEVICE_6601: return "DEVICE_6601";
        case PciDevice1AEA::DEVICE_6621: return "DEVICE_6621";
        case PciDevice1AEA::DEVICE_6625: return "DEVICE_6625";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AEA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AEA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AEA::DEVICE_6601: return "AU6601 PCI-E Flash card reader controller";
        case PciDevice1AEA::DEVICE_6621: return "AU6621 PCI-E Flash card reader controller";
        case PciDevice1AEA::DEVICE_6625: return "AU6625 PCI-E Flash card reader controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AEA_PCIDEVICE1AEA_H
