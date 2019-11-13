#include "cputestgui.h"

#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/cpu/generated/x86featuresnames.h>
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

#include "src/bits64/main/cputest.h"



#define REBOOT_BUTTON_POSITION_X_PERCENT 90
#define REBOOT_BUTTON_POSITION_Y_PERCENT 0

#define SHUTDOWN_BUTTON_POSITION_X_PERCENT 95
#define SHUTDOWN_BUTTON_POSITION_Y_PERCENT 0

#define TABWIDGET_HEIGHT_PERCENT 70

#define TAB_BUTTON_WIDTH_PERCENT  25
#define TAB_BUTTON_HEIGHT_PERCENT 6

#define TAB_PAGE_PROPORTION 2

#define CPU_IMAGE_POSITION_X_PERCENT 0
#define CPU_IMAGE_POSITION_Y_PERCENT 0
#define CPU_IMAGE_SIZE_PERCENT       30

#define CPU_MODEL_NAME_POSITION_X_PERCENT 1
#define CPU_MODEL_NAME_POSITION_Y_PERCENT 2
#define CPU_MODEL_NAME_WIDTH_PERCENT      98
#define CPU_MODEL_NAME_HEIGHT_PERCENT     20

#define CPU_CORES_POSITION_X_PERCENT 16
#define CPU_CORES_POSITION_Y_PERCENT 30
#define CPU_CORES_WIDTH_PERCENT      30
#define CPU_CORES_HEIGHT_PERCENT     20

#define CPU_THREADS_POSITION_X_PERCENT 46
#define CPU_THREADS_POSITION_Y_PERCENT 30
#define CPU_THREADS_WIDTH_PERCENT      30
#define CPU_THREADS_HEIGHT_PERCENT     20

#define CPU_FAMILY_POSITION_X_PERCENT 1
#define CPU_FAMILY_POSITION_Y_PERCENT 57
#define CPU_FAMILY_WIDTH_PERCENT      49
#define CPU_FAMILY_HEIGHT_PERCENT     20

#define CPU_MODEL_POSITION_X_PERCENT 50
#define CPU_MODEL_POSITION_Y_PERCENT 57
#define CPU_MODEL_WIDTH_PERCENT      49
#define CPU_MODEL_HEIGHT_PERCENT     20

#define CPU_STEPPING_POSITION_X_PERCENT 1
#define CPU_STEPPING_POSITION_Y_PERCENT 77
#define CPU_STEPPING_WIDTH_PERCENT      49
#define CPU_STEPPING_HEIGHT_PERCENT     20

#define CPU_REVISION_POSITION_X_PERCENT 50
#define CPU_REVISION_POSITION_Y_PERCENT 77
#define CPU_REVISION_WIDTH_PERCENT      49
#define CPU_REVISION_HEIGHT_PERCENT     20

#define FEATURE_PANEL_POSITION_X_PERCENT 2.5
#define FEATURE_PANEL_WIDTH_PERCENT      19
#define FEATURE_PANEL_HEIGHT_PERCENT     7

#define FEATURE_TEXT_POSITION_X_PERCENT 5
#define FEATURE_TEXT_POSITION_Y_PERCENT 5
#define FEATURE_TEXT_WIDTH_PERCENT      90
#define FEATURE_TEXT_HEIGHT_PERCENT     90

#define CPU_CLOCKS_PANEL_POSITION_X_PERCENT 0
#define CPU_CLOCKS_PANEL_WIDTH_PERCENT      49

#define CPU_CLOCKS_TEXT_POSITION_X_PERCENT 1
#define CPU_CLOCKS_TEXT_POSITION_Y_PERCENT 2
#define CPU_CLOCKS_TEXT_WIDTH_PERCENT      98
#define CPU_CLOCKS_TEXT_HEIGHT_PERCENT     20

#define CPU_SPEED_TEXT_POSITION_X_PERCENT 3
#define CPU_SPEED_TEXT_POSITION_Y_PERCENT 23
#define CPU_SPEED_TEXT_WIDTH_PERCENT      94
#define CPU_SPEED_TEXT_HEIGHT_PERCENT     17

#define CPU_CACHE_PANEL_POSITION_X_PERCENT 51
#define CPU_CACHE_PANEL_WIDTH_PERCENT      49

#define CPU_CACHE_TEXT_POSITION_X_PERCENT 1
#define CPU_CACHE_TEXT_POSITION_Y_PERCENT 2
#define CPU_CACHE_TEXT_WIDTH_PERCENT      98
#define CPU_CACHE_TEXT_HEIGHT_PERCENT     20

#define CPU_CACHE_L1_DATA_TEXT_POSITION_X_PERCENT 3
#define CPU_CACHE_L1_DATA_TEXT_POSITION_Y_PERCENT 23
#define CPU_CACHE_L1_DATA_TEXT_WIDTH_PERCENT      94
#define CPU_CACHE_L1_DATA_TEXT_HEIGHT_PERCENT     17

#define CPU_CACHE_L1_INSTRUCTION_TEXT_POSITION_X_PERCENT 3
#define CPU_CACHE_L1_INSTRUCTION_TEXT_POSITION_Y_PERCENT 42
#define CPU_CACHE_L1_INSTRUCTION_TEXT_WIDTH_PERCENT      94
#define CPU_CACHE_L1_INSTRUCTION_TEXT_HEIGHT_PERCENT     17

#define CPU_CACHE_L2_TEXT_POSITION_X_PERCENT 3
#define CPU_CACHE_L2_TEXT_POSITION_Y_PERCENT 61
#define CPU_CACHE_L2_TEXT_WIDTH_PERCENT      94
#define CPU_CACHE_L2_TEXT_HEIGHT_PERCENT     17

#define CPU_CACHE_L3_TEXT_POSITION_X_PERCENT 3
#define CPU_CACHE_L3_TEXT_POSITION_Y_PERCENT 80
#define CPU_CACHE_L3_TEXT_WIDTH_PERCENT      94
#define CPU_CACHE_L3_TEXT_HEIGHT_PERCENT     17

#define START_BUTTON_POSITION_X_PERCENT 0
#define START_BUTTON_POSITION_Y_PERCENT 0
#define START_BUTTON_WIDTH_PERCENT      20
#define START_BUTTON_HEIGHT_PERCENT     10

#define TEST_TABLEWIDGET_POSITION_X_PERCENT 0
#define TEST_TABLEWIDGET_POSITION_Y_PERCENT 10
#define TEST_TABLEWIDGET_WIDTH_PERCENT      98
#define TEST_TABLEWIDGET_HEIGHT_PERCENT     89
#define TEST_TABLEWIDGET_ROW_HEIGHT_PERCENT 7

#define TEST_COLUMN_NAME_WIDTH_PERCENT  80
#define TEST_COLUMN_SCORE_WIDTH_PERCENT 20

#define SUMMARY_TABLEWIDGET_POSITION_X_PERCENT 1
#define SUMMARY_TABLEWIDGET_POSITION_Y_PERCENT 1
#define SUMMARY_TABLEWIDGET_WIDTH_PERCENT      98
#define SUMMARY_TABLEWIDGET_HEIGHT_PERCENT     98
#define SUMMARY_TABLEWIDGET_ROW_HEIGHT_PERCENT 7

#define SUMMARY_COLUMN_NAME_WIDTH_PERCENT  80
#define SUMMARY_COLUMN_SCORE_WIDTH_PERCENT 20

#define SYSTEM_BUTTON_SIZE_PERCENT 5
#define CURSOR_SIZE_PERCENT        2

#define TABWIDGET_PAGE_SYSTEM_INFORMATION 0
#define TABWIDGET_PAGE_TEST               1
#define TABWIDGET_PAGE_SUMMARY            2

#define COLUMN_NAME  0
#define COLUMN_SCORE 1

#define SCORE_PER_THREAD                          500
#define SCORE_PER_100_MHZ                         200
#define SCORE_L1_DATA_CACHE_PER_1_KB_1_WAY        2
#define SCORE_L1_INSTRUCTION_CACHE_PER_1_KB_1_WAY 2
#define SCORE_L2_CACHE_PER_1_MB_1_WAY             10
#define SCORE_L3_CACHE_PER_1_MB_1_WAY             12



Button                 *CpuTestGUI::sRebootButton;
Button                 *CpuTestGUI::sShutdownButton;
TabWidget              *CpuTestGUI::sTabWidget;
TabButton              *CpuTestGUI::sSystemInformationTabButton;
TabButton              *CpuTestGUI::sTestTabButton;
TabButton              *CpuTestGUI::sSummaryTabButton;
Button                 *CpuTestGUI::sStartButton;
Image                  *CpuTestGUI::sStartImage;
Image                  *CpuTestGUI::sStopImage;
TableWidget            *CpuTestGUI::sTestTableWidget;
TableWidget            *CpuTestGUI::sSummaryTableWidget;
u64                     CpuTestGUI::sSummaryTotal;
UefiMpServicesProtocol *CpuTestGUI::sMpServices;
u16                     CpuTestGUI::sWaitEventsCount;
uefi_event             *CpuTestGUI::sWaitEvents;

X86Feature testedFeatures[] =
{
    X86Feature::NX
    , X86Feature::LA57
    , X86Feature::MMX
    , X86Feature::XMM
    , X86Feature::XMM2
    , X86Feature::XMM3
    , X86Feature::SSSE3
    , X86Feature::XMM4_1
    , X86Feature::XMM4_2
    , X86Feature::AVX
    , X86Feature::AVX2
    , X86Feature::AVX512F
    , X86Feature::AVX512CD
    , X86Feature::AVX512ER
    , X86Feature::AVX512PF
    , X86Feature::AVX512BW
    , X86Feature::AVX512DQ
    , X86Feature::AVX512VL
    , X86Feature::AVX512IFMA
    , X86Feature::AVX512VBMI
    , X86Feature::FMA
    , X86Feature::AES
    , X86Feature::RTM
    , X86Feature::VMX
};

u64 testedFeaturesScores[] =
{
    100     // X86Feature::NX
    , 50    // X86Feature::LA57
    , 16    // X86Feature::MMX
    , 20    // X86Feature::XMM
    , 25    // X86Feature::XMM2
    , 50    // X86Feature::XMM3
    , 50    // X86Feature::SSSE3
    , 100   // X86Feature::XMM4_1
    , 125   // X86Feature::XMM4_2
    , 200   // X86Feature::AVX
    , 250   // X86Feature::AVX2
    , 500   // X86Feature::AVX512F
    , 500   // X86Feature::AVX512CD
    , 500   // X86Feature::AVX512ER
    , 500   // X86Feature::AVX512PF
    , 500   // X86Feature::AVX512BW
    , 500   // X86Feature::AVX512DQ
    , 500   // X86Feature::AVX512VL
    , 500   // X86Feature::AVX512IFMA
    , 500   // X86Feature::AVX512VBMI
    , 250   // X86Feature::FMA
    , 250   // X86Feature::AES
    , 500   // X86Feature::RTM
    , 100   // X86Feature::VMX
};



NgosStatus CpuTestGUI::init(BootParams *params)
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
    Image *testImage;
    Image *summaryImage;
    Image *cpuImage;
    Image *infoPanelImage;
    Image *featurePanelImage;
    Image *featurePanelResizedImage;
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
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/test.png",                        &testImage),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/summary.png",                     &summaryImage),                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/cpu.png",                         &cpuImage),                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/info_panel.9.png",                &infoPanelImage),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/feature_panel.9.png",             &featurePanelImage),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/table_background.9.png",          &tableBackgroundImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/table_header.9.png",              &tableHeaderImage),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/reboot.png",                      &rebootImage),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/shutdown.png",                    &shutdownImage),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/cursor.png",                      &cursorImage),                  NgosStatus::ASSERTION);
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



    u64 cpuImageSize = tabPageHeight * CPU_IMAGE_SIZE_PERCENT / 100;



    ImageWidget *cpuImageWidget = new ImageWidget(cpuImage, systemInformationTabPageWidget);

    UEFI_ASSERT_EXECUTION(cpuImageWidget->setPosition(tabPageWidth * CPU_IMAGE_POSITION_X_PERCENT / 100, tabPageHeight * CPU_IMAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuImageWidget->setSize(cpuImageSize, cpuImageSize),                                                                                NgosStatus::ASSERTION);



    char8 *cpuModelName = (char8 *)malloc(60);

    i64 cpuModelNameLength = sprintf(cpuModelName, "CPU Model: %.48s", CPU::getModelName());
    AVOID_UNUSED(cpuModelNameLength);

    UEFI_TEST_ASSERT(sizeof(CPU::sModelName) == 48, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(cpuModelNameLength < 60,       NgosStatus::ASSERTION);



    char8 *cpuCores = (char8 *)malloc(18);

    i64 cpuCoresLength = sprintf(cpuCores, "Cores: %-3u", CPU::getNumberOfCores());
    AVOID_UNUSED(cpuCoresLength);

    UEFI_TEST_ASSERT(cpuCoresLength < 18, NgosStatus::ASSERTION);



    char8 *cpuThreads = (char8 *)malloc(20);

    i64 cpuThreadsLength = sprintf(cpuThreads, "Threads: %-3u", CPU::getNumberOfThreads());
    AVOID_UNUSED(cpuThreadsLength);

    UEFI_TEST_ASSERT(cpuThreadsLength < 20, NgosStatus::ASSERTION);



    char8 *cpuFamily = (char8 *)malloc(21);

    UEFI_ASSERT_EXECUTION(sprintf(cpuFamily, "Family:   0x%02X      ", CPU::getFamily()), i64, 20, NgosStatus::ASSERTION);



    char8 *cpuModel = (char8 *)malloc(21);

    UEFI_ASSERT_EXECUTION(sprintf(cpuModel, "Model:    0x%02X      ", CPU::getModel()), i64, 20, NgosStatus::ASSERTION);



    char8 *cpuStepping = (char8 *)malloc(21);

    UEFI_ASSERT_EXECUTION(sprintf(cpuStepping, "Stepping: 0x%02X      ", CPU::getStepping()), i64, 20, NgosStatus::ASSERTION);



    char8 *cpuRevision = (char8 *)malloc(21);

    UEFI_ASSERT_EXECUTION(sprintf(cpuRevision, "Revision: 0x%08X", CPU::getMicrocodeRevision()), i64, 20, NgosStatus::ASSERTION);



    u64 cpuInfoWidth  = tabPageWidth - cpuImageSize;
    u64 cpuInfoHeight = cpuImageSize;

    PanelWidget *cpuInfoPanelWidget = new PanelWidget(infoPanelImage, systemInformationTabPageWidget);

    UEFI_ASSERT_EXECUTION(cpuInfoPanelWidget->setPosition(cpuImageSize, 0),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuInfoPanelWidget->setSize(cpuInfoWidth, cpuInfoHeight), NgosStatus::ASSERTION);



    LabelWidget *cpuModelNameLabelWidget = new LabelWidget(cpuModelName, cpuInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuModelNameLabelWidget->setPosition(cpuInfoWidth * CPU_MODEL_NAME_POSITION_X_PERCENT / 100, cpuInfoHeight * CPU_MODEL_NAME_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuModelNameLabelWidget->setSize(cpuInfoWidth     * CPU_MODEL_NAME_WIDTH_PERCENT      / 100, cpuInfoHeight * CPU_MODEL_NAME_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuCoresLabelWidget = new LabelWidget(cpuCores, cpuInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuCoresLabelWidget->setPosition(cpuInfoWidth * CPU_CORES_POSITION_X_PERCENT / 100, cpuInfoHeight * CPU_CORES_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuCoresLabelWidget->setSize(cpuInfoWidth     * CPU_CORES_WIDTH_PERCENT      / 100, cpuInfoHeight * CPU_CORES_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuThreadsLabelWidget = new LabelWidget(cpuThreads, cpuInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuThreadsLabelWidget->setPosition(cpuInfoWidth * CPU_THREADS_POSITION_X_PERCENT / 100, cpuInfoHeight * CPU_THREADS_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuThreadsLabelWidget->setSize(cpuInfoWidth     * CPU_THREADS_WIDTH_PERCENT      / 100, cpuInfoHeight * CPU_THREADS_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuFamilyLabelWidget = new LabelWidget(cpuFamily, cpuInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuFamilyLabelWidget->setPosition(cpuInfoWidth * CPU_FAMILY_POSITION_X_PERCENT / 100, cpuInfoHeight * CPU_FAMILY_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuFamilyLabelWidget->setSize(cpuInfoWidth     * CPU_FAMILY_WIDTH_PERCENT      / 100, cpuInfoHeight * CPU_FAMILY_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuModelLabelWidget = new LabelWidget(cpuModel, cpuInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuModelLabelWidget->setPosition(cpuInfoWidth * CPU_MODEL_POSITION_X_PERCENT / 100, cpuInfoHeight * CPU_MODEL_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuModelLabelWidget->setSize(cpuInfoWidth     * CPU_MODEL_WIDTH_PERCENT      / 100, cpuInfoHeight * CPU_MODEL_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuSteppingLabelWidget = new LabelWidget(cpuStepping, cpuInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuSteppingLabelWidget->setPosition(cpuInfoWidth * CPU_STEPPING_POSITION_X_PERCENT / 100, cpuInfoHeight * CPU_STEPPING_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuSteppingLabelWidget->setSize(cpuInfoWidth     * CPU_STEPPING_WIDTH_PERCENT      / 100, cpuInfoHeight * CPU_STEPPING_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuRevisionLabelWidget = new LabelWidget(cpuRevision, cpuInfoPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuRevisionLabelWidget->setPosition(cpuInfoWidth * CPU_REVISION_POSITION_X_PERCENT / 100, cpuInfoHeight * CPU_REVISION_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuRevisionLabelWidget->setSize(cpuInfoWidth     * CPU_REVISION_WIDTH_PERCENT      / 100, cpuInfoHeight * CPU_REVISION_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    u64 featurePanelLeft      = tabPageWidth  * FEATURE_PANEL_POSITION_X_PERCENT / 100;
    u64 featurePanelPositionY = cpuImageSize;
    u64 featurePanelWidth     = tabPageWidth  * FEATURE_PANEL_WIDTH_PERCENT      / 100;
    u64 featurePanelHeight    = tabPageHeight * FEATURE_PANEL_HEIGHT_PERCENT     / 100;

    u64 featurePanelPositionX = featurePanelLeft;

    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(featurePanelImage, featurePanelWidth, featurePanelHeight, &featurePanelResizedImage), NgosStatus::ASSERTION);



    i64 flagsCount = ARRAY_COUNT(testedFeatures);
    UEFI_LVVV(("flagsCount = %d", flagsCount));

    for (i64 i = 0; i < flagsCount; ++i)
    {
        if (featurePanelPositionX + featurePanelWidth > tabPageWidth)
        {
            featurePanelPositionX =  featurePanelLeft;
            featurePanelPositionY += featurePanelHeight;
        }

        UEFI_ASSERT_EXECUTION(addFeaturePanel(testedFeatures[i], featurePanelPositionX, featurePanelPositionY, featurePanelWidth, featurePanelHeight, featurePanelImage, featurePanelResizedImage, systemInformationTabPageWidget), NgosStatus::ASSERTION);

        featurePanelPositionX += featurePanelWidth;
    }



    u64 cpuPanelPositionY = featurePanelPositionY + featurePanelHeight;
    u64 cpuPanelHeight    = tabPageHeight - cpuPanelPositionY;



    u64 cpuClocksWidth  = tabPageWidth * CPU_CLOCKS_PANEL_WIDTH_PERCENT / 100;
    u64 cpuClocksHeight = cpuPanelHeight;

    PanelWidget *cpuClocksPanelWidget = new PanelWidget(infoPanelImage, systemInformationTabPageWidget);

    UEFI_ASSERT_EXECUTION(cpuClocksPanelWidget->setPosition(tabPageWidth * CPU_CLOCKS_PANEL_POSITION_X_PERCENT / 100, cpuPanelPositionY), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuClocksPanelWidget->setSize(cpuClocksWidth, cpuClocksHeight),                                                 NgosStatus::ASSERTION);



    char8 *cpuSpeed = (char8 *)malloc(24);

    UEFI_ASSERT_EXECUTION(sprintf(cpuSpeed, "CPU Speed    %-10s", hertzToString(CpuTest::getCpuSpeed())), i64, 23, NgosStatus::ASSERTION);



    LabelWidget *cpuClocksLabelWidget = new LabelWidget("Clocks", cpuClocksPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuClocksLabelWidget->setPosition(cpuClocksWidth * CPU_CLOCKS_TEXT_POSITION_X_PERCENT / 100, cpuClocksHeight * CPU_CLOCKS_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuClocksLabelWidget->setSize(cpuClocksWidth     * CPU_CLOCKS_TEXT_WIDTH_PERCENT      / 100, cpuClocksHeight * CPU_CLOCKS_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuSpeedLabelWidget = new LabelWidget(cpuSpeed, cpuClocksPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuSpeedLabelWidget->setPosition(cpuClocksWidth * CPU_SPEED_TEXT_POSITION_X_PERCENT / 100, cpuClocksHeight * CPU_SPEED_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuSpeedLabelWidget->setSize(cpuClocksWidth     * CPU_SPEED_TEXT_WIDTH_PERCENT      / 100, cpuClocksHeight * CPU_SPEED_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    u64 cpuCacheWidth  = tabPageWidth * CPU_CACHE_PANEL_WIDTH_PERCENT / 100;
    u64 cpuCacheHeight = cpuPanelHeight;

    PanelWidget *cpuCachePanelWidget = new PanelWidget(infoPanelImage, systemInformationTabPageWidget);

    UEFI_ASSERT_EXECUTION(cpuCachePanelWidget->setPosition(tabPageWidth * CPU_CACHE_PANEL_POSITION_X_PERCENT / 100, cpuPanelPositionY), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuCachePanelWidget->setSize(cpuCacheWidth, cpuCacheHeight),                                                  NgosStatus::ASSERTION);



    char8 *cpuL1DataCache = (char8 *)malloc(33);

    UEFI_ASSERT_EXECUTION(sprintf(cpuL1DataCache, "L1 Data  %3u x %-10s %2u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel1DataCache().size), CpuTest::getLevel1DataCache().numberOfWays), i64, 32, NgosStatus::ASSERTION);



    char8 *cpuL1InstructionCache = (char8 *)malloc(33);

    UEFI_ASSERT_EXECUTION(sprintf(cpuL1InstructionCache, "L1 Inst. %3u x %-10s %2u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel1InstructionCache().size), CpuTest::getLevel1InstructionCache().numberOfWays), i64, 32, NgosStatus::ASSERTION);



    char8 *cpuLevel2Cache = (char8 *)malloc(33);

    UEFI_ASSERT_EXECUTION(sprintf(cpuLevel2Cache, "Level 2  %3u x %-10s %2u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel2Cache().size), CpuTest::getLevel2Cache().numberOfWays), i64, 32, NgosStatus::ASSERTION);



    char8 *cpuLevel3Cache = (char8 *)malloc(33);

    UEFI_ASSERT_EXECUTION(sprintf(cpuLevel3Cache, "Level 3    %-10s     %2u-way", bytesToString(CpuTest::getLevel3Cache().size), CpuTest::getLevel3Cache().numberOfWays), i64, 32, NgosStatus::ASSERTION);



    LabelWidget *cpuCacheLabelWidget = new LabelWidget("Cache ", cpuCachePanelWidget);

    UEFI_ASSERT_EXECUTION(cpuCacheLabelWidget->setPosition(cpuCacheWidth * CPU_CACHE_TEXT_POSITION_X_PERCENT / 100, cpuCacheHeight * CPU_CACHE_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuCacheLabelWidget->setSize(cpuCacheWidth     * CPU_CACHE_TEXT_WIDTH_PERCENT      / 100, cpuCacheHeight * CPU_CACHE_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuL1DataCacheLabelWidget = new LabelWidget(cpuL1DataCache, cpuCachePanelWidget);

    UEFI_ASSERT_EXECUTION(cpuL1DataCacheLabelWidget->setPosition(cpuCacheWidth * CPU_CACHE_L1_DATA_TEXT_POSITION_X_PERCENT / 100, cpuCacheHeight * CPU_CACHE_L1_DATA_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuL1DataCacheLabelWidget->setSize(cpuCacheWidth     * CPU_CACHE_L1_DATA_TEXT_WIDTH_PERCENT      / 100, cpuCacheHeight * CPU_CACHE_L1_DATA_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuL1InstructionCacheLabelWidget = new LabelWidget(cpuL1InstructionCache, cpuCachePanelWidget);

    UEFI_ASSERT_EXECUTION(cpuL1InstructionCacheLabelWidget->setPosition(cpuCacheWidth * CPU_CACHE_L1_INSTRUCTION_TEXT_POSITION_X_PERCENT / 100, cpuCacheHeight * CPU_CACHE_L1_INSTRUCTION_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuL1InstructionCacheLabelWidget->setSize(cpuCacheWidth     * CPU_CACHE_L1_INSTRUCTION_TEXT_WIDTH_PERCENT      / 100, cpuCacheHeight * CPU_CACHE_L1_INSTRUCTION_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuLevel2CacheLabelWidget = new LabelWidget(cpuLevel2Cache, cpuCachePanelWidget);

    UEFI_ASSERT_EXECUTION(cpuLevel2CacheLabelWidget->setPosition(cpuCacheWidth * CPU_CACHE_L2_TEXT_POSITION_X_PERCENT / 100, cpuCacheHeight * CPU_CACHE_L2_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuLevel2CacheLabelWidget->setSize(cpuCacheWidth     * CPU_CACHE_L2_TEXT_WIDTH_PERCENT      / 100, cpuCacheHeight * CPU_CACHE_L2_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    LabelWidget *cpuLevel3CacheLabelWidget = new LabelWidget(cpuLevel3Cache, cpuCachePanelWidget);

    UEFI_ASSERT_EXECUTION(cpuLevel3CacheLabelWidget->setPosition(cpuCacheWidth * CPU_CACHE_L3_TEXT_POSITION_X_PERCENT / 100, cpuCacheHeight * CPU_CACHE_L3_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuLevel3CacheLabelWidget->setSize(cpuCacheWidth     * CPU_CACHE_L3_TEXT_WIDTH_PERCENT      / 100, cpuCacheHeight * CPU_CACHE_L3_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    TabPageWidget *testTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(testTabPageWidget), NgosStatus::ASSERTION);



    sStartButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, sStartImage, nullptr, "Start", testTabPageWidget);

    UEFI_ASSERT_EXECUTION(sStartButton->setPosition(tabPageWidth * START_BUTTON_POSITION_X_PERCENT / 100, tabPageHeight * START_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sStartButton->setSize(tabPageWidth     * START_BUTTON_WIDTH_PERCENT      / 100, tabPageHeight * START_BUTTON_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sStartButton->setKeyboardEventHandler(onStartButtonKeyboardEvent),                                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sStartButton->setPressEventHandler(onStartButtonPressed),                                                                               NgosStatus::ASSERTION);



    u64 testTableWidth  = tabPageWidth  * TEST_TABLEWIDGET_WIDTH_PERCENT  / 100;
    u64 testTableHeight = tabPageHeight * TEST_TABLEWIDGET_HEIGHT_PERCENT / 100;



    sTestTableWidget = new TableWidget(tableBackgroundImage, tableHeaderImage, testTabPageWidget);

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setPosition(tabPageWidth * TEST_TABLEWIDGET_POSITION_X_PERCENT / 100, tabPageHeight * TEST_TABLEWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setSize(testTableWidth, testTableHeight),                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setKeyboardEventHandler(onTestTableWidgetKeyboardEvent),                                                                             NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setRowHeight(tabPageHeight * TEST_TABLEWIDGET_ROW_HEIGHT_PERCENT / 100), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sTestTableWidget->setColumnCount(2), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setColumnWidth(COLUMN_NAME,  testTableWidth * TEST_COLUMN_NAME_WIDTH_PERCENT  / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setColumnWidth(COLUMN_SCORE, testTableWidth * TEST_COLUMN_SCORE_WIDTH_PERCENT / 100), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setHeaderText(COLUMN_NAME,  "Name"),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setHeaderText(COLUMN_SCORE, "Score"), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(addTestEntry("Start tests to get results"), NgosStatus::ASSERTION);



    TabPageWidget *summaryTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(summaryTabPageWidget), NgosStatus::ASSERTION);



    u64 summaryTableWidth  = tabPageWidth  * SUMMARY_TABLEWIDGET_WIDTH_PERCENT  / 100;
    u64 summaryTableHeight = tabPageHeight * SUMMARY_TABLEWIDGET_HEIGHT_PERCENT / 100;



    sSummaryTableWidget = new TableWidget(tableBackgroundImage, tableHeaderImage, summaryTabPageWidget);

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setPosition(tabPageWidth * SUMMARY_TABLEWIDGET_POSITION_X_PERCENT / 100, tabPageHeight * SUMMARY_TABLEWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setSize(summaryTableWidth, summaryTableHeight),                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setKeyboardEventHandler(onSummaryTableWidgetKeyboardEvent),                                                                             NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setRowHeight(tabPageHeight * SUMMARY_TABLEWIDGET_ROW_HEIGHT_PERCENT / 100), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setColumnCount(2), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setColumnWidth(COLUMN_NAME,  summaryTableWidth * SUMMARY_COLUMN_NAME_WIDTH_PERCENT  / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setColumnWidth(COLUMN_SCORE, summaryTableWidth * SUMMARY_COLUMN_SCORE_WIDTH_PERCENT / 100), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setHeaderText(COLUMN_NAME,  "Name"),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setHeaderText(COLUMN_SCORE, "Score"), NgosStatus::ASSERTION);



    char8 *summaryCpuThreads = (char8 *)malloc(23);

    i64 summaryCpuThreadsLength = sprintf(summaryCpuThreads, "Number of threads: %u", CPU::getNumberOfThreads());
    AVOID_UNUSED(summaryCpuThreadsLength);

    UEFI_TEST_ASSERT(summaryCpuThreadsLength < 23, NgosStatus::ASSERTION);



    char8 *summaryCpuSpeed = (char8 *)malloc(22);

    i64 summaryCpuSpeedLength = sprintf(summaryCpuSpeed, "CPU Speed: %s", hertzToString(CpuTest::getCpuSpeed()));
    AVOID_UNUSED(summaryCpuSpeedLength);

    UEFI_TEST_ASSERT(summaryCpuSpeedLength < 22, NgosStatus::ASSERTION);



    char8 *summaryCpuL1DataCache = (char8 *)malloc(39);

    i64 summaryCpuL1DataCacheLength = sprintf(summaryCpuL1DataCache, "L1 Data Cache: %u x %s %u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel1DataCache().size), CpuTest::getLevel1DataCache().numberOfWays);
    AVOID_UNUSED(summaryCpuL1DataCacheLength);

    UEFI_TEST_ASSERT(summaryCpuL1DataCacheLength < 39, NgosStatus::ASSERTION);



    char8 *summaryCpuL1InstructionCache = (char8 *)malloc(46);

    i64 summaryCpuL1InstructionCacheLength = sprintf(summaryCpuL1InstructionCache, "L1 Instruction Cache: %u x %s %u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel1InstructionCache().size), CpuTest::getLevel1InstructionCache().numberOfWays);
    AVOID_UNUSED(summaryCpuL1InstructionCacheLength);

    UEFI_TEST_ASSERT(summaryCpuL1InstructionCacheLength < 46, NgosStatus::ASSERTION);



    char8 *summaryCpuL2Cache = (char8 *)malloc(39);

    i64 summaryCpuL2CacheLength = sprintf(summaryCpuL2Cache, "Level 2 Cache: %u x %s %u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel2Cache().size), CpuTest::getLevel2Cache().numberOfWays);
    AVOID_UNUSED(summaryCpuL2CacheLength);

    UEFI_TEST_ASSERT(summaryCpuL2CacheLength < 39, NgosStatus::ASSERTION);



    char8 *summaryCpuL3Cache = (char8 *)malloc(33);

    i64 summaryCpuL3CacheLength = sprintf(summaryCpuL3Cache, "Level 3 Cache: %s %u-way", bytesToString(CpuTest::getLevel3Cache().size), CpuTest::getLevel3Cache().numberOfWays);
    AVOID_UNUSED(summaryCpuL3CacheLength);

    UEFI_TEST_ASSERT(summaryCpuL3CacheLength < 33, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(addSummaryEntry("Previous test results",      0),                                                                                                                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuThreads,            CPU::getNumberOfThreads() * SCORE_PER_THREAD),                                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuSpeed,              (CpuTest::getCpuSpeed() / 100000000) * SCORE_PER_100_MHZ),                                                                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuL1DataCache,        ((u64)CpuTest::getLevel1DataCache().size * CpuTest::getLevel1DataCache().numberOfWays * SCORE_L1_DATA_CACHE_PER_1_KB_1_WAY) >> 10),                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuL1InstructionCache, ((u64)CpuTest::getLevel1InstructionCache().size * CpuTest::getLevel1InstructionCache().numberOfWays * SCORE_L1_INSTRUCTION_CACHE_PER_1_KB_1_WAY) >> 10), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuL2Cache,            ((u64)CpuTest::getLevel2Cache().size * CpuTest::getLevel2Cache().numberOfWays * SCORE_L2_CACHE_PER_1_MB_1_WAY) >> 20),                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuL3Cache,            ((u64)CpuTest::getLevel3Cache().size * CpuTest::getLevel3Cache().numberOfWays * SCORE_L3_CACHE_PER_1_MB_1_WAY) >> 20),                                   NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(flagsCount == ARRAY_COUNT(testedFeaturesScores), NgosStatus::ASSERTION);

    for (i64 i = 0; i < flagsCount; ++i)
    {
        UEFI_ASSERT_EXECUTION(addSummaryFeature(testedFeatures[i], testedFeaturesScores[i]), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(addSummaryTotal(), NgosStatus::ASSERTION);



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



    Guid mpServicesProtocol = UEFI_MP_SERVICES_PROTOCOL_GUID;

    if (UEFI::locateProtocol(&mpServicesProtocol, nullptr, (void **)&sMpServices) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Found UEFI_MP_SERVICES_PROTOCOL at 0x%p", sMpServices));
    }
    else
    {
        UEFI_LW(("UEFI_MP_SERVICES_PROTOCOL not found"));
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::exec()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(generateWaitEventList(), NgosStatus::ASSERTION);

    do
    {
        UEFI_ASSERT_EXECUTION(waitForEvent(), NgosStatus::ASSERTION);
    } while(true);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addFeaturePanel(X86Feature flag, u64 featurePanelPositionX, u64 featurePanelPositionY, u64 featurePanelWidth, u64 featurePanelHeight, Image *featurePanelImage, Image *featurePanelResizedImage, TabPageWidget *tabPageWidget)
{
    UEFI_LT((" | flag = %u, featurePanelPositionX = %u, featurePanelPositionY = %u, featurePanelWidth = %u, featurePanelHeight = %u, featurePanelImage = 0x%p, featurePanelResizedImage = 0x%p, tabPageWidget = 0x%p", flag, featurePanelPositionX, featurePanelPositionY, featurePanelWidth, featurePanelHeight, featurePanelImage, featurePanelResizedImage, tabPageWidget));

    UEFI_ASSERT(featurePanelWidth > 0,    "featurePanelWidth is zero",        NgosStatus::ASSERTION);
    UEFI_ASSERT(featurePanelHeight > 0,   "featurePanelHeight is zero",       NgosStatus::ASSERTION);
    UEFI_ASSERT(featurePanelImage,        "featurePanelImage is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(featurePanelResizedImage, "featurePanelResizedImage is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(tabPageWidget,            "tabPageWidget is null",            NgosStatus::ASSERTION);



    const char8 *flagText     = x86FeaturesNames[(u64)flag];
    char8       *flagTextFull = (char8 *)malloc(11);

    UEFI_TEST_ASSERT(flagText && *flagText, NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sprintf(flagTextFull, "%-10s", flagText), i64, 10, NgosStatus::ASSERTION);



    PanelWidget *featurePanelWidget = new PanelWidget(featurePanelImage, featurePanelResizedImage, tabPageWidget);

    UEFI_ASSERT_EXECUTION(featurePanelWidget->setPosition(featurePanelPositionX, featurePanelPositionY), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(featurePanelWidget->setSize(featurePanelWidth, featurePanelHeight),            NgosStatus::ASSERTION);



    LabelWidget *featureTextLabelWidget = new LabelWidget(flagTextFull, featurePanelWidget);

    UEFI_ASSERT_EXECUTION(featureTextLabelWidget->setPosition(featurePanelWidth * FEATURE_TEXT_POSITION_X_PERCENT / 100, featurePanelHeight * FEATURE_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(featureTextLabelWidget->setSize(featurePanelWidth     * FEATURE_TEXT_WIDTH_PERCENT      / 100, featurePanelHeight * FEATURE_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);

    LabelWidget *featureTextLabelWidget2 = new LabelWidget(flagTextFull, featurePanelWidget);

    UEFI_ASSERT_EXECUTION(featureTextLabelWidget2->setPosition(featurePanelWidth * (FEATURE_TEXT_POSITION_X_PERCENT - 1) / 100, featurePanelHeight * (FEATURE_TEXT_POSITION_Y_PERCENT - 2) / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(featureTextLabelWidget2->setSize(featurePanelWidth     * FEATURE_TEXT_WIDTH_PERCENT            / 100, featurePanelHeight * FEATURE_TEXT_HEIGHT_PERCENT           / 100), NgosStatus::ASSERTION);



    RgbaPixel color;
    RgbaPixel color2;

    if (CPU::hasFlag(flag))
    {
        color.red   = 0x46;
        color.green = 0x60;
        color.blue  = 0x46;
        color.alpha = 0xDD;

        color2.red   = 0x00;
        color2.green = 0x9B;
        color2.blue  = 0x00;
        color2.alpha = 0xFF;
    }
    else
    {
        color.red   = 0x60;
        color.green = 0x60;
        color.blue  = 0x60;
        color.alpha = 0xDD;

        color2.red   = 0x33;
        color2.green = 0x33;
        color2.blue  = 0x33;
        color2.alpha = 0xFF;
    }

    UEFI_ASSERT_EXECUTION(featureTextLabelWidget->setColor(color),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(featureTextLabelWidget2->setColor(color2), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addTestEntry(const char8 *name)
{
    UEFI_LT((" | name = 0x%p", name));

    UEFI_ASSERT(name, "name is null", NgosStatus::ASSERTION);



    RgbaPixel blackColor;

    blackColor.red   = 0;
    blackColor.green = 0;
    blackColor.blue  = 0;
    blackColor.alpha = 0xFF;



    u64 row = sTestTableWidget->getRowCount();

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setRowCount(row + 1), NgosStatus::ASSERTION);



    LabelWidget *nameLabelWidget = new LabelWidget(name, sTestTableWidget);
    UEFI_ASSERT_EXECUTION(nameLabelWidget->setColor(blackColor),                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setCellWidget(row, COLUMN_NAME, nameLabelWidget), NgosStatus::ASSERTION);

    LabelWidget *scoreLabelWidget = new LabelWidget("", sTestTableWidget);
    UEFI_ASSERT_EXECUTION(scoreLabelWidget->setColor(blackColor),                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setCellWidget(row, COLUMN_SCORE, scoreLabelWidget), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addSummaryEntry(const char8 *name, u64 score)
{
    UEFI_LT((" | name = 0x%p, score = %u", name, score));

    UEFI_ASSERT(name, "name is null", NgosStatus::ASSERTION);



    RgbaPixel blackColor;

    blackColor.red   = 0;
    blackColor.green = 0;
    blackColor.blue  = 0;
    blackColor.alpha = 0xFF;



    char8 *scoreString = (char8 *)malloc(7);

    i64 scoreLength = sprintf(scoreString, "%u", score);
    AVOID_UNUSED(scoreLength);

    UEFI_TEST_ASSERT(scoreLength < 7, NgosStatus::ASSERTION);



    u64 row = sSummaryTableWidget->getRowCount();

    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setRowCount(row + 1), NgosStatus::ASSERTION);



    LabelWidget *nameLabelWidget = new LabelWidget(name, sSummaryTableWidget);
    UEFI_ASSERT_EXECUTION(nameLabelWidget->setColor(blackColor),                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setCellWidget(row, COLUMN_NAME, nameLabelWidget), NgosStatus::ASSERTION);

    LabelWidget *scoreLabelWidget = new LabelWidget(scoreString, sSummaryTableWidget);
    UEFI_ASSERT_EXECUTION(scoreLabelWidget->setColor(blackColor),                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSummaryTableWidget->setCellWidget(row, COLUMN_SCORE, scoreLabelWidget), NgosStatus::ASSERTION);



    sSummaryTotal += score;



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addSummaryFeature(X86Feature flag, u64 score)
{
    UEFI_LT((" | flag = %u, score = %u", flag, score));



    if (CPU::hasFlag(flag))
    {
        const char8 *flagText = x86FeaturesNames[(u64)flag];
        UEFI_TEST_ASSERT(flagText && *flagText, NgosStatus::ASSERTION);



        char8 *flagTextFull = (char8 *)malloc(28);

        i64 flagTextLength = sprintf(flagTextFull, "Support feature: %s", flagText);
        AVOID_UNUSED(flagTextLength);

        UEFI_TEST_ASSERT(flagTextLength < 28, NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(addSummaryEntry(flagTextFull, score), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addSummaryTotal()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(addSummaryEntry("Total", sSummaryTotal), NgosStatus::ASSERTION);

    sSummaryTotal >>= 1;



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::focusTabFirstWidget()
{
    UEFI_LT((""));



    switch (sTabWidget->getCurrentPage())
    {
        case TABWIDGET_PAGE_SYSTEM_INFORMATION: return NgosStatus::NO_EFFECT;
        case TABWIDGET_PAGE_TEST:               return GUI::setFocusedWidget(sStartButton);
        case TABWIDGET_PAGE_SUMMARY:            return GUI::setFocusedWidget(sSummaryTableWidget);

        default:
        {
            UEFI_LF(("Unknown tab page: %d", sTabWidget->getCurrentPage()));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::generateWaitEventList()
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

NgosStatus CpuTestGUI::waitForEvent()
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

NgosStatus CpuTestGUI::processKeyboardEvent()
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
    }

    UEFI_TEST_ASSERT(status == NgosStatus::OK
                    ||
                    status == NgosStatus::NO_EFFECT, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::processSimplePointerEvent(UefiSimplePointerProtocol *pointer)
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

NgosStatus CpuTestGUI::processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer)
{
    UEFI_LT((" | pointer = 0x%p", pointer));

    UEFI_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);



    UefiAbsolutePointerState state;

    if (pointer->getState(pointer, &state) == UefiStatus::SUCCESS)
    {
        UEFI_LVVV(("state.currentX      = %u",          state.currentX));
        UEFI_LVVV(("state.currentY      = %u",          state.currentY));
        UEFI_LVVV(("state.currentZ      = %u",          state.currentZ));
        UEFI_LVVV(("state.activeButtons = 0x%08X (%s)", state.activeButtons, uefiAbsolutePointerStateActiveButtonFlagsToString(state.activeButtons)));



        UEFI_ASSERT_EXECUTION(GUI::processAbsolutePointerState(pointer, &state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onRebootButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus CpuTestGUI::onShutdownButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::DOWN: focusTabFirstWidget();

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

NgosStatus CpuTestGUI::onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
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

NgosStatus CpuTestGUI::onTestTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sSystemInformationTabButton);
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

NgosStatus CpuTestGUI::onSummaryTabButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus CpuTestGUI::onStartButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sTestTabButton);
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sTestTableWidget);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sTestTableWidget);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus CpuTestGUI::onTestTableWidgetKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP: return (!sTestTableWidget->getSelectedRow()) ? GUI::setFocusedWidget(sStartButton) : NgosStatus::NO_EFFECT; // sTestTableWidget->getSelectedRow() == 0

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

NgosStatus CpuTestGUI::onSummaryTableWidgetKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP: return (!sSummaryTableWidget->getSelectedRow()) ? GUI::setFocusedWidget(sSummaryTabButton) : NgosStatus::NO_EFFECT; // sSummaryTableWidget->getSelectedRow() == 0

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

NgosStatus CpuTestGUI::onRebootButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::COLD, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onShutdownButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::SHUTDOWN, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onSystemInformationTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SYSTEM_INFORMATION), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onTestTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_TEST), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onSummaryTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SUMMARY), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onStartButtonPressed()
{
    UEFI_LT((""));



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



        if (numberOfProcessors > 1)
        {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            {
                UEFI_LVVV(("Processors:"));
                UEFI_LVVV(("-------------------------------------"));

                for (i64 i = 0; i < (i64)numberOfProcessors; ++i)
                {
                    UefiProcessorInformation info;

                    UEFI_ASSERT_EXECUTION(sMpServices->getProcessorInfo(sMpServices, i, &info), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



                    UEFI_LVVV(("info[%d].processorId      = %u",      i, info.processorId));
                    UEFI_LVVV(("info[%d].status           = %u (%s)", i, info.status, uefiProcessorInformationStatusFlagsToString(info.status)));
                    UEFI_LVVV(("info[%d].location.package = %u",      i, info.location.package));
                    UEFI_LVVV(("info[%d].location.core    = %u",      i, info.location.core));
                    UEFI_LVVV(("info[%d].location.thread  = %u",      i, info.location.thread));



                    if (i < (i64)numberOfProcessors - 1)
                    {
                        UEFI_LVVV(("+++++++++++++++++++++++++++++++++++++"));
                    }
                }

                UEFI_LVVV(("-------------------------------------"));
            }
#endif
        }
        else
        {
            UEFI_LE(("Failed to start task on dedicated CPU core since there is only one core"));
        }
    }
    else
    {
        UEFI_LE(("UEFI_MP_SERVICES_PROTOCOL not found"));
    }



    return NgosStatus::OK;
}
