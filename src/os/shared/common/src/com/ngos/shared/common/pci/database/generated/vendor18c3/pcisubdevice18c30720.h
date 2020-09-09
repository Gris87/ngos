// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCISUBDEVICE18C30720_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCISUBDEVICE18C30720_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18C30720: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1461032E = 0x1461032E
};



inline const char8* enumToString(PciSubDevice18C30720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18C30720::NONE:               return "NONE";
        case PciSubDevice18C30720::SUBDEVICE_1461032E: return "SUBDEVICE_1461032E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18C30720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18C30720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18C30720::SUBDEVICE_1461032E: return "Hybrid M779 PCI-E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCISUBDEVICE18C30720_H
