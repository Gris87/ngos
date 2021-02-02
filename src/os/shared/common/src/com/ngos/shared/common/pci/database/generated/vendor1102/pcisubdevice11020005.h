// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11020005: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11020021 = 0x11020021,
    SUBDEVICE_1102002C = 0x1102002C,
    SUBDEVICE_11021003 = 0x11021003
};



inline const char8* enumToString(PciSubDevice11020005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020005::NONE:               return "NONE";
        case PciSubDevice11020005::SUBDEVICE_11020021: return "SUBDEVICE_11020021";
        case PciSubDevice11020005::SUBDEVICE_1102002C: return "SUBDEVICE_1102002C";
        case PciSubDevice11020005::SUBDEVICE_11021003: return "SUBDEVICE_11021003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11020005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11020005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020005::SUBDEVICE_11020021: return "X-Fi Platinum";
        case PciSubDevice11020005::SUBDEVICE_1102002C: return "X-Fi XtremeGamer FATAL1TY PRO";
        case PciSubDevice11020005::SUBDEVICE_11021003: return "X-Fi XtremeMusic";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020005_H
