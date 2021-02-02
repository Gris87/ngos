// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240803_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240803_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19240803: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140478 = 0x10140478,
    SUBDEVICE_10140479 = 0x10140479,
    SUBDEVICE_101404A7 = 0x101404A7,
    SUBDEVICE_101404A8 = 0x101404A8,
    SUBDEVICE_103C2132 = 0x103C2132,
    SUBDEVICE_103C2136 = 0x103C2136,
    SUBDEVICE_19241201 = 0x19241201,
    SUBDEVICE_19246200 = 0x19246200,
    SUBDEVICE_19246201 = 0x19246201,
    SUBDEVICE_19246202 = 0x19246202,
    SUBDEVICE_19246204 = 0x19246204,
    SUBDEVICE_19246205 = 0x19246205,
    SUBDEVICE_19246206 = 0x19246206,
    SUBDEVICE_19246207 = 0x19246207,
    SUBDEVICE_19246210 = 0x19246210,
    SUBDEVICE_19246211 = 0x19246211,
    SUBDEVICE_19246217 = 0x19246217,
    SUBDEVICE_19246227 = 0x19246227,
    SUBDEVICE_19246237 = 0x19246237,
    SUBDEVICE_19246501 = 0x19246501,
    SUBDEVICE_19246511 = 0x19246511,
    SUBDEVICE_19246521 = 0x19246521,
    SUBDEVICE_19246562 = 0x19246562,
    SUBDEVICE_19246A05 = 0x19246A05,
    SUBDEVICE_19246A06 = 0x19246A06,
    SUBDEVICE_19247206 = 0x19247206,
    SUBDEVICE_19247207 = 0x19247207,
    SUBDEVICE_19247A06 = 0x19247A06,
    SUBDEVICE_19247A07 = 0x19247A07
};



inline const char8* enumToString(PciSubDevice19240803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240803::NONE:               return "NONE";
        case PciSubDevice19240803::SUBDEVICE_10140478: return "SUBDEVICE_10140478";
        case PciSubDevice19240803::SUBDEVICE_10140479: return "SUBDEVICE_10140479";
        case PciSubDevice19240803::SUBDEVICE_101404A7: return "SUBDEVICE_101404A7";
        case PciSubDevice19240803::SUBDEVICE_101404A8: return "SUBDEVICE_101404A8";
        case PciSubDevice19240803::SUBDEVICE_103C2132: return "SUBDEVICE_103C2132";
        case PciSubDevice19240803::SUBDEVICE_103C2136: return "SUBDEVICE_103C2136";
        case PciSubDevice19240803::SUBDEVICE_19241201: return "SUBDEVICE_19241201";
        case PciSubDevice19240803::SUBDEVICE_19246200: return "SUBDEVICE_19246200";
        case PciSubDevice19240803::SUBDEVICE_19246201: return "SUBDEVICE_19246201";
        case PciSubDevice19240803::SUBDEVICE_19246202: return "SUBDEVICE_19246202";
        case PciSubDevice19240803::SUBDEVICE_19246204: return "SUBDEVICE_19246204";
        case PciSubDevice19240803::SUBDEVICE_19246205: return "SUBDEVICE_19246205";
        case PciSubDevice19240803::SUBDEVICE_19246206: return "SUBDEVICE_19246206";
        case PciSubDevice19240803::SUBDEVICE_19246207: return "SUBDEVICE_19246207";
        case PciSubDevice19240803::SUBDEVICE_19246210: return "SUBDEVICE_19246210";
        case PciSubDevice19240803::SUBDEVICE_19246211: return "SUBDEVICE_19246211";
        case PciSubDevice19240803::SUBDEVICE_19246217: return "SUBDEVICE_19246217";
        case PciSubDevice19240803::SUBDEVICE_19246227: return "SUBDEVICE_19246227";
        case PciSubDevice19240803::SUBDEVICE_19246237: return "SUBDEVICE_19246237";
        case PciSubDevice19240803::SUBDEVICE_19246501: return "SUBDEVICE_19246501";
        case PciSubDevice19240803::SUBDEVICE_19246511: return "SUBDEVICE_19246511";
        case PciSubDevice19240803::SUBDEVICE_19246521: return "SUBDEVICE_19246521";
        case PciSubDevice19240803::SUBDEVICE_19246562: return "SUBDEVICE_19246562";
        case PciSubDevice19240803::SUBDEVICE_19246A05: return "SUBDEVICE_19246A05";
        case PciSubDevice19240803::SUBDEVICE_19246A06: return "SUBDEVICE_19246A06";
        case PciSubDevice19240803::SUBDEVICE_19247206: return "SUBDEVICE_19247206";
        case PciSubDevice19240803::SUBDEVICE_19247207: return "SUBDEVICE_19247207";
        case PciSubDevice19240803::SUBDEVICE_19247A06: return "SUBDEVICE_19247A06";
        case PciSubDevice19240803::SUBDEVICE_19247A07: return "SUBDEVICE_19247A07";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19240803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19240803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240803::SUBDEVICE_10140478: return "2-port 10GbE Low-Latency (R7)";
        case PciSubDevice19240803::SUBDEVICE_10140479: return "2-port 10GbE OpenOnload (R7)";
        case PciSubDevice19240803::SUBDEVICE_101404A7: return "Solarflare 10Gb Low-latency Dual-port HBA (R7)";
        case PciSubDevice19240803::SUBDEVICE_101404A8: return "Solarflare 10Gb Dual-port HBA (R7)";
        case PciSubDevice19240803::SUBDEVICE_103C2132: return "Ethernet 10Gb 2-port 570FLR-SFP+ Adapter (R1)";
        case PciSubDevice19240803::SUBDEVICE_103C2136: return "Ethernet 10Gb 2-port 570SFP+ Adapter (R7)";
        case PciSubDevice19240803::SUBDEVICE_19241201: return "SFA6902F-R1 SFP+ AOE Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246200: return "SFN5122F-R0 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246201: return "SFN5122F-R1 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246202: return "SFN5122F-R2 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246204: return "SFN5122F-R4 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246205: return "SFN5122F-R5 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246206: return "SFN5122F-R6 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246207: return "SFN5122F-R7 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246210: return "SFN5322F-R0 SFP+ Precision Time Synchronization Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246211: return "SFN5322F-R1 SFP+ Precision Time Synchronization Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246217: return "SFN5322F-R7 SFP+ Precision Time Synchronization Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246227: return "SFN6122F-R7 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246237: return "SFN6322F-R7 SFP+ Precision Time Synchronization Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246501: return "SFN5802K-R1 Mezzanine Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246511: return "SFN5814H-R1 Mezzanine Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246521: return "SFN5812H-R1 Mezzanine Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246562: return "SFN6832F-R2 SFP+ Mezzanine Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246A05: return "SFN5112F-R5 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19246A06: return "SFN5112F-R6 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19247206: return "SFN5162F-R6 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19247207: return "SFN5162F-R7 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19247A06: return "SFN5152F-R6 SFP+ Server Adapter";
        case PciSubDevice19240803::SUBDEVICE_19247A07: return "SFN5152F-R7 SFP+ Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240803_H
