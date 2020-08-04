#ifndef COM_NGOS_SHARED_COMMON_PAGETABLE_MACROS_H
#define COM_NGOS_SHARED_COMMON_PAGETABLE_MACROS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/page/macros.h>



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
#define PGD_SHIFT       48
#define P4D_SHIFT       39
#else
#define PGD_SHIFT       39
#endif

#define PUD_SHIFT       30
#define PMD_SHIFT       21



// --------------------------------------------------------------



#define PTRS_PER_PGD    512

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
#define PTRS_PER_P4D    512
#endif

#define PTRS_PER_PUD    512
#define PTRS_PER_PMD    512
#define PTRS_PER_PTE    512



// --------------------------------------------------------------



#define PGD_SIZE    (1ULL << PGD_SHIFT)

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
#define P4D_SIZE    (1ULL << P4D_SHIFT)
#endif

#define PUD_SIZE    (1ULL << PUD_SHIFT)
#define PMD_SIZE    (1ULL << PMD_SHIFT)



// --------------------------------------------------------------



#define PGD_MASK    (~(PGD_SIZE - 1))

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
#define P4D_MASK    (~(P4D_SIZE - 1))
#endif

#define PUD_MASK    (~(PUD_SIZE - 1))
#define PMD_MASK    (~(PMD_SIZE - 1))



// --------------------------------------------------------------



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
#define __PHYSICAL_MASK_SHIFT   52
#define __VIRTUAL_MASK_SHIFT    56
#else
#define __PHYSICAL_MASK_SHIFT   46
#define __VIRTUAL_MASK_SHIFT    47
#endif



#define __PHYSICAL_MASK     ((1ULL << __PHYSICAL_MASK_SHIFT) - 1)



#define PHYSICAL_PGD_PAGE_MASK  (PGD_MASK & __PHYSICAL_MASK)

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
#define PHYSICAL_P4D_PAGE_MASK  (P4D_MASK & __PHYSICAL_MASK)
#endif

#define PHYSICAL_PUD_PAGE_MASK  (PUD_MASK & __PHYSICAL_MASK)
#define PHYSICAL_PMD_PAGE_MASK  (PMD_MASK & __PHYSICAL_MASK)
#define PHYSICAL_PAGE_MASK      (PAGE_MASK & __PHYSICAL_MASK)



#define PTE_PFN_MASK    PHYSICAL_PAGE_MASK
#define PTE_FLAGS_MASK  (~PTE_PFN_MASK)



#endif // COM_NGOS_SHARED_COMMON_PAGETABLE_MACROS_H
