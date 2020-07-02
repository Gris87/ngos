#ifndef UEFI_UEFIFILEIOTOKEN_H
#define UEFI_UEFIFILEIOTOKEN_H



#include <uefi/types.h>
#include <uefi/uefistatus.h>



struct UefiFileIoToken
{
    uefi_event  event;
    UefiStatus  status;
    u64         bufferSize;
    void       *buffer;
};



#endif // UEFI_UEFIFILEIOTOKEN_H
