#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_MSR_MSR_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_MSR_MSR_H



#include <asm/instructions.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/status.h>
#include <ngos/types.h>



class MSR
{
public:
    static NgosStatus setBit(u32 msr, u8 bit); 
    static NgosStatus clearBit(u32 msr, u8 bit); 

    static inline bool testBit(u32 msr, u8 bit) 
    {
        COMMON_LT((" | msr = %u, bit = %u", msr, bit));

        COMMON_ASSERT(msr > 0,  "msr is invalid", false);
        COMMON_ASSERT(bit < 64, "bit is invalid", false);



        return read(msr) & (1ULL << bit);
    }

    static inline u64 read(u32 msr) 
    {
        COMMON_LT((" | msr = %u", msr));

        COMMON_ASSERT(msr > 0, "msr is invalid", 0);



        return rdmsr(msr);
    }

    static inline NgosStatus write(u32 msr, u64 value) 
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
    static NgosStatus setMsrBit(u32 msr, u8 bit, bool enabled); 
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_MSR_MSR_H
