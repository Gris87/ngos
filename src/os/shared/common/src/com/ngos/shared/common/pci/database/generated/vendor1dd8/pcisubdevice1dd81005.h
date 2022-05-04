// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCISUBDEVICE1DD81005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCISUBDEVICE1DD81005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1DD81005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1DD85001 = 0x1DD85001,
    SUBDEVICE_1DD85003 = 0x1DD85003
};



inline const char8* enumToString(PciSubDevice1DD81005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1DD81005::NONE:               return "NONE";
        case PciSubDevice1DD81005::SUBDEVICE_1DD85001: return "SUBDEVICE_1DD85001";
        case PciSubDevice1DD81005::SUBDEVICE_1DD85003: return "SUBDEVICE_1DD85003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1DD81005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1DD81005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1DD81005::SUBDEVICE_1DD85001: return "DSC2-200 50/100/200G 2-port 32G RAM 64G eMMC G2 Services Card";
        case PciSubDevice1DD81005::SUBDEVICE_1DD85003: return "DSC2-200 50/100/200G 2-port 32G RAM 64G eMMC G2 Services Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCISUBDEVICE1DD81005_H
