#ifndef COM_NGOS_SHARED_COMMON_CPU_MSR_MSR_H
#define COM_NGOS_SHARED_COMMON_CPU_MSR_MSR_H



#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



class MSR
{
public:
    static NgosStatus setBit(bad_uint32 msr, bad_uint8 bit); // TEST: NO
    static NgosStatus clearBit(bad_uint32 msr, bad_uint8 bit); // TEST: NO

    static inline bool testBit(bad_uint32 msr, bad_uint8 bit) // TEST: NO
    {
        COMMON_LT((" | msr = %u, bit = %u", msr, bit));

        COMMON_ASSERT(msr > 0,  "msr is invalid", false);
        COMMON_ASSERT(bit < 64, "bit is invalid", false);



        return read(msr) & (1ULL << bit);
    }

    static inline bad_uint64 read(bad_uint32 msr) // TEST: NO
    {
        COMMON_LT((" | msr = %u", msr));

        COMMON_ASSERT(msr > 0, "msr is invalid", 0);



        return rdmsr(msr);
    }

    static inline NgosStatus write(bad_uint32 msr, bad_uint64 value) // TEST: NO
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
    static NgosStatus setMsrBit(bad_uint32 msr, bad_uint8 bit, bool enabled); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_CPU_MSR_MSR_H
