#include "bootloadergui.h"

#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/misc/imagewidget.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/bootloader.h"



#define OS_BUTTON_SIZE_PERCENT     20
#define TOOL_BUTTON_SIZE_PERCENT   10
#define SYSTEM_BUTTON_SIZE_PERCENT 5
#define CURSOR_SIZE_PERCENT        2



NgosStatus BootloaderGUI::init(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



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



    u64 screenWidth  = params->screenInfo.width;
    u64 screenHeight = params->screenInfo.height;

    u64 osButtonSize     = MIN(screenWidth * 100 / OS_BUTTON_SIZE_PERCENT,     screenHeight * 100 / OS_BUTTON_SIZE_PERCENT);
    u64 toolButtonSize   = MIN(screenWidth * 100 / TOOL_BUTTON_SIZE_PERCENT,   screenHeight * 100 / TOOL_BUTTON_SIZE_PERCENT);
    u64 systemButtonSize = MIN(screenWidth * 100 / SYSTEM_BUTTON_SIZE_PERCENT, screenHeight * 100 / SYSTEM_BUTTON_SIZE_PERCENT);
    u64 cursorSize       = MIN(screenWidth * 100 / CURSOR_SIZE_PERCENT,        screenHeight * 100 / CURSOR_SIZE_PERCENT);

    AVOID_UNUSED(osButtonSize);
    AVOID_UNUSED(systemButtonSize);



    CursorWidget *cursorWidget = new CursorWidget(cursorImage, pointerImage);

    cursorWidget->setPosition(screenWidth >> 1, screenHeight >> 1); // ">> 1" == "/ 2"
    cursorWidget->setSize(cursorSize, cursorSize);



    ImageWidget *rootWidget = new ImageWidget(backgroundImage);

    rootWidget->setPosition(0, 0);
    rootWidget->setSize(screenWidth, screenHeight);



    Button *rebootButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, rebootImage, rootWidget);

    rebootButton->setPosition(0, 0);
    rebootButton->setSize(toolButtonSize, toolButtonSize);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, cursorWidget), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
