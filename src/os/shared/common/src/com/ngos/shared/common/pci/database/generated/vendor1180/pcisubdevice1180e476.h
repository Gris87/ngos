// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE1180E476_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE1180E476_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1180E476: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040A = 0x1028040A,
    SUBDEVICE_1028040B = 0x1028040B
};



inline const char8* enumToString(PciSubDevice1180E476 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1180E476::NONE:               return "NONE";
        case PciSubDevice1180E476::SUBDEVICE_1028040A: return "SUBDEVICE_1028040A";
        case PciSubDevice1180E476::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1180E476 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1180E476 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1180E476::SUBDEVICE_1028040A: return "Latitude E6410";
        case PciSubDevice1180E476::SUBDEVICE_1028040B: return "Latitude E6510";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE1180E476_H
