// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCIDEVICE11DE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCIDEVICE11DE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11DE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6017 = 0x6017,
    DEVICE_6057 = 0x6057,
    DEVICE_6120 = 0x6120
};



inline const char8* enumToString(PciDevice11DE device11DE) // TEST: NO
{
    // COMMON_LT((" | device11DE = %u", device11DE)); // Commented to avoid bad looking logs



    switch (device11DE)
    {
        case PciDevice11DE::NONE:        return "NONE";
        case PciDevice11DE::DEVICE_6017: return "DEVICE_6017";
        case PciDevice11DE::DEVICE_6057: return "DEVICE_6057";
        case PciDevice11DE::DEVICE_6120: return "DEVICE_6120";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11DE device11DE) // TEST: NO
{
    // COMMON_LT((" | device11DE = %u", device11DE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11DE, enumToString(device11DE));

    return res;
}



inline const char8* enumToHumanString(PciDevice11DE device11DE) // TEST: NO
{
    // COMMON_LT((" | device11DE = %u", device11DE)); // Commented to avoid bad looking logs



    switch (device11DE)
    {
        case PciDevice11DE::DEVICE_6017: return "miroVIDEO DC30";
        case PciDevice11DE::DEVICE_6057: return "ZR36057PQC Video cutting chipset";
        case PciDevice11DE::DEVICE_6120: return "ZR36120";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11DE_PCIDEVICE11DE_H
