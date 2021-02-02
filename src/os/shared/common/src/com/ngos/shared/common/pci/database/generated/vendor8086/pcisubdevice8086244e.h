// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086244E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_1028020D = 0x1028020D,
    SUBDEVICE_10280211 = 0x10280211,
    SUBDEVICE_102802DA = 0x102802DA,
    SUBDEVICE_102804F7 = 0x102804F7,
    SUBDEVICE_103C2A3B = 0x103C2A3B,
    SUBDEVICE_103C2A6F = 0x103C2A6F,
    SUBDEVICE_103C31FE = 0x103C31FE,
    SUBDEVICE_103C330B = 0x103C330B,
    SUBDEVICE_10438277 = 0x10438277,
    SUBDEVICE_1043844D = 0x1043844D,
    SUBDEVICE_10438534 = 0x10438534,
    SUBDEVICE_14585000 = 0x14585000,
    SUBDEVICE_14627345 = 0x14627345,
    SUBDEVICE_14627418 = 0x14627418,
    SUBDEVICE_15D9060D = 0x15D9060D,
    SUBDEVICE_15D99680 = 0x15D99680,
    SUBDEVICE_177511CC = 0x177511CC,
    SUBDEVICE_80867270 = 0x80867270
};



inline const char8* enumToString(PciSubDevice8086244E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086244E::NONE:               return "NONE";
        case PciSubDevice8086244E::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice8086244E::SUBDEVICE_1028020D: return "SUBDEVICE_1028020D";
        case PciSubDevice8086244E::SUBDEVICE_10280211: return "SUBDEVICE_10280211";
        case PciSubDevice8086244E::SUBDEVICE_102802DA: return "SUBDEVICE_102802DA";
        case PciSubDevice8086244E::SUBDEVICE_102804F7: return "SUBDEVICE_102804F7";
        case PciSubDevice8086244E::SUBDEVICE_103C2A3B: return "SUBDEVICE_103C2A3B";
        case PciSubDevice8086244E::SUBDEVICE_103C2A6F: return "SUBDEVICE_103C2A6F";
        case PciSubDevice8086244E::SUBDEVICE_103C31FE: return "SUBDEVICE_103C31FE";
        case PciSubDevice8086244E::SUBDEVICE_103C330B: return "SUBDEVICE_103C330B";
        case PciSubDevice8086244E::SUBDEVICE_10438277: return "SUBDEVICE_10438277";
        case PciSubDevice8086244E::SUBDEVICE_1043844D: return "SUBDEVICE_1043844D";
        case PciSubDevice8086244E::SUBDEVICE_10438534: return "SUBDEVICE_10438534";
        case PciSubDevice8086244E::SUBDEVICE_14585000: return "SUBDEVICE_14585000";
        case PciSubDevice8086244E::SUBDEVICE_14627345: return "SUBDEVICE_14627345";
        case PciSubDevice8086244E::SUBDEVICE_14627418: return "SUBDEVICE_14627418";
        case PciSubDevice8086244E::SUBDEVICE_15D9060D: return "SUBDEVICE_15D9060D";
        case PciSubDevice8086244E::SUBDEVICE_15D99680: return "SUBDEVICE_15D99680";
        case PciSubDevice8086244E::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";
        case PciSubDevice8086244E::SUBDEVICE_80867270: return "SUBDEVICE_80867270";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086244E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086244E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086244E::SUBDEVICE_10140267: return "NetVista A30p";
        case PciSubDevice8086244E::SUBDEVICE_1028020D: return "Inspiron 530";
        case PciSubDevice8086244E::SUBDEVICE_10280211: return "Optiplex 755";
        case PciSubDevice8086244E::SUBDEVICE_102802DA: return "OptiPlex 980";
        case PciSubDevice8086244E::SUBDEVICE_102804F7: return "PowerEdge R320 server";
        case PciSubDevice8086244E::SUBDEVICE_103C2A3B: return "Pavilion A1512X";
        case PciSubDevice8086244E::SUBDEVICE_103C2A6F: return "Asus IPIBL-LB Motherboard";
        case PciSubDevice8086244E::SUBDEVICE_103C31FE: return "ProLiant DL140 G3";
        case PciSubDevice8086244E::SUBDEVICE_103C330B: return "ProLiant ML150 G6 Server";
        case PciSubDevice8086244E::SUBDEVICE_10438277: return "P5K PRO Motherboard";
        case PciSubDevice8086244E::SUBDEVICE_1043844D: return "P8 series motherboard";
        case PciSubDevice8086244E::SUBDEVICE_10438534: return "ASUS B85-PLUS";
        case PciSubDevice8086244E::SUBDEVICE_14585000: return "Motherboard";
        case PciSubDevice8086244E::SUBDEVICE_14627345: return "MS-7345 Motherboard: Intel 82801I/IR [ICH9/ICH9R]";
        case PciSubDevice8086244E::SUBDEVICE_14627418: return "Wind PC MS-7418";
        case PciSubDevice8086244E::SUBDEVICE_15D9060D: return "C7SIM-Q Motherboard";
        case PciSubDevice8086244E::SUBDEVICE_15D99680: return "X7DBN Motherboard";
        case PciSubDevice8086244E::SUBDEVICE_177511CC: return "CC11/CL11";
        case PciSubDevice8086244E::SUBDEVICE_80867270: return "Server Board S1200BTS";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244E_H
