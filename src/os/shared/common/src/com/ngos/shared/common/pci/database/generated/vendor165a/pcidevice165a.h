// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165A_PCIDEVICE165A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165A_PCIDEVICE165A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice165A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_C100 = 0xC100,
    DEVICE_D200 = 0xD200,
    DEVICE_D300 = 0xD300,
    DEVICE_EB01 = 0xEB01
};



inline const char8* enumToString(PciDevice165A device165A) // TEST: NO
{
    // COMMON_LT((" | device165A = %u", device165A)); // Commented to avoid bad looking logs



    switch (device165A)
    {
        case PciDevice165A::NONE:        return "NONE";
        case PciDevice165A::DEVICE_C100: return "DEVICE_C100";
        case PciDevice165A::DEVICE_D200: return "DEVICE_D200";
        case PciDevice165A::DEVICE_D300: return "DEVICE_D300";
        case PciDevice165A::DEVICE_EB01: return "DEVICE_EB01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice165A device165A) // TEST: NO
{
    // COMMON_LT((" | device165A = %u", device165A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device165A, enumToString(device165A));

    return res;
}



inline const char8* enumToHumanString(PciDevice165A device165A) // TEST: NO
{
    // COMMON_LT((" | device165A = %u", device165A)); // Commented to avoid bad looking logs



    switch (device165A)
    {
        case PciDevice165A::DEVICE_C100: return "PIXCI(R) CL1 Camera Link Video Capture Board [custom QL5232]";
        case PciDevice165A::DEVICE_D200: return "PIXCI(R) D2X Digital Video Capture Board [custom QL5232]";
        case PciDevice165A::DEVICE_D300: return "PIXCI(R) D3X Digital Video Capture Board [custom QL5232]";
        case PciDevice165A::DEVICE_EB01: return "PIXCI(R) EB1 PCI Camera Link Video Capture Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165A_PCIDEVICE165A_H
