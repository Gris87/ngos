#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XSTATEHEADER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XSTATEHEADER_H



#include <com/ngos/shared/common/fpu/xfeaturetypeflags.h>
#include <com/ngos/shared/common/ngos/types.h>



// XStateHeader.xComponents[63] indicates that the extendedStateArea is in compacted format.
#define XCOMPONENTS_COMPACTED_FORMAT (1ULL << 63)



struct XStateHeader
{
    XFeatureTypeFlags xFeatures;
    u64               xComponents;
    u64               __reserved[6];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XSTATEHEADER_H