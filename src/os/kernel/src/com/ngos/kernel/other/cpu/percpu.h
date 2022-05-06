#ifndef COM_NGOS_KERNEL_OTHER_CPU_PERCPU_H
#define COM_NGOS_KERNEL_OTHER_CPU_PERCPU_H



#include <com/ngos/shared/common/cpu/lib/registers/x86cr4flags.h>
#include <com/ngos/shared/common/ngos/types.h>



class PERCPU
{
public:
    static X86Cr4Flags cr4;
};



#endif // COM_NGOS_KERNEL_OTHER_CPU_PERCPU_H
