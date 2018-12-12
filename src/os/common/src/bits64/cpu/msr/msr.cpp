#include "msr.h"

#include <asm/instructions.h>
#include <ngos/linkage.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>



NgosStatus MSR::setBit(u32 msr, u8 bit)
{
    COMMON_LT((" | msr = %u, bit = %u", msr, bit));

    COMMON_ASSERT(msr > 0,  "msr is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(bit < 64, "bit is invalid", NgosStatus::ASSERTION);



    return setMsrBit(msr, bit, true);
}

NgosStatus MSR::clearBit(u32 msr, u8 bit)
{
    COMMON_LT((" | msr = %u, bit = %u", msr, bit));

    COMMON_ASSERT(msr > 0,  "msr is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(bit < 64, "bit is invalid", NgosStatus::ASSERTION);



    return setMsrBit(msr, bit, false);
}

NgosStatus MSR::setMsrBit(u32 msr, u8 bit, bool enabled)
{
    COMMON_LT((" | msr = %u, bit = %u, enabled = %u", msr, bit, enabled));

    COMMON_ASSERT(msr > 0,  "msr is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(bit < 64, "bit is invalid", NgosStatus::ASSERTION);



    u64 value     = rdmsr(msr);
    u64 valueOrig = value;

    if (enabled)
    {
        value |= 1ULL << bit;
    }
    else
    {
        value &= ~(1ULL << bit);
    }



    if (value == valueOrig)
    {
        return NgosStatus::NO_EFFECT;
    }



    COMMON_ASSERT_EXECUTION(wrmsr(msr, value), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
