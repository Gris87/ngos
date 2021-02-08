// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44727_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44727_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44727: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280010 = 0x10280010
};



inline const char8* enumToString(PciSubDevice14E44727 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44727::NONE:               return "NONE";
        case PciSubDevice14E44727::SUBDEVICE_10280010: return "SUBDEVICE_10280010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44727 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44727 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44727::SUBDEVICE_10280010: return "Inspiron M5010 / XPS 8300";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44727_H
