// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000000B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E116004 = 0x0E116004,
    SUBDEVICE_10001000 = 0x10001000,
    SUBDEVICE_10001010 = 0x10001010,
    SUBDEVICE_10001020 = 0x10001020,
    SUBDEVICE_13E91000 = 0x13E91000
};



inline const char8* enumToString(PciSubDevice1000000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000000B::NONE:               return "NONE";
        case PciSubDevice1000000B::SUBDEVICE_0E116004: return "SUBDEVICE_0E116004";
        case PciSubDevice1000000B::SUBDEVICE_10001000: return "SUBDEVICE_10001000";
        case PciSubDevice1000000B::SUBDEVICE_10001010: return "SUBDEVICE_10001010";
        case PciSubDevice1000000B::SUBDEVICE_10001020: return "SUBDEVICE_10001020";
        case PciSubDevice1000000B::SUBDEVICE_13E91000: return "SUBDEVICE_13E91000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000000B::SUBDEVICE_0E116004: return "EOB003 Series SCSI host adapter";
        case PciSubDevice1000000B::SUBDEVICE_10001000: return "LSI53C896/7 PCI to Dual Channel Ultra2 SCSI Multifunction Controller";
        case PciSubDevice1000000B::SUBDEVICE_10001010: return "LSI22910 PCI to Dual Channel Ultra2 SCSI host adapter";
        case PciSubDevice1000000B::SUBDEVICE_10001020: return "LSI21002 PCI to Dual Channel Ultra2 SCSI host adapter";
        case PciSubDevice1000000B::SUBDEVICE_13E91000: return "6221L-4U (Dual U2W SCSI, dual 10/100TX, graphics)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000B_H
