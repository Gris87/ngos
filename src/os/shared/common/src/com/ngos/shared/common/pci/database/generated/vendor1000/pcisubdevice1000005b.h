// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000005B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009265 = 0x10009265,
    SUBDEVICE_10009266 = 0x10009266,
    SUBDEVICE_10009267 = 0x10009267,
    SUBDEVICE_10009268 = 0x10009268,
    SUBDEVICE_10009269 = 0x10009269,
    SUBDEVICE_10009270 = 0x10009270,
    SUBDEVICE_10009271 = 0x10009271,
    SUBDEVICE_10009272 = 0x10009272,
    SUBDEVICE_10009273 = 0x10009273,
    SUBDEVICE_10009274 = 0x10009274,
    SUBDEVICE_10009275 = 0x10009275,
    SUBDEVICE_10009276 = 0x10009276,
    SUBDEVICE_10009285 = 0x10009285,
    SUBDEVICE_10009288 = 0x10009288,
    SUBDEVICE_10009290 = 0x10009290,
    SUBDEVICE_10009291 = 0x10009291,
    SUBDEVICE_10009295 = 0x10009295,
    SUBDEVICE_1014040B = 0x1014040B,
    SUBDEVICE_1014040C = 0x1014040C,
    SUBDEVICE_10140412 = 0x10140412,
    SUBDEVICE_10281F2D = 0x10281F2D,
    SUBDEVICE_10281F30 = 0x10281F30,
    SUBDEVICE_10281F31 = 0x10281F31,
    SUBDEVICE_10281F33 = 0x10281F33,
    SUBDEVICE_10281F34 = 0x10281F34,
    SUBDEVICE_10281F35 = 0x10281F35,
    SUBDEVICE_10281F37 = 0x10281F37,
    SUBDEVICE_10281F38 = 0x10281F38,
    SUBDEVICE_15D90690 = 0x15D90690,
    SUBDEVICE_80863510 = 0x80863510,
    SUBDEVICE_80863511 = 0x80863511,
    SUBDEVICE_80863512 = 0x80863512,
    SUBDEVICE_80863513 = 0x80863513,
    SUBDEVICE_80863514 = 0x80863514,
    SUBDEVICE_8086351C = 0x8086351C,
    SUBDEVICE_8086351D = 0x8086351D,
    SUBDEVICE_80869265 = 0x80869265,
    SUBDEVICE_80869268 = 0x80869268,
    SUBDEVICE_80869285 = 0x80869285,
    SUBDEVICE_80869288 = 0x80869288
};



inline const char8* enumToString(PciSubDevice1000005B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000005B::NONE:               return "NONE";
        case PciSubDevice1000005B::SUBDEVICE_10009265: return "SUBDEVICE_10009265";
        case PciSubDevice1000005B::SUBDEVICE_10009266: return "SUBDEVICE_10009266";
        case PciSubDevice1000005B::SUBDEVICE_10009267: return "SUBDEVICE_10009267";
        case PciSubDevice1000005B::SUBDEVICE_10009268: return "SUBDEVICE_10009268";
        case PciSubDevice1000005B::SUBDEVICE_10009269: return "SUBDEVICE_10009269";
        case PciSubDevice1000005B::SUBDEVICE_10009270: return "SUBDEVICE_10009270";
        case PciSubDevice1000005B::SUBDEVICE_10009271: return "SUBDEVICE_10009271";
        case PciSubDevice1000005B::SUBDEVICE_10009272: return "SUBDEVICE_10009272";
        case PciSubDevice1000005B::SUBDEVICE_10009273: return "SUBDEVICE_10009273";
        case PciSubDevice1000005B::SUBDEVICE_10009274: return "SUBDEVICE_10009274";
        case PciSubDevice1000005B::SUBDEVICE_10009275: return "SUBDEVICE_10009275";
        case PciSubDevice1000005B::SUBDEVICE_10009276: return "SUBDEVICE_10009276";
        case PciSubDevice1000005B::SUBDEVICE_10009285: return "SUBDEVICE_10009285";
        case PciSubDevice1000005B::SUBDEVICE_10009288: return "SUBDEVICE_10009288";
        case PciSubDevice1000005B::SUBDEVICE_10009290: return "SUBDEVICE_10009290";
        case PciSubDevice1000005B::SUBDEVICE_10009291: return "SUBDEVICE_10009291";
        case PciSubDevice1000005B::SUBDEVICE_10009295: return "SUBDEVICE_10009295";
        case PciSubDevice1000005B::SUBDEVICE_1014040B: return "SUBDEVICE_1014040B";
        case PciSubDevice1000005B::SUBDEVICE_1014040C: return "SUBDEVICE_1014040C";
        case PciSubDevice1000005B::SUBDEVICE_10140412: return "SUBDEVICE_10140412";
        case PciSubDevice1000005B::SUBDEVICE_10281F2D: return "SUBDEVICE_10281F2D";
        case PciSubDevice1000005B::SUBDEVICE_10281F30: return "SUBDEVICE_10281F30";
        case PciSubDevice1000005B::SUBDEVICE_10281F31: return "SUBDEVICE_10281F31";
        case PciSubDevice1000005B::SUBDEVICE_10281F33: return "SUBDEVICE_10281F33";
        case PciSubDevice1000005B::SUBDEVICE_10281F34: return "SUBDEVICE_10281F34";
        case PciSubDevice1000005B::SUBDEVICE_10281F35: return "SUBDEVICE_10281F35";
        case PciSubDevice1000005B::SUBDEVICE_10281F37: return "SUBDEVICE_10281F37";
        case PciSubDevice1000005B::SUBDEVICE_10281F38: return "SUBDEVICE_10281F38";
        case PciSubDevice1000005B::SUBDEVICE_15D90690: return "SUBDEVICE_15D90690";
        case PciSubDevice1000005B::SUBDEVICE_80863510: return "SUBDEVICE_80863510";
        case PciSubDevice1000005B::SUBDEVICE_80863511: return "SUBDEVICE_80863511";
        case PciSubDevice1000005B::SUBDEVICE_80863512: return "SUBDEVICE_80863512";
        case PciSubDevice1000005B::SUBDEVICE_80863513: return "SUBDEVICE_80863513";
        case PciSubDevice1000005B::SUBDEVICE_80863514: return "SUBDEVICE_80863514";
        case PciSubDevice1000005B::SUBDEVICE_8086351C: return "SUBDEVICE_8086351C";
        case PciSubDevice1000005B::SUBDEVICE_8086351D: return "SUBDEVICE_8086351D";
        case PciSubDevice1000005B::SUBDEVICE_80869265: return "SUBDEVICE_80869265";
        case PciSubDevice1000005B::SUBDEVICE_80869268: return "SUBDEVICE_80869268";
        case PciSubDevice1000005B::SUBDEVICE_80869285: return "SUBDEVICE_80869285";
        case PciSubDevice1000005B::SUBDEVICE_80869288: return "SUBDEVICE_80869288";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000005B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000005B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000005B::SUBDEVICE_10009265: return "MegaRAID SAS 9265-8i";
        case PciSubDevice1000005B::SUBDEVICE_10009266: return "MegaRAID SAS 9266-8i";
        case PciSubDevice1000005B::SUBDEVICE_10009267: return "MegaRAID SAS 9267-8i";
        case PciSubDevice1000005B::SUBDEVICE_10009268: return "MegaRAID SAS 9265CV-8i / 9270CV-8i";
        case PciSubDevice1000005B::SUBDEVICE_10009269: return "MegaRAID SAS 9266-4i";
        case PciSubDevice1000005B::SUBDEVICE_10009270: return "MegaRAID SAS 9270-8i";
        case PciSubDevice1000005B::SUBDEVICE_10009271: return "MegaRAID SAS 9271-8i";
        case PciSubDevice1000005B::SUBDEVICE_10009272: return "MegaRAID SAS 9272-8i";
        case PciSubDevice1000005B::SUBDEVICE_10009273: return "MegaRAID SAS 9270CV-8i";
        case PciSubDevice1000005B::SUBDEVICE_10009274: return "MegaRAID SAS 9270-4i";
        case PciSubDevice1000005B::SUBDEVICE_10009275: return "MegaRAID SAS 9271-8iCC";
        case PciSubDevice1000005B::SUBDEVICE_10009276: return "MegaRAID SAS 9271-4i";
        case PciSubDevice1000005B::SUBDEVICE_10009285: return "MegaRAID SAS 9285-8e";
        case PciSubDevice1000005B::SUBDEVICE_10009288: return "MegaRAID SAS 9285CV-8e";
        case PciSubDevice1000005B::SUBDEVICE_10009290: return "MegaRAID SAS 9286-8e";
        case PciSubDevice1000005B::SUBDEVICE_10009291: return "MegaRAID SAS 9286CV-8e";
        case PciSubDevice1000005B::SUBDEVICE_10009295: return "MegaRAID SAS 9286CV-8eCC";
        case PciSubDevice1000005B::SUBDEVICE_1014040B: return "ServeRAID M5110 SAS/SATA Controller";
        case PciSubDevice1000005B::SUBDEVICE_1014040C: return "ServeRAID M5120 SAS/SATA Controller";
        case PciSubDevice1000005B::SUBDEVICE_10140412: return "ServeRAID M5110e SAS/SATA Controller";
        case PciSubDevice1000005B::SUBDEVICE_10281F2D: return "PERC H810 Adapter";
        case PciSubDevice1000005B::SUBDEVICE_10281F30: return "PERC H710 Embedded";
        case PciSubDevice1000005B::SUBDEVICE_10281F31: return "PERC H710P Adapter";
        case PciSubDevice1000005B::SUBDEVICE_10281F33: return "PERC H710P Mini (for blades)";
        case PciSubDevice1000005B::SUBDEVICE_10281F34: return "PERC H710P Mini (for monolithics)";
        case PciSubDevice1000005B::SUBDEVICE_10281F35: return "PERC H710 Adapter";
        case PciSubDevice1000005B::SUBDEVICE_10281F37: return "PERC H710 Mini (for blades)";
        case PciSubDevice1000005B::SUBDEVICE_10281F38: return "PERC H710 Mini (for monolithics)";
        case PciSubDevice1000005B::SUBDEVICE_15D90690: return "LSI MegaRAID ROMB";
        case PciSubDevice1000005B::SUBDEVICE_80863510: return "RMS25PB080 RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_80863511: return "RMS25PB040 RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_80863512: return "RMT3PB080 RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_80863513: return "Integrated RAID Module RMS25CB080";
        case PciSubDevice1000005B::SUBDEVICE_80863514: return "RMS25CB040 RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_8086351C: return "RMS25PB080N RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_8086351D: return "RMS25CB080N RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_80869265: return "RS25DB080 RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_80869268: return "RS25AB080 RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_80869285: return "RS25NB008 RAID Controller";
        case PciSubDevice1000005B::SUBDEVICE_80869288: return "RS25SB008 RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005B_H
