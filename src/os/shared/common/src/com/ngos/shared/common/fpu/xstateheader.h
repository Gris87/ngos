#ifndef COM_NGOS_SHARED_COMMON_FPU_XSTATEHEADER_H
#define COM_NGOS_SHARED_COMMON_FPU_XSTATEHEADER_H



#include <com/ngos/shared/common/fpu/xfeaturetypeflags.h>
#include <com/ngos/shared/common/ngos/types.h>



// XStateHeader.xComponents[63] indicates that the extendedStateArea is in compacted format.
#define XCOMPONENTS_COMPACTED_FORMAT (1ULL << 63)



struct XStateHeader
{
    XFeatureTypeFlags xFeatures;
    bad_uint64               xComponents;
    bad_uint64               __reserved[6];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_FPU_XSTATEHEADER_H
