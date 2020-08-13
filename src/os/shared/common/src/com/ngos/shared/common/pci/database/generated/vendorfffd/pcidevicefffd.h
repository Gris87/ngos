// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFFFD_PCIDEVICEFFFD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFFFD_PCIDEVICEFFFD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceFFFD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101
};



inline const char8* enumToString(PciDeviceFFFD deviceFFFD) // TEST: NO
{
    // COMMON_LT((" | deviceFFFD = %u", deviceFFFD)); // Commented to avoid bad looking logs



    switch (deviceFFFD)
    {
        case PciDeviceFFFD::NONE:        return "NONE";
        case PciDeviceFFFD::DEVICE_0101: return "DEVICE_0101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceFFFD deviceFFFD) // TEST: NO
{
    // COMMON_LT((" | deviceFFFD = %u", deviceFFFD)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceFFFD, enumToString(deviceFFFD));

    return res;
}



inline const char8* enumToHumanString(PciDeviceFFFD deviceFFFD) // TEST: NO
{
    // COMMON_LT((" | deviceFFFD = %u", deviceFFFD)); // Commented to avoid bad looking logs



    switch (deviceFFFD)
    {
        case PciDeviceFFFD::DEVICE_0101: return "PCI Event Channel Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFFFD_PCIDEVICEFFFD_H
