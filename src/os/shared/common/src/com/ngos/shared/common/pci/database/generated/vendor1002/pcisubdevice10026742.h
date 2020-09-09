// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026742_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026742_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026742: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10026570 = 0x10026570,
    SUBDEVICE_10192393 = 0x10192393,
    SUBDEVICE_10431D82 = 0x10431D82,
    SUBDEVICE_1179FB22 = 0x1179FB22,
    SUBDEVICE_1179FB23 = 0x1179FB23,
    SUBDEVICE_1179FB27 = 0x1179FB27,
    SUBDEVICE_1179FB2A = 0x1179FB2A,
    SUBDEVICE_1179FB2C = 0x1179FB2C,
    SUBDEVICE_1179FB30 = 0x1179FB30,
    SUBDEVICE_1179FB31 = 0x1179FB31,
    SUBDEVICE_1179FB32 = 0x1179FB32,
    SUBDEVICE_1179FB38 = 0x1179FB38,
    SUBDEVICE_1179FB39 = 0x1179FB39,
    SUBDEVICE_1179FB3A = 0x1179FB3A,
    SUBDEVICE_1179FB3B = 0x1179FB3B,
    SUBDEVICE_1179FB40 = 0x1179FB40,
    SUBDEVICE_1179FB41 = 0x1179FB41,
    SUBDEVICE_1179FB47 = 0x1179FB47,
    SUBDEVICE_1179FB48 = 0x1179FB48,
    SUBDEVICE_1179FB49 = 0x1179FB49,
    SUBDEVICE_1179FB51 = 0x1179FB51,
    SUBDEVICE_1179FB52 = 0x1179FB52,
    SUBDEVICE_1179FB53 = 0x1179FB53,
    SUBDEVICE_1179FB56 = 0x1179FB56,
    SUBDEVICE_1179FB81 = 0x1179FB81,
    SUBDEVICE_1179FB82 = 0x1179FB82,
    SUBDEVICE_1179FB83 = 0x1179FB83,
    SUBDEVICE_1179FC56 = 0x1179FC56,
    SUBDEVICE_1179FCD4 = 0x1179FCD4,
    SUBDEVICE_1179FCEE = 0x1179FCEE,
    SUBDEVICE_14586570 = 0x14586570,
    SUBDEVICE_14626570 = 0x14626570,
    SUBDEVICE_148C6570 = 0x148C6570,
    SUBDEVICE_16826570 = 0x16826570,
    SUBDEVICE_174B5570 = 0x174B5570,
    SUBDEVICE_174B6570 = 0x174B6570,
    SUBDEVICE_174B7570 = 0x174B7570,
    SUBDEVICE_174B8510 = 0x174B8510,
    SUBDEVICE_174B8570 = 0x174B8570,
    SUBDEVICE_17876570 = 0x17876570,
    SUBDEVICE_17AF6570 = 0x17AF6570,
    SUBDEVICE_80862111 = 0x80862111
};



inline const char8* enumToString(PciSubDevice10026742 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026742::NONE:               return "NONE";
        case PciSubDevice10026742::SUBDEVICE_10026570: return "SUBDEVICE_10026570";
        case PciSubDevice10026742::SUBDEVICE_10192393: return "SUBDEVICE_10192393";
        case PciSubDevice10026742::SUBDEVICE_10431D82: return "SUBDEVICE_10431D82";
        case PciSubDevice10026742::SUBDEVICE_1179FB22: return "SUBDEVICE_1179FB22";
        case PciSubDevice10026742::SUBDEVICE_1179FB23: return "SUBDEVICE_1179FB23";
        case PciSubDevice10026742::SUBDEVICE_1179FB27: return "SUBDEVICE_1179FB27";
        case PciSubDevice10026742::SUBDEVICE_1179FB2A: return "SUBDEVICE_1179FB2A";
        case PciSubDevice10026742::SUBDEVICE_1179FB2C: return "SUBDEVICE_1179FB2C";
        case PciSubDevice10026742::SUBDEVICE_1179FB30: return "SUBDEVICE_1179FB30";
        case PciSubDevice10026742::SUBDEVICE_1179FB31: return "SUBDEVICE_1179FB31";
        case PciSubDevice10026742::SUBDEVICE_1179FB32: return "SUBDEVICE_1179FB32";
        case PciSubDevice10026742::SUBDEVICE_1179FB38: return "SUBDEVICE_1179FB38";
        case PciSubDevice10026742::SUBDEVICE_1179FB39: return "SUBDEVICE_1179FB39";
        case PciSubDevice10026742::SUBDEVICE_1179FB3A: return "SUBDEVICE_1179FB3A";
        case PciSubDevice10026742::SUBDEVICE_1179FB3B: return "SUBDEVICE_1179FB3B";
        case PciSubDevice10026742::SUBDEVICE_1179FB40: return "SUBDEVICE_1179FB40";
        case PciSubDevice10026742::SUBDEVICE_1179FB41: return "SUBDEVICE_1179FB41";
        case PciSubDevice10026742::SUBDEVICE_1179FB47: return "SUBDEVICE_1179FB47";
        case PciSubDevice10026742::SUBDEVICE_1179FB48: return "SUBDEVICE_1179FB48";
        case PciSubDevice10026742::SUBDEVICE_1179FB49: return "SUBDEVICE_1179FB49";
        case PciSubDevice10026742::SUBDEVICE_1179FB51: return "SUBDEVICE_1179FB51";
        case PciSubDevice10026742::SUBDEVICE_1179FB52: return "SUBDEVICE_1179FB52";
        case PciSubDevice10026742::SUBDEVICE_1179FB53: return "SUBDEVICE_1179FB53";
        case PciSubDevice10026742::SUBDEVICE_1179FB56: return "SUBDEVICE_1179FB56";
        case PciSubDevice10026742::SUBDEVICE_1179FB81: return "SUBDEVICE_1179FB81";
        case PciSubDevice10026742::SUBDEVICE_1179FB82: return "SUBDEVICE_1179FB82";
        case PciSubDevice10026742::SUBDEVICE_1179FB83: return "SUBDEVICE_1179FB83";
        case PciSubDevice10026742::SUBDEVICE_1179FC56: return "SUBDEVICE_1179FC56";
        case PciSubDevice10026742::SUBDEVICE_1179FCD4: return "SUBDEVICE_1179FCD4";
        case PciSubDevice10026742::SUBDEVICE_1179FCEE: return "SUBDEVICE_1179FCEE";
        case PciSubDevice10026742::SUBDEVICE_14586570: return "SUBDEVICE_14586570";
        case PciSubDevice10026742::SUBDEVICE_14626570: return "SUBDEVICE_14626570";
        case PciSubDevice10026742::SUBDEVICE_148C6570: return "SUBDEVICE_148C6570";
        case PciSubDevice10026742::SUBDEVICE_16826570: return "SUBDEVICE_16826570";
        case PciSubDevice10026742::SUBDEVICE_174B5570: return "SUBDEVICE_174B5570";
        case PciSubDevice10026742::SUBDEVICE_174B6570: return "SUBDEVICE_174B6570";
        case PciSubDevice10026742::SUBDEVICE_174B7570: return "SUBDEVICE_174B7570";
        case PciSubDevice10026742::SUBDEVICE_174B8510: return "SUBDEVICE_174B8510";
        case PciSubDevice10026742::SUBDEVICE_174B8570: return "SUBDEVICE_174B8570";
        case PciSubDevice10026742::SUBDEVICE_17876570: return "SUBDEVICE_17876570";
        case PciSubDevice10026742::SUBDEVICE_17AF6570: return "SUBDEVICE_17AF6570";
        case PciSubDevice10026742::SUBDEVICE_80862111: return "SUBDEVICE_80862111";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026742 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026742 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026742::SUBDEVICE_10026570: return "Turks [Radeon HD 6570]";
        case PciSubDevice10026742::SUBDEVICE_10192393: return "Radeon HD 6610M";
        case PciSubDevice10026742::SUBDEVICE_10431D82: return "K53SK Laptop Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB22: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB23: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB27: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB2A: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB2C: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB30: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB31: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB32: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB38: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB39: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB3A: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB3B: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB40: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB41: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB47: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB48: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB49: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB51: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB52: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB53: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB56: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB81: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB82: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FB83: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FC56: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FCD4: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_1179FCEE: return "Radeon HD 7610M";
        case PciSubDevice10026742::SUBDEVICE_14586570: return "Turks [Radeon HD 6570]";
        case PciSubDevice10026742::SUBDEVICE_14626570: return "Turks [Radeon HD 6570]";
        case PciSubDevice10026742::SUBDEVICE_148C6570: return "Turks [Radeon HD 6570]";
        case PciSubDevice10026742::SUBDEVICE_16826570: return "Turks [Radeon HD 6570]";
        case PciSubDevice10026742::SUBDEVICE_174B5570: return "Turks [Radeon HD 5570]";
        case PciSubDevice10026742::SUBDEVICE_174B6570: return "Turks [Radeon HD 6570]";
        case PciSubDevice10026742::SUBDEVICE_174B7570: return "Turks [Radeon HD 7570]";
        case PciSubDevice10026742::SUBDEVICE_174B8510: return "Turks [Radeon HD 8510]";
        case PciSubDevice10026742::SUBDEVICE_174B8570: return "Turks [Radeon HD 8570]";
        case PciSubDevice10026742::SUBDEVICE_17876570: return "Turks [Radeon HD 6570]";
        case PciSubDevice10026742::SUBDEVICE_17AF6570: return "Turks [Radeon HD 6570]";
        case PciSubDevice10026742::SUBDEVICE_80862111: return "Radeon HD 6625M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026742_H
