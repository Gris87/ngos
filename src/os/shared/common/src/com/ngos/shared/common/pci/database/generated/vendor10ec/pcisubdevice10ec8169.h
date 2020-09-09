// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8169_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8169_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC8169: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250079 = 0x10250079,
    SUBDEVICE_10BD3202 = 0x10BD3202,
    SUBDEVICE_10EC8169 = 0x10EC8169,
    SUBDEVICE_1259C107 = 0x1259C107,
    SUBDEVICE_1371434E = 0x1371434E,
    SUBDEVICE_1385311A = 0x1385311A,
    SUBDEVICE_13855200 = 0x13855200,
    SUBDEVICE_1458E000 = 0x1458E000,
    SUBDEVICE_1462030C = 0x1462030C,
    SUBDEVICE_1462065C = 0x1462065C,
    SUBDEVICE_1462702C = 0x1462702C,
    SUBDEVICE_14627094 = 0x14627094,
    SUBDEVICE_16EC011F = 0x16EC011F,
    SUBDEVICE_17341091 = 0x17341091,
    SUBDEVICE_A0A00449 = 0xA0A00449
};



inline const char8* enumToString(PciSubDevice10EC8169 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8169::NONE:               return "NONE";
        case PciSubDevice10EC8169::SUBDEVICE_10250079: return "SUBDEVICE_10250079";
        case PciSubDevice10EC8169::SUBDEVICE_10BD3202: return "SUBDEVICE_10BD3202";
        case PciSubDevice10EC8169::SUBDEVICE_10EC8169: return "SUBDEVICE_10EC8169";
        case PciSubDevice10EC8169::SUBDEVICE_1259C107: return "SUBDEVICE_1259C107";
        case PciSubDevice10EC8169::SUBDEVICE_1371434E: return "SUBDEVICE_1371434E";
        case PciSubDevice10EC8169::SUBDEVICE_1385311A: return "SUBDEVICE_1385311A";
        case PciSubDevice10EC8169::SUBDEVICE_13855200: return "SUBDEVICE_13855200";
        case PciSubDevice10EC8169::SUBDEVICE_1458E000: return "SUBDEVICE_1458E000";
        case PciSubDevice10EC8169::SUBDEVICE_1462030C: return "SUBDEVICE_1462030C";
        case PciSubDevice10EC8169::SUBDEVICE_1462065C: return "SUBDEVICE_1462065C";
        case PciSubDevice10EC8169::SUBDEVICE_1462702C: return "SUBDEVICE_1462702C";
        case PciSubDevice10EC8169::SUBDEVICE_14627094: return "SUBDEVICE_14627094";
        case PciSubDevice10EC8169::SUBDEVICE_16EC011F: return "SUBDEVICE_16EC011F";
        case PciSubDevice10EC8169::SUBDEVICE_17341091: return "SUBDEVICE_17341091";
        case PciSubDevice10EC8169::SUBDEVICE_A0A00449: return "SUBDEVICE_A0A00449";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC8169 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC8169 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8169::SUBDEVICE_10250079: return "Aspire 5024WLMi";
        case PciSubDevice10EC8169::SUBDEVICE_10BD3202: return "EP-320G-TX1 32-bit PCI Gigabit Ethernet Adapter";
        case PciSubDevice10EC8169::SUBDEVICE_10EC8169: return "RTL8169/8110 Family PCI Gigabit Ethernet NIC";
        case PciSubDevice10EC8169::SUBDEVICE_1259C107: return "CG-LAPCIGT";
        case PciSubDevice10EC8169::SUBDEVICE_1371434E: return "ProG-2000L";
        case PciSubDevice10EC8169::SUBDEVICE_1385311A: return "GA311";
        case PciSubDevice10EC8169::SUBDEVICE_13855200: return "GA511 Gigabit PC Card";
        case PciSubDevice10EC8169::SUBDEVICE_1458E000: return "GA-8I915ME-G Mainboard";
        case PciSubDevice10EC8169::SUBDEVICE_1462030C: return "K8N Neo-FSR v2.0 mainboard";
        case PciSubDevice10EC8169::SUBDEVICE_1462065C: return "Hetis 865GV-E (MS-7065)";
        case PciSubDevice10EC8169::SUBDEVICE_1462702C: return "K8T NEO 2 motherboard";
        case PciSubDevice10EC8169::SUBDEVICE_14627094: return "K8T Neo2-F V2.0";
        case PciSubDevice10EC8169::SUBDEVICE_16EC011F: return "USR997903";
        case PciSubDevice10EC8169::SUBDEVICE_17341091: return "D2030-A1";
        case PciSubDevice10EC8169::SUBDEVICE_A0A00449: return "AK86-L motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8169_H
