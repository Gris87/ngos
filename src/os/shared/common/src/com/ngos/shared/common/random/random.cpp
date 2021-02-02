#include "random.h"

#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/cpu/x86feature.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



bad_uint64 simpleRandom(bad_uint64 seed)
{
    COMMON_LT((" | seed = %u", seed));



    bad_uint64 random = seed;
    bad_uint64 raw1   = 0;
    bad_uint64 raw2   = 0;
    bad_uint64 raw3   = 0;
    bad_uint64 raw    = 0;



    if (CPU::hasFlag(X86Feature::RDRAND))
    {
        COMMON_LVV(("X86Feature::RDRAND supported"));

        if (
            rdrand(&raw1) == NgosStatus::OK
            &&
            rdrand(&raw2) == NgosStatus::OK
            &&
            rdrand(&raw3) == NgosStatus::OK
           )
        {
            raw = raw1 * raw2 * raw3;

            COMMON_LVVV(("raw1 = 0x%016llX", raw1));
            COMMON_LVVV(("raw2 = 0x%016llX", raw2));
            COMMON_LVVV(("raw3 = 0x%016llX", raw3));
            COMMON_LVVV(("raw  = 0x%016llX", raw));

            random ^= raw;
        }
        else
        {
            COMMON_LW(("rdrand unsuccessful"));
        }
    }



    raw1 = rdtsc();
    raw2 = rdtsc();
    raw3 = rdtsc();
    raw  = raw1 * raw2 * raw3;

    COMMON_LVVV(("raw1 = 0x%016llX", raw1));
    COMMON_LVVV(("raw2 = 0x%016llX", raw2));
    COMMON_LVVV(("raw3 = 0x%016llX", raw3));
    COMMON_LVVV(("raw  = 0x%016llX", raw));

    random ^= raw;



    return random;
}
