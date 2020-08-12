// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR142E_PCIDEVICE142E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR142E_PCIDEVICE142E_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice142E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4020 = 0x4020,
    DEVICE_4337 = 0x4337
};



inline const char8* enumToString(PciDevice142E device142E) // TEST: NO
{
    // COMMON_LT((" | device142E = %u", device142E)); // Commented to avoid bad looking logs



    switch (device142E)
    {
        case PciDevice142E::NONE:        return "NONE";
        case PciDevice142E::DEVICE_4020: return "DEVICE_4020";
        case PciDevice142E::DEVICE_4337: return "DEVICE_4337";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice142E device142E) // TEST: NO
{
    // COMMON_LT((" | device142E = %u", device142E)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device142E, enumToString(device142E));

    return res;
}



inline const char8* enumToHumanString(PciDevice142E device142E) // TEST: NO
{
    // COMMON_LT((" | device142E = %u", device142E)); // Commented to avoid bad looking logs



    switch (device142E)
    {
        case PciDevice142E::DEVICE_4020: return "VM2-2 [Video Maker 2] MPEG1/2 Encoder";
        case PciDevice142E::DEVICE_4337: return "VM2-2-C7 [Video Maker 2 rev. C7] MPEG1/2 Encoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR142E_PCIDEVICE142E_H
