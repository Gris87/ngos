#ifndef UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H
#define UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H



#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 uefi_processor_information_status_flags;

enum class UefiProcessorInformationStatusFlag: uefi_processor_information_status_flags
{
    NONE          = 0,
    BSP           = (1ULL << 0),
    ENABLED       = (1ULL << 1),
    HEALTH_STATUS = (1ULL << 2)
};



inline const char8* uefiProcessorInformationStatusFlagToString(UefiProcessorInformationStatusFlag flag) // TEST: NO
{
    switch (flag)
    {
        case UefiProcessorInformationStatusFlag::NONE:          return "NONE";
        case UefiProcessorInformationStatusFlag::BSP:           return "BSP";
        case UefiProcessorInformationStatusFlag::ENABLED:       return "ENABLED";
        case UefiProcessorInformationStatusFlag::HEALTH_STATUS: return "HEALTH_STATUS";

        default: return "UNKNOWN";
    }
}



inline const char8* uefiProcessorInformationStatusFlagsToString(uefi_processor_information_status_flags flags) // TEST: NO
{
    if (!flags)
    {
        return "NONE";
    }



    static char8 res[76];

    FLAGS_TO_STRING(res, flags, uefiProcessorInformationStatusFlagToString, UefiProcessorInformationStatusFlag);

    return res;
}



#endif // UEFI_UEFIPROCESSORINFORMATIONSTATUSFLAGS_H
