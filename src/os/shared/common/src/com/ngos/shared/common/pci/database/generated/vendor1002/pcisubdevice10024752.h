// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024752_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024752_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024752: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11001E = 0x0E11001E,
    SUBDEVICE_10020008 = 0x10020008,
    SUBDEVICE_10024752 = 0x10024752,
    SUBDEVICE_10028008 = 0x10028008,
    SUBDEVICE_10140240 = 0x10140240,
    SUBDEVICE_102800CE = 0x102800CE,
    SUBDEVICE_102800D1 = 0x102800D1,
    SUBDEVICE_102800D9 = 0x102800D9,
    SUBDEVICE_10280134 = 0x10280134,
    SUBDEVICE_1028014A = 0x1028014A,
    SUBDEVICE_10280165 = 0x10280165,
    SUBDEVICE_103C10E1 = 0x103C10E1,
    SUBDEVICE_103C3208 = 0x103C3208,
    SUBDEVICE_107B6400 = 0x107B6400,
    SUBDEVICE_1734007A = 0x1734007A,
    SUBDEVICE_17341073 = 0x17341073,
    SUBDEVICE_80863411 = 0x80863411,
    SUBDEVICE_80863427 = 0x80863427,
    SUBDEVICE_80865744 = 0x80865744
};



inline const char8* enumToString(PciSubDevice10024752 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024752::NONE:               return "NONE";
        case PciSubDevice10024752::SUBDEVICE_0E11001E: return "SUBDEVICE_0E11001E";
        case PciSubDevice10024752::SUBDEVICE_10020008: return "SUBDEVICE_10020008";
        case PciSubDevice10024752::SUBDEVICE_10024752: return "SUBDEVICE_10024752";
        case PciSubDevice10024752::SUBDEVICE_10028008: return "SUBDEVICE_10028008";
        case PciSubDevice10024752::SUBDEVICE_10140240: return "SUBDEVICE_10140240";
        case PciSubDevice10024752::SUBDEVICE_102800CE: return "SUBDEVICE_102800CE";
        case PciSubDevice10024752::SUBDEVICE_102800D1: return "SUBDEVICE_102800D1";
        case PciSubDevice10024752::SUBDEVICE_102800D9: return "SUBDEVICE_102800D9";
        case PciSubDevice10024752::SUBDEVICE_10280134: return "SUBDEVICE_10280134";
        case PciSubDevice10024752::SUBDEVICE_1028014A: return "SUBDEVICE_1028014A";
        case PciSubDevice10024752::SUBDEVICE_10280165: return "SUBDEVICE_10280165";
        case PciSubDevice10024752::SUBDEVICE_103C10E1: return "SUBDEVICE_103C10E1";
        case PciSubDevice10024752::SUBDEVICE_103C3208: return "SUBDEVICE_103C3208";
        case PciSubDevice10024752::SUBDEVICE_107B6400: return "SUBDEVICE_107B6400";
        case PciSubDevice10024752::SUBDEVICE_1734007A: return "SUBDEVICE_1734007A";
        case PciSubDevice10024752::SUBDEVICE_17341073: return "SUBDEVICE_17341073";
        case PciSubDevice10024752::SUBDEVICE_80863411: return "SUBDEVICE_80863411";
        case PciSubDevice10024752::SUBDEVICE_80863427: return "SUBDEVICE_80863427";
        case PciSubDevice10024752::SUBDEVICE_80865744: return "SUBDEVICE_80865744";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024752 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024752 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024752::SUBDEVICE_0E11001E: return "Proliant Rage XL";
        case PciSubDevice10024752::SUBDEVICE_10020008: return "Rage XL";
        case PciSubDevice10024752::SUBDEVICE_10024752: return "Proliant Rage XL";
        case PciSubDevice10024752::SUBDEVICE_10028008: return "Rage XL";
        case PciSubDevice10024752::SUBDEVICE_10140240: return "eServer xSeries server mainboard";
        case PciSubDevice10024752::SUBDEVICE_102800CE: return "PowerEdge 1400";
        case PciSubDevice10024752::SUBDEVICE_102800D1: return "PowerEdge 2550";
        case PciSubDevice10024752::SUBDEVICE_102800D9: return "PowerEdge 2500";
        case PciSubDevice10024752::SUBDEVICE_10280134: return "PowerEdge 600SC";
        case PciSubDevice10024752::SUBDEVICE_1028014A: return "PowerEdge 1750";
        case PciSubDevice10024752::SUBDEVICE_10280165: return "PowerEdge 750";
        case PciSubDevice10024752::SUBDEVICE_103C10E1: return "NetServer Rage XL";
        case PciSubDevice10024752::SUBDEVICE_103C3208: return "ProLiant DL140 G2";
        case PciSubDevice10024752::SUBDEVICE_107B6400: return "6400 Server";
        case PciSubDevice10024752::SUBDEVICE_1734007A: return "PRIMERGY RX/TX series onboard VGA";
        case PciSubDevice10024752::SUBDEVICE_17341073: return "Primergy Econel 200 D2020 mainboard";
        case PciSubDevice10024752::SUBDEVICE_80863411: return "SDS2 Mainboard";
        case PciSubDevice10024752::SUBDEVICE_80863427: return "S875WP1-E mainboard";
        case PciSubDevice10024752::SUBDEVICE_80865744: return "S845WD1-E mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024752_H
