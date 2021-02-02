// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140180_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140180_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10140180: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140241 = 0x10140241,
    SUBDEVICE_10140264 = 0x10140264
};



inline const char8* enumToString(PciSubDevice10140180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140180::NONE:               return "NONE";
        case PciSubDevice10140180::SUBDEVICE_10140241: return "SUBDEVICE_10140241";
        case PciSubDevice10140180::SUBDEVICE_10140264: return "SUBDEVICE_10140264";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10140180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10140180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140180::SUBDEVICE_10140241: return "iSeries 2757 DASD IOA";
        case PciSubDevice10140180::SUBDEVICE_10140264: return "Quad Channel PCI-X bad_uint320 SCSI RAID Adapter (2780)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140180_H
