// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014002E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014002E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1014002E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014002E = 0x1014002E,
    SUBDEVICE_1014022E = 0x1014022E
};



inline const char8* enumToString(PciSubDevice1014002E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014002E::NONE:               return "NONE";
        case PciSubDevice1014002E::SUBDEVICE_1014002E: return "SUBDEVICE_1014002E";
        case PciSubDevice1014002E::SUBDEVICE_1014022E: return "SUBDEVICE_1014022E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1014002E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1014002E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014002E::SUBDEVICE_1014002E: return "ServeRAID-3x";
        case PciSubDevice1014002E::SUBDEVICE_1014022E: return "ServeRAID-4H";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014002E_H
