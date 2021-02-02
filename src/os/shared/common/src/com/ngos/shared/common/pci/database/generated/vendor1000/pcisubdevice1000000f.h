// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000000F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E117004 = 0x0E117004,
    SUBDEVICE_10001000 = 0x10001000,
    SUBDEVICE_10001010 = 0x10001010,
    SUBDEVICE_10001020 = 0x10001020,
    SUBDEVICE_10928760 = 0x10928760,
    SUBDEVICE_177510D0 = 0x177510D0,
    SUBDEVICE_177510D1 = 0x177510D1,
    SUBDEVICE_1DE13904 = 0x1DE13904,
    SUBDEVICE_4C531000 = 0x4C531000,
    SUBDEVICE_4C531050 = 0x4C531050
};



inline const char8* enumToString(PciSubDevice1000000F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000000F::NONE:               return "NONE";
        case PciSubDevice1000000F::SUBDEVICE_0E117004: return "SUBDEVICE_0E117004";
        case PciSubDevice1000000F::SUBDEVICE_10001000: return "SUBDEVICE_10001000";
        case PciSubDevice1000000F::SUBDEVICE_10001010: return "SUBDEVICE_10001010";
        case PciSubDevice1000000F::SUBDEVICE_10001020: return "SUBDEVICE_10001020";
        case PciSubDevice1000000F::SUBDEVICE_10928760: return "SUBDEVICE_10928760";
        case PciSubDevice1000000F::SUBDEVICE_177510D0: return "SUBDEVICE_177510D0";
        case PciSubDevice1000000F::SUBDEVICE_177510D1: return "SUBDEVICE_177510D1";
        case PciSubDevice1000000F::SUBDEVICE_1DE13904: return "SUBDEVICE_1DE13904";
        case PciSubDevice1000000F::SUBDEVICE_4C531000: return "SUBDEVICE_4C531000";
        case PciSubDevice1000000F::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000000F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000000F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000000F::SUBDEVICE_0E117004: return "Embedded Ultra Wide SCSI Controller";
        case PciSubDevice1000000F::SUBDEVICE_10001000: return "LSI53C876/E PCI to Dual Channel SCSI Controller";
        case PciSubDevice1000000F::SUBDEVICE_10001010: return "LSI22801 PCI to Dual Channel Ultra SCSI host adapter";
        case PciSubDevice1000000F::SUBDEVICE_10001020: return "LSI22802 PCI to Dual Channel Ultra SCSI host adapter";
        case PciSubDevice1000000F::SUBDEVICE_10928760: return "FirePort 40 Dual SCSI Controller";
        case PciSubDevice1000000F::SUBDEVICE_177510D0: return "V5D Single Board Computer Wide Ultra SCSI";
        case PciSubDevice1000000F::SUBDEVICE_177510D1: return "V5D Single Board Computer Ultra SCSI";
        case PciSubDevice1000000F::SUBDEVICE_1DE13904: return "DC390F/U Ultra Wide SCSI Adapter";
        case PciSubDevice1000000F::SUBDEVICE_4C531000: return "CC7/CR7/CP7/VC7/VP7/VR7 mainboard";
        case PciSubDevice1000000F::SUBDEVICE_4C531050: return "CT7 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000F_H
