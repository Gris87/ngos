#ifndef UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H
#define UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H



#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



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
    static char8 res[27];

    sprintf(res, "0x%08X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiProcessorInformationStatusFlags &flags) // TEST: NO
{
    static char8 res[51];

    FLAGS_TO_STRING(res, flags.flags, UefiProcessorInformationStatusFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiProcessorInformationStatusFlags &flags) // TEST: NO
{
    static char8 res[64];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiProcessorInformationStatusFlag, "0x%08X");

    return res;
}



#endif // UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H
