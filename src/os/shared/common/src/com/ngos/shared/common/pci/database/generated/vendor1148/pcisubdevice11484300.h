// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11484300: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11489821 = 0x11489821,
    SUBDEVICE_11489822 = 0x11489822,
    SUBDEVICE_11489841 = 0x11489841,
    SUBDEVICE_11489842 = 0x11489842,
    SUBDEVICE_11489843 = 0x11489843,
    SUBDEVICE_11489844 = 0x11489844,
    SUBDEVICE_11489861 = 0x11489861,
    SUBDEVICE_11489862 = 0x11489862,
    SUBDEVICE_11489871 = 0x11489871,
    SUBDEVICE_11489872 = 0x11489872,
    SUBDEVICE_12592970 = 0x12592970,
    SUBDEVICE_12592971 = 0x12592971,
    SUBDEVICE_12592972 = 0x12592972,
    SUBDEVICE_12592973 = 0x12592973,
    SUBDEVICE_12592974 = 0x12592974,
    SUBDEVICE_12592975 = 0x12592975,
    SUBDEVICE_12592976 = 0x12592976,
    SUBDEVICE_12592977 = 0x12592977
};



inline const char8* enumToString(PciSubDevice11484300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11484300::NONE:               return "NONE";
        case PciSubDevice11484300::SUBDEVICE_11489821: return "SUBDEVICE_11489821";
        case PciSubDevice11484300::SUBDEVICE_11489822: return "SUBDEVICE_11489822";
        case PciSubDevice11484300::SUBDEVICE_11489841: return "SUBDEVICE_11489841";
        case PciSubDevice11484300::SUBDEVICE_11489842: return "SUBDEVICE_11489842";
        case PciSubDevice11484300::SUBDEVICE_11489843: return "SUBDEVICE_11489843";
        case PciSubDevice11484300::SUBDEVICE_11489844: return "SUBDEVICE_11489844";
        case PciSubDevice11484300::SUBDEVICE_11489861: return "SUBDEVICE_11489861";
        case PciSubDevice11484300::SUBDEVICE_11489862: return "SUBDEVICE_11489862";
        case PciSubDevice11484300::SUBDEVICE_11489871: return "SUBDEVICE_11489871";
        case PciSubDevice11484300::SUBDEVICE_11489872: return "SUBDEVICE_11489872";
        case PciSubDevice11484300::SUBDEVICE_12592970: return "SUBDEVICE_12592970";
        case PciSubDevice11484300::SUBDEVICE_12592971: return "SUBDEVICE_12592971";
        case PciSubDevice11484300::SUBDEVICE_12592972: return "SUBDEVICE_12592972";
        case PciSubDevice11484300::SUBDEVICE_12592973: return "SUBDEVICE_12592973";
        case PciSubDevice11484300::SUBDEVICE_12592974: return "SUBDEVICE_12592974";
        case PciSubDevice11484300::SUBDEVICE_12592975: return "SUBDEVICE_12592975";
        case PciSubDevice11484300::SUBDEVICE_12592976: return "SUBDEVICE_12592976";
        case PciSubDevice11484300::SUBDEVICE_12592977: return "SUBDEVICE_12592977";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11484300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11484300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11484300::SUBDEVICE_11489821: return "SK-9821 Gigabit Ethernet Server Adapter (SK-NET GE-T)";
        case PciSubDevice11484300::SUBDEVICE_11489822: return "SK-9822 Gigabit Ethernet Server Adapter (SK-NET GE-T dual link)";
        case PciSubDevice11484300::SUBDEVICE_11489841: return "SK-9841 Gigabit Ethernet Server Adapter (SK-NET GE-LX)";
        case PciSubDevice11484300::SUBDEVICE_11489842: return "SK-9842 Gigabit Ethernet Server Adapter (SK-NET GE-LX dual link)";
        case PciSubDevice11484300::SUBDEVICE_11489843: return "SK-9843 Gigabit Ethernet Server Adapter (SK-NET GE-SX)";
        case PciSubDevice11484300::SUBDEVICE_11489844: return "SK-9844 Gigabit Ethernet Server Adapter (SK-NET GE-SX dual link)";
        case PciSubDevice11484300::SUBDEVICE_11489861: return "SK-9861 Gigabit Ethernet Server Adapter (SK-NET GE-SX Volition)";
        case PciSubDevice11484300::SUBDEVICE_11489862: return "SK-9862 Gigabit Ethernet Server Adapter (SK-NET GE-SX Volition dual link)";
        case PciSubDevice11484300::SUBDEVICE_11489871: return "SK-9871 Gigabit Ethernet Server Adapter (SK-NET GE-ZX)";
        case PciSubDevice11484300::SUBDEVICE_11489872: return "SK-9872 Gigabit Ethernet Server Adapter (SK-NET GE-ZX dual link)";
        case PciSubDevice11484300::SUBDEVICE_12592970: return "AT-2970SX Gigabit Ethernet Adapter";
        case PciSubDevice11484300::SUBDEVICE_12592971: return "AT-2970LX Gigabit Ethernet Adapter";
        case PciSubDevice11484300::SUBDEVICE_12592972: return "AT-2970TX Gigabit Ethernet Adapter";
        case PciSubDevice11484300::SUBDEVICE_12592973: return "AT-2971SX Gigabit Ethernet Adapter";
        case PciSubDevice11484300::SUBDEVICE_12592974: return "AT-2971T Gigabit Ethernet Adapter";
        case PciSubDevice11484300::SUBDEVICE_12592975: return "AT-2970SX/2SC Gigabit Ethernet Adapter";
        case PciSubDevice11484300::SUBDEVICE_12592976: return "AT-2970LX/2SC Gigabit Ethernet Adapter";
        case PciSubDevice11484300::SUBDEVICE_12592977: return "AT-2970TX/2TX Gigabit Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484300_H
