#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLOPERATION_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLOPERATION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiPciIoProtocolOperation: u32
{
    BUS_MASTER_READ,
    BUS_MASTER_WRITE,
    BUS_MASTER_COMMON_BUFFER,
    MAXIMUM
};



inline const char8* enumToString(UefiPciIoProtocolOperation operation) // TEST: NO
{
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



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
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%08X (%s)", operation, enumToString(operation));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLOPERATION_H
