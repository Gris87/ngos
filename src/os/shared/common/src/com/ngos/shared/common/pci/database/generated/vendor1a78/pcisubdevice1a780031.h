// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A78_PCISUBDEVICE1A780031_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A78_PCISUBDEVICE1A780031_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1A780031: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1A780034 = 0x1A780034,
    SUBDEVICE_1A780037 = 0x1A780037,
    SUBDEVICE_1A780038 = 0x1A780038,
    SUBDEVICE_1A780039 = 0x1A780039
};



inline const char8* enumToString(PciSubDevice1A780031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1A780031::NONE:               return "NONE";
        case PciSubDevice1A780031::SUBDEVICE_1A780034: return "SUBDEVICE_1A780034";
        case PciSubDevice1A780031::SUBDEVICE_1A780037: return "SUBDEVICE_1A780037";
        case PciSubDevice1A780031::SUBDEVICE_1A780038: return "SUBDEVICE_1A780038";
        case PciSubDevice1A780031::SUBDEVICE_1A780039: return "SUBDEVICE_1A780039";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1A780031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1A780031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1A780031::SUBDEVICE_1A780034: return "FlashMAX PCIe SSD [rev 3]";
        case PciSubDevice1A780031::SUBDEVICE_1A780037: return "FlashMAX PCIe SSD [rev 3D]";
        case PciSubDevice1A780031::SUBDEVICE_1A780038: return "FlashMAX PCIe SSD [rev 4]";
        case PciSubDevice1A780031::SUBDEVICE_1A780039: return "FlashMAX PCIe SSD [rev 4D]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A78_PCISUBDEVICE1A780031_H
