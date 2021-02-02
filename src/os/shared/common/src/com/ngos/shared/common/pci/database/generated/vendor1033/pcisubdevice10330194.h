// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330194_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330194_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10330194: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804A3 = 0x102804A3,
    SUBDEVICE_102804B2 = 0x102804B2,
    SUBDEVICE_102804DA = 0x102804DA,
    SUBDEVICE_10438413 = 0x10438413,
    SUBDEVICE_104D907A = 0x104D907A,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_1B960001 = 0x1B960001
};



inline const char8* enumToString(PciSubDevice10330194 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10330194::NONE:               return "NONE";
        case PciSubDevice10330194::SUBDEVICE_102804A3: return "SUBDEVICE_102804A3";
        case PciSubDevice10330194::SUBDEVICE_102804B2: return "SUBDEVICE_102804B2";
        case PciSubDevice10330194::SUBDEVICE_102804DA: return "SUBDEVICE_102804DA";
        case PciSubDevice10330194::SUBDEVICE_10438413: return "SUBDEVICE_10438413";
        case PciSubDevice10330194::SUBDEVICE_104D907A: return "SUBDEVICE_104D907A";
        case PciSubDevice10330194::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice10330194::SUBDEVICE_1B960001: return "SUBDEVICE_1B960001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10330194 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10330194 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10330194::SUBDEVICE_102804A3: return "Precision M4600";
        case PciSubDevice10330194::SUBDEVICE_102804B2: return "Vostro 3350";
        case PciSubDevice10330194::SUBDEVICE_102804DA: return "Vostro 3750";
        case PciSubDevice10330194::SUBDEVICE_10438413: return "P8P67 Deluxe Motherboard";
        case PciSubDevice10330194::SUBDEVICE_104D907A: return "Vaio VPCF1";
        case PciSubDevice10330194::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice10330194::SUBDEVICE_1B960001: return "USB 3.0 PCIe Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330194_H
