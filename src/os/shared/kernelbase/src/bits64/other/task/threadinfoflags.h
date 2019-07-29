#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 thread_info_flags;

enum class ThreadInfoFlag: thread_info_flags
{
    NONE = 0
};



inline const char8* threadInfoFlagToString(ThreadInfoFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case ThreadInfoFlag::NONE: return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* threadInfoFlagsToString(thread_info_flags flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char8 res[13];

    FLAGS_TO_STRING(res, flags, threadInfoFlagToString, ThreadInfoFlag);

    return res;
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H
