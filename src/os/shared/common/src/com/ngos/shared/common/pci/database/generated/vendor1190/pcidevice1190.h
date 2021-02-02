// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1190_PCIDEVICE1190_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1190_PCIDEVICE1190_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1190: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_C731 = 0xC731
};



inline const char8* enumToString(PciDevice1190 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1190::NONE:        return "NONE";
        case PciDevice1190::DEVICE_C731: return "DEVICE_C731";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1190 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1190 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1190::DEVICE_C731: return "TP-910/920/940 PCI Ultra(Wide) SCSI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1190_PCIDEVICE1190_H
