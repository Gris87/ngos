#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H



#include <ngos/types.h>



struct DmiProcessorSignature
{
    u32 steppingId:  4;
    u32 model:       4;
    u32 family:      4;
    u32 type:        2;
    u32 __reserved:  2;
    u32 xModel:      4;
    u32 xFamily:     8;
    u32 __reserved2: 4;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H
