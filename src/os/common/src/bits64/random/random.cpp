#include "random.h"

#include <asm/instructions.h>
#include <src/bits64/cpu/cpu.h>
#include <src/bits64/cpu/cpufeatures.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>



u64 simpleRandom(u64 seed)
{
    COMMON_LT((" | seed = %u", seed));



    u64  random          = seed;
    bool needRandomI8254 = true;



    if (CPU::hasFlag(X86Feature::RDRAND))
    {
        COMMON_LVV(("X86Feature::RDRAND is enabled"));

        u64 raw1 = 0;
        u64 raw2 = 0;
        u64 raw3 = 0;

        if (
            rdrand(&raw1) == NgosStatus::OK
            &&
            rdrand(&raw2) == NgosStatus::OK
            &&
            rdrand(&raw3) == NgosStatus::OK
           )
        {
            u64 raw = raw1 * raw2 * raw3;

            COMMON_LVVV(("raw1 = 0x%016lX", raw1));
            COMMON_LVVV(("raw2 = 0x%016lX", raw2));
            COMMON_LVVV(("raw3 = 0x%016lX", raw3));
            COMMON_LVVV(("raw  = 0x%016lX", raw));

            random ^= raw;

            needRandomI8254 = false;
        }
        else
        {
            COMMON_LW(("rdrand unsuccessful"));
        }
    }



    if (CPU::hasFlag(X86Feature::TSC))
    {
        COMMON_LVV(("X86Feature::TSC is enabled"));

        u64 raw1 = rdtsc();
        u64 raw2 = rdtsc();
        u64 raw3 = rdtsc();
        u64 raw  = raw1 * raw2 * raw3;

        COMMON_LVVV(("raw1 = 0x%016lX", raw1));
        COMMON_LVVV(("raw2 = 0x%016lX", raw2));
        COMMON_LVVV(("raw3 = 0x%016lX", raw3));
        COMMON_LVVV(("raw  = 0x%016lX", raw));

        random ^= raw;

        needRandomI8254 = false;
    }



    if (needRandomI8254)
    {
        COMMON_LVV(("Random with i8254"));

        u64 raw1 = randomI8254();
        u64 raw2 = randomI8254();
        u64 raw3 = randomI8254();
        u64 raw4 = randomI8254();
        u64 raw5 = randomI8254();
        u64 raw6 = randomI8254();
        u64 raw  = raw1 * raw2 * raw3 * raw4 * raw5 * raw6;

        COMMON_LVVV(("raw1 = 0x%016lX", raw1));
        COMMON_LVVV(("raw2 = 0x%016lX", raw2));
        COMMON_LVVV(("raw3 = 0x%016lX", raw3));
        COMMON_LVVV(("raw4 = 0x%016lX", raw4));
        COMMON_LVVV(("raw5 = 0x%016lX", raw5));
        COMMON_LVVV(("raw6 = 0x%016lX", raw6));
        COMMON_LVVV(("raw  = 0x%016lX", raw));

        random ^= raw;
    }



    return random;
}
