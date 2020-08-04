#ifndef COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H
#define COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H



#include <com/ngos/shared/common/ngos/status.h>



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



#endif // COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H
