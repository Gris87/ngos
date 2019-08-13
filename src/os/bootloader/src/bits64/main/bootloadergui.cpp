#include "bootloadergui.h"

#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/misc/imagewidget.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/bootloader.h"



NgosStatus BootloaderGUI::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(GUI::init(), NgosStatus::ASSERTION);



    Image *backgroundImage;
    Image *arrowLeftImage;
    Image *arrowRightImage;
    Image *buttonFocusedImage;
    Image *buttonHoverImage;
    Image *buttonNormalImage;
    Image *buttonPressedImage;
    Image *cursorImage;
    Image *pointerImage;
    Image *rebootImage;
    Image *shutdownImage;
    Image *osNgosImage;
    Image *osUbuntuImage;
    Image *osWindowsImage;

    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/background.jpg",       &backgroundImage),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/arrow_left.png",       &arrowLeftImage),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/arrow_right.png",      &arrowRightImage),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_focused.9.png", &buttonFocusedImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_hover.9.png",   &buttonHoverImage),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_normal.9.png",  &buttonNormalImage),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_pressed.9.png", &buttonPressedImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/cursor.png",           &cursorImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/pointer.png",          &pointerImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/reboot.png",           &rebootImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/shutdown.png",         &shutdownImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/os_ngos.png",          &osNgosImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/os_ubuntu.png",        &osUbuntuImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/os_windows.png",       &osWindowsImage),     NgosStatus::ASSERTION);



    ImageWidget *rootWidget = new ImageWidget();

    /*Button *restartButton =*/ new Button(rootWidget);



    delete rootWidget;



    return NgosStatus::OK;
}
