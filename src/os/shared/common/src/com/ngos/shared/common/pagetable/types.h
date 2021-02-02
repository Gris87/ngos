#ifndef COM_NGOS_SHARED_COMMON_PAGETABLE_TYPES_H
#define COM_NGOS_SHARED_COMMON_PAGETABLE_TYPES_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>



typedef bad_uint64 pgd_value;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
typedef bad_uint64 p4d_value;
#endif

typedef bad_uint64 pud_value;
typedef bad_uint64 pmd_value;
typedef bad_uint64 pte_value;



struct PGD
{
    pgd_value pgd;
};

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
struct P4D
{
    p4d_value p4d;
};
#endif

struct PUD
{
    pud_value pud;
};

struct PMD
{
    pmd_value pmd;
};

struct PTE
{
    pte_value pte;
};



#endif // COM_NGOS_SHARED_COMMON_PAGETABLE_TYPES_H
