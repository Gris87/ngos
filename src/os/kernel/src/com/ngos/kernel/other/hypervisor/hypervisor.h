#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISOR_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISOR_H



#include <common/src/com/ngos/shared/common/ngos/status.h>

#include <src/com/ngos/kernel/other/hypervisor/hypervisortype.h>



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



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_HYPERVISOR_H
