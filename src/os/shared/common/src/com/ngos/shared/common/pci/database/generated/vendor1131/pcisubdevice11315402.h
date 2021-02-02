// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11315402_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11315402_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11315402: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12440F00 = 0x12440F00,
    SUBDEVICE_15EB1300 = 0x15EB1300,
    SUBDEVICE_15EB1302 = 0x15EB1302,
    SUBDEVICE_15EB1304 = 0x15EB1304,
    SUBDEVICE_15EB1305 = 0x15EB1305,
    SUBDEVICE_15EB1306 = 0x15EB1306,
    SUBDEVICE_15EB1308 = 0x15EB1308,
    SUBDEVICE_15EB1331 = 0x15EB1331,
    SUBDEVICE_15EB1337 = 0x15EB1337,
    SUBDEVICE_15EB2D3D = 0x15EB2D3D,
    SUBDEVICE_15EB7022 = 0x15EB7022
};



inline const char8* enumToString(PciSubDevice11315402 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11315402::NONE:               return "NONE";
        case PciSubDevice11315402::SUBDEVICE_12440F00: return "SUBDEVICE_12440F00";
        case PciSubDevice11315402::SUBDEVICE_15EB1300: return "SUBDEVICE_15EB1300";
        case PciSubDevice11315402::SUBDEVICE_15EB1302: return "SUBDEVICE_15EB1302";
        case PciSubDevice11315402::SUBDEVICE_15EB1304: return "SUBDEVICE_15EB1304";
        case PciSubDevice11315402::SUBDEVICE_15EB1305: return "SUBDEVICE_15EB1305";
        case PciSubDevice11315402::SUBDEVICE_15EB1306: return "SUBDEVICE_15EB1306";
        case PciSubDevice11315402::SUBDEVICE_15EB1308: return "SUBDEVICE_15EB1308";
        case PciSubDevice11315402::SUBDEVICE_15EB1331: return "SUBDEVICE_15EB1331";
        case PciSubDevice11315402::SUBDEVICE_15EB1337: return "SUBDEVICE_15EB1337";
        case PciSubDevice11315402::SUBDEVICE_15EB2D3D: return "SUBDEVICE_15EB2D3D";
        case PciSubDevice11315402::SUBDEVICE_15EB7022: return "SUBDEVICE_15EB7022";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11315402 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11315402 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11315402::SUBDEVICE_12440F00: return "Fritz!Card DSL";
        case PciSubDevice11315402::SUBDEVICE_15EB1300: return "DT1300";
        case PciSubDevice11315402::SUBDEVICE_15EB1302: return "DT1302";
        case PciSubDevice11315402::SUBDEVICE_15EB1304: return "DT1304";
        case PciSubDevice11315402::SUBDEVICE_15EB1305: return "DT1305";
        case PciSubDevice11315402::SUBDEVICE_15EB1306: return "PMCDT1306";
        case PciSubDevice11315402::SUBDEVICE_15EB1308: return "DT1308";
        case PciSubDevice11315402::SUBDEVICE_15EB1331: return "DT1301 with SAA7121";
        case PciSubDevice11315402::SUBDEVICE_15EB1337: return "DT1301 with SAA7127";
        case PciSubDevice11315402::SUBDEVICE_15EB2D3D: return "X3D";
        case PciSubDevice11315402::SUBDEVICE_15EB7022: return "PTM1300";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11315402_H
