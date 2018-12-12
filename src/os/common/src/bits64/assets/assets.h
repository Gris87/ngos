#ifndef OS_COMMON_SRC_BITS64_ASSETS_ASSETS_H
#define OS_COMMON_SRC_BITS64_ASSETS_ASSETS_H



#include <bootparams/bootparams.h>
#include <ngos/status.h>
#include <src/bits64/assets/assetentry.h>



#define ASSET_ENTRIES_COUNT 1



class Assets
{
public:
    static NgosStatus init(); // TEST: NO
    static AssetEntry* getAssetEntry(const char *filename); // TEST: NO

private:
    static u8         sEntriesCount;
    static AssetEntry sEntries[ASSET_ENTRIES_COUNT];
};



#endif // OS_COMMON_SRC_BITS64_ASSETS_ASSETS_H
