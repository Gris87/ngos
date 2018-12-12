#ifndef PAGETABLE_UTILS_H
#define PAGETABLE_UTILS_H



#include <ngos/types.h>
#include <pagetable/flags.h>
#include <pagetable/macros.h>
#include <pagetable/types.h>



inline u64 pgdIndex(u64 address) // TEST: NO
{
    return (address >> PGD_SHIFT) & (PTRS_PER_PGD - 1);
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline u64 p4dIndex(u64 address) // TEST: NO
{
    return (address >> P4D_SHIFT) & (PTRS_PER_P4D - 1);
}
#endif

inline u64 pudIndex(u64 address) // TEST: NO
{
    return (address >> PUD_SHIFT) & (PTRS_PER_PUD - 1);
}

inline u64 pmdIndex(u64 address) // TEST: NO
{
    return (address >> PMD_SHIFT) & (PTRS_PER_PMD - 1);
}

inline u64 pteIndex(u64 address) // TEST: NO
{
    return (address >> PAGE_SHIFT) & (PTRS_PER_PTE - 1);
}



// --------------------------------------------------------------



inline void setPgd(PGD *pgd, pgd_value value) // TEST: NO
{
    pgd->pgd = value;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline void setP4d(P4D *p4d, p4d_value value) // TEST: NO
{
    p4d->p4d = value;
}
#endif

inline void setPud(PUD *pud, pud_value value) // TEST: NO
{
    pud->pud = value;
}

inline void setPmd(PMD *pmd, pmd_value value) // TEST: NO
{
    pmd->pmd = value;
}

inline void setPte(PTE *pte, pte_value value) // TEST: NO
{
    pte->pte = value;
}



// --------------------------------------------------------------



inline pgd_value pgdValue(PGD pgd) // TEST: NO
{
    return pgd.pgd;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline p4d_value p4dValue(P4D p4d) // TEST: NO
{
    return p4d.p4d;
}
#endif

inline pud_value pudValue(PUD pud) // TEST: NO
{
    return pud.pud;
}

inline pmd_value pmdValue(PMD pmd) // TEST: NO
{
    return pmd.pmd;
}

inline pte_value pteValue(PTE pte) // TEST: NO
{
    return pte.pte;
}



// --------------------------------------------------------------



inline bool pgdPresent(PGD pgd) // TEST: NO
{
    return pgdValue(pgd) & PAGE_FLAG_PRESENT;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline bool p4dPresent(P4D p4d) // TEST: NO
{
    return p4dValue(p4d) & PAGE_FLAG_PRESENT;
}
#endif

inline bool pudPresent(PUD pud) // TEST: NO
{
    return pudValue(pud) & PAGE_FLAG_PRESENT;
}

inline bool pmdPresent(PMD pmd) // TEST: NO
{
    return pmdValue(pmd) & PAGE_FLAG_PRESENT;
}

inline bool ptePresent(PTE pte) // TEST: NO
{
    return pteValue(pte) & PAGE_FLAG_PRESENT;
}



// --------------------------------------------------------------



inline bool pgdExtended(PGD pgd) // TEST: NO
{
    return pgdValue(pgd) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline bool p4dExtended(P4D p4d) // TEST: NO
{
    return p4dValue(p4d) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}
#endif

inline bool pudExtended(PUD pud) // TEST: NO
{
    return pudValue(pud) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}

inline bool pmdExtended(PMD pmd) // TEST: NO
{
    return pmdValue(pmd) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}

inline bool pteExtended(PTE pte) // TEST: NO
{
    return pteValue(pte) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}



// --------------------------------------------------------------



inline pgd_value pgdPfnMask(PGD /*pgd*/) // TEST: NO
{
    // Ignore CppAlignmentVerifier [BEGIN]
    // if (pgdExtended(pgd))
    // {
    //     return PHYSICAL_PGD_PAGE_MASK;
    // }
    // else
    // {
    //     return PTE_PFN_MASK;
    // }
    // Ignore CppAlignmentVerifier [END]

    // No 256 TB huge pages
    return PTE_PFN_MASK;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline p4d_value p4dPfnMask(P4D /*p4d*/) // TEST: NO
{
    // Ignore CppAlignmentVerifier [BEGIN]
    // if (p4dExtended(p4d))
    // {
    //     return PHYSICAL_P4D_PAGE_MASK;
    // }
    // else
    // {
    //     return PTE_PFN_MASK;
    // }
    // Ignore CppAlignmentVerifier [END]

    // No 512 GB huge pages
    return PTE_PFN_MASK;
}
#endif

inline pud_value pudPfnMask(PUD pud) // TEST: NO
{
    if (pudExtended(pud))
    {
        return PHYSICAL_PUD_PAGE_MASK;
    }
    else
    {
        return PTE_PFN_MASK;
    }
}

inline pmd_value pmdPfnMask(PMD pmd) // TEST: NO
{
    if (pmdExtended(pmd))
    {
        return PHYSICAL_PMD_PAGE_MASK;
    }
    else
    {
        return PTE_PFN_MASK;
    }
}

inline pte_value ptePfnMask(PTE /*pte*/) // TEST: NO
{
    return PTE_PFN_MASK;
}



// --------------------------------------------------------------



inline pgd_value pgdFlagsMask(PGD pgd) // TEST: NO
{
    return ~pgdPfnMask(pgd);
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline p4d_value p4dFlagsMask(P4D p4d) // TEST: NO
{
    return ~p4dPfnMask(p4d);
}
#endif

inline pud_value pudFlagsMask(PUD pud) // TEST: NO
{
    return ~pudPfnMask(pud);
}

inline pmd_value pmdFlagsMask(PMD pmd) // TEST: NO
{
    return ~pmdPfnMask(pmd);
}

inline pte_value pteFlagsMask(PTE pte) // TEST: NO
{
    return ~ptePfnMask(pte);
}



// --------------------------------------------------------------



inline pgd_value pgdFlags(PGD pgd) // TEST: NO
{
    return pgdValue(pgd) & pgdFlagsMask(pgd);
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline p4d_value p4dFlags(P4D p4d) // TEST: NO
{
    return p4dValue(p4d) & p4dFlagsMask(p4d);
}
#endif

inline pud_value pudFlags(PUD pud) // TEST: NO
{
    return pudValue(pud) & pudFlagsMask(pud);
}

inline pmd_value pmdFlags(PMD pmd) // TEST: NO
{
    return pmdValue(pmd) & pmdFlagsMask(pmd);
}

inline pte_value pteFlags(PTE pte) // TEST: NO
{
    return pteValue(pte) & pteFlagsMask(pte);
}



// --------------------------------------------------------------



inline u64 pgdPageVirtualAddress(PGD pgd) // TEST: NO
{
    return (u64)(pgdValue(pgd) & pgdPfnMask(pgd));
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline u64 p4dPageVirtualAddress(P4D p4d) // TEST: NO
{
    return (u64)(p4dValue(p4d) & p4dPfnMask(p4d));
}
#endif

inline u64 pudPageVirtualAddress(PUD pud) // TEST: NO
{
    return (u64)(pudValue(pud) & pudPfnMask(pud));
}

inline u64 pmdPageVirtualAddress(PMD pmd) // TEST: NO
{
    return (u64)(pmdValue(pmd) & pmdPfnMask(pmd));
}

inline u64 ptePageVirtualAddress(PTE pte) // TEST: NO
{
    return (u64)(pteValue(pte) & ptePfnMask(pte));
}



// --------------------------------------------------------------



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline P4D* p4dOffset(PGD *pgd, u64 address) // TEST: NO
{
    return (P4D *)pgdPageVirtualAddress(*pgd) + p4dIndex(address);
}

inline PUD* pudOffset(P4D *p4d, u64 address) // TEST: NO
{
    return (PUD *)p4dPageVirtualAddress(*p4d) + pudIndex(address);
}
#else
inline PUD* pudOffset(PGD *pgd, u64 address) // TEST: NO
{
    return (PUD *)pgdPageVirtualAddress(*pgd) + pudIndex(address);
}
#endif

inline PMD* pmdOffset(PUD *pud, u64 address) // TEST: NO
{
    return (PMD *)pudPageVirtualAddress(*pud) + pmdIndex(address);
}

inline PTE* pteOffset(PMD *pmd, u64 address) // TEST: NO
{
    return (PTE *)pmdPageVirtualAddress(*pmd) + pteIndex(address);
}



#endif // PAGETABLE_UTILS_H
