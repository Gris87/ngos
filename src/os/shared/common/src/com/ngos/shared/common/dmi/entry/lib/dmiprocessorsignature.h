#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H



#include <com/ngos/shared/common/ngos/types.h>



struct DmiProcessorSignature
{ // TODO: The same as CPU info from CPUID. Should unify
    union
    {
        struct
        {
            bad_uint32 stepping:       4;
            bad_uint32 model:          4;
            bad_uint32 family:         4;
            bad_uint32 type:           2;
            bad_uint32 __reserved:     2;
            bad_uint32 extendedModel:  4;
            bad_uint32 extendedFamily: 8;
            bad_uint32 __reserved2:    4;
        };

        bad_uint32 value32;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSIGNATURE_H
