#include "stretchrange.h"

#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>



StretchRange::StretchRange(u16 from, u16 to)
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

u16 StretchRange::getSize() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mTo - mFrom;
}

u16 StretchRange::getFrom() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mFrom;
}

u16 StretchRange::getTo() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mTo;
}
