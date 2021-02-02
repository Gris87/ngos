// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14BC_PCIDEVICE14BC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14BC_PCIDEVICE14BC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14BC: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_D002 = 0xD002,
    DEVICE_D00F = 0xD00F
};



inline const char8* enumToString(PciDevice14BC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14BC::NONE:        return "NONE";
        case PciDevice14BC::DEVICE_D002: return "DEVICE_D002";
        case PciDevice14BC::DEVICE_D00F: return "DEVICE_D00F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14BC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14BC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14BC::DEVICE_D002: return "Pulsar [PCI ADSL Card]";
        case PciDevice14BC::DEVICE_D00F: return "Pulsar [PCI ADSL Card]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14BC_PCIDEVICE14BC_H
