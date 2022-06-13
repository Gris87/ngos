#ifndef COM_NGOS_SHARED_COMMON_PAGE_MACROS_H
#define COM_NGOS_SHARED_COMMON_PAGE_MACROS_H



#include <com/ngos/shared/common/bits/macros.h>



#define PAGE_SHIFT 12
#define PAGE_SIZE  SIZE_BY_BITS(PAGE_SHIFT)
#define PAGE_MASK  (~(PAGE_SIZE - 1))



#endif // COM_NGOS_SHARED_COMMON_PAGE_MACROS_H
