#ifndef COM_NGOS_KERNEL_OTHER_IOREMAP_UTILS_H
#define COM_NGOS_KERNEL_OTHER_IOREMAP_UTILS_H



#include <com/ngos/kernel/other/ioremap/macros.h>
#include <com/ngos/shared/common/page/macros.h>



#define FIX_ADDRESS_TO_VIRTUAL(x) (FIX_ADDRESS_TOP - ((x) << PAGE_SHIFT))



#endif // COM_NGOS_KERNEL_OTHER_IOREMAP_UTILS_H
