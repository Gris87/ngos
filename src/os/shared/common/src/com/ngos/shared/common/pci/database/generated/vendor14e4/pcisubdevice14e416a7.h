// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416A7: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100CA = 0x0E1100CA,
    SUBDEVICE_0E1100CB = 0x0E1100CB,
    SUBDEVICE_1014026F = 0x1014026F,
    SUBDEVICE_14E40009 = 0x14E40009,
    SUBDEVICE_14E4000A = 0x14E4000A,
    SUBDEVICE_14E4000B = 0x14E4000B,
    SUBDEVICE_14E4800A = 0x14E4800A
};



inline const char8* enumToString(PciSubDevice14E416A7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416A7::NONE:               return "NONE";
        case PciSubDevice14E416A7::SUBDEVICE_0E1100CA: return "SUBDEVICE_0E1100CA";
        case PciSubDevice14E416A7::SUBDEVICE_0E1100CB: return "SUBDEVICE_0E1100CB";
        case PciSubDevice14E416A7::SUBDEVICE_1014026F: return "SUBDEVICE_1014026F";
        case PciSubDevice14E416A7::SUBDEVICE_14E40009: return "SUBDEVICE_14E40009";
        case PciSubDevice14E416A7::SUBDEVICE_14E4000A: return "SUBDEVICE_14E4000A";
        case PciSubDevice14E416A7::SUBDEVICE_14E4000B: return "SUBDEVICE_14E4000B";
        case PciSubDevice14E416A7::SUBDEVICE_14E4800A: return "SUBDEVICE_14E4800A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416A7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416A7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416A7::SUBDEVICE_0E1100CA: return "NC7771 Gigabit Server Adapter (PCI-X, 10, 100, 1000-T)";
        case PciSubDevice14E416A7::SUBDEVICE_0E1100CB: return "NC7781 Gigabit Server Adapter (PCI-X, 10, 100, 1000-T)";
        case PciSubDevice14E416A7::SUBDEVICE_1014026F: return "eServer xSeries server mainboard";
        case PciSubDevice14E416A7::SUBDEVICE_14E40009: return "NetXtreme BCM5703 1000Base-T";
        case PciSubDevice14E416A7::SUBDEVICE_14E4000A: return "NetXtreme BCM5703 1000Base-SX";
        case PciSubDevice14E416A7::SUBDEVICE_14E4000B: return "NetXtreme BCM5703 1000Base-T";
        case PciSubDevice14E416A7::SUBDEVICE_14E4800A: return "NetXtreme BCM5703 1000Base-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A7_H
