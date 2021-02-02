// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863310_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863310_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863310: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10543030 = 0x10543030,
    SUBDEVICE_10543034 = 0x10543034
};



inline const char8* enumToString(PciSubDevice80863310 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863310::NONE:               return "NONE";
        case PciSubDevice80863310::SUBDEVICE_10543030: return "SUBDEVICE_10543030";
        case PciSubDevice80863310::SUBDEVICE_10543034: return "SUBDEVICE_10543034";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863310 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863310 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863310::SUBDEVICE_10543030: return "HRA380 Hitachi RAID Adapter to PCIe";
        case PciSubDevice80863310::SUBDEVICE_10543034: return "HRA381 Hitachi RAID Adapter to PCIe";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863310_H
