// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002678A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002678A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002678A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002030C = 0x1002030C,
    SUBDEVICE_10020310 = 0x10020310,
    SUBDEVICE_10020420 = 0x10020420,
    SUBDEVICE_10020422 = 0x10020422,
    SUBDEVICE_10020710 = 0x10020710,
    SUBDEVICE_10020B0E = 0x10020B0E,
    SUBDEVICE_10020B2A = 0x10020B2A,
    SUBDEVICE_1028030C = 0x1028030C,
    SUBDEVICE_10280710 = 0x10280710
};



inline const char8* enumToString(PciSubDevice1002678A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002678A::NONE:               return "NONE";
        case PciSubDevice1002678A::SUBDEVICE_1002030C: return "SUBDEVICE_1002030C";
        case PciSubDevice1002678A::SUBDEVICE_10020310: return "SUBDEVICE_10020310";
        case PciSubDevice1002678A::SUBDEVICE_10020420: return "SUBDEVICE_10020420";
        case PciSubDevice1002678A::SUBDEVICE_10020422: return "SUBDEVICE_10020422";
        case PciSubDevice1002678A::SUBDEVICE_10020710: return "SUBDEVICE_10020710";
        case PciSubDevice1002678A::SUBDEVICE_10020B0E: return "SUBDEVICE_10020B0E";
        case PciSubDevice1002678A::SUBDEVICE_10020B2A: return "SUBDEVICE_10020B2A";
        case PciSubDevice1002678A::SUBDEVICE_1028030C: return "SUBDEVICE_1028030C";
        case PciSubDevice1002678A::SUBDEVICE_10280710: return "SUBDEVICE_10280710";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002678A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002678A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002678A::SUBDEVICE_1002030C: return "FirePro W8000";
        case PciSubDevice1002678A::SUBDEVICE_10020310: return "FirePro S9000";
        case PciSubDevice1002678A::SUBDEVICE_10020420: return "Radeon Sky 700";
        case PciSubDevice1002678A::SUBDEVICE_10020422: return "Radeon Sky 900";
        case PciSubDevice1002678A::SUBDEVICE_10020710: return "FirePro S9050";
        case PciSubDevice1002678A::SUBDEVICE_10020B0E: return "FirePro S10000 Passive";
        case PciSubDevice1002678A::SUBDEVICE_10020B2A: return "FirePro S10000";
        case PciSubDevice1002678A::SUBDEVICE_1028030C: return "FirePro W8000";
        case PciSubDevice1002678A::SUBDEVICE_10280710: return "FirePro S9000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002678A_H
