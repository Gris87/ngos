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
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage[1], 4088),                   true);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1000, 0x2050, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF240000);
        TEST_ASSERT_EQUALS(params->header.signature,                                   BOOT_PARAMS_HEADER_SIGNATURE);

        params->header.signature = 0xAABBCCDDEEFF0011;

        TEST_ASSERT_EQUALS(((BootParams *)0xFFFFFFFFFF200000)->header.signature,       0xAABBCCDDEEFF0011);
        TEST_ASSERT_EQUALS(params->header.signature,                                   0xAABBCCDDEEFF0011);

        params->header.signature = BOOT_PARAMS_HEADER_SIGNATURE;

        TEST_ASSERT_EQUALS(((BootParams *)0xFFFFFFFFFF200000)->header.signature,       BOOT_PARAMS_HEADER_SIGNATURE);
        TEST_ASSERT_EQUALS(params->header.signature,                                   BOOT_PARAMS_HEADER_SIGNATURE);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1234, 0x1050, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF280234);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1050, 0x1000, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF2C0050);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1000, 0x1000, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF300000);
    }
    TEST_CASE_END();



    TEST_CASE("removeFixedMapping()");
    {
        TEST_ASSERT_EQUALS(IORemap::removeFixedMapping(0xFFFFFFFFFF200000, 0x1000), NgosStatus::OK);
    }
    TEST_CASE_END();



    TEST_CASE("Clean up");
    {
        TEST_ASSERT_EQUALS(memempty(&IORemap::sSlotsAddresses, sizeof(IORemap::sSlotsAddresses)), false);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sSlotsSizes,     sizeof(IORemap::sSlotsSizes)),     false);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sPoolOfSlots,    sizeof(IORemap::sPoolOfSlots)),    false);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage,     sizeof(IORemap::sFixmapPage)),     true);

        TEST_ASSERT_EQUALS(memzero(&IORemap::sSlotsAddresses, sizeof(IORemap::sSlotsAddresses)), &IORemap::sSlotsAddresses);
        TEST_ASSERT_EQUALS(memzero(&IORemap::sSlotsSizes,     sizeof(IORemap::sSlotsSizes)),     &IORemap::sSlotsSizes);
        TEST_ASSERT_EQUALS(memzero(&IORemap::sPoolOfSlots,    sizeof(IORemap::sPoolOfSlots)),    &IORemap::sPoolOfSlots);
        TEST_ASSERT_EQUALS(memzero(&IORemap::sFixmapPage,     sizeof(IORemap::sFixmapPage)),     &IORemap::sFixmapPage);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_IOREMAP_H
