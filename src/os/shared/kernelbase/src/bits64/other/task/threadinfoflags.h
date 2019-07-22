#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H



#include <ngos/types.h>



typedef u32 thread_info_flags;

enum class ThreadInfoFlag: thread_info_flags
{
    NONE = 0
};



inline const char* threadInfoFlagToString(ThreadInfoFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case ThreadInfoFlag::NONE: return "NONE";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H
