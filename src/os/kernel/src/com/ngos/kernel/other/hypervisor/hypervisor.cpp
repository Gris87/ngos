#include "hypervisor.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>

#include <com/ngos/kernel/other/hypervisor/kvm/kvm.h>



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
