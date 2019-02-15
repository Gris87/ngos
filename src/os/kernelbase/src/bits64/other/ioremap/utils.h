#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_UTILS_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_UTILS_H



#include <page/macros.h>
#include <src/bits64/other/ioremap/macros.h>



#define FIX_ADDRESS_TO_VIRTUAL(x) (FIX_ADDRESS_TOP - ((x) << PAGE_SHIFT))



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_UTILS_H
