// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCIDEVICE11AD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCIDEVICE11AD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11ad/pcisubdevice11ad0002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11ad/pcisubdevice11adc115.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11AD: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_C115 = 0xC115
};



inline const char8* enumToString(PciDevice11AD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11AD::NONE:        return "NONE";
        case PciDevice11AD::DEVICE_0002: return "DEVICE_0002";
        case PciDevice11AD::DEVICE_C115: return "DEVICE_C115";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11AD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11AD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11AD::DEVICE_0002: return "LNE100TX";
        case PciDevice11AD::DEVICE_C115: return "LNE100TX [Linksys EtherFast 10/100]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice11AD device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11AD::DEVICE_0002: return enumToHumanString((PciSubDevice11AD0002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11AD::DEVICE_C115: return enumToHumanString((PciSubDevice11ADC115)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCIDEVICE11AD_H
