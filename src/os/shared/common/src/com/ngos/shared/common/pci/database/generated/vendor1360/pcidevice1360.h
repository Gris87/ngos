// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1360_PCIDEVICE1360_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1360_PCIDEVICE1360_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1360: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0103 = 0x0103,
    DEVICE_0104 = 0x0104,
    DEVICE_0105 = 0x0105,
    DEVICE_0106 = 0x0106,
    DEVICE_0201 = 0x0201,
    DEVICE_0202 = 0x0202,
    DEVICE_0203 = 0x0203,
    DEVICE_0204 = 0x0204,
    DEVICE_0205 = 0x0205,
    DEVICE_0206 = 0x0206,
    DEVICE_0207 = 0x0207,
    DEVICE_0208 = 0x0208,
    DEVICE_0209 = 0x0209,
    DEVICE_0301 = 0x0301,
    DEVICE_0302 = 0x0302,
    DEVICE_0303 = 0x0303,
    DEVICE_0304 = 0x0304,
    DEVICE_0305 = 0x0305,
    DEVICE_0306 = 0x0306,
    DEVICE_0501 = 0x0501,
    DEVICE_0601 = 0x0601
};



inline const char8* enumToString(PciDevice1360 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1360::NONE:        return "NONE";
        case PciDevice1360::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1360::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1360::DEVICE_0103: return "DEVICE_0103";
        case PciDevice1360::DEVICE_0104: return "DEVICE_0104";
        case PciDevice1360::DEVICE_0105: return "DEVICE_0105";
        case PciDevice1360::DEVICE_0106: return "DEVICE_0106";
        case PciDevice1360::DEVICE_0201: return "DEVICE_0201";
        case PciDevice1360::DEVICE_0202: return "DEVICE_0202";
        case PciDevice1360::DEVICE_0203: return "DEVICE_0203";
        case PciDevice1360::DEVICE_0204: return "DEVICE_0204";
        case PciDevice1360::DEVICE_0205: return "DEVICE_0205";
        case PciDevice1360::DEVICE_0206: return "DEVICE_0206";
        case PciDevice1360::DEVICE_0207: return "DEVICE_0207";
        case PciDevice1360::DEVICE_0208: return "DEVICE_0208";
        case PciDevice1360::DEVICE_0209: return "DEVICE_0209";
        case PciDevice1360::DEVICE_0301: return "DEVICE_0301";
        case PciDevice1360::DEVICE_0302: return "DEVICE_0302";
        case PciDevice1360::DEVICE_0303: return "DEVICE_0303";
        case PciDevice1360::DEVICE_0304: return "DEVICE_0304";
        case PciDevice1360::DEVICE_0305: return "DEVICE_0305";
        case PciDevice1360::DEVICE_0306: return "DEVICE_0306";
        case PciDevice1360::DEVICE_0501: return "DEVICE_0501";
        case PciDevice1360::DEVICE_0601: return "DEVICE_0601";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1360 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1360 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1360::DEVICE_0101: return "PCi32 DCF77 Radio Clock";
        case PciDevice1360::DEVICE_0102: return "PCI509 DCF77 Radio Clock";
        case PciDevice1360::DEVICE_0103: return "PCI510 DCF77 Radio Clock";
        case PciDevice1360::DEVICE_0104: return "PCI511 DCF77 Radio Clock";
        case PciDevice1360::DEVICE_0105: return "PEX511 DCF77 Radio Clock (PCI Express)";
        case PciDevice1360::DEVICE_0106: return "PZF180PEX High Precision DCF77 Radio Clock (PCI Express)";
        case PciDevice1360::DEVICE_0201: return "GPS167PCI GPS Receiver";
        case PciDevice1360::DEVICE_0202: return "GPS168PCI GPS Receiver";
        case PciDevice1360::DEVICE_0203: return "GPS169PCI GPS Receiver";
        case PciDevice1360::DEVICE_0204: return "GPS170PCI GPS Receiver";
        case PciDevice1360::DEVICE_0205: return "GPS170PEX GPS Receiver (PCI Express)";
        case PciDevice1360::DEVICE_0206: return "GPS180PEX GPS Receiver (PCI Express)";
        case PciDevice1360::DEVICE_0207: return "GLN180PEX GPS/GLONASS receiver (PCI Express)";
        case PciDevice1360::DEVICE_0208: return "GPS180AMC GPS Receiver (PCI Express / MicroTCA / AdvancedMC)";
        case PciDevice1360::DEVICE_0209: return "GNS181PEX GPS/Galileo/GLONASS/BEIDOU receiver (PCI Express)";
        case PciDevice1360::DEVICE_0301: return "TCR510PCI IRIG Timecode Reader";
        case PciDevice1360::DEVICE_0302: return "TCR167PCI IRIG Timecode Reader";
        case PciDevice1360::DEVICE_0303: return "TCR511PCI IRIG Timecode Reader";
        case PciDevice1360::DEVICE_0304: return "TCR511PEX IRIG Timecode Reader (PCI Express)";
        case PciDevice1360::DEVICE_0305: return "TCR170PEX IRIG Timecode Reader (PCI Express)";
        case PciDevice1360::DEVICE_0306: return "TCR180PEX IRIG Timecode Reader (PCI Express)";
        case PciDevice1360::DEVICE_0501: return "PTP270PEX PTP/IEEE1588 slave card (PCI Express)";
        case PciDevice1360::DEVICE_0601: return "FRC511PEX Free Running Clock (PCI Express)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1360_PCIDEVICE1360_H
