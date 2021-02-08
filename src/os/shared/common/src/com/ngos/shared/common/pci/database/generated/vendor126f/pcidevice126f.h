// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR126F_PCIDEVICE126F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR126F_PCIDEVICE126F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice126F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0501 = 0x0501,
    DEVICE_0510 = 0x0510,
    DEVICE_0710 = 0x0710,
    DEVICE_0712 = 0x0712,
    DEVICE_0718 = 0x0718,
    DEVICE_0720 = 0x0720,
    DEVICE_0730 = 0x0730,
    DEVICE_0750 = 0x0750,
    DEVICE_0810 = 0x0810,
    DEVICE_0811 = 0x0811,
    DEVICE_0820 = 0x0820,
    DEVICE_0910 = 0x0910,
    DEVICE_2262 = 0x2262,
    DEVICE_2263 = 0x2263
};



inline const char8* enumToString(PciDevice126F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice126F::NONE:        return "NONE";
        case PciDevice126F::DEVICE_0501: return "DEVICE_0501";
        case PciDevice126F::DEVICE_0510: return "DEVICE_0510";
        case PciDevice126F::DEVICE_0710: return "DEVICE_0710";
        case PciDevice126F::DEVICE_0712: return "DEVICE_0712";
        case PciDevice126F::DEVICE_0718: return "DEVICE_0718";
        case PciDevice126F::DEVICE_0720: return "DEVICE_0720";
        case PciDevice126F::DEVICE_0730: return "DEVICE_0730";
        case PciDevice126F::DEVICE_0750: return "DEVICE_0750";
        case PciDevice126F::DEVICE_0810: return "DEVICE_0810";
        case PciDevice126F::DEVICE_0811: return "DEVICE_0811";
        case PciDevice126F::DEVICE_0820: return "DEVICE_0820";
        case PciDevice126F::DEVICE_0910: return "DEVICE_0910";
        case PciDevice126F::DEVICE_2262: return "DEVICE_2262";
        case PciDevice126F::DEVICE_2263: return "DEVICE_2263";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice126F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice126F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice126F::DEVICE_0501: return "SM501 VoyagerGX Rev. AA";
        case PciDevice126F::DEVICE_0510: return "SM501 VoyagerGX Rev. B";
        case PciDevice126F::DEVICE_0710: return "SM710 LynxEM";
        case PciDevice126F::DEVICE_0712: return "SM712 LynxEM+";
        case PciDevice126F::DEVICE_0718: return "SM718 LynxSE+";
        case PciDevice126F::DEVICE_0720: return "SM720 Lynx3DM";
        case PciDevice126F::DEVICE_0730: return "SM731 Cougar3DR";
        case PciDevice126F::DEVICE_0750: return "SM750";
        case PciDevice126F::DEVICE_0810: return "SM810 LynxE";
        case PciDevice126F::DEVICE_0811: return "SM811 LynxE";
        case PciDevice126F::DEVICE_0820: return "SM820 Lynx3D";
        case PciDevice126F::DEVICE_0910: return "SM910";
        case PciDevice126F::DEVICE_2262: return "SM2262/SM2262EN SSD Controller";
        case PciDevice126F::DEVICE_2263: return "SM2263EN/SM2263XT SSD Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR126F_PCIDEVICE126F_H
