// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREACE_PCIDEVICEEACE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREACE_PCIDEVICEEACE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceEACE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3100 = 0x3100,
    DEVICE_3200 = 0x3200,
    DEVICE_320E = 0x320E,
    DEVICE_340E = 0x340E,
    DEVICE_341E = 0x341E,
    DEVICE_3500 = 0x3500,
    DEVICE_351C = 0x351C,
    DEVICE_360D = 0x360D,
    DEVICE_360E = 0x360E,
    DEVICE_368E = 0x368E,
    DEVICE_3707 = 0x3707,
    DEVICE_370D = 0x370D,
    DEVICE_378E = 0x378E,
    DEVICE_3800 = 0x3800,
    DEVICE_4100 = 0x4100,
    DEVICE_4110 = 0x4110,
    DEVICE_4220 = 0x4220,
    DEVICE_422E = 0x422E,
    DEVICE_4230 = 0x4230,
    DEVICE_423E = 0x423E,
    DEVICE_4300 = 0x4300,
    DEVICE_430E = 0x430E,
    DEVICE_452E = 0x452E,
    DEVICE_454E = 0x454E,
    DEVICE_45B8 = 0x45B8,
    DEVICE_45BE = 0x45BE,
    DEVICE_520E = 0x520E,
    DEVICE_521A = 0x521A,
    DEVICE_5400 = 0x5400,
    DEVICE_5401 = 0x5401,
    DEVICE_540A = 0x540A,
    DEVICE_541A = 0x541A,
    DEVICE_542A = 0x542A,
    DEVICE_6000 = 0x6000,
    DEVICE_6100 = 0x6100,
    DEVICE_6200 = 0x6200,
    DEVICE_7100 = 0x7100,
    DEVICE_7400 = 0x7400,
    DEVICE_7401 = 0x7401,
    DEVICE_752E = 0x752E,
    DEVICE_754E = 0x754E,
    DEVICE_8100 = 0x8100,
    DEVICE_8101 = 0x8101,
    DEVICE_8102 = 0x8102,
    DEVICE_820E = 0x820E,
    DEVICE_820F = 0x820F,
    DEVICE_8400 = 0x8400,
    DEVICE_8500 = 0x8500,
    DEVICE_9200 = 0x9200,
    DEVICE_920E = 0x920E,
    DEVICE_9540 = 0x9540,
    DEVICE_954F = 0x954F,
    DEVICE_A120 = 0xA120,
    DEVICE_A12E = 0xA12E,
    DEVICE_A140 = 0xA140,
    DEVICE_A14E = 0xA14E,
    DEVICE_EACE = 0xEACE
};



inline const char8* enumToString(PciDeviceEACE deviceEACE) // TEST: NO
{
    // COMMON_LT((" | deviceEACE = %u", deviceEACE)); // Commented to avoid bad looking logs



    switch (deviceEACE)
    {
        case PciDeviceEACE::NONE:        return "NONE";
        case PciDeviceEACE::DEVICE_3100: return "DEVICE_3100";
        case PciDeviceEACE::DEVICE_3200: return "DEVICE_3200";
        case PciDeviceEACE::DEVICE_320E: return "DEVICE_320E";
        case PciDeviceEACE::DEVICE_340E: return "DEVICE_340E";
        case PciDeviceEACE::DEVICE_341E: return "DEVICE_341E";
        case PciDeviceEACE::DEVICE_3500: return "DEVICE_3500";
        case PciDeviceEACE::DEVICE_351C: return "DEVICE_351C";
        case PciDeviceEACE::DEVICE_360D: return "DEVICE_360D";
        case PciDeviceEACE::DEVICE_360E: return "DEVICE_360E";
        case PciDeviceEACE::DEVICE_368E: return "DEVICE_368E";
        case PciDeviceEACE::DEVICE_3707: return "DEVICE_3707";
        case PciDeviceEACE::DEVICE_370D: return "DEVICE_370D";
        case PciDeviceEACE::DEVICE_378E: return "DEVICE_378E";
        case PciDeviceEACE::DEVICE_3800: return "DEVICE_3800";
        case PciDeviceEACE::DEVICE_4100: return "DEVICE_4100";
        case PciDeviceEACE::DEVICE_4110: return "DEVICE_4110";
        case PciDeviceEACE::DEVICE_4220: return "DEVICE_4220";
        case PciDeviceEACE::DEVICE_422E: return "DEVICE_422E";
        case PciDeviceEACE::DEVICE_4230: return "DEVICE_4230";
        case PciDeviceEACE::DEVICE_423E: return "DEVICE_423E";
        case PciDeviceEACE::DEVICE_4300: return "DEVICE_4300";
        case PciDeviceEACE::DEVICE_430E: return "DEVICE_430E";
        case PciDeviceEACE::DEVICE_452E: return "DEVICE_452E";
        case PciDeviceEACE::DEVICE_454E: return "DEVICE_454E";
        case PciDeviceEACE::DEVICE_45B8: return "DEVICE_45B8";
        case PciDeviceEACE::DEVICE_45BE: return "DEVICE_45BE";
        case PciDeviceEACE::DEVICE_520E: return "DEVICE_520E";
        case PciDeviceEACE::DEVICE_521A: return "DEVICE_521A";
        case PciDeviceEACE::DEVICE_5400: return "DEVICE_5400";
        case PciDeviceEACE::DEVICE_5401: return "DEVICE_5401";
        case PciDeviceEACE::DEVICE_540A: return "DEVICE_540A";
        case PciDeviceEACE::DEVICE_541A: return "DEVICE_541A";
        case PciDeviceEACE::DEVICE_542A: return "DEVICE_542A";
        case PciDeviceEACE::DEVICE_6000: return "DEVICE_6000";
        case PciDeviceEACE::DEVICE_6100: return "DEVICE_6100";
        case PciDeviceEACE::DEVICE_6200: return "DEVICE_6200";
        case PciDeviceEACE::DEVICE_7100: return "DEVICE_7100";
        case PciDeviceEACE::DEVICE_7400: return "DEVICE_7400";
        case PciDeviceEACE::DEVICE_7401: return "DEVICE_7401";
        case PciDeviceEACE::DEVICE_752E: return "DEVICE_752E";
        case PciDeviceEACE::DEVICE_754E: return "DEVICE_754E";
        case PciDeviceEACE::DEVICE_8100: return "DEVICE_8100";
        case PciDeviceEACE::DEVICE_8101: return "DEVICE_8101";
        case PciDeviceEACE::DEVICE_8102: return "DEVICE_8102";
        case PciDeviceEACE::DEVICE_820E: return "DEVICE_820E";
        case PciDeviceEACE::DEVICE_820F: return "DEVICE_820F";
        case PciDeviceEACE::DEVICE_8400: return "DEVICE_8400";
        case PciDeviceEACE::DEVICE_8500: return "DEVICE_8500";
        case PciDeviceEACE::DEVICE_9200: return "DEVICE_9200";
        case PciDeviceEACE::DEVICE_920E: return "DEVICE_920E";
        case PciDeviceEACE::DEVICE_9540: return "DEVICE_9540";
        case PciDeviceEACE::DEVICE_954F: return "DEVICE_954F";
        case PciDeviceEACE::DEVICE_A120: return "DEVICE_A120";
        case PciDeviceEACE::DEVICE_A12E: return "DEVICE_A12E";
        case PciDeviceEACE::DEVICE_A140: return "DEVICE_A140";
        case PciDeviceEACE::DEVICE_A14E: return "DEVICE_A14E";
        case PciDeviceEACE::DEVICE_EACE: return "DEVICE_EACE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceEACE deviceEACE) // TEST: NO
{
    // COMMON_LT((" | deviceEACE = %u", deviceEACE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceEACE, enumToString(deviceEACE));

    return res;
}



inline const char8* enumToHumanString(PciDeviceEACE deviceEACE) // TEST: NO
{
    // COMMON_LT((" | deviceEACE = %u", deviceEACE)); // Commented to avoid bad looking logs



    switch (deviceEACE)
    {
        case PciDeviceEACE::DEVICE_3100: return "DAG 3.10 OC-3/OC-12";
        case PciDeviceEACE::DEVICE_3200: return "DAG 3.2x OC-3/OC-12";
        case PciDeviceEACE::DEVICE_320E: return "DAG 3.2E Fast Ethernet";
        case PciDeviceEACE::DEVICE_340E: return "DAG 3.4E Fast Ethernet";
        case PciDeviceEACE::DEVICE_341E: return "DAG 3.41E Fast Ethernet";
        case PciDeviceEACE::DEVICE_3500: return "DAG 3.5 OC-3/OC-12";
        case PciDeviceEACE::DEVICE_351C: return "DAG 3.5ECM Fast Ethernet";
        case PciDeviceEACE::DEVICE_360D: return "DAG 3.6D DS3";
        case PciDeviceEACE::DEVICE_360E: return "DAG 3.6E Fast Ethernet";
        case PciDeviceEACE::DEVICE_368E: return "DAG 3.6E Gig Ethernet";
        case PciDeviceEACE::DEVICE_3707: return "DAG 3.7T T1/E1/J1";
        case PciDeviceEACE::DEVICE_370D: return "DAG 3.7D DS3/E3";
        case PciDeviceEACE::DEVICE_378E: return "DAG 3.7G Gig Ethernet";
        case PciDeviceEACE::DEVICE_3800: return "DAG 3.8S OC-3/OC-12";
        case PciDeviceEACE::DEVICE_4100: return "DAG 4.10 OC-48";
        case PciDeviceEACE::DEVICE_4110: return "DAG 4.11 OC-48";
        case PciDeviceEACE::DEVICE_4220: return "DAG 4.2 OC-48";
        case PciDeviceEACE::DEVICE_422E: return "DAG 4.2GE Gig Ethernet";
        case PciDeviceEACE::DEVICE_4230: return "DAG 4.2S OC-48";
        case PciDeviceEACE::DEVICE_423E: return "DAG 4.2GE Gig Ethernet";
        case PciDeviceEACE::DEVICE_4300: return "DAG 4.3S OC-48";
        case PciDeviceEACE::DEVICE_430E: return "DAG 4.3GE Gig Ethernet";
        case PciDeviceEACE::DEVICE_452E: return "DAG 4.5G2 Gig Ethernet";
        case PciDeviceEACE::DEVICE_454E: return "DAG 4.5G4 Gig Ethernet";
        case PciDeviceEACE::DEVICE_45B8: return "DAG 4.5Z8 Gig Ethernet";
        case PciDeviceEACE::DEVICE_45BE: return "DAG 4.5Z2 Gig Ethernet";
        case PciDeviceEACE::DEVICE_520E: return "DAG 5.2X 10G Ethernet";
        case PciDeviceEACE::DEVICE_521A: return "DAG 5.2SXA 10G Ethernet/OC-192";
        case PciDeviceEACE::DEVICE_5400: return "DAG 5.4S-12 OC-3/OC-12";
        case PciDeviceEACE::DEVICE_5401: return "DAG 5.4SG-48 Gig Ethernet/OC-3/OC-12/OC-48";
        case PciDeviceEACE::DEVICE_540A: return "DAG 5.4GA Gig Ethernet";
        case PciDeviceEACE::DEVICE_541A: return "DAG 5.4SA-12 OC-3/OC-12";
        case PciDeviceEACE::DEVICE_542A: return "DAG 5.4SGA-48 Gig Ethernet/OC-3/OC-12/OC-48";
        case PciDeviceEACE::DEVICE_6000: return "DAG 6.0SE 10G Ethernet/OC-192";
        case PciDeviceEACE::DEVICE_6100: return "DAG 6.1SE 10G Ethernet/OC-192";
        case PciDeviceEACE::DEVICE_6200: return "DAG 6.2SE 10G Ethernet/OC-192";
        case PciDeviceEACE::DEVICE_7100: return "DAG 7.1S OC-3/OC-12";
        case PciDeviceEACE::DEVICE_7400: return "DAG 7.4S OC-3/OC-12";
        case PciDeviceEACE::DEVICE_7401: return "DAG 7.4S48 OC-48";
        case PciDeviceEACE::DEVICE_752E: return "DAG 7.5G2 Gig Ethernet";
        case PciDeviceEACE::DEVICE_754E: return "DAG 7.5G4 Gig Ethernet";
        case PciDeviceEACE::DEVICE_8100: return "DAG 8.1X 10G Ethernet";
        case PciDeviceEACE::DEVICE_8101: return "DAG 8.1SX 10G Ethernet/OC-192";
        case PciDeviceEACE::DEVICE_8102: return "DAG 8.1X 10G Ethernet";
        case PciDeviceEACE::DEVICE_820E: return "DAG 8.2X 10G Ethernet";
        case PciDeviceEACE::DEVICE_820F: return "DAG 8.2X 10G Ethernet (2nd bus)";
        case PciDeviceEACE::DEVICE_8400: return "DAG 8.4I Infiniband x4 SDR";
        case PciDeviceEACE::DEVICE_8500: return "DAG 8.5I Infiniband x4 DDR";
        case PciDeviceEACE::DEVICE_9200: return "DAG 9.2SX2 10G Ethernet";
        case PciDeviceEACE::DEVICE_920E: return "DAG 9.2X2 10G Ethernet";
        case PciDeviceEACE::DEVICE_9540: return "DAG 9.5G4 Gig Ethernet";
        case PciDeviceEACE::DEVICE_954F: return "DAG 9.5G4F Gig Ethernet";
        case PciDeviceEACE::DEVICE_A120: return "DAG 10X2-P 10G Ethernet";
        case PciDeviceEACE::DEVICE_A12E: return "DAG 10X2-S 10G Ethernet";
        case PciDeviceEACE::DEVICE_A140: return "DAG 10X4-P 10/40G Ethernet";
        case PciDeviceEACE::DEVICE_A14E: return "DAG 10X4-S 10/40G Ethernet";
        case PciDeviceEACE::DEVICE_EACE: return "vDAG virtual device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREACE_PCIDEVICEEACE_H
