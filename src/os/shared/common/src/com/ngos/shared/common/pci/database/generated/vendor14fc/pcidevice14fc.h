// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14FC_PCIDEVICE14FC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14FC_PCIDEVICE14FC_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14FC: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice14FC device14FC) // TEST: NO
{
    // COMMON_LT((" | device14FC = %u", device14FC)); // Commented to avoid bad looking logs



    switch (device14FC)
    {
        case PciDevice14FC::DEVICE_0000: return "DEVICE_0000";
        case PciDevice14FC::DEVICE_0001: return "DEVICE_0001";
        case PciDevice14FC::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14FC device14FC) // TEST: NO
{
    // COMMON_LT((" | device14FC = %u", device14FC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14FC, enumToString(device14FC));

    return res;
}



inline const char8* enumToHumanString(PciDevice14FC device14FC) // TEST: NO
{
    // COMMON_LT((" | device14FC = %u", device14FC)); // Commented to avoid bad looking logs



    switch (device14FC)
    {
        case PciDevice14FC::DEVICE_0000: return "QsNet Elan3 Network Adapter";
        case PciDevice14FC::DEVICE_0001: return "QsNetII Elan4 Network Adapter";
        case PciDevice14FC::DEVICE_0002: return "QsNetIII Elan5 Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14FC_PCIDEVICE14FC_H
