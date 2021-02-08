// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024966_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024966_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024966: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10F10002 = 0x10F10002,
    SUBDEVICE_148C2039 = 0x148C2039,
    SUBDEVICE_15099A00 = 0x15099A00,
    SUBDEVICE_16810040 = 0x16810040,
    SUBDEVICE_174B7176 = 0x174B7176,
    SUBDEVICE_174B7192 = 0x174B7192,
    SUBDEVICE_17AF2005 = 0x17AF2005,
    SUBDEVICE_17AF2006 = 0x17AF2006
};



inline const char8* enumToString(PciSubDevice10024966 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024966::NONE:               return "NONE";
        case PciSubDevice10024966::SUBDEVICE_10F10002: return "SUBDEVICE_10F10002";
        case PciSubDevice10024966::SUBDEVICE_148C2039: return "SUBDEVICE_148C2039";
        case PciSubDevice10024966::SUBDEVICE_15099A00: return "SUBDEVICE_15099A00";
        case PciSubDevice10024966::SUBDEVICE_16810040: return "SUBDEVICE_16810040";
        case PciSubDevice10024966::SUBDEVICE_174B7176: return "SUBDEVICE_174B7176";
        case PciSubDevice10024966::SUBDEVICE_174B7192: return "SUBDEVICE_174B7192";
        case PciSubDevice10024966::SUBDEVICE_17AF2005: return "SUBDEVICE_17AF2005";
        case PciSubDevice10024966::SUBDEVICE_17AF2006: return "SUBDEVICE_17AF2006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024966 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024966 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024966::SUBDEVICE_10F10002: return "RV250 If [Tachyon G9000 PRO]";
        case PciSubDevice10024966::SUBDEVICE_148C2039: return "RV250 If [Radeon 9000 Pro \"Evil Commando\"]";
        case PciSubDevice10024966::SUBDEVICE_15099A00: return "RV250 If [Radeon 9000 \"AT009\"]";
        case PciSubDevice10024966::SUBDEVICE_16810040: return "RV250 If [3D prophet 9000]";
        case PciSubDevice10024966::SUBDEVICE_174B7176: return "Radeon 9000 Pro";
        case PciSubDevice10024966::SUBDEVICE_174B7192: return "RV250 If [Radeon 9000 \"Atlantis\"]";
        case PciSubDevice10024966::SUBDEVICE_17AF2005: return "RV250 If [Excalibur Radeon 9000 Pro]";
        case PciSubDevice10024966::SUBDEVICE_17AF2006: return "RV250 If [Excalibur Radeon 9000]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024966_H
