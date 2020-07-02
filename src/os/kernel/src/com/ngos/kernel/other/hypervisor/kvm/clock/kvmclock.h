#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H



#include <common/src/com/ngos/shared/common/ngos/status.h>



class KvmClock
{
public:
    static NgosStatus init(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static u32 sWallClockMsr;
    static u32 sSystemTimeMsr;
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H
