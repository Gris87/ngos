#ifndef BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_MAIN_BOOTLOADER_H
#define BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_MAIN_BOOTLOADER_H



#include <com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/common/containers/list.h>
#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/uefidevicepath.h>
#include <com/ngos/shared/common/uefi/uefiloadedimageprotocol.h>

#include "com/ngos/bootloader/other/osinfo.h"
#include "com/ngos/bootloader/other/volumeinfo.h"



class Bootloader
{
public:
    static NgosStatus init(); // TEST: NO
    static NgosStatus cleanUp(); // TEST: NO

    static NgosStatus cleanUpPath(char16 *path);
    static NgosStatus buildPath(const char16 *parentPath, const char16 *path, char16 **res);
    static NgosStatus buildPath(const char16 *parentPath, const char8 *path, char16 **res);

    static NgosStatus loadImageFromDiskOrAssets(const char8 *path, Image **image); // TEST: NO

    static NgosStatus startTool(const char8 *path); // TEST: NO
    static NgosStatus startOs(u64 index); // TEST: NO

    static const ArrayList<OsInfo>& getOSes(); // TEST: NO

private:
    static NgosStatus initImage(); // TEST: NO
    static NgosStatus initPaths(); // TEST: NO
    static NgosStatus initApplicationPath(char16 **applicationPath); // TEST: NO
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
    static NgosStatus initVolumeNameAndGuid(VolumeInfo *volume); // TEST: NO
    static NgosStatus initVolumeRootDirectory(VolumeInfo *volume); // TEST: NO
    static NgosStatus initOSes(); // TEST: NO
    static NgosStatus initOSesFromVolume(VolumeInfo *volume); // TEST: NO
    static NgosStatus addNgosKernel(VolumeInfo *volume); // TEST: NO
    static NgosStatus addNgosInstaller(VolumeInfo *volume); // TEST: NO
    static NgosStatus addWindows10(VolumeInfo *volume); // TEST: NO
    static NgosStatus addUbuntu19(VolumeInfo *volume); // TEST: NO
    static NgosStatus addCentOS8(VolumeInfo *volume); // TEST: NO
    static NgosStatus startApplication(VolumeInfo *volume, const char16 *path, bool freePath); // TEST: NO

    static UefiLoadedImageProtocol *sImage;
    static char16                  *sApplicationDirPath;
    static VolumeInfo              *sMainVolume;
    static List<VolumeInfo>         sVolumes;
    static ArrayList<OsInfo>        sOSes;
};



#endif // BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_MAIN_BOOTLOADER_H
