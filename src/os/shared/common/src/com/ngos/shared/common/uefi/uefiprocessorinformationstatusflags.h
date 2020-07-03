#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H



#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/string/string.h>
#include <common/src/com/ngos/shared/common/ngos/flags.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



typedef u32 uefi_processor_information_status_flags;

enum class UefiProcessorInformationStatusFlag: uefi_processor_information_status_flags
{
    NONE          = 0,
    BOOTSTRAP     = (1ULL << 0),
    ENABLED       = (1ULL << 1),
    HEALTH_STATUS = (1ULL << 2)
};

DEFINE_FLAGS(UefiProcessorInformationStatusFlags, uefi_processor_information_status_flags); // TEST: NO



inline const char8* flagToString(UefiProcessorInformationStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case UefiProcessorInformationStatusFlag::NONE:          return "NONE";
        case UefiProcessorInformationStatusFlag::BOOTSTRAP:     return "BOOTSTRAP";
        case UefiProcessorInformationStatusFlag::ENABLED:       return "ENABLED";
        case UefiProcessorInformationStatusFlag::HEALTH_STATUS: return "HEALTH_STATUS";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(UefiProcessorInformationStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[27];

    sprintf(res, "0x%08X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiProcessorInformationStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[51];

    FLAGS_TO_STRING(res, flags.flags, UefiProcessorInformationStatusFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiProcessorInformationStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[64];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiProcessorInformationStatusFlag, "0x%08X");

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H
