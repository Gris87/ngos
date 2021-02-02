// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3373_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3373_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105A3373: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380F5 = 0x104380F5,
    SUBDEVICE_1462590D = 0x1462590D,
    SUBDEVICE_1462702E = 0x1462702E
};



inline const char8* enumToString(PciSubDevice105A3373 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A3373::NONE:               return "NONE";
        case PciSubDevice105A3373::SUBDEVICE_104380F5: return "SUBDEVICE_104380F5";
        case PciSubDevice105A3373::SUBDEVICE_1462590D: return "SUBDEVICE_1462590D";
        case PciSubDevice105A3373::SUBDEVICE_1462702E: return "SUBDEVICE_1462702E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105A3373 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105A3373 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A3373::SUBDEVICE_104380F5: return "K8V Deluxe/PC-DL Deluxe motherboard";
        case PciSubDevice105A3373::SUBDEVICE_1462590D: return "KT6 Delta-FIS2R (MS-6590)";
        case PciSubDevice105A3373::SUBDEVICE_1462702E: return "K8T NEO FIS2R motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3373_H
