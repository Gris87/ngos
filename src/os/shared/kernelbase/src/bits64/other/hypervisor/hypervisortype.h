#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISORTYPE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISORTYPE_H



#include <ngos/types.h>



enum class HypervisorType: u8
{
    NONE = 0,
    KVM  = 1
};



inline const char8* hypervisorTypeToString(HypervisorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case HypervisorType::NONE: return "NONE";
        case HypervisorType::KVM:  return "KVM";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISORTYPE_H
