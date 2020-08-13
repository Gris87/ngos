// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR139A_PCIDEVICE139A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR139A_PCIDEVICE139A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice139A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0003 = 0x0003,
    DEVICE_0005 = 0x0005
};



inline const char8* enumToString(PciDevice139A device139A) // TEST: NO
{
    // COMMON_LT((" | device139A = %u", device139A)); // Commented to avoid bad looking logs



    switch (device139A)
    {
        case PciDevice139A::NONE:        return "NONE";
        case PciDevice139A::DEVICE_0001: return "DEVICE_0001";
        case PciDevice139A::DEVICE_0003: return "DEVICE_0003";
        case PciDevice139A::DEVICE_0005: return "DEVICE_0005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice139A device139A) // TEST: NO
{
    // COMMON_LT((" | device139A = %u", device139A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device139A, enumToString(device139A));

    return res;
}



inline const char8* enumToHumanString(PciDevice139A device139A) // TEST: NO
{
    // COMMON_LT((" | device139A = %u", device139A)); // Commented to avoid bad looking logs



    switch (device139A)
    {
        case PciDevice139A::DEVICE_0001: return "Quad Port 10/100 Server Accelerator";
        case PciDevice139A::DEVICE_0003: return "Single Port 10/100 Server Accelerator";
        case PciDevice139A::DEVICE_0005: return "Single Port Gigabit Server Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR139A_PCIDEVICE139A_H
