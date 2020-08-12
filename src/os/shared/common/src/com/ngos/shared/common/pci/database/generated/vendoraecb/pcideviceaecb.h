// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAECB_PCIDEVICEAECB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAECB_PCIDEVICEAECB_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceAECB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6250 = 0x6250
};



inline const char8* enumToString(PciDeviceAECB deviceAECB) // TEST: NO
{
    // COMMON_LT((" | deviceAECB = %u", deviceAECB)); // Commented to avoid bad looking logs



    switch (deviceAECB)
    {
        case PciDeviceAECB::NONE:        return "NONE";
        case PciDeviceAECB::DEVICE_6250: return "DEVICE_6250";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceAECB deviceAECB) // TEST: NO
{
    // COMMON_LT((" | deviceAECB = %u", deviceAECB)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceAECB, enumToString(deviceAECB));

    return res;
}



inline const char8* enumToHumanString(PciDeviceAECB deviceAECB) // TEST: NO
{
    // COMMON_LT((" | deviceAECB = %u", deviceAECB)); // Commented to avoid bad looking logs



    switch (deviceAECB)
    {
        case PciDeviceAECB::DEVICE_6250: return "VITC/LTC Timecode Reader card [PCI-VLTC/RDR]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAECB_PCIDEVICEAECB_H
