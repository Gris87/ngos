// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4005_PCIDEVICE4005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4005_PCIDEVICE4005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4005: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0300 = 0x0300,
    DEVICE_0308 = 0x0308,
    DEVICE_0309 = 0x0309,
    DEVICE_1064 = 0x1064,
    DEVICE_2064 = 0x2064,
    DEVICE_2128 = 0x2128,
    DEVICE_2301 = 0x2301,
    DEVICE_2302 = 0x2302,
    DEVICE_2303 = 0x2303,
    DEVICE_2364 = 0x2364,
    DEVICE_2464 = 0x2464,
    DEVICE_2501 = 0x2501,
    DEVICE_4000 = 0x4000,
    DEVICE_4710 = 0x4710
};



inline const char8* enumToString(PciDevice4005 device4005) // TEST: NO
{
    // COMMON_LT((" | device4005 = %u", device4005)); // Commented to avoid bad looking logs



    switch (device4005)
    {
        case PciDevice4005::NONE:        return "NONE";
        case PciDevice4005::DEVICE_0300: return "DEVICE_0300";
        case PciDevice4005::DEVICE_0308: return "DEVICE_0308";
        case PciDevice4005::DEVICE_0309: return "DEVICE_0309";
        case PciDevice4005::DEVICE_1064: return "DEVICE_1064";
        case PciDevice4005::DEVICE_2064: return "DEVICE_2064";
        case PciDevice4005::DEVICE_2128: return "DEVICE_2128";
        case PciDevice4005::DEVICE_2301: return "DEVICE_2301";
        case PciDevice4005::DEVICE_2302: return "DEVICE_2302";
        case PciDevice4005::DEVICE_2303: return "DEVICE_2303";
        case PciDevice4005::DEVICE_2364: return "DEVICE_2364";
        case PciDevice4005::DEVICE_2464: return "DEVICE_2464";
        case PciDevice4005::DEVICE_2501: return "DEVICE_2501";
        case PciDevice4005::DEVICE_4000: return "DEVICE_4000";
        case PciDevice4005::DEVICE_4710: return "DEVICE_4710";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4005 device4005) // TEST: NO
{
    // COMMON_LT((" | device4005 = %u", device4005)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device4005, enumToString(device4005));

    return res;
}



inline const char8* enumToHumanString(PciDevice4005 device4005) // TEST: NO
{
    // COMMON_LT((" | device4005 = %u", device4005)); // Commented to avoid bad looking logs



    switch (device4005)
    {
        case PciDevice4005::DEVICE_0300: return "ALS300 PCI Audio Device";
        case PciDevice4005::DEVICE_0308: return "ALS300+ PCI Audio Device";
        case PciDevice4005::DEVICE_0309: return "PCI Input Controller";
        case PciDevice4005::DEVICE_1064: return "ALG-2064";
        case PciDevice4005::DEVICE_2064: return "ALG-2064i";
        case PciDevice4005::DEVICE_2128: return "ALG-2364A GUI Accelerator";
        case PciDevice4005::DEVICE_2301: return "ALG-2301";
        case PciDevice4005::DEVICE_2302: return "ALG-2302";
        case PciDevice4005::DEVICE_2303: return "AVG-2302 GUI Accelerator";
        case PciDevice4005::DEVICE_2364: return "ALG-2364A";
        case PciDevice4005::DEVICE_2464: return "ALG-2464";
        case PciDevice4005::DEVICE_2501: return "ALG-2564A/25128A";
        case PciDevice4005::DEVICE_4000: return "ALS4000 Audio Chipset";
        case PciDevice4005::DEVICE_4710: return "ALC200/200P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4005_PCIDEVICE4005_H
