#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISORTYPE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISORTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class HypervisorType: u8
{
    NONE = 0,
    KVM  = 1
};



inline const char8* enumToString(HypervisorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case HypervisorType::NONE: return "NONE";
        case HypervisorType::KVM:  return "KVM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(HypervisorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISORTYPE_H
