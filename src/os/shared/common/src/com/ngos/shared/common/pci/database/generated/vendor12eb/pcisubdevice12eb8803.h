// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB8803_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB8803_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12EB8803: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12EB8803 = 0x12EB8803
};



inline const char8* enumToString(PciSubDevice12EB8803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12EB8803::NONE:               return "NONE";
        case PciSubDevice12EB8803::SUBDEVICE_12EB8803: return "SUBDEVICE_12EB8803";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12EB8803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12EB8803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12EB8803::SUBDEVICE_12EB8803: return "Vortex 56k Software Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB8803_H
