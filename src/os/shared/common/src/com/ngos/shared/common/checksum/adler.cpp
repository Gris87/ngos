#include "adler.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



u32 Adler::adler32(u8 *data, u64 length)
{
    COMMON_LT((" | data = 0x%p, length = %u", data, length));

    COMMON_ASSERT(data,       "data is null",   0);
    COMMON_ASSERT(length > 0, "length is zero", 0);



    u64 s1 = 1;
    u64 s2 = 0;

    while (length)
    {
        // at least 380368439 sums can be done before the sums overflow, saving a lot of module divisions
        //
        u64 count =  length > 380368439 ? 380368439 : length;
        length    -= count;

        while (count)
        {
            s1 += *data;
            s2 += s1;

            ++data;
            --count;
        }

        s1 %= 65521;
        s2 %= 65521;
    }



    return (s2 << 16) | s1;
}
