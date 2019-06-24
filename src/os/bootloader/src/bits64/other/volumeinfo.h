#ifndef BOOTLOADER_SRC_BITS64_OTHER_VOLUMEINFO_H
#define BOOTLOADER_SRC_BITS64_OTHER_VOLUMEINFO_H



#include <uefi/types.h>
#include <uefi/uefiblockioprotocol.h>
#include <uefi/uefidevicepath.h>

#include "src/bits64/other/volumetype.h"


struct VolumeInfo
{
    uefi_handle          deviceHandle;
    UefiBlockIoProtocol *blockIoProtocol;
    UefiDevicePath      *devicePath;
    VolumeType           type;
};



#endif // BOOTLOADER_SRC_BITS64_OTHER_VOLUMEINFO_H
