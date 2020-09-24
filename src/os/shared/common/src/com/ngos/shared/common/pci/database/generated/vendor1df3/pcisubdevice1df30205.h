// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCISUBDEVICE1DF30205_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCISUBDEVICE1DF30205_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1DF30205: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1DF30000 = 0x1DF30000,
    SUBDEVICE_1DF30001 = 0x1DF30001
};



inline const char8* enumToString(PciSubDevice1DF30205 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1DF30205::NONE:               return "NONE";
        case PciSubDevice1DF30205::SUBDEVICE_1DF30000: return "SUBDEVICE_1DF30000";
        case PciSubDevice1DF30205::SUBDEVICE_1DF30001: return "SUBDEVICE_1DF30001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1DF30205 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1DF30205 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1DF30205::SUBDEVICE_1DF30000: return "Maintenance Mode";
        case PciSubDevice1DF30205::SUBDEVICE_1DF30001: return "ENA2250F";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCISUBDEVICE1DF30205_H
