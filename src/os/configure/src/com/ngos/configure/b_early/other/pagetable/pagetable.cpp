#include "pagetable.h"

#include <com/ngos/configure/b_early/other/pagetable/asm_switchtofivelevelpaging.h>
#include <com/ngos/configure/b_early/other/pagetable/pageallocationcontext.h>
#include <com/ngos/configure/other/configuredefines.h>
#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/pagetable/utils.h>



PageAllocationContext  pageAllocationContext;
u8                    *topLevelPage;



u8* allocatePage()
{
    EARLY_LT((""));



    if (pageAllocationContext.position >= pageAllocationContext.size)
    {
        EARLY_LF(("Page allocation is failed because buffer is out of space"));

        return 0;
    }



    u8 *page = pageAllocationContext.buffer + pageAllocationContext.position;
    EARLY_LVV(("Page allocated at address 0x%p", page));

    pageAllocationContext.position += PAGE_SIZE;
    EARLY_LVVV(("pageAllocationContext.position = %u", pageAllocationContext.position));



    return page;
}

NgosStatus initializePageIdentity(PGD *page, u64 address, u64 end, u8 level)
{
    EARLY_LT((" | page = 0x%p, address = 0x%p, end = 0x%p, level = %u", page, address, end, level));

    EARLY_ASSERT(page,                     "page is null",     NgosStatus::ASSERTION);
    EARLY_ASSERT(end > address,            "end is invalid",   NgosStatus::ASSERTION);
    EARLY_ASSERT(level >= 2 && level <= 5, "level is invalid", NgosStatus::ASSERTION);



    u8 bits = PAGE_SHIFT + (level - 1) * (PMD_SHIFT - PAGE_SHIFT);

    u64 pageSize = (1ULL << bits);
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

            if (pgdPresent(*pgd))
            {
                pgdNext = (PGD *)pgdPageVirtualAddress(*pgd);
            }
            else
            {
                pgdNext = (PGD *)allocatePage();
                EARLY_TEST_ASSERT(pgdNext, NgosStatus::ASSERTION);

                setPgd(pgd, (pgd_value)pgdNext | KERNEL_PAGE_TABLE_FLAGS);
            }



            EARLY_ASSERT_EXECUTION(initializePageIdentity(pgdNext, address, next, level - 1), NgosStatus::ASSERTION);
        }
        else
        {
            if (!pgdPresent(*pgd))
            {
                setPmd((PMD *)pgd, (pmd_value)address | KERNEL_PAGE_LARGE_EXEC_FLAGS);
            }
        }



        address = next;
    }



    return NgosStatus::OK;
}

NgosStatus initializeIdentityMaps(u8 *pageTable)
{
    EARLY_LT((" | pageTable = 0x%p", pageTable));

    EARLY_ASSERT(pageTable, "pageTable is null", NgosStatus::ASSERTION);



    pageAllocationContext.buffer   = pageTable;
    pageAllocationContext.size     = BOOT_PAGE_TABLE_SIZE;
    pageAllocationContext.position = 0;

    EARLY_LVVV(("pageAllocationContext.buffer   = 0x%p", pageAllocationContext.buffer));
    EARLY_LVVV(("pageAllocationContext.size     = %u",   pageAllocationContext.size));
    EARLY_LVVV(("pageAllocationContext.position = %u",   pageAllocationContext.position));



    memzero(pageAllocationContext.buffer, pageAllocationContext.size);
    topLevelPage = allocatePage();

    EARLY_LVVV(("topLevelPage = 0x%p", topLevelPage));
    EARLY_TEST_ASSERT(topLevelPage, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus addIdentityMap(u64 start, u64 end)
{
    EARLY_LT((" | start = 0x%p, end = 0x%p", start, end));

    EARLY_ASSERT(end > start, "end is invalid", NgosStatus::ASSERTION);



    start = ROUND_DOWN(start, PMD_SIZE);
    end   = ROUND_UP(end,     PMD_SIZE);



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    EARLY_ASSERT_EXECUTION(initializePageIdentity((PGD *)topLevelPage, start, end, 5), NgosStatus::ASSERTION);
#else
    EARLY_ASSERT_EXECUTION(initializePageIdentity((PGD *)topLevelPage, start, end, 4), NgosStatus::ASSERTION);
#endif



    return NgosStatus::OK;
}

NgosStatus finalizeIdentityMaps()
{
    EARLY_LT((""));



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    switchToFiveLevelPaging(topLevelPage);
#else
    EARLY_ASSERT_EXECUTION(writeCr3((u64)topLevelPage), NgosStatus::ASSERTION);
#endif



    return NgosStatus::OK;
}
