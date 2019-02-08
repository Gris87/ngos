#ifndef OS_COMMON_SRC_BITS64_FPU_XSTATEHEADER_H
#define OS_COMMON_SRC_BITS64_FPU_XSTATEHEADER_H



#include <ngos/types.h>
#include <src/bits64/fpu/xfeature.h>



// XStateHeader.xComponents[63] indicates that the extendedStateArea is in compacted format.
#define XCOMPONENTS_COMPACTED_FORMAT (1ULL << 63)



struct XStateHeader
{
    x_features xFeatures;
    u64        xComponents;
    u64        __reserved[6];
} __attribute__((packed));



#endif // OS_COMMON_SRC_BITS64_FPU_XSTATEHEADER_H