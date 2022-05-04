// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF15E_PCIDEVICEF15E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF15E_PCIDEVICEF15E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceF15E: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDeviceF15E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceF15E::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceF15E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceF15E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceF15E::DEVICE_0000: return "FU740-C000 RISC-V SoC PCI Express x8 to AXI4 Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF15E_PCIDEVICEF15E_H
