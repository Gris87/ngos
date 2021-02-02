#include "stretchrange.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



StretchRange::StretchRange(bad_uint16 from, bad_uint16 to)
    : mFrom(from)
    , mTo(to)
{
    COMMON_LT((" | from = %u, to = %u", from, to));

    COMMON_ASSERT(to >= from, "to is invalid");
}

StretchRange::~StretchRange()
{
    COMMON_LT((""));
}

bad_uint16 StretchRange::getSize() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mTo - mFrom;
}

bad_uint16 StretchRange::getFrom() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mFrom;
}

bad_uint16 StretchRange::getTo() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mTo;
}
