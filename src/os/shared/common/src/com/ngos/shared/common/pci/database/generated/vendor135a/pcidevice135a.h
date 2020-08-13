// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135A_PCIDEVICE135A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135A_PCIDEVICE135A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice135A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0A61 = 0x0A61
};



inline const char8* enumToString(PciDevice135A device135A) // TEST: NO
{
    // COMMON_LT((" | device135A = %u", device135A)); // Commented to avoid bad looking logs



    switch (device135A)
    {
        case PciDevice135A::NONE:        return "NONE";
        case PciDevice135A::DEVICE_0A61: return "DEVICE_0A61";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice135A device135A) // TEST: NO
{
    // COMMON_LT((" | device135A = %u", device135A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device135A, enumToString(device135A));

    return res;
}



inline const char8* enumToHumanString(PciDevice135A device135A) // TEST: NO
{
    // COMMON_LT((" | device135A = %u", device135A)); // Commented to avoid bad looking logs



    switch (device135A)
    {
        case PciDevice135A::DEVICE_0A61: return "UC-324 [VELOCITY RS422/485]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135A_PCIDEVICE135A_H
