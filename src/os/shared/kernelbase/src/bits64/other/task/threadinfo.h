#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFO_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFO_H



#include <kernelbase/src/bits64/other/task/threadinfoflags.h>
#include <ngos/types.h>



struct ThreadInfo
{
    thread_info_flags flags;
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFO_H
