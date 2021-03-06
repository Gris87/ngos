#ifndef COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVM_H
#define COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVM_H



#include <com/ngos/kernel/other/hypervisor/kvm/kvmfeature.h>
#include <com/ngos/kernel/other/hypervisor/kvm/kvmfeaturetypeflags.h>
#include <com/ngos/shared/common/ngos/status.h>



class KVM
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus setFeature(KvmFeature feature);
    static NgosStatus clearFeature(KvmFeature feature);
    static bool hasFeature(KvmFeature feature);

    static NgosStatus setFlag(KvmFeatureTypeFlag flag);
    static NgosStatus clearFlag(KvmFeatureTypeFlag flag);
    static bool hasFlag(KvmFeatureTypeFlag flag);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initPlatform(u32 id); // TEST: NO

    static KvmFeatureTypeFlags sFeatures;
};



#endif // COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVM_H
