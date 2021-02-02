// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025941_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025941_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025941: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14584019 = 0x14584019,
    SUBDEVICE_174B7C12 = 0x174B7C12,
    SUBDEVICE_17AF200D = 0x17AF200D,
    SUBDEVICE_18BC0050 = 0x18BC0050
};



inline const char8* enumToString(PciSubDevice10025941 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025941::NONE:               return "NONE";
        case PciSubDevice10025941::SUBDEVICE_14584019: return "SUBDEVICE_14584019";
        case PciSubDevice10025941::SUBDEVICE_174B7C12: return "SUBDEVICE_174B7C12";
        case PciSubDevice10025941::SUBDEVICE_17AF200D: return "SUBDEVICE_17AF200D";
        case PciSubDevice10025941::SUBDEVICE_18BC0050: return "SUBDEVICE_18BC0050";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025941 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025941 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025941::SUBDEVICE_14584019: return "Radeon 9200";
        case PciSubDevice10025941::SUBDEVICE_174B7C12: return "Radeon 9200";
        case PciSubDevice10025941::SUBDEVICE_17AF200D: return "Excalibur Radeon 9200";
        case PciSubDevice10025941::SUBDEVICE_18BC0050: return "GC-R9200-C3 (Secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025941_H
