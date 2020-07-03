#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H



#include <com/ngos/shared/common/ngos/types.h>



struct DmiProcessorSignature
{ // TODO: The same as CPU info from CPUID. Should unify
    union
    {
        struct
        {
            u32 stepping:       4;
            u32 model:          4;
            u32 family:         4;
            u32 type:           2;
            u32 __reserved:     2;
            u32 extendedModel:  4;
            u32 extendedFamily: 8;
            u32 __reserved2:    4;
        };

        u32 value32;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H
