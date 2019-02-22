#ifndef OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_IOREMAP_H
#define OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_IOREMAP_H



#include <buildconfig.h>
#include <src/bits64/memory/memory.h>
#include <src/bits64/other/ioremap/ioremap.h>
#include <test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_other_ioremap_utils);
{
    TEST_CASE("init()");
    {
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage,   sizeof(IORemap::sFixmapPage)),   true);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sVirtualSlots, sizeof(IORemap::sVirtualSlots)), true);

        TEST_ASSERT_EQUALS(IORemap::init(),            NgosStatus::OK);
        TEST_ASSERT_EQUALS(IORemap::addPmdForFixmap(), NgosStatus::OK);

        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage,     sizeof(IORemap::sFixmapPage)),   false);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sVirtualSlots,   sizeof(IORemap::sVirtualSlots)), false);
    }
    TEST_CASE_END();



    TEST_CASE("addFixedMapping()");
    {
        BootParams *params = 0;

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1000, 0x1000, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF200000);
        TEST_ASSERT_EQUALS(params->header.signature,                                   BOOT_PARAMS_HEADER_SIGNATURE);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1000, 0x2050, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF201000);
        TEST_ASSERT_EQUALS(params->header.signature,                                   BOOT_PARAMS_HEADER_SIGNATURE);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1234, 0x1050, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF204234);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1050, 0x1000, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF206050);

        TEST_ASSERT_EQUALS(IORemap::addFixedMapping(0x1000, 0x1000, (void **)&params), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)params,                                                0xFFFFFFFFFF208000);
    }
    TEST_CASE_END();



    TEST_CASE("Clean up");
    {
        TEST_ASSERT_EQUALS(memempty(&IORemap::sFixmapPage,   sizeof(IORemap::sFixmapPage)),   false);
        TEST_ASSERT_EQUALS(memempty(&IORemap::sVirtualSlots, sizeof(IORemap::sVirtualSlots)), false);

        TEST_ASSERT_EQUALS(memzero(&IORemap::sFixmapPage,   sizeof(IORemap::sFixmapPage)),   &IORemap::sFixmapPage);
        TEST_ASSERT_EQUALS(memzero(&IORemap::sVirtualSlots, sizeof(IORemap::sVirtualSlots)), &IORemap::sVirtualSlots);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_IOREMAP_H
