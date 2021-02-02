#include "msr.h"



NgosStatus MSR::setBit(bad_uint32 msr, bad_uint8 bit)
{
    COMMON_LT((" | msr = %u, bit = %u", msr, bit));

    COMMON_ASSERT(msr > 0,  "msr is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(bit < 64, "bit is invalid", NgosStatus::ASSERTION);



    return setMsrBit(msr, bit, true);
}

NgosStatus MSR::clearBit(bad_uint32 msr, bad_uint8 bit)
{
    COMMON_LT((" | msr = %u, bit = %u", msr, bit));

    COMMON_ASSERT(msr > 0,  "msr is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(bit < 64, "bit is invalid", NgosStatus::ASSERTION);



    return setMsrBit(msr, bit, false);
}

NgosStatus MSR::setMsrBit(bad_uint32 msr, bad_uint8 bit, bool enabled)
{
    COMMON_LT((" | msr = %u, bit = %u, enabled = %u", msr, bit, enabled));

    COMMON_ASSERT(msr > 0,  "msr is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(bit < 64, "bit is invalid", NgosStatus::ASSERTION);



    bad_uint64 value     = read(msr);
    bad_uint64 valueOrig = value;

    if (enabled)
    {
        value |= (1ULL << bit);
    }
    else
    {
        value &= ~(1ULL << bit);
    }



    if (value == valueOrig)
    {
        return NgosStatus::NO_EFFECT;
    }



    COMMON_ASSERT_EXECUTION(write(msr, value), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
