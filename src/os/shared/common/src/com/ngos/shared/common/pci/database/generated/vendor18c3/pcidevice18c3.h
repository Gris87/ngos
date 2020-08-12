// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCIDEVICE18C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCIDEVICE18C3_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18C3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0720 = 0x0720
};



inline const char8* enumToString(PciDevice18C3 device18C3) // TEST: NO
{
    // COMMON_LT((" | device18C3 = %u", device18C3)); // Commented to avoid bad looking logs



    switch (device18C3)
    {
        case PciDevice18C3::NONE:        return "NONE";
        case PciDevice18C3::DEVICE_0720: return "DEVICE_0720";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18C3 device18C3) // TEST: NO
{
    // COMMON_LT((" | device18C3 = %u", device18C3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device18C3, enumToString(device18C3));

    return res;
}



inline const char8* enumToHumanString(PciDevice18C3 device18C3) // TEST: NO
{
    // COMMON_LT((" | device18C3 = %u", device18C3)); // Commented to avoid bad looking logs



    switch (device18C3)
    {
        case PciDevice18C3::DEVICE_0720: return "nGene PCI-Express Multimedia Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCIDEVICE18C3_H
