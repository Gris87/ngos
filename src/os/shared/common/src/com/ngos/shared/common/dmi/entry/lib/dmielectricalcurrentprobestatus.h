#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBESTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBESTATUS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiElectricalCurrentProbeStatus: bad_uint8
{
    NONE            = 0,
    OTHER           = 1,
    UNKNOWN         = 2,
    OK              = 3,
    NON_CRITICAL    = 4,
    CRITICAL        = 5,
    NON_RECOVERABLE = 6
};



inline const char8* enumToString(DmiElectricalCurrentProbeStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiElectricalCurrentProbeStatus::NONE:            return "NONE";
        case DmiElectricalCurrentProbeStatus::OTHER:           return "OTHER";
        case DmiElectricalCurrentProbeStatus::UNKNOWN:         return "UNKNOWN";
        case DmiElectricalCurrentProbeStatus::OK:              return "OK";
        case DmiElectricalCurrentProbeStatus::NON_CRITICAL:    return "NON_CRITICAL";
        case DmiElectricalCurrentProbeStatus::CRITICAL:        return "CRITICAL";
        case DmiElectricalCurrentProbeStatus::NON_RECOVERABLE: return "NON_RECOVERABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiElectricalCurrentProbeStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", (bad_uint8)status, enumToString(status));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBESTATUS_H
