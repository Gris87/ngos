#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISTATUS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISTATUS_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiStatus: u64
{
    SUCCESS              = 0,
    LOAD_ERROR           = 0x8000000000000001,
    INVALID_PARAMETER    = 0x8000000000000002,
    UNSUPPORTED          = 0x8000000000000003,
    BAD_BUFFER_SIZE      = 0x8000000000000004,
    BUFFER_TOO_SMALL     = 0x8000000000000005,
    NOT_READY            = 0x8000000000000006,
    DEVICE_ERROR         = 0x8000000000000007,
    WRITE_PROTECTED      = 0x8000000000000008,
    OUT_OF_RESOURCES     = 0x8000000000000009,
    VOLUME_CORRUPTED     = 0x800000000000000A,
    VOLUME_FULL          = 0x800000000000000B,
    NO_MEDIA             = 0x800000000000000C,
    MEDIA_CHANGED        = 0x800000000000000D,
    NOT_FOUND            = 0x800000000000000E,
    ACCESS_DENIED        = 0x800000000000000F,
    NO_RESPONSE          = 0x8000000000000010,
    NO_MAPPING           = 0x8000000000000011,
    TIMEOUT              = 0x8000000000000012,
    NOT_STARTED          = 0x8000000000000013,
    ALREADY_STARTED      = 0x8000000000000014,
    ABORTED              = 0x8000000000000015,
    ICMP_ERROR           = 0x8000000000000016,
    TFTP_ERROR           = 0x8000000000000017,
    PROTOCOL_ERROR       = 0x8000000000000018,
    INCOMPATIBLE_VERSION = 0x8000000000000019,
    SECURITY_VIOLATION   = 0x800000000000001A,
    CRC_ERROR            = 0x800000000000001B,
    END_OF_MEDIA         = 0x800000000000001C,
    END_OF_FILE          = 0x800000000000001F,
    INVALID_LANGUAGE     = 0x8000000000000020,
    COMPROMISED_DATA     = 0x8000000000000021
};



inline const char8* enumToString(UefiStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case UefiStatus::SUCCESS:              return "SUCCESS";
        case UefiStatus::LOAD_ERROR:           return "LOAD_ERROR";
        case UefiStatus::INVALID_PARAMETER:    return "INVALID_PARAMETER";
        case UefiStatus::UNSUPPORTED:          return "UNSUPPORTED";
        case UefiStatus::BAD_BUFFER_SIZE:      return "BAD_BUFFER_SIZE";
        case UefiStatus::BUFFER_TOO_SMALL:     return "BUFFER_TOO_SMALL";
        case UefiStatus::NOT_READY:            return "NOT_READY";
        case UefiStatus::DEVICE_ERROR:         return "DEVICE_ERROR";
        case UefiStatus::WRITE_PROTECTED:      return "WRITE_PROTECTED";
        case UefiStatus::OUT_OF_RESOURCES:     return "OUT_OF_RESOURCES";
        case UefiStatus::VOLUME_CORRUPTED:     return "VOLUME_CORRUPTED";
        case UefiStatus::VOLUME_FULL:          return "VOLUME_FULL";
        case UefiStatus::NO_MEDIA:             return "NO_MEDIA";
        case UefiStatus::MEDIA_CHANGED:        return "MEDIA_CHANGED";
        case UefiStatus::NOT_FOUND:            return "NOT_FOUND";
        case UefiStatus::ACCESS_DENIED:        return "ACCESS_DENIED";
        case UefiStatus::NO_RESPONSE:          return "NO_RESPONSE";
        case UefiStatus::NO_MAPPING:           return "NO_MAPPING";
        case UefiStatus::TIMEOUT:              return "TIMEOUT";
        case UefiStatus::NOT_STARTED:          return "NOT_STARTED";
        case UefiStatus::ALREADY_STARTED:      return "ALREADY_STARTED";
        case UefiStatus::ABORTED:              return "ABORTED";
        case UefiStatus::ICMP_ERROR:           return "ICMP_ERROR";
        case UefiStatus::TFTP_ERROR:           return "TFTP_ERROR";
        case UefiStatus::PROTOCOL_ERROR:       return "PROTOCOL_ERROR";
        case UefiStatus::INCOMPATIBLE_VERSION: return "INCOMPATIBLE_VERSION";
        case UefiStatus::SECURITY_VIOLATION:   return "SECURITY_VIOLATION";
        case UefiStatus::CRC_ERROR:            return "CRC_ERROR";
        case UefiStatus::END_OF_MEDIA:         return "END_OF_MEDIA";
        case UefiStatus::END_OF_FILE:          return "END_OF_FILE";
        case UefiStatus::INVALID_LANGUAGE:     return "INVALID_LANGUAGE";
        case UefiStatus::COMPROMISED_DATA:     return "COMPROMISED_DATA";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[42];

    sprintf(res, "0x%016lX (%s)", status, enumToString(status));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISTATUS_H
