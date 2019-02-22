#include "ioremap.h"

#include <pagetable/utils.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/other/ioremap/utils.h>
#include <src/bits64/other/pagetable/addressconversion.h>



extern PMD fixmap_pagetable_level2[PTRS_PER_PMD]; // fixmap_pagetable_level2 declared in main.S file



u64 IORemap::sVirtualSlots[FIX_BITMAP_SLOTS];
PTE IORemap::sFixmapPage[PTRS_PER_PTE] __attribute__((aligned(PAGE_SIZE)));



NgosStatus IORemap::init()
{
    COMMON_LT((""));



    for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
    {
        sVirtualSlots[i] = FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN - i * NUMBER_OF_FIX_BITMAPS);

        COMMON_LVVV(("sVirtualSlots[%d] = 0x%016lX", i, sVirtualSlots[i]));
    }

    COMMON_TEST_ASSERT(FIX_BITMAP_SLOTS == 8,                                                                         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[0] == 0xFFFFFFFFFF200000,                                                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[1] == 0xFFFFFFFFFF240000,                                                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[2] == 0xFFFFFFFFFF280000,                                                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[3] == 0xFFFFFFFFFF2C0000,                                                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[4] == 0xFFFFFFFFFF300000,                                                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[5] == 0xFFFFFFFFFF340000,                                                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[6] == 0xFFFFFFFFFF380000,                                                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[7] == 0xFFFFFFFFFF3C0000,                                                        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[FIX_BITMAP_SLOTS - 1] == 0xFFFFFFFFFF400000 - NUMBER_OF_FIX_BITMAPS * PAGE_SIZE, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus IORemap::addPmdForFixmap()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN)           == 0xFFFFFFFFFF200000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(pmdIndex(FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN)) == 505,                NgosStatus::ASSERTION);



    PMD *pmd = &fixmap_pagetable_level2[pmdIndex(FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN))];

    setPmd(pmd, AddressConversion::physicalAddress((pmd_value)&sFixmapPage | USER_PAGE_TABLE_FLAGS));



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    for (i64 i = 0; i < PTRS_PER_PMD; ++i)
    {
        if (fixmap_pagetable_level2[i].pmd)
        {
            COMMON_LVVV(("fixmap_pagetable_level2[%d] = 0x%016lX", i, fixmap_pagetable_level2[i].pmd));
        }
    }
#endif

    COMMON_TEST_ASSERT(fixmap_pagetable_level2[504].pmd == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(fixmap_pagetable_level2[505].pmd != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(fixmap_pagetable_level2[506].pmd != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(fixmap_pagetable_level2[507].pmd == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(fixmap_pagetable_level2[508].pmd == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(fixmap_pagetable_level2[509].pmd == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(fixmap_pagetable_level2[510].pmd == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(fixmap_pagetable_level2[511].pmd == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus IORemap::addFixedMapping(u64 address, u64 size, void **res)
{
    COMMON_LT((" | address = 0x%016lX, size = %u, res = 0x%016lX", address, size, res));

    COMMON_ASSERT(address,                  "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,                 "size is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(res,                      "res is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(address + size > address, "size is invalid", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
