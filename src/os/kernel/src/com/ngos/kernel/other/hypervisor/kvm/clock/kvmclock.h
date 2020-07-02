#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H



#include <ngos/status.h>



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



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_CLOCK_KVMCLOCK_H
