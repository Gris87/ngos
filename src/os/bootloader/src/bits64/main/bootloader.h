#ifndef BOOTLOADER_H
#define BOOTLOADER_H



#include <ngos/status.h>
#include <src/bits64/other/volumeinfo.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefiloadedimageprotocol.h>



class Bootloader
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus cleanUpPath(char *path); // TEST: NO

private:
    static NgosStatus initImage(); // TEST: NO
    static NgosStatus initApplicationPath(char **applicationPath); // TEST: NO
    static NgosStatus initDevicePath(char *applicationPath); // TEST: NO
    static NgosStatus initApplicationDirPath(char *applicationPath); // TEST: NO
    static NgosStatus initVolumes(); // TEST: NO
    static NgosStatus initBlockIoProtocol(UefiGuid *protocol, u64 size); // TEST: NO
    static NgosStatus initBlockIoProtocol(UefiGuid *protocol, u64 size, uefi_handle *blockIoHandles); // TEST: NO
    static NgosStatus initVolume(VolumeInfo *volume, UefiGuid *protocol, uefi_handle handle); // TEST: NO

    static UefiLoadedImageProtocol *sImage;
    static UefiDevicePath          *sDevicePath;
    static char                    *sApplicationDirPath;
    static u64                      sNumberOfVolumes;
    static VolumeInfo              *sVolumes;
};



#endif // BOOTLOADER_H
