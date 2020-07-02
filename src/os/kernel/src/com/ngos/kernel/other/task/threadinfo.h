#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_THREADINFO_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_THREADINFO_H



#include <ngos/types.h>

#include <src/com/ngos/kernel/other/task/threadinfoflags.h>



struct ThreadInfo
{
    ThreadInfoFlags flags;
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_THREADINFO_H
