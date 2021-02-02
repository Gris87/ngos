// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086100D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280123 = 0x10280123,
    SUBDEVICE_1079891F = 0x1079891F,
    SUBDEVICE_4C531080 = 0x4C531080,
    SUBDEVICE_8086110D = 0x8086110D
};



inline const char8* enumToString(PciSubDevice8086100D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086100D::NONE:               return "NONE";
        case PciSubDevice8086100D::SUBDEVICE_10280123: return "SUBDEVICE_10280123";
        case PciSubDevice8086100D::SUBDEVICE_1079891F: return "SUBDEVICE_1079891F";
        case PciSubDevice8086100D::SUBDEVICE_4C531080: return "SUBDEVICE_4C531080";
        case PciSubDevice8086100D::SUBDEVICE_8086110D: return "SUBDEVICE_8086110D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086100D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086100D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086100D::SUBDEVICE_10280123: return "PRO/1000 XT Network Connection";
        case PciSubDevice8086100D::SUBDEVICE_1079891F: return "82544GC Based Network Connection";
        case PciSubDevice8086100D::SUBDEVICE_4C531080: return "CT8 mainboard";
        case PciSubDevice8086100D::SUBDEVICE_8086110D: return "82544GC Based Network Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100D_H
