#ifndef OS_SHARED_COMMON_SRC_BITS64_ASSETS_ASSETS_H
#define OS_SHARED_COMMON_SRC_BITS64_ASSETS_ASSETS_H



#include <bootparams/bootparams.h>
#include <common/src/bits64/assets/assetentry.h>
#include <ngos/status.h>



#define ASSET_ENTRIES_COUNT 66



class Assets
{
public:
    static NgosStatus init(); // TEST: NO
    static AssetEntry* getAssetEntry(const char8 *fileName); // TEST: NO

private:
    static u8         sEntriesCount;
    static AssetEntry sEntries[ASSET_ENTRIES_COUNT];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_ASSETS_ASSETS_H
