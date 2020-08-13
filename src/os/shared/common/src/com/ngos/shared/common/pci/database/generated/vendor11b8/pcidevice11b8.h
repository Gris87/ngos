// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B8_PCIDEVICE11B8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B8_PCIDEVICE11B8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11B8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice11B8 device11B8) // TEST: NO
{
    // COMMON_LT((" | device11B8 = %u", device11B8)); // Commented to avoid bad looking logs



    switch (device11B8)
    {
        case PciDevice11B8::NONE:        return "NONE";
        case PciDevice11B8::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11B8 device11B8) // TEST: NO
{
    // COMMON_LT((" | device11B8 = %u", device11B8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11B8, enumToString(device11B8));

    return res;
}



inline const char8* enumToHumanString(PciDevice11B8 device11B8) // TEST: NO
{
    // COMMON_LT((" | device11B8 = %u", device11B8)); // Commented to avoid bad looking logs



    switch (device11B8)
    {
        case PciDevice11B8::DEVICE_0001: return "Quad PeerMaster";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B8_PCIDEVICE11B8_H
