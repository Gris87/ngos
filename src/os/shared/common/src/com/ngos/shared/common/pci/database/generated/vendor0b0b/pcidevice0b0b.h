// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0B0B_PCIDEVICE0B0B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0B0B_PCIDEVICE0B0B_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0B0B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0105 = 0x0105,
    DEVICE_0205 = 0x0205,
    DEVICE_0206 = 0x0206,
    DEVICE_0305 = 0x0305,
    DEVICE_0405 = 0x0405,
    DEVICE_0406 = 0x0406,
    DEVICE_0505 = 0x0505,
    DEVICE_0506 = 0x0506,
    DEVICE_0605 = 0x0605,
    DEVICE_0705 = 0x0705,
    DEVICE_0706 = 0x0706,
    DEVICE_0905 = 0x0905,
    DEVICE_0906 = 0x0906,
    DEVICE_0A06 = 0x0A06
};



inline const char8* enumToString(PciDevice0B0B device0B0B) // TEST: NO
{
    // COMMON_LT((" | device0B0B = %u", device0B0B)); // Commented to avoid bad looking logs



    switch (device0B0B)
    {
        case PciDevice0B0B::NONE:        return "NONE";
        case PciDevice0B0B::DEVICE_0105: return "DEVICE_0105";
        case PciDevice0B0B::DEVICE_0205: return "DEVICE_0205";
        case PciDevice0B0B::DEVICE_0206: return "DEVICE_0206";
        case PciDevice0B0B::DEVICE_0305: return "DEVICE_0305";
        case PciDevice0B0B::DEVICE_0405: return "DEVICE_0405";
        case PciDevice0B0B::DEVICE_0406: return "DEVICE_0406";
        case PciDevice0B0B::DEVICE_0505: return "DEVICE_0505";
        case PciDevice0B0B::DEVICE_0506: return "DEVICE_0506";
        case PciDevice0B0B::DEVICE_0605: return "DEVICE_0605";
        case PciDevice0B0B::DEVICE_0705: return "DEVICE_0705";
        case PciDevice0B0B::DEVICE_0706: return "DEVICE_0706";
        case PciDevice0B0B::DEVICE_0905: return "DEVICE_0905";
        case PciDevice0B0B::DEVICE_0906: return "DEVICE_0906";
        case PciDevice0B0B::DEVICE_0A06: return "DEVICE_0A06";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0B0B device0B0B) // TEST: NO
{
    // COMMON_LT((" | device0B0B = %u", device0B0B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0B0B, enumToString(device0B0B));

    return res;
}



inline const char8* enumToHumanString(PciDevice0B0B device0B0B) // TEST: NO
{
    // COMMON_LT((" | device0B0B = %u", device0B0B)); // Commented to avoid bad looking logs



    switch (device0B0B)
    {
        case PciDevice0B0B::DEVICE_0105: return "R1T1";
        case PciDevice0B0B::DEVICE_0205: return "R4FXO";
        case PciDevice0B0B::DEVICE_0206: return "RCB4FXO 4-channel FXO analog telephony card";
        case PciDevice0B0B::DEVICE_0305: return "R4T1";
        case PciDevice0B0B::DEVICE_0405: return "R8FXX";
        case PciDevice0B0B::DEVICE_0406: return "RCB8FXX 8-channel modular analog telephony card";
        case PciDevice0B0B::DEVICE_0505: return "R24FXX";
        case PciDevice0B0B::DEVICE_0506: return "RCB24FXS 24-Channel FXS analog telephony card";
        case PciDevice0B0B::DEVICE_0605: return "R2T1";
        case PciDevice0B0B::DEVICE_0705: return "R24FXS";
        case PciDevice0B0B::DEVICE_0706: return "RCB24FXO 24-Channel FXO analog telephony card";
        case PciDevice0B0B::DEVICE_0905: return "R1T3 Single T3 Digital Telephony Card";
        case PciDevice0B0B::DEVICE_0906: return "RCB24FXX 24-channel modular analog telephony card";
        case PciDevice0B0B::DEVICE_0A06: return "RCB672FXX 672-channel modular analog telephony card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0B0B_PCIDEVICE0B0B_H
