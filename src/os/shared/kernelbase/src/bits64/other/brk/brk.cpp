#include "brk.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



extern void *_brk_begin; // _brk_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_brk_end;   // _brk_end declared in linker.ld file // Ignore CppEqualAlignmentVerifier



u64 BRK::sBegin;
u64 BRK::sEnd;



NgosStatus BRK::init()
{
    COMMON_LT((""));



    sBegin = (u64)&_brk_begin;
    sEnd   = (u64)&_brk_end;



    // Validation
    {
        COMMON_LVVV(("sBegin = 0x%p", sBegin));
        COMMON_LVVV(("sEnd   = 0x%p", sEnd));



        COMMON_TEST_ASSERT(sBegin != 0, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sEnd   != 0, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
