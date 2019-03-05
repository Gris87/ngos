#include "brk.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/utils.h>



extern void *_brk_begin; // _brk_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_brk_end;   // _brk_end declared in linker.ld file // Ignore CppEqualAlignmentVerifier



u64 BRK::sBegin;
u64 BRK::sEnd;



NgosStatus BRK::init()
{
    COMMON_LT((""));



    sBegin = (u64)&_brk_begin;
    sEnd   = sBegin;



    // Validation
    {
        COMMON_LVVV(("sBegin = 0x%p", sBegin));
        COMMON_LVVV(("sEnd   = 0x%p", sEnd));



        COMMON_TEST_ASSERT(sBegin != 0, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sEnd   != 0, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BRK::allocate(u64 size, u64 align, u8 **result)
{
    COMMON_LT((" | size = %u, align = %u, result = 0x%p", size, align, result));

    COMMON_ASSERT(size > 0,             "size is zero",            NgosStatus::ASSERTION);
    COMMON_ASSERT(align > 0,            "align is zero",           NgosStatus::ASSERTION);
    COMMON_ASSERT(IS_POWER_OF_2(align), "align is not power of 2", NgosStatus::ASSERTION);
    COMMON_ASSERT(result,               "result is null",          NgosStatus::ASSERTION);



    sEnd = ROUND_UP(sEnd, align);
    COMMON_TEST_ASSERT(sEnd + size <= (u64)&_brk_end, NgosStatus::ASSERTION);

    *result = (u8 *)sEnd;

    sEnd += size;



    COMMON_LVV(("Allocated space(0x%p, %u) in BRK", *result, size));



    return NgosStatus::OK;
}