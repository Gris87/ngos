#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_CPU_CPUMASK_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_CPU_CPUMASK_H



#include <asm/bitutils.h>
#include <ngos/status.h>
#include <ngos/types.h>
#include <ngos/utils.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/other/kerneldefines.h>



class CpuMask
{
public:
    static inline NgosStatus setCpuOnline(u64 cpu, bool enabled)
    {
        EARLY_LT((" | cpu = %u, enabled = %s", cpu, enabled ? "true" : "false"));

        EARLY_ASSERT(cpu < NUMBER_OF_CPUS, "cpu is invalid", NgosStatus::ASSERTION);



        sOnlineCpus.setCpuMask(cpu, enabled);



        return NgosStatus::OK;
    }

    static inline NgosStatus setCpuActive(u64 cpu, bool enabled)
    {
        EARLY_LT((" | cpu = %u, enabled = %s", cpu, enabled ? "true" : "false"));

        EARLY_ASSERT(cpu < NUMBER_OF_CPUS, "cpu is invalid", NgosStatus::ASSERTION);



        sActiveCpus.setCpuMask(cpu, enabled);



        return NgosStatus::OK;
    }

    static inline NgosStatus setCpuPresent(u64 cpu, bool enabled)
    {
        EARLY_LT((" | cpu = %u, enabled = %s", cpu, enabled ? "true" : "false"));

        EARLY_ASSERT(cpu < NUMBER_OF_CPUS, "cpu is invalid", NgosStatus::ASSERTION);



        sPresentCpus.setCpuMask(cpu, enabled);



        return NgosStatus::OK;
    }

    static inline NgosStatus setCpuPossible(u64 cpu, bool enabled)
    {
        EARLY_LT((" | cpu = %u, enabled = %s", cpu, enabled ? "true" : "false"));

        EARLY_ASSERT(cpu < NUMBER_OF_CPUS, "cpu is invalid", NgosStatus::ASSERTION);



        sPossibleCpus.setCpuMask(cpu, enabled);



        return NgosStatus::OK;
    }

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    inline NgosStatus setCpuMask(u64 cpu, bool enabled)
    {
        EARLY_LT((" | cpu = %u, enabled = %s, this = 0x%p", cpu, enabled ? "true" : "false", this));

        EARLY_ASSERT(cpu < NUMBER_OF_CPUS, "cpu is invalid", NgosStatus::ASSERTION);



        if (enabled)
        {
            return BitUtils::setSafe((u8 *)mBits, cpu);
        }
        else
        {
            return BitUtils::clearSafe((u8 *)mBits, cpu);
        }
    }



    u64 mBits[ROUND_UP(NUMBER_OF_CPUS, 8) >> 3]; // ">> 3" == "/ 8"

    static CpuMask sOnlineCpus;
    static CpuMask sActiveCpus;
    static CpuMask sPresentCpus;
    static CpuMask sPossibleCpus;
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_CPU_CPUMASK_H
