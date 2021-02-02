// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCIDEVICE109E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCIDEVICE109E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor109e/pcisubdevice109e0369.h>
#include <com/ngos/shared/common/pci/database/generated/vendor109e/pcisubdevice109e036c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor109e/pcisubdevice109e036e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor109e/pcisubdevice109e036f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor109e/pcisubdevice109e0370.h>
#include <com/ngos/shared/common/pci/database/generated/vendor109e/pcisubdevice109e0878.h>
#include <com/ngos/shared/common/pci/database/generated/vendor109e/pcisubdevice109e0879.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice109E: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0310 = 0x0310,
    DEVICE_032E = 0x032E,
    DEVICE_0350 = 0x0350,
    DEVICE_0351 = 0x0351,
    DEVICE_0369 = 0x0369,
    DEVICE_036C = 0x036C,
    DEVICE_036E = 0x036E,
    DEVICE_036F = 0x036F,
    DEVICE_0370 = 0x0370,
    DEVICE_0878 = 0x0878,
    DEVICE_0879 = 0x0879,
    DEVICE_0880 = 0x0880,
    DEVICE_2115 = 0x2115,
    DEVICE_2125 = 0x2125,
    DEVICE_2164 = 0x2164,
    DEVICE_2165 = 0x2165,
    DEVICE_8230 = 0x8230,
    DEVICE_8472 = 0x8472,
    DEVICE_8474 = 0x8474
};



inline const char8* enumToString(PciDevice109E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice109E::NONE:        return "NONE";
        case PciDevice109E::DEVICE_0310: return "DEVICE_0310";
        case PciDevice109E::DEVICE_032E: return "DEVICE_032E";
        case PciDevice109E::DEVICE_0350: return "DEVICE_0350";
        case PciDevice109E::DEVICE_0351: return "DEVICE_0351";
        case PciDevice109E::DEVICE_0369: return "DEVICE_0369";
        case PciDevice109E::DEVICE_036C: return "DEVICE_036C";
        case PciDevice109E::DEVICE_036E: return "DEVICE_036E";
        case PciDevice109E::DEVICE_036F: return "DEVICE_036F";
        case PciDevice109E::DEVICE_0370: return "DEVICE_0370";
        case PciDevice109E::DEVICE_0878: return "DEVICE_0878";
        case PciDevice109E::DEVICE_0879: return "DEVICE_0879";
        case PciDevice109E::DEVICE_0880: return "DEVICE_0880";
        case PciDevice109E::DEVICE_2115: return "DEVICE_2115";
        case PciDevice109E::DEVICE_2125: return "DEVICE_2125";
        case PciDevice109E::DEVICE_2164: return "DEVICE_2164";
        case PciDevice109E::DEVICE_2165: return "DEVICE_2165";
        case PciDevice109E::DEVICE_8230: return "DEVICE_8230";
        case PciDevice109E::DEVICE_8472: return "DEVICE_8472";
        case PciDevice109E::DEVICE_8474: return "DEVICE_8474";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice109E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice109E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice109E::DEVICE_0310: return "Bt848 Video Capture";
        case PciDevice109E::DEVICE_032E: return "Bt878 Video Capture";
        case PciDevice109E::DEVICE_0350: return "Bt848 Video Capture";
        case PciDevice109E::DEVICE_0351: return "Bt849A Video capture";
        case PciDevice109E::DEVICE_0369: return "Bt878 Video Capture";
        case PciDevice109E::DEVICE_036C: return "Bt879(??) Video Capture";
        case PciDevice109E::DEVICE_036E: return "Bt878 Video Capture";
        case PciDevice109E::DEVICE_036F: return "Bt879 Video Capture";
        case PciDevice109E::DEVICE_0370: return "Bt880 Video Capture";
        case PciDevice109E::DEVICE_0878: return "Bt878 Audio Capture";
        case PciDevice109E::DEVICE_0879: return "Bt879 Audio Capture";
        case PciDevice109E::DEVICE_0880: return "Bt880 Audio Capture";
        case PciDevice109E::DEVICE_2115: return "BtV 2115 Mediastream controller";
        case PciDevice109E::DEVICE_2125: return "BtV 2125 Mediastream controller";
        case PciDevice109E::DEVICE_2164: return "BtV 2164";
        case PciDevice109E::DEVICE_2165: return "BtV 2165";
        case PciDevice109E::DEVICE_8230: return "Bt8230 ATM Segment/Reassembly Ctrlr (SRC)";
        case PciDevice109E::DEVICE_8472: return "Bt8472";
        case PciDevice109E::DEVICE_8474: return "Bt8474";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice109E device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice109E::DEVICE_0310: return "Unknown device";
        case PciDevice109E::DEVICE_032E: return "Unknown device";
        case PciDevice109E::DEVICE_0350: return "Unknown device";
        case PciDevice109E::DEVICE_0351: return "Unknown device";
        case PciDevice109E::DEVICE_0369: return enumToHumanString((PciSubDevice109E0369)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice109E::DEVICE_036C: return enumToHumanString((PciSubDevice109E036C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice109E::DEVICE_036E: return enumToHumanString((PciSubDevice109E036E)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice109E::DEVICE_036F: return enumToHumanString((PciSubDevice109E036F)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice109E::DEVICE_0370: return enumToHumanString((PciSubDevice109E0370)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice109E::DEVICE_0878: return enumToHumanString((PciSubDevice109E0878)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice109E::DEVICE_0879: return enumToHumanString((PciSubDevice109E0879)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice109E::DEVICE_0880: return "Unknown device";
        case PciDevice109E::DEVICE_2115: return "Unknown device";
        case PciDevice109E::DEVICE_2125: return "Unknown device";
        case PciDevice109E::DEVICE_2164: return "Unknown device";
        case PciDevice109E::DEVICE_2165: return "Unknown device";
        case PciDevice109E::DEVICE_8230: return "Unknown device";
        case PciDevice109E::DEVICE_8472: return "Unknown device";
        case PciDevice109E::DEVICE_8474: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCIDEVICE109E_H
