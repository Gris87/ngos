// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE056E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE056E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE056E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1019297A = 0x1019297A,
    SUBDEVICE_10DE0000 = 0x10DE0000
};



inline const char8* enumToString(PciSubDevice10DE056E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE056E::NONE:               return "NONE";
        case PciSubDevice10DE056E::SUBDEVICE_1019297A: return "SUBDEVICE_1019297A";
        case PciSubDevice10DE056E::SUBDEVICE_10DE0000: return "SUBDEVICE_10DE0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE056E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE056E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE056E::SUBDEVICE_1019297A: return "MCP73PVT-SM";
        case PciSubDevice10DE056E::SUBDEVICE_10DE0000: return "MCP73 PCIe x16 port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE056E_H
