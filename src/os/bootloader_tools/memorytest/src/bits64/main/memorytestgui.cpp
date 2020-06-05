#include "memorytestgui.h"

#include <common/src/bits64/dmi/dmi.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/misc/labelwidget.h>
#include <common/src/bits64/gui/widgets/misc/panelwidget.h>
#include <common/src/bits64/gui/widgets/special/rootwidget.h>
#include <common/src/bits64/gui/widgets/special/screenwidget.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/utils.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <uefibase/src/bits64/uefi/uefi.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/src/bits64/uefi/uefipointerdevices.h>

#include "src/bits64/main/memorytest.h"



#define TABWIDGET_HEIGHT_PERCENT 70

#define TAB_BUTTON_WIDTH_PERCENT  20
#define TAB_BUTTON_HEIGHT_PERCENT 6

#define TAB_PAGE_PROPORTION 2

#define SUMMARY_MEMORY_INFO_POSITION_X_PERCENT 1
#define SUMMARY_MEMORY_INFO_POSITION_Y_PERCENT 2
#define SUMMARY_MEMORY_INFO_WIDTH_PERCENT      98
#define SUMMARY_MEMORY_INFO_HEIGHT_PERCENT     13

#define TOTAL_MEMORY_CAPACITY_POSITION_X_PERCENT 1
#define TOTAL_MEMORY_CAPACITY_POSITION_Y_PERCENT 2
#define TOTAL_MEMORY_CAPACITY_WIDTH_PERCENT      98
#define TOTAL_MEMORY_CAPACITY_HEIGHT_PERCENT     32

#define MAXIMUM_MEMORY_CAPACITY_POSITION_X_PERCENT 1
#define MAXIMUM_MEMORY_CAPACITY_POSITION_Y_PERCENT 34
#define MAXIMUM_MEMORY_CAPACITY_WIDTH_PERCENT      98
#define MAXIMUM_MEMORY_CAPACITY_HEIGHT_PERCENT     32

#define NUMBER_OF_MEMORY_DEVICES_POSITION_X_PERCENT 1
#define NUMBER_OF_MEMORY_DEVICES_POSITION_Y_PERCENT 66
#define NUMBER_OF_MEMORY_DEVICES_WIDTH_PERCENT      98
#define NUMBER_OF_MEMORY_DEVICES_HEIGHT_PERCENT     32

#define MEMORY_INFO_REGION_POSITION_X_PERCENT 0
#define MEMORY_INFO_REGION_POSITION_Y_PERCENT 15
#define MEMORY_INFO_REGION_WIDTH_PERCENT      100
#define MEMORY_INFO_REGION_HEIGHT_PERCENT     85

#define MEMORY_INFO_REGION_OVERRIDE_POSITION_X_PERCENT 5
#define MEMORY_INFO_REGION_OVERRIDE_POSITION_Y_PERCENT 15
#define MEMORY_INFO_REGION_OVERRIDE_WIDTH_PERCENT      90
#define MEMORY_INFO_REGION_OVERRIDE_HEIGHT_PERCENT     85

#define MEMORY_INFO_LEFT_BUTTON_POSITION_X_PERCENT  0
#define MEMORY_INFO_RIGHT_BUTTON_POSITION_X_PERCENT 95
#define MEMORY_INFO_ARROW_BUTTON_SIZE_PERCENT       5

#define MEMORY_INFO_IMAGE_POSITION_X_PERCENT 1
#define MEMORY_INFO_IMAGE_POSITION_Y_PERCENT 1
#define MEMORY_INFO_IMAGE_SIZE_PERCENT       98

#define MEMORY_INFO_DEVICE_LOCATOR_POSITION_X_PERCENT 2
#define MEMORY_INFO_DEVICE_LOCATOR_POSITION_Y_PERCENT 1
#define MEMORY_INFO_DEVICE_LOCATOR_WIDTH_PERCENT      97
#define MEMORY_INFO_DEVICE_LOCATOR_HEIGHT_PERCENT     14

#define MEMORY_INFO_MANUFACTURER_POSITION_X_PERCENT 2
#define MEMORY_INFO_MANUFACTURER_POSITION_Y_PERCENT 15
#define MEMORY_INFO_MANUFACTURER_WIDTH_PERCENT      97
#define MEMORY_INFO_MANUFACTURER_HEIGHT_PERCENT     14

#define MEMORY_INFO_SERIAL_NUMBER_POSITION_X_PERCENT 2
#define MEMORY_INFO_SERIAL_NUMBER_POSITION_Y_PERCENT 29
#define MEMORY_INFO_SERIAL_NUMBER_WIDTH_PERCENT      97
#define MEMORY_INFO_SERIAL_NUMBER_HEIGHT_PERCENT     14

#define MEMORY_INFO_PART_NUMBER_POSITION_X_PERCENT 2
#define MEMORY_INFO_PART_NUMBER_POSITION_Y_PERCENT 43
#define MEMORY_INFO_PART_NUMBER_WIDTH_PERCENT      97
#define MEMORY_INFO_PART_NUMBER_HEIGHT_PERCENT     14

#define MEMORY_INFO_SIZE_POSITION_X_PERCENT 2
#define MEMORY_INFO_SIZE_POSITION_Y_PERCENT 57
#define MEMORY_INFO_SIZE_WIDTH_PERCENT      97
#define MEMORY_INFO_SIZE_HEIGHT_PERCENT     14

#define MEMORY_INFO_TYPE_POSITION_X_PERCENT 2
#define MEMORY_INFO_TYPE_POSITION_Y_PERCENT 71
#define MEMORY_INFO_TYPE_WIDTH_PERCENT      97
#define MEMORY_INFO_TYPE_HEIGHT_PERCENT     14

#define MEMORY_INFO_SPEED_POSITION_X_PERCENT 2
#define MEMORY_INFO_SPEED_POSITION_Y_PERCENT 85
#define MEMORY_INFO_SPEED_WIDTH_PERCENT      97
#define MEMORY_INFO_SPEED_HEIGHT_PERCENT     14

#define MEMORY_INFO_NOT_INSTALLED_POSITION_X_PERCENT 2
#define MEMORY_INFO_NOT_INSTALLED_POSITION_Y_PERCENT 43
#define MEMORY_INFO_NOT_INSTALLED_WIDTH_PERCENT      97
#define MEMORY_INFO_NOT_INSTALLED_HEIGHT_PERCENT     14

#define ISSUES_TABLEWIDGET_POSITION_X_PERCENT 1
#define ISSUES_TABLEWIDGET_POSITION_Y_PERCENT 1
#define ISSUES_TABLEWIDGET_WIDTH_PERCENT      98
#define ISSUES_TABLEWIDGET_HEIGHT_PERCENT     98
#define ISSUES_TABLEWIDGET_ROW_HEIGHT         27

#define ISSUES_COLUMN_ICON_WIDTH 27

#define SUMMARY_TOTAL_TEXT_POSITION_X_PERCENT 80
#define SUMMARY_TOTAL_TEXT_POSITION_Y_PERCENT 1
#define SUMMARY_TOTAL_TEXT_WIDTH_PERCENT      19
#define SUMMARY_TOTAL_TEXT_HEIGHT_PERCENT     8

#define SUMMARY_TABLEWIDGET_POSITION_X_PERCENT 1
#define SUMMARY_TABLEWIDGET_POSITION_Y_PERCENT 10
#define SUMMARY_TABLEWIDGET_WIDTH_PERCENT      98
#define SUMMARY_TABLEWIDGET_HEIGHT_PERCENT     89
#define SUMMARY_TABLEWIDGET_ROW_HEIGHT         27

#define SUMMARY_COLUMN_NAME_WIDTH_PERCENT  80
#define SUMMARY_COLUMN_SCORE_WIDTH_PERCENT 20

#define SYSTEM_BUTTON_RESERVED_PROPORTION 0.7
#define CURSOR_SIZE                       20

#define TABWIDGET_PAGE_SYSTEM_INFORMATION 0
#define TABWIDGET_PAGE_ISSUES             1
#define TABWIDGET_PAGE_TEST               2
#define TABWIDGET_PAGE_SUMMARY            3

#define COLUMN_NAME  0
#define COLUMN_SCORE 1

#define COLUMN_ICON        0
#define COLUMN_DESCRIPTION 1

#define SCORE_PER_1GB_RAM 125
#define SCORE_PER_100_MHZ 40

#define BLACK_COLOR    0xFF000000
#define DISABLED_COLOR 0xFFB2B2B2



Button                                *MemoryTestGUI::sRebootButton;
Button                                *MemoryTestGUI::sShutdownButton;
TabWidget                             *MemoryTestGUI::sTabWidget;
TabButton                             *MemoryTestGUI::sSystemInformationTabButton;
TabButton                             *MemoryTestGUI::sIssuesTabButton;
TabButton                             *MemoryTestGUI::sTestTabButton;
TabButton                             *MemoryTestGUI::sSummaryTabButton;
ArrayList<ArrayList<PanelWidget *> *>  MemoryTestGUI::sInfoPages;
u64                                    MemoryTestGUI::sInfoCurrentPage;
Button                                *MemoryTestGUI::sInfoLeftButton;
Button                                *MemoryTestGUI::sInfoRightButton;
Image                                 *MemoryTestGUI::sWarningImage;
Image                                 *MemoryTestGUI::sCriticalImage;
TableWidget                           *MemoryTestGUI::sIssuesTableWidget;
Image                                 *MemoryTestGUI::sStartImage;
Image                                 *MemoryTestGUI::sStopImage;
LabelWidget                           *MemoryTestGUI::sSummaryTotalLabelWidget;
TableWidget                           *MemoryTestGUI::sSummaryTableWidget;
u64                                    MemoryTestGUI::sSummaryTotal;
UefiMpServicesProtocol                *MemoryTestGUI::sMpServices;
u16                                    MemoryTestGUI::sWaitEventsCount;
uefi_event                            *MemoryTestGUI::sWaitEvents;
u16                                    MemoryTestGUI::sFirstProcessorEventIndex;
u64                                    MemoryTestGUI::sNumberOfRunningProcessors;
bool                                   MemoryTestGUI::sTerminated;



NgosStatus MemoryTestGUI::init(BootParams *params)
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
    Image *infoPanelImage;
    Image *memoryInfoPanelImage;
    Image *memoryInfoPanelResizedImage;
    Image *memoryDeviceImage;
    Image *memoryDeviceResizedImage;
    Image *memoryDeviceDisabledImage;
    Image *memoryDeviceDisabledResizedImage;
    Image *arrowLeftImage = nullptr;
    Image *arrowRightImage;
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
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/info_panel.9.png",                &infoPanelImage),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/memory_info_panel.9.png",         &memoryInfoPanelImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/memory_device.png",               &memoryDeviceImage),            NgosStatus::ASSERTION);
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



    RootWidget *rootWidget = new RootWidget();

    UEFI_ASSERT_EXECUTION(rootWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rootWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    ScreenWidget *screenWidget = new ScreenWidget(backgroundImage, params->screens[0], rootWidget);

    UEFI_ASSERT_EXECUTION(screenWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(screenWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    u64 allowedWidthForSystemButtons   = screenWidth  * (100 - (GRAPHICAL_CONSOLE_POSITION_X_PERCENT + GRAPHICAL_CONSOLE_WIDTH_PERCENT)) / 100;
    u64 allowedHeighthForSystemButtons = screenHeight * GRAPHICAL_CONSOLE_HEIGHT_PERCENT                                                 / 100 - allowedWidthForSystemButtons * SYSTEM_BUTTON_RESERVED_PROPORTION;

    u64 systemButtonSize = allowedHeighthForSystemButtons / 2;

    if (systemButtonSize > allowedWidthForSystemButtons)
    {
        systemButtonSize = allowedWidthForSystemButtons;
    }



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonNormalImage,       systemButtonSize, systemButtonSize, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonHoverImage,        systemButtonSize, systemButtonSize, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonPressedImage,      systemButtonSize, systemButtonSize, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedImage,      systemButtonSize, systemButtonSize, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedHoverImage, systemButtonSize, systemButtonSize, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



    sRebootButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, rebootImage, nullptr, "", rootWidget);

    UEFI_ASSERT_EXECUTION(sRebootButton->setPosition(screenWidth - systemButtonSize, screenHeight - systemButtonSize * 2), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setSize(systemButtonSize, systemButtonSize),                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setKeyboardEventHandler(onRebootButtonKeyboardEvent),                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sRebootButton->setPressEventHandler(onRebootButtonPressed),                                      NgosStatus::ASSERTION);



    sShutdownButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, shutdownImage, nullptr, "", rootWidget);

    UEFI_ASSERT_EXECUTION(sShutdownButton->setPosition(screenWidth - systemButtonSize, screenHeight - systemButtonSize), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setSize(systemButtonSize, systemButtonSize),                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setKeyboardEventHandler(onShutdownButtonKeyboardEvent),                       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sShutdownButton->setPressEventHandler(onShutdownButtonPressed),                                NgosStatus::ASSERTION);



    u64 tabWidgetHeight = screenHeight * TABWIDGET_HEIGHT_PERCENT  / 100;
    u64 tabButtonHeight = screenWidth  * TAB_BUTTON_HEIGHT_PERCENT / 100;

    u64 tabPageHeight = tabWidgetHeight - tabButtonHeight;



    u64 tabPageWidth = tabPageHeight * TAB_PAGE_PROPORTION;

    if (tabPageWidth > screenWidth)
    {
        tabPageWidth = screenWidth;

        tabPageHeight   = tabPageWidth / TAB_PAGE_PROPORTION;
        tabWidgetHeight = tabButtonHeight + tabPageHeight;
    }



    u64 tabWidgetWidth = tabPageWidth;
    u64 tabButtonWidth = tabWidgetWidth * TAB_BUTTON_WIDTH_PERCENT / 100;

    NinePatch *patch = tabWidgetPanelImage->getNinePatch();

    if (patch)
    {
        tabPageWidth  -= patch->getPaddingLeft() + patch->getPaddingRight();
        tabPageHeight -= patch->getPaddingTop()  + patch->getPaddingBottom();
    }



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



    char8 *totalMemoryCapacity            = mprintf("Total memory capacity: %s",                   bytesToString(DMI::getTotalAmountOfMemory()));
    char8 *maximumMemoryCapacity          = mprintf("Maximum memory capacity: %s",                 bytesToString(DMI::getSystemPhysicalMemoryArrayCapacity()));
    char8 *numberOfInstalledMemoryDevices = mprintf("Number of installed memory devices: %u / %u", DMI::getNumberOfInstalledMemoryDevices(), DMI::getMemoryDevices().getSize());



    u64 summaryMemoryInfoWidth  = tabPageWidth  * SUMMARY_MEMORY_INFO_WIDTH_PERCENT  / 100;
    u64 summaryMemoryInfoHeight = tabPageHeight * SUMMARY_MEMORY_INFO_HEIGHT_PERCENT / 100;



    PanelWidget *summaryMemoryInfoPanelWidget = new PanelWidget(infoPanelImage, systemInformationTabPageWidget);

    UEFI_ASSERT_EXECUTION(summaryMemoryInfoPanelWidget->setPosition(tabPageWidth * SUMMARY_MEMORY_INFO_POSITION_X_PERCENT / 100, tabPageHeight * SUMMARY_MEMORY_INFO_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(summaryMemoryInfoPanelWidget->setSize(summaryMemoryInfoWidth, summaryMemoryInfoHeight),                                                                               NgosStatus::ASSERTION);



    LabelWidget *totalMemoryCapacityLabelWidget = new LabelWidget(totalMemoryCapacity, summaryMemoryInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(totalMemoryCapacityLabelWidget->setPosition(summaryMemoryInfoWidth * TOTAL_MEMORY_CAPACITY_POSITION_X_PERCENT / 100, summaryMemoryInfoHeight * TOTAL_MEMORY_CAPACITY_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(totalMemoryCapacityLabelWidget->setSize(summaryMemoryInfoWidth     * TOTAL_MEMORY_CAPACITY_WIDTH_PERCENT      / 100, summaryMemoryInfoHeight * TOTAL_MEMORY_CAPACITY_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *maximumMemoryCapacityLabelWidget = new LabelWidget(maximumMemoryCapacity, summaryMemoryInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(maximumMemoryCapacityLabelWidget->setPosition(summaryMemoryInfoWidth * MAXIMUM_MEMORY_CAPACITY_POSITION_X_PERCENT / 100, summaryMemoryInfoHeight * MAXIMUM_MEMORY_CAPACITY_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(maximumMemoryCapacityLabelWidget->setSize(summaryMemoryInfoWidth     * MAXIMUM_MEMORY_CAPACITY_WIDTH_PERCENT      / 100, summaryMemoryInfoHeight * MAXIMUM_MEMORY_CAPACITY_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *numberOfInstalledMemoryDevicesLabelWidget = new LabelWidget(numberOfInstalledMemoryDevices, summaryMemoryInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(numberOfInstalledMemoryDevicesLabelWidget->setPosition(summaryMemoryInfoWidth * NUMBER_OF_MEMORY_DEVICES_POSITION_X_PERCENT / 100, summaryMemoryInfoHeight * NUMBER_OF_MEMORY_DEVICES_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(numberOfInstalledMemoryDevicesLabelWidget->setSize(summaryMemoryInfoWidth     * NUMBER_OF_MEMORY_DEVICES_WIDTH_PERCENT      / 100, summaryMemoryInfoHeight * NUMBER_OF_MEMORY_DEVICES_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    const ArrayList<DmiMemoryDevice> &memoryDevices = DMI::getMemoryDevices();



    u64 memoryInfoRegionPositionX;
    u64 memoryInfoRegionPositionY;
    u64 memoryInfoRegionWidth;
    u64 memoryInfoRegionHeight;

    if (memoryDevices.getSize() > 4)
    {
        memoryInfoRegionPositionX = tabPageWidth  * MEMORY_INFO_REGION_OVERRIDE_POSITION_X_PERCENT / 100;
        memoryInfoRegionPositionY = tabPageHeight * MEMORY_INFO_REGION_OVERRIDE_POSITION_Y_PERCENT / 100;
        memoryInfoRegionWidth     = tabPageWidth  * MEMORY_INFO_REGION_OVERRIDE_WIDTH_PERCENT      / 100;
        memoryInfoRegionHeight    = tabPageHeight * MEMORY_INFO_REGION_OVERRIDE_HEIGHT_PERCENT     / 100;
    }
    else
    {
        memoryInfoRegionPositionX = tabPageWidth  * MEMORY_INFO_REGION_POSITION_X_PERCENT / 100;
        memoryInfoRegionPositionY = tabPageHeight * MEMORY_INFO_REGION_POSITION_Y_PERCENT / 100;
        memoryInfoRegionWidth     = tabPageWidth  * MEMORY_INFO_REGION_WIDTH_PERCENT      / 100;
        memoryInfoRegionHeight    = tabPageHeight * MEMORY_INFO_REGION_HEIGHT_PERCENT     / 100;
    }



    u64 memoryInfoPanelHeight = memoryInfoRegionHeight / 2;
    u64 memoryInfoImageSize   = memoryInfoPanelHeight * MEMORY_INFO_IMAGE_SIZE_PERCENT / 100;



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryDeviceImage, memoryInfoImageSize, memoryInfoImageSize, &memoryDeviceResizedImage), NgosStatus::ASSERTION);

    if (memoryDevices.getSize() > DMI::getNumberOfInstalledMemoryDevices())
    {
        UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/memory_device_disabled.png", &memoryDeviceDisabledImage), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryDeviceDisabledImage, memoryInfoImageSize, memoryInfoImageSize, &memoryDeviceDisabledResizedImage), NgosStatus::ASSERTION);
    }
    else
    {
        memoryDeviceDisabledImage        = memoryDeviceImage;
        memoryDeviceDisabledResizedImage = memoryDeviceResizedImage;
    }



    if (memoryDevices.getSize() > 2)
    {
        u64 memoryInfoPanelWidth = memoryInfoRegionWidth / 2;

        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryInfoPanelImage, memoryInfoPanelWidth, memoryInfoPanelHeight, &memoryInfoPanelResizedImage), NgosStatus::ASSERTION);



        for (i64 i = 0; i < (i64)memoryDevices.getSize(); ++i)
        {
            UEFI_ASSERT_EXECUTION(addMemoryInfoPanel(i / 4, memoryInfoRegionPositionX + (i % 2) * memoryInfoPanelWidth, memoryInfoRegionPositionY + ((i >> 1) % 2) * memoryInfoPanelHeight, memoryInfoPanelWidth, memoryInfoPanelHeight, memoryInfoPanelImage, memoryInfoPanelResizedImage, memoryDeviceImage, memoryDeviceResizedImage, memoryDeviceDisabledImage, memoryDeviceDisabledResizedImage, systemInformationTabPageWidget, memoryDevices.at(i)), NgosStatus::ASSERTION);
        }



        if (sInfoPages.getSize() > 1)
        {
            if (arrowLeftImage == nullptr)
            {
                UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/arrow_left.png",  &arrowLeftImage),  NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/arrow_right.png", &arrowRightImage), NgosStatus::ASSERTION);
            }



            u64 arrowButtonSize = tabPageWidth * MEMORY_INFO_ARROW_BUTTON_SIZE_PERCENT / 100;



            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonNormalImage,       arrowButtonSize, arrowButtonSize, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonHoverImage,        arrowButtonSize, arrowButtonSize, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonPressedImage,      arrowButtonSize, arrowButtonSize, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedImage,      arrowButtonSize, arrowButtonSize, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedHoverImage, arrowButtonSize, arrowButtonSize, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



            sInfoLeftButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, arrowLeftImage, nullptr, "", systemInformationTabPageWidget);

            UEFI_ASSERT_EXECUTION(sInfoLeftButton->setVisible(false),                                                                                                                                        NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sInfoLeftButton->setPosition(tabPageWidth * MEMORY_INFO_LEFT_BUTTON_POSITION_X_PERCENT / 100, memoryInfoRegionPositionY + (memoryInfoRegionHeight - arrowButtonSize) / 2), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sInfoLeftButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                                NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sInfoLeftButton->setKeyboardEventHandler(onInfoLeftButtonKeyboardEvent),                                                                                                   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sInfoLeftButton->setPressEventHandler(onInfoLeftButtonPressed),                                                                                                            NgosStatus::ASSERTION);



            sInfoRightButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, arrowRightImage, nullptr, "", systemInformationTabPageWidget);

            UEFI_ASSERT_EXECUTION(sInfoRightButton->setPosition(tabPageWidth * MEMORY_INFO_RIGHT_BUTTON_POSITION_X_PERCENT / 100, memoryInfoRegionPositionY + (memoryInfoRegionHeight - arrowButtonSize) / 2), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sInfoRightButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                                 NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sInfoRightButton->setKeyboardEventHandler(onInfoRightButtonKeyboardEvent),                                                                                                   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sInfoRightButton->setPressEventHandler(onInfoRightButtonPressed),                                                                                                            NgosStatus::ASSERTION);
        }
    }
    else
    {
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryInfoPanelImage, memoryInfoRegionWidth, memoryInfoPanelHeight, &memoryInfoPanelResizedImage), NgosStatus::ASSERTION);



        for (i64 i = 0; i < (i64)memoryDevices.getSize(); ++i)
        {
            UEFI_ASSERT_EXECUTION(addMemoryInfoPanel(0, memoryInfoRegionPositionX, memoryInfoRegionPositionY + i * memoryInfoPanelHeight, memoryInfoRegionWidth, memoryInfoPanelHeight, memoryInfoPanelImage, memoryInfoPanelResizedImage, memoryDeviceImage, memoryDeviceResizedImage, memoryDeviceDisabledImage, memoryDeviceDisabledResizedImage, systemInformationTabPageWidget, memoryDevices.at(i)), NgosStatus::ASSERTION);
        }
    }



    TabPageWidget *issuesTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(issuesTabPageWidget), NgosStatus::ASSERTION);



    u64 issuesTableWidth  = tabPageWidth  * ISSUES_TABLEWIDGET_WIDTH_PERCENT  / 100;
    u64 issuesTableHeight = tabPageHeight * ISSUES_TABLEWIDGET_HEIGHT_PERCENT / 100;



    sIssuesTableWidget = new TableWidget(tableBackgroundImage, tableHeaderImage, issuesTabPageWidget);

    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setPosition(tabPageWidth * ISSUES_TABLEWIDGET_POSITION_X_PERCENT / 100, tabPageHeight * ISSUES_TABLEWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setSize(issuesTableWidth, issuesTableHeight),                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setKeyboardEventHandler(onIssuesTableWidgetKeyboardEvent),                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setRowHeight(ISSUES_TABLEWIDGET_ROW_HEIGHT),                                                                                          NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setColumnCount(2), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setColumnWidth(COLUMN_ICON,        ISSUES_COLUMN_ICON_WIDTH),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setColumnWidth(COLUMN_DESCRIPTION, issuesTableWidth - ISSUES_COLUMN_ICON_WIDTH), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setHeaderText(COLUMN_ICON,        ""),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setHeaderText(COLUMN_DESCRIPTION, "Description"), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(fillIssuesTable(), NgosStatus::ASSERTION);



    TabPageWidget *testTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(testTabPageWidget), NgosStatus::ASSERTION);



    TabPageWidget *summaryTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(summaryTabPageWidget), NgosStatus::ASSERTION);



    u64 summaryTableWidth  = tabPageWidth  * SUMMARY_TABLEWIDGET_WIDTH_PERCENT  / 100;
    u64 summaryTableHeight = tabPageHeight * SUMMARY_TABLEWIDGET_HEIGHT_PERCENT / 100;



    sSummaryTableWidget = new TableWidget(tableBackgroundImage, tableHeaderImage, summaryTabPageWidget);

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setPosition(tabPageWidth * SUMMARY_TABLEWIDGET_POSITION_X_PERCENT / 100, tabPageHeight * SUMMARY_TABLEWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setSize(summaryTableWidth, summaryTableHeight),                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setKeyboardEventHandler(onSummaryTableWidgetKeyboardEvent),                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setRowHeight(SUMMARY_TABLEWIDGET_ROW_HEIGHT),                                                                                           NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setColumnCount(2), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setColumnWidth(COLUMN_NAME,  summaryTableWidth * SUMMARY_COLUMN_NAME_WIDTH_PERCENT  / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setColumnWidth(COLUMN_SCORE, summaryTableWidth * SUMMARY_COLUMN_SCORE_WIDTH_PERCENT / 100), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setHeaderText(COLUMN_NAME,  "Name"),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setHeaderText(COLUMN_SCORE, "Score"), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(fillSummaryTable(), NgosStatus::ASSERTION);



    char8 *summaryTotalText = (char8 *)malloc(14);

    i64 summaryTotalTextLength = sprintf(summaryTotalText, "Total: %u", sSummaryTotal);
    AVOID_UNUSED(summaryTotalTextLength);

    UEFI_TEST_ASSERT(summaryTotalTextLength < 14, NgosStatus::ASSERTION);



    sSummaryTotalLabelWidget = new LabelWidget(summaryTotalText, summaryTabPageWidget);

    UEFI_ASSERT_EXECUTION(sSummaryTotalLabelWidget->setPosition(tabPageWidth * SUMMARY_TOTAL_TEXT_POSITION_X_PERCENT / 100, tabPageHeight * SUMMARY_TOTAL_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTotalLabelWidget->setSize(tabPageWidth     * SUMMARY_TOTAL_TEXT_WIDTH_PERCENT      / 100, tabPageHeight * SUMMARY_TOTAL_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sTabWidget->setPosition((screenWidth - tabWidgetWidth) / 2, 0), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->setSize(tabWidgetWidth, tabWidgetHeight),           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SYSTEM_INFORMATION),  NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sSystemInformationTabButton), NgosStatus::ASSERTION);



    CursorWidget *cursorWidget = new CursorWidget(cursorImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cursorWidget->setPosition(screenWidth / 2, screenHeight / 2), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cursorWidget->setSize(CURSOR_SIZE, CURSOR_SIZE),              NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(),                              NgosStatus::ASSERTION);

    UEFI_TEST_ASSERT(GUI::isUpdatesEnabled(), NgosStatus::ASSERTION);



    Guid mpServicesProtocol = UEFI_MP_SERVICES_PROTOCOL_GUID;

    if (UEFI::locateProtocol(&mpServicesProtocol, nullptr, (void **)&sMpServices) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Found UEFI_MP_SERVICES_PROTOCOL at 0x%p", sMpServices));
    }
    else
    {
        UEFI_LW(("UEFI_MP_SERVICES_PROTOCOL not found")); // TODO: Try to do in single thread
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::exec()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(generateWaitEventList(), NgosStatus::ASSERTION);

    do
    {
        UEFI_ASSERT_EXECUTION(waitForEvent(), NgosStatus::ASSERTION);
    } while(true);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::addMemoryInfoPanel(u64 pageIndex, u64 posX, u64 posY, u64 width, u64 height, Image *memoryInfoPanelImage, Image *memoryInfoPanelResizedImage, Image *memoryDeviceImage, Image *memoryDeviceResizedImage, Image *memoryDeviceDisabledImage, Image *memoryDeviceDisabledResizedImage, TabPageWidget *tabPageWidget, const DmiMemoryDevice &memoryDevice)
{
    UEFI_LT((" | pageIndex = %u, posX = %u, posY = %u, width = %u, height = %u, memoryInfoPanelImage = 0x%p, memoryInfoPanelResizedImage = 0x%p, memoryDeviceImage = 0x%p, memoryDeviceResizedImage = 0x%p, memoryDeviceDisabledImage = 0x%p, memoryDeviceDisabledResizedImage = 0x%p, tabPageWidget = 0x%p, memoryDevice = ...", pageIndex, posX, posY, width, height, memoryInfoPanelImage, memoryInfoPanelResizedImage, memoryDeviceImage, memoryDeviceResizedImage, memoryDeviceDisabledImage, memoryDeviceDisabledResizedImage, tabPageWidget));

    UEFI_ASSERT(width > 0,                        "width is zero",                            NgosStatus::ASSERTION);
    UEFI_ASSERT(height > 0,                       "height is zero",                           NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryInfoPanelImage,             "memoryInfoPanelImage is null",             NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryInfoPanelResizedImage,      "memoryInfoPanelResizedImage is null",      NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryDeviceImage,                "memoryDeviceImage is null",                NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryDeviceResizedImage,         "memoryDeviceResizedImage is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryDeviceDisabledImage,        "memoryDeviceDisabledImage is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryDeviceDisabledResizedImage, "memoryDeviceDisabledResizedImage is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(tabPageWidget,                    "tabPageWidget is null",                    NgosStatus::ASSERTION);



    u64 memoryImageSize = height * MEMORY_INFO_IMAGE_SIZE_PERCENT / 100;
    u64 allowedWidth    = width - memoryImageSize;



    PanelWidget *memoryInfoPanelWidget = new PanelWidget(memoryInfoPanelImage, memoryInfoPanelResizedImage, tabPageWidget);

    if (pageIndex > 0)
    {
        UEFI_ASSERT_EXECUTION(memoryInfoPanelWidget->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(memoryInfoPanelWidget->setPosition(posX, posY), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(memoryInfoPanelWidget->setSize(width, height),  NgosStatus::ASSERTION);



    if (memoryDevice.size == 0)
    {
        RgbaPixel disabledColor(DISABLED_COLOR);


        ImageWidget *memoryImageWidget = new ImageWidget(memoryDeviceDisabledImage, memoryDeviceDisabledResizedImage, memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryImageWidget->setPosition(width * MEMORY_INFO_IMAGE_POSITION_X_PERCENT / 100, height * MEMORY_INFO_IMAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryImageWidget->setSize(memoryImageSize, memoryImageSize),                                                                            NgosStatus::ASSERTION);



        LabelWidget *memoryDeviceLocatorLabelWidget = new LabelWidget(memoryDevice.deviceLocator != nullptr ? memoryDevice.deviceLocator : "---", memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setColor(disabledColor),                                                                                                                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_DEVICE_LOCATOR_POSITION_X_PERCENT / 100, height * MEMORY_INFO_DEVICE_LOCATOR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_DEVICE_LOCATOR_WIDTH_PERCENT      / 100, height * MEMORY_INFO_DEVICE_LOCATOR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



        LabelWidget *memoryNotInstalledLabelWidget = new LabelWidget("Not installed", memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryNotInstalledLabelWidget->setColor(disabledColor),                                                                                                                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryNotInstalledLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_NOT_INSTALLED_POSITION_X_PERCENT / 100, height * MEMORY_INFO_NOT_INSTALLED_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryNotInstalledLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_NOT_INSTALLED_WIDTH_PERCENT      / 100, height * MEMORY_INFO_NOT_INSTALLED_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    }
    else
    {
        RgbaPixel blackColor(BLACK_COLOR);



        const char8 *memorySize;
        const char8 *memorySpeed;

        // Get strings
        {
            // Get string for Size
            {
                if (memoryDevice.size == MEMORY_DEVICE_SIZE_UNKNOWN)
                {
                    memorySize = "Size: Unknown";
                }
                else
                {
                    memorySize = mprintf("Size: %s", bytesToString(memoryDevice.size));
                }
            }



            // Get string for Speed
            {
                if (memoryDevice.speed == 0)
                {
                    memorySpeed = "Speed: Unknown";
                }
                else
                {
                    memorySpeed = mprintf("Speed: %u MHz", memoryDevice.speed);
                }
            }
        }



        ImageWidget *memoryImageWidget = new ImageWidget(memoryDeviceImage, memoryDeviceResizedImage, memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryImageWidget->setPosition(width * MEMORY_INFO_IMAGE_POSITION_X_PERCENT / 100, height * MEMORY_INFO_IMAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryImageWidget->setSize(memoryImageSize, memoryImageSize),                                                                            NgosStatus::ASSERTION);



        LabelWidget *memoryDeviceLocatorLabelWidget = new LabelWidget(memoryDevice.deviceLocator != nullptr ? memoryDevice.deviceLocator : "---", memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setColor(blackColor),                                                                                                                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_DEVICE_LOCATOR_POSITION_X_PERCENT / 100, height * MEMORY_INFO_DEVICE_LOCATOR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_DEVICE_LOCATOR_WIDTH_PERCENT      / 100, height * MEMORY_INFO_DEVICE_LOCATOR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



        LabelWidget *memoryManufacturerLabelWidget = new LabelWidget(memoryDevice.manufacturer != nullptr ? memoryDevice.manufacturer : "---", memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setColor(blackColor),                                                                                                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_MANUFACTURER_POSITION_X_PERCENT / 100, height * MEMORY_INFO_MANUFACTURER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_MANUFACTURER_WIDTH_PERCENT      / 100, height * MEMORY_INFO_MANUFACTURER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



        LabelWidget *memorySerialNumberLabelWidget = new LabelWidget(memoryDevice.serialNumber != nullptr ? memoryDevice.serialNumber : "---", memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setColor(blackColor),                                                                                                                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_SERIAL_NUMBER_POSITION_X_PERCENT / 100, height * MEMORY_INFO_SERIAL_NUMBER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_SERIAL_NUMBER_WIDTH_PERCENT      / 100, height * MEMORY_INFO_SERIAL_NUMBER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



        LabelWidget *memoryPartNumberLabelWidget = new LabelWidget(memoryDevice.partNumber != nullptr ? memoryDevice.partNumber : "---", memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setColor(blackColor),                                                                                                                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_PART_NUMBER_POSITION_X_PERCENT / 100, height * MEMORY_INFO_PART_NUMBER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_PART_NUMBER_WIDTH_PERCENT      / 100, height * MEMORY_INFO_PART_NUMBER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



        LabelWidget *memorySizeLabelWidget = new LabelWidget(memorySize, memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setColor(blackColor),                                                                                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_SIZE_POSITION_X_PERCENT / 100, height * MEMORY_INFO_SIZE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_SIZE_WIDTH_PERCENT      / 100, height * MEMORY_INFO_SIZE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



        LabelWidget *memorySpeedLabelWidget = new LabelWidget(memorySpeed, memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memorySpeedLabelWidget->setColor(blackColor),                                                                                                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySpeedLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySpeedLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_SPEED_POSITION_X_PERCENT / 100, height * MEMORY_INFO_SPEED_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySpeedLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_SPEED_WIDTH_PERCENT      / 100, height * MEMORY_INFO_SPEED_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



        LabelWidget *memoryTypeLabelWidget = new LabelWidget(mprintf("Type: %s", enumToHumanString(memoryDevice.memoryType)), memoryInfoPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryTypeLabelWidget->setColor(blackColor),                                                                                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTypeLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTypeLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_TYPE_POSITION_X_PERCENT / 100, height * MEMORY_INFO_TYPE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTypeLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_TYPE_WIDTH_PERCENT      / 100, height * MEMORY_INFO_TYPE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    }



    // Add memoryInfoPanelWidget to last page
    {
        ArrayList<PanelWidget *> *page;

        if (pageIndex >= sInfoPages.getSize())
        {
            UEFI_TEST_ASSERT(pageIndex == sInfoPages.getSize(), NgosStatus::ASSERTION);



            page = new ArrayList<PanelWidget *>();

            UEFI_ASSERT_EXECUTION(sInfoPages.append(page), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(pageIndex == sInfoPages.getSize() - 1, NgosStatus::ASSERTION);



            page = sInfoPages.last();
        }



        UEFI_ASSERT_EXECUTION(page->append(memoryInfoPanelWidget), NgosStatus::ASSERTION);

        UEFI_TEST_ASSERT(page->getSize() <= 4, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::addIssueEntry(Image *icon, const char8 *description)
{
    UEFI_LT((" | icon = 0x%p, description = 0x%p", icon, description));

    UEFI_ASSERT(description, "description is null", NgosStatus::ASSERTION);



    u64 row = sIssuesTableWidget->getRowCount();

    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setRowCount(row + 1), NgosStatus::ASSERTION);



    if (icon)
    {
        ImageWidget *iconImageWidget = new ImageWidget(icon, sIssuesTableWidget);

        UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setCellWidget(row, COLUMN_ICON, iconImageWidget), NgosStatus::ASSERTION);
    }

    LabelWidget *descriptionLabelWidget = new LabelWidget(description, sIssuesTableWidget);

    UEFI_ASSERT_EXECUTION(descriptionLabelWidget->setColor(RgbaPixel(BLACK_COLOR)),                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sIssuesTableWidget->setCellWidget(row, COLUMN_DESCRIPTION, descriptionLabelWidget), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::fillIssuesTable()
{
    UEFI_LT((""));



    if (DMI::getTotalAmountOfMemory() < 16 * GB)
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "Memory capacity is less than 16 GB"), NgosStatus::ASSERTION);
    }

    if (DMI::getTotalAmountOfMemory() < GB)
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "Memory capacity is too small"), NgosStatus::ASSERTION);
    }

    if (DMI::getTotalAmountOfMemory() > DMI::getSystemPhysicalMemoryArrayCapacity())
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "Memory capacity is exceed maximum memory capacity"), NgosStatus::ASSERTION);
    }



    u32  minimumSpeed   = 0xFFFFFFFF;
    bool differentSpeed = false;



    const ArrayList<DmiMemoryDevice> &memoryDevices = DMI::getMemoryDevices();

    for (i64 i = 0; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
    {
        const DmiMemoryDevice &memoryDevice = memoryDevices.at(i);



        if (memoryDevice.memoryType != DmiMemoryDeviceType::DDR4)
        {
            UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "Memory device type is not DDR4"), NgosStatus::ASSERTION);
        }



        if (memoryDevice.speed > 0)
        {
            if (memoryDevice.speed < minimumSpeed)
            {
                if (minimumSpeed != 0xFFFFFFFF)
                {
                    differentSpeed = true;
                }

                minimumSpeed = memoryDevice.speed;
            }
            else
            if (memoryDevice.speed != minimumSpeed)
            {
                differentSpeed = true;
            }
        }
        else
        {
            UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "Memory device speed is unknown"), NgosStatus::ASSERTION);
        }



        if (memoryDevice.size == MEMORY_DEVICE_SIZE_UNKNOWN)
        {
            UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "Size of memory device is unknown"), NgosStatus::ASSERTION);
        }



        if (
            memoryDevice.manufacturer == nullptr
            &&
            memoryDevice.partNumber == nullptr
           )
        {
            UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "Memory device without vendor information"), NgosStatus::ASSERTION);
        }
    }



    if (minimumSpeed < 2666)
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "Memory device speed is less than 2666 MHz"), NgosStatus::ASSERTION);
    }

    if (differentSpeed)
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "Memory devices has different speed"), NgosStatus::ASSERTION);
    }



    if (DMI::getNumberOfInstalledMemoryDevices() > 1)
    {
        bool identical = true;



        const DmiMemoryDevice &firstMemoryDevice = memoryDevices.first();

        for (i64 i = 1; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
        {
            const DmiMemoryDevice &memoryDevice = memoryDevices.at(i);

            if (
                memoryDevice.memoryType != firstMemoryDevice.memoryType
                &&
                memoryDevice.speed != firstMemoryDevice.speed
                &&
                memoryDevice.size != firstMemoryDevice.size
               )
            {
                identical = false;

                break;
            }
        }



        if (identical)
        {
            if (DMI::getNumberOfInstalledMemoryDevices() % 2 == 1)
            {
                UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "It's better to install one more memory card"), NgosStatus::ASSERTION);
            }
        }
        else
        {
            UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "Memory cards should be identical"), NgosStatus::ASSERTION);
        }
    }
    else
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "It's better to have 2 or more identical memory cards"), NgosStatus::ASSERTION);
    }



    if (sIssuesTableWidget->getRowCount() == 0)
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(nullptr, "Everything is OK"), NgosStatus::ASSERTION);
    }
    else
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(nullptr, ""),                                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(addIssueEntry(nullptr, "We recommend to install 2 identical DDR4-2666 MHz memory cards"), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(addIssueEntry(nullptr, "with total size 16GB or more"),                                   NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::addSummaryEntry(const char8 *name, u64 score)
{
    UEFI_LT((" | name = 0x%p, score = %u", name, score));

    UEFI_ASSERT(name, "name is null", NgosStatus::ASSERTION);



    RgbaPixel blackColor(BLACK_COLOR);



    u64 row = sSummaryTableWidget->getRowCount();

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setRowCount(row + 1), NgosStatus::ASSERTION);



    LabelWidget *nameLabelWidget = new LabelWidget(name, sSummaryTableWidget);

    UEFI_ASSERT_EXECUTION(nameLabelWidget->setColor(blackColor),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(nameLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setCellWidget(row, COLUMN_NAME, nameLabelWidget),        NgosStatus::ASSERTION);

    LabelWidget *scoreLabelWidget = new LabelWidget(mprintf("%u", score), sSummaryTableWidget);

    UEFI_ASSERT_EXECUTION(scoreLabelWidget->setColor(blackColor),                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setCellWidget(row, COLUMN_SCORE, scoreLabelWidget), NgosStatus::ASSERTION);



    sSummaryTotal += score;



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::fillSummaryTable()
{
    UEFI_LT((""));



    u32 minimumSpeed = 0xFFFFFFFF;



    const ArrayList<DmiMemoryDevice> &memoryDevices = DMI::getMemoryDevices();

    for (i64 i = 0; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
    {
        const DmiMemoryDevice &memoryDevice = memoryDevices.at(i);



        if (memoryDevice.speed > 0)
        {
            if (memoryDevice.speed < minimumSpeed)
            {
                minimumSpeed = memoryDevice.speed;
            }
        }
    }



    if (minimumSpeed == 0xFFFFFFFF)
    {
        minimumSpeed = 0;
    }



    char8 *totalMemoryCapacity = mprintf("Total memory capacity: %s", bytesToString(DMI::getTotalAmountOfMemory()));
    char8 *memorySpeed         = mprintf("Memory speed: %u MHz",      minimumSpeed);



    UEFI_ASSERT_EXECUTION(addSummaryEntry("Previous test results", 0),                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(totalMemoryCapacity,     DMI::getTotalAmountOfMemory() * SCORE_PER_1GB_RAM / GB), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(memorySpeed,             minimumSpeed * SCORE_PER_100_MHZ / 100),                 NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::focusTabFirstWidget()
{
    UEFI_LT((""));



    switch (sTabWidget->getCurrentPage())
    {
        case TABWIDGET_PAGE_SYSTEM_INFORMATION: return GUI::setFocusedWidget(sInfoLeftButton != nullptr ? (sInfoLeftButton->isVisible() ? (Widget *)sInfoLeftButton : (Widget *)sInfoRightButton) : (Widget *)sRebootButton);
        case TABWIDGET_PAGE_ISSUES:             return GUI::setFocusedWidget(sIssuesTableWidget);
        case TABWIDGET_PAGE_TEST:               return GUI::setFocusedWidget(sRebootButton);
        case TABWIDGET_PAGE_SUMMARY:            return GUI::setFocusedWidget(sSummaryTableWidget);

        default:
        {
            UEFI_LF(("Unknown tab page: %d, %s:%u", sTabWidget->getCurrentPage(), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::focusTabLastWidget()
{
    UEFI_LT((""));



    switch (sTabWidget->getCurrentPage())
    {
        case TABWIDGET_PAGE_SYSTEM_INFORMATION: return GUI::setFocusedWidget(sInfoLeftButton != nullptr ? (sInfoLeftButton->isVisible() ? (Widget *)sInfoLeftButton : (Widget *)sInfoRightButton) : (Widget *)sSystemInformationTabButton);
        case TABWIDGET_PAGE_ISSUES:             return GUI::setFocusedWidget(sIssuesTableWidget);
        case TABWIDGET_PAGE_TEST:               return GUI::setFocusedWidget(sTestTabButton);
        case TABWIDGET_PAGE_SUMMARY:            return GUI::setFocusedWidget(sSummaryTableWidget);

        default:
        {
            UEFI_LF(("Unknown tab page: %d, %s:%u", sTabWidget->getCurrentPage(), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::generateWaitEventList()
{
    UEFI_LT((""));



    sWaitEventsCount          = UefiPointerDevices::getSimplePointersCount() + UefiPointerDevices::getAbsolutePointersCount() + 1; // "+ 1" = keyboard event
    sFirstProcessorEventIndex = sWaitEventsCount;



    if (sMpServices)
    {
        u64 numberOfProcessors;
        u64 numberOfEnabledProcessors;

        UEFI_ASSERT_EXECUTION(sMpServices->getNumberOfProcessors(sMpServices, &numberOfProcessors, &numberOfEnabledProcessors), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



        // Validation
        {
            UEFI_LVVV(("numberOfProcessors        = %u", numberOfProcessors));
            UEFI_LVVV(("numberOfEnabledProcessors = %u", numberOfEnabledProcessors));

            // UEFI_TEST_ASSERT(numberOfProcessors        == 4, NgosStatus::ASSERTION); // Commented due to value variation
            // UEFI_TEST_ASSERT(numberOfEnabledProcessors == 4, NgosStatus::ASSERTION); // Commented due to value variation
        }



        sWaitEventsCount += numberOfProcessors;
    }



    u64 size = sWaitEventsCount * sizeof(uefi_event);



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



    for (i64 i = eventId; i < sWaitEventsCount; ++i)
    {
        UEFI_ASSERT_EXECUTION(UEFI::createEvent(UefiEventType::NONE, UefiTpl::NONE, 0, 0, &sWaitEvents[i]), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
        UEFI_LVV(("Created event(0x%p) for processor", sWaitEvents[i]));
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::waitForEvent()
{
    UEFI_LT((""));



    u64 eventIndex;

    UEFI_ASSERT_EXECUTION(UEFI::waitForEvent(sWaitEventsCount, sWaitEvents, &eventIndex), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("eventIndex = %u", eventIndex));



    if (eventIndex == 0)
    {
        return processKeyboardEvent();
    }



    if (eventIndex <= UefiPointerDevices::getSimplePointersCount())
    {
        return processSimplePointerEvent(UefiPointerDevices::getSimplePointer(eventIndex - 1));
    }



    if (eventIndex >= sFirstProcessorEventIndex)
    {
        return processApplicationProcessorEvent(eventIndex - sFirstProcessorEventIndex);
    }



    return processAbsolutePointerEvent(UefiPointerDevices::getAbsolutePointer(eventIndex - UefiPointerDevices::getSimplePointersCount() - 1));
}

NgosStatus MemoryTestGUI::terminateAndWaitForApplicationProcessors()
{
    UEFI_LT((""));



    if (sNumberOfRunningProcessors > 0)
    {
        if (!sTerminated)
        {
            sTerminated = true;
        }



        while (sNumberOfRunningProcessors > 0)
        {
            u64 eventIndex;

            UEFI_ASSERT_EXECUTION(UEFI::waitForEvent(sWaitEventsCount, sWaitEvents, &eventIndex), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

            UEFI_LVVV(("eventIndex = %u", eventIndex));



            if (eventIndex >= sFirstProcessorEventIndex)
            {
                UEFI_ASSERT_EXECUTION(processApplicationProcessorEvent(eventIndex - sFirstProcessorEventIndex), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::processKeyboardEvent()
{
    UEFI_LT((""));



    UefiInputKey key;

    UEFI_ASSERT_EXECUTION(UEFI::getSystemTable()->stdin->readKeyStroke(UEFI::getSystemTable()->stdin, &key), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

    UEFI_LVVV(("key.scanCode    = %s",     enumToFullString(key.scanCode)));
    UEFI_LVVV(("key.unicodeChar = 0x%04X", key.unicodeChar));



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

NgosStatus MemoryTestGUI::processSimplePointerEvent(UefiSimplePointerProtocol *pointer)
{
    UEFI_LT((" | pointer = 0x%p", pointer));

    UEFI_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);



    UefiSimplePointerState state;

    if (pointer->getState(pointer, &state) == UefiStatus::SUCCESS)
    {
        UEFI_LVVV(("state.relativeMovementX = %d", state.relativeMovementX));
        UEFI_LVVV(("state.relativeMovementY = %d", state.relativeMovementY));
        UEFI_LVVV(("state.relativeMovementZ = %d", state.relativeMovementZ));
        UEFI_LVVV(("state.leftButton        = %s", boolToString(state.leftButton)));
        UEFI_LVVV(("state.rightButton       = %s", boolToString(state.rightButton)));



        UEFI_ASSERT_EXECUTION(GUI::processSimplePointerState(&state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer)
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

NgosStatus MemoryTestGUI::processApplicationProcessorEvent(u64 processorId)
{
    UEFI_LT((" | processorId = %u", processorId));



    AVOID_UNUSED(processorId); // TODO: Need to remove



    UEFI_LV(("Application processor %u finished", processorId));



    if (!sTerminated)
    {
        --sNumberOfRunningProcessors;
    }
    else
    {
        --sNumberOfRunningProcessors;
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onRebootButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return focusTabLastWidget();
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sShutdownButton);

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

NgosStatus MemoryTestGUI::onShutdownButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP: return GUI::setFocusedWidget(sRebootButton);

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

NgosStatus MemoryTestGUI::onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus MemoryTestGUI::onIssuesTabButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus MemoryTestGUI::onTestTabButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus MemoryTestGUI::onSummaryTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sTestTabButton);
        case UefiInputKeyScanCode::DOWN: return focusTabFirstWidget();

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

NgosStatus MemoryTestGUI::onInfoLeftButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sSystemInformationTabButton);
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::LEFT: return onInfoLeftButtonPressed();

        case UefiInputKeyScanCode::RIGHT:
        {
            if (sInfoCurrentPage < sInfoPages.getSize() - 1)
            {
                if (sInfoCurrentPage < sInfoPages.getSize() - 2)
                {
                    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sInfoRightButton), NgosStatus::ASSERTION);
                }

                return onInfoRightButtonPressed();
            }

            return NgosStatus::NO_EFFECT;
        }
        break;

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sInfoRightButton->isVisible() ? sInfoRightButton : sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onInfoRightButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:    return GUI::setFocusedWidget(sSystemInformationTabButton);
        case UefiInputKeyScanCode::DOWN:  return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::RIGHT: return onInfoRightButtonPressed();

        case UefiInputKeyScanCode::LEFT:
        {
            if (sInfoCurrentPage > 0)
            {
                if (sInfoCurrentPage > 1)
                {
                    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sInfoLeftButton), NgosStatus::ASSERTION);
                }

                return onInfoLeftButtonPressed();
            }

            return NgosStatus::NO_EFFECT;
        }
        break;

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onIssuesTableWidgetKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return sIssuesTableWidget->getSelectedRow() == 0                                     ? GUI::setFocusedWidget(sIssuesTabButton) : NgosStatus::NO_EFFECT;
        case UefiInputKeyScanCode::DOWN: return sIssuesTableWidget->getSelectedRow() == sIssuesTableWidget->getRowCount() - 1 ? GUI::setFocusedWidget(sRebootButton)    : NgosStatus::NO_EFFECT;

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onSummaryTableWidgetKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return sSummaryTableWidget->getSelectedRow() == 0                                      ? GUI::setFocusedWidget(sSummaryTabButton) : NgosStatus::NO_EFFECT;
        case UefiInputKeyScanCode::DOWN: return sSummaryTableWidget->getSelectedRow() == sSummaryTableWidget->getRowCount() - 1 ? GUI::setFocusedWidget(sRebootButton)     : NgosStatus::NO_EFFECT;

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onRebootButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(terminateAndWaitForApplicationProcessors(),                                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::COLD, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onShutdownButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(terminateAndWaitForApplicationProcessors(),                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::SHUTDOWN, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onSystemInformationTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SYSTEM_INFORMATION), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onIssuesTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_ISSUES), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onTestTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_TEST), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onSummaryTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SUMMARY), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onInfoLeftButtonPressed()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sInfoCurrentPage > 0, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    ArrayList<PanelWidget *> *page = sInfoPages.at(sInfoCurrentPage);

    for (i64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }



    --sInfoCurrentPage;



    page = sInfoPages.at(sInfoCurrentPage);

    for (i64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sInfoRightButton->setVisible(true), NgosStatus::ASSERTION);

    if (sInfoCurrentPage <= 0)
    {
        UEFI_ASSERT_EXECUTION(sInfoLeftButton->setVisible(false),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sInfoRightButton), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onInfoRightButtonPressed()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sInfoCurrentPage < sInfoPages.getSize() - 1, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    ArrayList<PanelWidget *> *page = sInfoPages.at(sInfoCurrentPage);

    for (i64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }



    ++sInfoCurrentPage;



    page = sInfoPages.at(sInfoCurrentPage);

    for (i64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sInfoLeftButton->setVisible(true), NgosStatus::ASSERTION);

    if (sInfoCurrentPage >= sInfoPages.getSize() - 1)
    {
        UEFI_ASSERT_EXECUTION(sInfoRightButton->setVisible(false),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sInfoLeftButton), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
