// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20704_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20704_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19A20704: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DFE602 = 0x10DFE602,
    SUBDEVICE_10DFE630 = 0x10DFE630
};



inline const char8* enumToString(PciSubDevice19A20704 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19A20704::NONE:               return "NONE";
        case PciSubDevice19A20704::SUBDEVICE_10DFE602: return "SUBDEVICE_10DFE602";
        case PciSubDevice19A20704::SUBDEVICE_10DFE630: return "SUBDEVICE_10DFE630";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19A20704 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19A20704 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19A20704::SUBDEVICE_10DFE602: return "OneConnect OCe10100 10Gb CNA";
        case PciSubDevice19A20704::SUBDEVICE_10DFE630: return "OneConnect OCe10102-FM-E / OCe10102-FX-E for EMC VNX Symmetrix";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20704_H
