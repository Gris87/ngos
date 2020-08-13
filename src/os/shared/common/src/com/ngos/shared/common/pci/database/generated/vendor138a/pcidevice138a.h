// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR138A_PCIDEVICE138A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR138A_PCIDEVICE138A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice138A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_003D = 0x003D
};



inline const char8* enumToString(PciDevice138A device138A) // TEST: NO
{
    // COMMON_LT((" | device138A = %u", device138A)); // Commented to avoid bad looking logs



    switch (device138A)
    {
        case PciDevice138A::NONE:        return "NONE";
        case PciDevice138A::DEVICE_003D: return "DEVICE_003D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice138A device138A) // TEST: NO
{
    // COMMON_LT((" | device138A = %u", device138A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device138A, enumToString(device138A));

    return res;
}



inline const char8* enumToHumanString(PciDevice138A device138A) // TEST: NO
{
    // COMMON_LT((" | device138A = %u", device138A)); // Commented to avoid bad looking logs



    switch (device138A)
    {
        case PciDevice138A::DEVICE_003D: return "VFS491 Validity Sensor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR138A_PCIDEVICE138A_H
