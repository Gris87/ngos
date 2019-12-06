#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORID_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORID_H



#include <common/src/bits64/dmi/entry/lib/dmiprocessorfeatureflags.h>
#include <common/src/bits64/dmi/entry/lib/dmiprocessorsignature.h>



struct DmiProcessorId
{
    DmiProcessorSignature       signature;
    dmi_processor_feature_flags featureFlags;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORID_H
