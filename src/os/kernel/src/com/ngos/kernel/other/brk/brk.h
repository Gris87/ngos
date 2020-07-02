#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_BRK_BRK_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_BRK_BRK_H



#include <ngos/status.h>



class BRK
{
public:
    static NgosStatus init();

    static NgosStatus allocate(u64 size, u64 align, u8 **result);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static u64 sBegin;
    static u64 sEnd;
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_BRK_BRK_H
