// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B4A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B4A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863B4A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102802DA = 0x102802DA,
    SUBDEVICE_17C010D2 = 0x17C010D2
};



inline const char8* enumToString(PciSubDevice80863B4A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B4A::NONE:               return "NONE";
        case PciSubDevice80863B4A::SUBDEVICE_102802DA: return "SUBDEVICE_102802DA";
        case PciSubDevice80863B4A::SUBDEVICE_17C010D2: return "SUBDEVICE_17C010D2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863B4A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863B4A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B4A::SUBDEVICE_102802DA: return "OptiPlex 980";
        case PciSubDevice80863B4A::SUBDEVICE_17C010D2: return "Medion Akoya E7214 Notebook PC [MD98410]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B4A_H
