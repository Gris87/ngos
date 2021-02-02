// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1236_PCIDEVICE1236_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1236_PCIDEVICE1236_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1236: bad_uint16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_6401 = 0x6401
};



inline const char8* enumToString(PciDevice1236 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1236::DEVICE_0000: return "DEVICE_0000";
        case PciDevice1236::DEVICE_6401: return "DEVICE_6401";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1236 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1236 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1236::DEVICE_0000: return "RealMagic64/GX";
        case PciDevice1236::DEVICE_6401: return "REALmagic 64/GX (SD 6425)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1236_PCIDEVICE1236_H
