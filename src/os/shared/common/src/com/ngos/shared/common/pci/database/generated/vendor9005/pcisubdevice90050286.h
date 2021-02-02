// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050286_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050286_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050286: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014034D = 0x1014034D,
    SUBDEVICE_10149540 = 0x10149540,
    SUBDEVICE_10149580 = 0x10149580,
    SUBDEVICE_9005028C = 0x9005028C,
    SUBDEVICE_9005028D = 0x9005028D,
    SUBDEVICE_9005029B = 0x9005029B,
    SUBDEVICE_9005029C = 0x9005029C,
    SUBDEVICE_9005029D = 0x9005029D,
    SUBDEVICE_9005029E = 0x9005029E,
    SUBDEVICE_9005029F = 0x9005029F,
    SUBDEVICE_900502A0 = 0x900502A0,
    SUBDEVICE_900502A1 = 0x900502A1,
    SUBDEVICE_900502A2 = 0x900502A2,
    SUBDEVICE_900502A3 = 0x900502A3,
    SUBDEVICE_900502A4 = 0x900502A4,
    SUBDEVICE_900502A5 = 0x900502A5,
    SUBDEVICE_900502A6 = 0x900502A6,
    SUBDEVICE_900502A7 = 0x900502A7,
    SUBDEVICE_900502A8 = 0x900502A8,
    SUBDEVICE_900502A9 = 0x900502A9,
    SUBDEVICE_900502AA = 0x900502AA,
    SUBDEVICE_900502AC = 0x900502AC,
    SUBDEVICE_900502B3 = 0x900502B3,
    SUBDEVICE_900502B4 = 0x900502B4,
    SUBDEVICE_90050800 = 0x90050800
};



inline const char8* enumToString(PciSubDevice90050286 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050286::NONE:               return "NONE";
        case PciSubDevice90050286::SUBDEVICE_1014034D: return "SUBDEVICE_1014034D";
        case PciSubDevice90050286::SUBDEVICE_10149540: return "SUBDEVICE_10149540";
        case PciSubDevice90050286::SUBDEVICE_10149580: return "SUBDEVICE_10149580";
        case PciSubDevice90050286::SUBDEVICE_9005028C: return "SUBDEVICE_9005028C";
        case PciSubDevice90050286::SUBDEVICE_9005028D: return "SUBDEVICE_9005028D";
        case PciSubDevice90050286::SUBDEVICE_9005029B: return "SUBDEVICE_9005029B";
        case PciSubDevice90050286::SUBDEVICE_9005029C: return "SUBDEVICE_9005029C";
        case PciSubDevice90050286::SUBDEVICE_9005029D: return "SUBDEVICE_9005029D";
        case PciSubDevice90050286::SUBDEVICE_9005029E: return "SUBDEVICE_9005029E";
        case PciSubDevice90050286::SUBDEVICE_9005029F: return "SUBDEVICE_9005029F";
        case PciSubDevice90050286::SUBDEVICE_900502A0: return "SUBDEVICE_900502A0";
        case PciSubDevice90050286::SUBDEVICE_900502A1: return "SUBDEVICE_900502A1";
        case PciSubDevice90050286::SUBDEVICE_900502A2: return "SUBDEVICE_900502A2";
        case PciSubDevice90050286::SUBDEVICE_900502A3: return "SUBDEVICE_900502A3";
        case PciSubDevice90050286::SUBDEVICE_900502A4: return "SUBDEVICE_900502A4";
        case PciSubDevice90050286::SUBDEVICE_900502A5: return "SUBDEVICE_900502A5";
        case PciSubDevice90050286::SUBDEVICE_900502A6: return "SUBDEVICE_900502A6";
        case PciSubDevice90050286::SUBDEVICE_900502A7: return "SUBDEVICE_900502A7";
        case PciSubDevice90050286::SUBDEVICE_900502A8: return "SUBDEVICE_900502A8";
        case PciSubDevice90050286::SUBDEVICE_900502A9: return "SUBDEVICE_900502A9";
        case PciSubDevice90050286::SUBDEVICE_900502AA: return "SUBDEVICE_900502AA";
        case PciSubDevice90050286::SUBDEVICE_900502AC: return "SUBDEVICE_900502AC";
        case PciSubDevice90050286::SUBDEVICE_900502B3: return "SUBDEVICE_900502B3";
        case PciSubDevice90050286::SUBDEVICE_900502B4: return "SUBDEVICE_900502B4";
        case PciSubDevice90050286::SUBDEVICE_90050800: return "SUBDEVICE_90050800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050286 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050286 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050286::SUBDEVICE_1014034D: return "8s";
        case PciSubDevice90050286::SUBDEVICE_10149540: return "ServeRAID 8k/8k-l4";
        case PciSubDevice90050286::SUBDEVICE_10149580: return "ServeRAID 8k/8k-l8";
        case PciSubDevice90050286::SUBDEVICE_9005028C: return "ASR-2230S + ASR-2230SLP PCI-X (Lancer)";
        case PciSubDevice90050286::SUBDEVICE_9005028D: return "ASR-2130S";
        case PciSubDevice90050286::SUBDEVICE_9005029B: return "ASR-2820SA";
        case PciSubDevice90050286::SUBDEVICE_9005029C: return "ASR-2620SA";
        case PciSubDevice90050286::SUBDEVICE_9005029D: return "ASR-2420SA";
        case PciSubDevice90050286::SUBDEVICE_9005029E: return "ICP ICP9024R0";
        case PciSubDevice90050286::SUBDEVICE_9005029F: return "ICP ICP9014R0";
        case PciSubDevice90050286::SUBDEVICE_900502A0: return "ICP ICP9047MA";
        case PciSubDevice90050286::SUBDEVICE_900502A1: return "ICP ICP9087MA";
        case PciSubDevice90050286::SUBDEVICE_900502A2: return "3800";
        case PciSubDevice90050286::SUBDEVICE_900502A3: return "ICP ICP5445AU";
        case PciSubDevice90050286::SUBDEVICE_900502A4: return "ICP ICP9085LI";
        case PciSubDevice90050286::SUBDEVICE_900502A5: return "ICP ICP5085BR";
        case PciSubDevice90050286::SUBDEVICE_900502A6: return "ICP9067MA";
        case PciSubDevice90050286::SUBDEVICE_900502A7: return "3805";
        case PciSubDevice90050286::SUBDEVICE_900502A8: return "3400";
        case PciSubDevice90050286::SUBDEVICE_900502A9: return "ICP ICP5085AU";
        case PciSubDevice90050286::SUBDEVICE_900502AA: return "ICP ICP5045AU";
        case PciSubDevice90050286::SUBDEVICE_900502AC: return "1800";
        case PciSubDevice90050286::SUBDEVICE_900502B3: return "2400";
        case PciSubDevice90050286::SUBDEVICE_900502B4: return "ICP ICP5045AL";
        case PciSubDevice90050286::SUBDEVICE_90050800: return "Callisto";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050286_H
