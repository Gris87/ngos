// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DFC_PCIDEVICE1DFC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DFC_PCIDEVICE1DFC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DFC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1181 = 0x1181
};



inline const char8* enumToString(PciDevice1DFC device1DFC) // TEST: NO
{
    // COMMON_LT((" | device1DFC = %u", device1DFC)); // Commented to avoid bad looking logs



    switch (device1DFC)
    {
        case PciDevice1DFC::NONE:        return "NONE";
        case PciDevice1DFC::DEVICE_1181: return "DEVICE_1181";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DFC device1DFC) // TEST: NO
{
    // COMMON_LT((" | device1DFC = %u", device1DFC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1DFC, enumToString(device1DFC));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DFC device1DFC) // TEST: NO
{
    // COMMON_LT((" | device1DFC = %u", device1DFC)); // Commented to avoid bad looking logs



    switch (device1DFC)
    {
        case PciDevice1DFC::DEVICE_1181: return "TDM 8 Port E1/T1/J1 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DFC_PCIDEVICE1DFC_H
