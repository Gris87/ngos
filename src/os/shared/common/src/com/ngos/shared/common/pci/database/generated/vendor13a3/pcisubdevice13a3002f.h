// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCISUBDEVICE13A3002F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCISUBDEVICE13A3002F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13A3002F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13A31600 = 0x13A31600,
    SUBDEVICE_13A31605 = 0x13A31605,
    SUBDEVICE_13A31610 = 0x13A31610,
    SUBDEVICE_13A31615 = 0x13A31615,
    SUBDEVICE_13A31620 = 0x13A31620,
    SUBDEVICE_13A31625 = 0x13A31625
};



inline const char8* enumToString(PciSubDevice13A3002F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13A3002F::NONE:               return "NONE";
        case PciSubDevice13A3002F::SUBDEVICE_13A31600: return "SUBDEVICE_13A31600";
        case PciSubDevice13A3002F::SUBDEVICE_13A31605: return "SUBDEVICE_13A31605";
        case PciSubDevice13A3002F::SUBDEVICE_13A31610: return "SUBDEVICE_13A31610";
        case PciSubDevice13A3002F::SUBDEVICE_13A31615: return "SUBDEVICE_13A31615";
        case PciSubDevice13A3002F::SUBDEVICE_13A31620: return "SUBDEVICE_13A31620";
        case PciSubDevice13A3002F::SUBDEVICE_13A31625: return "SUBDEVICE_13A31625";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13A3002F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13A3002F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13A3002F::SUBDEVICE_13A31600: return "DR1600 Acceleration Card";
        case PciSubDevice13A3002F::SUBDEVICE_13A31605: return "DR1605 Acceleration Card";
        case PciSubDevice13A3002F::SUBDEVICE_13A31610: return "DR1610 Acceleration Card";
        case PciSubDevice13A3002F::SUBDEVICE_13A31615: return "DR1615 Acceleration Card";
        case PciSubDevice13A3002F::SUBDEVICE_13A31620: return "DR1620 Acceleration Card";
        case PciSubDevice13A3002F::SUBDEVICE_13A31625: return "DR1625 Acceleration Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCISUBDEVICE13A3002F_H
