// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice111A0007: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_111A1001 = 0x111A1001
};



inline const char8* enumToString(PciSubDevice111A0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice111A0007::NONE:               return "NONE";
        case PciSubDevice111A0007::SUBDEVICE_111A1001: return "SUBDEVICE_111A1001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice111A0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice111A0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice111A0007::SUBDEVICE_111A1001: return "ENI-3061 ADSL [ASIC]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0007_H
