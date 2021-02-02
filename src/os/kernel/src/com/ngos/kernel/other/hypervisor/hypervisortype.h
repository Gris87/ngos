#ifndef COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISORTYPE_H
#define COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISORTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class HypervisorType: bad_uint8
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

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISORTYPE_H
