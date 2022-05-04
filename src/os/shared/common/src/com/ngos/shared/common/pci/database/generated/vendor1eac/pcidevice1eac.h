// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EAC_PCIDEVICE1EAC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EAC_PCIDEVICE1EAC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1EAC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002
};



inline const char8* enumToString(PciDevice1EAC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EAC::NONE:        return "NONE";
        case PciDevice1EAC::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1EAC::DEVICE_1002: return "DEVICE_1002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1EAC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1EAC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EAC::DEVICE_1001: return "EM120R-GL LTE Modem";
        case PciDevice1EAC::DEVICE_1002: return "EM160R-GL LTE Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EAC_PCIDEVICE1EAC_H
