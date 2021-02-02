#include "brk.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/utils.h>



extern void *_brk_begin; // _brk_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_brk_end;   // _brk_end declared in linker.ld file // Ignore CppEqualAlignmentVerifier



bad_uint64 BRK::sBegin;
bad_uint64 BRK::sEnd;



NgosStatus BRK::init()
{
    COMMON_LT((""));



    sBegin = (bad_uint64)&_brk_begin;
    sEnd   = sBegin;



    // Validation
    {
        COMMON_LVVV(("sBegin = 0x%p", sBegin));
        COMMON_LVVV(("sEnd   = 0x%p", sEnd));



        COMMON_TEST_ASSERT(sBegin == (bad_uint64)&_brk_begin, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sEnd   == (bad_uint64)&_brk_begin, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BRK::allocate(bad_uint64 size, bad_uint64 align, bad_uint8 **result)
{
    COMMON_LT((" | size = %u, align = %u, result = 0x%p", size, align, result));

    COMMON_ASSERT(size > 0,             "size is zero",            NgosStatus::ASSERTION);
    COMMON_ASSERT(align > 0,            "align is zero",           NgosStatus::ASSERTION);
    COMMON_ASSERT(IS_POWER_OF_2(align), "align is not power of 2", NgosStatus::ASSERTION);
    COMMON_ASSERT(result,               "result is null",          NgosStatus::ASSERTION);



    sEnd = ROUND_UP(sEnd, align);
    COMMON_TEST_ASSERT(sEnd + size <= (bad_uint64)&_brk_end, NgosStatus::ASSERTION);

    *result = (bad_uint8 *)sEnd;

    sEnd += size;



    COMMON_LVV(("Allocated space(0x%p, %u) in BRK", *result, size));



    return NgosStatus::OK;
}
