#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVM_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVM_H



#include <ngos/status.h>



class KVM
{
public:
    static NgosStatus init(); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initPlatform(u32 id); // TEST: NO

    static u32 sBaseId;
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVM_H
