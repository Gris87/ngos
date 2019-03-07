#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISOR_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISOR_H



#include <kernelbase/src/bits64/other/hypervisor/hypervisortype.h>
#include <ngos/status.h>



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



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_HYPERVISOR_H
