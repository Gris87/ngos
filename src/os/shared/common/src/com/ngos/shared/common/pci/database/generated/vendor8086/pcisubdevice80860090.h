// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860090_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860090_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860090: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80865211 = 0x80865211,
    SUBDEVICE_80865215 = 0x80865215,
    SUBDEVICE_80865216 = 0x80865216
};



inline const char8* enumToString(PciSubDevice80860090 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860090::NONE:               return "NONE";
        case PciSubDevice80860090::SUBDEVICE_80865211: return "SUBDEVICE_80865211";
        case PciSubDevice80860090::SUBDEVICE_80865215: return "SUBDEVICE_80865215";
        case PciSubDevice80860090::SUBDEVICE_80865216: return "SUBDEVICE_80865216";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860090 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860090 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860090::SUBDEVICE_80865211: return "Centrino Advanced-N 6230 AGN";
        case PciSubDevice80860090::SUBDEVICE_80865215: return "Centrino Advanced-N 6230 BGN";
        case PciSubDevice80860090::SUBDEVICE_80865216: return "Centrino Advanced-N 6230 ABG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860090_H
