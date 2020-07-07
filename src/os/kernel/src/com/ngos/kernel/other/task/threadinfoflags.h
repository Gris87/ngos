#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_THREADINFOFLAGS_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_THREADINFOFLAGS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 thread_info_flags;

enum class ThreadInfoFlag: thread_info_flags
{
    NONE = 0
};

DEFINE_FLAGS(ThreadInfoFlags, thread_info_flags); // TEST: NO



inline const char8* flagToString(ThreadInfoFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case ThreadInfoFlag::NONE: return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(ThreadInfoFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%08X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const ThreadInfoFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[13];

    FLAGS_TO_STRING(res, flags.flags, ThreadInfoFlag);

    return res;
}



inline const char8* flagsToFullString(const ThreadInfoFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[26];

    FLAGS_TO_FULL_STRING(res, flags.flags, ThreadInfoFlag, "0x%08X");

    return res;
}



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_THREADINFOFLAGS_H
