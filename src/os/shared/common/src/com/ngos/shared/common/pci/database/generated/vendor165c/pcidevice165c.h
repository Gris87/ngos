// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165C_PCIDEVICE165C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165C_PCIDEVICE165C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice165C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5361 = 0x5361,
    DEVICE_5362 = 0x5362,
    DEVICE_5364 = 0x5364,
    DEVICE_5435 = 0x5435,
    DEVICE_5661 = 0x5661,
    DEVICE_56E1 = 0x56E1,
    DEVICE_5911 = 0x5911,
    DEVICE_5912 = 0x5912,
    DEVICE_5913 = 0x5913,
    DEVICE_5914 = 0x5914,
    DEVICE_5921 = 0x5921,
    DEVICE_5922 = 0x5922,
    DEVICE_5923 = 0x5923,
    DEVICE_5924 = 0x5924,
    DEVICE_5931 = 0x5931,
    DEVICE_5932 = 0x5932,
    DEVICE_5933 = 0x5933,
    DEVICE_5934 = 0x5934,
    DEVICE_5941 = 0x5941,
    DEVICE_5942 = 0x5942,
    DEVICE_5943 = 0x5943,
    DEVICE_5944 = 0x5944,
    DEVICE_5A01 = 0x5A01,
    DEVICE_5A11 = 0x5A11,
    DEVICE_5A21 = 0x5A21,
    DEVICE_5A31 = 0x5A31,
    DEVICE_5A41 = 0x5A41,
    DEVICE_5B51 = 0x5B51,
    DEVICE_5B61 = 0x5B61,
    DEVICE_5B71 = 0x5B71,
    DEVICE_5C01 = 0x5C01,
    DEVICE_5C02 = 0x5C02,
    DEVICE_5C03 = 0x5C03,
    DEVICE_5C04 = 0x5C04,
    DEVICE_5C11 = 0x5C11,
    DEVICE_5C12 = 0x5C12,
    DEVICE_5C13 = 0x5C13,
    DEVICE_5C14 = 0x5C14,
    DEVICE_5C51 = 0x5C51,
    DEVICE_5C52 = 0x5C52,
    DEVICE_5C53 = 0x5C53,
    DEVICE_5C54 = 0x5C54,
    DEVICE_5C61 = 0x5C61,
    DEVICE_5C62 = 0x5C62,
    DEVICE_5C63 = 0x5C63,
    DEVICE_5C64 = 0x5C64,
    DEVICE_5C71 = 0x5C71,
    DEVICE_5C72 = 0x5C72,
    DEVICE_5C73 = 0x5C73,
    DEVICE_5C74 = 0x5C74,
    DEVICE_5D01 = 0x5D01,
    DEVICE_5D11 = 0x5D11,
    DEVICE_5F01 = 0x5F01,
    DEVICE_5F11 = 0x5F11,
    DEVICE_5F21 = 0x5F21,
    DEVICE_5F31 = 0x5F31,
    DEVICE_5F41 = 0x5F41,
    DEVICE_6732 = 0x6732,
    DEVICE_6832 = 0x6832,
    DEVICE_7101 = 0x7101,
    DEVICE_7111 = 0x7111,
    DEVICE_7121 = 0x7121,
    DEVICE_7141 = 0x7141,
    DEVICE_7181 = 0x7181,
    DEVICE_7191 = 0x7191,
    DEVICE_71A1 = 0x71A1,
    DEVICE_71B1 = 0x71B1,
    DEVICE_72B1 = 0x72B1,
    DEVICE_73B1 = 0x73B1
};



inline const char8* enumToString(PciDevice165C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice165C::NONE:        return "NONE";
        case PciDevice165C::DEVICE_5361: return "DEVICE_5361";
        case PciDevice165C::DEVICE_5362: return "DEVICE_5362";
        case PciDevice165C::DEVICE_5364: return "DEVICE_5364";
        case PciDevice165C::DEVICE_5435: return "DEVICE_5435";
        case PciDevice165C::DEVICE_5661: return "DEVICE_5661";
        case PciDevice165C::DEVICE_56E1: return "DEVICE_56E1";
        case PciDevice165C::DEVICE_5911: return "DEVICE_5911";
        case PciDevice165C::DEVICE_5912: return "DEVICE_5912";
        case PciDevice165C::DEVICE_5913: return "DEVICE_5913";
        case PciDevice165C::DEVICE_5914: return "DEVICE_5914";
        case PciDevice165C::DEVICE_5921: return "DEVICE_5921";
        case PciDevice165C::DEVICE_5922: return "DEVICE_5922";
        case PciDevice165C::DEVICE_5923: return "DEVICE_5923";
        case PciDevice165C::DEVICE_5924: return "DEVICE_5924";
        case PciDevice165C::DEVICE_5931: return "DEVICE_5931";
        case PciDevice165C::DEVICE_5932: return "DEVICE_5932";
        case PciDevice165C::DEVICE_5933: return "DEVICE_5933";
        case PciDevice165C::DEVICE_5934: return "DEVICE_5934";
        case PciDevice165C::DEVICE_5941: return "DEVICE_5941";
        case PciDevice165C::DEVICE_5942: return "DEVICE_5942";
        case PciDevice165C::DEVICE_5943: return "DEVICE_5943";
        case PciDevice165C::DEVICE_5944: return "DEVICE_5944";
        case PciDevice165C::DEVICE_5A01: return "DEVICE_5A01";
        case PciDevice165C::DEVICE_5A11: return "DEVICE_5A11";
        case PciDevice165C::DEVICE_5A21: return "DEVICE_5A21";
        case PciDevice165C::DEVICE_5A31: return "DEVICE_5A31";
        case PciDevice165C::DEVICE_5A41: return "DEVICE_5A41";
        case PciDevice165C::DEVICE_5B51: return "DEVICE_5B51";
        case PciDevice165C::DEVICE_5B61: return "DEVICE_5B61";
        case PciDevice165C::DEVICE_5B71: return "DEVICE_5B71";
        case PciDevice165C::DEVICE_5C01: return "DEVICE_5C01";
        case PciDevice165C::DEVICE_5C02: return "DEVICE_5C02";
        case PciDevice165C::DEVICE_5C03: return "DEVICE_5C03";
        case PciDevice165C::DEVICE_5C04: return "DEVICE_5C04";
        case PciDevice165C::DEVICE_5C11: return "DEVICE_5C11";
        case PciDevice165C::DEVICE_5C12: return "DEVICE_5C12";
        case PciDevice165C::DEVICE_5C13: return "DEVICE_5C13";
        case PciDevice165C::DEVICE_5C14: return "DEVICE_5C14";
        case PciDevice165C::DEVICE_5C51: return "DEVICE_5C51";
        case PciDevice165C::DEVICE_5C52: return "DEVICE_5C52";
        case PciDevice165C::DEVICE_5C53: return "DEVICE_5C53";
        case PciDevice165C::DEVICE_5C54: return "DEVICE_5C54";
        case PciDevice165C::DEVICE_5C61: return "DEVICE_5C61";
        case PciDevice165C::DEVICE_5C62: return "DEVICE_5C62";
        case PciDevice165C::DEVICE_5C63: return "DEVICE_5C63";
        case PciDevice165C::DEVICE_5C64: return "DEVICE_5C64";
        case PciDevice165C::DEVICE_5C71: return "DEVICE_5C71";
        case PciDevice165C::DEVICE_5C72: return "DEVICE_5C72";
        case PciDevice165C::DEVICE_5C73: return "DEVICE_5C73";
        case PciDevice165C::DEVICE_5C74: return "DEVICE_5C74";
        case PciDevice165C::DEVICE_5D01: return "DEVICE_5D01";
        case PciDevice165C::DEVICE_5D11: return "DEVICE_5D11";
        case PciDevice165C::DEVICE_5F01: return "DEVICE_5F01";
        case PciDevice165C::DEVICE_5F11: return "DEVICE_5F11";
        case PciDevice165C::DEVICE_5F21: return "DEVICE_5F21";
        case PciDevice165C::DEVICE_5F31: return "DEVICE_5F31";
        case PciDevice165C::DEVICE_5F41: return "DEVICE_5F41";
        case PciDevice165C::DEVICE_6732: return "DEVICE_6732";
        case PciDevice165C::DEVICE_6832: return "DEVICE_6832";
        case PciDevice165C::DEVICE_7101: return "DEVICE_7101";
        case PciDevice165C::DEVICE_7111: return "DEVICE_7111";
        case PciDevice165C::DEVICE_7121: return "DEVICE_7121";
        case PciDevice165C::DEVICE_7141: return "DEVICE_7141";
        case PciDevice165C::DEVICE_7181: return "DEVICE_7181";
        case PciDevice165C::DEVICE_7191: return "DEVICE_7191";
        case PciDevice165C::DEVICE_71A1: return "DEVICE_71A1";
        case PciDevice165C::DEVICE_71B1: return "DEVICE_71B1";
        case PciDevice165C::DEVICE_72B1: return "DEVICE_72B1";
        case PciDevice165C::DEVICE_73B1: return "DEVICE_73B1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice165C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice165C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice165C::DEVICE_5361: return "PROCStarII60-1";
        case PciDevice165C::DEVICE_5362: return "PROCStarII60-2";
        case PciDevice165C::DEVICE_5364: return "PROCStarII60-4";
        case PciDevice165C::DEVICE_5435: return "ProcSparkII";
        case PciDevice165C::DEVICE_5661: return "ProcE60";
        case PciDevice165C::DEVICE_56E1: return "ProcE180";
        case PciDevice165C::DEVICE_5911: return "ProcStarIII110-1";
        case PciDevice165C::DEVICE_5912: return "ProcStarIII110-2";
        case PciDevice165C::DEVICE_5913: return "ProcStarIII110-3";
        case PciDevice165C::DEVICE_5914: return "ProcStarIII110-4";
        case PciDevice165C::DEVICE_5921: return "ProcStarIII150-1";
        case PciDevice165C::DEVICE_5922: return "ProcStarIII150-2";
        case PciDevice165C::DEVICE_5923: return "ProcStarIII150-3";
        case PciDevice165C::DEVICE_5924: return "ProcStarIII150-4";
        case PciDevice165C::DEVICE_5931: return "ProcStarIII260-1";
        case PciDevice165C::DEVICE_5932: return "ProcStarIII260-2";
        case PciDevice165C::DEVICE_5933: return "ProcStarIII260-3";
        case PciDevice165C::DEVICE_5934: return "ProcStarIII260-4";
        case PciDevice165C::DEVICE_5941: return "ProcStarIII340-1";
        case PciDevice165C::DEVICE_5942: return "ProcStarIII340-2";
        case PciDevice165C::DEVICE_5943: return "ProcStarIII340-3";
        case PciDevice165C::DEVICE_5944: return "ProcStarIII340-4";
        case PciDevice165C::DEVICE_5A01: return "ProceIIi80";
        case PciDevice165C::DEVICE_5A11: return "ProceIII110";
        case PciDevice165C::DEVICE_5A21: return "ProceIII150";
        case PciDevice165C::DEVICE_5A31: return "ProceIII260";
        case PciDevice165C::DEVICE_5A41: return "ProceIII340";
        case PciDevice165C::DEVICE_5B51: return "ProceIV360";
        case PciDevice165C::DEVICE_5B61: return "ProceIV530";
        case PciDevice165C::DEVICE_5B71: return "ProceIV820";
        case PciDevice165C::DEVICE_5C01: return "ProcStarIV80-1";
        case PciDevice165C::DEVICE_5C02: return "ProcStarIV80-2";
        case PciDevice165C::DEVICE_5C03: return "ProcStarIV80-3";
        case PciDevice165C::DEVICE_5C04: return "ProcStarIV80-4";
        case PciDevice165C::DEVICE_5C11: return "ProcStarIV110-1";
        case PciDevice165C::DEVICE_5C12: return "ProcStarIV110-2";
        case PciDevice165C::DEVICE_5C13: return "ProcStarIV110-3";
        case PciDevice165C::DEVICE_5C14: return "ProcStarIV110-4";
        case PciDevice165C::DEVICE_5C51: return "ProcStarIV360-1";
        case PciDevice165C::DEVICE_5C52: return "ProcStarIV360-2";
        case PciDevice165C::DEVICE_5C53: return "ProcStarIV360-3";
        case PciDevice165C::DEVICE_5C54: return "ProcStarIV360-4";
        case PciDevice165C::DEVICE_5C61: return "ProcStarIV530-1";
        case PciDevice165C::DEVICE_5C62: return "ProcStarIV530-2";
        case PciDevice165C::DEVICE_5C63: return "ProcStarIV530-3";
        case PciDevice165C::DEVICE_5C64: return "ProcStarIV530-4";
        case PciDevice165C::DEVICE_5C71: return "ProcStarIV820-1";
        case PciDevice165C::DEVICE_5C72: return "ProcStarIV820-2";
        case PciDevice165C::DEVICE_5C73: return "ProcStarIV820-3";
        case PciDevice165C::DEVICE_5C74: return "ProcStarIV820-4";
        case PciDevice165C::DEVICE_5D01: return "Proc10480";
        case PciDevice165C::DEVICE_5D11: return "Proc104110";
        case PciDevice165C::DEVICE_5F01: return "ProceV_A3";
        case PciDevice165C::DEVICE_5F11: return "ProceV_A7";
        case PciDevice165C::DEVICE_5F21: return "ProceV_AB";
        case PciDevice165C::DEVICE_5F31: return "ProceV_D5";
        case PciDevice165C::DEVICE_5F41: return "ProceV_D8";
        case PciDevice165C::DEVICE_6732: return "Proc6M";
        case PciDevice165C::DEVICE_6832: return "Proc12M";
        case PciDevice165C::DEVICE_7101: return "Proc10a_27";
        case PciDevice165C::DEVICE_7111: return "Proc10a_48";
        case PciDevice165C::DEVICE_7121: return "Proc10a_66";
        case PciDevice165C::DEVICE_7141: return "Proc10a_115";
        case PciDevice165C::DEVICE_7181: return "Proc10a_27S";
        case PciDevice165C::DEVICE_7191: return "Proc10a_48S";
        case PciDevice165C::DEVICE_71A1: return "Proc10a_66S";
        case PciDevice165C::DEVICE_71B1: return "Proc10A";
        case PciDevice165C::DEVICE_72B1: return "HawkEye";
        case PciDevice165C::DEVICE_73B1: return "Proc10s";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165C_PCIDEVICE165C_H
