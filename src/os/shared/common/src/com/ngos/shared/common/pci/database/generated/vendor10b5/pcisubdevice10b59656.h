// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59656_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59656_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B59656: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1517000F = 0x1517000F,
    SUBDEVICE_18850700 = 0x18850700,
    SUBDEVICE_18850701 = 0x18850701
};



inline const char8* enumToString(PciSubDevice10B59656 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59656::NONE:               return "NONE";
        case PciSubDevice10B59656::SUBDEVICE_1517000F: return "SUBDEVICE_1517000F";
        case PciSubDevice10B59656::SUBDEVICE_18850700: return "SUBDEVICE_18850700";
        case PciSubDevice10B59656::SUBDEVICE_18850701: return "SUBDEVICE_18850701";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B59656 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B59656 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59656::SUBDEVICE_1517000F: return "ECDR-GC314-PMC Receiver";
        case PciSubDevice10B59656::SUBDEVICE_18850700: return "Tsunami FPGA PMC with Altera Stratix S40";
        case PciSubDevice10B59656::SUBDEVICE_18850701: return "Tsunami FPGA PMC with Altera Stratix S30";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59656_H
