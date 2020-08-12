// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCIDEVICE14E4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCIDEVICE14E4_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14E4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0576 = 0x0576,
    DEVICE_0800 = 0x0800,
    DEVICE_0804 = 0x0804,
    DEVICE_0805 = 0x0805,
    DEVICE_0806 = 0x0806,
    DEVICE_080B = 0x080B,
    DEVICE_080F = 0x080F,
    DEVICE_0811 = 0x0811,
    DEVICE_0816 = 0x0816,
    DEVICE_1570 = 0x1570,
    DEVICE_1600 = 0x1600,
    DEVICE_1601 = 0x1601,
    DEVICE_1604 = 0x1604,
    DEVICE_1605 = 0x1605,
    DEVICE_1606 = 0x1606,
    DEVICE_1609 = 0x1609,
    DEVICE_1612 = 0x1612,
    DEVICE_1614 = 0x1614,
    DEVICE_1615 = 0x1615,
    DEVICE_1639 = 0x1639,
    DEVICE_163A = 0x163A,
    DEVICE_163B = 0x163B,
    DEVICE_163C = 0x163C,
    DEVICE_163D = 0x163D,
    DEVICE_163E = 0x163E,
    DEVICE_163F = 0x163F,
    DEVICE_1641 = 0x1641,
    DEVICE_1642 = 0x1642,
    DEVICE_1643 = 0x1643,
    DEVICE_1644 = 0x1644,
    DEVICE_1645 = 0x1645,
    DEVICE_1646 = 0x1646,
    DEVICE_1647 = 0x1647,
    DEVICE_1648 = 0x1648,
    DEVICE_1649 = 0x1649,
    DEVICE_164A = 0x164A,
    DEVICE_164C = 0x164C,
    DEVICE_164D = 0x164D,
    DEVICE_164E = 0x164E,
    DEVICE_164F = 0x164F,
    DEVICE_1650 = 0x1650,
    DEVICE_1653 = 0x1653,
    DEVICE_1654 = 0x1654,
    DEVICE_1655 = 0x1655,
    DEVICE_1656 = 0x1656,
    DEVICE_1657 = 0x1657,
    DEVICE_1659 = 0x1659,
    DEVICE_165A = 0x165A,
    DEVICE_165B = 0x165B,
    DEVICE_165C = 0x165C,
    DEVICE_165D = 0x165D,
    DEVICE_165E = 0x165E,
    DEVICE_165F = 0x165F,
    DEVICE_1662 = 0x1662,
    DEVICE_1663 = 0x1663,
    DEVICE_1665 = 0x1665,
    DEVICE_1668 = 0x1668,
    DEVICE_1669 = 0x1669,
    DEVICE_166A = 0x166A,
    DEVICE_166B = 0x166B,
    DEVICE_166E = 0x166E,
    DEVICE_166F = 0x166F,
    DEVICE_1672 = 0x1672,
    DEVICE_1673 = 0x1673,
    DEVICE_1674 = 0x1674,
    DEVICE_1677 = 0x1677,
    DEVICE_1678 = 0x1678,
    DEVICE_1679 = 0x1679,
    DEVICE_167A = 0x167A,
    DEVICE_167B = 0x167B,
    DEVICE_167D = 0x167D,
    DEVICE_167E = 0x167E,
    DEVICE_167F = 0x167F,
    DEVICE_1680 = 0x1680,
    DEVICE_1681 = 0x1681,
    DEVICE_1682 = 0x1682,
    DEVICE_1683 = 0x1683,
    DEVICE_1684 = 0x1684,
    DEVICE_1685 = 0x1685,
    DEVICE_1686 = 0x1686,
    DEVICE_1687 = 0x1687,
    DEVICE_1688 = 0x1688,
    DEVICE_168A = 0x168A,
    DEVICE_168D = 0x168D,
    DEVICE_168E = 0x168E,
    DEVICE_1690 = 0x1690,
    DEVICE_1691 = 0x1691,
    DEVICE_1692 = 0x1692,
    DEVICE_1693 = 0x1693,
    DEVICE_1694 = 0x1694,
    DEVICE_1696 = 0x1696,
    DEVICE_1698 = 0x1698,
    DEVICE_1699 = 0x1699,
    DEVICE_169A = 0x169A,
    DEVICE_169B = 0x169B,
    DEVICE_169C = 0x169C,
    DEVICE_169D = 0x169D,
    DEVICE_16A0 = 0x16A0,
    DEVICE_16A1 = 0x16A1,
    DEVICE_16A2 = 0x16A2,
    DEVICE_16A3 = 0x16A3,
    DEVICE_16A4 = 0x16A4,
    DEVICE_16A5 = 0x16A5,
    DEVICE_16A6 = 0x16A6,
    DEVICE_16A7 = 0x16A7,
    DEVICE_16A8 = 0x16A8,
    DEVICE_16A9 = 0x16A9,
    DEVICE_16AA = 0x16AA,
    DEVICE_16AB = 0x16AB,
    DEVICE_16AC = 0x16AC,
    DEVICE_16AD = 0x16AD,
    DEVICE_16AE = 0x16AE,
    DEVICE_16AF = 0x16AF,
    DEVICE_16B0 = 0x16B0,
    DEVICE_16B1 = 0x16B1,
    DEVICE_16B2 = 0x16B2,
    DEVICE_16B3 = 0x16B3,
    DEVICE_16B4 = 0x16B4,
    DEVICE_16B5 = 0x16B5,
    DEVICE_16B6 = 0x16B6,
    DEVICE_16B7 = 0x16B7,
    DEVICE_16BC = 0x16BC,
    DEVICE_16BE = 0x16BE,
    DEVICE_16BF = 0x16BF,
    DEVICE_16C1 = 0x16C1,
    DEVICE_16C6 = 0x16C6,
    DEVICE_16C7 = 0x16C7,
    DEVICE_16C8 = 0x16C8,
    DEVICE_16C9 = 0x16C9,
    DEVICE_16CA = 0x16CA,
    DEVICE_16CB = 0x16CB,
    DEVICE_16CC = 0x16CC,
    DEVICE_16CE = 0x16CE,
    DEVICE_16CF = 0x16CF,
    DEVICE_16D0 = 0x16D0,
    DEVICE_16D1 = 0x16D1,
    DEVICE_16D2 = 0x16D2,
    DEVICE_16D3 = 0x16D3,
    DEVICE_16D4 = 0x16D4,
    DEVICE_16D5 = 0x16D5,
    DEVICE_16D6 = 0x16D6,
    DEVICE_16D7 = 0x16D7,
    DEVICE_16D8 = 0x16D8,
    DEVICE_16D9 = 0x16D9,
    DEVICE_16DC = 0x16DC,
    DEVICE_16DD = 0x16DD,
    DEVICE_16DE = 0x16DE,
    DEVICE_16DF = 0x16DF,
    DEVICE_16E1 = 0x16E1,
    DEVICE_16E2 = 0x16E2,
    DEVICE_16E3 = 0x16E3,
    DEVICE_16E5 = 0x16E5,
    DEVICE_16E7 = 0x16E7,
    DEVICE_16E8 = 0x16E8,
    DEVICE_16E9 = 0x16E9,
    DEVICE_16EC = 0x16EC,
    DEVICE_16ED = 0x16ED,
    DEVICE_16EE = 0x16EE,
    DEVICE_16EF = 0x16EF,
    DEVICE_16F1 = 0x16F1,
    DEVICE_16F3 = 0x16F3,
    DEVICE_16F7 = 0x16F7,
    DEVICE_16FD = 0x16FD,
    DEVICE_16FE = 0x16FE,
    DEVICE_170C = 0x170C,
    DEVICE_170D = 0x170D,
    DEVICE_170E = 0x170E,
    DEVICE_1712 = 0x1712,
    DEVICE_1713 = 0x1713,
    DEVICE_1750 = 0x1750,
    DEVICE_1751 = 0x1751,
    DEVICE_1752 = 0x1752,
    DEVICE_1806 = 0x1806,
    DEVICE_1807 = 0x1807,
    DEVICE_3352 = 0x3352,
    DEVICE_3360 = 0x3360,
    DEVICE_4210 = 0x4210,
    DEVICE_4211 = 0x4211,
    DEVICE_4212 = 0x4212,
    DEVICE_4220 = 0x4220,
    DEVICE_4222 = 0x4222,
    DEVICE_4301 = 0x4301,
    DEVICE_4305 = 0x4305,
    DEVICE_4306 = 0x4306,
    DEVICE_4307 = 0x4307,
    DEVICE_4310 = 0x4310,
    DEVICE_4311 = 0x4311,
    DEVICE_4312 = 0x4312,
    DEVICE_4313 = 0x4313,
    DEVICE_4315 = 0x4315,
    DEVICE_4318 = 0x4318,
    DEVICE_4319 = 0x4319,
    DEVICE_4320 = 0x4320,
    DEVICE_4321 = 0x4321,
    DEVICE_4322 = 0x4322,
    DEVICE_4324 = 0x4324,
    DEVICE_4325 = 0x4325,
    DEVICE_4326 = 0x4326,
    DEVICE_4328 = 0x4328,
    DEVICE_4329 = 0x4329,
    DEVICE_432A = 0x432A,
    DEVICE_432B = 0x432B,
    DEVICE_432C = 0x432C,
    DEVICE_432D = 0x432D,
    DEVICE_4331 = 0x4331,
    DEVICE_4333 = 0x4333,
    DEVICE_4344 = 0x4344,
    DEVICE_4350 = 0x4350,
    DEVICE_4351 = 0x4351,
    DEVICE_4353 = 0x4353,
    DEVICE_4357 = 0x4357,
    DEVICE_4358 = 0x4358,
    DEVICE_4359 = 0x4359,
    DEVICE_4360 = 0x4360,
    DEVICE_4365 = 0x4365,
    DEVICE_43A0 = 0x43A0,
    DEVICE_43A1 = 0x43A1,
    DEVICE_43A2 = 0x43A2,
    DEVICE_43A3 = 0x43A3,
    DEVICE_43A9 = 0x43A9,
    DEVICE_43AA = 0x43AA,
    DEVICE_43AE = 0x43AE,
    DEVICE_43B1 = 0x43B1,
    DEVICE_43BA = 0x43BA,
    DEVICE_43BB = 0x43BB,
    DEVICE_43BC = 0x43BC,
    DEVICE_43D3 = 0x43D3,
    DEVICE_43D9 = 0x43D9,
    DEVICE_43DC = 0x43DC,
    DEVICE_43DF = 0x43DF,
    DEVICE_43E9 = 0x43E9,
    DEVICE_43EC = 0x43EC,
    DEVICE_4401 = 0x4401,
    DEVICE_4402 = 0x4402,
    DEVICE_4403 = 0x4403,
    DEVICE_4410 = 0x4410,
    DEVICE_4411 = 0x4411,
    DEVICE_4412 = 0x4412,
    DEVICE_4430 = 0x4430,
    DEVICE_4432 = 0x4432,
    DEVICE_4464 = 0x4464,
    DEVICE_4488 = 0x4488,
    DEVICE_4610 = 0x4610,
    DEVICE_4611 = 0x4611,
    DEVICE_4612 = 0x4612,
    DEVICE_4613 = 0x4613,
    DEVICE_4614 = 0x4614,
    DEVICE_4615 = 0x4615,
    DEVICE_4704 = 0x4704,
    DEVICE_4705 = 0x4705,
    DEVICE_4706 = 0x4706,
    DEVICE_4707 = 0x4707,
    DEVICE_4708 = 0x4708,
    DEVICE_4710 = 0x4710,
    DEVICE_4711 = 0x4711,
    DEVICE_4712 = 0x4712,
    DEVICE_4713 = 0x4713,
    DEVICE_4714 = 0x4714,
    DEVICE_4715 = 0x4715,
    DEVICE_4716 = 0x4716,
    DEVICE_4717 = 0x4717,
    DEVICE_4718 = 0x4718,
    DEVICE_4719 = 0x4719,
    DEVICE_4720 = 0x4720,
    DEVICE_4727 = 0x4727,
    DEVICE_5365 = 0x5365,
    DEVICE_5600 = 0x5600,
    DEVICE_5605 = 0x5605,
    DEVICE_5615 = 0x5615,
    DEVICE_5625 = 0x5625,
    DEVICE_5645 = 0x5645,
    DEVICE_5670 = 0x5670,
    DEVICE_5680 = 0x5680,
    DEVICE_5690 = 0x5690,
    DEVICE_5691 = 0x5691,
    DEVICE_5692 = 0x5692,
    DEVICE_5695 = 0x5695,
    DEVICE_5698 = 0x5698,
    DEVICE_5820 = 0x5820,
    DEVICE_5821 = 0x5821,
    DEVICE_5822 = 0x5822,
    DEVICE_5823 = 0x5823,
    DEVICE_5824 = 0x5824,
    DEVICE_5840 = 0x5840,
    DEVICE_5841 = 0x5841,
    DEVICE_5850 = 0x5850,
    DEVICE_5E87 = 0x5E87,
    DEVICE_5E88 = 0x5E88,
    DEVICE_8602 = 0x8602,
    DEVICE_9026 = 0x9026,
    DEVICE_9027 = 0x9027,
    DEVICE_A8D8 = 0xA8D8,
    DEVICE_AA52 = 0xAA52,
    DEVICE_B302 = 0xB302,
    DEVICE_B334 = 0xB334,
    DEVICE_B370 = 0xB370,
    DEVICE_B371 = 0xB371,
    DEVICE_B372 = 0xB372,
    DEVICE_B375 = 0xB375,
    DEVICE_B376 = 0xB376,
    DEVICE_B377 = 0xB377,
    DEVICE_B379 = 0xB379,
    DEVICE_B470 = 0xB470,
    DEVICE_B471 = 0xB471,
    DEVICE_B472 = 0xB472,
    DEVICE_B800 = 0xB800,
    DEVICE_B842 = 0xB842,
    DEVICE_B850 = 0xB850,
    DEVICE_B880 = 0xB880,
    DEVICE_B960 = 0xB960,
    DEVICE_B990 = 0xB990,
    DEVICE_D802 = 0xD802,
    DEVICE_D804 = 0xD804
};



inline const char8* enumToString(PciDevice14E4 device14E4) // TEST: NO
{
    // COMMON_LT((" | device14E4 = %u", device14E4)); // Commented to avoid bad looking logs



    switch (device14E4)
    {
        case PciDevice14E4::NONE:        return "NONE";
        case PciDevice14E4::DEVICE_0576: return "DEVICE_0576";
        case PciDevice14E4::DEVICE_0800: return "DEVICE_0800";
        case PciDevice14E4::DEVICE_0804: return "DEVICE_0804";
        case PciDevice14E4::DEVICE_0805: return "DEVICE_0805";
        case PciDevice14E4::DEVICE_0806: return "DEVICE_0806";
        case PciDevice14E4::DEVICE_080B: return "DEVICE_080B";
        case PciDevice14E4::DEVICE_080F: return "DEVICE_080F";
        case PciDevice14E4::DEVICE_0811: return "DEVICE_0811";
        case PciDevice14E4::DEVICE_0816: return "DEVICE_0816";
        case PciDevice14E4::DEVICE_1570: return "DEVICE_1570";
        case PciDevice14E4::DEVICE_1600: return "DEVICE_1600";
        case PciDevice14E4::DEVICE_1601: return "DEVICE_1601";
        case PciDevice14E4::DEVICE_1604: return "DEVICE_1604";
        case PciDevice14E4::DEVICE_1605: return "DEVICE_1605";
        case PciDevice14E4::DEVICE_1606: return "DEVICE_1606";
        case PciDevice14E4::DEVICE_1609: return "DEVICE_1609";
        case PciDevice14E4::DEVICE_1612: return "DEVICE_1612";
        case PciDevice14E4::DEVICE_1614: return "DEVICE_1614";
        case PciDevice14E4::DEVICE_1615: return "DEVICE_1615";
        case PciDevice14E4::DEVICE_1639: return "DEVICE_1639";
        case PciDevice14E4::DEVICE_163A: return "DEVICE_163A";
        case PciDevice14E4::DEVICE_163B: return "DEVICE_163B";
        case PciDevice14E4::DEVICE_163C: return "DEVICE_163C";
        case PciDevice14E4::DEVICE_163D: return "DEVICE_163D";
        case PciDevice14E4::DEVICE_163E: return "DEVICE_163E";
        case PciDevice14E4::DEVICE_163F: return "DEVICE_163F";
        case PciDevice14E4::DEVICE_1641: return "DEVICE_1641";
        case PciDevice14E4::DEVICE_1642: return "DEVICE_1642";
        case PciDevice14E4::DEVICE_1643: return "DEVICE_1643";
        case PciDevice14E4::DEVICE_1644: return "DEVICE_1644";
        case PciDevice14E4::DEVICE_1645: return "DEVICE_1645";
        case PciDevice14E4::DEVICE_1646: return "DEVICE_1646";
        case PciDevice14E4::DEVICE_1647: return "DEVICE_1647";
        case PciDevice14E4::DEVICE_1648: return "DEVICE_1648";
        case PciDevice14E4::DEVICE_1649: return "DEVICE_1649";
        case PciDevice14E4::DEVICE_164A: return "DEVICE_164A";
        case PciDevice14E4::DEVICE_164C: return "DEVICE_164C";
        case PciDevice14E4::DEVICE_164D: return "DEVICE_164D";
        case PciDevice14E4::DEVICE_164E: return "DEVICE_164E";
        case PciDevice14E4::DEVICE_164F: return "DEVICE_164F";
        case PciDevice14E4::DEVICE_1650: return "DEVICE_1650";
        case PciDevice14E4::DEVICE_1653: return "DEVICE_1653";
        case PciDevice14E4::DEVICE_1654: return "DEVICE_1654";
        case PciDevice14E4::DEVICE_1655: return "DEVICE_1655";
        case PciDevice14E4::DEVICE_1656: return "DEVICE_1656";
        case PciDevice14E4::DEVICE_1657: return "DEVICE_1657";
        case PciDevice14E4::DEVICE_1659: return "DEVICE_1659";
        case PciDevice14E4::DEVICE_165A: return "DEVICE_165A";
        case PciDevice14E4::DEVICE_165B: return "DEVICE_165B";
        case PciDevice14E4::DEVICE_165C: return "DEVICE_165C";
        case PciDevice14E4::DEVICE_165D: return "DEVICE_165D";
        case PciDevice14E4::DEVICE_165E: return "DEVICE_165E";
        case PciDevice14E4::DEVICE_165F: return "DEVICE_165F";
        case PciDevice14E4::DEVICE_1662: return "DEVICE_1662";
        case PciDevice14E4::DEVICE_1663: return "DEVICE_1663";
        case PciDevice14E4::DEVICE_1665: return "DEVICE_1665";
        case PciDevice14E4::DEVICE_1668: return "DEVICE_1668";
        case PciDevice14E4::DEVICE_1669: return "DEVICE_1669";
        case PciDevice14E4::DEVICE_166A: return "DEVICE_166A";
        case PciDevice14E4::DEVICE_166B: return "DEVICE_166B";
        case PciDevice14E4::DEVICE_166E: return "DEVICE_166E";
        case PciDevice14E4::DEVICE_166F: return "DEVICE_166F";
        case PciDevice14E4::DEVICE_1672: return "DEVICE_1672";
        case PciDevice14E4::DEVICE_1673: return "DEVICE_1673";
        case PciDevice14E4::DEVICE_1674: return "DEVICE_1674";
        case PciDevice14E4::DEVICE_1677: return "DEVICE_1677";
        case PciDevice14E4::DEVICE_1678: return "DEVICE_1678";
        case PciDevice14E4::DEVICE_1679: return "DEVICE_1679";
        case PciDevice14E4::DEVICE_167A: return "DEVICE_167A";
        case PciDevice14E4::DEVICE_167B: return "DEVICE_167B";
        case PciDevice14E4::DEVICE_167D: return "DEVICE_167D";
        case PciDevice14E4::DEVICE_167E: return "DEVICE_167E";
        case PciDevice14E4::DEVICE_167F: return "DEVICE_167F";
        case PciDevice14E4::DEVICE_1680: return "DEVICE_1680";
        case PciDevice14E4::DEVICE_1681: return "DEVICE_1681";
        case PciDevice14E4::DEVICE_1682: return "DEVICE_1682";
        case PciDevice14E4::DEVICE_1683: return "DEVICE_1683";
        case PciDevice14E4::DEVICE_1684: return "DEVICE_1684";
        case PciDevice14E4::DEVICE_1685: return "DEVICE_1685";
        case PciDevice14E4::DEVICE_1686: return "DEVICE_1686";
        case PciDevice14E4::DEVICE_1687: return "DEVICE_1687";
        case PciDevice14E4::DEVICE_1688: return "DEVICE_1688";
        case PciDevice14E4::DEVICE_168A: return "DEVICE_168A";
        case PciDevice14E4::DEVICE_168D: return "DEVICE_168D";
        case PciDevice14E4::DEVICE_168E: return "DEVICE_168E";
        case PciDevice14E4::DEVICE_1690: return "DEVICE_1690";
        case PciDevice14E4::DEVICE_1691: return "DEVICE_1691";
        case PciDevice14E4::DEVICE_1692: return "DEVICE_1692";
        case PciDevice14E4::DEVICE_1693: return "DEVICE_1693";
        case PciDevice14E4::DEVICE_1694: return "DEVICE_1694";
        case PciDevice14E4::DEVICE_1696: return "DEVICE_1696";
        case PciDevice14E4::DEVICE_1698: return "DEVICE_1698";
        case PciDevice14E4::DEVICE_1699: return "DEVICE_1699";
        case PciDevice14E4::DEVICE_169A: return "DEVICE_169A";
        case PciDevice14E4::DEVICE_169B: return "DEVICE_169B";
        case PciDevice14E4::DEVICE_169C: return "DEVICE_169C";
        case PciDevice14E4::DEVICE_169D: return "DEVICE_169D";
        case PciDevice14E4::DEVICE_16A0: return "DEVICE_16A0";
        case PciDevice14E4::DEVICE_16A1: return "DEVICE_16A1";
        case PciDevice14E4::DEVICE_16A2: return "DEVICE_16A2";
        case PciDevice14E4::DEVICE_16A3: return "DEVICE_16A3";
        case PciDevice14E4::DEVICE_16A4: return "DEVICE_16A4";
        case PciDevice14E4::DEVICE_16A5: return "DEVICE_16A5";
        case PciDevice14E4::DEVICE_16A6: return "DEVICE_16A6";
        case PciDevice14E4::DEVICE_16A7: return "DEVICE_16A7";
        case PciDevice14E4::DEVICE_16A8: return "DEVICE_16A8";
        case PciDevice14E4::DEVICE_16A9: return "DEVICE_16A9";
        case PciDevice14E4::DEVICE_16AA: return "DEVICE_16AA";
        case PciDevice14E4::DEVICE_16AB: return "DEVICE_16AB";
        case PciDevice14E4::DEVICE_16AC: return "DEVICE_16AC";
        case PciDevice14E4::DEVICE_16AD: return "DEVICE_16AD";
        case PciDevice14E4::DEVICE_16AE: return "DEVICE_16AE";
        case PciDevice14E4::DEVICE_16AF: return "DEVICE_16AF";
        case PciDevice14E4::DEVICE_16B0: return "DEVICE_16B0";
        case PciDevice14E4::DEVICE_16B1: return "DEVICE_16B1";
        case PciDevice14E4::DEVICE_16B2: return "DEVICE_16B2";
        case PciDevice14E4::DEVICE_16B3: return "DEVICE_16B3";
        case PciDevice14E4::DEVICE_16B4: return "DEVICE_16B4";
        case PciDevice14E4::DEVICE_16B5: return "DEVICE_16B5";
        case PciDevice14E4::DEVICE_16B6: return "DEVICE_16B6";
        case PciDevice14E4::DEVICE_16B7: return "DEVICE_16B7";
        case PciDevice14E4::DEVICE_16BC: return "DEVICE_16BC";
        case PciDevice14E4::DEVICE_16BE: return "DEVICE_16BE";
        case PciDevice14E4::DEVICE_16BF: return "DEVICE_16BF";
        case PciDevice14E4::DEVICE_16C1: return "DEVICE_16C1";
        case PciDevice14E4::DEVICE_16C6: return "DEVICE_16C6";
        case PciDevice14E4::DEVICE_16C7: return "DEVICE_16C7";
        case PciDevice14E4::DEVICE_16C8: return "DEVICE_16C8";
        case PciDevice14E4::DEVICE_16C9: return "DEVICE_16C9";
        case PciDevice14E4::DEVICE_16CA: return "DEVICE_16CA";
        case PciDevice14E4::DEVICE_16CB: return "DEVICE_16CB";
        case PciDevice14E4::DEVICE_16CC: return "DEVICE_16CC";
        case PciDevice14E4::DEVICE_16CE: return "DEVICE_16CE";
        case PciDevice14E4::DEVICE_16CF: return "DEVICE_16CF";
        case PciDevice14E4::DEVICE_16D0: return "DEVICE_16D0";
        case PciDevice14E4::DEVICE_16D1: return "DEVICE_16D1";
        case PciDevice14E4::DEVICE_16D2: return "DEVICE_16D2";
        case PciDevice14E4::DEVICE_16D3: return "DEVICE_16D3";
        case PciDevice14E4::DEVICE_16D4: return "DEVICE_16D4";
        case PciDevice14E4::DEVICE_16D5: return "DEVICE_16D5";
        case PciDevice14E4::DEVICE_16D6: return "DEVICE_16D6";
        case PciDevice14E4::DEVICE_16D7: return "DEVICE_16D7";
        case PciDevice14E4::DEVICE_16D8: return "DEVICE_16D8";
        case PciDevice14E4::DEVICE_16D9: return "DEVICE_16D9";
        case PciDevice14E4::DEVICE_16DC: return "DEVICE_16DC";
        case PciDevice14E4::DEVICE_16DD: return "DEVICE_16DD";
        case PciDevice14E4::DEVICE_16DE: return "DEVICE_16DE";
        case PciDevice14E4::DEVICE_16DF: return "DEVICE_16DF";
        case PciDevice14E4::DEVICE_16E1: return "DEVICE_16E1";
        case PciDevice14E4::DEVICE_16E2: return "DEVICE_16E2";
        case PciDevice14E4::DEVICE_16E3: return "DEVICE_16E3";
        case PciDevice14E4::DEVICE_16E5: return "DEVICE_16E5";
        case PciDevice14E4::DEVICE_16E7: return "DEVICE_16E7";
        case PciDevice14E4::DEVICE_16E8: return "DEVICE_16E8";
        case PciDevice14E4::DEVICE_16E9: return "DEVICE_16E9";
        case PciDevice14E4::DEVICE_16EC: return "DEVICE_16EC";
        case PciDevice14E4::DEVICE_16ED: return "DEVICE_16ED";
        case PciDevice14E4::DEVICE_16EE: return "DEVICE_16EE";
        case PciDevice14E4::DEVICE_16EF: return "DEVICE_16EF";
        case PciDevice14E4::DEVICE_16F1: return "DEVICE_16F1";
        case PciDevice14E4::DEVICE_16F3: return "DEVICE_16F3";
        case PciDevice14E4::DEVICE_16F7: return "DEVICE_16F7";
        case PciDevice14E4::DEVICE_16FD: return "DEVICE_16FD";
        case PciDevice14E4::DEVICE_16FE: return "DEVICE_16FE";
        case PciDevice14E4::DEVICE_170C: return "DEVICE_170C";
        case PciDevice14E4::DEVICE_170D: return "DEVICE_170D";
        case PciDevice14E4::DEVICE_170E: return "DEVICE_170E";
        case PciDevice14E4::DEVICE_1712: return "DEVICE_1712";
        case PciDevice14E4::DEVICE_1713: return "DEVICE_1713";
        case PciDevice14E4::DEVICE_1750: return "DEVICE_1750";
        case PciDevice14E4::DEVICE_1751: return "DEVICE_1751";
        case PciDevice14E4::DEVICE_1752: return "DEVICE_1752";
        case PciDevice14E4::DEVICE_1806: return "DEVICE_1806";
        case PciDevice14E4::DEVICE_1807: return "DEVICE_1807";
        case PciDevice14E4::DEVICE_3352: return "DEVICE_3352";
        case PciDevice14E4::DEVICE_3360: return "DEVICE_3360";
        case PciDevice14E4::DEVICE_4210: return "DEVICE_4210";
        case PciDevice14E4::DEVICE_4211: return "DEVICE_4211";
        case PciDevice14E4::DEVICE_4212: return "DEVICE_4212";
        case PciDevice14E4::DEVICE_4220: return "DEVICE_4220";
        case PciDevice14E4::DEVICE_4222: return "DEVICE_4222";
        case PciDevice14E4::DEVICE_4301: return "DEVICE_4301";
        case PciDevice14E4::DEVICE_4305: return "DEVICE_4305";
        case PciDevice14E4::DEVICE_4306: return "DEVICE_4306";
        case PciDevice14E4::DEVICE_4307: return "DEVICE_4307";
        case PciDevice14E4::DEVICE_4310: return "DEVICE_4310";
        case PciDevice14E4::DEVICE_4311: return "DEVICE_4311";
        case PciDevice14E4::DEVICE_4312: return "DEVICE_4312";
        case PciDevice14E4::DEVICE_4313: return "DEVICE_4313";
        case PciDevice14E4::DEVICE_4315: return "DEVICE_4315";
        case PciDevice14E4::DEVICE_4318: return "DEVICE_4318";
        case PciDevice14E4::DEVICE_4319: return "DEVICE_4319";
        case PciDevice14E4::DEVICE_4320: return "DEVICE_4320";
        case PciDevice14E4::DEVICE_4321: return "DEVICE_4321";
        case PciDevice14E4::DEVICE_4322: return "DEVICE_4322";
        case PciDevice14E4::DEVICE_4324: return "DEVICE_4324";
        case PciDevice14E4::DEVICE_4325: return "DEVICE_4325";
        case PciDevice14E4::DEVICE_4326: return "DEVICE_4326";
        case PciDevice14E4::DEVICE_4328: return "DEVICE_4328";
        case PciDevice14E4::DEVICE_4329: return "DEVICE_4329";
        case PciDevice14E4::DEVICE_432A: return "DEVICE_432A";
        case PciDevice14E4::DEVICE_432B: return "DEVICE_432B";
        case PciDevice14E4::DEVICE_432C: return "DEVICE_432C";
        case PciDevice14E4::DEVICE_432D: return "DEVICE_432D";
        case PciDevice14E4::DEVICE_4331: return "DEVICE_4331";
        case PciDevice14E4::DEVICE_4333: return "DEVICE_4333";
        case PciDevice14E4::DEVICE_4344: return "DEVICE_4344";
        case PciDevice14E4::DEVICE_4350: return "DEVICE_4350";
        case PciDevice14E4::DEVICE_4351: return "DEVICE_4351";
        case PciDevice14E4::DEVICE_4353: return "DEVICE_4353";
        case PciDevice14E4::DEVICE_4357: return "DEVICE_4357";
        case PciDevice14E4::DEVICE_4358: return "DEVICE_4358";
        case PciDevice14E4::DEVICE_4359: return "DEVICE_4359";
        case PciDevice14E4::DEVICE_4360: return "DEVICE_4360";
        case PciDevice14E4::DEVICE_4365: return "DEVICE_4365";
        case PciDevice14E4::DEVICE_43A0: return "DEVICE_43A0";
        case PciDevice14E4::DEVICE_43A1: return "DEVICE_43A1";
        case PciDevice14E4::DEVICE_43A2: return "DEVICE_43A2";
        case PciDevice14E4::DEVICE_43A3: return "DEVICE_43A3";
        case PciDevice14E4::DEVICE_43A9: return "DEVICE_43A9";
        case PciDevice14E4::DEVICE_43AA: return "DEVICE_43AA";
        case PciDevice14E4::DEVICE_43AE: return "DEVICE_43AE";
        case PciDevice14E4::DEVICE_43B1: return "DEVICE_43B1";
        case PciDevice14E4::DEVICE_43BA: return "DEVICE_43BA";
        case PciDevice14E4::DEVICE_43BB: return "DEVICE_43BB";
        case PciDevice14E4::DEVICE_43BC: return "DEVICE_43BC";
        case PciDevice14E4::DEVICE_43D3: return "DEVICE_43D3";
        case PciDevice14E4::DEVICE_43D9: return "DEVICE_43D9";
        case PciDevice14E4::DEVICE_43DC: return "DEVICE_43DC";
        case PciDevice14E4::DEVICE_43DF: return "DEVICE_43DF";
        case PciDevice14E4::DEVICE_43E9: return "DEVICE_43E9";
        case PciDevice14E4::DEVICE_43EC: return "DEVICE_43EC";
        case PciDevice14E4::DEVICE_4401: return "DEVICE_4401";
        case PciDevice14E4::DEVICE_4402: return "DEVICE_4402";
        case PciDevice14E4::DEVICE_4403: return "DEVICE_4403";
        case PciDevice14E4::DEVICE_4410: return "DEVICE_4410";
        case PciDevice14E4::DEVICE_4411: return "DEVICE_4411";
        case PciDevice14E4::DEVICE_4412: return "DEVICE_4412";
        case PciDevice14E4::DEVICE_4430: return "DEVICE_4430";
        case PciDevice14E4::DEVICE_4432: return "DEVICE_4432";
        case PciDevice14E4::DEVICE_4464: return "DEVICE_4464";
        case PciDevice14E4::DEVICE_4488: return "DEVICE_4488";
        case PciDevice14E4::DEVICE_4610: return "DEVICE_4610";
        case PciDevice14E4::DEVICE_4611: return "DEVICE_4611";
        case PciDevice14E4::DEVICE_4612: return "DEVICE_4612";
        case PciDevice14E4::DEVICE_4613: return "DEVICE_4613";
        case PciDevice14E4::DEVICE_4614: return "DEVICE_4614";
        case PciDevice14E4::DEVICE_4615: return "DEVICE_4615";
        case PciDevice14E4::DEVICE_4704: return "DEVICE_4704";
        case PciDevice14E4::DEVICE_4705: return "DEVICE_4705";
        case PciDevice14E4::DEVICE_4706: return "DEVICE_4706";
        case PciDevice14E4::DEVICE_4707: return "DEVICE_4707";
        case PciDevice14E4::DEVICE_4708: return "DEVICE_4708";
        case PciDevice14E4::DEVICE_4710: return "DEVICE_4710";
        case PciDevice14E4::DEVICE_4711: return "DEVICE_4711";
        case PciDevice14E4::DEVICE_4712: return "DEVICE_4712";
        case PciDevice14E4::DEVICE_4713: return "DEVICE_4713";
        case PciDevice14E4::DEVICE_4714: return "DEVICE_4714";
        case PciDevice14E4::DEVICE_4715: return "DEVICE_4715";
        case PciDevice14E4::DEVICE_4716: return "DEVICE_4716";
        case PciDevice14E4::DEVICE_4717: return "DEVICE_4717";
        case PciDevice14E4::DEVICE_4718: return "DEVICE_4718";
        case PciDevice14E4::DEVICE_4719: return "DEVICE_4719";
        case PciDevice14E4::DEVICE_4720: return "DEVICE_4720";
        case PciDevice14E4::DEVICE_4727: return "DEVICE_4727";
        case PciDevice14E4::DEVICE_5365: return "DEVICE_5365";
        case PciDevice14E4::DEVICE_5600: return "DEVICE_5600";
        case PciDevice14E4::DEVICE_5605: return "DEVICE_5605";
        case PciDevice14E4::DEVICE_5615: return "DEVICE_5615";
        case PciDevice14E4::DEVICE_5625: return "DEVICE_5625";
        case PciDevice14E4::DEVICE_5645: return "DEVICE_5645";
        case PciDevice14E4::DEVICE_5670: return "DEVICE_5670";
        case PciDevice14E4::DEVICE_5680: return "DEVICE_5680";
        case PciDevice14E4::DEVICE_5690: return "DEVICE_5690";
        case PciDevice14E4::DEVICE_5691: return "DEVICE_5691";
        case PciDevice14E4::DEVICE_5692: return "DEVICE_5692";
        case PciDevice14E4::DEVICE_5695: return "DEVICE_5695";
        case PciDevice14E4::DEVICE_5698: return "DEVICE_5698";
        case PciDevice14E4::DEVICE_5820: return "DEVICE_5820";
        case PciDevice14E4::DEVICE_5821: return "DEVICE_5821";
        case PciDevice14E4::DEVICE_5822: return "DEVICE_5822";
        case PciDevice14E4::DEVICE_5823: return "DEVICE_5823";
        case PciDevice14E4::DEVICE_5824: return "DEVICE_5824";
        case PciDevice14E4::DEVICE_5840: return "DEVICE_5840";
        case PciDevice14E4::DEVICE_5841: return "DEVICE_5841";
        case PciDevice14E4::DEVICE_5850: return "DEVICE_5850";
        case PciDevice14E4::DEVICE_5E87: return "DEVICE_5E87";
        case PciDevice14E4::DEVICE_5E88: return "DEVICE_5E88";
        case PciDevice14E4::DEVICE_8602: return "DEVICE_8602";
        case PciDevice14E4::DEVICE_9026: return "DEVICE_9026";
        case PciDevice14E4::DEVICE_9027: return "DEVICE_9027";
        case PciDevice14E4::DEVICE_A8D8: return "DEVICE_A8D8";
        case PciDevice14E4::DEVICE_AA52: return "DEVICE_AA52";
        case PciDevice14E4::DEVICE_B302: return "DEVICE_B302";
        case PciDevice14E4::DEVICE_B334: return "DEVICE_B334";
        case PciDevice14E4::DEVICE_B370: return "DEVICE_B370";
        case PciDevice14E4::DEVICE_B371: return "DEVICE_B371";
        case PciDevice14E4::DEVICE_B372: return "DEVICE_B372";
        case PciDevice14E4::DEVICE_B375: return "DEVICE_B375";
        case PciDevice14E4::DEVICE_B376: return "DEVICE_B376";
        case PciDevice14E4::DEVICE_B377: return "DEVICE_B377";
        case PciDevice14E4::DEVICE_B379: return "DEVICE_B379";
        case PciDevice14E4::DEVICE_B470: return "DEVICE_B470";
        case PciDevice14E4::DEVICE_B471: return "DEVICE_B471";
        case PciDevice14E4::DEVICE_B472: return "DEVICE_B472";
        case PciDevice14E4::DEVICE_B800: return "DEVICE_B800";
        case PciDevice14E4::DEVICE_B842: return "DEVICE_B842";
        case PciDevice14E4::DEVICE_B850: return "DEVICE_B850";
        case PciDevice14E4::DEVICE_B880: return "DEVICE_B880";
        case PciDevice14E4::DEVICE_B960: return "DEVICE_B960";
        case PciDevice14E4::DEVICE_B990: return "DEVICE_B990";
        case PciDevice14E4::DEVICE_D802: return "DEVICE_D802";
        case PciDevice14E4::DEVICE_D804: return "DEVICE_D804";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14E4 device14E4) // TEST: NO
{
    // COMMON_LT((" | device14E4 = %u", device14E4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14E4, enumToString(device14E4));

    return res;
}



inline const char8* enumToHumanString(PciDevice14E4 device14E4) // TEST: NO
{
    // COMMON_LT((" | device14E4 = %u", device14E4)); // Commented to avoid bad looking logs



    switch (device14E4)
    {
        case PciDevice14E4::DEVICE_0576: return "BCM43224 802.11a/b/g/n";
        case PciDevice14E4::DEVICE_0800: return "Sentry5 Chipcommon I/O Controller";
        case PciDevice14E4::DEVICE_0804: return "Sentry5 PCI Bridge";
        case PciDevice14E4::DEVICE_0805: return "Sentry5 MIPS32 CPU";
        case PciDevice14E4::DEVICE_0806: return "Sentry5 Ethernet Controller";
        case PciDevice14E4::DEVICE_080B: return "Sentry5 Crypto Accelerator";
        case PciDevice14E4::DEVICE_080F: return "Sentry5 DDR/SDR RAM Controller";
        case PciDevice14E4::DEVICE_0811: return "Sentry5 External Interface Core";
        case PciDevice14E4::DEVICE_0816: return "BCM3302 Sentry5 MIPS32 CPU";
        case PciDevice14E4::DEVICE_1570: return "720p FaceTime HD Camera";
        case PciDevice14E4::DEVICE_1600: return "NetXtreme BCM5752 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1601: return "NetXtreme BCM5752M Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1604: return "BCM5745X NetXtreme-E Ethernet Partition";
        case PciDevice14E4::DEVICE_1605: return "BCM5745X NetXtreme-E RDMA Partition";
        case PciDevice14E4::DEVICE_1606: return "BCM5745X NetXtreme-E RDMA Virtual Function";
        case PciDevice14E4::DEVICE_1609: return "BCM5745X NetXtreme-E Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_1612: return "BCM70012 Video Decoder [Crystal HD]";
        case PciDevice14E4::DEVICE_1614: return "BCM57454 NetXtreme-E 10Gb/25Gb/40Gb/50Gb/100Gb Ethernet";
        case PciDevice14E4::DEVICE_1615: return "BCM70015 Video Decoder [Crystal HD]";
        case PciDevice14E4::DEVICE_1639: return "NetXtreme II BCM5709 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_163A: return "NetXtreme II BCM5709S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_163B: return "NetXtreme II BCM5716 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_163C: return "NetXtreme II BCM5716S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_163D: return "NetXtreme II BCM57811 10-Gigabit Ethernet";
        case PciDevice14E4::DEVICE_163E: return "NetXtreme II BCM57811 10 Gigabit Ethernet Multi Function";
        case PciDevice14E4::DEVICE_163F: return "NetXtreme II BCM57811 10-Gigabit Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_1641: return "NetXtreme BCM57787 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1642: return "NetXtreme BCM57764 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1643: return "NetXtreme BCM5725 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1644: return "NetXtreme BCM5700 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1645: return "NetXtreme BCM5701 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1646: return "NetXtreme BCM5702 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1647: return "NetXtreme BCM5703 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1648: return "NetXtreme BCM5704 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1649: return "NetXtreme BCM5704S_2 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_164A: return "NetXtreme II BCM5706 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_164C: return "NetXtreme II BCM5708 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_164D: return "NetXtreme BCM5702FE Gigabit Ethernet";
        case PciDevice14E4::DEVICE_164E: return "NetXtreme II BCM57710 10-Gigabit PCIe [Everest]";
        case PciDevice14E4::DEVICE_164F: return "NetXtreme II BCM57711 10-Gigabit PCIe";
        case PciDevice14E4::DEVICE_1650: return "NetXtreme II BCM57711E 10-Gigabit PCIe";
        case PciDevice14E4::DEVICE_1653: return "NetXtreme BCM5705 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1654: return "NetXtreme BCM5705_2 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1655: return "NetXtreme BCM5717 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1656: return "NetXtreme BCM5718 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1657: return "NetXtreme BCM5719 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1659: return "NetXtreme BCM5721 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_165A: return "NetXtreme BCM5722 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_165B: return "NetXtreme BCM5723 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_165C: return "NetXtreme BCM5724 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_165D: return "NetXtreme BCM5705M Gigabit Ethernet";
        case PciDevice14E4::DEVICE_165E: return "NetXtreme BCM5705M_2 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_165F: return "NetXtreme BCM5720 2-port Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1662: return "NetXtreme II BCM57712 10 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1663: return "NetXtreme II BCM57712 10 Gigabit Ethernet Multi Function";
        case PciDevice14E4::DEVICE_1665: return "NetXtreme BCM5717 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1668: return "NetXtreme BCM5714 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1669: return "NetXtreme 5714S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_166A: return "NetXtreme BCM5780 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_166B: return "NetXtreme BCM5780S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_166E: return "570x 10/100 Integrated Controller";
        case PciDevice14E4::DEVICE_166F: return "NetXtreme II BCM57712 10 Gigabit Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_1672: return "NetXtreme BCM5754M Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1673: return "NetXtreme BCM5755M Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1674: return "NetXtreme BCM5756ME Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1677: return "NetXtreme BCM5751 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1678: return "NetXtreme BCM5715 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1679: return "NetXtreme BCM5715S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_167A: return "NetXtreme BCM5754 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_167B: return "NetXtreme BCM5755 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_167D: return "NetXtreme BCM5751M Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_167E: return "NetXtreme BCM5751F Fast Ethernet PCI Express";
        case PciDevice14E4::DEVICE_167F: return "NetLink BCM5787F Fast Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1680: return "NetXtreme BCM5761e Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1681: return "NetXtreme BCM5761 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1682: return "NetXtreme BCM57762 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1683: return "NetXtreme BCM57767 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1684: return "NetXtreme BCM5764M Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1685: return "NetXtreme II BCM57500S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1686: return "NetXtreme BCM57766 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1687: return "NetXtreme BCM5762 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1688: return "NetXtreme BCM5761 10/100/1000BASE-T Ethernet";
        case PciDevice14E4::DEVICE_168A: return "NetXtreme II BCM57800 1/10 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_168D: return "NetXtreme II BCM57840 10/20 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_168E: return "NetXtreme II BCM57810 10 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1690: return "NetXtreme BCM57760 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1691: return "NetLink BCM57788 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1692: return "NetLink BCM57780 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1693: return "NetLink BCM5787M Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1694: return "NetLink BCM57790 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1696: return "NetXtreme BCM5782 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_1698: return "NetLink BCM5784M Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_1699: return "NetLink BCM5785 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_169A: return "NetLink BCM5786 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_169B: return "NetLink BCM5787 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_169C: return "NetXtreme BCM5788 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_169D: return "NetLink BCM5789 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_16A0: return "NetLink BCM5785 Fast Ethernet";
        case PciDevice14E4::DEVICE_16A1: return "BCM57840 NetXtreme II 10 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16A2: return "BCM57840 NetXtreme II 10/20-Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16A3: return "NetXtreme BCM57786 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16A4: return "BCM57840 NetXtreme II Ethernet Multi Function";
        case PciDevice14E4::DEVICE_16A5: return "NetXtreme II BCM57800 1/10 Gigabit Ethernet Multi Function";
        case PciDevice14E4::DEVICE_16A6: return "NetXtreme BCM5702X Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16A7: return "NetXtreme BCM5703X Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16A8: return "NetXtreme BCM5704S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16A9: return "NetXtreme II BCM57800 1/10 Gigabit Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_16AA: return "NetXtreme II BCM5706S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16AB: return "NetXtreme II BCM57840 10/20 Gigabit Ethernet Multi Function";
        case PciDevice14E4::DEVICE_16AC: return "NetXtreme II BCM5708S Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16AD: return "NetXtreme II BCM57840 10/20 Gigabit Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_16AE: return "NetXtreme II BCM57810 10 Gigabit Ethernet Multi Function";
        case PciDevice14E4::DEVICE_16AF: return "NetXtreme II BCM57810 10 Gigabit Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_16B0: return "NetXtreme BCM57761 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16B1: return "NetLink BCM57781 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16B2: return "NetLink BCM57791 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16B3: return "NetXtreme BCM57786 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16B4: return "NetXtreme BCM57765 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16B5: return "NetLink BCM57785 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16B6: return "NetLink BCM57795 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16B7: return "NetXtreme BCM57782 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16BC: return "BCM57765/57785 SDXC/MMC Card Reader";
        case PciDevice14E4::DEVICE_16BE: return "BCM57765/57785 MS Card Reader";
        case PciDevice14E4::DEVICE_16BF: return "BCM57765/57785 xD-Picture Card Reader";
        case PciDevice14E4::DEVICE_16C1: return "NetXtreme-E RDMA Virtual Function";
        case PciDevice14E4::DEVICE_16C6: return "NetXtreme BCM5702A3 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16C7: return "NetXtreme BCM5703 Gigabit Ethernet";
        case PciDevice14E4::DEVICE_16C8: return "BCM57301 NetXtreme-C 10Gb Ethernet Controller";
        case PciDevice14E4::DEVICE_16C9: return "BCM57302 NetXtreme-C 10Gb/25Gb Ethernet Controller";
        case PciDevice14E4::DEVICE_16CA: return "BCM57304 NetXtreme-C 10Gb/25Gb/40Gb/50Gb Ethernet Controller";
        case PciDevice14E4::DEVICE_16CB: return "NetXtreme-C Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_16CC: return "BCM57417 NetXtreme-E Ethernet Partition";
        case PciDevice14E4::DEVICE_16CE: return "BCM57311 NetXtreme-C 10Gb RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16CF: return "BCM57312 NetXtreme-C 10Gb/25Gb RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16D0: return "BCM57402 NetXtreme-E 10Gb Ethernet Controller";
        case PciDevice14E4::DEVICE_16D1: return "BCM57404 NetXtreme-E 10Gb/25Gb Ethernet Controller";
        case PciDevice14E4::DEVICE_16D2: return "BCM57406 NetXtreme-E 10GBASE-T Ethernet Controller";
        case PciDevice14E4::DEVICE_16D3: return "NetXtreme-E Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_16D4: return "BCM57402 NetXtreme-E Ethernet Partition";
        case PciDevice14E4::DEVICE_16D5: return "BCM57407 NetXtreme-E 10GBase-T Ethernet Controller";
        case PciDevice14E4::DEVICE_16D6: return "BCM57412 NetXtreme-E 10Gb RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16D7: return "BCM57414 NetXtreme-E 10Gb/25Gb RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16D8: return "BCM57416 NetXtreme-E Dual-Media 10G RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16D9: return "BCM57417 NetXtreme-E 10GBASE-T RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16DC: return "NetXtreme-E Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_16DD: return "NetLink BCM5781 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_16DE: return "BCM57412 NetXtreme-E Ethernet Partition";
        case PciDevice14E4::DEVICE_16DF: return "BCM57314 NetXtreme-C 10Gb/25Gb/40Gb/50Gb RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16E1: return "NetXtreme-C Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_16E2: return "BCM57417 NetXtreme-E 10Gb/25Gb RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16E3: return "BCM57416 NetXtreme-E 10Gb RDMA Ethernet Controller";
        case PciDevice14E4::DEVICE_16E5: return "NetXtreme-C RDMA Virtual Function";
        case PciDevice14E4::DEVICE_16E7: return "BCM57404 NetXtreme-E Ethernet Partition";
        case PciDevice14E4::DEVICE_16E8: return "BCM57406 NetXtreme-E Ethernet Partition";
        case PciDevice14E4::DEVICE_16E9: return "BCM57407 NetXtreme-E 25Gb Ethernet Controller";
        case PciDevice14E4::DEVICE_16EC: return "BCM57414 NetXtreme-E Ethernet Partition";
        case PciDevice14E4::DEVICE_16ED: return "BCM57414 NetXtreme-E RDMA Partition";
        case PciDevice14E4::DEVICE_16EE: return "BCM57416 NetXtreme-E Ethernet Partition";
        case PciDevice14E4::DEVICE_16EF: return "BCM57416 NetXtreme-E RDMA Partition";
        case PciDevice14E4::DEVICE_16F1: return "BCM57452 NetXtreme-E 10Gb/25Gb/40Gb/50Gb Ethernet";
        case PciDevice14E4::DEVICE_16F3: return "NetXtreme BCM5727 Gigabit Ethernet PCIe";
        case PciDevice14E4::DEVICE_16F7: return "NetXtreme BCM5753 Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_16FD: return "NetXtreme BCM5753M Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_16FE: return "NetXtreme BCM5753F Fast Ethernet PCI Express";
        case PciDevice14E4::DEVICE_170C: return "BCM4401-B0 100Base-TX";
        case PciDevice14E4::DEVICE_170D: return "NetXtreme BCM5901 100Base-TX";
        case PciDevice14E4::DEVICE_170E: return "NetXtreme BCM5901 100Base-TX";
        case PciDevice14E4::DEVICE_1712: return "NetLink BCM5906 Fast Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1713: return "NetLink BCM5906M Fast Ethernet PCI Express";
        case PciDevice14E4::DEVICE_1750: return "BCM57508 NetXtreme-E 10Gb/25Gb/40Gb/50Gb/100Gb/200Gb Ethernet";
        case PciDevice14E4::DEVICE_1751: return "BCM57504 NetXtreme-E 10Gb/25Gb/40Gb/50Gb/100Gb/200Gb Ethernet";
        case PciDevice14E4::DEVICE_1752: return "BCM57502 NetXtreme-E 10Gb/25Gb/40Gb/50Gb Ethernet";
        case PciDevice14E4::DEVICE_1806: return "BCM5750X NetXtreme-E Ethernet Virtual Function";
        case PciDevice14E4::DEVICE_1807: return "BCM5750X NetXtreme-E RDMA Virtual Function";
        case PciDevice14E4::DEVICE_3352: return "BCM3352";
        case PciDevice14E4::DEVICE_3360: return "BCM3360";
        case PciDevice14E4::DEVICE_4210: return "BCM4210 iLine10 HomePNA 2.0";
        case PciDevice14E4::DEVICE_4211: return "BCM4211 iLine10 HomePNA 2.0 + V.90 56k modem";
        case PciDevice14E4::DEVICE_4212: return "BCM4212 v.90 56k modem";
        case PciDevice14E4::DEVICE_4220: return "802-11b/g Wireless PCI controller, packaged as a Linksys WPC54G ver 1.2 PCMCIA card";
        case PciDevice14E4::DEVICE_4222: return "NetXtreme BCM5753M Gigabit Ethernet PCI Express";
        case PciDevice14E4::DEVICE_4301: return "BCM4301 802.11b Wireless LAN Controller";
        case PciDevice14E4::DEVICE_4305: return "BCM4307 V.90 56k Modem";
        case PciDevice14E4::DEVICE_4306: return "BCM4306 802.11bg Wireless LAN controller";
        case PciDevice14E4::DEVICE_4307: return "BCM4306 802.11bg Wireless LAN Controller";
        case PciDevice14E4::DEVICE_4310: return "BCM4310 Chipcommon I/OController";
        case PciDevice14E4::DEVICE_4311: return "BCM4311 802.11b/g WLAN";
        case PciDevice14E4::DEVICE_4312: return "BCM4311 802.11a/b/g";
        case PciDevice14E4::DEVICE_4313: return "BCM4311 802.11a";
        case PciDevice14E4::DEVICE_4315: return "BCM4312 802.11b/g LP-PHY";
        case PciDevice14E4::DEVICE_4318: return "BCM4318 [AirForce One 54g] 802.11g Wireless LAN Controller";
        case PciDevice14E4::DEVICE_4319: return "BCM4318 [AirForce 54g] 802.11a/b/g PCI Express Transceiver";
        case PciDevice14E4::DEVICE_4320: return "BCM4306 802.11b/g Wireless LAN Controller";
        case PciDevice14E4::DEVICE_4321: return "BCM4321 802.11a Wireless Network Controller";
        case PciDevice14E4::DEVICE_4322: return "BCM4322 802.11bgn Wireless Network Controller";
        case PciDevice14E4::DEVICE_4324: return "BCM4309 802.11abg Wireless Network Controller";
        case PciDevice14E4::DEVICE_4325: return "BCM4306 802.11bg Wireless Network Controller";
        case PciDevice14E4::DEVICE_4326: return "BCM4307 Chipcommon I/O Controller?";
        case PciDevice14E4::DEVICE_4328: return "BCM4321 802.11a/b/g/n";
        case PciDevice14E4::DEVICE_4329: return "BCM4321 802.11b/g/n";
        case PciDevice14E4::DEVICE_432A: return "BCM4321 802.11an Wireless Network Controller";
        case PciDevice14E4::DEVICE_432B: return "BCM4322 802.11a/b/g/n Wireless LAN Controller";
        case PciDevice14E4::DEVICE_432C: return "BCM4322 802.11b/g/n";
        case PciDevice14E4::DEVICE_432D: return "BCM4322 802.11an Wireless Network Controller";
        case PciDevice14E4::DEVICE_4331: return "BCM4331 802.11a/b/g/n";
        case PciDevice14E4::DEVICE_4333: return "Serial (EDGE/GPRS modem part of Option GT Combo Edge)";
        case PciDevice14E4::DEVICE_4344: return "EDGE/GPRS data and 802.11b/g combo cardbus [GC89]";
        case PciDevice14E4::DEVICE_4350: return "BCM43222 Wireless Network Adapter";
        case PciDevice14E4::DEVICE_4351: return "BCM43222 802.11abgn Wireless Network Adapter";
        case PciDevice14E4::DEVICE_4353: return "BCM43224 802.11a/b/g/n";
        case PciDevice14E4::DEVICE_4357: return "BCM43225 802.11b/g/n";
        case PciDevice14E4::DEVICE_4358: return "BCM43227 802.11b/g/n";
        case PciDevice14E4::DEVICE_4359: return "BCM43228 802.11a/b/g/n";
        case PciDevice14E4::DEVICE_4360: return "BCM4360 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_4365: return "BCM43142 802.11b/g/n";
        case PciDevice14E4::DEVICE_43A0: return "BCM4360 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_43A1: return "BCM4360 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_43A2: return "BCM4360 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_43A3: return "BCM4350 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_43A9: return "BCM43217 802.11b/g/n";
        case PciDevice14E4::DEVICE_43AA: return "BCM43131 802.11b/g/n";
        case PciDevice14E4::DEVICE_43AE: return "BCM43162 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_43B1: return "BCM4352 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_43BA: return "BCM43602 802.11ac Wireless LAN SoC";
        case PciDevice14E4::DEVICE_43BB: return "BCM43602 802.11ac Wireless LAN SoC";
        case PciDevice14E4::DEVICE_43BC: return "BCM43602 802.11ac Wireless LAN SoC";
        case PciDevice14E4::DEVICE_43D3: return "BCM43567 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_43D9: return "BCM43570 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_43DC: return "BCM4355 802.11ac Wireless LAN SoC";
        case PciDevice14E4::DEVICE_43DF: return "BCM4354 802.11ac Wireless LAN SoC";
        case PciDevice14E4::DEVICE_43E9: return "BCM4358 802.11ac Wireless LAN SoC";
        case PciDevice14E4::DEVICE_43EC: return "BCM4356 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_4401: return "BCM4401 100Base-T";
        case PciDevice14E4::DEVICE_4402: return "BCM4402 Integrated 10/100BaseT";
        case PciDevice14E4::DEVICE_4403: return "BCM4402 V.90 56k Modem";
        case PciDevice14E4::DEVICE_4410: return "BCM4413 iLine32 HomePNA 2.0";
        case PciDevice14E4::DEVICE_4411: return "BCM4413 V.90 56k modem";
        case PciDevice14E4::DEVICE_4412: return "BCM4412 10/100BaseT";
        case PciDevice14E4::DEVICE_4430: return "BCM44xx CardBus iLine32 HomePNA 2.0";
        case PciDevice14E4::DEVICE_4432: return "BCM4432 CardBus 10/100BaseT";
        case PciDevice14E4::DEVICE_4464: return "BCM4364 802.11ac Wireless Network Adapter";
        case PciDevice14E4::DEVICE_4488: return "BCM4377b Wireless Network Adapter";
        case PciDevice14E4::DEVICE_4610: return "BCM4610 Sentry5 PCI to SB Bridge";
        case PciDevice14E4::DEVICE_4611: return "BCM4610 Sentry5 iLine32 HomePNA 1.0";
        case PciDevice14E4::DEVICE_4612: return "BCM4610 Sentry5 V.90 56k Modem";
        case PciDevice14E4::DEVICE_4613: return "BCM4610 Sentry5 Ethernet Controller";
        case PciDevice14E4::DEVICE_4614: return "BCM4610 Sentry5 External Interface";
        case PciDevice14E4::DEVICE_4615: return "BCM4610 Sentry5 USB Controller";
        case PciDevice14E4::DEVICE_4704: return "BCM4704 PCI to SB Bridge";
        case PciDevice14E4::DEVICE_4705: return "BCM4704 Sentry5 802.11b Wireless LAN Controller";
        case PciDevice14E4::DEVICE_4706: return "BCM4704 Sentry5 Ethernet Controller";
        case PciDevice14E4::DEVICE_4707: return "BCM4704 Sentry5 USB Controller";
        case PciDevice14E4::DEVICE_4708: return "BCM4704 Crypto Accelerator";
        case PciDevice14E4::DEVICE_4710: return "BCM4710 Sentry5 PCI to SB Bridge";
        case PciDevice14E4::DEVICE_4711: return "BCM47xx Sentry5 iLine32 HomePNA 2.0";
        case PciDevice14E4::DEVICE_4712: return "BCM47xx V.92 56k modem";
        case PciDevice14E4::DEVICE_4713: return "Sentry5 Ethernet Controller";
        case PciDevice14E4::DEVICE_4714: return "BCM47xx Sentry5 External Interface";
        case PciDevice14E4::DEVICE_4715: return "BCM47xx Sentry5 USB / Ethernet Controller";
        case PciDevice14E4::DEVICE_4716: return "BCM47xx Sentry5 USB Host Controller";
        case PciDevice14E4::DEVICE_4717: return "BCM47xx Sentry5 USB Device Controller";
        case PciDevice14E4::DEVICE_4718: return "Sentry5 Crypto Accelerator";
        case PciDevice14E4::DEVICE_4719: return "BCM47xx/53xx RoboSwitch Core";
        case PciDevice14E4::DEVICE_4720: return "BCM4712 MIPS CPU";
        case PciDevice14E4::DEVICE_4727: return "BCM4313 802.11bgn Wireless Network Adapter";
        case PciDevice14E4::DEVICE_5365: return "BCM5365P Sentry5 Host Bridge";
        case PciDevice14E4::DEVICE_5600: return "BCM5600 StrataSwitch 24+2 Ethernet Switch Controller";
        case PciDevice14E4::DEVICE_5605: return "BCM5605 StrataSwitch 24+2 Ethernet Switch Controller";
        case PciDevice14E4::DEVICE_5615: return "BCM5615 StrataSwitch 24+2 Ethernet Switch Controller";
        case PciDevice14E4::DEVICE_5625: return "BCM5625 StrataSwitch 24+2 Ethernet Switch Controller";
        case PciDevice14E4::DEVICE_5645: return "BCM5645 StrataSwitch 24+2 Ethernet Switch Controller";
        case PciDevice14E4::DEVICE_5670: return "BCM5670 8-Port 10GE Ethernet Switch Fabric";
        case PciDevice14E4::DEVICE_5680: return "BCM5680 G-Switch 8 Port Gigabit Ethernet Switch Controller";
        case PciDevice14E4::DEVICE_5690: return "BCM5690 12-port Multi-Layer Gigabit Ethernet Switch";
        case PciDevice14E4::DEVICE_5691: return "BCM5691 GE/10GE 8+2 Gigabit Ethernet Switch Controller";
        case PciDevice14E4::DEVICE_5692: return "BCM5692 12-port Multi-Layer Gigabit Ethernet Switch";
        case PciDevice14E4::DEVICE_5695: return "BCM5695 12-port + HiGig Multi-Layer Gigabit Ethernet Switch";
        case PciDevice14E4::DEVICE_5698: return "BCM5698 12-port Multi-Layer Gigabit Ethernet Switch";
        case PciDevice14E4::DEVICE_5820: return "BCM5820 Crypto Accelerator";
        case PciDevice14E4::DEVICE_5821: return "BCM5821 Crypto Accelerator";
        case PciDevice14E4::DEVICE_5822: return "BCM5822 Crypto Accelerator";
        case PciDevice14E4::DEVICE_5823: return "BCM5823 Crypto Accelerator";
        case PciDevice14E4::DEVICE_5824: return "BCM5824 Crypto Accelerator";
        case PciDevice14E4::DEVICE_5840: return "BCM5840 Crypto Accelerator";
        case PciDevice14E4::DEVICE_5841: return "BCM5841 Crypto Accelerator";
        case PciDevice14E4::DEVICE_5850: return "BCM5850 Crypto Accelerator";
        case PciDevice14E4::DEVICE_5E87: return "Valkyrie offload engine";
        case PciDevice14E4::DEVICE_5E88: return "Viper Offload Engine";
        case PciDevice14E4::DEVICE_8602: return "BCM7400/BCM7405 Serial ATA Controller";
        case PciDevice14E4::DEVICE_9026: return "CN99xx [ThunderX2] Integrated USB 3.0 xHCI Host Controller";
        case PciDevice14E4::DEVICE_9027: return "CN99xx [ThunderX2] Integrated AHCI/SATA 3 Host Controller";
        case PciDevice14E4::DEVICE_A8D8: return "BCM43224/5 Wireless Network Adapter";
        case PciDevice14E4::DEVICE_AA52: return "BCM43602 802.11ac Wireless LAN SoC";
        case PciDevice14E4::DEVICE_B302: return "BCM56302 StrataXGS 24x1GE 2x10GE Switch Controller";
        case PciDevice14E4::DEVICE_B334: return "BCM56334 StrataXGS 24x1GE 4x10GE Switch Controller";
        case PciDevice14E4::DEVICE_B370: return "BCM56370 Switch ASIC";
        case PciDevice14E4::DEVICE_B371: return "BCM56371 Switch ASIC";
        case PciDevice14E4::DEVICE_B372: return "BCM56372 Switch ASIC";
        case PciDevice14E4::DEVICE_B375: return "BCM56375 Switch ASIC";
        case PciDevice14E4::DEVICE_B376: return "BCM56376 Switch ASIC";
        case PciDevice14E4::DEVICE_B377: return "BCM56377 Switch ASIC";
        case PciDevice14E4::DEVICE_B379: return "Broadcom BCM56379 Switch ASIC";
        case PciDevice14E4::DEVICE_B470: return "BCM56470 SWITCH ASIC";
        case PciDevice14E4::DEVICE_B471: return "BCM56471 SWITCH ASIC";
        case PciDevice14E4::DEVICE_B472: return "BCM56472 SWITCH ASIC";
        case PciDevice14E4::DEVICE_B800: return "BCM56800 StrataXGS 10GE Switch Controller";
        case PciDevice14E4::DEVICE_B842: return "BCM56842 Trident 10GE Switch Controller";
        case PciDevice14E4::DEVICE_B850: return "Broadcom BCM56850 Switch ASIC";
        case PciDevice14E4::DEVICE_B880: return "BCM56880 Switch ASIC";
        case PciDevice14E4::DEVICE_B960: return "Broadcom BCM56960 Switch ASIC";
        case PciDevice14E4::DEVICE_B990: return "BCM56990 Switch ASIC";
        case PciDevice14E4::DEVICE_D802: return "BCM58802 Stingray 50Gb Ethernet SoC";
        case PciDevice14E4::DEVICE_D804: return "BCM58804 Stingray 100Gb Ethernet SoC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCIDEVICE14E4_H
