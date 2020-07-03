#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_NGOS_STATUS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_NGOS_STATUS_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class NgosStatus: u64
{
    OK                   = 0,
    FAILED               = 0x8000000000000001,
    NO_EFFECT            = 0x8000000000000002,
    INVALID_DATA         = 0x8000000000000003,
    UNEXPECTED_BEHAVIOUR = 0x8000000000000004,
    NOT_SUPPORTED        = 0x8000000000000005,
    NOT_FOUND            = 0x8000000000000006,
    OUT_OF_MEMORY        = 0x8000000000000007,
    BUFFER_TOO_SMALL     = 0x8000000000000008,
    ASSERTION            = 0x8888888888888888
};



inline const char8* enumToString(NgosStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case NgosStatus::OK:                   return "OK";
        case NgosStatus::FAILED:               return "FAILED";
        case NgosStatus::NO_EFFECT:            return "NO_EFFECT";
        case NgosStatus::INVALID_DATA:         return "INVALID_DATA";
        case NgosStatus::UNEXPECTED_BEHAVIOUR: return "UNEXPECTED_BEHAVIOUR";
        case NgosStatus::NOT_SUPPORTED:        return "NOT_SUPPORTED";
        case NgosStatus::NOT_FOUND:            return "NOT_FOUND";
        case NgosStatus::OUT_OF_MEMORY:        return "OUT_OF_MEMORY";
        case NgosStatus::BUFFER_TOO_SMALL:     return "BUFFER_TOO_SMALL";
        case NgosStatus::ASSERTION:            return "ASSERTION";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(NgosStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[42];

    sprintf(res, "0x%016lX (%s)", status, enumToString(status));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_NGOS_STATUS_H
