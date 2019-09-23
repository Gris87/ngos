#include "bootloadergui.h"

#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/misc/rootwidget.h>
#include <common/src/bits64/gui/widgets/misc/screenwidget.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/bootloader.h"



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

#define MEMORY_TEST_BUTTON_POSITION_X_PERCENT 51
#define MEMORY_TEST_BUTTON_POSITION_Y_PERCENT 48

#define HDD_TEST_BUTTON_POSITION_X_PERCENT 10
#define HDD_TEST_BUTTON_POSITION_Y_PERCENT 59

#define PARTITION_WIZARD_BUTTON_POSITION_X_PERCENT 51
#define PARTITION_WIZARD_BUTTON_POSITION_Y_PERCENT 59

#define CURSOR_POSITION_X_PERCENT 50
#define CURSOR_POSITION_Y_PERCENT 50

#define OS_BUTTON_SIZE_PERCENT     20
#define ARROW_BUTTON_SIZE_PERCENT  6
#define TOOL_BUTTON_WIDTH_PERCENT  39
#define TOOL_BUTTON_HEIGHT_PERCENT 10
#define SYSTEM_BUTTON_SIZE_PERCENT 5
#define CURSOR_SIZE_PERCENT        2



NgosStatus BootloaderGUI::init(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    Image  *backgroundImage;
    Image  *buttonFocusedImage;
    Image  *buttonHoverImage;
    Image  *buttonNormalImage;
    Image  *buttonPressedImage;
    Image  *cpuTestImage;
    Image  *cursorImage;
    Image  *hddTestImage;
    Image  *memoryTestImage;
    Image  *partitionWizardImage;
    Image  *pointerImage;
    Image  *rebootImage;
    Image  *shutdownImage;
    Image*  osImages[(u64)OsType::MAXIMUM];

    memzero(osImages, sizeof(osImages));



    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/background.jpg",       &backgroundImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_focused.9.png", &buttonFocusedImage),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_hover.9.png",   &buttonHoverImage),     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_normal.9.png",  &buttonNormalImage),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/button_pressed.9.png", &buttonPressedImage),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/cpu_test.png",         &cpuTestImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/cursor.png",           &cursorImage),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/hdd_test.png",         &hddTestImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/memory_test.png",      &memoryTestImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/partition_wizard.png", &partitionWizardImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/pointer.png",          &pointerImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/reboot.png",           &rebootImage),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/shutdown.png",         &shutdownImage),        NgosStatus::ASSERTION);



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



    Button *rebootButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, rebootImage, rootWidget);

    UEFI_ASSERT_EXECUTION(rebootButton->setPosition(screenWidth * REBOOT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * REBOOT_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rebootButton->setSize(systemButtonSize, systemButtonSize),                                                                              NgosStatus::ASSERTION);



    Button *shutdownButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, shutdownImage, rootWidget);

    UEFI_ASSERT_EXECUTION(shutdownButton->setPosition(screenWidth * SHUTDOWN_BUTTON_POSITION_X_PERCENT / 100, screenHeight * SHUTDOWN_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(shutdownButton->setSize(systemButtonSize, systemButtonSize),                                                                                  NgosStatus::ASSERTION);



    List<Button *>       osButtons;
    u64                  osCount = 0;
    ListElement<OsInfo> *element = Bootloader::getOSes().getHead();

    while (element)
    {
        const OsInfo &os = element->getData();



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

        UEFI_ASSERT_EXECUTION(osButton->setSize(osButtonSize, osButtonSize), NgosStatus::ASSERTION);

        osButtons.append(osButton);



        ++osCount;
        element = element->getNext();
    }



    if (osCount)
    {
        if (osCount > OS_VISIBLE_COUNT)
        {
            osCount = OS_VISIBLE_COUNT;

            Image *arrowLeftImage;
            Image *arrowRightImage;

            UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/arrow_left.png",  &arrowLeftImage),  NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Bootloader::loadImageFromDiskOrAssets("images/arrow_right.png", &arrowRightImage), NgosStatus::ASSERTION);



            u64 arrowButtonSize = screenWidth * ARROW_BUTTON_SIZE_PERCENT / 100;



            Button *leftButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, arrowLeftImage, rootWidget);

            UEFI_ASSERT_EXECUTION(leftButton->setPosition(screenWidth * LEFT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * OS_REGION_VERTICAL_CENTER_PERCENT / 100 - (arrowButtonSize >> 1)), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(leftButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                        NgosStatus::ASSERTION);



            Button *rightButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, arrowRightImage, rootWidget);

            UEFI_ASSERT_EXECUTION(rightButton->setPosition(screenWidth * RIGHT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * OS_REGION_VERTICAL_CENTER_PERCENT / 100 - (arrowButtonSize >> 1)), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(rightButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                         NgosStatus::ASSERTION);
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



        ListElement<Button *> *element = osButtons.getHead();

        while (element && osCount)
        {
            element->getData()->setPosition(osButtonPositionX, osButtonPositionY);
            osButtonPositionX += osButtonStep;

            --osCount;
            element = element->getNext();
        }

        while (element)
        {
            element->getData()->setVisible(false);

            element = element->getNext();
        }
    }



    Button *cpuTestButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, cpuTestImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cpuTestButton->setPosition(screenWidth * CPU_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * CPU_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                   NgosStatus::ASSERTION);



    Button *memoryTestButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, memoryTestImage, rootWidget);

    UEFI_ASSERT_EXECUTION(memoryTestButton->setPosition(screenWidth * MEMORY_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * MEMORY_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(memoryTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                         NgosStatus::ASSERTION);



    Button *hddTestButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, hddTestImage, rootWidget);

    UEFI_ASSERT_EXECUTION(hddTestButton->setPosition(screenWidth * HDD_TEST_BUTTON_POSITION_X_PERCENT / 100, screenHeight * HDD_TEST_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(hddTestButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                   NgosStatus::ASSERTION);



    Button *partitionWizardButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, partitionWizardImage, rootWidget);

    UEFI_ASSERT_EXECUTION(partitionWizardButton->setPosition(screenWidth * PARTITION_WIZARD_BUTTON_POSITION_X_PERCENT / 100, screenHeight * PARTITION_WIZARD_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(partitionWizardButton->setSize(toolButtonWidth, toolButtonHeight),                                                                                                   NgosStatus::ASSERTION);



    CursorWidget *cursorWidget = new CursorWidget(cursorImage, pointerImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cursorWidget->setPosition(screenWidth * CURSOR_POSITION_X_PERCENT / 100, screenHeight * CURSOR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cursorWidget->setSize(cursorSize, cursorSize),                                                                            NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus BootloaderGUI::exec()
{
    UEFI_LT((""));



    return NgosStatus::OK;
}
