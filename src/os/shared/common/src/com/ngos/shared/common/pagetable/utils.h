#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PAGETABLE_UTILS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PAGETABLE_UTILS_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/pagetable/flags.h>
#include <common/src/com/ngos/shared/common/pagetable/macros.h>
#include <common/src/com/ngos/shared/common/pagetable/types.h>



inline u64 pgdIndex(u64 address)
{
    COMMON_LT((" | address = 0x%016lX", address));



    return (address >> PGD_SHIFT) & (PTRS_PER_PGD - 1);
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline u64 p4dIndex(u64 address)
{
    COMMON_LT((" | address = 0x%016lX", address));



    return (address >> P4D_SHIFT) & (PTRS_PER_P4D - 1);
}
#endif

inline u64 pudIndex(u64 address)
{
    COMMON_LT((" | address = 0x%016lX", address));



    return (address >> PUD_SHIFT) & (PTRS_PER_PUD - 1);
}

inline u64 pmdIndex(u64 address)
{
    COMMON_LT((" | address = 0x%016lX", address));



    return (address >> PMD_SHIFT) & (PTRS_PER_PMD - 1);
}

inline u64 pteIndex(u64 address)
{
    COMMON_LT((" | address = 0x%016lX", address));



    return (address >> PAGE_SHIFT) & (PTRS_PER_PTE - 1);
}



// --------------------------------------------------------------



inline void setPgd(PGD *pgd, pgd_value value)
{
    COMMON_LT((" | pgd = 0x%p, value = 0x%016lX", pgd, value));



    pgd->pgd = value;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline void setP4d(P4D *p4d, p4d_value value)
{
    COMMON_LT((" | p4d = 0x%p, value = 0x%016lX", p4d, value));



    p4d->p4d = value;
}
#endif

inline void setPud(PUD *pud, pud_value value)
{
    COMMON_LT((" | pud = 0x%p, value = 0x%016lX", pud, value));



    pud->pud = value;
}

inline void setPmd(PMD *pmd, pmd_value value)
{
    COMMON_LT((" | pmd = 0x%p, value = 0x%016lX", pmd, value));



    pmd->pmd = value;
}

inline void setPte(PTE *pte, pte_value value)
{
    COMMON_LT((" | pte = 0x%p, value = 0x%016lX", pte, value));



    pte->pte = value;
}



// --------------------------------------------------------------



inline pgd_value pgdValue(const PGD &pgd)
{
    COMMON_LT((" | pgd = ..."));



    return pgd.pgd;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline p4d_value p4dValue(const P4D &p4d)
{
    COMMON_LT((" | p4d = ..."));



    return p4d.p4d;
}
#endif

inline pud_value pudValue(const PUD &pud)
{
    COMMON_LT((" | pud = ..."));



    return pud.pud;
}

inline pmd_value pmdValue(const PMD &pmd)
{
    COMMON_LT((" | pmd = ..."));



    return pmd.pmd;
}

inline pte_value pteValue(const PTE &pte)
{
    COMMON_LT((" | pte = ..."));



    return pte.pte;
}



// --------------------------------------------------------------



inline bool pgdPresent(const PGD &pgd)
{
    COMMON_LT((" | pgd = ..."));



    return pgdValue(pgd) & PAGE_FLAG_PRESENT;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline bool p4dPresent(const P4D &p4d)
{
    COMMON_LT((" | p4d = ..."));



    return p4dValue(p4d) & PAGE_FLAG_PRESENT;
}
#endif

inline bool pudPresent(const PUD &pud)
{
    COMMON_LT((" | pud = ..."));



    return pudValue(pud) & PAGE_FLAG_PRESENT;
}

inline bool pmdPresent(const PMD &pmd)
{
    COMMON_LT((" | pmd = ..."));



    return pmdValue(pmd) & PAGE_FLAG_PRESENT;
}

inline bool ptePresent(const PTE &pte)
{
    COMMON_LT((" | pte = ..."));



    return pteValue(pte) & PAGE_FLAG_PRESENT;
}



// --------------------------------------------------------------



inline bool pgdExtended(const PGD &pgd)
{
    COMMON_LT((" | pgd = ..."));



    return pgdValue(pgd) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline bool p4dExtended(const P4D &p4d)
{
    COMMON_LT((" | p4d = ..."));



    return p4dValue(p4d) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}
#endif

inline bool pudExtended(const PUD &pud)
{
    COMMON_LT((" | pud = ..."));



    return pudValue(pud) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}

inline bool pmdExtended(const PMD &pmd)
{
    COMMON_LT((" | pmd = ..."));



    return pmdValue(pmd) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}

inline bool pteExtended(const PTE &pte)
{
    COMMON_LT((" | pte = ..."));



    return pteValue(pte) & PAGE_FLAG_PAGE_SIZE_EXTENSION;
}



// --------------------------------------------------------------



inline pgd_value pgdPfnMask(const PGD &/*pgd*/)
{
    COMMON_LT((" | pgd = ..."));



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
inline p4d_value p4dPfnMask(const P4D &/*p4d*/)
{
    COMMON_LT((" | p4d = ..."));



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

inline pud_value pudPfnMask(const PUD &pud)
{
    COMMON_LT((" | pud = ..."));



    if (pudExtended(pud))
    {
        return PHYSICAL_PUD_PAGE_MASK;
    }
    else
    {
        return PTE_PFN_MASK;
    }
}

inline pmd_value pmdPfnMask(const PMD &pmd)
{
    COMMON_LT((" | pmd = ..."));



    if (pmdExtended(pmd))
    {
        return PHYSICAL_PMD_PAGE_MASK;
    }
    else
    {
        return PTE_PFN_MASK;
    }
}

inline pte_value ptePfnMask(const PTE &/*pte*/)
{
    COMMON_LT((" | pte = ..."));



    return PTE_PFN_MASK;
}



// --------------------------------------------------------------



inline pgd_value pgdFlagsMask(const PGD &pgd)
{
    COMMON_LT((" | pgd = ..."));



    return ~pgdPfnMask(pgd);
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline p4d_value p4dFlagsMask(const P4D &p4d)
{
    COMMON_LT((" | p4d = ..."));



    return ~p4dPfnMask(p4d);
}
#endif

inline pud_value pudFlagsMask(const PUD &pud)
{
    COMMON_LT((" | pud = ..."));



    return ~pudPfnMask(pud);
}

inline pmd_value pmdFlagsMask(const PMD &pmd)
{
    COMMON_LT((" | pmd = ..."));



    return ~pmdPfnMask(pmd);
}

inline pte_value pteFlagsMask(const PTE &pte)
{
    COMMON_LT((" | pte = ..."));



    return ~ptePfnMask(pte);
}



// --------------------------------------------------------------



inline pgd_value pgdFlags(const PGD &pgd)
{
    COMMON_LT((" | pgd = ..."));



    return pgdValue(pgd) & pgdFlagsMask(pgd);
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline p4d_value p4dFlags(const P4D &p4d)
{
    COMMON_LT((" | p4d = ..."));



    return p4dValue(p4d) & p4dFlagsMask(p4d);
}
#endif

inline pud_value pudFlags(const PUD &pud)
{
    COMMON_LT((" | pud = ..."));



    return pudValue(pud) & pudFlagsMask(pud);
}

inline pmd_value pmdFlags(const PMD &pmd)
{
    COMMON_LT((" | pmd = ..."));



    return pmdValue(pmd) & pmdFlagsMask(pmd);
}

inline pte_value pteFlags(const PTE &pte)
{
    COMMON_LT((" | pte = ..."));



    return pteValue(pte) & pteFlagsMask(pte);
}



// --------------------------------------------------------------



inline u64 pgdPageVirtualAddress(const PGD &pgd)
{
    COMMON_LT((" | pgd = ..."));



    return (u64)(pgdValue(pgd) & pgdPfnMask(pgd));
}

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline u64 p4dPageVirtualAddress(const P4D &p4d)
{
    COMMON_LT((" | p4d = ..."));



    return (u64)(p4dValue(p4d) & p4dPfnMask(p4d));
}
#endif

inline u64 pudPageVirtualAddress(const PUD &pud)
{
    COMMON_LT((" | pud = ..."));



    return (u64)(pudValue(pud) & pudPfnMask(pud));
}

inline u64 pmdPageVirtualAddress(const PMD &pmd)
{
    COMMON_LT((" | pmd = ..."));



    return (u64)(pmdValue(pmd) & pmdPfnMask(pmd));
}

inline u64 ptePageVirtualAddress(const PTE &pte)
{
    COMMON_LT((" | pte = ..."));



    return (u64)(pteValue(pte) & ptePfnMask(pte));
}



// --------------------------------------------------------------



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
inline P4D* p4dOffset(PGD *pgd, u64 address)
{
    COMMON_LT((" | pgd = 0x%p, address = 0x%016lX", pgd, address));



    return (P4D *)pgdPageVirtualAddress(*pgd) + p4dIndex(address);
}

inline PUD* pudOffset(P4D *p4d, u64 address)
{
    COMMON_LT((" | p4d = 0x%p, address = 0x%016lX", p4d, address));



    return (PUD *)p4dPageVirtualAddress(*p4d) + pudIndex(address);
}
#else
inline PUD* pudOffset(PGD *pgd, u64 address)
{
    COMMON_LT((" | pgd = 0x%p, address = 0x%016lX", pgd, address));



    return (PUD *)pgdPageVirtualAddress(*pgd) + pudIndex(address);
}
#endif

inline PMD* pmdOffset(PUD *pud, u64 address)
{
    COMMON_LT((" | pud = 0x%p, address = 0x%016lX", pud, address));



    return (PMD *)pudPageVirtualAddress(*pud) + pmdIndex(address);
}

inline PTE* pteOffset(PMD *pmd, u64 address)
{
    COMMON_LT((" | pmd = 0x%p, address = 0x%016lX", pmd, address));



    return (PTE *)pmdPageVirtualAddress(*pmd) + pteIndex(address);
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PAGETABLE_UTILS_H
