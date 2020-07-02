#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IOREMAP_UTILS_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IOREMAP_UTILS_H



#include <page/macros.h>

#include <src/com/ngos/kernel/other/ioremap/macros.h>



#define FIX_ADDRESS_TO_VIRTUAL(x) (FIX_ADDRESS_TOP - ((x) << PAGE_SHIFT))



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IOREMAP_UTILS_H
