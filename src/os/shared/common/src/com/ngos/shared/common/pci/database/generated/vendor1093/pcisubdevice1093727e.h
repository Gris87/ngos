// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1093_PCISUBDEVICE1093727E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1093_PCISUBDEVICE1093727E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1093727E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_109375AC = 0x109375AC,
    SUBDEVICE_109375AD = 0x109375AD,
    SUBDEVICE_10937650 = 0x10937650,
    SUBDEVICE_10938360 = 0x10938360,
    SUBDEVICE_10938370 = 0x10938370,
    SUBDEVICE_10938375 = 0x10938375
};



inline const char8* enumToString(PciSubDevice1093727E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1093727E::NONE:               return "NONE";
        case PciSubDevice1093727E::SUBDEVICE_109375AC: return "SUBDEVICE_109375AC";
        case PciSubDevice1093727E::SUBDEVICE_109375AD: return "SUBDEVICE_109375AD";
        case PciSubDevice1093727E::SUBDEVICE_10937650: return "SUBDEVICE_10937650";
        case PciSubDevice1093727E::SUBDEVICE_10938360: return "SUBDEVICE_10938360";
        case PciSubDevice1093727E::SUBDEVICE_10938370: return "SUBDEVICE_10938370";
        case PciSubDevice1093727E::SUBDEVICE_10938375: return "SUBDEVICE_10938375";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1093727E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1093727E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1093727E::SUBDEVICE_109375AC: return "PXIe-8388";
        case PciSubDevice1093727E::SUBDEVICE_109375AD: return "PXIe-8389";
        case PciSubDevice1093727E::SUBDEVICE_10937650: return "PXIe-8381";
        case PciSubDevice1093727E::SUBDEVICE_10938360: return "PXIe-8360";
        case PciSubDevice1093727E::SUBDEVICE_10938370: return "PXIe-8370";
        case PciSubDevice1093727E::SUBDEVICE_10938375: return "PXIe-8375";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1093_PCISUBDEVICE1093727E_H
