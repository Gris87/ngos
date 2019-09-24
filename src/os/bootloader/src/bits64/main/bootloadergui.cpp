#include "bootloadergui.h"

#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
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



u16         BootloaderGUI::sWaitEventsCount;
uefi_event *BootloaderGUI::sWaitEvents;
uefi_event  BootloaderGUI::sTimerEvent;



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



    LabelWidget *infoLabel = new LabelWidget("Use arrow keys to select, Enter to boot, F8 for options", rootWidget);

    UEFI_ASSERT_EXECUTION(infoLabel->setPosition(screenWidth * INFO_LABEL_POSITION_X_PERCENT     / 100, screenHeight * INFO_LABEL_POSITION_Y_PERCENT      / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(infoLabel->setSize(screenWidth     * INFO_LABEL_POSITION_WIDTH_PERCENT / 100, screenHeight * INFO_LABEL_POSITION_HEIGHT_PERCENT / 100), NgosStatus::ASSERTION);



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



    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(osButtons.getHead()->getData()), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget),     NgosStatus::ASSERTION);



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
