#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEIOTOKEN_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEIOTOKEN_H



#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



struct UefiFileIoToken
{
    uefi_event  event;
    UefiStatus  status;
    u64         bufferSize;
    void       *buffer;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEIOTOKEN_H
