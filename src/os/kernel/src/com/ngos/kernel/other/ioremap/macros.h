#ifndef COM_NGOS_KERNEL_OTHER_IOREMAP_MACROS_H
#define COM_NGOS_KERNEL_OTHER_IOREMAP_MACROS_H



#include <com/ngos/kernel/other/ioremap/fixmap.h>
#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/pagetable/macros.h>



#define FIX_BITMAP_SLOTS      8
#define NUMBER_OF_FIX_BITMAPS 64
#define TOTAL_FIX_BITMAPS     (FIX_BITMAP_SLOTS * NUMBER_OF_FIX_BITMAPS)

#define FIX_ADDRESS_BOTTOM 0xFFFFFFFFFF200000
#define FIX_ADDRESS_TOP    0xFFFFFFFFFF3FF000
#define FIX_BITMAP_END     ROUND_UP((u64)FixMap::MAXIMUM, PTRS_PER_PTE)
#define FIX_BITMAP_BEGIN   FIX_BITMAP_END + TOTAL_FIX_BITMAPS - 1



#endif // COM_NGOS_KERNEL_OTHER_IOREMAP_MACROS_H
