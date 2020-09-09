// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A1003: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B0BC = 0x0E11B0BC,
    SUBDEVICE_0E11B114 = 0x0E11B114,
    SUBDEVICE_1033802B = 0x1033802B,
    SUBDEVICE_13DF1003 = 0x13DF1003,
    SUBDEVICE_13E00117 = 0x13E00117,
    SUBDEVICE_13E00147 = 0x13E00147,
    SUBDEVICE_13E00197 = 0x13E00197,
    SUBDEVICE_13E001C7 = 0x13E001C7,
    SUBDEVICE_13E001F7 = 0x13E001F7,
    SUBDEVICE_14361003 = 0x14361003,
    SUBDEVICE_14361103 = 0x14361103,
    SUBDEVICE_14361602 = 0x14361602
};



inline const char8* enumToString(PciSubDevice127A1003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1003::NONE:               return "NONE";
        case PciSubDevice127A1003::SUBDEVICE_0E11B0BC: return "SUBDEVICE_0E11B0BC";
        case PciSubDevice127A1003::SUBDEVICE_0E11B114: return "SUBDEVICE_0E11B114";
        case PciSubDevice127A1003::SUBDEVICE_1033802B: return "SUBDEVICE_1033802B";
        case PciSubDevice127A1003::SUBDEVICE_13DF1003: return "SUBDEVICE_13DF1003";
        case PciSubDevice127A1003::SUBDEVICE_13E00117: return "SUBDEVICE_13E00117";
        case PciSubDevice127A1003::SUBDEVICE_13E00147: return "SUBDEVICE_13E00147";
        case PciSubDevice127A1003::SUBDEVICE_13E00197: return "SUBDEVICE_13E00197";
        case PciSubDevice127A1003::SUBDEVICE_13E001C7: return "SUBDEVICE_13E001C7";
        case PciSubDevice127A1003::SUBDEVICE_13E001F7: return "SUBDEVICE_13E001F7";
        case PciSubDevice127A1003::SUBDEVICE_14361003: return "SUBDEVICE_14361003";
        case PciSubDevice127A1003::SUBDEVICE_14361103: return "SUBDEVICE_14361103";
        case PciSubDevice127A1003::SUBDEVICE_14361602: return "SUBDEVICE_14361602";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A1003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A1003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1003::SUBDEVICE_0E11B0BC: return "229-DF Zephyr";
        case PciSubDevice127A1003::SUBDEVICE_0E11B114: return "229-DF Cheetah";
        case PciSubDevice127A1003::SUBDEVICE_1033802B: return "229-DF";
        case PciSubDevice127A1003::SUBDEVICE_13DF1003: return "PCI56RX Modem";
        case PciSubDevice127A1003::SUBDEVICE_13E00117: return "IBM";
        case PciSubDevice127A1003::SUBDEVICE_13E00147: return "IBM F-1156IV+/R3 Spain V.90 Modem";
        case PciSubDevice127A1003::SUBDEVICE_13E00197: return "IBM";
        case PciSubDevice127A1003::SUBDEVICE_13E001C7: return "IBM F-1156IV+/R3 WW V.90 Modem";
        case PciSubDevice127A1003::SUBDEVICE_13E001F7: return "IBM";
        case PciSubDevice127A1003::SUBDEVICE_14361003: return "IBM";
        case PciSubDevice127A1003::SUBDEVICE_14361103: return "IBM 5614PM3G V.90 Modem";
        case PciSubDevice127A1003::SUBDEVICE_14361602: return "Compaq 229-DF Ducati";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1003_H
