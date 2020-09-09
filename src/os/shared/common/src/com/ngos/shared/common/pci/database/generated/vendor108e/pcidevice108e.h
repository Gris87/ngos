// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCIDEVICE108E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCIDEVICE108E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108e/pcisubdevice108e1100.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108e/pcisubdevice108e1101.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108e/pcisubdevice108e1102.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108e/pcisubdevice108e1103.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108e/pcisubdevice108e5000.h>
#include <com/ngos/shared/common/pci/database/generated/vendor108e/pcisubdevice108ea001.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice108E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_1100 = 0x1100,
    DEVICE_1101 = 0x1101,
    DEVICE_1102 = 0x1102,
    DEVICE_1103 = 0x1103,
    DEVICE_1647 = 0x1647,
    DEVICE_1648 = 0x1648,
    DEVICE_16A7 = 0x16A7,
    DEVICE_16A8 = 0x16A8,
    DEVICE_2BAD = 0x2BAD,
    DEVICE_5000 = 0x5000,
    DEVICE_5043 = 0x5043,
    DEVICE_5CA0 = 0x5CA0,
    DEVICE_6300 = 0x6300,
    DEVICE_6301 = 0x6301,
    DEVICE_6302 = 0x6302,
    DEVICE_6303 = 0x6303,
    DEVICE_6310 = 0x6310,
    DEVICE_6311 = 0x6311,
    DEVICE_6312 = 0x6312,
    DEVICE_6313 = 0x6313,
    DEVICE_6320 = 0x6320,
    DEVICE_6323 = 0x6323,
    DEVICE_6330 = 0x6330,
    DEVICE_6331 = 0x6331,
    DEVICE_6332 = 0x6332,
    DEVICE_6333 = 0x6333,
    DEVICE_6340 = 0x6340,
    DEVICE_6343 = 0x6343,
    DEVICE_6350 = 0x6350,
    DEVICE_6353 = 0x6353,
    DEVICE_6722 = 0x6722,
    DEVICE_676E = 0x676E,
    DEVICE_7063 = 0x7063,
    DEVICE_8000 = 0x8000,
    DEVICE_8001 = 0x8001,
    DEVICE_8002 = 0x8002,
    DEVICE_80F0 = 0x80F0,
    DEVICE_80F8 = 0x80F8,
    DEVICE_9010 = 0x9010,
    DEVICE_9020 = 0x9020,
    DEVICE_9102 = 0x9102,
    DEVICE_A000 = 0xA000,
    DEVICE_A001 = 0xA001,
    DEVICE_A801 = 0xA801,
    DEVICE_AAAA = 0xAAAA,
    DEVICE_ABBA = 0xABBA,
    DEVICE_ABCD = 0xABCD,
    DEVICE_C416 = 0xC416
};



inline const char8* enumToString(PciDevice108E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice108E::NONE:        return "NONE";
        case PciDevice108E::DEVICE_0001: return "DEVICE_0001";
        case PciDevice108E::DEVICE_1000: return "DEVICE_1000";
        case PciDevice108E::DEVICE_1001: return "DEVICE_1001";
        case PciDevice108E::DEVICE_1100: return "DEVICE_1100";
        case PciDevice108E::DEVICE_1101: return "DEVICE_1101";
        case PciDevice108E::DEVICE_1102: return "DEVICE_1102";
        case PciDevice108E::DEVICE_1103: return "DEVICE_1103";
        case PciDevice108E::DEVICE_1647: return "DEVICE_1647";
        case PciDevice108E::DEVICE_1648: return "DEVICE_1648";
        case PciDevice108E::DEVICE_16A7: return "DEVICE_16A7";
        case PciDevice108E::DEVICE_16A8: return "DEVICE_16A8";
        case PciDevice108E::DEVICE_2BAD: return "DEVICE_2BAD";
        case PciDevice108E::DEVICE_5000: return "DEVICE_5000";
        case PciDevice108E::DEVICE_5043: return "DEVICE_5043";
        case PciDevice108E::DEVICE_5CA0: return "DEVICE_5CA0";
        case PciDevice108E::DEVICE_6300: return "DEVICE_6300";
        case PciDevice108E::DEVICE_6301: return "DEVICE_6301";
        case PciDevice108E::DEVICE_6302: return "DEVICE_6302";
        case PciDevice108E::DEVICE_6303: return "DEVICE_6303";
        case PciDevice108E::DEVICE_6310: return "DEVICE_6310";
        case PciDevice108E::DEVICE_6311: return "DEVICE_6311";
        case PciDevice108E::DEVICE_6312: return "DEVICE_6312";
        case PciDevice108E::DEVICE_6313: return "DEVICE_6313";
        case PciDevice108E::DEVICE_6320: return "DEVICE_6320";
        case PciDevice108E::DEVICE_6323: return "DEVICE_6323";
        case PciDevice108E::DEVICE_6330: return "DEVICE_6330";
        case PciDevice108E::DEVICE_6331: return "DEVICE_6331";
        case PciDevice108E::DEVICE_6332: return "DEVICE_6332";
        case PciDevice108E::DEVICE_6333: return "DEVICE_6333";
        case PciDevice108E::DEVICE_6340: return "DEVICE_6340";
        case PciDevice108E::DEVICE_6343: return "DEVICE_6343";
        case PciDevice108E::DEVICE_6350: return "DEVICE_6350";
        case PciDevice108E::DEVICE_6353: return "DEVICE_6353";
        case PciDevice108E::DEVICE_6722: return "DEVICE_6722";
        case PciDevice108E::DEVICE_676E: return "DEVICE_676E";
        case PciDevice108E::DEVICE_7063: return "DEVICE_7063";
        case PciDevice108E::DEVICE_8000: return "DEVICE_8000";
        case PciDevice108E::DEVICE_8001: return "DEVICE_8001";
        case PciDevice108E::DEVICE_8002: return "DEVICE_8002";
        case PciDevice108E::DEVICE_80F0: return "DEVICE_80F0";
        case PciDevice108E::DEVICE_80F8: return "DEVICE_80F8";
        case PciDevice108E::DEVICE_9010: return "DEVICE_9010";
        case PciDevice108E::DEVICE_9020: return "DEVICE_9020";
        case PciDevice108E::DEVICE_9102: return "DEVICE_9102";
        case PciDevice108E::DEVICE_A000: return "DEVICE_A000";
        case PciDevice108E::DEVICE_A001: return "DEVICE_A001";
        case PciDevice108E::DEVICE_A801: return "DEVICE_A801";
        case PciDevice108E::DEVICE_AAAA: return "DEVICE_AAAA";
        case PciDevice108E::DEVICE_ABBA: return "DEVICE_ABBA";
        case PciDevice108E::DEVICE_ABCD: return "DEVICE_ABCD";
        case PciDevice108E::DEVICE_C416: return "DEVICE_C416";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice108E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice108E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice108E::DEVICE_0001: return "EBUS";
        case PciDevice108E::DEVICE_1000: return "EBUS";
        case PciDevice108E::DEVICE_1001: return "Happy Meal 10/100 Ethernet [hme]";
        case PciDevice108E::DEVICE_1100: return "RIO EBUS";
        case PciDevice108E::DEVICE_1101: return "RIO 10/100 Ethernet [eri]";
        case PciDevice108E::DEVICE_1102: return "RIO 1394";
        case PciDevice108E::DEVICE_1103: return "RIO USB";
        case PciDevice108E::DEVICE_1647: return "Broadcom 570x 10/100/1000 Ethernet [bge]";
        case PciDevice108E::DEVICE_1648: return "Broadcom 570x 10/100/1000 Ethernet [bge]";
        case PciDevice108E::DEVICE_16A7: return "Broadcom 570x 10/100/1000 Ethernet [bge]";
        case PciDevice108E::DEVICE_16A8: return "Broadcom 570x 10/100/1000 Ethernet [bge]";
        case PciDevice108E::DEVICE_2BAD: return "GEM 10/100/1000 Ethernet [ge]";
        case PciDevice108E::DEVICE_5000: return "Simba Advanced PCI Bridge";
        case PciDevice108E::DEVICE_5043: return "SunPCI Co-processor";
        case PciDevice108E::DEVICE_5CA0: return "Crypto Accelerator 6000 [mca]";
        case PciDevice108E::DEVICE_6300: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6301: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6302: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6303: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6310: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6311: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6312: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6313: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6320: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6323: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6330: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6331: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6332: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6333: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6340: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6343: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6350: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6353: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_6722: return "Intel 21554 PCI-PCI bus bridge [db21554]";
        case PciDevice108E::DEVICE_676E: return "SunPCiIII";
        case PciDevice108E::DEVICE_7063: return "SunPCiII / SunPCiIIpro";
        case PciDevice108E::DEVICE_8000: return "Psycho PCI Bus Module";
        case PciDevice108E::DEVICE_8001: return "Schizo PCI Bus Module";
        case PciDevice108E::DEVICE_8002: return "Schizo+ PCI Bus Module";
        case PciDevice108E::DEVICE_80F0: return "PCIe switch [px]";
        case PciDevice108E::DEVICE_80F8: return "PCIe switch [px]";
        case PciDevice108E::DEVICE_9010: return "PCIe/PCI bridge switch [pxb_plx]";
        case PciDevice108E::DEVICE_9020: return "PCIe/PCI bridge switch [pxb_plx]";
        case PciDevice108E::DEVICE_9102: return "Davicom Fast Ethernet driver for Davicom DM9102A [dmfe]";
        case PciDevice108E::DEVICE_A000: return "Psycho UPA-PCI Bus Module [pcipsy]";
        case PciDevice108E::DEVICE_A001: return "Psycho UPA-PCI Bus Module [pcipsy]";
        case PciDevice108E::DEVICE_A801: return "Schizo Fireplane-PCI bus bridge module [pcisch]";
        case PciDevice108E::DEVICE_AAAA: return "Multithreaded Shared 10GbE Ethernet Network Controller";
        case PciDevice108E::DEVICE_ABBA: return "Cassini 10/100/1000";
        case PciDevice108E::DEVICE_ABCD: return "Multithreaded 10-Gigabit Ethernet Network Controller";
        case PciDevice108E::DEVICE_C416: return "Sun Fire System/System Controller Interface chip [sbbc]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice108E device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice108E::DEVICE_0001: return "Unknown device";
        case PciDevice108E::DEVICE_1000: return "Unknown device";
        case PciDevice108E::DEVICE_1001: return "Unknown device";
        case PciDevice108E::DEVICE_1100: return enumToHumanString((PciSubDevice108E1100)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice108E::DEVICE_1101: return enumToHumanString((PciSubDevice108E1101)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice108E::DEVICE_1102: return enumToHumanString((PciSubDevice108E1102)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice108E::DEVICE_1103: return enumToHumanString((PciSubDevice108E1103)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice108E::DEVICE_1647: return "Unknown device";
        case PciDevice108E::DEVICE_1648: return "Unknown device";
        case PciDevice108E::DEVICE_16A7: return "Unknown device";
        case PciDevice108E::DEVICE_16A8: return "Unknown device";
        case PciDevice108E::DEVICE_2BAD: return "Unknown device";
        case PciDevice108E::DEVICE_5000: return enumToHumanString((PciSubDevice108E5000)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice108E::DEVICE_5043: return "Unknown device";
        case PciDevice108E::DEVICE_5CA0: return "Unknown device";
        case PciDevice108E::DEVICE_6300: return "Unknown device";
        case PciDevice108E::DEVICE_6301: return "Unknown device";
        case PciDevice108E::DEVICE_6302: return "Unknown device";
        case PciDevice108E::DEVICE_6303: return "Unknown device";
        case PciDevice108E::DEVICE_6310: return "Unknown device";
        case PciDevice108E::DEVICE_6311: return "Unknown device";
        case PciDevice108E::DEVICE_6312: return "Unknown device";
        case PciDevice108E::DEVICE_6313: return "Unknown device";
        case PciDevice108E::DEVICE_6320: return "Unknown device";
        case PciDevice108E::DEVICE_6323: return "Unknown device";
        case PciDevice108E::DEVICE_6330: return "Unknown device";
        case PciDevice108E::DEVICE_6331: return "Unknown device";
        case PciDevice108E::DEVICE_6332: return "Unknown device";
        case PciDevice108E::DEVICE_6333: return "Unknown device";
        case PciDevice108E::DEVICE_6340: return "Unknown device";
        case PciDevice108E::DEVICE_6343: return "Unknown device";
        case PciDevice108E::DEVICE_6350: return "Unknown device";
        case PciDevice108E::DEVICE_6353: return "Unknown device";
        case PciDevice108E::DEVICE_6722: return "Unknown device";
        case PciDevice108E::DEVICE_676E: return "Unknown device";
        case PciDevice108E::DEVICE_7063: return "Unknown device";
        case PciDevice108E::DEVICE_8000: return "Unknown device";
        case PciDevice108E::DEVICE_8001: return "Unknown device";
        case PciDevice108E::DEVICE_8002: return "Unknown device";
        case PciDevice108E::DEVICE_80F0: return "Unknown device";
        case PciDevice108E::DEVICE_80F8: return "Unknown device";
        case PciDevice108E::DEVICE_9010: return "Unknown device";
        case PciDevice108E::DEVICE_9020: return "Unknown device";
        case PciDevice108E::DEVICE_9102: return "Unknown device";
        case PciDevice108E::DEVICE_A000: return "Unknown device";
        case PciDevice108E::DEVICE_A001: return enumToHumanString((PciSubDevice108EA001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice108E::DEVICE_A801: return "Unknown device";
        case PciDevice108E::DEVICE_AAAA: return "Unknown device";
        case PciDevice108E::DEVICE_ABBA: return "Unknown device";
        case PciDevice108E::DEVICE_ABCD: return "Unknown device";
        case PciDevice108E::DEVICE_C416: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108E_PCIDEVICE108E_H
