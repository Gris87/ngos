#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURE_H



#include <ngos/types.h>



enum class KvmFeature: u8
{
    CLOCKSOURCE            = 0,
    NOP_IO_DELAY           = 1,
    MMU_OP                 = 2,
    CLOCKSOURCE2           = 3,
    ASYNC_PF               = 4,
    STEAL_TIME             = 5,
    PV_EOI                 = 6,
    PV_UNHALT              = 7,
    PV_TLB_FLUSH           = 9,
    ASYNC_PF_VMEXIT        = 10,
    PV_SEND_IPI            = 11,
    CLOCKSOURCE_STABLE_BIT = 24
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURE_H
