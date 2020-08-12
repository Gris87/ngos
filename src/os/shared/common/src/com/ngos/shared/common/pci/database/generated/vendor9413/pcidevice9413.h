// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9413_PCIDEVICE9413_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9413_PCIDEVICE9413_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9413: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6010 = 0x6010,
    DEVICE_6110 = 0x6110
};



inline const char8* enumToString(PciDevice9413 device9413) // TEST: NO
{
    // COMMON_LT((" | device9413 = %u", device9413)); // Commented to avoid bad looking logs



    switch (device9413)
    {
        case PciDevice9413::NONE:        return "NONE";
        case PciDevice9413::DEVICE_6010: return "DEVICE_6010";
        case PciDevice9413::DEVICE_6110: return "DEVICE_6110";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9413 device9413) // TEST: NO
{
    // COMMON_LT((" | device9413 = %u", device9413)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device9413, enumToString(device9413));

    return res;
}



inline const char8* enumToHumanString(PciDevice9413 device9413) // TEST: NO
{
    // COMMON_LT((" | device9413 = %u", device9413)); // Commented to avoid bad looking logs



    switch (device9413)
    {
        case PciDevice9413::DEVICE_6010: return "SOLO6010 MPEG-4 Video encoder/decoder";
        case PciDevice9413::DEVICE_6110: return "SOLO6110 H.264 Video encoder/decoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9413_PCIDEVICE9413_H
