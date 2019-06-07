#include "assets.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/string/string.h>



u8         Assets::sEntriesCount;
AssetEntry Assets::sEntries[ASSET_ENTRIES_COUNT];



extern void *_assets_begin; // _assets_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_assets_end;   // _assets_end declared in linker.ld file   // Ignore CppEqualAlignmentVerifier



NgosStatus Assets::init()
{
    COMMON_LT((""));



    // HACK: Temporary fix for PIE. Try to find another solution
    // u8 *start = (u8 *)(params->header.kernelLocation + (u64)&_assets_begin);
    // u8 *end   = (u8 *)(params->header.kernelLocation + (u64)&_assets_end);
    u8 *start;
    u8 *end;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    _assets_begin(%%rip), %0"  "\n\t" // leaq    _assets_begin(%rip), %rbx     # Get address of _assets_begin variable to RBX. %RBX == start
        "leaq    _assets_end(%%rip),   %1"         // leaq    _assets_end(%rip),   %r12     # Get address of _assets_end variable to R12. %R12 == end
            :                                      // Output parameters
                "=r" (start),                      // 'r' - any general register, '=' - write only
                "=r" (end)                         // 'r' - any general register, '=' - write only
    );
    // Ignore CppAlignmentVerifier [END]



    u8 *currentAddress = start;
    sEntriesCount      = 0;

    while (currentAddress < end)
    {
        COMMON_TEST_ASSERT(sEntriesCount < ASSET_ENTRIES_COUNT, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].filename = (const char *)currentAddress;
        currentAddress += strlen(sEntries[sEntriesCount].filename) + 1;

        COMMON_TEST_ASSERT(currentAddress < end, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].contentSize = *(u64 *)currentAddress;
        currentAddress += sizeof(sEntries[sEntriesCount].contentSize);

        COMMON_TEST_ASSERT(currentAddress < end, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].content = currentAddress;
        currentAddress += sEntries[sEntriesCount].contentSize;



        COMMON_LVVV(("Assets::sEntries[%u].filename    = %s",   sEntriesCount, sEntries[sEntriesCount].filename));
        COMMON_LVVV(("Assets::sEntries[%u].contentSize = %u",   sEntriesCount, sEntries[sEntriesCount].contentSize));
        COMMON_LVVV(("Assets::sEntries[%u].content     = 0x%p", sEntriesCount, sEntries[sEntriesCount].content));



        ++sEntriesCount;
    }

    COMMON_TEST_ASSERT(currentAddress == end, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

AssetEntry* Assets::getAssetEntry(const char *filename)
{
    COMMON_LT((" | filename = 0x%p", filename));

    COMMON_ASSERT(filename, "filename is null", 0);



    for (i64 i = 0; i < sEntriesCount; ++i)
    {
        if (!strcmp(sEntries[i].filename, filename)) // strcmp(sEntries[i].filename, filename) == 0
        {
            COMMON_LVV(("Asset \"%s\" found at address 0x%p with size %u", filename, sEntries[i].content, sEntries[i].contentSize));

            return &sEntries[i];
        }
    }



    COMMON_LF(("Asset \"%s\" not found", filename));

    return 0;
}
