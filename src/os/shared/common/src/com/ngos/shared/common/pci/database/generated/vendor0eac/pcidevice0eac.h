// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0EAC_PCIDEVICE0EAC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0EAC_PCIDEVICE0EAC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0EAC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0008 = 0x0008
};



inline const char8* enumToString(PciDevice0EAC device0EAC) // TEST: NO
{
    // COMMON_LT((" | device0EAC = %u", device0EAC)); // Commented to avoid bad looking logs



    switch (device0EAC)
    {
        case PciDevice0EAC::NONE:        return "NONE";
        case PciDevice0EAC::DEVICE_0008: return "DEVICE_0008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0EAC device0EAC) // TEST: NO
{
    // COMMON_LT((" | device0EAC = %u", device0EAC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0EAC, enumToString(device0EAC));

    return res;
}



inline const char8* enumToHumanString(PciDevice0EAC device0EAC) // TEST: NO
{
    // COMMON_LT((" | device0EAC = %u", device0EAC)); // Commented to avoid bad looking logs



    switch (device0EAC)
    {
        case PciDevice0EAC::DEVICE_0008: return "Ethernet Powerlink Managing Node 01";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0EAC_PCIDEVICE0EAC_H
