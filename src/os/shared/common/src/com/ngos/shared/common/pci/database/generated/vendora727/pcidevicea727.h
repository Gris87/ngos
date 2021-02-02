// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORA727_PCIDEVICEA727_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORA727_PCIDEVICEA727_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceA727: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0013 = 0x0013,
    DEVICE_6803 = 0x6803
};



inline const char8* enumToString(PciDeviceA727 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceA727::NONE:        return "NONE";
        case PciDeviceA727::DEVICE_0013: return "DEVICE_0013";
        case PciDeviceA727::DEVICE_6803: return "DEVICE_6803";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceA727 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceA727 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceA727::DEVICE_0013: return "3CRPAG175 Wireless PC Card";
        case PciDeviceA727::DEVICE_6803: return "3CRDAG675B Wireless 11a/b/g Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORA727_PCIDEVICEA727_H
