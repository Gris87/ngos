// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026900_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026900_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026900: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10251056 = 0x10251056,
    SUBDEVICE_10280640 = 0x10280640,
    SUBDEVICE_10280643 = 0x10280643,
    SUBDEVICE_1028067F = 0x1028067F,
    SUBDEVICE_10280767 = 0x10280767,
    SUBDEVICE_10280810 = 0x10280810,
    SUBDEVICE_1028130A = 0x1028130A,
    SUBDEVICE_103C2263 = 0x103C2263,
    SUBDEVICE_103C2269 = 0x103C2269,
    SUBDEVICE_103C22C6 = 0x103C22C6,
    SUBDEVICE_103C22C8 = 0x103C22C8,
    SUBDEVICE_103C2B45 = 0x103C2B45,
    SUBDEVICE_103C808C = 0x103C808C,
    SUBDEVICE_103C8099 = 0x103C8099,
    SUBDEVICE_103C80B5 = 0x103C80B5,
    SUBDEVICE_103C80B9 = 0x103C80B9,
    SUBDEVICE_103C811C = 0x103C811C,
    SUBDEVICE_103C8226 = 0x103C8226,
    SUBDEVICE_10CF1906 = 0x10CF1906,
    SUBDEVICE_11709979 = 0x11709979,
    SUBDEVICE_1179F903 = 0x1179F903,
    SUBDEVICE_1179F922 = 0x1179F922,
    SUBDEVICE_1179F923 = 0x1179F923,
    SUBDEVICE_1179F934 = 0x1179F934,
    SUBDEVICE_17AA3822 = 0x17AA3822,
    SUBDEVICE_17AA3824 = 0x17AA3824,
    SUBDEVICE_17AA5021 = 0x17AA5021
};



inline const char8* enumToString(PciSubDevice10026900 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026900::NONE:               return "NONE";
        case PciSubDevice10026900::SUBDEVICE_10251056: return "SUBDEVICE_10251056";
        case PciSubDevice10026900::SUBDEVICE_10280640: return "SUBDEVICE_10280640";
        case PciSubDevice10026900::SUBDEVICE_10280643: return "SUBDEVICE_10280643";
        case PciSubDevice10026900::SUBDEVICE_1028067F: return "SUBDEVICE_1028067F";
        case PciSubDevice10026900::SUBDEVICE_10280767: return "SUBDEVICE_10280767";
        case PciSubDevice10026900::SUBDEVICE_10280810: return "SUBDEVICE_10280810";
        case PciSubDevice10026900::SUBDEVICE_1028130A: return "SUBDEVICE_1028130A";
        case PciSubDevice10026900::SUBDEVICE_103C2263: return "SUBDEVICE_103C2263";
        case PciSubDevice10026900::SUBDEVICE_103C2269: return "SUBDEVICE_103C2269";
        case PciSubDevice10026900::SUBDEVICE_103C22C6: return "SUBDEVICE_103C22C6";
        case PciSubDevice10026900::SUBDEVICE_103C22C8: return "SUBDEVICE_103C22C8";
        case PciSubDevice10026900::SUBDEVICE_103C2B45: return "SUBDEVICE_103C2B45";
        case PciSubDevice10026900::SUBDEVICE_103C808C: return "SUBDEVICE_103C808C";
        case PciSubDevice10026900::SUBDEVICE_103C8099: return "SUBDEVICE_103C8099";
        case PciSubDevice10026900::SUBDEVICE_103C80B5: return "SUBDEVICE_103C80B5";
        case PciSubDevice10026900::SUBDEVICE_103C80B9: return "SUBDEVICE_103C80B9";
        case PciSubDevice10026900::SUBDEVICE_103C811C: return "SUBDEVICE_103C811C";
        case PciSubDevice10026900::SUBDEVICE_103C8226: return "SUBDEVICE_103C8226";
        case PciSubDevice10026900::SUBDEVICE_10CF1906: return "SUBDEVICE_10CF1906";
        case PciSubDevice10026900::SUBDEVICE_11709979: return "SUBDEVICE_11709979";
        case PciSubDevice10026900::SUBDEVICE_1179F903: return "SUBDEVICE_1179F903";
        case PciSubDevice10026900::SUBDEVICE_1179F922: return "SUBDEVICE_1179F922";
        case PciSubDevice10026900::SUBDEVICE_1179F923: return "SUBDEVICE_1179F923";
        case PciSubDevice10026900::SUBDEVICE_1179F934: return "SUBDEVICE_1179F934";
        case PciSubDevice10026900::SUBDEVICE_17AA3822: return "SUBDEVICE_17AA3822";
        case PciSubDevice10026900::SUBDEVICE_17AA3824: return "SUBDEVICE_17AA3824";
        case PciSubDevice10026900::SUBDEVICE_17AA5021: return "SUBDEVICE_17AA5021";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026900 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026900 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026900::SUBDEVICE_10251056: return "Radeon R7 M360 / R8 M365DX";
        case PciSubDevice10026900::SUBDEVICE_10280640: return "Radeon R7 M260/M265";
        case PciSubDevice10026900::SUBDEVICE_10280643: return "Radeon R7 M260/M265";
        case PciSubDevice10026900::SUBDEVICE_1028067F: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_10280767: return "Radeon R7 M445";
        case PciSubDevice10026900::SUBDEVICE_10280810: return "Radeon 530";
        case PciSubDevice10026900::SUBDEVICE_1028130A: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_103C2263: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_103C2269: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_103C22C6: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_103C22C8: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_103C2B45: return "Radeon R7 A360";
        case PciSubDevice10026900::SUBDEVICE_103C808C: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_103C8099: return "Radeon R7 M360";
        case PciSubDevice10026900::SUBDEVICE_103C80B5: return "Radeon R7 M360";
        case PciSubDevice10026900::SUBDEVICE_103C80B9: return "Radeon R7 M360";
        case PciSubDevice10026900::SUBDEVICE_103C811C: return "Radeon R7 M340";
        case PciSubDevice10026900::SUBDEVICE_103C8226: return "Radeon R7 M440";
        case PciSubDevice10026900::SUBDEVICE_10CF1906: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_11709979: return "Radeon R7 M360";
        case PciSubDevice10026900::SUBDEVICE_1179F903: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_1179F922: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_1179F923: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_1179F934: return "Radeon R7 M260";
        case PciSubDevice10026900::SUBDEVICE_17AA3822: return "Radeon R7 M360";
        case PciSubDevice10026900::SUBDEVICE_17AA3824: return "Radeon R7 M360";
        case PciSubDevice10026900::SUBDEVICE_17AA5021: return "Radeon R7 M260";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026900_H
