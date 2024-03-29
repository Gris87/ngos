#include "dynamicpagetable.h"

#include <com/ngos/kernel/other/kerneldefines.h>
#include <com/ngos/kernel/other/pagetable/addressconversion.h>
#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/pagetable/utils.h>



extern void *_start;                                                           // _start declared in main.S file // Ignore CppEqualAlignmentVerifier
extern PGD   early_pagetable[PTRS_PER_PGD];                                    // early_pagetable declared in main.S file
extern PMD   dynamic_pagetable_pages[EARLY_DYNAMIC_PAGE_TABLES][PTRS_PER_PMD]; // dynamic_pagetable_pages declared in main.S file



u8 currentDynamicPageIndex = 0;

u8* allocateDynamicPage()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(currentDynamicPageIndex < EARLY_DYNAMIC_PAGE_TABLES, nullptr);
    u8 *page = (u8 *)dynamic_pagetable_pages[currentDynamicPageIndex];
    ++currentDynamicPageIndex;



    return page;
}

NgosStatus initializeDynamicPageIdentity(PGD *page, u64 address, u64 end, u8 level)
{
    COMMON_LT((" | page = 0x%p, address = 0x%p, end = 0x%p, level = %u", page, address, end, level));

    COMMON_ASSERT(page,                     "page is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(end > address,            "end is invalid",   NgosStatus::ASSERTION);
    COMMON_ASSERT(level >= 2 && level <= 5, "level is invalid", NgosStatus::ASSERTION);



    u8 bits = PAGE_SHIFT + (level - 1) * (PMD_SHIFT - PAGE_SHIFT);

    u64 pageSize = SIZE_BY_BITS(bits);
    u64 pageMask = ~(pageSize - 1);



    while (address < end)
    {
        PGD *pgd = page + ((address >> bits) & (PTRS_PER_PGD - 1));



        u64 next = (address & pageMask) + pageSize;

        if (next > end)
        {
            next = end;
        }



        if (level > 2)
        {
            PGD *pgdNext;

            if (pgdValue(*pgd))
            {
                pgdNext = (PGD *)AddressConversion::virtualAddress(pgdPageVirtualAddress(*pgd));
            }
            else
            {
                pgdNext = (PGD *)allocateDynamicPage();

                setPgd(pgd, AddressConversion::physicalAddress((pgd_value)pgdNext | KERNEL_PAGE_TABLE_FLAGS));
            }



            COMMON_LVVV(("pgdNext = 0x%p", pgdNext));

            COMMON_TEST_ASSERT(pgdNext, NgosStatus::ASSERTION);



            COMMON_ASSERT_EXECUTION(initializeDynamicPageIdentity(pgdNext, address, next, level - 1), NgosStatus::ASSERTION);
        }
        else
        {
            setPmd((PMD *)pgd, (pmd_value)address | KERNEL_PAGE_LARGE_EXEC_FLAGS);
        }



        address = next;
    }



    return NgosStatus::OK;
}

NgosStatus addDynamicIdentityMap(u64 start, u64 end)
{
    COMMON_LT((" | start = 0x%p, end = 0x%p", start, end));

    COMMON_ASSERT(end > start, "end is invalid", NgosStatus::ASSERTION);



    start = ROUND_DOWN(start, PMD_SIZE);
    end   = ROUND_UP(end,     PMD_SIZE);

    currentDynamicPageIndex = 0;



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    COMMON_ASSERT_EXECUTION(initializeDynamicPageIdentity(early_pagetable, start, end, 5), NgosStatus::ASSERTION);
#else
    COMMON_ASSERT_EXECUTION(initializeDynamicPageIdentity(early_pagetable, start, end, 4), NgosStatus::ASSERTION);
#endif



    while (start < end)
    {
        COMMON_ASSERT_EXECUTION(AsmUtils::invlpg((u8 *)start), NgosStatus::ASSERTION);

        start += PMD_SIZE;
    }



    return NgosStatus::OK;
}

NgosStatus clearDynamicIdentityMap(u64 start, u64 end)
{
    COMMON_LT((" | start = 0x%p, end = 0x%p", start, end));

    COMMON_ASSERT(end > start, "end is invalid", NgosStatus::ASSERTION);



    memzero(dynamic_pagetable_pages, sizeof(dynamic_pagetable_pages));



    start = ROUND_DOWN(start, PMD_SIZE);
    end   = ROUND_UP(end,     PMD_SIZE);

    while (start < end)
    {
        COMMON_ASSERT_EXECUTION(AsmUtils::invlpg((u8 *)start), NgosStatus::ASSERTION);

        start += PMD_SIZE;
    }



    return NgosStatus::OK;
}
