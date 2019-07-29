#ifndef BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H
#define BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H



#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefiloadedimageprotocol.h>

#include "src/bits64/other/volumeinfo.h"



class Bootloader
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus cleanUpPath(char8 *path); // TEST: NO

    static NgosStatus loadImageFromDiskOrAssets(const char8 *path, Image **image); // TEST: NO

private:
    static NgosStatus initImage(); // TEST: NO
    static NgosStatus initApplicationPath(char8 **applicationPath); // TEST: NO
    static NgosStatus initDevicePath(char8 *applicationPath); // TEST: NO
    static NgosStatus initApplicationDirPath(char8 *applicationPath); // TEST: NO
    static NgosStatus initVolumes(); // TEST: NO
    static NgosStatus initBlockIoProtocol(UefiGuid *protocol, u64 size); // TEST: NO
    static NgosStatus initBlockIoProtocol(UefiGuid *protocol, u64 size, uefi_handle *blockIoHandles); // TEST: NO
    static NgosStatus initVolume(VolumeInfo *volume, UefiGuid *protocol, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeDeviceHandle(VolumeInfo *volume, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeBlockIoProtocol(VolumeInfo *volume, UefiGuid *protocol, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeDevicePath(VolumeInfo *volume, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeGptData(VolumeInfo *volume); // TEST: NO
    static NgosStatus initVolumeTypeAndName(VolumeInfo *volume); // TEST: NO
    static NgosStatus initVolumeName(VolumeInfo *volume, UefiDevicePath *devicePath); // TEST: NO
    static NgosStatus initImages(); // TEST: NO

    static UefiLoadedImageProtocol *sImage;
    static UefiDevicePath          *sDevicePath;
    static char8                   *sApplicationDirPath;
    static u64                      sNumberOfVolumes;
    static VolumeInfo              *sVolumes;
    static Image                   *sBackgroundImage;
};



#endif // BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H
