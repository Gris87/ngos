// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1578_PCIDEVICE1578_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1578_PCIDEVICE1578_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1578: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4D34 = 0x4D34,
    DEVICE_5615 = 0x5615
};



inline const char8* enumToString(PciDevice1578 device1578) // TEST: NO
{
    // COMMON_LT((" | device1578 = %u", device1578)); // Commented to avoid bad looking logs



    switch (device1578)
    {
        case PciDevice1578::NONE:        return "NONE";
        case PciDevice1578::DEVICE_4D34: return "DEVICE_4D34";
        case PciDevice1578::DEVICE_5615: return "DEVICE_5615";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1578 device1578) // TEST: NO
{
    // COMMON_LT((" | device1578 = %u", device1578)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1578, enumToString(device1578));

    return res;
}



inline const char8* enumToHumanString(PciDevice1578 device1578) // TEST: NO
{
    // COMMON_LT((" | device1578 = %u", device1578)); // Commented to avoid bad looking logs



    switch (device1578)
    {
        case PciDevice1578::DEVICE_4D34: return "VPMK4 [Video Processor Mk IV]";
        case PciDevice1578::DEVICE_5615: return "VPMK3 [Video Processor Mk III]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1578_PCIDEVICE1578_H
