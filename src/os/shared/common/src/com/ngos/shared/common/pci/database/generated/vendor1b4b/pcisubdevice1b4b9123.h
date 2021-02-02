// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B9123_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B9123_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1B4B9123: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_DC93600E = 0xDC93600E
};



inline const char8* enumToString(PciSubDevice1B4B9123 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B4B9123::NONE:               return "NONE";
        case PciSubDevice1B4B9123::SUBDEVICE_DC93600E: return "SUBDEVICE_DC93600E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1B4B9123 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1B4B9123 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B4B9123::SUBDEVICE_DC93600E: return "DC-6xxe series SATA 6G controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B9123_H
