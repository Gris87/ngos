// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1023_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1023_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A1023: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_122D4020 = 0x122D4020,
    SUBDEVICE_122D4023 = 0x122D4023,
    SUBDEVICE_13E00247 = 0x13E00247,
    SUBDEVICE_13E00297 = 0x13E00297,
    SUBDEVICE_13E002C7 = 0x13E002C7,
    SUBDEVICE_14361203 = 0x14361203,
    SUBDEVICE_14361303 = 0x14361303
};



inline const char8* enumToString(PciSubDevice127A1023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1023::NONE:               return "NONE";
        case PciSubDevice127A1023::SUBDEVICE_122D4020: return "SUBDEVICE_122D4020";
        case PciSubDevice127A1023::SUBDEVICE_122D4023: return "SUBDEVICE_122D4023";
        case PciSubDevice127A1023::SUBDEVICE_13E00247: return "SUBDEVICE_13E00247";
        case PciSubDevice127A1023::SUBDEVICE_13E00297: return "SUBDEVICE_13E00297";
        case PciSubDevice127A1023::SUBDEVICE_13E002C7: return "SUBDEVICE_13E002C7";
        case PciSubDevice127A1023::SUBDEVICE_14361203: return "SUBDEVICE_14361203";
        case PciSubDevice127A1023::SUBDEVICE_14361303: return "SUBDEVICE_14361303";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A1023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A1023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1023::SUBDEVICE_122D4020: return "Packard Bell MDP3858-WE";
        case PciSubDevice127A1023::SUBDEVICE_122D4023: return "MDP3858-UE";
        case PciSubDevice127A1023::SUBDEVICE_13E00247: return "IBM F-1156IV+/R6 Spain V.90 Modem";
        case PciSubDevice127A1023::SUBDEVICE_13E00297: return "IBM";
        case PciSubDevice127A1023::SUBDEVICE_13E002C7: return "IBM F-1156IV+/R6 WW V.90 Modem";
        case PciSubDevice127A1023::SUBDEVICE_14361203: return "IBM";
        case PciSubDevice127A1023::SUBDEVICE_14361303: return "IBM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1023_H
