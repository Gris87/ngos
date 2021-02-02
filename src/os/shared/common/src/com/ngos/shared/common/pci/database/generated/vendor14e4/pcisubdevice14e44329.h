// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44329_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44329_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44329: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13857B00 = 0x13857B00,
    SUBDEVICE_13857D00 = 0x13857D00,
    SUBDEVICE_17370058 = 0x17370058
};



inline const char8* enumToString(PciSubDevice14E44329 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44329::NONE:               return "NONE";
        case PciSubDevice14E44329::SUBDEVICE_13857B00: return "SUBDEVICE_13857B00";
        case PciSubDevice14E44329::SUBDEVICE_13857D00: return "SUBDEVICE_13857D00";
        case PciSubDevice14E44329::SUBDEVICE_17370058: return "SUBDEVICE_17370058";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44329 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44329 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44329::SUBDEVICE_13857B00: return "WN511B RangeMax NEXT Wireless Notebook Adapter";
        case PciSubDevice14E44329::SUBDEVICE_13857D00: return "WN311B RangeMax Next 270 Mbps Wireless PCI Adapter";
        case PciSubDevice14E44329::SUBDEVICE_17370058: return "WPC300N v1 Wireless-N Notebook Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44329_H
