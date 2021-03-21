// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772031_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772031_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772031: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C17E7 = 0x103C17E7,
    SUBDEVICE_103C17E8 = 0x103C17E8,
    SUBDEVICE_103C1939 = 0x103C1939,
    SUBDEVICE_103C8002 = 0x103C8002,
    SUBDEVICE_10770241 = 0x10770241
};



inline const char8* enumToString(PciSubDevice10772031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772031::NONE:               return "NONE";
        case PciSubDevice10772031::SUBDEVICE_103C17E7: return "SUBDEVICE_103C17E7";
        case PciSubDevice10772031::SUBDEVICE_103C17E8: return "SUBDEVICE_103C17E8";
        case PciSubDevice10772031::SUBDEVICE_103C1939: return "SUBDEVICE_103C1939";
        case PciSubDevice10772031::SUBDEVICE_103C8002: return "SUBDEVICE_103C8002";
        case PciSubDevice10772031::SUBDEVICE_10770241: return "SUBDEVICE_10770241";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772031::SUBDEVICE_103C17E7: return "SN1000Q 16Gb Single Port Fibre Channel Adapter";
        case PciSubDevice10772031::SUBDEVICE_103C17E8: return "SN1000Q 16Gb Dual Port Fibre Channel Adapter";
        case PciSubDevice10772031::SUBDEVICE_103C1939: return "QMH2672 16Gb Dual Port Fibre Channel Adapter";
        case PciSubDevice10772031::SUBDEVICE_103C8002: return "3830C 16G Fibre Channel Host Bus Adapter";
        case PciSubDevice10772031::SUBDEVICE_10770241: return "QLE2670 16Gb Single Port Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772031_H
