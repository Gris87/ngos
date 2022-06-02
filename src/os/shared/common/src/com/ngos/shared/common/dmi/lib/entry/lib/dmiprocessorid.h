#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORID_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORID_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorfeatureflags.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorsignature.h>



struct DmiProcessorId
{
    DmiProcessorSignature    signature;
    DmiProcessorFeatureFlags featureFlags;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORID_H
