// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE056D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE056D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE056D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1019297A = 0x1019297A,
    SUBDEVICE_10DECB73 = 0x10DECB73
};



inline const char8* enumToString(PciSubDevice10DE056D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE056D::NONE:               return "NONE";
        case PciSubDevice10DE056D::SUBDEVICE_1019297A: return "SUBDEVICE_1019297A";
        case PciSubDevice10DE056D::SUBDEVICE_10DECB73: return "SUBDEVICE_10DECB73";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE056D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE056D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE056D::SUBDEVICE_1019297A: return "MCP73PVT-SM";
        case PciSubDevice10DE056D::SUBDEVICE_10DECB73: return "MCP73 PCI Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE056D_H
