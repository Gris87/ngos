// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF500_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF500_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DFF500: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101406C1 = 0x101406C1,
    SUBDEVICE_101406C2 = 0x101406C2
};



inline const char8* enumToString(PciSubDevice10DFF500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFF500::NONE:               return "NONE";
        case PciSubDevice10DFF500::SUBDEVICE_101406C1: return "SUBDEVICE_101406C1";
        case PciSubDevice10DFF500::SUBDEVICE_101406C2: return "SUBDEVICE_101406C2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DFF500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DFF500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFF500::SUBDEVICE_101406C1: return "PCIe4 4-Port 32Gb Fibre Channel Adapter for POWER (FC EN1L/EN1M; CCIN 2CFC)";
        case PciSubDevice10DFF500::SUBDEVICE_101406C2: return "PCIe4 2-Port 64Gb Fibre Channel Adapter for POWER (FC EN1N/EN1P; CCIN 2CFD)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF500_H
