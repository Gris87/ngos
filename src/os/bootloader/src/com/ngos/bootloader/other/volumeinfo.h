#ifndef BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_VOLUMEINFO_H
#define BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_VOLUMEINFO_H



#include <common/src/com/ngos/shared/common/gpt/gptdata.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefiblockioprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefidevicepath.h>
#include <common/src/com/ngos/shared/common/uefi/uefifileprotocol.h>

#include "src/com/ngos/bootloader/other/volumetype.h"



struct VolumeInfo
{
    uefi_handle          deviceHandle;
    UefiBlockIoProtocol *blockIoProtocol;
    UefiDevicePath      *devicePath;
    UefiBlockIoProtocol *wholeDiskBlockIoProtocol;
    UefiDevicePath      *wholeDiskDevicePath;
    GptData              gptData;
    VolumeType           type;
    const char16        *name;
    bool                 partitionUniqueGuidAllocated;
    Guid                *partitionUniqueGuid;
    UefiFileProtocol    *rootDirectory;



    bool operator<(const VolumeInfo &another) const // TEST: NO
    {
        return type < another.type;
    }
};



#endif // BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_VOLUMEINFO_H
