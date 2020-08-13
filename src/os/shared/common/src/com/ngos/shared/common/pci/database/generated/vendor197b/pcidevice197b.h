// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCIDEVICE197B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCIDEVICE197B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice197B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0250 = 0x0250,
    DEVICE_0260 = 0x0260,
    DEVICE_0368 = 0x0368,
    DEVICE_2360 = 0x2360,
    DEVICE_2361 = 0x2361,
    DEVICE_2362 = 0x2362,
    DEVICE_2363 = 0x2363,
    DEVICE_2364 = 0x2364,
    DEVICE_2365 = 0x2365,
    DEVICE_2366 = 0x2366,
    DEVICE_2368 = 0x2368,
    DEVICE_2369 = 0x2369,
    DEVICE_2380 = 0x2380,
    DEVICE_2381 = 0x2381,
    DEVICE_2382 = 0x2382,
    DEVICE_2383 = 0x2383,
    DEVICE_2384 = 0x2384,
    DEVICE_2386 = 0x2386,
    DEVICE_2387 = 0x2387,
    DEVICE_2388 = 0x2388,
    DEVICE_2389 = 0x2389,
    DEVICE_2391 = 0x2391,
    DEVICE_2392 = 0x2392,
    DEVICE_2393 = 0x2393,
    DEVICE_2394 = 0x2394
};



inline const char8* enumToString(PciDevice197B device197B) // TEST: NO
{
    // COMMON_LT((" | device197B = %u", device197B)); // Commented to avoid bad looking logs



    switch (device197B)
    {
        case PciDevice197B::NONE:        return "NONE";
        case PciDevice197B::DEVICE_0250: return "DEVICE_0250";
        case PciDevice197B::DEVICE_0260: return "DEVICE_0260";
        case PciDevice197B::DEVICE_0368: return "DEVICE_0368";
        case PciDevice197B::DEVICE_2360: return "DEVICE_2360";
        case PciDevice197B::DEVICE_2361: return "DEVICE_2361";
        case PciDevice197B::DEVICE_2362: return "DEVICE_2362";
        case PciDevice197B::DEVICE_2363: return "DEVICE_2363";
        case PciDevice197B::DEVICE_2364: return "DEVICE_2364";
        case PciDevice197B::DEVICE_2365: return "DEVICE_2365";
        case PciDevice197B::DEVICE_2366: return "DEVICE_2366";
        case PciDevice197B::DEVICE_2368: return "DEVICE_2368";
        case PciDevice197B::DEVICE_2369: return "DEVICE_2369";
        case PciDevice197B::DEVICE_2380: return "DEVICE_2380";
        case PciDevice197B::DEVICE_2381: return "DEVICE_2381";
        case PciDevice197B::DEVICE_2382: return "DEVICE_2382";
        case PciDevice197B::DEVICE_2383: return "DEVICE_2383";
        case PciDevice197B::DEVICE_2384: return "DEVICE_2384";
        case PciDevice197B::DEVICE_2386: return "DEVICE_2386";
        case PciDevice197B::DEVICE_2387: return "DEVICE_2387";
        case PciDevice197B::DEVICE_2388: return "DEVICE_2388";
        case PciDevice197B::DEVICE_2389: return "DEVICE_2389";
        case PciDevice197B::DEVICE_2391: return "DEVICE_2391";
        case PciDevice197B::DEVICE_2392: return "DEVICE_2392";
        case PciDevice197B::DEVICE_2393: return "DEVICE_2393";
        case PciDevice197B::DEVICE_2394: return "DEVICE_2394";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice197B device197B) // TEST: NO
{
    // COMMON_LT((" | device197B = %u", device197B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device197B, enumToString(device197B));

    return res;
}



inline const char8* enumToHumanString(PciDevice197B device197B) // TEST: NO
{
    // COMMON_LT((" | device197B = %u", device197B)); // Commented to avoid bad looking logs



    switch (device197B)
    {
        case PciDevice197B::DEVICE_0250: return "JMC250 PCI Express Gigabit Ethernet Controller";
        case PciDevice197B::DEVICE_0260: return "JMC260 PCI Express Fast Ethernet Controller";
        case PciDevice197B::DEVICE_0368: return "JMB368 IDE controller";
        case PciDevice197B::DEVICE_2360: return "JMB360 AHCI Controller";
        case PciDevice197B::DEVICE_2361: return "JMB361 AHCI/IDE";
        case PciDevice197B::DEVICE_2362: return "JMB362 SATA Controller";
        case PciDevice197B::DEVICE_2363: return "JMB363 SATA/IDE Controller";
        case PciDevice197B::DEVICE_2364: return "JMB364 AHCI Controller";
        case PciDevice197B::DEVICE_2365: return "JMB365 AHCI/IDE";
        case PciDevice197B::DEVICE_2366: return "JMB366 AHCI/IDE";
        case PciDevice197B::DEVICE_2368: return "JMB368 IDE controller";
        case PciDevice197B::DEVICE_2369: return "JMB369 Serial ATA Controller";
        case PciDevice197B::DEVICE_2380: return "IEEE 1394 Host Controller";
        case PciDevice197B::DEVICE_2381: return "Standard SD Host Controller";
        case PciDevice197B::DEVICE_2382: return "SD/MMC Host Controller";
        case PciDevice197B::DEVICE_2383: return "MS Host Controller";
        case PciDevice197B::DEVICE_2384: return "xD Host Controller";
        case PciDevice197B::DEVICE_2386: return "Standard SD Host Controller";
        case PciDevice197B::DEVICE_2387: return "SD/MMC Host Controller";
        case PciDevice197B::DEVICE_2388: return "MS Host Controller";
        case PciDevice197B::DEVICE_2389: return "xD Host Controller";
        case PciDevice197B::DEVICE_2391: return "Standard SD Host Controller";
        case PciDevice197B::DEVICE_2392: return "SD/MMC Host Controller";
        case PciDevice197B::DEVICE_2393: return "MS Host Controller";
        case PciDevice197B::DEVICE_2394: return "xD Host Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCIDEVICE197B_H
