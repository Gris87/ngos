// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110046_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110046_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10110046: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E114050 = 0x0E114050,
    SUBDEVICE_0E114051 = 0x0E114051,
    SUBDEVICE_0E114058 = 0x0E114058,
    SUBDEVICE_103C10C2 = 0x103C10C2,
    SUBDEVICE_12D9000A = 0x12D9000A,
    SUBDEVICE_4C531050 = 0x4C531050,
    SUBDEVICE_4C531051 = 0x4C531051,
    SUBDEVICE_90050364 = 0x90050364,
    SUBDEVICE_90050365 = 0x90050365,
    SUBDEVICE_90051364 = 0x90051364,
    SUBDEVICE_90051365 = 0x90051365,
    SUBDEVICE_E4BF1000 = 0xE4BF1000
};



inline const char8* enumToString(PciSubDevice10110046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10110046::NONE:               return "NONE";
        case PciSubDevice10110046::SUBDEVICE_0E114050: return "SUBDEVICE_0E114050";
        case PciSubDevice10110046::SUBDEVICE_0E114051: return "SUBDEVICE_0E114051";
        case PciSubDevice10110046::SUBDEVICE_0E114058: return "SUBDEVICE_0E114058";
        case PciSubDevice10110046::SUBDEVICE_103C10C2: return "SUBDEVICE_103C10C2";
        case PciSubDevice10110046::SUBDEVICE_12D9000A: return "SUBDEVICE_12D9000A";
        case PciSubDevice10110046::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";
        case PciSubDevice10110046::SUBDEVICE_4C531051: return "SUBDEVICE_4C531051";
        case PciSubDevice10110046::SUBDEVICE_90050364: return "SUBDEVICE_90050364";
        case PciSubDevice10110046::SUBDEVICE_90050365: return "SUBDEVICE_90050365";
        case PciSubDevice10110046::SUBDEVICE_90051364: return "SUBDEVICE_90051364";
        case PciSubDevice10110046::SUBDEVICE_90051365: return "SUBDEVICE_90051365";
        case PciSubDevice10110046::SUBDEVICE_E4BF1000: return "SUBDEVICE_E4BF1000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10110046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10110046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10110046::SUBDEVICE_0E114050: return "Smart Array 4200 Controller";
        case PciSubDevice10110046::SUBDEVICE_0E114051: return "Smart Array 4250ES Controller";
        case PciSubDevice10110046::SUBDEVICE_0E114058: return "Smart Array 431 Controller";
        case PciSubDevice10110046::SUBDEVICE_103C10C2: return "NetRAID-4M";
        case PciSubDevice10110046::SUBDEVICE_12D9000A: return "IP Telephony card";
        case PciSubDevice10110046::SUBDEVICE_4C531050: return "CT7 mainboard";
        case PciSubDevice10110046::SUBDEVICE_4C531051: return "CE7 mainboard";
        case PciSubDevice10110046::SUBDEVICE_90050364: return "5400S (Mustang)";
        case PciSubDevice10110046::SUBDEVICE_90050365: return "5400S (Mustang)";
        case PciSubDevice10110046::SUBDEVICE_90051364: return "Dell PowerEdge RAID Controller 2";
        case PciSubDevice10110046::SUBDEVICE_90051365: return "Dell PowerEdge RAID Controller 2";
        case PciSubDevice10110046::SUBDEVICE_E4BF1000: return "CC8-1-BLUES";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110046_H
