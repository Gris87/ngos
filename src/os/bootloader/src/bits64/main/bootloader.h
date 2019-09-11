#ifndef BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H
#define BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H



#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefifileinfo.h>
#include <uefi/uefiloadedimageprotocol.h>

#include "src/bits64/other/osinfo.h"
#include "src/bits64/other/volumeinfo.h"



class Bootloader
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus cleanUpPath(char16 *path);
    static NgosStatus buildPath(const char16 *parentPath, const char16 *path, char16 **res);
    static NgosStatus buildPath(const char16 *parentPath, const char8 *path, char16 **res);

    static NgosStatus loadImageFromDiskOrAssets(const char8 *path, Image **image); // TEST: NO

private:
    static NgosStatus initImage(); // TEST: NO
    static NgosStatus initPaths(); // TEST: NO
    static NgosStatus initApplicationPath(char16 **applicationPath); // TEST: NO
    static NgosStatus initDevicePath(char16 *applicationPath); // TEST: NO
    static NgosStatus initApplicationDirPath(char16 *applicationPath); // TEST: NO
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
    static NgosStatus initVolumeRootDirectory(VolumeInfo *volume); // TEST: NO
    static NgosStatus initOSes(); // TEST: NO
    static NgosStatus initOSesFromVolume(VolumeInfo *volume); // TEST: NO
    static NgosStatus initOSesFromPath(VolumeInfo *volume, UefiFileProtocol *parentDirectory, const char16 *parentPath, const char16 *path); // TEST: NO
    static NgosStatus initOSesFromDirectory(VolumeInfo *volume, char16 *absolutePath, UefiFileProtocol *directory); // TEST: NO
    static NgosStatus initOSesFromDirectory(VolumeInfo *volume, char16 *absolutePath, UefiFileProtocol *directory, u64 size); // TEST: NO
    static NgosStatus initOSesFromDirectory(VolumeInfo *volume, char16 *absolutePath, UefiFileProtocol *directory, UefiFileInfo *fileInfo); // TEST: NO
    static NgosStatus addNgosOS(VolumeInfo *volume, char16 *directoryPath, char16 *fileName); // TEST: NO

    static UefiLoadedImageProtocol *sImage;
    static UefiDevicePath          *sDevicePath;
    static char16                  *sApplicationDirPath;
    static VolumeInfo              *sMainVolume;
    static List<VolumeInfo>         sVolumes;
    static List<OsInfo>             sOSes;
};



#endif // BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADER_H
