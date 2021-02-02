// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4165E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_103C0890 = 0x103C0890,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_10CF1279 = 0x10CF1279
};



inline const char8* enumToString(PciSubDevice14E4165E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4165E::NONE:               return "NONE";
        case PciSubDevice14E4165E::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice14E4165E::SUBDEVICE_103C0890: return "SUBDEVICE_103C0890";
        case PciSubDevice14E4165E::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice14E4165E::SUBDEVICE_10CF1279: return "SUBDEVICE_10CF1279";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4165E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4165E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4165E::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice14E4165E::SUBDEVICE_103C0890: return "NC6000 laptop";
        case PciSubDevice14E4165E::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice14E4165E::SUBDEVICE_10CF1279: return "LifeBook E8010D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165E_H
