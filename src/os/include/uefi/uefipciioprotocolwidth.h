#ifndef UEFI_UEFIPCIIOPROTOCOLWIDTH_H
#define UEFI_UEFIPCIIOPROTOCOLWIDTH_H



#include <ngos/types.h>



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



#endif // UEFI_UEFIPCIIOPROTOCOLWIDTH_H
