#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 thread_info_flags;

enum class ThreadInfoFlag: thread_info_flags
{
    NONE = 0
};

DEFINE_FLAGS(ThreadInfoFlags, thread_info_flags);



inline const char8* flagToString(ThreadInfoFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case ThreadInfoFlag::NONE: return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagsToString(const ThreadInfoFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags.flags)
    {
        return "NONE";
    }



    static char8 res[13];

    FLAGS_TO_STRING(res, flags.flags, flagToString, ThreadInfoFlag);

    return res;
}



inline const char8* flagsToFullString(const ThreadInfoFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags.flags)
    {
        return "NONE";
    }



    static char8 res[13];

    FLAGS_TO_STRING(res, flags.flags, flagToString, ThreadInfoFlag);

    return res;
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_TASK_THREADINFOFLAGS_H
