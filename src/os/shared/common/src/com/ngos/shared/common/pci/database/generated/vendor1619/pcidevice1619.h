// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1619_PCIDEVICE1619_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1619_PCIDEVICE1619_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1619: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0400 = 0x0400,
    DEVICE_0440 = 0x0440,
    DEVICE_0610 = 0x0610,
    DEVICE_0620 = 0x0620,
    DEVICE_0640 = 0x0640,
    DEVICE_1610 = 0x1610,
    DEVICE_1612 = 0x1612,
    DEVICE_2610 = 0x2610,
    DEVICE_3640 = 0x3640,
    DEVICE_4620 = 0x4620,
    DEVICE_4640 = 0x4640,
    DEVICE_5621 = 0x5621,
    DEVICE_5641 = 0x5641,
    DEVICE_6620 = 0x6620
};



inline const char8* enumToString(PciDevice1619 device1619) // TEST: NO
{
    // COMMON_LT((" | device1619 = %u", device1619)); // Commented to avoid bad looking logs



    switch (device1619)
    {
        case PciDevice1619::NONE:        return "NONE";
        case PciDevice1619::DEVICE_0400: return "DEVICE_0400";
        case PciDevice1619::DEVICE_0440: return "DEVICE_0440";
        case PciDevice1619::DEVICE_0610: return "DEVICE_0610";
        case PciDevice1619::DEVICE_0620: return "DEVICE_0620";
        case PciDevice1619::DEVICE_0640: return "DEVICE_0640";
        case PciDevice1619::DEVICE_1610: return "DEVICE_1610";
        case PciDevice1619::DEVICE_1612: return "DEVICE_1612";
        case PciDevice1619::DEVICE_2610: return "DEVICE_2610";
        case PciDevice1619::DEVICE_3640: return "DEVICE_3640";
        case PciDevice1619::DEVICE_4620: return "DEVICE_4620";
        case PciDevice1619::DEVICE_4640: return "DEVICE_4640";
        case PciDevice1619::DEVICE_5621: return "DEVICE_5621";
        case PciDevice1619::DEVICE_5641: return "DEVICE_5641";
        case PciDevice1619::DEVICE_6620: return "DEVICE_6620";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1619 device1619) // TEST: NO
{
    // COMMON_LT((" | device1619 = %u", device1619)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1619, enumToString(device1619));

    return res;
}



inline const char8* enumToHumanString(PciDevice1619 device1619) // TEST: NO
{
    // COMMON_LT((" | device1619 = %u", device1619)); // Commented to avoid bad looking logs



    switch (device1619)
    {
        case PciDevice1619::DEVICE_0400: return "FarSync T2P (2 port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_0440: return "FarSync T4P (4 port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_0610: return "FarSync T1U (1 port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_0620: return "FarSync T2U (2 port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_0640: return "FarSync T4U (4 port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_1610: return "FarSync TE1 (T1,E1)";
        case PciDevice1619::DEVICE_1612: return "FarSync TE1 PCI Express (T1,E1)";
        case PciDevice1619::DEVICE_2610: return "FarSync DSL-S1 (SHDSL)";
        case PciDevice1619::DEVICE_3640: return "FarSync T4E (4-port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_4620: return "FarSync T2Ue PCI Express (2-port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_4640: return "FarSync T4Ue PCI Express (4-port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_5621: return "FarSync T2Ee PCI Express (2 port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_5641: return "FarSync T4Ee PCI Express (4 port X.21/V.35/V.24)";
        case PciDevice1619::DEVICE_6620: return "FarSync T2U-PMC PCI Express (2 port X.21/V.35/V.24)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1619_PCIDEVICE1619_H
