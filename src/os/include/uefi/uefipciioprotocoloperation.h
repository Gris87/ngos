#ifndef UEFI_UEFIPCIIOPROTOCOLOPERATION_H
#define UEFI_UEFIPCIIOPROTOCOLOPERATION_H



#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class UefiPciIoProtocolOperation: u32
{
    BUS_MASTER_READ,
    BUS_MASTER_WRITE,
    BUS_MASTER_COMMON_BUFFER,
    MAXIMUM
};



inline const char8* enumToString(UefiPciIoProtocolOperation operation) // TEST: NO
{
    switch (operation)
    {
        case UefiPciIoProtocolOperation::BUS_MASTER_READ:          return "BUS_MASTER_READ";
        case UefiPciIoProtocolOperation::BUS_MASTER_WRITE:         return "BUS_MASTER_WRITE";
        case UefiPciIoProtocolOperation::BUS_MASTER_COMMON_BUFFER: return "BUS_MASTER_COMMON_BUFFER";
        case UefiPciIoProtocolOperation::MAXIMUM:                  return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiPciIoProtocolOperation operation) // TEST: NO
{
    static char8 res[38];

    sprintf(res, "0x%08X (%s)", operation, enumToString(operation));

    return res;
}



#endif // UEFI_UEFIPCIIOPROTOCOLOPERATION_H
