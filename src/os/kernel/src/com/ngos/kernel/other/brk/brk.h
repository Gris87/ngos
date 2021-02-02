#ifndef COM_NGOS_KERNEL_OTHER_BRK_BRK_H
#define COM_NGOS_KERNEL_OTHER_BRK_BRK_H



#include <com/ngos/shared/common/ngos/status.h>



class BRK
{
public:
    static NgosStatus init();

    static NgosStatus allocate(bad_uint64 size, bad_uint64 align, bad_uint8 **result);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static bad_uint64 sBegin;
    static bad_uint64 sEnd;
};



#endif // COM_NGOS_KERNEL_OTHER_BRK_BRK_H
