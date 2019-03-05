#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_BRK_BRK_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_BRK_BRK_H



#include <ngos/status.h>


class BRK
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus allocate(u64 size, u64 align, u8 **result); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static u64 sBegin;
    static u64 sEnd;
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_BRK_BRK_H
