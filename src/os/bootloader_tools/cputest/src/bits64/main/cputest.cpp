#include "cputest.h"

#include <common/src/bits64/cpu/cpu.h>
#include <macro/constants.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



#define CACHE_INFO_CPUID 0x00000002



CacheInfo CpuTest::sLevel1DataCache;
CacheInfo CpuTest::sLevel1InstructionCache;
CacheInfo CpuTest::sLevel2Cache;
CacheInfo CpuTest::sLevel3Cache;



NgosStatus CpuTest::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initCpuCaches(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

const CacheInfo& CpuTest::getLevel1DataCache()
{
    UEFI_LT((""));



    return sLevel1DataCache;
}

const CacheInfo& CpuTest::getLevel1InstructionCache()
{
    UEFI_LT((""));



    return sLevel1InstructionCache;
}

const CacheInfo& CpuTest::getLevel2Cache()
{
    UEFI_LT((""));



    return sLevel2Cache;
}

const CacheInfo& CpuTest::getLevel3Cache()
{
    UEFI_LT((""));



    return sLevel3Cache;
}

NgosStatus CpuTest::initCpuCaches()
{
    UEFI_LT((""));



    if (CPU::isCpuIdLevelSupported(CACHE_INFO_CPUID))
    {
        u32 registers[4];

        UEFI_ASSERT_EXECUTION(CPU::cpuid(CACHE_INFO_CPUID, 0, &registers[0], &registers[1], &registers[2], &registers[3]), NgosStatus::ASSERTION);



        u8 *registerByte = (u8 *)&registers[0];

        for (i64 i = 1; i < (i64)sizeof(registers); ++i) // Skip first byte
        {
            UEFI_LVVV(("registerByte[%d] = 0x%02X", i, registerByte[i]));

            switch (registerByte[i])
            {
                case 0x00:
                {
                    // Nothing
                }
                break;

                case 0x06: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1InstructionCache, 8   * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x06 , "Cache"    , "1st-level instruction cache: 8 KBytes, 4-way set associative, 32 byte line size" },
                case 0x08: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1InstructionCache, 16  * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x08 , "Cache"    , "1st-level instruction cache: 16 KBytes, 4-way set associative, 32 byte line size" },
                case 0x09: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1InstructionCache, 32  * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x09 , "Cache"    , "1st-level instruction cache: 32KBytes, 4-way set associative, 64 byte line size" },
                case 0x0A: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        8   * KB, 2),  NgosStatus::ASSERTION); break;                                                                                        // { 0x0A , "Cache"    , "1st-level data cache: 8 KBytes, 2-way set associative, 32 byte line size" },
                case 0x0C: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        16  * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x0C , "Cache"    , "1st-level data cache: 16 KBytes, 4-way set associative, 32 byte line size" },
                case 0x0D: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        16  * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x0D , "Cache"    , "1st-level data cache: 16 KBytes, 4-way set associative, 64 byte line size" },
                case 0x0E: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        24  * KB, 6),  NgosStatus::ASSERTION); break;                                                                                        // { 0x0E , "Cache"    , "1st-level data cache: 24 KBytes, 6-way set associative, 64 byte line size" },
                case 0x1D: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            128 * KB, 2),  NgosStatus::ASSERTION); break;                                                                                        // { 0x1D , "Cache"    , "2nd-level cache: 128 KBytes, 2-way set associative, 64 byte line size" },
                case 0x21: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            256 * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x21 , "Cache"    , "2nd-level cache: 256 KBytes, 8-way set associative, 64 byte line size" },
                case 0x22: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            512 * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x22 , "Cache"    , "3rd-level cache: 512 KBytes, 4-way set associative, 64 byte line size, 2 lines per sector" },
                case 0x23: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            1   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x23 , "Cache"    , "3rd-level cache: 1 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector" },
                case 0x24: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            1   * MB, 16), NgosStatus::ASSERTION); break;                                                                                        // { 0x24 , "Cache"    , "2nd-level cache: 1 MBytes, 16-way set associative, 64 byte line size" },
                case 0x25: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            2   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x25 , "Cache"    , "3rd-level cache: 2 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector" },
                case 0x29: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            4   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x29 , "Cache"    , "3rd-level cache: 4 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector" },
                case 0x2C: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        32  * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x2C , "Cache"    , "1st-level data cache: 32 KBytes, 8-way set associative, 64 byte line size" },
                case 0x30: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1InstructionCache, 32  * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x30 , "Cache"    , "1st-level instruction cache: 32 KBytes, 8-way set associative, 64 byte line size" },
                case 0x41: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            128 * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x41 , "Cache"    , "2nd-level cache: 128 KBytes, 4-way set associative, 32 byte line size" },
                case 0x42: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            256 * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x42 , "Cache"    , "2nd-level cache: 256 KBytes, 4-way set associative, 32 byte line size" },
                case 0x43: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            512 * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x43 , "Cache"    , "2nd-level cache: 512 KBytes, 4-way set associative, 32 byte line size" },
                case 0x44: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            1   * MB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x44 , "Cache"    , "2nd-level cache: 1 MByte, 4-way set associative, 32 byte line size" },
                case 0x45: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            2   * MB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x45 , "Cache"    , "2nd-level cache: 2 MByte, 4-way set associative, 32 byte line size" },
                case 0x46: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            4   * MB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x46 , "Cache"    , "3rd-level cache: 4 MByte, 4-way set associative, 64 byte line size" },
                case 0x47: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            8   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x47 , "Cache"    , "3rd-level cache: 8 MByte, 8-way set associative, 64 byte line size" },
                case 0x48: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            3   * MB, 12), NgosStatus::ASSERTION); break;                                                                                        // { 0x48 , "Cache"    , "2nd-level cache: 3MByte, 12-way set associative, 64 byte line size" },
                case 0x49: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            4   * MB, 16), NgosStatus::ASSERTION); UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache, 4 * MB, 16), NgosStatus::ASSERTION); break; // { 0x49 , "Cache"    , "3rd-level cache: 4MB, 16-way set associative, 64-byte line size (Intel Xeon processor MP, Family 0FH, Model 06H). 2nd-level cache: 4 MByte, 16-way set associative, 64 byte line size" },
                case 0x4A: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            6   * MB, 12), NgosStatus::ASSERTION); break;                                                                                        // { 0x4A , "Cache"    , "3rd-level cache: 6MByte, 12-way set associative, 64 byte line size" },
                case 0x4B: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            8   * MB, 16), NgosStatus::ASSERTION); break;                                                                                        // { 0x4B , "Cache"    , "3rd-level cache: 8MByte, 16-way set associative, 64 byte line size" },
                case 0x4C: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            12  * MB, 12), NgosStatus::ASSERTION); break;                                                                                        // { 0x4C , "Cache"    , "3rd-level cache: 12MByte, 12-way set associative, 64 byte line size" },
                case 0x4D: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            16  * MB, 16), NgosStatus::ASSERTION); break;                                                                                        // { 0x4D , "Cache"    , "3rd-level cache: 16MByte, 16-way set associative, 64 byte line size" },
                case 0x4E: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            6   * MB, 24), NgosStatus::ASSERTION); break;                                                                                        // { 0x4E , "Cache"    , "2nd-level cache: 6MByte, 24-way set associative, 64 byte line size" },
                case 0x60: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        16  * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x60 , "Cache"    , "1st-level data cache: 16 KByte, 8-way set associative, 64 byte line size" },
                case 0x66: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        8   * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x66 , "Cache"    , "1st-level data cache: 8 KByte, 4-way set associative, 64 byte line size" },
                case 0x67: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        16  * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x67 , "Cache"    , "1st-level data cache: 16 KByte, 4-way set associative, 64 byte line size" },
                case 0x68: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel1DataCache,        32  * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x68 , "Cache"    , "1st-level data cache: 32 KByte, 4-way set associative, 64 byte line size" },
                case 0x78: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            1   * MB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x78 , "Cache"    , "2nd-level cache: 1 MByte, 4-way set associative, 64byte line size" },
                case 0x79: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            128 * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x79 , "Cache"    , "2nd-level cache: 128 KByte, 8-way set associative, 64 byte line size, 2 lines per sector" },
                case 0x7A: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            256 * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x7A , "Cache"    , "2nd-level cache: 256 KByte, 8-way set associative, 64 byte line size, 2 lines per sector" },
                case 0x7B: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            512 * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x7B , "Cache"    , "2nd-level cache: 512 KByte, 8-way set associative, 64 byte line size, 2 lines per sector" },
                case 0x7C: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            1   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x7C , "Cache"    , "2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size, 2 lines per sector" },
                case 0x7D: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            2   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x7D , "Cache"    , "2nd-level cache: 2 MByte, 8-way set associative, 64byte line size" },
                case 0x7F: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            512 * KB, 2),  NgosStatus::ASSERTION); break;                                                                                        // { 0x7F , "Cache"    , "2nd-level cache: 512 KByte, 2-way set associative, 64-byte line size" },
                case 0x80: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            512 * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x80 , "Cache"    , "2nd-level cache: 512 KByte, 8-way set associative, 64-byte line size" },
                case 0x82: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            256 * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x82 , "Cache"    , "2nd-level cache: 256 KByte, 8-way set associative, 32 byte line size" },
                case 0x83: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            512 * KB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x83 , "Cache"    , "2nd-level cache: 512 KByte, 8-way set associative, 32 byte line size" },
                case 0x84: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            1   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x84 , "Cache"    , "2nd-level cache: 1 MByte, 8-way set associative, 32 byte line size" },
                case 0x85: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            2   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x85 , "Cache"    , "2nd-level cache: 2 MByte, 8-way set associative, 32 byte line size" },
                case 0x86: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            512 * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0x86 , "Cache"    , "2nd-level cache: 512 KByte, 4-way set associative, 64 byte line size" },
                case 0x87: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel2Cache,            1   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0x87 , "Cache"    , "2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size" },
                case 0xD0: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            512 * KB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0xD0 , "Cache"    , "3rd-level cache: 512 KByte, 4-way set associative, 64 byte line size" },
                case 0xD1: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            1   * MB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0xD1 , "Cache"    , "3rd-level cache: 1 MByte, 4-way set associative, 64 byte line size" },
                case 0xD2: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            2   * MB, 4),  NgosStatus::ASSERTION); break;                                                                                        // { 0xD2 , "Cache"    , "3rd-level cache: 2 MByte, 4-way set associative, 64 byte line size" },
                case 0xD6: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            1   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0xD6 , "Cache"    , "3rd-level cache: 1 MByte, 8-way set associative, 64 byte line size" },
                case 0xD7: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            2   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0xD7 , "Cache"    , "3rd-level cache: 2 MByte, 8-way set associative, 64 byte line size" },
                case 0xD8: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            4   * MB, 8),  NgosStatus::ASSERTION); break;                                                                                        // { 0xD8 , "Cache"    , "3rd-level cache: 4 MByte, 8-way set associative, 64 byte line size" },
                case 0xDC: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            1.5 * MB, 12), NgosStatus::ASSERTION); break;                                                                                        // { 0xDC , "Cache"    , "3rd-level cache: 1.5 MByte, 12-way set associative, 64 byte line size" },
                case 0xDD: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            3   * MB, 12), NgosStatus::ASSERTION); break;                                                                                        // { 0xDD , "Cache"    , "3rd-level cache: 3 MByte, 12-way set associative, 64 byte line size" },
                case 0xDE: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            6   * MB, 12), NgosStatus::ASSERTION); break;                                                                                        // { 0xDE , "Cache"    , "3rd-level cache: 6 MByte, 12-way set associative, 64 byte line size" },
                case 0xE2: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            2   * MB, 16), NgosStatus::ASSERTION); break;                                                                                        // { 0xE2 , "Cache"    , "3rd-level cache: 2 MByte, 16-way set associative, 64 byte line size" },
                case 0xE3: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            4   * MB, 16), NgosStatus::ASSERTION); break;                                                                                        // { 0xE3 , "Cache"    , "3rd-level cache: 4 MByte, 16-way set associative, 64 byte line size" },
                case 0xE4: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            8   * MB, 16), NgosStatus::ASSERTION); break;                                                                                        // { 0xE4 , "Cache"    , "3rd-level cache: 8 MByte, 16-way set associative, 64 byte line size" },
                case 0xEA: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            12  * MB, 24), NgosStatus::ASSERTION); break;                                                                                        // { 0xEA , "Cache"    , "3rd-level cache: 12MByte, 24-way set associative, 64 byte line size" },
                case 0xEB: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            18  * MB, 24), NgosStatus::ASSERTION); break;                                                                                        // { 0xEB , "Cache"    , "3rd-level cache: 18MByte, 24-way set associative, 64 byte line size" },
                case 0xEC: UEFI_ASSERT_EXECUTION(initCpuCache(&sLevel3Cache,            24  * MB, 24), NgosStatus::ASSERTION); break;                                                                                        // { 0xEC , "Cache"    , "3rd-level cache: 24MByte, 24-way set associative, 64 byte line size" },

                default:
                {
                    UEFI_LW(("Unknown register byte for CACHE_INFO_CPUID: 0x%02X", registerByte[i]));
                }
                break;
            }
        }



        if (!sLevel2Cache.size) // sLevel2Cache.size == 0
        {
            sLevel2Cache.size         = sLevel3Cache.size;
            sLevel2Cache.numberOfWays = sLevel3Cache.numberOfWays;
            sLevel3Cache.size         = 0;
            sLevel3Cache.numberOfWays = 0;
        }



        // Validation
        {
            UEFI_LVVV(("sLevel1DataCache.size                = %u", sLevel1DataCache.size));
            UEFI_LVVV(("sLevel1DataCache.numberOfWays        = %u", sLevel1DataCache.numberOfWays));
            UEFI_LVVV(("sLevel1InstructionCache.size         = %u", sLevel1InstructionCache.size));
            UEFI_LVVV(("sLevel1InstructionCache.numberOfWays = %u", sLevel1InstructionCache.numberOfWays));
            UEFI_LVVV(("sLevel2Cache.size                    = %u", sLevel2Cache.size));
            UEFI_LVVV(("sLevel2Cache.numberOfWays            = %u", sLevel2Cache.numberOfWays));
            UEFI_LVVV(("sLevel3Cache.size                    = %u", sLevel3Cache.size));
            UEFI_LVVV(("sLevel3Cache.numberOfWays            = %u", sLevel3Cache.numberOfWays));

            UEFI_TEST_ASSERT(sLevel1DataCache.size                > 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(sLevel1DataCache.numberOfWays        > 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(sLevel1InstructionCache.size         > 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(sLevel1InstructionCache.numberOfWays > 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(sLevel2Cache.size                    > 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(sLevel2Cache.numberOfWays            > 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(sLevel3Cache.size                    > 0, NgosStatus::ASSERTION);
            UEFI_TEST_ASSERT(sLevel3Cache.numberOfWays            > 0, NgosStatus::ASSERTION);
        }
    }
    else
    {
        UEFI_LW(("CACHE_INFO_CPUID not supported"));
    }



    return NgosStatus::OK;
}

NgosStatus CpuTest::initCpuCache(CacheInfo *cache, u32 size, u8 numberOfWays)
{
    UEFI_LT((" | cache = 0x%p, size = %u, numberOfWays = %u", cache, size, numberOfWays));

    UEFI_ASSERT(cache,        "cache is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(size,         "size is zero",         NgosStatus::ASSERTION);
    UEFI_ASSERT(numberOfWays, "numberOfWays is zero", NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(cache->size == 0, NgosStatus::ASSERTION);

    cache->size         = size;
    cache->numberOfWays = numberOfWays;



    return NgosStatus::OK;
}
