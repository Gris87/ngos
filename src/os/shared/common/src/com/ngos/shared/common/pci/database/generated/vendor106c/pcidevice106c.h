// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106C_PCIDEVICE106C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106C_PCIDEVICE106C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice106C: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8139 = 0x8139,
    DEVICE_8801 = 0x8801,
    DEVICE_8802 = 0x8802,
    DEVICE_8803 = 0x8803,
    DEVICE_8804 = 0x8804,
    DEVICE_8805 = 0x8805
};



inline const char8* enumToString(PciDevice106C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice106C::NONE:        return "NONE";
        case PciDevice106C::DEVICE_8139: return "DEVICE_8139";
        case PciDevice106C::DEVICE_8801: return "DEVICE_8801";
        case PciDevice106C::DEVICE_8802: return "DEVICE_8802";
        case PciDevice106C::DEVICE_8803: return "DEVICE_8803";
        case PciDevice106C::DEVICE_8804: return "DEVICE_8804";
        case PciDevice106C::DEVICE_8805: return "DEVICE_8805";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice106C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice106C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice106C::DEVICE_8139: return "8139c 100BaseTX Ethernet Controller";
        case PciDevice106C::DEVICE_8801: return "Dual Pentium ISA/PCI Motherboard";
        case PciDevice106C::DEVICE_8802: return "PowerPC ISA/PCI Motherboard";
        case PciDevice106C::DEVICE_8803: return "Dual Window Graphics Accelerator";
        case PciDevice106C::DEVICE_8804: return "LAN Controller";
        case PciDevice106C::DEVICE_8805: return "100-BaseT LAN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106C_PCIDEVICE106C_H
