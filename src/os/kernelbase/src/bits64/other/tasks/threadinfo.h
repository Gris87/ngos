#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_THREADINFO_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_THREADINFO_H



#include <ngos/types.h>
#include <src/bits64/other/tasks/threadinfoflags.h>



struct ThreadInfo
{
    thread_info_flags flags;
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_THREADINFO_H
