#include "kvm.h"

#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>

#include <src/com/ngos/kernel/other/hypervisor/kvm/clock/kvmclock.h>



#define HYPERVISORS_REGION_BEGIN 0x40000000
#define HYPERVISORS_REGION_END   0x40010000
#define HYPERVISORS_REGION_STEP  0x0100

// KVM signature: KVMKVMKVM
#define KVM_SIGNATURE_EBX 0x4B4D564B    // KVMK
#define KVM_SIGNATURE_ECX 0x564B4D56    // VMKV
#define KVM_SIGNATURE_EDX 0x0000004D    // M



KvmFeatureTypeFlags KVM::sFeatures;



NgosStatus KVM::init()
{
    COMMON_LT((""));



    if (CPU::hasFlag(X86Feature::HYPERVISOR))
    {
        u32 id = HYPERVISORS_REGION_BEGIN;

        while (id < HYPERVISORS_REGION_END)
        {
            u32 ebx;
            u32 ecx;
            u32 edx;
            u32 ignored;



            COMMON_ASSERT_EXECUTION(CPU::cpuid(id, 0, &ignored, &ebx, &ecx, &edx), NgosStatus::ASSERTION);

            COMMON_LVVV(("ebx = 0x%08X", ebx));
            COMMON_LVVV(("ecx = 0x%08X", ecx));
            COMMON_LVVV(("edx = 0x%08X", edx));



            if (
                ebx == KVM_SIGNATURE_EBX
                &&
                ecx == KVM_SIGNATURE_ECX
                &&
                edx == KVM_SIGNATURE_EDX
               )
            {
                COMMON_ASSERT_EXECUTION(initPlatform(id), NgosStatus::ASSERTION);

                return NgosStatus::OK;
            }



            id += HYPERVISORS_REGION_STEP;
        }
    }



    return NgosStatus::NOT_FOUND;
}

NgosStatus KVM::setFeature(KvmFeature feature)
{
    COMMON_LT((" | feature = %u", feature));



    sFeatures |= (1ULL << (u64)feature);



    return NgosStatus::OK;
}

NgosStatus KVM::clearFeature(KvmFeature feature)
{
    COMMON_LT((" | feature = %u", feature));



    sFeatures &= ~(1ULL << (u64)feature);



    return NgosStatus::OK;
}

bool KVM::hasFeature(KvmFeature feature)
{
    COMMON_LT((" | feature = %u", feature));



    return sFeatures & (1ULL << (u64)feature);
}

NgosStatus KVM::setFlag(KvmFeatureTypeFlag flag)
{
    COMMON_LT((" | flag = %u", flag));



    sFeatures |= FLAGS(flag);



    return NgosStatus::OK;
}

NgosStatus KVM::clearFlag(KvmFeatureTypeFlag flag)
{
    COMMON_LT((" | flag = %u", flag));



    sFeatures &= ~FLAGS(flag);



    return NgosStatus::OK;
}

bool KVM::hasFlag(KvmFeatureTypeFlag flag)
{
    COMMON_LT((" | flag = %u", flag));



    return sFeatures & FLAGS(flag);
}

NgosStatus KVM::initPlatform(u32 id)
{
    COMMON_LT((" | id = 0x%08X", id));

    COMMON_ASSERT(id >= HYPERVISORS_REGION_BEGIN && id < HYPERVISORS_REGION_END, "id is invalid", NgosStatus::ASSERTION);



    u32 ignored;
    u32 eax;

    COMMON_ASSERT_EXECUTION(CPU::cpuid(id | 0x01, 0, &eax, &ignored, &ignored, &ignored), NgosStatus::ASSERTION);
    sFeatures = eax;

    COMMON_ASSERT_EXECUTION(KvmClock::init(), NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("sFeatures = %s", flagsToFullString(sFeatures)));



        COMMON_TEST_ASSERT(sFeatures == 0x0100007B, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
