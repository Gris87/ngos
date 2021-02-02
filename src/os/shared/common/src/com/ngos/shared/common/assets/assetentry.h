#ifndef COM_NGOS_SHARED_COMMON_ASSETS_ASSETENTRY_H
#define COM_NGOS_SHARED_COMMON_ASSETS_ASSETENTRY_H



#include <com/ngos/shared/common/ngos/types.h>



struct AssetEntry
{
    const char8 *fileName;
    bad_uint64          contentSize;
    bad_uint8          *content;
};



#endif // COM_NGOS_SHARED_COMMON_ASSETS_ASSETENTRY_H
