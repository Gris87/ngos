#include "random.h"                                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/asm/asmutils.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/cpu.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/cpu/lib/x86feature.h>                                                                                                                                                       // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_I64 Random::cpuBased(good_I64 seed)                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | seed = %d", seed));                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    good_I64 random = seed;                                                                                                                                                                              // Colorize: green
    good_I64 raw1   = 0;                                                                                                                                                                                 // Colorize: green
    good_I64 raw2   = 0;                                                                                                                                                                                 // Colorize: green
    good_I64 raw3   = 0;                                                                                                                                                                                 // Colorize: green
    good_I64 raw    = 0;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Use rdrand if supported                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (CPU::hasFlag(X86Feature::RDRAND))                                                                                                                                                            // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            COMMON_LVV(("X86Feature::RDRAND supported"));                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (                                                                                                                                                                                         // Colorize: green
                AsmUtils::rdrand(&raw1) == NgosStatus::OK                                                                                                                                                // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                AsmUtils::rdrand(&raw2) == NgosStatus::OK                                                                                                                                                // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                AsmUtils::rdrand(&raw3) == NgosStatus::OK                                                                                                                                                // Colorize: green
               )                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                raw = raw1 * raw2 * raw3;                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                COMMON_LVVV(("raw1 = 0x%016llX", raw1));                                                                                                                                                 // Colorize: green
                COMMON_LVVV(("raw2 = 0x%016llX", raw2));                                                                                                                                                 // Colorize: green
                COMMON_LVVV(("raw3 = 0x%016llX", raw3));                                                                                                                                                 // Colorize: green
                COMMON_LVVV(("raw  = 0x%016llX", raw));                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                random ^= raw;                                                                                                                                                                           // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LW(("rdrand unsuccessful"));                                                                                                                                                      // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Use rdtsc for random number                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        raw1 = AsmUtils::rdtsc();                                                                                                                                                                        // Colorize: green
        raw2 = AsmUtils::rdtsc();                                                                                                                                                                        // Colorize: green
        raw3 = AsmUtils::rdtsc();                                                                                                                                                                        // Colorize: green
        raw  = raw1 * raw2 * raw3;                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        COMMON_LVVV(("raw1 = 0x%016llX", raw1));                                                                                                                                                         // Colorize: green
        COMMON_LVVV(("raw2 = 0x%016llX", raw2));                                                                                                                                                         // Colorize: green
        COMMON_LVVV(("raw3 = 0x%016llX", raw3));                                                                                                                                                         // Colorize: green
        COMMON_LVVV(("raw  = 0x%016llX", raw));                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        random ^= raw;                                                                                                                                                                                   // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return random;                                                                                                                                                                                       // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
