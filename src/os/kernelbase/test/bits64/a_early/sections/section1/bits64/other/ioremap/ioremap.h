#ifndef OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_IOREMAP_H
#define OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_IOREMAP_H



#include <buildconfig.h>
#include <src/bits64/memory/memory.h>
#include <src/bits64/other/ioremap/ioremap.h>
#include <test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_other_ioremap_ioremap);
{
    TEST_CASE("init()");
    {
        TEST_ASSERT_EQUALS(memempty(&IORemap::sSlotsAddresses, sizeof(IORemap::sSlotsAddresses)), true);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sSlotsSizes,     sizeof(IORemap::sSlotsSizes)),     true);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sPoolOfSlots,    sizeof(IORemap::sPoolOfSlots)),    true);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage,     sizeof(IORemap::sFixmapPage)),     true);

        TEST_ASSERT_EQUALS(IORemap::init(),            NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::addPmdForFixmap(), NgosStatus::OK);

        TEST_ASSERT_EQUALS(memempty(&IORemap::sSlotsAddresses, sizeof(IORemap::sSlotsAddresses)), true);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sSlotsSizes,     sizeof(IORemap::sSlotsSizes)),     true);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sPoolOfSlots,    sizeof(IORemap::sPoolOfSlots)),    false);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage,     sizeof(IORemap::sFixmapPage)),     true);
    }
    TEST_CASE_END();



    TEST_CASE("addFixedMapping()");
    {
        BootParams *params = 0;

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1000, 0x1000, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(params->header.signature,                                   BOOT_PARAMS_HEADER_SIGNATURE);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                     0);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                                 7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                   7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                                0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                    0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                   0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                   1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                   2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                   3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                   4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                   5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                   6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                   7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                                0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 511 * 8),                true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1000, 0x2050, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF240000);
        TEST_ASSERT_EQUALS(params->header.signature,                                   BOOT_PARAMS_HEADER_SIGNATURE);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                     1);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                                 7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                   6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                                0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                                0xFFFFFFFFFF240000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                    0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                    0x2050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                   0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                   1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                   2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                   3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                   4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                   5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                   6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                   7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                                0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 63 * 8),                 true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[64].pte,                               0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[65].pte,                               0x8000000000002163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[66].pte,                               0x8000000000003163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[67], 445 * 8),               true); // Ignore CppShiftVerifier

        params->header.signature = 0xAABBCCDDEEFF0011;

        TEST_ASSERT_EQUALS(((BootParams *)0xFFFFFFFFFF200000)->header.signature,       0xAABBCCDDEEFF0011);
        TEST_ASSERT_EQUALS(params->header.signature,                                   0xAABBCCDDEEFF0011);

        params->header.signature = BOOT_PARAMS_HEADER_SIGNATURE;

        TEST_ASSERT_EQUALS(((BootParams *)0xFFFFFFFFFF200000)->header.signature,       BOOT_PARAMS_HEADER_SIGNATURE);
        TEST_ASSERT_EQUALS(params->header.signature,                                   BOOT_PARAMS_HEADER_SIGNATURE);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1234, 0x1050, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF280234);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                     2);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                                 7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                   5);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                                0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                                0xFFFFFFFFFF240000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                                0xFFFFFFFFFF280234);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                    0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                    0x2050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                    0x1050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                   0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                   1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                   2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                   3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                   4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                   5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                   6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                   7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                                0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 63 * 8),                 true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[64].pte,                               0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[65].pte,                               0x8000000000002163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[66].pte,                               0x8000000000003163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[67], 61 * 8),                true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[128].pte,                              0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[129].pte,                              0x8000000000002163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[130], 382 * 8),              true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1050, 0x1000, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF2C0050);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                     3);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                                 7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                   4);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                                0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                                0xFFFFFFFFFF240000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                                0xFFFFFFFFFF280234);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                                0xFFFFFFFFFF2C0050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                    0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                    0x2050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                    0x1050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                    0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                   0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                   1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                   2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                   3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                   4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                   5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                   6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                   7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                                0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 63 * 8),                 true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[64].pte,                               0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[65].pte,                               0x8000000000002163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[66].pte,                               0x8000000000003163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[67], 61 * 8),                true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[128].pte,                              0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[129].pte,                              0x8000000000002163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[130], 62 * 8),               true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[192].pte,                              0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[193].pte,                              0x8000000000002163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[194], 318 * 8),              true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1000, 0x1000, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF300000);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                     4);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                                 7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                   3);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                                0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                                0xFFFFFFFFFF240000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                                0xFFFFFFFFFF280234);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                                0xFFFFFFFFFF2C0050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                                0xFFFFFFFFFF300000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                    0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                    0x2050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                    0x1050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                    0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                    0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                    0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                   0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                   1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                   2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                   3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                   4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                   5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                   6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                   7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                                0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 63 * 8),                 true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[64].pte,                               0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[65].pte,                               0x8000000000002163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[66].pte,                               0x8000000000003163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[67], 61 * 8),                true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[128].pte,                              0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[129].pte,                              0x8000000000002163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[130], 62 * 8),               true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[192].pte,                              0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[193].pte,                              0x8000000000002163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[194], 62 * 8),               true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[256].pte,                              0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[257], 255 * 8),              true); // Ignore CppShiftVerifier
    }
    TEST_CASE_END();



    TEST_CASE("removeFixedMapping()");
    {
        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF240000, 0x2050), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  4);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                4);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0xFFFFFFFFFF280234);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0xFFFFFFFFFF2C0050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0xFFFFFFFFFF300000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0x1050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                             0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 127 * 8),             true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[128].pte,                           0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[129].pte,                           0x8000000000002163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[130], 62 * 8),            true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[192].pte,                           0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[193].pte,                           0x8000000000002163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[194], 62 * 8),            true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[256].pte,                           0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[257], 255 * 8),           true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF2C0050, 0x1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  4);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              1);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                5);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0xFFFFFFFFFF280234);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0xFFFFFFFFFF300000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0x1050);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                             0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 127 * 8),             true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[128].pte,                           0x8000000000001163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[129].pte,                           0x8000000000002163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[130], 126 * 8),           true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[256].pte,                           0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[257], 255 * 8),           true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF280234, 0x1050), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  4);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              2);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0xFFFFFFFFFF300000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                             0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 255 * 8),             true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[256].pte,                           0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[257], 255 * 8),           true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF300000, 0x1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  4);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              3);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                7);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[0].pte,                             0x8000000000001163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 511 * 8),             true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF200000, 0x1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  4);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              4);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                8);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                7);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 512 * 8),             true); // Ignore CppShiftVerifier
    }
    TEST_CASE_END();



    TEST_CASE("addFixedMapping()/removeFixedMapping()");
    {
        void *a = 0;

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x54321, 0x1F00, (void **)&a), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)a,                                                 0xFFFFFFFFFF340321);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                 5);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                             4);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                               7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                            0xFFFFFFFFFF340321);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                0x1F00);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                               1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                               3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                               2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                               4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                               0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                               5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                               6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                               7);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 320 * 8),            true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[320].pte,                          0x8000000000054163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[321].pte,                          0x8000000000055163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[322].pte,                          0x8000000000056163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[323], 189 * 8),          true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x65F36, 0x0205, (void **)&a), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)a,                                                 0xFFFFFFFFFF380F36);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                 6);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                             4);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                               6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                            0xFFFFFFFFFF340321);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                            0xFFFFFFFFFF380F36);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                0x1F00);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                0x0205);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                               1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                               3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                               2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                               4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                               0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                               5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                               6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                               7);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 320 * 8),            true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[320].pte,                          0x8000000000054163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[321].pte,                          0x8000000000055163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[322].pte,                          0x8000000000056163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[323], 61 * 8),           true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[384].pte,                          0x8000000000065163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[385].pte,                          0x8000000000066163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[386], 126 * 8),          true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0xA0000, 0x1000, (void **)&a), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)a,                                                 0xFFFFFFFFFF3C0000);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                 7);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                             4);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                               5);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                            0xFFFFFFFFFF340321);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                            0xFFFFFFFFFF380F36);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                            0xFFFFFFFFFF3C0000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                0x1F00);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                0x0205);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                0x1000);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                               1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                               3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                               2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                               4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                               0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                               5);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                               6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                               7);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 320 * 8),            true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[320].pte,                          0x8000000000054163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[321].pte,                          0x8000000000055163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[322].pte,                          0x8000000000056163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[323], 61 * 8),           true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[384].pte,                          0x8000000000065163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[385].pte,                          0x8000000000066163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[386], 62 * 8),           true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[448].pte,                          0x80000000000A0163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[449], 63 * 8),           true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF380F36, 0x0205), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  7);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              5);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0xFFFFFFFFFF340321);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0xFFFFFFFFFF3C0000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0x1F00);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0x1000);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                7);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 320 * 8),             true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[320].pte,                           0x8000000000054163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[321].pte,                           0x8000000000055163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[322].pte,                           0x8000000000056163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[323], 125 * 8),           true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[448].pte,                           0x80000000000A0163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[449], 63 * 8),            true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF3C0000, 0x1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  7);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0xFFFFFFFFFF340321);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0x1F00);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                7);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                7);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 320 * 8),             true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[320].pte,                           0x8000000000054163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[321].pte,                           0x8000000000055163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[322].pte,                           0x8000000000056163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[323], 189 * 8),           true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0xFFFFF, 0x0002, (void **)&a), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)a,                                                 0xFFFFFFFFFF240FFF);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                 0);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                             6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                               6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                            0xFFFFFFFFFF240FFF);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                            0xFFFFFFFFFF340321);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                0x0002);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                0x1F00);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                               1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                               3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                               2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                               4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                               0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                               6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                               7);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                               7);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 64 * 8),             true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[64].pte,                           0x80000000000FF163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[65].pte,                           0x8000000000100163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[66], 254 * 8),           true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[320].pte,                          0x8000000000054163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[321].pte,                          0x8000000000055163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[322].pte,                          0x8000000000056163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[323], 189 * 8),          true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0xAAAAA, 0xBBBB, (void **)&a), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)a,                                                 0xFFFFFFFFFF2C0AAA);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                 1);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                             6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                               5);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                            0xFFFFFFFFFF240FFF);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                            0xFFFFFFFFFF2C0AAA);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                            0xFFFFFFFFFF340321);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                0x0002);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                0xBBBB);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                0x1F00);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                               1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                               3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                               2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                               4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                               0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                               6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                               7);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                               7);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 64 * 8),             true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[64].pte,                           0x80000000000FF163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[65].pte,                           0x8000000000100163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[66], 126 * 8),           true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[192].pte,                          0x80000000000AA163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[193].pte,                          0x80000000000AB163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[194].pte,                          0x80000000000AC163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[195].pte,                          0x80000000000AD163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[196].pte,                          0x80000000000AE163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[197].pte,                          0x80000000000AF163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[198].pte,                          0x80000000000B0163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[199].pte,                          0x80000000000B1163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[200].pte,                          0x80000000000B2163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[201].pte,                          0x80000000000B3163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[202].pte,                          0x80000000000B4163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[203].pte,                          0x80000000000B5163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[204].pte,                          0x80000000000B6163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[205], 115 * 8),          true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[320].pte,                          0x8000000000054163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[321].pte,                          0x8000000000055163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[322].pte,                          0x8000000000056163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[323], 189 * 8),          true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF340321, 0x1F00), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  1);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                6);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0xFFFFFFFFFF240FFF);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0xFFFFFFFFFF2C0AAA);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0x0002);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0xBBBB);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                7);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                5);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 64 * 8),              true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[64].pte,                            0x80000000000FF163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[65].pte,                            0x8000000000100163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[66], 126 * 8),            true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[192].pte,                           0x80000000000AA163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[193].pte,                           0x80000000000AB163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[194].pte,                           0x80000000000AC163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[195].pte,                           0x80000000000AD163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[196].pte,                           0x80000000000AE163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[197].pte,                           0x80000000000AF163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[198].pte,                           0x80000000000B0163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[199].pte,                           0x80000000000B1163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[200].pte,                           0x80000000000B2163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[201].pte,                           0x80000000000B3163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[202].pte,                           0x80000000000B4163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[203].pte,                           0x80000000000B5163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[204].pte,                           0x80000000000B6163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[205], 307 * 8),           true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF2C0AAA, 0xBBBB), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  1);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0xFFFFFFFFFF240FFF);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0x0002);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                7);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                5);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 64 * 8),              true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[64].pte,                            0x80000000000FF163);
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[65].pte,                            0x8000000000100163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[66], 446 * 8),            true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF240FFF, 0x0002), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  1);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              1);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                8);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                7);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                5);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 512 * 8),             true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x10000, 0x1000, (void **)&a), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)a,                                                 0xFFFFFFFFFF280000);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                 2);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                             1);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                               7);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                            0xFFFFFFFFFF280000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                            0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                0x1000);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                               3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                               1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                               2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                               4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                               0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                               6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                               7);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                               5);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 128 * 8),            true); // Ignore CppShiftVerifier
        TEST_ASSERT_EQUALS(IORemap::sFixmapPage[128].pte,                          0x8000000000010163);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[129], 383 * 8),          true); // Ignore CppShiftVerifier

        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF280000, 0x1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::sLastUsedSlot,                                  2);
        TEST_ASSERT_EQUALS(IORemap::sLastReleasedSlot,                              2);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAvailable,                                8);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[0],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[1],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[2],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[3],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[4],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[5],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[6],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsAddresses[7],                             0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[0],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[1],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[2],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[3],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[4],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[5],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[6],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sSlotsSizes[7],                                 0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[0],                                3);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[1],                                1);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[2],                                2);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[3],                                4);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[4],                                0);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[5],                                6);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[6],                                7);
        TEST_ASSERT_EQUALS(IORemap::sPoolOfSlots[7],                                5);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[0], 512 * 8),             true); // Ignore CppShiftVerifier
    }
    TEST_CASE_END();



    TEST_CASE("Clean up");
    {
        TEST_ASSERT_EQUALS(memempty(&IORemap::sSlotsAddresses, sizeof(IORemap::sSlotsAddresses)), true);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sSlotsSizes,     sizeof(IORemap::sSlotsSizes)),     true);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sPoolOfSlots,    sizeof(IORemap::sPoolOfSlots)),    false);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage,     sizeof(IORemap::sFixmapPage)),     true);

        TEST_ASSERT_EQUALS(memzero(&IORemap::sPoolOfSlots, sizeof(IORemap::sPoolOfSlots)), &IORemap::sPoolOfSlots);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_IOREMAP_H
