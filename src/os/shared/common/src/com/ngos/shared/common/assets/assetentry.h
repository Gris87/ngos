#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ASSETS_ASSETENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ASSETS_ASSETENTRY_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct AssetEntry
{
    const char8 *fileName;
    u64          contentSize;
    u8          *content;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ASSETS_ASSETENTRY_H
