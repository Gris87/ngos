#ifndef VOLUMEINFO_H
#define VOLUMEINFO_H



#include <uefi/types.h>
#include <uefi/uefiblockioprotocol.h>



struct VolumeInfo
{
    uefi_handle          deviceHandle;
    UefiBlockIoProtocol *blockIoProtocol;
};



#endif // VOLUMEINFO_H
