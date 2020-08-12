// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCIDEVICE12EB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCIDEVICE12EB_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12EB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_8803 = 0x8803
};



inline const char8* enumToString(PciDevice12EB device12EB) // TEST: NO
{
    // COMMON_LT((" | device12EB = %u", device12EB)); // Commented to avoid bad looking logs



    switch (device12EB)
    {
        case PciDevice12EB::NONE:        return "NONE";
        case PciDevice12EB::DEVICE_0001: return "DEVICE_0001";
        case PciDevice12EB::DEVICE_0002: return "DEVICE_0002";
        case PciDevice12EB::DEVICE_0003: return "DEVICE_0003";
        case PciDevice12EB::DEVICE_8803: return "DEVICE_8803";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12EB device12EB) // TEST: NO
{
    // COMMON_LT((" | device12EB = %u", device12EB)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12EB, enumToString(device12EB));

    return res;
}



inline const char8* enumToHumanString(PciDevice12EB device12EB) // TEST: NO
{
    // COMMON_LT((" | device12EB = %u", device12EB)); // Commented to avoid bad looking logs



    switch (device12EB)
    {
        case PciDevice12EB::DEVICE_0001: return "Vortex 1";
        case PciDevice12EB::DEVICE_0002: return "Vortex 2";
        case PciDevice12EB::DEVICE_0003: return "AU8810 Vortex Digital Audio Processor";
        case PciDevice12EB::DEVICE_8803: return "Vortex 56k Software Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCIDEVICE12EB_H
