#include "ioremap.h"

#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/other/ioremap/utils.h>



u64 IORemap::sVirtualSlots[FIX_BITMAP_SLOTS];



NgosStatus IORemap::init()
{
    COMMON_LT((""));



    for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
    {
        sVirtualSlots[i] = FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN - i * NUMBER_OF_FIX_BITMAPS);

        COMMON_LVVV(("sVirtualSlots[%d] = 0x%016lX", i, sVirtualSlots[i]));
    }

    COMMON_TEST_ASSERT(FIX_BITMAP_SLOTS == 8,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[0] == 0xFFFFFFFFFF200000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[1] == 0xFFFFFFFFFF240000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[2] == 0xFFFFFFFFFF280000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[3] == 0xFFFFFFFFFF2C0000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[4] == 0xFFFFFFFFFF300000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[5] == 0xFFFFFFFFFF340000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[6] == 0xFFFFFFFFFF380000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sVirtualSlots[7] == 0xFFFFFFFFFF3C0000, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
