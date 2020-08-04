#ifndef COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISOR_H
#define COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISOR_H



#include <com/ngos/kernel/other/hypervisor/hypervisortype.h>
#include <com/ngos/shared/common/ngos/status.h>



class Hypervisor
{
public:
    static NgosStatus init(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static HypervisorType sType;
};



#endif // COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISOR_H
