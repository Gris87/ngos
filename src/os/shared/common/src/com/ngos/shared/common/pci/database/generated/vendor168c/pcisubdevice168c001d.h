// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C001D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1799720B = 0x1799720B,
    SUBDEVICE_1799721B = 0x1799721B
};



inline const char8* enumToString(PciSubDevice168C001D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C001D::NONE:               return "NONE";
        case PciSubDevice168C001D::SUBDEVICE_1799720B: return "SUBDEVICE_1799720B";
        case PciSubDevice168C001D::SUBDEVICE_1799721B: return "SUBDEVICE_1799721B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C001D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C001D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C001D::SUBDEVICE_1799720B: return "F5D7000 v8000 Wireless G Desktop Card";
        case PciSubDevice168C001D::SUBDEVICE_1799721B: return "F5D7010 v8000 Wireless G Notebook Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001D_H
