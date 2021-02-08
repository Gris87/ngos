// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE14159501_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE14159501_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14159501: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12C40201 = 0x12C40201,
    SUBDEVICE_12C40202 = 0x12C40202,
    SUBDEVICE_12C40203 = 0x12C40203,
    SUBDEVICE_12C40210 = 0x12C40210,
    SUBDEVICE_131F2050 = 0x131F2050,
    SUBDEVICE_131F2051 = 0x131F2051,
    SUBDEVICE_15ED2000 = 0x15ED2000,
    SUBDEVICE_15ED2001 = 0x15ED2001
};



inline const char8* enumToString(PciSubDevice14159501 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14159501::NONE:               return "NONE";
        case PciSubDevice14159501::SUBDEVICE_12C40201: return "SUBDEVICE_12C40201";
        case PciSubDevice14159501::SUBDEVICE_12C40202: return "SUBDEVICE_12C40202";
        case PciSubDevice14159501::SUBDEVICE_12C40203: return "SUBDEVICE_12C40203";
        case PciSubDevice14159501::SUBDEVICE_12C40210: return "SUBDEVICE_12C40210";
        case PciSubDevice14159501::SUBDEVICE_131F2050: return "SUBDEVICE_131F2050";
        case PciSubDevice14159501::SUBDEVICE_131F2051: return "SUBDEVICE_131F2051";
        case PciSubDevice14159501::SUBDEVICE_15ED2000: return "SUBDEVICE_15ED2000";
        case PciSubDevice14159501::SUBDEVICE_15ED2001: return "SUBDEVICE_15ED2001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14159501 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14159501 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14159501::SUBDEVICE_12C40201: return "Titan/cPCI (2 port)";
        case PciSubDevice14159501::SUBDEVICE_12C40202: return "Titan/cPCI (4 port)";
        case PciSubDevice14159501::SUBDEVICE_12C40203: return "Titan/cPCI (8 port)";
        case PciSubDevice14159501::SUBDEVICE_12C40210: return "Titan/104-Plus (8 port, p1-4)";
        case PciSubDevice14159501::SUBDEVICE_131F2050: return "CyberPro (4-port)";
        case PciSubDevice14159501::SUBDEVICE_131F2051: return "CyberSerial 4S Plus";
        case PciSubDevice14159501::SUBDEVICE_15ED2000: return "MCCR Serial p0-3 of 8";
        case PciSubDevice14159501::SUBDEVICE_15ED2001: return "MCCR Serial p0-3 of 16";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE14159501_H
