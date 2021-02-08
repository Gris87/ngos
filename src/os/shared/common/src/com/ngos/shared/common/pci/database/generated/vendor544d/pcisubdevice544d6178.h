// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544D_PCISUBDEVICE544D6178_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544D_PCISUBDEVICE544D6178_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice544D6178: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_544D6904 = 0x544D6904,
    SUBDEVICE_544D6905 = 0x544D6905,
    SUBDEVICE_62050001 = 0x62050001,
    SUBDEVICE_62090001 = 0x62090001
};



inline const char8* enumToString(PciSubDevice544D6178 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice544D6178::NONE:               return "NONE";
        case PciSubDevice544D6178::SUBDEVICE_544D6904: return "SUBDEVICE_544D6904";
        case PciSubDevice544D6178::SUBDEVICE_544D6905: return "SUBDEVICE_544D6905";
        case PciSubDevice544D6178::SUBDEVICE_62050001: return "SUBDEVICE_62050001";
        case PciSubDevice544D6178::SUBDEVICE_62090001: return "SUBDEVICE_62090001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice544D6178 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice544D6178 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice544D6178::SUBDEVICE_544D6904: return "TBS6904 DVB-S2 Quad Tuner PCIe Card";
        case PciSubDevice544D6178::SUBDEVICE_544D6905: return "TBS6905 DVB-S2 Quad Tuner PCIe Card";
        case PciSubDevice544D6178::SUBDEVICE_62050001: return "TBS6205 DVB-T2/T/C Quad TV Tuner PCIe Card";
        case PciSubDevice544D6178::SUBDEVICE_62090001: return "TBS6209 DVB-T2/C2/T/C/ISDB-T OctaTV Tuner";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544D_PCISUBDEVICE544D6178_H
