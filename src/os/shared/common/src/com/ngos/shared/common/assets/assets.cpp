#include "assets.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/string/string.h>



bad_uint8         Assets::sEntriesCount;
AssetEntry Assets::sEntries[ASSET_ENTRIES_COUNT];



extern void *_assets_begin; // _assets_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier
extern void *_assets_end;   // _assets_end declared in linker.ld file   // Ignore CppEqualAlignmentVerifier



NgosStatus Assets::init()
{
    COMMON_LT((""));



    bad_uint8 *start = (bad_uint8 *)&_assets_begin;
    bad_uint8 *end   = (bad_uint8 *)&_assets_end;



    bad_uint8 *currentAddress = start;
    sEntriesCount      = 0;

    while (currentAddress < end)
    {
        COMMON_TEST_ASSERT(sEntriesCount < ASSET_ENTRIES_COUNT, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].fileName =  (const char8 *)currentAddress;
        currentAddress                   += strlen(sEntries[sEntriesCount].fileName) + 1;

        COMMON_TEST_ASSERT(currentAddress < end, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].contentSize =  (*(bad_uint64 *)currentAddress);
        currentAddress                      += sizeof(sEntries[sEntriesCount].contentSize);

        COMMON_TEST_ASSERT(currentAddress < end, NgosStatus::ASSERTION);



        sEntries[sEntriesCount].content =  currentAddress;
        currentAddress                  += sEntries[sEntriesCount].contentSize;



        COMMON_LVVV(("Assets::sEntries[%u].fileName    = %s",   sEntriesCount, sEntries[sEntriesCount].fileName));
        COMMON_LVVV(("Assets::sEntries[%u].contentSize = %u",   sEntriesCount, sEntries[sEntriesCount].contentSize));
        COMMON_LVVV(("Assets::sEntries[%u].content     = 0x%p", sEntriesCount, sEntries[sEntriesCount].content));



        ++sEntriesCount;
    }



    COMMON_TEST_ASSERT(currentAddress == end, NgosStatus::ASSERTION);

#ifdef BUILD_TARGET_DEVICEMANAGER // Defined in pro file
    COMMON_TEST_ASSERT(sEntriesCount == ASSET_ENTRIES_COUNT, NgosStatus::ASSERTION);
#endif



    return NgosStatus::OK;
}

AssetEntry* Assets::getAssetEntry(const char8 *fileName)
{
    COMMON_LT((" | fileName = 0x%p", fileName));

    COMMON_ASSERT(fileName, "fileName is null", 0);



    for (bad_int64 i = 0; i < sEntriesCount; ++i)
    {
        if (strequal(sEntries[i].fileName, fileName))
        {
            COMMON_LVV(("Asset \"%s\" found at address 0x%p with size %u", fileName, sEntries[i].content, sEntries[i].contentSize));

            return &sEntries[i];
        }
    }



    COMMON_LF(("Asset \"%s\" not found", fileName));

    return 0;
}
