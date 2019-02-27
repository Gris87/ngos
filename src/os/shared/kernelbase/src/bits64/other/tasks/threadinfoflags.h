#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_THREADINFOFLAGS_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_THREADINFOFLAGS_H



#include <ngos/types.h>



typedef u32 thread_info_flags;

enum class ThreadInfoFlag: thread_info_flags
{
    NONE = 0
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_TASKS_THREADINFOFLAGS_H
