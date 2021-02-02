// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135C_PCIDEVICE135C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135C_PCIDEVICE135C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice135C: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0020 = 0x0020,
    DEVICE_0030 = 0x0030,
    DEVICE_0040 = 0x0040,
    DEVICE_0050 = 0x0050,
    DEVICE_0060 = 0x0060,
    DEVICE_00F0 = 0x00F0,
    DEVICE_0170 = 0x0170,
    DEVICE_0180 = 0x0180,
    DEVICE_0190 = 0x0190,
    DEVICE_01A0 = 0x01A0,
    DEVICE_01B0 = 0x01B0,
    DEVICE_01C0 = 0x01C0,
    DEVICE_0258 = 0x0258
};



inline const char8* enumToString(PciDevice135C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice135C::NONE:        return "NONE";
        case PciDevice135C::DEVICE_0010: return "DEVICE_0010";
        case PciDevice135C::DEVICE_0020: return "DEVICE_0020";
        case PciDevice135C::DEVICE_0030: return "DEVICE_0030";
        case PciDevice135C::DEVICE_0040: return "DEVICE_0040";
        case PciDevice135C::DEVICE_0050: return "DEVICE_0050";
        case PciDevice135C::DEVICE_0060: return "DEVICE_0060";
        case PciDevice135C::DEVICE_00F0: return "DEVICE_00F0";
        case PciDevice135C::DEVICE_0170: return "DEVICE_0170";
        case PciDevice135C::DEVICE_0180: return "DEVICE_0180";
        case PciDevice135C::DEVICE_0190: return "DEVICE_0190";
        case PciDevice135C::DEVICE_01A0: return "DEVICE_01A0";
        case PciDevice135C::DEVICE_01B0: return "DEVICE_01B0";
        case PciDevice135C::DEVICE_01C0: return "DEVICE_01C0";
        case PciDevice135C::DEVICE_0258: return "DEVICE_0258";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice135C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice135C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice135C::DEVICE_0010: return "QSC-100";
        case PciDevice135C::DEVICE_0020: return "DSC-100";
        case PciDevice135C::DEVICE_0030: return "DSC-200/300";
        case PciDevice135C::DEVICE_0040: return "QSC-200/300";
        case PciDevice135C::DEVICE_0050: return "ESC-100D";
        case PciDevice135C::DEVICE_0060: return "ESC-100M";
        case PciDevice135C::DEVICE_00F0: return "MPAC-100 Synchronous Serial Card (Zilog 85230)";
        case PciDevice135C::DEVICE_0170: return "QSCLP-100";
        case PciDevice135C::DEVICE_0180: return "DSCLP-100";
        case PciDevice135C::DEVICE_0190: return "SSCLP-100";
        case PciDevice135C::DEVICE_01A0: return "QSCLP-200/300";
        case PciDevice135C::DEVICE_01B0: return "DSCLP-200/300";
        case PciDevice135C::DEVICE_01C0: return "SSCLP-200/300";
        case PciDevice135C::DEVICE_0258: return "DSPSX-200/300";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR135C_PCIDEVICE135C_H
