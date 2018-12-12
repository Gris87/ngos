#ifndef OS_COMMON_SRC_BITS64_ASSETS_ASSETENTRY_H
#define OS_COMMON_SRC_BITS64_ASSETS_ASSETENTRY_H



#include <ngos/types.h>



struct AssetEntry
{
    const char *filename;
    u64         contentSize;
    u8         *content;
};



#endif // OS_COMMON_SRC_BITS64_ASSETS_ASSETENTRY_H
