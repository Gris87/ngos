#include "random.h"

#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/cpu/x86feature.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



good_I64 simpleRandom(good_I64 seed)
{
    COMMON_LT((" | seed = %d", seed));



    good_I64 random = seed;
    good_I64 raw1   = 0;
    good_I64 raw2   = 0;
    good_I64 raw3   = 0;
    good_I64 raw    = 0;



    if (CPU::hasFlag(X86Feature::RDRAND))
    {
        COMMON_LVV(("X86Feature::RDRAND supported"));

        if (
            AsmUtils::rdrand(&raw1) == NgosStatus::OK
            &&
            AsmUtils::rdrand(&raw2) == NgosStatus::OK
            &&
            AsmUtils::rdrand(&raw3) == NgosStatus::OK
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



    raw1 = AsmUtils::rdtsc();
    raw2 = AsmUtils::rdtsc();
    raw3 = AsmUtils::rdtsc();
    raw  = raw1 * raw2 * raw3;

    COMMON_LVVV(("raw1 = 0x%016llX", raw1));
    COMMON_LVVV(("raw2 = 0x%016llX", raw2));
    COMMON_LVVV(("raw3 = 0x%016llX", raw3));
    COMMON_LVVV(("raw  = 0x%016llX", raw));

    random ^= raw;



    return random;
}
