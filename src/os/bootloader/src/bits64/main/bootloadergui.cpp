#include "bootloadergui.h"

#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/misc/labelwidget.h>
#include <common/src/bits64/gui/widgets/misc/rootwidget.h>
#include <common/src/bits64/gui/widgets/misc/screenwidget.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <uefibase/src/bits64/uefi/uefi.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/src/bits64/uefi/uefipointerdevices.h>

#include "src/bits64/main/bootloader.h"



#define INFO_LABEL_POSITION_X_PERCENT      0
#define INFO_LABEL_POSITION_Y_PERCENT      0
#define INFO_LABEL_POSITION_WIDTH_PERCENT  90
#define INFO_LABEL_POSITION_HEIGHT_PERCENT 2

#define REBOOT_BUTTON_POSITION_X_PERCENT 90
#define REBOOT_BUTTON_POSITION_Y_PERCENT 0

#define SHUTDOWN_BUTTON_POSITION_X_PERCENT 95
#define SHUTDOWN_BUTTON_POSITION_Y_PERCENT 0

#define OS_REGION_LEFT_PERCENT            10
#define OS_REGION_RIGHT_PERCENT           90
#define OS_REGION_VERTICAL_CENTER_PERCENT 25
#define OS_VISIBLE_COUNT                  4

#define LEFT_BUTTON_POSITION_X_PERCENT  2
#define RIGHT_BUTTON_POSITION_X_PERCENT 92

#define CPU_TEST_BUTTON_POSITION_X_PERCENT 10
#define CPU_TEST_BUTTON_POSITION_Y_PERCENT 48

#define MEMORY_TEST_BUTTON_POSITION_X_PERCENT 37
#define MEMORY_TEST_BUTTON_POSITION_Y_PERCENT 48

#define NETWORK_TEST_BUTTON_POSITION_X_PERCENT 64
#define NETWORK_TEST_BUTTON_POSITION_Y_PERCENT 48

#define HDD_TEST_BUTTON_POSITION_X_PERCENT 10
#define HDD_TEST_BUTTON_POSITION_Y_PERCENT 59

#define PARTITION_WIZARD_BUTTON_POSITION_X_PERCENT 37
#define PARTITION_WIZARD_BUTTON_POSITION_Y_PERCENT 59

#define SHELL_BUTTON_POSITION_X_PERCENT 64
#define SHELL_BUTTON_POSITION_Y_PERCENT 59

#define CURSOR_POSITION_X_PERCENT 50
#define CURSOR_POSITION_Y_PERCENT 50

#define OS_BUTTON_SIZE_PERCENT     20
#define ARROW_BUTTON_SIZE_PERCENT  6
#define TOOL_BUTTON_WIDTH_PERCENT  26
#define TOOL_BUTTON_HEIGHT_PERCENT 10
#define SYSTEM_BUTTON_SIZE_PERCENT 5
#define CURSOR_SIZE_PERCENT        2



Button              *BootloaderGUI::sRebootButton;
Button              *BootloaderGUI::sShutdownButton;
ArrayList<Button *>  BootloaderGUI::sOsButtons;
u64                  BootloaderGUI::sOsButtonLeft;
u64                  BootloaderGUI::sOsButtonRight;
u64                  BootloaderGUI::sOsButtonSelected;
Button              *BootloaderGUI::sLeftButton;
Button              *BootloaderGUI::sRightButton;
Button              *BootloaderGUI::sCpuTestButton;
Button              *BootloaderGUI::sMemoryTestButton;
Button              *BootloaderGUI::sNetworkTestButton;
Button              *BootloaderGUI::sHddTestButton;
Button              *BootloaderGUI::sPartitionWizardButton;
Button              *BootloaderGUI::sShellButton;
u16                  BootloaderGUI::sWaitEventsCount;
uefi_event          *BootloaderGUI::sWaitEvents;
uefi_event           BootloaderGUI::sTimerEvent;



NgosStatus BootloaderGUI::init(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    Image  *backgroundImage;
    Image  *buttonNormalImage;
    Image  *buttonHoverImage;
    Image  *buttonPressedImage;
    Image  *buttonFocusedImage;
    Image  *cpuTestImage;
    Image  *memoryTestImage;
    Image  *networkTestImage;
    Image  *hddTestImage;
    Image  *partitionWizardImage;
    Image  *shellImage;
    Image  *rebootImage;
    Image  *shutdownImage;
    Image  *cursorImage;
    Image*  osImages[(u64)OsType::MAXIMUM];

    memzero(osImages, sizeof(osImages));



    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/background.jpg",       &backgroundImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_normal.9.png",  &buttonNormalImage),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_hover.9.png",   &buttonHoverImage),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_pressed.9.png", &buttonPressedImage),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_focused.9.png", &buttonFocusedImage),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/cpu_test.png",         &cpuTestImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/memory_test.png",      &memoryTestImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/network_test.png",     &networkTestImage),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/hdd_test.png",         &hddTestImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/partition_wizard.png", &partitionWizardImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/shell.png",            &shellImage),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/reboot.png",           &rebootImage),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/shutdown.png",         &shutdownImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/cursor.png",           &cursorImage),          NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(params->screensCount > 0, NgosStatus::ASSERTION);

    u64 screenWidth  = params->screens[0]->mode->info->horizontalResolution;
    u64 screenHeight = params->screens[0]->mode->info->verticalResolution;

    u64 systemButtonSize = screenWidth  * SYSTEM_BUTTON_SIZE_PERCENT / 100;
    u64 osButtonSize     = screenWidth  * OS_BUTTON_SIZE_PERCENT     / 100;
    u64 toolButtonWidth  = screenWidth  * TOOL_BUTTON_WIDTH_PERCENT  / 100;
    u64 toolButtonHeight = screenHeight * TOOL_BUTTON_HEIGHT_PERCENT / 100;
    u64 cursorSize       = screenWidth  * CURSOR_SIZE_PERCENT        / 100;



    RootWidget *rootWidget = new RootWidget();

    UEFI_ASSERT_EXECUTION(rootWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rootWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    ScreenWidget *screenWidget = new ScreenWidget(backgroundImage, params->screens[0], rootWidget);

    UEFI_ASSERT_EXECUTION(screenWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(screenWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    LabelWidget *infoLabel = new LabelWidget("Use arrow keys and Tab to select, Enter to boot, F8 for options", rootWidget);

    UEFI_ASSERT_EXECUTION(infoLabel->setPosition(screenWidth * INFO_LABEL_POSITION_X_PERCENT     / 100, screenHeight * INFO_LABEL_POSITION_Y_PERCENT      / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(infoLabel->setSize(screenWidth     * INFO_LABEL_POSITION_WIDTH_PERCENT / 100, screenHeight * INFO_LABEL_POSITION_HEIGHT_PERCENT / 100), NgosStatus::ASSERTION);



    sRebootButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, rebootImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sRebootButton->setPosition(screenWidth * REBOOT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * REBOOT_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setSize(systemButtonSize, systemButtonSize),                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setKeyboardEventHandler(onRebootButtonKeyboardEvent),                                                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setPressEventHandler(onRebootButtonPressed),                                                                              NgosStatus::ASSERTION);



    sShutdownButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, shutdownImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sShutdownButton->setPosition(screenWidth * SHUTDOWN_BUTTON_POSITION_X_PERCENT / 100, screenHeight * SHUTDOWN_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setSize(systemButtonSize, systemButtonSize),                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setKeyboardEventHandler(onShutdownButtonKeyboardEvent),                                                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setPressEventHandler(onShutdownButtonPressed),                                                                                NgosStatus::ASSERTION);



    const ArrayList<OsInfo>& oses    = Bootloader::getOSes();
    u64                      osCount = oses.getSize();

    if (osCount)
    {
        for (i64 i = 0; i < (i64)osCount; ++i)
        {
            const OsInfo &os = oses.at(i);



            UEFI_TEST_ASSERT(os.type < OsType::MAXIMUM, NgosStatus::ASSERTION);
            Image *osImage = osImages[(u64)os.type];

            if (!osImage)
            {
                const char8 *pathToImage;

                switch (os.type)
                {
                    case OsType::NGOS:       pathToImage = "images/os_ngos.png";    break;
                    case OsType::WINDOWS_10: pathToImage = "images/os_windows.png"; break;
                    case OsType::UBUNTU_19:  pathToImage = "images/os_ubuntu.png";  break;
                    case OsType::CENTOS_7:   pathToImage = "images/os_centos.png";  break;
                    case OsType::UNKNOWN:    pathToImage = "images/os_unknown.png"; break;
                    case OsType::MAXIMUM:
                    {
                        UEFI_LF(("Unexpected OS type: %u (%s)", os.type, osTypeToString(os.type)));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        UEFI_LF(("Unexpected OS type: %u (%s)", os.type, osTypeToString(os.type)));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }

                UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets(pathToImage, &osImage), NgosStatus::ASSERTION);
                osImages[(u64)os.type] = osImage;
            }



            Button *osButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, osImage, rootWidget);

            UEFI_ASSERT_EXECUTION(osButton->setKeyboardEventHandler(onOsButtonKeyboardEvent), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(osButton->setPressEventHandler(onOsButtonPressed),          NgosStatus::ASSERTION);

            sOsButtons.append(osButton);
        }



        if (osCount > OS_VISIBLE_COUNT)
        {
            osCount = OS_VISIBLE_COUNT;

            Image *arrowLeftImage;
            Image *arrowRightImage;

            UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/arrow_left.png",  &arrowLeftImage),  NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/arrow_right.png", &arrowRightImage), NgosStatus::ASSERTION);



            u64 arrowButtonSize = screenWidth * ARROW_BUTTON_SIZE_PERCENT / 100;



            sLeftButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, arrowLeftImage, rootWidget);

            UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(false),                                                                                                                                NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sLeftButton->setPosition(screenWidth * LEFT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * OS_REGION_VERTICAL_CENTER_PERCENT / 100 - (arrowButtonSize >> 1)), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sLeftButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                        NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sLeftButton->setKeyboardEventHandler(onLeftButtonKeyboardEvent),                                                                                               NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sLeftButton->setPressEventHandler(onLeftButtonPressed),                                                                                                        NgosStatus::ASSERTION);



            sRightButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, arrowRightImage, rootWidget);

            UEFI_ASSERT_EXECUTION(sRightButton->setPosition(screenWidth * RIGHT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * OS_REGION_VERTICAL_CENTER_PERCENT / 100 - (arrowButtonSize >> 1)), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                         NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setKeyboardEventHandler(onRightButtonKeyboardEvent),                                                                                               NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setPressEventHandler(onRightButtonPressed),                                                                                                        NgosStatus::ASSERTION);
        }



        i64 osButtonPositionX;
        i64 osButtonStep;

        if (osCount == 1)
        {
            osButtonPositionX = screenWidth * (OS_REGION_LEFT_PERCENT + OS_REGION_RIGHT_PERCENT - OS_BUTTON_SIZE_PERCENT) / 200;
            osButtonStep      = 0;
        }
        else
        if (osCount == 2)
        {
            osButtonPositionX = screenWidth * (OS_REGION_LEFT_PERCENT + OS_REGION_RIGHT_PERCENT - OS_BUTTON_SIZE_PERCENT) / 200 - osButtonSize;
            osButtonStep      = osButtonSize << 1; // "<< 1" == "* 2"
        }
        else
        {
            osButtonPositionX = screenWidth * OS_REGION_LEFT_PERCENT / 100;
            osButtonStep      = screenWidth * (OS_REGION_RIGHT_PERCENT - OS_REGION_LEFT_PERCENT - OS_BUTTON_SIZE_PERCENT) / 100 / (osCount - 1);
        }

        i64 osButtonPositionY = screenHeight * OS_REGION_VERTICAL_CENTER_PERCENT / 100 - (osButtonSize >> 1);



        for (i64 i = 0; i < (i64)sOsButtons.getSize() && i < (i64)osCount; ++i)
        {
            Button *button = sOsButtons.at(i);

            UEFI_ASSERT_EXECUTION(button->setPosition(osButtonPositionX, osButtonPositionY), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(button->setSize(osButtonSize, osButtonSize),               NgosStatus::ASSERTION);

            osButtonPositionX += osButtonStep;
        }

        for (i64 i = osCount; i < (i64)sOsButtons.getSize(); ++i)
        {
            Button *button = sOsButtons.at(i);

            UEFI_ASSERT_EXECUTION(button->setVisible(false),                   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(button->setSize(osButtonSize, osButtonSize), NgosStatus::ASSERTION);
        }

        sOsButtonLeft     = 0;
        sOsButtonRight    = osCount;
        sOsButtonSelected = 0;
    }



    sCpuTestButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, cpuTestImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sCpuTestButton->setPosition(screenWidth * CPU_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * CPU_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sCpuTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sCpuTestButton->setKeyboardEventHandler(onCpuTestButtonKeyboardEvent),                                                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sCpuTestButton->setPressEventHandler(onCpuTestButtonPressed),                                                                                 NgosStatus::ASSERTION);



    sMemoryTestButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, memoryTestImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sMemoryTestButton->setPosition(screenWidth * MEMORY_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * MEMORY_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sMemoryTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sMemoryTestButton->setKeyboardEventHandler(onMemoryTestButtonKeyboardEvent),                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sMemoryTestButton->setPressEventHandler(onMemoryTestButtonPressed),                                                                                    NgosStatus::ASSERTION);



    sNetworkTestButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, networkTestImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sNetworkTestButton->setPosition(screenWidth * NETWORK_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * NETWORK_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sNetworkTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sNetworkTestButton->setKeyboardEventHandler(onNetworkTestButtonKeyboardEvent),                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sNetworkTestButton->setPressEventHandler(onNetworkTestButtonPressed),                                                                                     NgosStatus::ASSERTION);



    sHddTestButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, hddTestImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sHddTestButton->setPosition(screenWidth * HDD_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * HDD_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sHddTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sHddTestButton->setKeyboardEventHandler(onHddTestButtonKeyboardEvent),                                                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sHddTestButton->setPressEventHandler(onHddTestButtonPressed),                                                                                 NgosStatus::ASSERTION);



    sPartitionWizardButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, partitionWizardImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sPartitionWizardButton->setPosition(screenWidth * PARTITION_WIZARD_BUTTON_POSITION_X_PERCENT / 100, screenHeight * PARTITION_WIZARD_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sPartitionWizardButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sPartitionWizardButton->setKeyboardEventHandler(onPartitionWizardButtonKeyboardEvent),                                                                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sPartitionWizardButton->setPressEventHandler(onPartitionWizardButtonPressed),                                                                                         NgosStatus::ASSERTION);



    sShellButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, shellImage, rootWidget);

    UEFI_ASSERT_EXECUTION(sShellButton->setPosition(screenWidth * SHELL_BUTTON_POSITION_X_PERCENT / 100, screenHeight * SHELL_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShellButton->setSize(toolButtonWidth, toolButtonHeight),                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShellButton->setKeyboardEventHandler(onShellButtonKeyboardEvent),                                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShellButton->setPressEventHandler(onShellButtonPressed),                                                                             NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(focusFirstOsButton(), NgosStatus::ASSERTION);



    CursorWidget *cursorWidget = new CursorWidget(cursorImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cursorWidget->setPosition(GUI::getFocusedWidget()->getPositionX() + (osButtonSize >> 1), GUI::getFocusedWidget()->getPositionY() + (osButtonSize >> 1)), NgosStatus::ASSERTION); // ">> 1" == "/ 2"
    UEFI_ASSERT_EXECUTION(cursorWidget->setSize(cursorSize, cursorSize),                                                                                                           NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(),                              NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::exec()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(generateWaitEventList(), NgosStatus::ASSERTION);

    do
    {
        UEFI_ASSERT_EXECUTION(waitForEvent(), NgosStatus::ASSERTION);
    } while(true);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::focusOsButton()
{
    UEFI_LT((""));



    return GUI::setFocusedWidget(sOsButtons.at(sOsButtonSelected));
}

NgosStatus BootloaderGUI::focusFirstOsButton()
{
    UEFI_LT((""));



    bool locked = false;

    if (sOsButtonLeft) // sOsButtonLeft > 0
    {
        locked = true;

        UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        for (i64 i = 0; i < OS_VISIBLE_COUNT; ++i)
        {
            Button *button        = sOsButtons.at(i);
            Button *visibleButton = sOsButtons.at(sOsButtonLeft + i);

            button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
            button->setVisible(true);
        }

        for (i64 i = OS_VISIBLE_COUNT; i < (i64)sOsButtons.getSize(); ++i)
        {
            sOsButtons.at(i)->setVisible(false);
        }

        sOsButtonLeft  = 0;
        sOsButtonRight = OS_VISIBLE_COUNT;

        UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(false), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sRightButton->setVisible(true), NgosStatus::ASSERTION);
    }

    sOsButtonSelected = 0;



    UEFI_ASSERT_EXECUTION(focusOsButton(), NgosStatus::ASSERTION);



    if (locked)
    {
        UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::focusOsButtonLeft()
{
    UEFI_LT((""));



    sOsButtonSelected = sOsButtonLeft;



    return focusOsButton();
}

NgosStatus BootloaderGUI::focusOsButtonRight()
{
    UEFI_LT((""));



    sOsButtonSelected = sOsButtonRight - 1;



    return focusOsButton();
}

NgosStatus BootloaderGUI::focusPreviousOsButton()
{
    UEFI_LT((""));



    bool locked = false;

    if (sOsButtonSelected <= sOsButtonLeft)
    {
        if (sOsButtonLeft) // sOsButtonLeft > 0
        {
            locked = true;

            UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            for (i64 i = sOsButtonLeft; i < (i64)sOsButtonRight; ++i)
            {
                Button *button        = sOsButtons.at(i - 1);
                Button *visibleButton = sOsButtons.at(i);

                button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
            }

            --sOsButtonLeft;
            --sOsButtonRight;

            UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonLeft)->setVisible(true),   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonRight)->setVisible(false), NgosStatus::ASSERTION);

            UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(sOsButtonLeft > 0), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setVisible(true),             NgosStatus::ASSERTION);
        }
        else
        {
            return NgosStatus::NO_EFFECT;
        }
    }

    --sOsButtonSelected;



    UEFI_ASSERT_EXECUTION(focusOsButton(), NgosStatus::ASSERTION);



    if (locked)
    {
        UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::focusNextOsButton()
{
    UEFI_LT((""));



    bool locked = false;

    if (sOsButtonSelected + 1 >= sOsButtonRight)
    {
        if (sOsButtonRight < sOsButtons.getSize())
        {
            locked = true;

            UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            for (i64 i = sOsButtonRight; i > (i64)sOsButtonLeft; --i)
            {
                Button *button        = sOsButtons.at(i);
                Button *visibleButton = sOsButtons.at(i - 1);

                button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
            }

            UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonLeft)->setVisible(false), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonRight)->setVisible(true), NgosStatus::ASSERTION);

            ++sOsButtonLeft;
            ++sOsButtonRight;

            UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(true),                                   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sRightButton->setVisible(sOsButtonRight < sOsButtons.getSize()), NgosStatus::ASSERTION);
        }
        else
        {
            return NgosStatus::NO_EFFECT;
        }
    }

    ++sOsButtonSelected;



    UEFI_ASSERT_EXECUTION(focusOsButton(), NgosStatus::ASSERTION);



    if (locked)
    {
        UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::focusNextOsButtonOrGoDown()
{
    UEFI_LT((""));



    NgosStatus status = focusNextOsButton();

    if (status == NgosStatus::NO_EFFECT)
    {
        return GUI::setFocusedWidget(sCpuTestButton);
    }



    return status;
}

NgosStatus BootloaderGUI::generateWaitEventList()
{
    UEFI_LT((""));



    sWaitEventsCount = UefiPointerDevices::getSimplePointersCount() + UefiPointerDevices::getAbsolutePointersCount() + 2; // "+ 1" = keyboard event, "+ 1" = timer event
    u64 size         = sWaitEventsCount * sizeof(uefi_event);

    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&sWaitEvents) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for wait events", size));

        return NgosStatus::OUT_OF_MEMORY;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for wait events", sWaitEvents, size));



    sWaitEvents[0] = UEFI::getSystemTable()->stdin->waitForKey;
    u16 eventId    = 1;



    for (i64 i = 0; i < UefiPointerDevices::getSimplePointersCount(); ++i)
    {
        sWaitEvents[eventId] = UefiPointerDevices::getSimplePointer(i)->waitForInput;

        ++eventId;
    }



    for (i64 i = 0; i < UefiPointerDevices::getAbsolutePointersCount(); ++i)
    {
        sWaitEvents[eventId] = UefiPointerDevices::getAbsolutePointer(i)->waitForInput;

        ++eventId;
    }



    UEFI_ASSERT_EXECUTION(UEFI::createEvent(UefiEventType::TIMER, 0, 0, 0, &sTimerEvent), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Created timer event(0x%p)", sTimerEvent));



    UEFI_ASSERT_EXECUTION(UEFI::setTimer(sTimerEvent, UefiTimerDelay::PERIODIC, 10000000), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION); // 1 * 1000 * 1000 * 10 "* 100ns"
    UEFI_LVV(("Setup timer(0x%p) completed", sTimerEvent));



    sWaitEvents[eventId] = sTimerEvent;



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::waitForEvent()
{
    UEFI_LT((""));



    u64 eventIndex;

    UEFI_ASSERT_EXECUTION(UEFI::waitForEvent(sWaitEventsCount, sWaitEvents, &eventIndex), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("eventIndex = %u", eventIndex));



    if (!eventIndex) // eventIndex == 0
    {
        return processKeyboardEvent();
    }

    if (sWaitEvents[eventIndex] == sTimerEvent)
    {
        return processTimerEvent();
    }



    if (eventIndex <= UefiPointerDevices::getSimplePointersCount())
    {
        return processSimplePointerEvent(UefiPointerDevices::getSimplePointer(eventIndex - 1));
    }



    return processAbsolutePointerEvent(UefiPointerDevices::getAbsolutePointer(eventIndex - UefiPointerDevices::getSimplePointersCount() - 1));
}

NgosStatus BootloaderGUI::processKeyboardEvent()
{
    UEFI_LT((""));



    UefiInputKey key;

    UEFI_ASSERT_EXECUTION(UEFI::getSystemTable()->stdin->readKeyStroke(UEFI::getSystemTable()->stdin, &key), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("key.scanCode    = 0x%04X (%s)", key.scanCode, uefiInputKeyScanCodeToString(key.scanCode)));
    UEFI_LVVV(("key.unicodeChar = 0x%04X",      key.unicodeChar));



    if (sTimerEvent)
    {
        UEFI_ASSERT_EXECUTION(disableTimerEvent(), NgosStatus::ASSERTION);
    }



    UEFI_TEST_ASSERT(GUI::getFocusedWidget(),                            NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(GUI::getFocusedWidget()->getKeyboardEventHandler(), NgosStatus::ASSERTION);



    NgosStatus status = GUI::getFocusedWidget()->getKeyboardEventHandler()(key);
    AVOID_UNUSED(status);

    UEFI_TEST_ASSERT(status == NgosStatus::OK
                    ||
                    status == NgosStatus::NO_EFFECT, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer)
{
    UEFI_LT((" | pointer = 0x%p", pointer));

    UEFI_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);



    UefiAbsolutePointerState state;

    UEFI_ASSERT_EXECUTION(pointer->getState(pointer, &state), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("state.currentX      = %u",          state.currentX));
    UEFI_LVVV(("state.currentY      = %u",          state.currentY));
    UEFI_LVVV(("state.currentZ      = %u",          state.currentZ));
    UEFI_LVVV(("state.activeButtons = 0x%08X (%s)", state.activeButtons, uefiAbsolutePointerStateActiveButtonFlagsToString(state.activeButtons)));



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::processSimplePointerEvent(UefiSimplePointerProtocol *pointer)
{
    UEFI_LT((" | pointer = 0x%p", pointer));

    UEFI_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);



    UefiSimplePointerState state;

    UEFI_ASSERT_EXECUTION(pointer->getState(pointer, &state), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("state.relativeMovementX = %d", state.relativeMovementX));
    UEFI_LVVV(("state.relativeMovementY = %d", state.relativeMovementY));
    UEFI_LVVV(("state.relativeMovementZ = %d", state.relativeMovementZ));
    UEFI_LVVV(("state.leftButton        = %s", state.leftButton ? "true" : "false"));
    UEFI_LVVV(("state.rightButton       = %s", state.rightButton ? "true" : "false"));



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::processTimerEvent()
{
    UEFI_LT((""));



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::disableTimerEvent()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sTimerEvent, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(UEFI::closeEvent(sTimerEvent), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Closed timer event(0x%p)", sTimerEvent));

    sTimerEvent = 0;
    --sWaitEventsCount;



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onRebootButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sShutdownButton);
        case UefiInputKeyScanCode::DOWN:  return focusOsButton();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onRebootButtonPressed();
        case KEY_TAB:   return GUI::setFocusedWidget(sShutdownButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onShutdownButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::DOWN: return focusOsButton();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onShutdownButtonPressed();
        case KEY_TAB:   return focusFirstOsButton();

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onOsButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return focusPreviousOsButton();
        case UefiInputKeyScanCode::RIGHT: return focusNextOsButton();
        case UefiInputKeyScanCode::UP:    return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sMemoryTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onOsButtonPressed();
        case KEY_TAB:   return focusNextOsButtonOrGoDown();

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onLeftButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::RIGHT: return focusOsButtonLeft();
        case UefiInputKeyScanCode::UP:    return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sCpuTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onLeftButtonPressed();
        case KEY_TAB:   return focusOsButtonLeft();

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onRightButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT: return focusOsButtonRight();
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sNetworkTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onRightButtonPressed();
        case KEY_TAB:   return GUI::setFocusedWidget(sCpuTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onCpuTestButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sMemoryTestButton);
        case UefiInputKeyScanCode::UP:    return focusOsButton();
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sHddTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onCpuTestButtonPressed();
        case KEY_TAB:   return GUI::setFocusedWidget(sMemoryTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onMemoryTestButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sCpuTestButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sNetworkTestButton);
        case UefiInputKeyScanCode::UP:    return focusOsButton();
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sPartitionWizardButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onMemoryTestButtonPressed();
        case KEY_TAB:   return GUI::setFocusedWidget(sNetworkTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onNetworkTestButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sMemoryTestButton);
        case UefiInputKeyScanCode::UP:   return focusOsButton();
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sShellButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onNetworkTestButtonPressed();
        case KEY_TAB:   return GUI::setFocusedWidget(sHddTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onHddTestButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sPartitionWizardButton);
        case UefiInputKeyScanCode::UP:    return GUI::setFocusedWidget(sCpuTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onHddTestButtonPressed();
        case KEY_TAB:   return GUI::setFocusedWidget(sPartitionWizardButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onPartitionWizardButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sHddTestButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sShellButton);
        case UefiInputKeyScanCode::UP:    return GUI::setFocusedWidget(sMemoryTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onPartitionWizardButtonPressed();
        case KEY_TAB:   return GUI::setFocusedWidget(sShellButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onShellButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sPartitionWizardButton);
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sNetworkTestButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_ENTER: return onShellButtonPressed();
        case KEY_TAB:   return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus BootloaderGUI::onRebootButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::COLD, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onShutdownButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::SHUTDOWN, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onOsButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startOs(sOsButtonSelected), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onLeftButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(sOsButtonLeft > 0, NgosStatus::ASSERTION);

    for (i64 i = sOsButtonLeft; i < (i64)sOsButtonRight; ++i)
    {
        Button *button        = sOsButtons.at(i - 1);
        Button *visibleButton = sOsButtons.at(i);

        button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
    }

    --sOsButtonLeft;
    --sOsButtonRight;

    UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonLeft)->setVisible(true),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonRight)->setVisible(false), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(sOsButtonLeft > 0), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRightButton->setVisible(true),             NgosStatus::ASSERTION);



    if (!sOsButtonLeft) // sOsButtonLeft == 0
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sRightButton), NgosStatus::ASSERTION);
    }

    sOsButtonSelected = sOsButtonLeft;



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onRightButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(sOsButtonRight < sOsButtons.getSize(), NgosStatus::ASSERTION);

    for (i64 i = sOsButtonRight; i > (i64)sOsButtonLeft; --i)
    {
        Button *button        = sOsButtons.at(i);
        Button *visibleButton = sOsButtons.at(i - 1);

        button->setPosition(visibleButton->getPositionX(), visibleButton->getPositionY());
    }

    UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonLeft)->setVisible(false), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sOsButtons.at(sOsButtonRight)->setVisible(true), NgosStatus::ASSERTION);

    ++sOsButtonLeft;
    ++sOsButtonRight;

    UEFI_ASSERT_EXECUTION(sLeftButton->setVisible(true),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRightButton->setVisible(sOsButtonRight < sOsButtons.getSize()), NgosStatus::ASSERTION);



    if (sOsButtonRight >= sOsButtons.getSize())
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sLeftButton), NgosStatus::ASSERTION);
    }

    sOsButtonSelected = sOsButtonRight - 1;



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onCpuTestButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\cputest.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onMemoryTestButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\memorytest.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onNetworkTestButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\networktest.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onHddTestButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\hddtest.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onPartitionWizardButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\partitionwizard.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::onShellButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(Bootloader::startTool("tools\\shell.efi"), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
