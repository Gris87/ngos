// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002679A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B01 = 0x10020B01,
    SUBDEVICE_10023000 = 0x10023000,
    SUBDEVICE_14623000 = 0x14623000,
    SUBDEVICE_174BA003 = 0x174BA003
};



inline const char8* enumToString(PciSubDevice1002679A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002679A::NONE:               return "NONE";
        case PciSubDevice1002679A::SUBDEVICE_10020B01: return "SUBDEVICE_10020B01";
        case PciSubDevice1002679A::SUBDEVICE_10023000: return "SUBDEVICE_10023000";
        case PciSubDevice1002679A::SUBDEVICE_14623000: return "SUBDEVICE_14623000";
        case PciSubDevice1002679A::SUBDEVICE_174BA003: return "SUBDEVICE_174BA003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002679A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002679A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002679A::SUBDEVICE_10020B01: return "Radeon HD 8950 OEM";
        case PciSubDevice1002679A::SUBDEVICE_10023000: return "Tahiti PRO2 [Radeon HD 7950 Boost]";
        case PciSubDevice1002679A::SUBDEVICE_14623000: return "Radeon HD 8950 OEM";
        case PciSubDevice1002679A::SUBDEVICE_174BA003: return "Radeon R9 280";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679A_H
