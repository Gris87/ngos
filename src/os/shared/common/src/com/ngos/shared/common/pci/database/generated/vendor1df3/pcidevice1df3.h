// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCIDEVICE1DF3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCIDEVICE1DF3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DF3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0201 = 0x0201,
    DEVICE_0202 = 0x0202,
    DEVICE_0203 = 0x0203,
    DEVICE_0204 = 0x0204
};



inline const char8* enumToString(PciDevice1DF3 device1DF3) // TEST: NO
{
    // COMMON_LT((" | device1DF3 = %u", device1DF3)); // Commented to avoid bad looking logs



    switch (device1DF3)
    {
        case PciDevice1DF3::NONE:        return "NONE";
        case PciDevice1DF3::DEVICE_0201: return "DEVICE_0201";
        case PciDevice1DF3::DEVICE_0202: return "DEVICE_0202";
        case PciDevice1DF3::DEVICE_0203: return "DEVICE_0203";
        case PciDevice1DF3::DEVICE_0204: return "DEVICE_0204";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DF3 device1DF3) // TEST: NO
{
    // COMMON_LT((" | device1DF3 = %u", device1DF3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1DF3, enumToString(device1DF3));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DF3 device1DF3) // TEST: NO
{
    // COMMON_LT((" | device1DF3 = %u", device1DF3)); // Commented to avoid bad looking logs



    switch (device1DF3)
    {
        case PciDevice1DF3::DEVICE_0201: return "ACE-NIC40 Programmable Network Accelerator";
        case PciDevice1DF3::DEVICE_0202: return "ACE-NIC50 Programmable Network Accelerator";
        case PciDevice1DF3::DEVICE_0203: return "ACE-NIC100 Programmable Network Accelerator";
        case PciDevice1DF3::DEVICE_0204: return "ACE-NIC-NID Programmable Network Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCIDEVICE1DF3_H
