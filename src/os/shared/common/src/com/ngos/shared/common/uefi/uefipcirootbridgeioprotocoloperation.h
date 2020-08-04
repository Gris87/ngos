#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLOPERATION_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLOPERATION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiPciRootBridgeIoProtocolOperation: u32
{
    BUS_MASTER_READ,
    BUS_MASTER_WRITE,
    BUS_MASTER_COMMON_BUFFER,
    BUS_MASTER_READ64,
    BUS_MASTER_WRITE64,
    BUS_MASTER_COMMON_BUFFER64,
    MAXIMUM
};



inline const char8* enumToString(UefiPciRootBridgeIoProtocolOperation operation) // TEST: NO
{
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



    switch (operation)
    {
        case UefiPciRootBridgeIoProtocolOperation::BUS_MASTER_READ:            return "BUS_MASTER_READ";
        case UefiPciRootBridgeIoProtocolOperation::BUS_MASTER_WRITE:           return "BUS_MASTER_WRITE";
        case UefiPciRootBridgeIoProtocolOperation::BUS_MASTER_COMMON_BUFFER:   return "BUS_MASTER_COMMON_BUFFER";
        case UefiPciRootBridgeIoProtocolOperation::BUS_MASTER_READ64:          return "BUS_MASTER_READ64";
        case UefiPciRootBridgeIoProtocolOperation::BUS_MASTER_WRITE64:         return "BUS_MASTER_WRITE64";
        case UefiPciRootBridgeIoProtocolOperation::BUS_MASTER_COMMON_BUFFER64: return "BUS_MASTER_COMMON_BUFFER64";
        case UefiPciRootBridgeIoProtocolOperation::MAXIMUM:                    return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiPciRootBridgeIoProtocolOperation operation) // TEST: NO
{
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



    static char8 res[40];

    sprintf(res, "0x%08X (%s)", operation, enumToString(operation));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLOPERATION_H
