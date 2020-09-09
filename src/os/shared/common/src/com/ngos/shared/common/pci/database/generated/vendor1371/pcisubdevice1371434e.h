// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1371_PCISUBDEVICE1371434E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1371_PCISUBDEVICE1371434E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1371434E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1371434E = 0x1371434E
};



inline const char8* enumToString(PciSubDevice1371434E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1371434E::NONE:               return "NONE";
        case PciSubDevice1371434E::SUBDEVICE_1371434E: return "SUBDEVICE_1371434E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1371434E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1371434E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1371434E::SUBDEVICE_1371434E: return "N-Way PCI-Bus Giga-Card 1000/100/10Mbps(L)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1371_PCISUBDEVICE1371434E_H
