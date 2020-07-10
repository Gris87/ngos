#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLWIDTH_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLWIDTH_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiPciRootBridgeIoProtocolWidth: u32
{
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    FIFO_UINT8,
    FIFO_UINT16,
    FIFO_UINT32,
    FIFO_UINT64,
    FILL_UINT8,
    FILL_UINT16,
    FILL_UINT32,
    FILL_UINT64,
    MAXIMUM
};



inline const char8* enumToString(UefiPciRootBridgeIoProtocolWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    switch (width)
    {
        case UefiPciRootBridgeIoProtocolWidth::UINT8:       return "UINT8";
        case UefiPciRootBridgeIoProtocolWidth::UINT16:      return "UINT16";
        case UefiPciRootBridgeIoProtocolWidth::UINT32:      return "UINT32";
        case UefiPciRootBridgeIoProtocolWidth::UINT64:      return "UINT64";
        case UefiPciRootBridgeIoProtocolWidth::FIFO_UINT8:  return "FIFO_UINT8";
        case UefiPciRootBridgeIoProtocolWidth::FIFO_UINT16: return "FIFO_UINT16";
        case UefiPciRootBridgeIoProtocolWidth::FIFO_UINT32: return "FIFO_UINT32";
        case UefiPciRootBridgeIoProtocolWidth::FIFO_UINT64: return "FIFO_UINT64";
        case UefiPciRootBridgeIoProtocolWidth::FILL_UINT8:  return "FILL_UINT8";
        case UefiPciRootBridgeIoProtocolWidth::FILL_UINT16: return "FILL_UINT16";
        case UefiPciRootBridgeIoProtocolWidth::FILL_UINT32: return "FILL_UINT32";
        case UefiPciRootBridgeIoProtocolWidth::FILL_UINT64: return "FILL_UINT64";
        case UefiPciRootBridgeIoProtocolWidth::MAXIMUM:     return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiPciRootBridgeIoProtocolWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%08X (%s)", width, enumToString(width));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLWIDTH_H
