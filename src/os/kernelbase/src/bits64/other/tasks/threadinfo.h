#ifndef OS_COMMON_SRC_BITS64_TASKS_THREADINFO_H
#define OS_COMMON_SRC_BITS64_TASKS_THREADINFO_H



#include <ngos/types.h>
#include <src/bits64/other/tasks/threadinfoflags.h>



struct ThreadInfo
{
    thread_info_flags flags;
};



#endif // OS_COMMON_SRC_BITS64_TASKS_THREADINFO_H
