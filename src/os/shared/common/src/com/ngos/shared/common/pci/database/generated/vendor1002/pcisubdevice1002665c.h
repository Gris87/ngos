// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002665C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002665C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002665C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430452 = 0x10430452,
    SUBDEVICE_14622930 = 0x14622930,
    SUBDEVICE_14622932 = 0x14622932,
    SUBDEVICE_14622934 = 0x14622934,
    SUBDEVICE_14622938 = 0x14622938,
    SUBDEVICE_148C0907 = 0x148C0907,
    SUBDEVICE_148C9260 = 0x148C9260,
    SUBDEVICE_148C9360 = 0x148C9360,
    SUBDEVICE_16820907 = 0x16820907,
    SUBDEVICE_16823310 = 0x16823310,
    SUBDEVICE_174BE253 = 0x174BE253,
    SUBDEVICE_17872329 = 0x17872329
};



inline const char8* enumToString(PciSubDevice1002665C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002665C::NONE:               return "NONE";
        case PciSubDevice1002665C::SUBDEVICE_10430452: return "SUBDEVICE_10430452";
        case PciSubDevice1002665C::SUBDEVICE_14622930: return "SUBDEVICE_14622930";
        case PciSubDevice1002665C::SUBDEVICE_14622932: return "SUBDEVICE_14622932";
        case PciSubDevice1002665C::SUBDEVICE_14622934: return "SUBDEVICE_14622934";
        case PciSubDevice1002665C::SUBDEVICE_14622938: return "SUBDEVICE_14622938";
        case PciSubDevice1002665C::SUBDEVICE_148C0907: return "SUBDEVICE_148C0907";
        case PciSubDevice1002665C::SUBDEVICE_148C9260: return "SUBDEVICE_148C9260";
        case PciSubDevice1002665C::SUBDEVICE_148C9360: return "SUBDEVICE_148C9360";
        case PciSubDevice1002665C::SUBDEVICE_16820907: return "SUBDEVICE_16820907";
        case PciSubDevice1002665C::SUBDEVICE_16823310: return "SUBDEVICE_16823310";
        case PciSubDevice1002665C::SUBDEVICE_174BE253: return "SUBDEVICE_174BE253";
        case PciSubDevice1002665C::SUBDEVICE_17872329: return "SUBDEVICE_17872329";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002665C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002665C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002665C::SUBDEVICE_10430452: return "Radeon HD 7790 DirectCU II OC";
        case PciSubDevice1002665C::SUBDEVICE_14622930: return "Radeon HD 7790 OC";
        case PciSubDevice1002665C::SUBDEVICE_14622932: return "Radeon HD 8770";
        case PciSubDevice1002665C::SUBDEVICE_14622934: return "Radeon R9 260 OEM";
        case PciSubDevice1002665C::SUBDEVICE_14622938: return "Radeon R9 360 OEM";
        case PciSubDevice1002665C::SUBDEVICE_148C0907: return "Radeon R7 360";
        case PciSubDevice1002665C::SUBDEVICE_148C9260: return "Radeon R9 260 OEM";
        case PciSubDevice1002665C::SUBDEVICE_148C9360: return "Radeon R9 360 OEM";
        case PciSubDevice1002665C::SUBDEVICE_16820907: return "Radeon R7 360";
        case PciSubDevice1002665C::SUBDEVICE_16823310: return "Radeon HD 7790 Black Edition 2 GB";
        case PciSubDevice1002665C::SUBDEVICE_174BE253: return "Radeon HD 7790 Dual-X OC";
        case PciSubDevice1002665C::SUBDEVICE_17872329: return "Radeon HD 7790 TurboDuo";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002665C_H
