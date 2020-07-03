#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEIOTOKEN_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEIOTOKEN_H



#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



struct UefiFileIoToken
{
    uefi_event  event;
    UefiStatus  status;
    u64         bufferSize;
    void       *buffer;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEIOTOKEN_H
