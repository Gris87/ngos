#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORID_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORID_H



#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorfeatureflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiprocessorsignature.h>



struct DmiProcessorId
{
    DmiProcessorSignature    signature;
    DmiProcessorFeatureFlags featureFlags;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORID_H
