#ifndef COM_NGOS_KERNEL_OTHER_KERNELDEFINES_H
#define COM_NGOS_KERNEL_OTHER_KERNELDEFINES_H



#include <buildconfig.h>
#include <com/ngos/shared/common/page/macros.h>



#define NUMBER_OF_CPUS      8192

#define EARLY_STACK_SIZE    (5 * PAGE_SIZE)
#define THREAD_SIZE         (4 * PAGE_SIZE)



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
#define EARLY_DYNAMIC_PAGE_TABLES     6
#else
#define EARLY_DYNAMIC_PAGE_TABLES     4
#endif



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
#define EARLY_VIDEO_RAM_PAGE_TABLES     6
#else
#define EARLY_VIDEO_RAM_PAGE_TABLES     4
#endif



#endif // COM_NGOS_KERNEL_OTHER_KERNELDEFINES_H
