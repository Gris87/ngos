#include <common/src/bits64/assets/assets.h>
#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/kerneldefines.h>
#include <kernelbase/src/bits64/other/pagetable/addressconversion.h>
#include <ngos/linkage.h>
#include <pagetable/utils.h>



extern void *_start;                                                           // _start declared in main.S file // Ignore CppEqualAlignmentVerifier
extern PGD   early_pagetable[PTRS_PER_PGD];                                    // early_pagetable declared in main.S file

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
extern P4D   early_pagetable_level4[PTRS_PER_P4D];                             // early_pagetable_level4 declared in main.S file
#endif

extern PUD   early_pagetable_level3[PTRS_PER_PUD];                                 // early_pagetable_level3 declared in main.S file
extern PMD   early_pagetable_level2[PTRS_PER_PMD];                                 // early_pagetable_level2 declared in main.S file
extern PMD   fixmap_pagetable_level2[PTRS_PER_PMD];                                // fixmap_pagetable_level2 declared in main.S file
extern PMD   dynamic_pagetable_pages[EARLY_DYNAMIC_PAGE_TABLES][PTRS_PER_PMD];     // dynamic_pagetable_pages declared in main.S file
extern PMD   video_ram_pagetable_pages[EARLY_VIDEO_RAM_PAGE_TABLES][PTRS_PER_PMD]; // video_ram_pagetable_pages declared in main.S file



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE
NgosStatus printPte(PTE *pte)
{
    EARLY_LT((" | pte = 0x%p", pte));

    EARLY_ASSERT(pte, "pte is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_PTE; ++i)
    {
        if (ptePresent(pte[i]))
        {
            EARLY_LVV(("        pte[%d] = 0x%016lX", i, pteValue(pte[i])));
        }
    }



    return NgosStatus::OK;
}

NgosStatus printPmd(PMD *pmd)
{
    EARLY_LT((" | pmd = 0x%p", pmd));

    EARLY_ASSERT(pmd, "pmd is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_PMD; ++i)
    {
        if (pmdPresent(pmd[i]))
        {
            EARLY_LVV(("      pmd[%d] = 0x%016lX", i, pmdValue(pmd[i])));

            if (!pmdExtended(pmd[i]))
            {
                EARLY_ASSERT_EXECUTION(printPte((PTE *)pmdPageVirtualAddress(pmd[i])), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus printPud(PUD *pud)
{
    EARLY_LT((" | pud = 0x%p", pud));

    EARLY_ASSERT(pud, "pud is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_PUD; ++i)
    {
        if (pudPresent(pud[i]))
        {
            EARLY_LVV(("    pud[%d] = 0x%016lX", i, pudValue(pud[i])));

            if (!pudExtended(pud[i]))
            {
                EARLY_ASSERT_EXECUTION(printPmd((PMD *)pudPageVirtualAddress(pud[i])), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
NgosStatus printP4d(P4D *p4d)
{
    EARLY_LT((" | p4d = 0x%p", p4d));

    EARLY_ASSERT(p4d, "p4d is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_P4D; ++i)
    {
        if (p4dPresent(p4d[i]))
        {
            EARLY_LVV(("  p4d[%d] = 0x%016lX", i, p4dValue(p4d[i])));

            if (!p4dExtended(p4d[i]))
            {
                EARLY_ASSERT_EXECUTION(printPud((PUD *)p4dPageVirtualAddress(p4d[i])), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}
#endif

NgosStatus printPgd(PGD *pgd)
{
    EARLY_LT((" | pgd = 0x%p", pgd));

    EARLY_ASSERT(pgd, "pgd is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < PTRS_PER_PGD; ++i)
    {
        if (pgdPresent(pgd[i]))
        {
            EARLY_LVV(("pgd[%d] = 0x%016lX", i, pgdValue(pgd[i])));

            if (!pgdExtended(pgd[i]))
            {
#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
                EARLY_ASSERT_EXECUTION(printP4d((P4D *)pgdPageVirtualAddress(pgd[i])), NgosStatus::ASSERTION);
#else
                EARLY_ASSERT_EXECUTION(printPud((PUD *)pgdPageVirtualAddress(pgd[i])), NgosStatus::ASSERTION);
#endif
            }
        }
    }



    return NgosStatus::OK;
}
#endif

NgosStatus adaptPredefinedPageTable(u64 imageLocation, PGD *pgd)
{
    EARLY_LT((" | imageLocation = 0x%p, pgd = 0x%p", imageLocation, pgd));

    EARLY_ASSERT(imageLocation, "imageLocation is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(pgd,           "pgd is null",           NgosStatus::ASSERTION);



    // =====================================================================
    // Update predefined entries of page table in order to let them point
    // to valid physical address where the image was loaded
    // =====================================================================



    // HACK: Temporary fix for PIE. Try to find another solution
    // #if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    //     P4D *p4d = (P4D *)((u64)&early_pagetable_level4 + imageLocation);
    // #endif
    //
    // PUD *pud = (PUD *)((u64)&early_pagetable_level3  + imageLocation);
    // PMD *pmd = (PMD *)((u64)&fixmap_pagetable_level2 + imageLocation);

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    P4D *p4d;
#endif

    PUD *pud;
    PMD *pmd;



    // ---------------------------------------------------------------------



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    early_pagetable_level4(%%rip),  %0"    "\n\t" // leaq    early_pagetable_level4(%rip),  %r14   # Get address of early_pagetable_level4 variable to R14. %R14 == p4d
        "leaq    early_pagetable_level3(%%rip),  %1"    "\n\t" // leaq    early_pagetable_level3(%rip),  %rbp   # Get address of early_pagetable_level3 variable to RBP. %RBP == pud
        "leaq    fixmap_pagetable_level2(%%rip), %2"           // leaq    fixmap_pagetable_level2(%rip), %r13   # Get address of fixmap_pagetable_level2 variable to R13. %R13 == pmd
            :                                                  // Output parameters
                "=r" (p4d),                                    // "r" == any general register, "=" - write only
                "=r" (pud),                                    // "r" == any general register, "=" - write only
                "=r" (pmd)                                     // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]
#else
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    early_pagetable_level3(%%rip),  %0"    "\n\t" // leaq    early_pagetable_level3(%rip),  %rbp   # Get address of early_pagetable_level3 variable to RBP. %RBP == pud
        "leaq    fixmap_pagetable_level2(%%rip), %1"           // leaq    fixmap_pagetable_level2(%rip), %r13   # Get address of fixmap_pagetable_level2 variable to R13. %R13 == pmd
            :                                                  // Output parameters
                "=r" (pud),                                    // "r" == any general register, "=" - write only
                "=r" (pmd)                                     // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]
#endif



    // ---------------------------------------------------------------------



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    EARLY_LVVV(("p4d = 0x%p", p4d));
#endif

    EARLY_LVVV(("pud = 0x%p", pud));
    EARLY_LVVV(("pmd = 0x%p", pmd));



    // ---------------------------------------------------------------------



    // (u64)&_start give us chosen random virtual address
    // We are substracting (u64)&_start since the predefined values already has values with the base address as chosen random virtual address
    u64 delta = imageLocation - (u64)&_start;

    EARLY_LVVV(("delta = 0x%016lX", delta));

    EARLY_TEST_ASSERT(delta != 0, NgosStatus::ASSERTION);



    pgd[511].pgd += delta;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    p4d[511].p4d += delta;
#endif

    pud[510].pud += delta;
    pud[511].pud += delta;

    pmd[506].pmd += delta;



    return NgosStatus::OK;
}

NgosStatus adaptVirtualAddressSpacePageTable(u64 imageLocation)
{
    EARLY_LT((" | imageLocation = 0x%p", imageLocation));

    EARLY_ASSERT(imageLocation, "imageLocation is null", NgosStatus::ASSERTION);



    // =====================================================================
    // We have a set of PMD entries with 1 to 1 mapping for 1 GB in
    // page table. This set should map the same 1 GB but starting from
    // image location. It let us use virtual address space:
    // 0xFFFFFFFF80000000 - 0xFFFFFFFFC0000000
    // =====================================================================



    // HACK: Temporary fix for PIE. Try to find another solution
    // PMD *pmd = (PMD *)((u64)&early_pagetable_level2 + imageLocation);

    PMD *pmd;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    early_pagetable_level2(%%rip), %0" // leaq    early_pagetable_level2(%rip), %rbx   # Get address of early_pagetable_level2 variable to RBX. %RBX == pmd
            :                                       // Output parameters
                "=r" (pmd)                          // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]



    EARLY_LVVV(("pmd = 0x%p", pmd));



    // (u64)&_start give us chosen random virtual address
    u64 delta = imageLocation - ((u64)&_start - 0xFFFFFFFF80000000);

    EARLY_LVVV(("delta = 0x%016lX", delta));

    if (!delta) // delta == 0 // Relocation not needed
    {
        return NgosStatus::OK;
    }



    for (i64 i = 0; i < PTRS_PER_PMD; ++i)
    {
        if (pmdPresent(pmd[i]))
        {
            if ((i64)(pmd[i].pmd + delta) >= 0)
            {
                pmd[i].pmd += delta;
            }
            else
            {
                pmd[i].pmd = 0;
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus adaptVideoRamPageTable(u64 imageLocation, BootParams *params, PGD *pgd)
{
    EARLY_LT((" | imageLocation = 0x%p, params = 0x%p, pgd = 0x%p", imageLocation, params, pgd));

    EARLY_ASSERT(imageLocation, "imageLocation is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(params,        "params is null",        NgosStatus::ASSERTION);
    EARLY_ASSERT(pgd,           "pgd is null",           NgosStatus::ASSERTION);



    u8 pageIndex = 0;

    // HACK: Temporary fix for PIE. Try to find another solution
    u64 videoRamPagetablePages;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    video_ram_pagetable_pages(%%rip), %0"  // leaq    video_ram_pagetable_pages(%rip), %rbp     # Get address of video_ram_pagetable_pages variable to RBP. %RBP == videoRamPagetablePages
            :                                           // Output parameters
                "=r" (videoRamPagetablePages)           // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    P4D *p4d = (P4D *)(videoRamPagetablePages + pageIndex * PAGE_SIZE);
    ++pageIndex;
#endif

    EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    PUD *pud = (PUD *)(videoRamPagetablePages + pageIndex * PAGE_SIZE);
    ++pageIndex;

    EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    PMD *pmd = (PMD *)(videoRamPagetablePages + pageIndex * PAGE_SIZE);
    ++pageIndex;



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    EARLY_LVVV(("p4d = 0x%p", p4d));
#endif

    EARLY_LVVV(("pud = 0x%p", pud));
    EARLY_LVVV(("pmd = 0x%p", pmd));



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    pgd[pgdIndex(imageLocation)].pgd = (u64)p4d       | KERNEL_PAGE_TABLE_FLAGS;
    p4d[pgdIndex(imageLocation)].p4d = (u64)pud       | KERNEL_PAGE_TABLE_FLAGS;
#else
    pgd[pgdIndex(imageLocation)].pgd = (u64)pud       | KERNEL_PAGE_TABLE_FLAGS;
#endif

    pud[pudIndex(imageLocation)].pud = (u64)pmd       | KERNEL_PAGE_TABLE_FLAGS;
    pmd[pmdIndex(imageLocation)].pmd = (imageLocation | KERNEL_PAGE_LARGE_EXEC_FLAGS) & ~PAGE_FLAG_GLOBAL;



    return NgosStatus::OK;
}

NgosStatus adaptLastResortPageTable(u64 imageLocation, PGD *pgd)
{
    EARLY_LT((" | imageLocation = 0x%p, pgd = 0x%p", imageLocation, pgd));

    EARLY_ASSERT(imageLocation, "imageLocation is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(pgd,           "pgd is null",           NgosStatus::ASSERTION);



    // =====================================================================
    // We are living not in the ideal world unfortunately.
    // So we have to create additional mapping in page table that let us
    // complete the remaining instructions for jumping to virtual address
    // space. We can't do that without such mapping since the code become
    // unavailable after updating CR3 register.
    // =====================================================================



    u8 pageIndex = 0;

    // HACK: Temporary fix for PIE. Try to find another solution
    // #if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    //     EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    //     P4D *p4d = (P4D *)((u64)&dynamic_pagetable_pages[pageIndex++] + imageLocation);
    // #endif
    //
    // EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    // PUD *pud = (PUD *)((u64)&dynamic_pagetable_pages[pageIndex++] + imageLocation);
    //
    // EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    // PMD *pmd = (PMD *)((u64)&dynamic_pagetable_pages[pageIndex++] + imageLocation);

    u64 dynamicPagetablePages;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    dynamic_pagetable_pages(%%rip), %0" // leaq    dynamic_pagetable_pages(%rip), %rbp     # Get address of dynamic_pagetable_pages variable to RBP. %RBP == dynamicPagetablePages
            :                                        // Output parameters
                "=r" (dynamicPagetablePages)         // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    P4D *p4d = (P4D *)(dynamicPagetablePages + pageIndex * PAGE_SIZE);
    ++pageIndex;
#endif

    EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    PUD *pud = (PUD *)(dynamicPagetablePages + pageIndex * PAGE_SIZE);
    ++pageIndex;

    EARLY_TEST_ASSERT(pageIndex < EARLY_DYNAMIC_PAGE_TABLES, NgosStatus::ASSERTION);
    PMD *pmd = (PMD *)(dynamicPagetablePages + pageIndex * PAGE_SIZE);
    ++pageIndex;



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    EARLY_LVVV(("p4d = 0x%p", p4d));
#endif

    EARLY_LVVV(("pud = 0x%p", pud));
    EARLY_LVVV(("pmd = 0x%p", pmd));



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    pgd[pgdIndex(imageLocation)].pgd = (u64)p4d       | KERNEL_PAGE_TABLE_FLAGS;
    p4d[pgdIndex(imageLocation)].p4d = (u64)pud       | KERNEL_PAGE_TABLE_FLAGS;
#else
    pgd[pgdIndex(imageLocation)].pgd = (u64)pud       | KERNEL_PAGE_TABLE_FLAGS;
#endif

    pud[pudIndex(imageLocation)].pud = (u64)pmd       | KERNEL_PAGE_TABLE_FLAGS;
    pmd[pmdIndex(imageLocation)].pmd = (imageLocation | KERNEL_PAGE_LARGE_EXEC_FLAGS) & ~PAGE_FLAG_GLOBAL;



    return NgosStatus::OK;
}

CPP_EXTERN_C
NgosStatus adaptPageTable(u64 imageLocation, BootParams *params)
{
    // We can't output at the moment
    // EARLY_LT((" | imageLocation = 0x%p", imageLocation));



    EARLY_ASSERT_EXECUTION(Serial::initConsole(), NgosStatus::ASSERTION);



    EARLY_ASSERT_EXECUTION(Assets::init(), NgosStatus::ASSERTION);
    EARLY_LVV(("Assets initialized"));



    EARLY_ASSERT_EXECUTION(Console::init(params), NgosStatus::ASSERTION);
    EARLY_LVV(("Console initialized"));



    EARLY_LT((" | imageLocation = 0x%p", imageLocation));

    EARLY_ASSERT(imageLocation, "imageLocation is null", NgosStatus::ASSERTION);



    // HACK: Temporary fix for PIE. Try to find another solution
    // PGD *pgd = (PGD *)((u64)&early_pagetable + imageLocation);

    PGD *pgd;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    early_pagetable(%%rip), %0" // leaq    early_pagetable(%rip), %r12     # Get address of early_pagetable variable to R12. %R12 == pgd
            :                                // Output parameters
                "=r" (pgd)                   // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]

    EARLY_LVVV(("pgd = 0x%p", pgd));



    EARLY_ASSERT_EXECUTION(adaptPredefinedPageTable(imageLocation, pgd),       NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(adaptVirtualAddressSpacePageTable(imageLocation),   NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(adaptVideoRamPageTable(imageLocation, params, pgd), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(adaptLastResortPageTable(imageLocation, pgd),       NgosStatus::ASSERTION);

    EARLY_ASSERT_EXECUTION(AddressConversion::setPhysicalDeltaBaseOnLocation(imageLocation), NgosStatus::ASSERTION);



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE
    EARLY_LVV(("Page table:"));

    EARLY_ASSERT_EXECUTION(printPgd(pgd), NgosStatus::ASSERTION);
#endif



    return NgosStatus::FAILED;
}
