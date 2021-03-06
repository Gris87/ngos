// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860E2A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860E2A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860E2A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804F7 = 0x102804F7,
    SUBDEVICE_15D9066B = 0x15D9066B
};



inline const char8* enumToString(PciSubDevice80860E2A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860E2A::NONE:               return "NONE";
        case PciSubDevice80860E2A::SUBDEVICE_102804F7: return "SUBDEVICE_102804F7";
        case PciSubDevice80860E2A::SUBDEVICE_15D9066B: return "SUBDEVICE_15D9066B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860E2A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860E2A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860E2A::SUBDEVICE_102804F7: return "Xeon E5 v2 on PowerEdge R320 server";
        case PciSubDevice80860E2A::SUBDEVICE_15D9066B: return "X9SRL-F";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860E2A_H
