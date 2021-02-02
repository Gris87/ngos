// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15C7_PCIDEVICE15C7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15C7_PCIDEVICE15C7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15C7: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0349 = 0x0349
};



inline const char8* enumToString(PciDevice15C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15C7::NONE:        return "NONE";
        case PciDevice15C7::DEVICE_0349: return "DEVICE_0349";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice15C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15C7::DEVICE_0349: return "Tateyama C-PCI PLC/NC card Rev.01A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15C7_PCIDEVICE15C7_H
