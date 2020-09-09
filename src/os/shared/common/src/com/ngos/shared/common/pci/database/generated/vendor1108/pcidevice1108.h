// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1108_PCIDEVICE1108_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1108_PCIDEVICE1108_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1108: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_0101 = 0x0101,
    DEVICE_0105 = 0x0105,
    DEVICE_0108 = 0x0108,
    DEVICE_0138 = 0x0138,
    DEVICE_0139 = 0x0139,
    DEVICE_013C = 0x013C,
    DEVICE_013D = 0x013D
};



inline const char8* enumToString(PciDevice1108 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1108::NONE:        return "NONE";
        case PciDevice1108::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1108::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1108::DEVICE_0105: return "DEVICE_0105";
        case PciDevice1108::DEVICE_0108: return "DEVICE_0108";
        case PciDevice1108::DEVICE_0138: return "DEVICE_0138";
        case PciDevice1108::DEVICE_0139: return "DEVICE_0139";
        case PciDevice1108::DEVICE_013C: return "DEVICE_013C";
        case PciDevice1108::DEVICE_013D: return "DEVICE_013D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1108 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1108 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1108::DEVICE_0100: return "p1690plus_AA";
        case PciDevice1108::DEVICE_0101: return "p1690plus_AB";
        case PciDevice1108::DEVICE_0105: return "P1690Plus";
        case PciDevice1108::DEVICE_0108: return "P1690Plus";
        case PciDevice1108::DEVICE_0138: return "P1690Plus";
        case PciDevice1108::DEVICE_0139: return "P1690Plus";
        case PciDevice1108::DEVICE_013C: return "P1690Plus";
        case PciDevice1108::DEVICE_013D: return "P1690Plus";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1108_PCIDEVICE1108_H
