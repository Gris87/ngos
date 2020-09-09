// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11489000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11489000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11489000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11482100 = 0x11482100,
    SUBDEVICE_11482200 = 0x11482200,
    SUBDEVICE_11482210 = 0x11482210,
    SUBDEVICE_11482220 = 0x11482220,
    SUBDEVICE_11488100 = 0x11488100,
    SUBDEVICE_11488200 = 0x11488200,
    SUBDEVICE_11488210 = 0x11488210,
    SUBDEVICE_11488220 = 0x11488220,
    SUBDEVICE_11489100 = 0x11489100,
    SUBDEVICE_11489200 = 0x11489200,
    SUBDEVICE_12592973 = 0x12592973,
    SUBDEVICE_12592974 = 0x12592974,
    SUBDEVICE_12592978 = 0x12592978
};



inline const char8* enumToString(PciSubDevice11489000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11489000::NONE:               return "NONE";
        case PciSubDevice11489000::SUBDEVICE_11482100: return "SUBDEVICE_11482100";
        case PciSubDevice11489000::SUBDEVICE_11482200: return "SUBDEVICE_11482200";
        case PciSubDevice11489000::SUBDEVICE_11482210: return "SUBDEVICE_11482210";
        case PciSubDevice11489000::SUBDEVICE_11482220: return "SUBDEVICE_11482220";
        case PciSubDevice11489000::SUBDEVICE_11488100: return "SUBDEVICE_11488100";
        case PciSubDevice11489000::SUBDEVICE_11488200: return "SUBDEVICE_11488200";
        case PciSubDevice11489000::SUBDEVICE_11488210: return "SUBDEVICE_11488210";
        case PciSubDevice11489000::SUBDEVICE_11488220: return "SUBDEVICE_11488220";
        case PciSubDevice11489000::SUBDEVICE_11489100: return "SUBDEVICE_11489100";
        case PciSubDevice11489000::SUBDEVICE_11489200: return "SUBDEVICE_11489200";
        case PciSubDevice11489000::SUBDEVICE_12592973: return "SUBDEVICE_12592973";
        case PciSubDevice11489000::SUBDEVICE_12592974: return "SUBDEVICE_12592974";
        case PciSubDevice11489000::SUBDEVICE_12592978: return "SUBDEVICE_12592978";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11489000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11489000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11489000::SUBDEVICE_11482100: return "SK-9S21 10/100/1000Base-T Server Adapter, PCI-X, Copper RJ-45";
        case PciSubDevice11489000::SUBDEVICE_11482200: return "SK-9S22 10/100/1000Base-T Dual Port Server Adapter, PCI-X, 2 Copper RJ-45";
        case PciSubDevice11489000::SUBDEVICE_11482210: return "SK-9P22 10/100/1000 Base-T Dual Port PMC card";
        case PciSubDevice11489000::SUBDEVICE_11482220: return "TPMC-GBE-CO";
        case PciSubDevice11489000::SUBDEVICE_11488100: return "SK-9S81 1000Base-SX Server Adapter, PCI-X, Fiber SX/LC";
        case PciSubDevice11489000::SUBDEVICE_11488200: return "SK-9S82 1000Base-SX Dual Port Server Adapter, PCI-X, 2 Fiber SX/LC";
        case PciSubDevice11489000::SUBDEVICE_11488210: return "SK-9P82 1000 Base-SX Dual Port PMC card";
        case PciSubDevice11489000::SUBDEVICE_11488220: return "TPMC-GBE-FI";
        case PciSubDevice11489000::SUBDEVICE_11489100: return "SK-9S91 1000Base-LX Server Adapter, PCI-X, Fiber LX/LC";
        case PciSubDevice11489000::SUBDEVICE_11489200: return "SK-9S92 1000Base-LX Dual Port Server Adapter, PCI-X, 2 Fiber LX/LC";
        case PciSubDevice11489000::SUBDEVICE_12592973: return "AT-2971SX v2 Gigabit Adapter";
        case PciSubDevice11489000::SUBDEVICE_12592974: return "AT-2971T v2 Gigabit Adapter";
        case PciSubDevice11489000::SUBDEVICE_12592978: return "AT-2971LX Gigabit Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11489000_H
