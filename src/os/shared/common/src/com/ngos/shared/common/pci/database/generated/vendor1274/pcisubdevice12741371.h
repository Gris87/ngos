// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCISUBDEVICE12741371_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCISUBDEVICE12741371_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12741371: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110024 = 0x0E110024,
    SUBDEVICE_0E11B1A7 = 0x0E11B1A7,
    SUBDEVICE_103380AC = 0x103380AC,
    SUBDEVICE_10421854 = 0x10421854,
    SUBDEVICE_107B8054 = 0x107B8054,
    SUBDEVICE_12741371 = 0x12741371,
    SUBDEVICE_12748001 = 0x12748001,
    SUBDEVICE_14626470 = 0x14626470,
    SUBDEVICE_14626560 = 0x14626560,
    SUBDEVICE_14626630 = 0x14626630,
    SUBDEVICE_14626631 = 0x14626631,
    SUBDEVICE_14626632 = 0x14626632,
    SUBDEVICE_14626633 = 0x14626633,
    SUBDEVICE_14626820 = 0x14626820,
    SUBDEVICE_14626822 = 0x14626822,
    SUBDEVICE_14626830 = 0x14626830,
    SUBDEVICE_14626880 = 0x14626880,
    SUBDEVICE_14626900 = 0x14626900,
    SUBDEVICE_14626910 = 0x14626910,
    SUBDEVICE_14626930 = 0x14626930,
    SUBDEVICE_14626990 = 0x14626990,
    SUBDEVICE_14626991 = 0x14626991,
    SUBDEVICE_14A42077 = 0x14A42077,
    SUBDEVICE_14A42105 = 0x14A42105,
    SUBDEVICE_14A42107 = 0x14A42107,
    SUBDEVICE_14A42172 = 0x14A42172,
    SUBDEVICE_15099902 = 0x15099902,
    SUBDEVICE_15099903 = 0x15099903,
    SUBDEVICE_15099904 = 0x15099904,
    SUBDEVICE_15099905 = 0x15099905,
    SUBDEVICE_152D8801 = 0x152D8801,
    SUBDEVICE_152D8802 = 0x152D8802,
    SUBDEVICE_152D8803 = 0x152D8803,
    SUBDEVICE_152D8804 = 0x152D8804,
    SUBDEVICE_152D8805 = 0x152D8805,
    SUBDEVICE_270F2001 = 0x270F2001,
    SUBDEVICE_270F2200 = 0x270F2200,
    SUBDEVICE_270F3000 = 0x270F3000,
    SUBDEVICE_270F3100 = 0x270F3100,
    SUBDEVICE_270F3102 = 0x270F3102,
    SUBDEVICE_270F7060 = 0x270F7060,
    SUBDEVICE_80864249 = 0x80864249,
    SUBDEVICE_8086424C = 0x8086424C,
    SUBDEVICE_8086425A = 0x8086425A,
    SUBDEVICE_80864341 = 0x80864341,
    SUBDEVICE_80864343 = 0x80864343,
    SUBDEVICE_80864541 = 0x80864541,
    SUBDEVICE_80864649 = 0x80864649,
    SUBDEVICE_8086464A = 0x8086464A,
    SUBDEVICE_80864D4F = 0x80864D4F,
    SUBDEVICE_80864F43 = 0x80864F43,
    SUBDEVICE_80865243 = 0x80865243,
    SUBDEVICE_80865352 = 0x80865352,
    SUBDEVICE_80865643 = 0x80865643,
    SUBDEVICE_80865753 = 0x80865753
};



inline const char8* enumToString(PciSubDevice12741371 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12741371::NONE:               return "NONE";
        case PciSubDevice12741371::SUBDEVICE_0E110024: return "SUBDEVICE_0E110024";
        case PciSubDevice12741371::SUBDEVICE_0E11B1A7: return "SUBDEVICE_0E11B1A7";
        case PciSubDevice12741371::SUBDEVICE_103380AC: return "SUBDEVICE_103380AC";
        case PciSubDevice12741371::SUBDEVICE_10421854: return "SUBDEVICE_10421854";
        case PciSubDevice12741371::SUBDEVICE_107B8054: return "SUBDEVICE_107B8054";
        case PciSubDevice12741371::SUBDEVICE_12741371: return "SUBDEVICE_12741371";
        case PciSubDevice12741371::SUBDEVICE_12748001: return "SUBDEVICE_12748001";
        case PciSubDevice12741371::SUBDEVICE_14626470: return "SUBDEVICE_14626470";
        case PciSubDevice12741371::SUBDEVICE_14626560: return "SUBDEVICE_14626560";
        case PciSubDevice12741371::SUBDEVICE_14626630: return "SUBDEVICE_14626630";
        case PciSubDevice12741371::SUBDEVICE_14626631: return "SUBDEVICE_14626631";
        case PciSubDevice12741371::SUBDEVICE_14626632: return "SUBDEVICE_14626632";
        case PciSubDevice12741371::SUBDEVICE_14626633: return "SUBDEVICE_14626633";
        case PciSubDevice12741371::SUBDEVICE_14626820: return "SUBDEVICE_14626820";
        case PciSubDevice12741371::SUBDEVICE_14626822: return "SUBDEVICE_14626822";
        case PciSubDevice12741371::SUBDEVICE_14626830: return "SUBDEVICE_14626830";
        case PciSubDevice12741371::SUBDEVICE_14626880: return "SUBDEVICE_14626880";
        case PciSubDevice12741371::SUBDEVICE_14626900: return "SUBDEVICE_14626900";
        case PciSubDevice12741371::SUBDEVICE_14626910: return "SUBDEVICE_14626910";
        case PciSubDevice12741371::SUBDEVICE_14626930: return "SUBDEVICE_14626930";
        case PciSubDevice12741371::SUBDEVICE_14626990: return "SUBDEVICE_14626990";
        case PciSubDevice12741371::SUBDEVICE_14626991: return "SUBDEVICE_14626991";
        case PciSubDevice12741371::SUBDEVICE_14A42077: return "SUBDEVICE_14A42077";
        case PciSubDevice12741371::SUBDEVICE_14A42105: return "SUBDEVICE_14A42105";
        case PciSubDevice12741371::SUBDEVICE_14A42107: return "SUBDEVICE_14A42107";
        case PciSubDevice12741371::SUBDEVICE_14A42172: return "SUBDEVICE_14A42172";
        case PciSubDevice12741371::SUBDEVICE_15099902: return "SUBDEVICE_15099902";
        case PciSubDevice12741371::SUBDEVICE_15099903: return "SUBDEVICE_15099903";
        case PciSubDevice12741371::SUBDEVICE_15099904: return "SUBDEVICE_15099904";
        case PciSubDevice12741371::SUBDEVICE_15099905: return "SUBDEVICE_15099905";
        case PciSubDevice12741371::SUBDEVICE_152D8801: return "SUBDEVICE_152D8801";
        case PciSubDevice12741371::SUBDEVICE_152D8802: return "SUBDEVICE_152D8802";
        case PciSubDevice12741371::SUBDEVICE_152D8803: return "SUBDEVICE_152D8803";
        case PciSubDevice12741371::SUBDEVICE_152D8804: return "SUBDEVICE_152D8804";
        case PciSubDevice12741371::SUBDEVICE_152D8805: return "SUBDEVICE_152D8805";
        case PciSubDevice12741371::SUBDEVICE_270F2001: return "SUBDEVICE_270F2001";
        case PciSubDevice12741371::SUBDEVICE_270F2200: return "SUBDEVICE_270F2200";
        case PciSubDevice12741371::SUBDEVICE_270F3000: return "SUBDEVICE_270F3000";
        case PciSubDevice12741371::SUBDEVICE_270F3100: return "SUBDEVICE_270F3100";
        case PciSubDevice12741371::SUBDEVICE_270F3102: return "SUBDEVICE_270F3102";
        case PciSubDevice12741371::SUBDEVICE_270F7060: return "SUBDEVICE_270F7060";
        case PciSubDevice12741371::SUBDEVICE_80864249: return "SUBDEVICE_80864249";
        case PciSubDevice12741371::SUBDEVICE_8086424C: return "SUBDEVICE_8086424C";
        case PciSubDevice12741371::SUBDEVICE_8086425A: return "SUBDEVICE_8086425A";
        case PciSubDevice12741371::SUBDEVICE_80864341: return "SUBDEVICE_80864341";
        case PciSubDevice12741371::SUBDEVICE_80864343: return "SUBDEVICE_80864343";
        case PciSubDevice12741371::SUBDEVICE_80864541: return "SUBDEVICE_80864541";
        case PciSubDevice12741371::SUBDEVICE_80864649: return "SUBDEVICE_80864649";
        case PciSubDevice12741371::SUBDEVICE_8086464A: return "SUBDEVICE_8086464A";
        case PciSubDevice12741371::SUBDEVICE_80864D4F: return "SUBDEVICE_80864D4F";
        case PciSubDevice12741371::SUBDEVICE_80864F43: return "SUBDEVICE_80864F43";
        case PciSubDevice12741371::SUBDEVICE_80865243: return "SUBDEVICE_80865243";
        case PciSubDevice12741371::SUBDEVICE_80865352: return "SUBDEVICE_80865352";
        case PciSubDevice12741371::SUBDEVICE_80865643: return "SUBDEVICE_80865643";
        case PciSubDevice12741371::SUBDEVICE_80865753: return "SUBDEVICE_80865753";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12741371 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12741371 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12741371::SUBDEVICE_0E110024: return "AudioPCI on Motherboard Compaq Deskpro";
        case PciSubDevice12741371::SUBDEVICE_0E11B1A7: return "ES1371, ES1373 AudioPCI";
        case PciSubDevice12741371::SUBDEVICE_103380AC: return "ES1371, ES1373 AudioPCI";
        case PciSubDevice12741371::SUBDEVICE_10421854: return "Tazer";
        case PciSubDevice12741371::SUBDEVICE_107B8054: return "Tabor2";
        case PciSubDevice12741371::SUBDEVICE_12741371: return "Audio PCI 64V/128/5200 / Creative CT4810/CT5803/CT5806 [Sound Blaster PCI]";
        case PciSubDevice12741371::SUBDEVICE_12748001: return "CT4751 board";
        case PciSubDevice12741371::SUBDEVICE_14626470: return "ES1371, ES1373 AudioPCI On Motherboard MS-6147 1.1A";
        case PciSubDevice12741371::SUBDEVICE_14626560: return "ES1371, ES1373 AudioPCI On Motherboard MS-6156 1.10";
        case PciSubDevice12741371::SUBDEVICE_14626630: return "ES1371, ES1373 AudioPCI On Motherboard MS-6163BX 1.0A";
        case PciSubDevice12741371::SUBDEVICE_14626631: return "ES1371, ES1373 AudioPCI On Motherboard MS-6163VIA 1.0A";
        case PciSubDevice12741371::SUBDEVICE_14626632: return "ES1371, ES1373 AudioPCI On Motherboard MS-6163BX 2.0A";
        case PciSubDevice12741371::SUBDEVICE_14626633: return "ES1371, ES1373 AudioPCI On Motherboard MS-6163VIA 2.0A";
        case PciSubDevice12741371::SUBDEVICE_14626820: return "ES1371, ES1373 AudioPCI On Motherboard MS-6182 1.00";
        case PciSubDevice12741371::SUBDEVICE_14626822: return "ES1371, ES1373 AudioPCI On Motherboard MS-6182 1.00A";
        case PciSubDevice12741371::SUBDEVICE_14626830: return "ES1371, ES1373 AudioPCI On Motherboard MS-6183 1.00";
        case PciSubDevice12741371::SUBDEVICE_14626880: return "ES1371, ES1373 AudioPCI On Motherboard MS-6188 1.00";
        case PciSubDevice12741371::SUBDEVICE_14626900: return "ES1371, ES1373 AudioPCI On Motherboard MS-6190 1.00";
        case PciSubDevice12741371::SUBDEVICE_14626910: return "ES1371, ES1373 AudioPCI On Motherboard MS-6191";
        case PciSubDevice12741371::SUBDEVICE_14626930: return "ES1371, ES1373 AudioPCI On Motherboard MS-6193";
        case PciSubDevice12741371::SUBDEVICE_14626990: return "ES1371, ES1373 AudioPCI On Motherboard MS-6199BX 2.0A";
        case PciSubDevice12741371::SUBDEVICE_14626991: return "ES1371, ES1373 AudioPCI On Motherboard MS-6199VIA 2.0A";
        case PciSubDevice12741371::SUBDEVICE_14A42077: return "ES1371, ES1373 AudioPCI On Motherboard KR639";
        case PciSubDevice12741371::SUBDEVICE_14A42105: return "ES1371, ES1373 AudioPCI On Motherboard MR800";
        case PciSubDevice12741371::SUBDEVICE_14A42107: return "ES1371, ES1373 AudioPCI On Motherboard MR801";
        case PciSubDevice12741371::SUBDEVICE_14A42172: return "ES1371, ES1373 AudioPCI On Motherboard DR739";
        case PciSubDevice12741371::SUBDEVICE_15099902: return "ES1371, ES1373 AudioPCI On Motherboard KW11";
        case PciSubDevice12741371::SUBDEVICE_15099903: return "ES1371, ES1373 AudioPCI On Motherboard KW31";
        case PciSubDevice12741371::SUBDEVICE_15099904: return "ES1371, ES1373 AudioPCI On Motherboard KA11";
        case PciSubDevice12741371::SUBDEVICE_15099905: return "ES1371, ES1373 AudioPCI On Motherboard KC13";
        case PciSubDevice12741371::SUBDEVICE_152D8801: return "ES1371, ES1373 AudioPCI On Motherboard CP810E";
        case PciSubDevice12741371::SUBDEVICE_152D8802: return "ES1371, ES1373 AudioPCI On Motherboard CP810";
        case PciSubDevice12741371::SUBDEVICE_152D8803: return "ES1371, ES1373 AudioPCI On Motherboard P3810E";
        case PciSubDevice12741371::SUBDEVICE_152D8804: return "ES1371, ES1373 AudioPCI On Motherboard P3810-S";
        case PciSubDevice12741371::SUBDEVICE_152D8805: return "ES1371, ES1373 AudioPCI On Motherboard P3820-S";
        case PciSubDevice12741371::SUBDEVICE_270F2001: return "ES1371, ES1373 AudioPCI On Motherboard 6CTR";
        case PciSubDevice12741371::SUBDEVICE_270F2200: return "ES1371, ES1373 AudioPCI On Motherboard 6WTX";
        case PciSubDevice12741371::SUBDEVICE_270F3000: return "ES1371, ES1373 AudioPCI On Motherboard 6WSV";
        case PciSubDevice12741371::SUBDEVICE_270F3100: return "ES1371, ES1373 AudioPCI On Motherboard 6WIV2";
        case PciSubDevice12741371::SUBDEVICE_270F3102: return "ES1371, ES1373 AudioPCI On Motherboard 6WIV";
        case PciSubDevice12741371::SUBDEVICE_270F7060: return "ES1371, ES1373 AudioPCI On Motherboard 6ASA2";
        case PciSubDevice12741371::SUBDEVICE_80864249: return "ES1371, ES1373 AudioPCI On Motherboard BI440ZX";
        case PciSubDevice12741371::SUBDEVICE_8086424C: return "ES1371, ES1373 AudioPCI On Motherboard BL440ZX";
        case PciSubDevice12741371::SUBDEVICE_8086425A: return "ES1371, ES1373 AudioPCI On Motherboard BZ440ZX";
        case PciSubDevice12741371::SUBDEVICE_80864341: return "ES1371, ES1373 AudioPCI On Motherboard Cayman";
        case PciSubDevice12741371::SUBDEVICE_80864343: return "ES1371, ES1373 AudioPCI On Motherboard Cape Cod";
        case PciSubDevice12741371::SUBDEVICE_80864541: return "D815EEA Motherboard";
        case PciSubDevice12741371::SUBDEVICE_80864649: return "ES1371, ES1373 AudioPCI On Motherboard Fire Island";
        case PciSubDevice12741371::SUBDEVICE_8086464A: return "ES1371, ES1373 AudioPCI On Motherboard FJ440ZX";
        case PciSubDevice12741371::SUBDEVICE_80864D4F: return "ES1371, ES1373 AudioPCI On Motherboard Montreal";
        case PciSubDevice12741371::SUBDEVICE_80864F43: return "ES1371, ES1373 AudioPCI On Motherboard OC440LX";
        case PciSubDevice12741371::SUBDEVICE_80865243: return "ES1371, ES1373 AudioPCI On Motherboard RC440BX";
        case PciSubDevice12741371::SUBDEVICE_80865352: return "ES1371, ES1373 AudioPCI On Motherboard SunRiver";
        case PciSubDevice12741371::SUBDEVICE_80865643: return "ES1371, ES1373 AudioPCI On Motherboard Vancouver";
        case PciSubDevice12741371::SUBDEVICE_80865753: return "ES1371, ES1373 AudioPCI On Motherboard WS440BX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCISUBDEVICE12741371_H
