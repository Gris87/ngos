// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCIDEVICE102A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCIDEVICE102A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice102A: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0010 = 0x0010,
    DEVICE_001F = 0x001F,
    DEVICE_00C5 = 0x00C5,
    DEVICE_00CF = 0x00CF
};



inline const char8* enumToString(PciDevice102A device102A) // TEST: NO
{
    // COMMON_LT((" | device102A = %u", device102A)); // Commented to avoid bad looking logs



    switch (device102A)
    {
        case PciDevice102A::DEVICE_0000: return "DEVICE_0000";
        case PciDevice102A::DEVICE_0010: return "DEVICE_0010";
        case PciDevice102A::DEVICE_001F: return "DEVICE_001F";
        case PciDevice102A::DEVICE_00C5: return "DEVICE_00C5";
        case PciDevice102A::DEVICE_00CF: return "DEVICE_00CF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice102A device102A) // TEST: NO
{
    // COMMON_LT((" | device102A = %u", device102A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device102A, enumToString(device102A));

    return res;
}



inline const char8* enumToHumanString(PciDevice102A device102A) // TEST: NO
{
    // COMMON_LT((" | device102A = %u", device102A)); // Commented to avoid bad looking logs



    switch (device102A)
    {
        case PciDevice102A::DEVICE_0000: return "HYDRA";
        case PciDevice102A::DEVICE_0010: return "ASPEN";
        case PciDevice102A::DEVICE_001F: return "AHA-2940U2/U2W /7890/7891 SCSI Controllers";
        case PciDevice102A::DEVICE_00C5: return "AIC-7899 U160/m SCSI Controller";
        case PciDevice102A::DEVICE_00CF: return "AIC-7899P U160/m";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCIDEVICE102A_H
