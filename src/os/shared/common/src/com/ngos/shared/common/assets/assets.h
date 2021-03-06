#ifndef COM_NGOS_SHARED_COMMON_ASSETS_ASSETS_H
#define COM_NGOS_SHARED_COMMON_ASSETS_ASSETS_H



#include <com/ngos/shared/common/assets/assetentry.h>
#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/ngos/status.h>



#define ASSET_ENTRIES_COUNT 78



class Assets
{
public:
    static NgosStatus init(); // TEST: NO
    static AssetEntry* getAssetEntry(const char8 *fileName); // TEST: NO

private:
    static u8         sEntriesCount;
    static AssetEntry sEntries[ASSET_ENTRIES_COUNT];
};



#endif // COM_NGOS_SHARED_COMMON_ASSETS_ASSETS_H
