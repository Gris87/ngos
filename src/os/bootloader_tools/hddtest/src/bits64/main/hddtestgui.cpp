#include "hddtestgui.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/misc/labelwidget.h>
#include <common/src/bits64/gui/widgets/special/rootwidget.h>
#include <common/src/bits64/gui/widgets/special/screenwidget.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <uefibase/src/bits64/uefi/uefi.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/src/bits64/uefi/uefipointerdevices.h>

#include "src/bits64/main/hddtest.h"



#define REBOOT_BUTTON_POSITION_X_PERCENT 90
#define REBOOT_BUTTON_POSITION_Y_PERCENT 0

#define SHUTDOWN_BUTTON_POSITION_X_PERCENT 95
#define SHUTDOWN_BUTTON_POSITION_Y_PERCENT 0

#define TABWIDGET_HEIGHT_PERCENT 70

#define TAB_BUTTON_WIDTH_PERCENT  20
#define TAB_BUTTON_HEIGHT_PERCENT 6

#define TAB_PAGE_PROPORTION 2

#define SYSTEM_BUTTON_SIZE_PERCENT 5
#define CURSOR_SIZE_PERCENT        2

#define TABWIDGET_PAGE_SYSTEM_INFORMATION 0
#define TABWIDGET_PAGE_ISSUES             1
#define TABWIDGET_PAGE_TEST               2
#define TABWIDGET_PAGE_SUMMARY            3



Button     *HddTestGUI::sRebootButton;
Button     *HddTestGUI::sShutdownButton;
TabWidget  *HddTestGUI::sTabWidget;
TabButton  *HddTestGUI::sSystemInformationTabButton;
TabButton  *HddTestGUI::sIssuesTabButton;
TabButton  *HddTestGUI::sTestTabButton;
TabButton  *HddTestGUI::sSummaryTabButton;
Image      *HddTestGUI::sWarningImage;
Image      *HddTestGUI::sCriticalImage;
Image      *HddTestGUI::sStartImage;
Image      *HddTestGUI::sStopImage;
u16         HddTestGUI::sWaitEventsCount;
uefi_event *HddTestGUI::sWaitEvents;



NgosStatus HddTestGUI::init(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    Image *backgroundImage;
    Image *buttonNormalImage;
    Image *buttonHoverImage;
    Image *buttonPressedImage;
    Image *buttonFocusedImage;
    Image *buttonFocusedHoverImage;
    Image *buttonNormalResizedImage;
    Image *buttonHoverResizedImage;
    Image *buttonPressedResizedImage;
    Image *buttonFocusedResizedImage;
    Image *buttonFocusedHoverResizedImage;
    Image *tabNormalImage;
    Image *tabHoverImage;
    Image *tabPressedImage;
    Image *tabFocusedImage;
    Image *tabFocusedHoverImage;
    Image *tabNormalResizedImage;
    Image *tabHoverResizedImage;
    Image *tabPressedResizedImage;
    Image *tabFocusedResizedImage;
    Image *tabFocusedHoverResizedImage;
    Image *selectedTabNormalImage;
    Image *selectedTabHoverImage;
    Image *selectedTabPressedImage;
    Image *selectedTabFocusedImage;
    Image *selectedTabFocusedHoverImage;
    Image *selectedTabNormalResizedImage;
    Image *selectedTabHoverResizedImage;
    Image *selectedTabPressedResizedImage;
    Image *selectedTabFocusedResizedImage;
    Image *selectedTabFocusedHoverResizedImage;
    Image *tabWidgetPanelImage;
    Image *systemInformationImage;
    Image *issuesImage;
    Image *testImage;
    Image *summaryImage;
    Image *tableBackgroundImage;
    Image *tableHeaderImage;
    Image *rebootImage;
    Image *shutdownImage;
    Image *cursorImage;



    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/background.jpg",                  &backgroundImage),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_normal.9.png",             &buttonNormalImage),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_hover.9.png",              &buttonHoverImage),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_pressed.9.png",            &buttonPressedImage),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_focused.9.png",            &buttonFocusedImage),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/button_focused_hover.9.png",      &buttonFocusedHoverImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/tab_normal.9.png",                &tabNormalImage),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/tab_hover.9.png",                 &tabHoverImage),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/tab_pressed.9.png",               &tabPressedImage),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/tab_focused.9.png",               &tabFocusedImage),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/tab_focused_hover.9.png",         &tabFocusedHoverImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/selectedtab_normal.9.png",        &selectedTabNormalImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/selectedtab_hover.9.png",         &selectedTabHoverImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/selectedtab_pressed.9.png",       &selectedTabPressedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/selectedtab_focused.9.png",       &selectedTabFocusedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/selectedtab_focused_hover.9.png", &selectedTabFocusedHoverImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/tabwidget_panel.9.png",           &tabWidgetPanelImage),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/system_information.png",          &systemInformationImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/issues.png",                      &issuesImage),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/test.png",                        &testImage),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/summary.png",                     &summaryImage),                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/table_background.9.png",          &tableBackgroundImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/table_header.9.png",              &tableHeaderImage),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/reboot.png",                      &rebootImage),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/shutdown.png",                    &shutdownImage),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/cursor.png",                      &cursorImage),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/warning.png",                     &sWarningImage),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/critical.png",                    &sCriticalImage),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/start.png",                       &sStartImage),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/stop.png",                        &sStopImage),                   NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(params->screensCount > 0, NgosStatus::ASSERTION);

    u64 screenWidth  = params->screens[0]->mode->info->horizontalResolution;
    u64 screenHeight = params->screens[0]->mode->info->verticalResolution;



    u64 systemButtonSize = screenWidth * SYSTEM_BUTTON_SIZE_PERCENT / 100;
    u64 cursorSize       = screenWidth * CURSOR_SIZE_PERCENT        / 100;



    u64 tabWidgetHeight = screenHeight * TABWIDGET_HEIGHT_PERCENT  / 100;
    u64 tabButtonHeight = screenWidth  * TAB_BUTTON_HEIGHT_PERCENT / 100;

    u64 tabPageHeight = tabWidgetHeight - tabButtonHeight;



    u64 tabPageWidth = tabPageHeight * TAB_PAGE_PROPORTION;

    if (tabPageWidth > screenWidth)
    {
        tabPageWidth = screenWidth;

        tabPageHeight   = tabPageWidth / TAB_PAGE_PROPORTION;
        tabWidgetHeight = tabPageHeight + tabButtonHeight;
    }



    u64 tabWidgetWidth = tabPageWidth;
    u64 tabButtonWidth = tabWidgetWidth * TAB_BUTTON_WIDTH_PERCENT / 100;

    NinePatch *patch = tabWidgetPanelImage->getNinePatch();

    if (patch)
    {
        tabPageWidth  -= patch->getPaddingLeft() + patch->getPaddingRight();
        tabPageHeight -= patch->getPaddingTop()  + patch->getPaddingBottom();
    }



    RootWidget *rootWidget = new RootWidget();

    UEFI_ASSERT_EXECUTION(rootWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rootWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    ScreenWidget *screenWidget = new ScreenWidget(backgroundImage, params->screens[0], rootWidget);

    UEFI_ASSERT_EXECUTION(screenWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(screenWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonNormalImage,       systemButtonSize, systemButtonSize, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonHoverImage,        systemButtonSize, systemButtonSize, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonPressedImage,      systemButtonSize, systemButtonSize, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedImage,      systemButtonSize, systemButtonSize, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedHoverImage, systemButtonSize, systemButtonSize, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



    sRebootButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, rebootImage, nullptr, "", rootWidget);

    UEFI_ASSERT_EXECUTION(sRebootButton->setPosition(screenWidth * REBOOT_BUTTON_POSITION_X_PERCENT / 100, screenHeight * REBOOT_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setSize(systemButtonSize, systemButtonSize),                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setKeyboardEventHandler(onRebootButtonKeyboardEvent),                                                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setPressEventHandler(onRebootButtonPressed),                                                                              NgosStatus::ASSERTION);



    sShutdownButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, shutdownImage, nullptr, "", rootWidget);

    UEFI_ASSERT_EXECUTION(sShutdownButton->setPosition(screenWidth * SHUTDOWN_BUTTON_POSITION_X_PERCENT / 100, screenHeight * SHUTDOWN_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setSize(systemButtonSize, systemButtonSize),                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setKeyboardEventHandler(onShutdownButtonKeyboardEvent),                                                                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setPressEventHandler(onShutdownButtonPressed),                                                                                NgosStatus::ASSERTION);



    sTabWidget = new TabWidget(tabWidgetPanelImage, rootWidget);



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(tabNormalImage,               tabButtonWidth, tabButtonHeight, &tabNormalResizedImage),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(tabHoverImage,                tabButtonWidth, tabButtonHeight, &tabHoverResizedImage),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(tabPressedImage,              tabButtonWidth, tabButtonHeight, &tabPressedResizedImage),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(tabFocusedImage,              tabButtonWidth, tabButtonHeight, &tabFocusedResizedImage),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(tabFocusedHoverImage,         tabButtonWidth, tabButtonHeight, &tabFocusedHoverResizedImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(selectedTabNormalImage,       tabButtonWidth, tabButtonHeight, &selectedTabNormalResizedImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(selectedTabHoverImage,        tabButtonWidth, tabButtonHeight, &selectedTabHoverResizedImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(selectedTabPressedImage,      tabButtonWidth, tabButtonHeight, &selectedTabPressedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(selectedTabFocusedImage,      tabButtonWidth, tabButtonHeight, &selectedTabFocusedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(selectedTabFocusedHoverImage, tabButtonWidth, tabButtonHeight, &selectedTabFocusedHoverResizedImage), NgosStatus::ASSERTION);



    sSystemInformationTabButton = new TabButton(tabNormalImage, tabHoverImage, tabPressedImage, tabFocusedImage, tabFocusedHoverImage, selectedTabNormalImage, selectedTabHoverImage, selectedTabPressedImage, selectedTabFocusedImage, selectedTabFocusedHoverImage, tabNormalResizedImage, tabHoverResizedImage, tabPressedResizedImage, tabFocusedResizedImage, tabFocusedHoverResizedImage, selectedTabNormalResizedImage, selectedTabHoverResizedImage, selectedTabPressedResizedImage, selectedTabFocusedResizedImage, selectedTabFocusedHoverResizedImage, systemInformationImage, nullptr, "System Info", sTabWidget);

    UEFI_ASSERT_EXECUTION(sSystemInformationTabButton->setSize(tabButtonWidth, tabButtonHeight),                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSystemInformationTabButton->setKeyboardEventHandler(onSystemInformationTabButtonKeyboardEvent), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSystemInformationTabButton->setPressEventHandler(onSystemInformationTabButtonPressed),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->addTabButton(sSystemInformationTabButton),                                           NgosStatus::ASSERTION);



    sIssuesTabButton = new TabButton(tabNormalImage, tabHoverImage, tabPressedImage, tabFocusedImage, tabFocusedHoverImage, selectedTabNormalImage, selectedTabHoverImage, selectedTabPressedImage, selectedTabFocusedImage, selectedTabFocusedHoverImage, tabNormalResizedImage, tabHoverResizedImage, tabPressedResizedImage, tabFocusedResizedImage, tabFocusedHoverResizedImage, selectedTabNormalResizedImage, selectedTabHoverResizedImage, selectedTabPressedResizedImage, selectedTabFocusedResizedImage, selectedTabFocusedHoverResizedImage, issuesImage, nullptr, "Issues     ", sTabWidget);

    UEFI_ASSERT_EXECUTION(sIssuesTabButton->setSize(tabButtonWidth, tabButtonHeight),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sIssuesTabButton->setKeyboardEventHandler(onIssuesTabButtonKeyboardEvent), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sIssuesTabButton->setPressEventHandler(onIssuesTabButtonPressed),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->addTabButton(sIssuesTabButton),                                NgosStatus::ASSERTION);



    sTestTabButton = new TabButton(tabNormalImage, tabHoverImage, tabPressedImage, tabFocusedImage, tabFocusedHoverImage, selectedTabNormalImage, selectedTabHoverImage, selectedTabPressedImage, selectedTabFocusedImage, selectedTabFocusedHoverImage, tabNormalResizedImage, tabHoverResizedImage, tabPressedResizedImage, tabFocusedResizedImage, tabFocusedHoverResizedImage, selectedTabNormalResizedImage, selectedTabHoverResizedImage, selectedTabPressedResizedImage, selectedTabFocusedResizedImage, selectedTabFocusedHoverResizedImage, testImage, nullptr, "Test       ", sTabWidget);

    UEFI_ASSERT_EXECUTION(sTestTabButton->setSize(tabButtonWidth, tabButtonHeight),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTabButton->setKeyboardEventHandler(onTestTabButtonKeyboardEvent), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTabButton->setPressEventHandler(onTestTabButtonPressed),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->addTabButton(sTestTabButton),                              NgosStatus::ASSERTION);



    sSummaryTabButton = new TabButton(tabNormalImage, tabHoverImage, tabPressedImage, tabFocusedImage, tabFocusedHoverImage, selectedTabNormalImage, selectedTabHoverImage, selectedTabPressedImage, selectedTabFocusedImage, selectedTabFocusedHoverImage, tabNormalResizedImage, tabHoverResizedImage, tabPressedResizedImage, tabFocusedResizedImage, tabFocusedHoverResizedImage, selectedTabNormalResizedImage, selectedTabHoverResizedImage, selectedTabPressedResizedImage, selectedTabFocusedResizedImage, selectedTabFocusedHoverResizedImage, summaryImage, nullptr, "Summary    ", sTabWidget);

    UEFI_ASSERT_EXECUTION(sSummaryTabButton->setSize(tabButtonWidth, tabButtonHeight),                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTabButton->setKeyboardEventHandler(onSummaryTabButtonKeyboardEvent), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTabButton->setPressEventHandler(onSummaryTabButtonPressed),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->addTabButton(sSummaryTabButton),                                 NgosStatus::ASSERTION);



    TabPageWidget *systemInformationTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(systemInformationTabPageWidget), NgosStatus::ASSERTION);



    TabPageWidget *issuesTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(issuesTabPageWidget), NgosStatus::ASSERTION);



    TabPageWidget *testTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(testTabPageWidget), NgosStatus::ASSERTION);



    TabPageWidget *summaryTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(summaryTabPageWidget), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sTabWidget->setPosition((screenWidth - tabWidgetWidth) >> 1, 0), NgosStatus::ASSERTION); // ">> 1"  == "/ 2"
    UEFI_ASSERT_EXECUTION(sTabWidget->setSize(tabWidgetWidth, tabWidgetHeight),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SYSTEM_INFORMATION),   NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sSystemInformationTabButton), NgosStatus::ASSERTION);



    CursorWidget *cursorWidget = new CursorWidget(cursorImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cursorWidget->setPosition(GUI::getFocusedWidget()->getGlobalPositionX() + (GUI::getFocusedWidget()->getWidth() >> 1), GUI::getFocusedWidget()->getGlobalPositionY() + (GUI::getFocusedWidget()->getHeight() >> 1)), NgosStatus::ASSERTION); // ">> 1" == "/ 2"
    UEFI_ASSERT_EXECUTION(cursorWidget->setSize(cursorSize, cursorSize),                                                                                                                                                                      NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(),                              NgosStatus::ASSERTION);

    UEFI_TEST_ASSERT(GUI::isUpdatesEnabled(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::exec()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(generateWaitEventList(), NgosStatus::ASSERTION);

    do
    {
        UEFI_ASSERT_EXECUTION(waitForEvent(), NgosStatus::ASSERTION);
    } while(true);



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::focusTabFirstWidget()
{
    UEFI_LT((""));



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::generateWaitEventList()
{
    UEFI_LT((""));



    sWaitEventsCount = UefiPointerDevices::getSimplePointersCount() + UefiPointerDevices::getAbsolutePointersCount() + 1; // "+ 1" = keyboard event
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



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::waitForEvent()
{
    UEFI_LT((""));



    u64 eventIndex;

    UEFI_ASSERT_EXECUTION(UEFI::waitForEvent(sWaitEventsCount, sWaitEvents, &eventIndex), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("eventIndex = %u", eventIndex));



    if (!eventIndex) // eventIndex == 0
    {
        return processKeyboardEvent();
    }



    if (eventIndex <= UefiPointerDevices::getSimplePointersCount())
    {
        return processSimplePointerEvent(UefiPointerDevices::getSimplePointer(eventIndex - 1));
    }



    return processAbsolutePointerEvent(UefiPointerDevices::getAbsolutePointer(eventIndex - UefiPointerDevices::getSimplePointersCount() - 1));
}

NgosStatus HddTestGUI::processKeyboardEvent()
{
    UEFI_LT((""));



    UefiInputKey key;

    UEFI_ASSERT_EXECUTION(UEFI::getSystemTable()->stdin->readKeyStroke(UEFI::getSystemTable()->stdin, &key), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("key.scanCode    = 0x%04X (%s)", key.scanCode, uefiInputKeyScanCodeToString(key.scanCode)));
    UEFI_LVVV(("key.unicodeChar = 0x%04X",      key.unicodeChar));



    UEFI_TEST_ASSERT(GUI::getFocusedWidget(),                            NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(GUI::getFocusedWidget()->getKeyboardEventHandler(), NgosStatus::ASSERTION);



    NgosStatus status = GUI::getFocusedWidget()->getKeyboardEventHandler()(key);

    if (status == NgosStatus::NO_EFFECT)
    {
        status = GUI::getFocusedWidget()->onKeyboardEvent(key);

        if (status == NgosStatus::NO_EFFECT)
        {
            status = GUI::processKeyboardEvent(key);
        }
    }

    UEFI_TEST_ASSERT(status == NgosStatus::OK
                    ||
                    status == NgosStatus::NO_EFFECT, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::processSimplePointerEvent(UefiSimplePointerProtocol *pointer)
{
    UEFI_LT((" | pointer = 0x%p", pointer));

    UEFI_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);



    UefiSimplePointerState state;

    if (pointer->getState(pointer, &state) == UefiStatus::SUCCESS)
    {
        UEFI_LVVV(("state.relativeMovementX = %d", state.relativeMovementX));
        UEFI_LVVV(("state.relativeMovementY = %d", state.relativeMovementY));
        UEFI_LVVV(("state.relativeMovementZ = %d", state.relativeMovementZ));
        UEFI_LVVV(("state.leftButton        = %s", state.leftButton ? "true" : "false"));
        UEFI_LVVV(("state.rightButton       = %s", state.rightButton ? "true" : "false"));



        UEFI_ASSERT_EXECUTION(GUI::processSimplePointerState(&state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer)
{
    UEFI_LT((" | pointer = 0x%p", pointer));

    UEFI_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);



    UefiAbsolutePointerState state;

    if (pointer->getState(pointer, &state) == UefiStatus::SUCCESS)
    {
        UEFI_LVVV(("state.currentX      = %u", state.currentX));
        UEFI_LVVV(("state.currentY      = %u", state.currentY));
        UEFI_LVVV(("state.currentZ      = %u", state.currentZ));
        UEFI_LVVV(("state.activeButtons = %s", flagsToFullString(state.activeButtons)));



        UEFI_ASSERT_EXECUTION(GUI::processAbsolutePointerState(pointer, &state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::onRebootButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sSummaryTabButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sShutdownButton);
        case UefiInputKeyScanCode::DOWN:  return focusTabFirstWidget();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sShutdownButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus HddTestGUI::onShutdownButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::DOWN: return focusTabFirstWidget();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sSystemInformationTabButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus HddTestGUI::onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sIssuesTabButton);
        case UefiInputKeyScanCode::DOWN:  return focusTabFirstWidget();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sIssuesTabButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus HddTestGUI::onIssuesTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sSystemInformationTabButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sTestTabButton);
        case UefiInputKeyScanCode::DOWN:  return focusTabFirstWidget();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sTestTabButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus HddTestGUI::onTestTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sIssuesTabButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sSummaryTabButton);
        case UefiInputKeyScanCode::DOWN:  return focusTabFirstWidget();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sSummaryTabButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus HddTestGUI::onSummaryTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sTestTabButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::DOWN:  return focusTabFirstWidget();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return focusTabFirstWidget();

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus HddTestGUI::onRebootButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::COLD, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::onShutdownButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::SHUTDOWN, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::onSystemInformationTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SYSTEM_INFORMATION), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::onIssuesTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_ISSUES), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::onTestTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_TEST), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus HddTestGUI::onSummaryTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SUMMARY), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
