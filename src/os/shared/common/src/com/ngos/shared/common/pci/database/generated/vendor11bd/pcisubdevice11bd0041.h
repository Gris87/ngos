// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCISUBDEVICE11BD0041_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCISUBDEVICE11BD0041_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11BD0041: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11BD0044 = 0x11BD0044,
    SUBDEVICE_11BD0045 = 0x11BD0045
};



inline const char8* enumToString(PciSubDevice11BD0041 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11BD0041::NONE:               return "NONE";
        case PciSubDevice11BD0041::SUBDEVICE_11BD0044: return "SUBDEVICE_11BD0044";
        case PciSubDevice11BD0041::SUBDEVICE_11BD0045: return "SUBDEVICE_11BD0045";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11BD0041 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11BD0041 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11BD0041::SUBDEVICE_11BD0044: return "PCTV 2000i Dual DVB-T Pro PCI Tuner 2";
        case PciSubDevice11BD0041::SUBDEVICE_11BD0045: return "PCTV Dual Sat Pro PCI 4000i Tuner 2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BD_PCISUBDEVICE11BD0041_H
