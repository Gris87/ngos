// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026778_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026778_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026778: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190024 = 0x10190024,
    SUBDEVICE_10190027 = 0x10190027,
    SUBDEVICE_10282120 = 0x10282120,
    SUBDEVICE_1462B491 = 0x1462B491,
    SUBDEVICE_1462B492 = 0x1462B492,
    SUBDEVICE_1462B493 = 0x1462B493,
    SUBDEVICE_1462B499 = 0x1462B499,
    SUBDEVICE_16423C65 = 0x16423C65,
    SUBDEVICE_16423C75 = 0x16423C75,
    SUBDEVICE_174B8145 = 0x174B8145,
    SUBDEVICE_174BD145 = 0x174BD145,
    SUBDEVICE_174BD335 = 0x174BD335,
    SUBDEVICE_174BE145 = 0x174BE145,
    SUBDEVICE_17AA3694 = 0x17AA3694
};



inline const char8* enumToString(PciSubDevice10026778 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026778::NONE:               return "NONE";
        case PciSubDevice10026778::SUBDEVICE_10190024: return "SUBDEVICE_10190024";
        case PciSubDevice10026778::SUBDEVICE_10190027: return "SUBDEVICE_10190027";
        case PciSubDevice10026778::SUBDEVICE_10282120: return "SUBDEVICE_10282120";
        case PciSubDevice10026778::SUBDEVICE_1462B491: return "SUBDEVICE_1462B491";
        case PciSubDevice10026778::SUBDEVICE_1462B492: return "SUBDEVICE_1462B492";
        case PciSubDevice10026778::SUBDEVICE_1462B493: return "SUBDEVICE_1462B493";
        case PciSubDevice10026778::SUBDEVICE_1462B499: return "SUBDEVICE_1462B499";
        case PciSubDevice10026778::SUBDEVICE_16423C65: return "SUBDEVICE_16423C65";
        case PciSubDevice10026778::SUBDEVICE_16423C75: return "SUBDEVICE_16423C75";
        case PciSubDevice10026778::SUBDEVICE_174B8145: return "SUBDEVICE_174B8145";
        case PciSubDevice10026778::SUBDEVICE_174BD145: return "SUBDEVICE_174BD145";
        case PciSubDevice10026778::SUBDEVICE_174BD335: return "SUBDEVICE_174BD335";
        case PciSubDevice10026778::SUBDEVICE_174BE145: return "SUBDEVICE_174BE145";
        case PciSubDevice10026778::SUBDEVICE_17AA3694: return "SUBDEVICE_17AA3694";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026778 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026778 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026778::SUBDEVICE_10190024: return "Radeon HD 7470";
        case PciSubDevice10026778::SUBDEVICE_10190027: return "Radeon HD 8470";
        case PciSubDevice10026778::SUBDEVICE_10282120: return "Radeon HD 7470";
        case PciSubDevice10026778::SUBDEVICE_1462B491: return "Radeon HD 8470";
        case PciSubDevice10026778::SUBDEVICE_1462B492: return "Radeon HD 8470";
        case PciSubDevice10026778::SUBDEVICE_1462B493: return "Radeon HD 8470 OEM";
        case PciSubDevice10026778::SUBDEVICE_1462B499: return "Radeon R5 235 OEM";
        case PciSubDevice10026778::SUBDEVICE_16423C65: return "Radeon HD 8470";
        case PciSubDevice10026778::SUBDEVICE_16423C75: return "Radeon HD 8470";
        case PciSubDevice10026778::SUBDEVICE_174B8145: return "Radeon HD 8470";
        case PciSubDevice10026778::SUBDEVICE_174BD145: return "Radeon R5 235 OEM";
        case PciSubDevice10026778::SUBDEVICE_174BD335: return "Radeon R5 310 OEM";
        case PciSubDevice10026778::SUBDEVICE_174BE145: return "Radeon HD 7470";
        case PciSubDevice10026778::SUBDEVICE_17AA3694: return "Radeon R5 A220";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026778_H
