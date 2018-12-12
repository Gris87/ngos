#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_CPU_CPUMASK_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_CPU_CPUMASK_H



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
    inline NgosStatus setCpuBit(u64 cpu)
    {
        EARLY_LT((" | cpu = %u, this = 0x%p", cpu, this));

        EARLY_ASSERT(cpu < NUMBER_OF_CPUS, "cpu is invalid", NgosStatus::ASSERTION);



        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "lock bts   %1, %0"             // lock bts   %rax,(%rbx) # lock - CPU will lock system Bus until instruction finish # Sets bit RAX starting from address RBX. %rax == cpu. %rbx == mBits
                :                           // Output parameters
                    "+m" (mBits)            // "m" == use memory, "+" - read and write
                :                           // Input parameters
                    "r" (cpu)               // "r" == any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]



        return NgosStatus::OK;
    }

    inline NgosStatus clearCpuBit(u64 cpu)
    {
        EARLY_LT((" | cpu = %u, this = 0x%p", cpu, this));

        EARLY_ASSERT(cpu < NUMBER_OF_CPUS, "cpu is invalid", NgosStatus::ASSERTION);



        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "lock btr   %1, %0"             // lock btr   %rax,(%rbx) # lock - CPU will lock system Bus until instruction finish # Clears bit RAX starting from address RBX. %rax == cpu. %rbx == mBits
                :                           // Output parameters
                    "+m" (mBits)            // "m" == use memory, "+" - read and write
                :                           // Input parameters
                    "r" (cpu)               // "r" == any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]



        return NgosStatus::OK;
    }

    inline NgosStatus setCpuMask(u64 cpu, bool enabled)
    {
        EARLY_LT((" | cpu = %u, enabled = %s, this = 0x%p", cpu, enabled ? "true" : "false", this));

        EARLY_ASSERT(cpu < NUMBER_OF_CPUS, "cpu is invalid", NgosStatus::ASSERTION);



        if (enabled)
        {
            return setCpuBit(cpu);
        }
        else
        {
            return clearCpuBit(cpu);
        }
    }



    u64 mBits[ROUND_UP(NUMBER_OF_CPUS, 8) >> 3]; // ">> 3" == "/ 8"

    static CpuMask sOnlineCpus;
    static CpuMask sActiveCpus;
    static CpuMask sPresentCpus;
    static CpuMask sPossibleCpus;
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_CPU_CPUMASK_H
