// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1105_PCIDEVICE1105_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1105_PCIDEVICE1105_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1105/pcisubdevice11058475.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1105/pcisubdevice11058476.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1105: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1105 = 0x1105,
    DEVICE_8300 = 0x8300,
    DEVICE_8400 = 0x8400,
    DEVICE_8401 = 0x8401,
    DEVICE_8470 = 0x8470,
    DEVICE_8471 = 0x8471,
    DEVICE_8475 = 0x8475,
    DEVICE_8476 = 0x8476,
    DEVICE_8485 = 0x8485,
    DEVICE_8486 = 0x8486,
    DEVICE_C621 = 0xC621,
    DEVICE_C622 = 0xC622
};



inline const char8* enumToString(PciDevice1105 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1105::NONE:        return "NONE";
        case PciDevice1105::DEVICE_1105: return "DEVICE_1105";
        case PciDevice1105::DEVICE_8300: return "DEVICE_8300";
        case PciDevice1105::DEVICE_8400: return "DEVICE_8400";
        case PciDevice1105::DEVICE_8401: return "DEVICE_8401";
        case PciDevice1105::DEVICE_8470: return "DEVICE_8470";
        case PciDevice1105::DEVICE_8471: return "DEVICE_8471";
        case PciDevice1105::DEVICE_8475: return "DEVICE_8475";
        case PciDevice1105::DEVICE_8476: return "DEVICE_8476";
        case PciDevice1105::DEVICE_8485: return "DEVICE_8485";
        case PciDevice1105::DEVICE_8486: return "DEVICE_8486";
        case PciDevice1105::DEVICE_C621: return "DEVICE_C621";
        case PciDevice1105::DEVICE_C622: return "DEVICE_C622";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1105 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1105 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1105::DEVICE_1105: return "REALmagic Xcard MPEG 1/2/3/4 DVD Decoder";
        case PciDevice1105::DEVICE_8300: return "REALmagic Hollywood Plus DVD Decoder";
        case PciDevice1105::DEVICE_8400: return "EM840x REALmagic DVD/MPEG-2 Audio/Video Decoder";
        case PciDevice1105::DEVICE_8401: return "EM8401 REALmagic DVD/MPEG-2 A/V Decoder";
        case PciDevice1105::DEVICE_8470: return "EM8470 REALmagic DVD/MPEG-4 A/V Decoder";
        case PciDevice1105::DEVICE_8471: return "EM8471 REALmagic DVD/MPEG-4 A/V Decoder";
        case PciDevice1105::DEVICE_8475: return "EM8475 REALmagic DVD/MPEG-4 A/V Decoder";
        case PciDevice1105::DEVICE_8476: return "EM8476 REALmagic DVD/MPEG-4 A/V Decoder";
        case PciDevice1105::DEVICE_8485: return "EM8485 REALmagic DVD/MPEG-4 A/V Decoder";
        case PciDevice1105::DEVICE_8486: return "EM8486 REALmagic DVD/MPEG-4 A/V Decoder";
        case PciDevice1105::DEVICE_C621: return "EM8621L Digital Media Processor";
        case PciDevice1105::DEVICE_C622: return "EM8622L MPEG-4.10 (H.264) and SMPTE 421M (VC-1) A/V Decoder";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1105 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1105::DEVICE_1105: return "Unknown device";
        case PciDevice1105::DEVICE_8300: return "Unknown device";
        case PciDevice1105::DEVICE_8400: return "Unknown device";
        case PciDevice1105::DEVICE_8401: return "Unknown device";
        case PciDevice1105::DEVICE_8470: return "Unknown device";
        case PciDevice1105::DEVICE_8471: return "Unknown device";
        case PciDevice1105::DEVICE_8475: return enumToHumanString((PciSubDevice11058475)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1105::DEVICE_8476: return enumToHumanString((PciSubDevice11058476)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1105::DEVICE_8485: return "Unknown device";
        case PciDevice1105::DEVICE_8486: return "Unknown device";
        case PciDevice1105::DEVICE_C621: return "Unknown device";
        case PciDevice1105::DEVICE_C622: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1105_PCIDEVICE1105_H
