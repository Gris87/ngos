// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863594_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863594_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863594: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17751100 = 0x17751100,
    SUBDEVICE_4C5310D0 = 0x4C5310D0
};



inline const char8* enumToString(PciSubDevice80863594 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863594::NONE:               return "NONE";
        case PciSubDevice80863594::SUBDEVICE_17751100: return "SUBDEVICE_17751100";
        case PciSubDevice80863594::SUBDEVICE_4C5310D0: return "SUBDEVICE_4C5310D0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863594 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863594 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863594::SUBDEVICE_17751100: return "CR11/VR11 Single Board Computer";
        case PciSubDevice80863594::SUBDEVICE_4C5310D0: return "Telum ASLP10 Processor AMC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863594_H
