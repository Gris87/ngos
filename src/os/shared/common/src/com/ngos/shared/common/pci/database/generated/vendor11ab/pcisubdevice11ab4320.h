// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4320_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4320_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB4320: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190F38 = 0x10190F38,
    SUBDEVICE_10198001 = 0x10198001,
    SUBDEVICE_1043173C = 0x1043173C,
    SUBDEVICE_1043811A = 0x1043811A,
    SUBDEVICE_105B0C19 = 0x105B0C19,
    SUBDEVICE_10B8B452 = 0x10B8B452,
    SUBDEVICE_11AB0121 = 0x11AB0121,
    SUBDEVICE_11AB0321 = 0x11AB0321,
    SUBDEVICE_11AB1021 = 0x11AB1021,
    SUBDEVICE_11AB4320 = 0x11AB4320,
    SUBDEVICE_11AB5021 = 0x11AB5021,
    SUBDEVICE_11AB9521 = 0x11AB9521,
    SUBDEVICE_1458E000 = 0x1458E000,
    SUBDEVICE_147B1406 = 0x147B1406,
    SUBDEVICE_15D40047 = 0x15D40047,
    SUBDEVICE_16959025 = 0x16959025,
    SUBDEVICE_17F21C03 = 0x17F21C03,
    SUBDEVICE_270F2803 = 0x270F2803
};



inline const char8* enumToString(PciSubDevice11AB4320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4320::NONE:               return "NONE";
        case PciSubDevice11AB4320::SUBDEVICE_10190F38: return "SUBDEVICE_10190F38";
        case PciSubDevice11AB4320::SUBDEVICE_10198001: return "SUBDEVICE_10198001";
        case PciSubDevice11AB4320::SUBDEVICE_1043173C: return "SUBDEVICE_1043173C";
        case PciSubDevice11AB4320::SUBDEVICE_1043811A: return "SUBDEVICE_1043811A";
        case PciSubDevice11AB4320::SUBDEVICE_105B0C19: return "SUBDEVICE_105B0C19";
        case PciSubDevice11AB4320::SUBDEVICE_10B8B452: return "SUBDEVICE_10B8B452";
        case PciSubDevice11AB4320::SUBDEVICE_11AB0121: return "SUBDEVICE_11AB0121";
        case PciSubDevice11AB4320::SUBDEVICE_11AB0321: return "SUBDEVICE_11AB0321";
        case PciSubDevice11AB4320::SUBDEVICE_11AB1021: return "SUBDEVICE_11AB1021";
        case PciSubDevice11AB4320::SUBDEVICE_11AB4320: return "SUBDEVICE_11AB4320";
        case PciSubDevice11AB4320::SUBDEVICE_11AB5021: return "SUBDEVICE_11AB5021";
        case PciSubDevice11AB4320::SUBDEVICE_11AB9521: return "SUBDEVICE_11AB9521";
        case PciSubDevice11AB4320::SUBDEVICE_1458E000: return "SUBDEVICE_1458E000";
        case PciSubDevice11AB4320::SUBDEVICE_147B1406: return "SUBDEVICE_147B1406";
        case PciSubDevice11AB4320::SUBDEVICE_15D40047: return "SUBDEVICE_15D40047";
        case PciSubDevice11AB4320::SUBDEVICE_16959025: return "SUBDEVICE_16959025";
        case PciSubDevice11AB4320::SUBDEVICE_17F21C03: return "SUBDEVICE_17F21C03";
        case PciSubDevice11AB4320::SUBDEVICE_270F2803: return "SUBDEVICE_270F2803";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB4320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB4320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4320::SUBDEVICE_10190F38: return "Marvell 88E8001 Gigabit Ethernet Controller (ECS)";
        case PciSubDevice11AB4320::SUBDEVICE_10198001: return "Marvell 88E8001 Gigabit Ethernet Controller (ECS)";
        case PciSubDevice11AB4320::SUBDEVICE_1043173C: return "Marvell 88E8001 Gigabit Ethernet Controller (Asus)";
        case PciSubDevice11AB4320::SUBDEVICE_1043811A: return "Marvell 88E8001 Gigabit Ethernet Controller (Asus)";
        case PciSubDevice11AB4320::SUBDEVICE_105B0C19: return "Marvell 88E8001 Gigabit Ethernet Controller (Foxconn)";
        case PciSubDevice11AB4320::SUBDEVICE_10B8B452: return "EZ Card 1000 (SMC9452TXV.2)";
        case PciSubDevice11AB4320::SUBDEVICE_11AB0121: return "Marvell RDK-8001";
        case PciSubDevice11AB4320::SUBDEVICE_11AB0321: return "Marvell RDK-8003";
        case PciSubDevice11AB4320::SUBDEVICE_11AB1021: return "Marvell RDK-8010";
        case PciSubDevice11AB4320::SUBDEVICE_11AB4320: return "Marvell Yukon Gigabit Ethernet 10/100/1000Baset-T Constroller (Asus)";
        case PciSubDevice11AB4320::SUBDEVICE_11AB5021: return "Marvell Yukon Gigabit Ethernet 10/100/1000Base-T Controller (64 bit)";
        case PciSubDevice11AB4320::SUBDEVICE_11AB9521: return "Marvell Yukon Gigabit Ethernet 10/100/1000Base-T Controller (32 bit)";
        case PciSubDevice11AB4320::SUBDEVICE_1458E000: return "Marvell 88E8001 Gigabit Ethernet Controller (Gigabyte)";
        case PciSubDevice11AB4320::SUBDEVICE_147B1406: return "Marvell 88E8001 Gigabit Ethernet Controller (Abit)";
        case PciSubDevice11AB4320::SUBDEVICE_15D40047: return "Marvell 88E8001 Gigabit Ethernet Controller (Iwill)";
        case PciSubDevice11AB4320::SUBDEVICE_16959025: return "Marvell 88E8001 Gigabit Ethernet Controller (Epox)";
        case PciSubDevice11AB4320::SUBDEVICE_17F21C03: return "Marvell 88E8001 Gigabit Ethernet Controller (Albatron)";
        case PciSubDevice11AB4320::SUBDEVICE_270F2803: return "Marvell 88E8001 Gigabit Ethernet Controller (Chaintech)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4320_H
