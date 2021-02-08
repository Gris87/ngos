#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLWIDTH_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLWIDTH_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiPciIoProtocolWidth: u32
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



inline const char8* enumToString(UefiPciIoProtocolWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    switch (width)
    {
        case UefiPciIoProtocolWidth::UINT8:       return "UINT8";
        case UefiPciIoProtocolWidth::UINT16:      return "UINT16";
        case UefiPciIoProtocolWidth::UINT32:      return "UINT32";
        case UefiPciIoProtocolWidth::UINT64:      return "UINT64";
        case UefiPciIoProtocolWidth::FIFO_UINT8:  return "FIFO_UINT8";
        case UefiPciIoProtocolWidth::FIFO_UINT16: return "FIFO_UINT16";
        case UefiPciIoProtocolWidth::FIFO_UINT32: return "FIFO_UINT32";
        case UefiPciIoProtocolWidth::FIFO_UINT64: return "FIFO_UINT64";
        case UefiPciIoProtocolWidth::FILL_UINT8:  return "FILL_UINT8";
        case UefiPciIoProtocolWidth::FILL_UINT16: return "FILL_UINT16";
        case UefiPciIoProtocolWidth::FILL_UINT32: return "FILL_UINT32";
        case UefiPciIoProtocolWidth::FILL_UINT64: return "FILL_UINT64";
        case UefiPciIoProtocolWidth::MAXIMUM:     return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiPciIoProtocolWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%08X (%s)", (u32)width, enumToString(width));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLWIDTH_H
