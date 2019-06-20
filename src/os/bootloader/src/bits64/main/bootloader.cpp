#include "bootloader.h"

#include <uefi/uefiloadedimageprotocol.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



char *Bootloader::sApplicationPath;



NgosStatus Bootloader::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(initApplicationPath(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Bootloader::initApplicationPath()
{
    UEFI_LT((""));



    UefiGuid                 protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
    uefi_handle              handle   = UEFI::getImageHandle();
    UefiLoadedImageProtocol *image    = 0;



    if (UEFI::handleProtocol(handle, &protocol, (void **)&image) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to handle(0x%p) protocol for UEFI_LOADED_IMAGE_PROTOCOL", handle));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_LOADED_IMAGE_PROTOCOL", handle, image));



    UEFI_LVVV(("Loaded image:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("image->imageBase = 0x%p", image->imageBase));
    UEFI_LVVV(("image->imageSize = %u",   image->imageSize));

    UEFI_LVVV(("-------------------------------------"));



    sApplicationPath = UEFI::devicePathToString(image->filePath);

    if (!sApplicationPath)
    {
        return NgosStatus::FAILED;
    }

    UEFI_LVVV(("sApplicationPath = %s", sApplicationPath));



    return NgosStatus::OK;
}
