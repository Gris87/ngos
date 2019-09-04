#ifndef BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H
#define BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H



#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefiloadedimageprotocol.h>

#include "src/bits64/other/volumeinfo.h"



class Bootloader
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus cleanUpPath(char8 *path);

    static NgosStatus loadImageFromDiskOrAssets(const char8 *path, Image **image); // TEST: NO

private:
    static NgosStatus initImage(); // TEST: NO
    static NgosStatus initPaths(); // TEST: NO
    static NgosStatus initApplicationPath(char8 **applicationPath); // TEST: NO
    static NgosStatus initDevicePath(char8 *applicationPath); // TEST: NO
    static NgosStatus initApplicationDirPath(char8 *applicationPath); // TEST: NO
    static NgosStatus initVolumes(); // TEST: NO
    static NgosStatus initBlockIoProtocol(Guid *protocol, u64 size); // TEST: NO
    static NgosStatus initBlockIoProtocol(Guid *protocol, u64 size, uefi_handle *blockIoHandles); // TEST: NO
    static NgosStatus initVolume(VolumeInfo *volume, Guid *protocol, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeDeviceHandle(VolumeInfo *volume, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeBlockIoProtocol(VolumeInfo *volume, Guid *protocol, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeDevicePath(VolumeInfo *volume, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeWholeDisk(VolumeInfo *volume, Guid *protocol); // TEST: NO
    static NgosStatus initVolumeWholeDiskBlockIoProtocol(VolumeInfo *volume, Guid *protocol, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeWholeDiskDevicePath(VolumeInfo *volume, uefi_handle handle); // TEST: NO
    static NgosStatus initVolumeGptData(VolumeInfo *volume); // TEST: NO
    static NgosStatus initVolumeType(VolumeInfo *volume); // TEST: NO
    static NgosStatus initVolumeName(VolumeInfo *volume); // TEST: NO
    static NgosStatus initOSes(); // TEST: NO
    static NgosStatus initOSesFromVolume(const VolumeInfo &volume); // TEST: NO

    static UefiLoadedImageProtocol *sImage;
    static UefiDevicePath          *sDevicePath;
    static char8                   *sApplicationDirPath;
    static List<VolumeInfo>         sVolumes;
};



#endif // BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H
