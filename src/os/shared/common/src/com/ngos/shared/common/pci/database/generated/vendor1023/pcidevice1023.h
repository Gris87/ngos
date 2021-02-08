// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCIDEVICE1023_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCIDEVICE1023_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1023/pcisubdevice10232001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1023/pcisubdevice10238400.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1023/pcisubdevice10238420.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1023/pcisubdevice10238520.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1023/pcisubdevice10238620.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1023/pcisubdevice10239750.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1023/pcisubdevice10239880.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1023: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0194 = 0x0194,
    DEVICE_2000 = 0x2000,
    DEVICE_2001 = 0x2001,
    DEVICE_2100 = 0x2100,
    DEVICE_2200 = 0x2200,
    DEVICE_8400 = 0x8400,
    DEVICE_8420 = 0x8420,
    DEVICE_8500 = 0x8500,
    DEVICE_8520 = 0x8520,
    DEVICE_8620 = 0x8620,
    DEVICE_8820 = 0x8820,
    DEVICE_9320 = 0x9320,
    DEVICE_9350 = 0x9350,
    DEVICE_9360 = 0x9360,
    DEVICE_9382 = 0x9382,
    DEVICE_9383 = 0x9383,
    DEVICE_9385 = 0x9385,
    DEVICE_9386 = 0x9386,
    DEVICE_9388 = 0x9388,
    DEVICE_9397 = 0x9397,
    DEVICE_939A = 0x939A,
    DEVICE_9420 = 0x9420,
    DEVICE_9430 = 0x9430,
    DEVICE_9440 = 0x9440,
    DEVICE_9460 = 0x9460,
    DEVICE_9470 = 0x9470,
    DEVICE_9520 = 0x9520,
    DEVICE_9525 = 0x9525,
    DEVICE_9540 = 0x9540,
    DEVICE_9660 = 0x9660,
    DEVICE_9680 = 0x9680,
    DEVICE_9682 = 0x9682,
    DEVICE_9683 = 0x9683,
    DEVICE_9685 = 0x9685,
    DEVICE_9750 = 0x9750,
    DEVICE_9753 = 0x9753,
    DEVICE_9754 = 0x9754,
    DEVICE_9759 = 0x9759,
    DEVICE_9783 = 0x9783,
    DEVICE_9785 = 0x9785,
    DEVICE_9850 = 0x9850,
    DEVICE_9880 = 0x9880,
    DEVICE_9910 = 0x9910,
    DEVICE_9930 = 0x9930,
    DEVICE_9960 = 0x9960
};



inline const char8* enumToString(PciDevice1023 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1023::NONE:        return "NONE";
        case PciDevice1023::DEVICE_0194: return "DEVICE_0194";
        case PciDevice1023::DEVICE_2000: return "DEVICE_2000";
        case PciDevice1023::DEVICE_2001: return "DEVICE_2001";
        case PciDevice1023::DEVICE_2100: return "DEVICE_2100";
        case PciDevice1023::DEVICE_2200: return "DEVICE_2200";
        case PciDevice1023::DEVICE_8400: return "DEVICE_8400";
        case PciDevice1023::DEVICE_8420: return "DEVICE_8420";
        case PciDevice1023::DEVICE_8500: return "DEVICE_8500";
        case PciDevice1023::DEVICE_8520: return "DEVICE_8520";
        case PciDevice1023::DEVICE_8620: return "DEVICE_8620";
        case PciDevice1023::DEVICE_8820: return "DEVICE_8820";
        case PciDevice1023::DEVICE_9320: return "DEVICE_9320";
        case PciDevice1023::DEVICE_9350: return "DEVICE_9350";
        case PciDevice1023::DEVICE_9360: return "DEVICE_9360";
        case PciDevice1023::DEVICE_9382: return "DEVICE_9382";
        case PciDevice1023::DEVICE_9383: return "DEVICE_9383";
        case PciDevice1023::DEVICE_9385: return "DEVICE_9385";
        case PciDevice1023::DEVICE_9386: return "DEVICE_9386";
        case PciDevice1023::DEVICE_9388: return "DEVICE_9388";
        case PciDevice1023::DEVICE_9397: return "DEVICE_9397";
        case PciDevice1023::DEVICE_939A: return "DEVICE_939A";
        case PciDevice1023::DEVICE_9420: return "DEVICE_9420";
        case PciDevice1023::DEVICE_9430: return "DEVICE_9430";
        case PciDevice1023::DEVICE_9440: return "DEVICE_9440";
        case PciDevice1023::DEVICE_9460: return "DEVICE_9460";
        case PciDevice1023::DEVICE_9470: return "DEVICE_9470";
        case PciDevice1023::DEVICE_9520: return "DEVICE_9520";
        case PciDevice1023::DEVICE_9525: return "DEVICE_9525";
        case PciDevice1023::DEVICE_9540: return "DEVICE_9540";
        case PciDevice1023::DEVICE_9660: return "DEVICE_9660";
        case PciDevice1023::DEVICE_9680: return "DEVICE_9680";
        case PciDevice1023::DEVICE_9682: return "DEVICE_9682";
        case PciDevice1023::DEVICE_9683: return "DEVICE_9683";
        case PciDevice1023::DEVICE_9685: return "DEVICE_9685";
        case PciDevice1023::DEVICE_9750: return "DEVICE_9750";
        case PciDevice1023::DEVICE_9753: return "DEVICE_9753";
        case PciDevice1023::DEVICE_9754: return "DEVICE_9754";
        case PciDevice1023::DEVICE_9759: return "DEVICE_9759";
        case PciDevice1023::DEVICE_9783: return "DEVICE_9783";
        case PciDevice1023::DEVICE_9785: return "DEVICE_9785";
        case PciDevice1023::DEVICE_9850: return "DEVICE_9850";
        case PciDevice1023::DEVICE_9880: return "DEVICE_9880";
        case PciDevice1023::DEVICE_9910: return "DEVICE_9910";
        case PciDevice1023::DEVICE_9930: return "DEVICE_9930";
        case PciDevice1023::DEVICE_9960: return "DEVICE_9960";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1023 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1023 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1023::DEVICE_0194: return "82C194";
        case PciDevice1023::DEVICE_2000: return "4DWave DX";
        case PciDevice1023::DEVICE_2001: return "4DWave NX";
        case PciDevice1023::DEVICE_2100: return "CyberBlade XP4m32";
        case PciDevice1023::DEVICE_2200: return "XGI Volari XP5";
        case PciDevice1023::DEVICE_8400: return "CyberBlade/i7";
        case PciDevice1023::DEVICE_8420: return "CyberBlade/i7d";
        case PciDevice1023::DEVICE_8500: return "CyberBlade/i1";
        case PciDevice1023::DEVICE_8520: return "CyberBlade i1";
        case PciDevice1023::DEVICE_8620: return "CyberBlade/i1";
        case PciDevice1023::DEVICE_8820: return "CyberBlade XPAi1";
        case PciDevice1023::DEVICE_9320: return "TGUI 9320";
        case PciDevice1023::DEVICE_9350: return "GUI Accelerator";
        case PciDevice1023::DEVICE_9360: return "Flat panel GUI Accelerator";
        case PciDevice1023::DEVICE_9382: return "Cyber 9382 [Reference design]";
        case PciDevice1023::DEVICE_9383: return "Cyber 9383 [Reference design]";
        case PciDevice1023::DEVICE_9385: return "Cyber 9385 [Reference design]";
        case PciDevice1023::DEVICE_9386: return "Cyber 9386";
        case PciDevice1023::DEVICE_9388: return "Cyber 9388";
        case PciDevice1023::DEVICE_9397: return "Cyber 9397";
        case PciDevice1023::DEVICE_939A: return "Cyber 9397DVD";
        case PciDevice1023::DEVICE_9420: return "TGUI 9420";
        case PciDevice1023::DEVICE_9430: return "TGUI 9430";
        case PciDevice1023::DEVICE_9440: return "TGUI 9440";
        case PciDevice1023::DEVICE_9460: return "TGUI 9460";
        case PciDevice1023::DEVICE_9470: return "TGUI 9470";
        case PciDevice1023::DEVICE_9520: return "Cyber 9520";
        case PciDevice1023::DEVICE_9525: return "Cyber 9525";
        case PciDevice1023::DEVICE_9540: return "Cyber 9540";
        case PciDevice1023::DEVICE_9660: return "TGUI 9660/938x/968x";
        case PciDevice1023::DEVICE_9680: return "TGUI 9680";
        case PciDevice1023::DEVICE_9682: return "TGUI 9682";
        case PciDevice1023::DEVICE_9683: return "TGUI 9683";
        case PciDevice1023::DEVICE_9685: return "ProVIDIA 9685";
        case PciDevice1023::DEVICE_9750: return "3DImage 9750";
        case PciDevice1023::DEVICE_9753: return "TGUI 9753";
        case PciDevice1023::DEVICE_9754: return "TGUI 9754";
        case PciDevice1023::DEVICE_9759: return "TGUI 975";
        case PciDevice1023::DEVICE_9783: return "TGUI 9783";
        case PciDevice1023::DEVICE_9785: return "TGUI 9785";
        case PciDevice1023::DEVICE_9850: return "3DImage 9850";
        case PciDevice1023::DEVICE_9880: return "Blade 3D PCI/AGP";
        case PciDevice1023::DEVICE_9910: return "CyberBlade/XP";
        case PciDevice1023::DEVICE_9930: return "CyberBlade/XPm";
        case PciDevice1023::DEVICE_9960: return "CyberBlade XP2";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1023 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1023::DEVICE_0194: return "Unknown device";
        case PciDevice1023::DEVICE_2000: return "Unknown device";
        case PciDevice1023::DEVICE_2001: return enumToHumanString((PciSubDevice10232001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1023::DEVICE_2100: return "Unknown device";
        case PciDevice1023::DEVICE_2200: return "Unknown device";
        case PciDevice1023::DEVICE_8400: return enumToHumanString((PciSubDevice10238400)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1023::DEVICE_8420: return enumToHumanString((PciSubDevice10238420)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1023::DEVICE_8500: return "Unknown device";
        case PciDevice1023::DEVICE_8520: return enumToHumanString((PciSubDevice10238520)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1023::DEVICE_8620: return enumToHumanString((PciSubDevice10238620)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1023::DEVICE_8820: return "Unknown device";
        case PciDevice1023::DEVICE_9320: return "Unknown device";
        case PciDevice1023::DEVICE_9350: return "Unknown device";
        case PciDevice1023::DEVICE_9360: return "Unknown device";
        case PciDevice1023::DEVICE_9382: return "Unknown device";
        case PciDevice1023::DEVICE_9383: return "Unknown device";
        case PciDevice1023::DEVICE_9385: return "Unknown device";
        case PciDevice1023::DEVICE_9386: return "Unknown device";
        case PciDevice1023::DEVICE_9388: return "Unknown device";
        case PciDevice1023::DEVICE_9397: return "Unknown device";
        case PciDevice1023::DEVICE_939A: return "Unknown device";
        case PciDevice1023::DEVICE_9420: return "Unknown device";
        case PciDevice1023::DEVICE_9430: return "Unknown device";
        case PciDevice1023::DEVICE_9440: return "Unknown device";
        case PciDevice1023::DEVICE_9460: return "Unknown device";
        case PciDevice1023::DEVICE_9470: return "Unknown device";
        case PciDevice1023::DEVICE_9520: return "Unknown device";
        case PciDevice1023::DEVICE_9525: return "Unknown device";
        case PciDevice1023::DEVICE_9540: return "Unknown device";
        case PciDevice1023::DEVICE_9660: return "Unknown device";
        case PciDevice1023::DEVICE_9680: return "Unknown device";
        case PciDevice1023::DEVICE_9682: return "Unknown device";
        case PciDevice1023::DEVICE_9683: return "Unknown device";
        case PciDevice1023::DEVICE_9685: return "Unknown device";
        case PciDevice1023::DEVICE_9750: return enumToHumanString((PciSubDevice10239750)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1023::DEVICE_9753: return "Unknown device";
        case PciDevice1023::DEVICE_9754: return "Unknown device";
        case PciDevice1023::DEVICE_9759: return "Unknown device";
        case PciDevice1023::DEVICE_9783: return "Unknown device";
        case PciDevice1023::DEVICE_9785: return "Unknown device";
        case PciDevice1023::DEVICE_9850: return "Unknown device";
        case PciDevice1023::DEVICE_9880: return enumToHumanString((PciSubDevice10239880)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1023::DEVICE_9910: return "Unknown device";
        case PciDevice1023::DEVICE_9930: return "Unknown device";
        case PciDevice1023::DEVICE_9960: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCIDEVICE1023_H
