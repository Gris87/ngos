// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F4_PCIDEVICE13F4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F4_PCIDEVICE13F4_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13F4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1401 = 0x1401
};



inline const char8* enumToString(PciDevice13F4 device13F4) // TEST: NO
{
    // COMMON_LT((" | device13F4 = %u", device13F4)); // Commented to avoid bad looking logs



    switch (device13F4)
    {
        case PciDevice13F4::NONE:        return "NONE";
        case PciDevice13F4::DEVICE_1401: return "DEVICE_1401";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13F4 device13F4) // TEST: NO
{
    // COMMON_LT((" | device13F4 = %u", device13F4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device13F4, enumToString(device13F4));

    return res;
}



inline const char8* enumToHumanString(PciDevice13F4 device13F4) // TEST: NO
{
    // COMMON_LT((" | device13F4 = %u", device13F4)); // Commented to avoid bad looking logs



    switch (device13F4)
    {
        case PciDevice13F4::DEVICE_1401: return "Zentai Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F4_PCIDEVICE13F4_H
