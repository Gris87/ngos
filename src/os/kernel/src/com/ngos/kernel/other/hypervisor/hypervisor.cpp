#include "hypervisor.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <kernelbase/src/bits64/other/hypervisor/kvm/kvm.h>



HypervisorType Hypervisor::sType;



NgosStatus Hypervisor::init()
{
    COMMON_LT((""));



    sType = HypervisorType::NONE;

    if (KVM::init() == NgosStatus::OK)
    {
        sType = HypervisorType::KVM;

        COMMON_LV(("KVM hypervisor found"));
    }
    else
    {
        COMMON_LV(("Hypervisor not found"));
    }



    return NgosStatus::OK;
}
