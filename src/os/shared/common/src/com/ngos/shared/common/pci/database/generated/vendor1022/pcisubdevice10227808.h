// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10227808_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10227808_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10227808: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C194E = 0x103C194E,
    SUBDEVICE_103C1985 = 0x103C1985,
    SUBDEVICE_10438623 = 0x10438623,
    SUBDEVICE_17AA3988 = 0x17AA3988,
    SUBDEVICE_18497808 = 0x18497808
};



inline const char8* enumToString(PciSubDevice10227808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10227808::NONE:               return "NONE";
        case PciSubDevice10227808::SUBDEVICE_103C194E: return "SUBDEVICE_103C194E";
        case PciSubDevice10227808::SUBDEVICE_103C1985: return "SUBDEVICE_103C1985";
        case PciSubDevice10227808::SUBDEVICE_10438623: return "SUBDEVICE_10438623";
        case PciSubDevice10227808::SUBDEVICE_17AA3988: return "SUBDEVICE_17AA3988";
        case PciSubDevice10227808::SUBDEVICE_18497808: return "SUBDEVICE_18497808";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10227808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10227808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10227808::SUBDEVICE_103C194E: return "ProBook 455 G1 Notebook";
        case PciSubDevice10227808::SUBDEVICE_103C1985: return "Pavilion 17-e163sg Notebook PC";
        case PciSubDevice10227808::SUBDEVICE_10438623: return "AM1I-A Motherboard";
        case PciSubDevice10227808::SUBDEVICE_17AA3988: return "Z50-75";
        case PciSubDevice10227808::SUBDEVICE_18497808: return "QC5000-ITX/PH";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10227808_H
