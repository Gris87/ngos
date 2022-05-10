// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1055_PCIDEVICE1055_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1055_PCIDEVICE1055_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1055: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7430 = 0x7430,
    DEVICE_7431 = 0x7431,
    DEVICE_9130 = 0x9130,
    DEVICE_9460 = 0x9460,
    DEVICE_9462 = 0x9462,
    DEVICE_9463 = 0x9463,
    DEVICE_E420 = 0xE420
};



inline const char8* enumToString(PciDevice1055 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1055::NONE:        return "NONE";
        case PciDevice1055::DEVICE_7430: return "DEVICE_7430";
        case PciDevice1055::DEVICE_7431: return "DEVICE_7431";
        case PciDevice1055::DEVICE_9130: return "DEVICE_9130";
        case PciDevice1055::DEVICE_9460: return "DEVICE_9460";
        case PciDevice1055::DEVICE_9462: return "DEVICE_9462";
        case PciDevice1055::DEVICE_9463: return "DEVICE_9463";
        case PciDevice1055::DEVICE_E420: return "DEVICE_E420";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1055 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1055 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1055::DEVICE_7430: return "LAN7430";
        case PciDevice1055::DEVICE_7431: return "LAN7431";
        case PciDevice1055::DEVICE_9130: return "SLC90E66 [Victory66] IDE";
        case PciDevice1055::DEVICE_9460: return "SLC90E66 [Victory66] ISA";
        case PciDevice1055::DEVICE_9462: return "SLC90E66 [Victory66] USB";
        case PciDevice1055::DEVICE_9463: return "SLC90E66 [Victory66] ACPI";
        case PciDevice1055::DEVICE_E420: return "LAN9420/LAN9420i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1055_PCIDEVICE1055_H
