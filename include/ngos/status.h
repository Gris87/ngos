#ifndef NGOS_STATUS_H
#define NGOS_STATUS_H



#include <ngos/types.h>



enum class NgosStatus: u64
{
    OK                   = 0,
    FAILED               = 0x8000000000000001,
    ASSERTION            = 0x8000000000000002,
    NO_EFFECT            = 0x8000000000000003,
    INVALID_DATA         = 0x8000000000000004,
    UNEXPECTED_BEHAVIOUR = 0x8000000000000005,
    NOT_SUPPORTED        = 0x8000000000000006,
    NOT_FOUND            = 0x8000000000000007,
    OUT_OF_MEMORY        = 0x8000000000000008
};



inline const char* ngosStatusToString(NgosStatus status) // TEST: NO
{
    switch (status)
    {
        case NgosStatus::OK:                   return "OK";
        case NgosStatus::FAILED:               return "FAILED";
        case NgosStatus::ASSERTION:            return "ASSERTION";
        case NgosStatus::NO_EFFECT:            return "NO_EFFECT";
        case NgosStatus::INVALID_DATA:         return "INVALID_DATA";
        case NgosStatus::UNEXPECTED_BEHAVIOUR: return "UNEXPECTED_BEHAVIOUR";
        case NgosStatus::NOT_SUPPORTED:        return "NOT_SUPPORTED";
        case NgosStatus::NOT_FOUND:            return "NOT_FOUND";
        case NgosStatus::OUT_OF_MEMORY:        return "OUT_OF_MEMORY";

        default: return "UNKNOWN";
    }
}



#endif // NGOS_STATUS_H
