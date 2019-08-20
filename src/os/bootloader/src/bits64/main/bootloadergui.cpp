#include "bootloadergui.h"

#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/misc/rootwidget.h>
#include <common/src/bits64/gui/widgets/misc/screenwidget.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/bootloader.h"



#define REBOOT_BUTTON_POSITION_X_PERCENT 90
#define REBOOT_BUTTON_POSITION_Y_PERCENT 0

#define SHUTDOWN_BUTTON_POSITION_X_PERCENT 95
#define SHUTDOWN_BUTTON_POSITION_Y_PERCENT 0

#define LEFT_BUTTON_POSITION_X_PERCENT 5
#define LEFT_BUTTON_POSITION_Y_PERCENT 40

#define RIGHT_BUTTON_POSITION_X_PERCENT 90
#define RIGHT_BUTTON_POSITION_Y_PERCENT 40

#define CURSOR_POSITION_X_PERCENT 50
#define CURSOR_POSITION_Y_PERCENT 50

#define OS_BUTTON_SIZE_PERCENT     20
#define ARROW_BUTTON_SIZE_PERCENT  5
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

    u64 osButtonSize     = MIN(screenWidth * OS_BUTTON_SIZE_PERCENT     / 100, screenHeight * OS_BUTTON_SIZE_PERCENT     / 100);
    u64 arrowButtonSize  = MIN(screenWidth * ARROW_BUTTON_SIZE_PERCENT  / 100, screenHeight * ARROW_BUTTON_SIZE_PERCENT  / 100);
    u64 toolButtonSize   = MIN(screenWidth * TOOL_BUTTON_SIZE_PERCENT   / 100, screenHeight * TOOL_BUTTON_SIZE_PERCENT   / 100);
    u64 systemButtonSize = MIN(screenWidth * SYSTEM_BUTTON_SIZE_PERCENT / 100, screenHeight * SYSTEM_BUTTON_SIZE_PERCENT / 100);
    u64 cursorSize       = MIN(screenWidth * CURSOR_SIZE_PERCENT        / 100, screenHeight * CURSOR_SIZE_PERCENT        / 100);

    AVOID_UNUSED(osButtonSize);
    AVOID_UNUSED(toolButtonSize);



    RootWidget *rootWidget = new RootWidget();

    UEFI_ASSERT_EXECUTION(rootWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rootWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    ScreenWidget *screenWidget = new ScreenWidget(backgroundImage, (u8 *)params->screenInfo.frameBufferBase, rootWidget);

    UEFI_ASSERT_EXECUTION(screenWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(screenWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    Button *rebootButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, rebootImage, rootWidget);

    UEFI_ASSERT_EXECUTION(rebootButton->setPosition(screenWidth * REBOOT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * REBOOT_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rebootButton->setSize(systemButtonSize, systemButtonSize),                                                                              NgosStatus::ASSERTION);



    Button *shutdownButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, shutdownImage, rootWidget);

    UEFI_ASSERT_EXECUTION(shutdownButton->setPosition(screenWidth * SHUTDOWN_BUTTON_POSITION_X_PERCENT / 100, screenHeight * SHUTDOWN_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(shutdownButton->setSize(systemButtonSize, systemButtonSize),                                                                                  NgosStatus::ASSERTION);



    Button *leftButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, arrowLeftImage, rootWidget);

    UEFI_ASSERT_EXECUTION(leftButton->setPosition(screenWidth * LEFT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * LEFT_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(leftButton->setSize(arrowButtonSize, arrowButtonSize),                                                                            NgosStatus::ASSERTION);



    Button *rightButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, arrowRightImage, rootWidget);

    UEFI_ASSERT_EXECUTION(rightButton->setPosition(screenWidth * RIGHT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * RIGHT_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rightButton->setSize(arrowButtonSize, arrowButtonSize),                                                                              NgosStatus::ASSERTION);



    CursorWidget *cursorWidget = new CursorWidget(cursorImage, pointerImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cursorWidget->setPosition(screenWidth * CURSOR_POSITION_X_PERCENT / 100, screenHeight * CURSOR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cursorWidget->setSize(cursorSize, cursorSize),                                                                            NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
