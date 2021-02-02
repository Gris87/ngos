// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B09_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B09_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863B09: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250347 = 0x10250347,
    SUBDEVICE_144DC06A = 0x144DC06A,
    SUBDEVICE_17C010D2 = 0x17C010D2
};



inline const char8* enumToString(PciSubDevice80863B09 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B09::NONE:               return "NONE";
        case PciSubDevice80863B09::SUBDEVICE_10250347: return "SUBDEVICE_10250347";
        case PciSubDevice80863B09::SUBDEVICE_144DC06A: return "SUBDEVICE_144DC06A";
        case PciSubDevice80863B09::SUBDEVICE_17C010D2: return "SUBDEVICE_17C010D2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863B09 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863B09 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B09::SUBDEVICE_10250347: return "Aspire 7740G";
        case PciSubDevice80863B09::SUBDEVICE_144DC06A: return "R730 Laptop";
        case PciSubDevice80863B09::SUBDEVICE_17C010D2: return "Medion Akoya E7214 Notebook PC [MD98410]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B09_H
