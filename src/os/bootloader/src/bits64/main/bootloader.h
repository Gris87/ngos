#ifndef BOOTLOADER_H
#define BOOTLOADER_H



#include <ngos/status.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefiloadedimageprotocol.h>



class Bootloader
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initImage(); // TEST: NO
    static NgosStatus initApplicationPath(); // TEST: NO
    static NgosStatus initDevicePath(); // TEST: NO

    static UefiLoadedImageProtocol *sImage;
    static char                    *sApplicationPath;
    static UefiDevicePath          *sDevicePath;
};



#endif // BOOTLOADER_H
