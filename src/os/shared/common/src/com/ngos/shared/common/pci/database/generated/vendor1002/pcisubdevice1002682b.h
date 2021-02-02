// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002682B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002682B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002682B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0128079C = 0x0128079C,
    SUBDEVICE_14623012 = 0x14623012
};



inline const char8* enumToString(PciSubDevice1002682B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002682B::NONE:               return "NONE";
        case PciSubDevice1002682B::SUBDEVICE_0128079C: return "SUBDEVICE_0128079C";
        case PciSubDevice1002682B::SUBDEVICE_14623012: return "SUBDEVICE_14623012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002682B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002682B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002682B::SUBDEVICE_0128079C: return "Radeon R7 465X";
        case PciSubDevice1002682B::SUBDEVICE_14623012: return "Radeon R7 250";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002682B_H
