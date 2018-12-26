#ifndef OS_COMMON_SRC_BITS64_CPU_MSR_MSR_H
#define OS_COMMON_SRC_BITS64_CPU_MSR_MSR_H



#include <asm/instructions.h>
#include <ngos/status.h>
#include <ngos/types.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>



class MSR
{
public:
    static NgosStatus setBit(u32 msr, u8 bit); // TEST: NO
    static NgosStatus clearBit(u32 msr, u8 bit); // TEST: NO

    static inline u64 read(u32 msr) // TEST: NO
    {
        COMMON_LT((" | msr = %u", msr));

        COMMON_ASSERT(msr > 0, "msr is invalid", 0);



        return rdmsr(msr);
    }

    static inline NgosStatus write(u32 msr, u64 value) // TEST: NO
    {
        COMMON_LT((" | msr = %u, value = %u", msr, value));

        COMMON_ASSERT(msr > 0, "msr is invalid", NgosStatus::ASSERTION);



        return wrmsr(msr, value);
    }

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus setMsrBit(u32 msr, u8 bit, bool enabled); // TEST: NO
};



#endif // OS_COMMON_SRC_BITS64_CPU_MSR_MSR_H
