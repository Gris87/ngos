// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002687F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002687F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002687F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B36 = 0x10020B36,
    SUBDEVICE_10026B76 = 0x10026B76,
    SUBDEVICE_1458230C = 0x1458230C,
    SUBDEVICE_1DA2E376 = 0x1DA2E376
};



inline const char8* enumToString(PciSubDevice1002687F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002687F::NONE:               return "NONE";
        case PciSubDevice1002687F::SUBDEVICE_10020B36: return "SUBDEVICE_10020B36";
        case PciSubDevice1002687F::SUBDEVICE_10026B76: return "SUBDEVICE_10026B76";
        case PciSubDevice1002687F::SUBDEVICE_1458230C: return "SUBDEVICE_1458230C";
        case PciSubDevice1002687F::SUBDEVICE_1DA2E376: return "SUBDEVICE_1DA2E376";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002687F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002687F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002687F::SUBDEVICE_10020B36: return "RX Vega64";
        case PciSubDevice1002687F::SUBDEVICE_10026B76: return "RX Vega64";
        case PciSubDevice1002687F::SUBDEVICE_1458230C: return "Radeon RX VEGA 56 GAMING OC 8G";
        case PciSubDevice1002687F::SUBDEVICE_1DA2E376: return "Radeon RX VEGA 56 Pulse 8GB OC HBM2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002687F_H
