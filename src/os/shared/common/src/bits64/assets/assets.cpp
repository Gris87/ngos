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



    u8 *start = (u8 *)&_assets_begin;
    u8 *end   = (u8 *)&_assets_end;



    u8 *currentAddress = start;
    sEntriesCount      = 0;

    while (currentAddress < end)
    {
        COMMON_TEST_ASSERT(sEntriesCount < ASSET_ENTRIES_COUNT, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].filename =  (const char8 *)currentAddress;
        currentAddress                   += strlen(sEntries[sEntriesCount].filename) + 1;

        COMMON_TEST_ASSERT(currentAddress < end, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].contentSize =  (*(u64 *)currentAddress);
        currentAddress                      += sizeof(sEntries[sEntriesCount].contentSize);

        COMMON_TEST_ASSERT(currentAddress < end, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].content =  currentAddress;
        currentAddress                  += sEntries[sEntriesCount].contentSize;



        COMMON_LVVV(("Assets::sEntries[%u].filename    = %s",   sEntriesCount, sEntries[sEntriesCount].filename));
        COMMON_LVVV(("Assets::sEntries[%u].contentSize = %u",   sEntriesCount, sEntries[sEntriesCount].contentSize));
        COMMON_LVVV(("Assets::sEntries[%u].content     = 0x%p", sEntriesCount, sEntries[sEntriesCount].content));



        ++sEntriesCount;
    }

    COMMON_TEST_ASSERT(currentAddress == end, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

AssetEntry* Assets::getAssetEntry(const char8 *filename)
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
