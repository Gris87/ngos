// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B475F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B475F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B475F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B475F = 0x102B475F,
    SUBDEVICE_102B4D5F = 0x102B4D5F,
    SUBDEVICE_102B4E5F = 0x102B4E5F
};



inline const char8* enumToString(PciSubDevice102B475F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B475F::NONE:               return "NONE";
        case PciSubDevice102B475F::SUBDEVICE_102B475F: return "SUBDEVICE_102B475F";
        case PciSubDevice102B475F::SUBDEVICE_102B4D5F: return "SUBDEVICE_102B4D5F";
        case PciSubDevice102B475F::SUBDEVICE_102B4E5F: return "SUBDEVICE_102B4E5F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B475F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B475F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B475F::SUBDEVICE_102B475F: return "Solios eCL/XCL-F frame grabber";
        case PciSubDevice102B475F::SUBDEVICE_102B4D5F: return "Solios eV-CL (single-Full) frame grabber";
        case PciSubDevice102B475F::SUBDEVICE_102B4E5F: return "Solios eM-CL (single-Full) frame grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B475F_H
