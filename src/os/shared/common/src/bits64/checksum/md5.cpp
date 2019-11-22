#include "md5.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



MD5::MD5()
{
    COMMON_LT((""));
}

MD5::~MD5()
{
    COMMON_LT((""));
}

Md5Hash MD5::md5(u8 *data, u64 length)
{
    COMMON_LT((" | data = 0x%p, length = %u", data, length));

    COMMON_ASSERT(data,       "data is null",   0);
    COMMON_ASSERT(length > 0, "length is zero", 0);



    Md5Hash res(0, 0);



    return res;
}
