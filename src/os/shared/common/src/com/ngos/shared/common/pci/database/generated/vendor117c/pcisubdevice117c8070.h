// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C8070_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C8070_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C8070: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C0070 = 0x117C0070,
    SUBDEVICE_117C0071 = 0x117C0071,
    SUBDEVICE_117C0080 = 0x117C0080
};



inline const char8* enumToString(PciSubDevice117C8070 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C8070::NONE:               return "NONE";
        case PciSubDevice117C8070::SUBDEVICE_117C0070: return "SUBDEVICE_117C0070";
        case PciSubDevice117C8070::SUBDEVICE_117C0071: return "SUBDEVICE_117C0071";
        case PciSubDevice117C8070::SUBDEVICE_117C0080: return "SUBDEVICE_117C0080";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C8070 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C8070 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C8070::SUBDEVICE_117C0070: return "ExpressSAS H1280";
        case PciSubDevice117C8070::SUBDEVICE_117C0071: return "ExpressSAS H1208";
        case PciSubDevice117C8070::SUBDEVICE_117C0080: return "ExpressSAS H1244";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C8070_H
