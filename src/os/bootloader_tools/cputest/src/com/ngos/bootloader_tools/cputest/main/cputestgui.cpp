#include "cputestgui.h"

#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/cpu/generated/x86featuresnames.h>
#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/gui/gui.h>
#include <com/ngos/shared/common/gui/widgets/misc/labelwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/panelwidget.h>
#include <com/ngos/shared/common/gui/widgets/special/rootwidget.h>
#include <com/ngos/shared/common/gui/widgets/special/screenwidget.h>
#include <com/ngos/shared/common/memory/malloc.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/common/macro/constants.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/uefibase/uefi/uefi.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>
#include <com/ngos/shared/uefibase/uefi/uefipointerdevices.h>

#include "com/ngos/bootloader_tools/cputest/main/cputest.h"
#include "com/ngos/bootloader_tools/cputest/tests/testbase.h"



#define TABWIDGET_HEIGHT_PERCENT 70

#define TAB_BUTTON_WIDTH_PERCENT  15
#define TAB_BUTTON_HEIGHT_PERCENT 11

#define TAB_PAGE_PROPORTION 2.8

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

#define ISSUES_TABLEWIDGET_POSITION_X_PERCENT 1
#define ISSUES_TABLEWIDGET_POSITION_Y_PERCENT 1
#define ISSUES_TABLEWIDGET_WIDTH_PERCENT      98
#define ISSUES_TABLEWIDGET_HEIGHT_PERCENT     98
#define ISSUES_TABLEWIDGET_ROW_HEIGHT         27

#define ISSUES_COLUMN_ICON_WIDTH 27

#define START_BUTTON_POSITION_X_PERCENT 1
#define START_BUTTON_POSITION_Y_PERCENT 0
#define START_BUTTON_WIDTH_PERCENT      20
#define START_BUTTON_HEIGHT_PERCENT     10

#define TEST_TOTAL_TEXT_POSITION_X_PERCENT 80
#define TEST_TOTAL_TEXT_POSITION_Y_PERCENT 1
#define TEST_TOTAL_TEXT_WIDTH_PERCENT      19
#define TEST_TOTAL_TEXT_HEIGHT_PERCENT     8

#define TEST_TABLEWIDGET_POSITION_X_PERCENT 1
#define TEST_TABLEWIDGET_POSITION_Y_PERCENT 10
#define TEST_TABLEWIDGET_WIDTH_PERCENT      98
#define TEST_TABLEWIDGET_HEIGHT_PERCENT     89
#define TEST_TABLEWIDGET_ROW_HEIGHT         27

#define TEST_COLUMN_NAME_WIDTH_PERCENT  80
#define TEST_COLUMN_SCORE_WIDTH_PERCENT 20

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

#define SCORE_PER_THREAD                    500
#define SCORE_PER_100_MHZ                   200
#define SCORE_L1_DATA_CACHE_PER_1_KB        2
#define SCORE_L1_INSTRUCTION_CACHE_PER_1_KB 2
#define SCORE_L2_CACHE_PER_1_MB             200
#define SCORE_L3_CACHE_PER_1_MB             40

#define BLACK_COLOR                   0xFF000000
#define FEATURE_ENABLED_TEXT_COLOR    0xFF009B00
#define FEATURE_ENABLED_SHADOW_COLOR  0xDD466046
#define FEATURE_DISABLED_TEXT_COLOR   0xFF333333
#define FEATURE_DISABLED_SHADOW_COLOR 0xDD606060

#define TEST_TOTAL_TEXT_LENGTH    14
#define SUMMARY_TOTAL_TEXT_LENGTH 14



Button                 *CpuTestGUI::sRebootButton;
Button                 *CpuTestGUI::sShutdownButton;
TabWidget              *CpuTestGUI::sTabWidget;
TabButton              *CpuTestGUI::sSystemInformationTabButton;
TabButton              *CpuTestGUI::sIssuesTabButton;
TabButton              *CpuTestGUI::sTestTabButton;
TabButton              *CpuTestGUI::sSummaryTabButton;
Image                  *CpuTestGUI::sWarningImage;
Image                  *CpuTestGUI::sCriticalImage;
TableWidget            *CpuTestGUI::sIssuesTableWidget;
Button                 *CpuTestGUI::sStartButton;
Image                  *CpuTestGUI::sStartImage;
Image                  *CpuTestGUI::sStopImage;
LabelWidget            *CpuTestGUI::sTestTotalLabelWidget;
TableWidget            *CpuTestGUI::sTestTableWidget;
LabelWidget            *CpuTestGUI::sSummaryTotalLabelWidget;
TableWidget            *CpuTestGUI::sSummaryTableWidget;
u64                     CpuTestGUI::sSummaryTotal;
UefiMpServicesProtocol *CpuTestGUI::sMpServices;
u16                     CpuTestGUI::sWaitEventsCount;
uefi_event             *CpuTestGUI::sWaitEvents;
u16                     CpuTestGUI::sFirstProcessorEventIndex;
TestType                CpuTestGUI::sCurrentTest;
TestType                CpuTestGUI::sDisplayedTest;
u64                     CpuTestGUI::sNumberOfRunningProcessors;
bool                    CpuTestGUI::sTerminated;

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
    Image *issuesImage;
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
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/issues.png",                      &issuesImage),                  NgosStatus::ASSERTION);
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



    // Ignore CppAlignmentVerifier [BEGIN]
    u64 tabWidgetHeight = screenHeight    * TABWIDGET_HEIGHT_PERCENT  / 100;
    u64 tabButtonHeight = tabWidgetHeight * TAB_BUTTON_HEIGHT_PERCENT / 100;
    u64 tabPageHeight   = tabWidgetHeight - tabButtonHeight;
    // Ignore CppAlignmentVerifier [END]



    u64 tabPageWidth = tabPageHeight * TAB_PAGE_PROPORTION;

    if (tabPageWidth > screenWidth)
    {
        tabPageWidth    = screenWidth;
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



    u64 cpuImageSize = tabPageHeight * CPU_IMAGE_SIZE_PERCENT / 100;



    ImageWidget *cpuImageWidget = new ImageWidget(cpuImage, systemInformationTabPageWidget);

    UEFI_ASSERT_EXECUTION(cpuImageWidget->setPosition(tabPageWidth * CPU_IMAGE_POSITION_X_PERCENT / 100, tabPageHeight * CPU_IMAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuImageWidget->setSize(cpuImageSize, cpuImageSize),                                                                                NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(sizeof(CPU::sModelName) == 48, NgosStatus::ASSERTION);

    // Ignore CppAlignmentVerifier [BEGIN]
    char8 *cpuModelName = mprintf("CPU Model: %.48s",       CPU::getModelName());
    char8 *cpuCores     = mprintf("Cores: %-3u",            CPU::getNumberOfCores());
    char8 *cpuThreads   = mprintf("Threads: %-3u",          CPU::getNumberOfThreads());
    char8 *cpuFamily    = mprintf("Family:   0x%02X      ", CPU::getFamily());
    char8 *cpuModel     = mprintf("Model:    0x%02X      ", CPU::getModel());
    char8 *cpuStepping  = mprintf("Stepping: 0x%02X      ", CPU::getStepping());
    char8 *cpuRevision  = mprintf("Revision: 0x%08X",       CPU::getMicrocodeRevision());
    // Ignore CppAlignmentVerifier [END]



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



    char8 *cpuSpeed = mprintf("CPU Speed    %-10s", hertzToString(CpuTest::getCpuSpeed()));



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



    // Ignore CppAlignmentVerifier [BEGIN]
    char8 *cpuL1DataCache        = mprintf("L1 Data  %3u x %-10s %2u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel1DataCache().size),        CpuTest::getLevel1DataCache().numberOfWays);
    char8 *cpuL1InstructionCache = mprintf("L1 Inst. %3u x %-10s %2u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel1InstructionCache().size), CpuTest::getLevel1InstructionCache().numberOfWays);
    char8 *cpuLevel2Cache        = mprintf("Level 2  %3u x %-10s %2u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel2Cache().size),            CpuTest::getLevel2Cache().numberOfWays);
    char8 *cpuLevel3Cache        = mprintf("Level 3    %-10s     %2u-way",                          bytesToString(CpuTest::getLevel3Cache().size),            CpuTest::getLevel3Cache().numberOfWays);
    // Ignore CppAlignmentVerifier [END]



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



    sStartButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, sStartImage, nullptr, "Start", testTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sStartButton->setPosition(tabPageWidth * START_BUTTON_POSITION_X_PERCENT / 100, tabPageHeight * START_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sStartButton->setSize(tabPageWidth     * START_BUTTON_WIDTH_PERCENT      / 100, tabPageHeight * START_BUTTON_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sStartButton->setKeyboardEventHandler(onStartButtonKeyboardEvent),                                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sStartButton->setPressEventHandler(onStartButtonPressed),                                                                               NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    char8 *testTotalText = (char8 *)malloc(TEST_TOTAL_TEXT_LENGTH);
    UEFI_TEST_ASSERT(testTotalText != nullptr, NgosStatus::ASSERTION);

    testTotalText[0] = 0;



    sTestTotalLabelWidget = new LabelWidget(testTotalText, testTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestTotalLabelWidget->setVisible(false),                                                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTotalLabelWidget->setPosition(tabPageWidth * TEST_TOTAL_TEXT_POSITION_X_PERCENT / 100, tabPageHeight * TEST_TOTAL_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTotalLabelWidget->setSize(tabPageWidth     * TEST_TOTAL_TEXT_WIDTH_PERCENT      / 100, tabPageHeight * TEST_TOTAL_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    u64 testTableWidth  = tabPageWidth  * TEST_TABLEWIDGET_WIDTH_PERCENT  / 100;
    u64 testTableHeight = tabPageHeight * TEST_TABLEWIDGET_HEIGHT_PERCENT / 100;



    sTestTableWidget = new TableWidget(tableBackgroundImage, tableHeaderImage, testTabPageWidget);

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setPosition(tabPageWidth * TEST_TABLEWIDGET_POSITION_X_PERCENT / 100, tabPageHeight * TEST_TABLEWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setSize(testTableWidth, testTableHeight),                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setKeyboardEventHandler(onTestTableWidgetKeyboardEvent),                                                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setRowHeight(TEST_TABLEWIDGET_ROW_HEIGHT),                                                                                        NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sTestTableWidget->setColumnCount(2), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setColumnWidth(COLUMN_NAME,  testTableWidth * TEST_COLUMN_NAME_WIDTH_PERCENT  / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setColumnWidth(COLUMN_SCORE, testTableWidth * TEST_COLUMN_SCORE_WIDTH_PERCENT / 100), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setHeaderText(COLUMN_NAME,  "Name"),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setHeaderText(COLUMN_SCORE, "Score"), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(addTestEntry("Start tests to get results", ""), NgosStatus::ASSERTION);



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



    char8 *summaryTotalText = (char8 *)malloc(SUMMARY_TOTAL_TEXT_LENGTH);
    UEFI_TEST_ASSERT(summaryTotalText != nullptr, NgosStatus::ASSERTION);

    i64 summaryTotalTextLength = sprintf(summaryTotalText, "Total: %u", sSummaryTotal);
    AVOID_UNUSED(summaryTotalTextLength);

    UEFI_TEST_ASSERT(summaryTotalTextLength < SUMMARY_TOTAL_TEXT_LENGTH, NgosStatus::ASSERTION);



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

NgosStatus CpuTestGUI::addFeaturePanel(X86Feature flag, u64 posX, u64 posY, u64 width, u64 height, Image *featurePanelImage, Image *featurePanelResizedImage, TabPageWidget *tabPageWidget)
{
    UEFI_LT((" | flag = %u, posX = %u, posY = %u, width = %u, height = %u, featurePanelImage = 0x%p, featurePanelResizedImage = 0x%p, tabPageWidget = 0x%p", flag, posX, posY, width, height, featurePanelImage, featurePanelResizedImage, tabPageWidget));

    UEFI_ASSERT(width > 0,                "width is zero",                    NgosStatus::ASSERTION);
    UEFI_ASSERT(height > 0,               "height is zero",                   NgosStatus::ASSERTION);
    UEFI_ASSERT(featurePanelImage,        "featurePanelImage is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(featurePanelResizedImage, "featurePanelResizedImage is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(tabPageWidget,            "tabPageWidget is null",            NgosStatus::ASSERTION);



    const char8 *flagText = x86FeaturesNames[(u64)flag];
    UEFI_TEST_ASSERT(flagText != nullptr && flagText[0] != 0, NgosStatus::ASSERTION);



    char8 *flagTextFull = mprintf("%-10s", flagText);



    PanelWidget *featurePanelWidget = new PanelWidget(featurePanelImage, featurePanelResizedImage, tabPageWidget);

    UEFI_ASSERT_EXECUTION(featurePanelWidget->setPosition(posX, posY), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(featurePanelWidget->setSize(width, height),  NgosStatus::ASSERTION);



    LabelWidget *featureShadowLabelWidget = new LabelWidget(flagTextFull, featurePanelWidget);

    UEFI_ASSERT_EXECUTION(featureShadowLabelWidget->setPosition(width * FEATURE_TEXT_POSITION_X_PERCENT / 100, height * FEATURE_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(featureShadowLabelWidget->setSize(width     * FEATURE_TEXT_WIDTH_PERCENT      / 100, height * FEATURE_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);

    LabelWidget *featureTextLabelWidget = new LabelWidget(flagTextFull, featurePanelWidget);

    UEFI_ASSERT_EXECUTION(featureTextLabelWidget->setPosition(width * (FEATURE_TEXT_POSITION_X_PERCENT - 1) / 100, height * (FEATURE_TEXT_POSITION_Y_PERCENT - 2) / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(featureTextLabelWidget->setSize(width     * FEATURE_TEXT_WIDTH_PERCENT            / 100, height * FEATURE_TEXT_HEIGHT_PERCENT           / 100), NgosStatus::ASSERTION);



    RgbaPixel shadowColor;
    RgbaPixel textColor;

    if (CPU::hasFlag(flag))
    {
        shadowColor.value32 = FEATURE_ENABLED_SHADOW_COLOR;
        textColor.value32   = FEATURE_ENABLED_TEXT_COLOR;
    }
    else
    {
        shadowColor.value32 = FEATURE_DISABLED_SHADOW_COLOR;
        textColor.value32   = FEATURE_DISABLED_TEXT_COLOR;
    }

    UEFI_ASSERT_EXECUTION(featureShadowLabelWidget->setColor(shadowColor), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(featureTextLabelWidget->setColor(textColor),     NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addIssueEntry(Image *icon, const char8 *description)
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

NgosStatus CpuTestGUI::fillIssuesTable()
{
    UEFI_LT((""));



    if (!CPU::hasFlag(X86Feature::CPUID))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support CPUID that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::FPU))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support FPU that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::LM))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support LM that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::MSR))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support MSR that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::PAE))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support PAE that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::NX))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support NX that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::TSC))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support TSC that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::FXSR))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support FXSR that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::XSAVE))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support XSAVE that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::AES))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support AES that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::CX8))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support CX8 that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::CMOV))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support CMOV that highly required"), NgosStatus::ASSERTION);
    }

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    if (!CPU::hasFlag(X86Feature::LA57))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support LA57 that highly required"), NgosStatus::ASSERTION);
    }
#endif

    if (!CPU::hasFlag(X86Feature::FMA))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support FMA3 that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::XMM))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support SSE that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::XMM2))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support SSE2 that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::XMM3))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support SSE3 that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::SSSE3))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support SSSE3 that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::XMM4_1))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support SSE4.1 that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::XMM4_2))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support SSE4.2 that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::AVX))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support AVX that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::AVX2))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "CPU doesn't support AVX2 that highly required"), NgosStatus::ASSERTION);
    }

    if (!CPU::hasFlag(X86Feature::AVX512F))
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "CPU doesn't support AVX512F for best performance"), NgosStatus::ASSERTION);
    }



    if (CPU::getNumberOfCores() < 4)
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sWarningImage, "CPU with less than 4 cores"), NgosStatus::ASSERTION);
    }



    if (CPU::isOutdated())
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(sCriticalImage, "Your CPU is already outdated. Please upgrade it"), NgosStatus::ASSERTION);
    }



    if (sIssuesTableWidget->getRowCount() == 0)
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(nullptr, "Everything is OK"), NgosStatus::ASSERTION);
    }
    else
    {
        UEFI_ASSERT_EXECUTION(addIssueEntry(nullptr, ""),                                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(addIssueEntry(nullptr, "We recommend Intel Core i9-10980XE Extreme Edition"), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(addIssueEntry(nullptr, "or AMD Ryzen Threadripper 3990X or newer"),           NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addTestEntry(const char8 *name, const char8 *score)
{
    UEFI_LT((" | name = 0x%p, score = 0x%p", name, score));

    UEFI_ASSERT(name,  "name is null",  NgosStatus::ASSERTION);
    UEFI_ASSERT(score, "score is null", NgosStatus::ASSERTION);



    RgbaPixel blackColor(BLACK_COLOR);



    u64 row = sTestTableWidget->getRowCount();

    UEFI_ASSERT_EXECUTION(sTestTableWidget->setRowCount(row + 1), NgosStatus::ASSERTION);



    LabelWidget *nameLabelWidget = new LabelWidget(name, sTestTableWidget);

    UEFI_ASSERT_EXECUTION(nameLabelWidget->setColor(blackColor),                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(nameLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setCellWidget(row, COLUMN_NAME, nameLabelWidget),           NgosStatus::ASSERTION);

    LabelWidget *scoreLabelWidget = new LabelWidget(score, sTestTableWidget);

    UEFI_ASSERT_EXECUTION(scoreLabelWidget->setColor(blackColor),                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestTableWidget->setCellWidget(row, COLUMN_SCORE, scoreLabelWidget), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addTestEntry()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sDisplayedTest < TestType::MAXIMUM, NgosStatus::ASSERTION);

    TestBase *test = cpuTests[(u64)sDisplayedTest];



    if (test->isCompleted())
    {
        if (test->getScore() != 0)
        {
            UEFI_ASSERT_EXECUTION(addTestEntry(test->getName(), mprintf("%u", test->getScore())), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_ASSERT_EXECUTION(addTestEntry(test->getName(), "N/A"), NgosStatus::ASSERTION);
        }
    }
    else
    {
        UEFI_ASSERT_EXECUTION(addTestEntry(test->getName(), "..."), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::putTestScore()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sDisplayedTest < TestType::MAXIMUM, NgosStatus::ASSERTION);

    TestBase *test = cpuTests[(u64)sDisplayedTest];



    if (test->getScore() != 0)
    {
        ((LabelWidget *)sTestTableWidget->getCellWidget(sTestTableWidget->getRowCount() - 1, COLUMN_SCORE))->setText(mprintf("%u", test->getScore()));
    }
    else
    {
        ((LabelWidget *)sTestTableWidget->getCellWidget(sTestTableWidget->getRowCount() - 1, COLUMN_SCORE))->setText("N/A");
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::addSummaryEntry(const char8 *name, u64 score)
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

NgosStatus CpuTestGUI::addSummaryFeature(X86Feature flag, u64 score)
{
    UEFI_LT((" | flag = %u, score = %u", flag, score));



    if (CPU::hasFlag(flag))
    {
        const char8 *flagText = x86FeaturesNames[(u64)flag];
        UEFI_TEST_ASSERT(flagText != nullptr && flagText[0] != 0, NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(addSummaryEntry(mprintf("Support feature: %s", flagText), score), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::fillSummaryTable()
{
    UEFI_LT((""));



    // Ignore CppAlignmentVerifier [BEGIN]
    char8 *summaryCpuThreads            = mprintf("Number of threads: %u",                CPU::getNumberOfThreads());
    char8 *summaryCpuSpeed              = mprintf("CPU Speed: %s",                        hertzToString(CpuTest::getCpuSpeed()));
    char8 *summaryCpuL1DataCache        = mprintf("L1 Data Cache: %u x %s %u-way",        CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel1DataCache().size),        CpuTest::getLevel1DataCache().numberOfWays);
    char8 *summaryCpuL1InstructionCache = mprintf("L1 Instruction Cache: %u x %s %u-way", CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel1InstructionCache().size), CpuTest::getLevel1InstructionCache().numberOfWays);
    char8 *summaryCpuL2Cache            = mprintf("Level 2 Cache: %u x %s %u-way",        CPU::getNumberOfCores(), bytesToString(CpuTest::getLevel2Cache().size),            CpuTest::getLevel2Cache().numberOfWays);
    char8 *summaryCpuL3Cache            = mprintf("Level 3 Cache: %s %u-way",                                      bytesToString(CpuTest::getLevel3Cache().size),            CpuTest::getLevel3Cache().numberOfWays);
    // Ignore CppAlignmentVerifier [END]



    UEFI_ASSERT_EXECUTION(addSummaryEntry("Previous test results",      0),                                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuThreads,            CPU::getNumberOfThreads() * SCORE_PER_THREAD),                                                                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuSpeed,              (CpuTest::getCpuSpeed() / 100000000) * SCORE_PER_100_MHZ),                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuL1DataCache,        CPU::getNumberOfCores() * (u64)CpuTest::getLevel1DataCache().size * SCORE_L1_DATA_CACHE_PER_1_KB / KB),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuL1InstructionCache, CPU::getNumberOfCores() * (u64)CpuTest::getLevel1InstructionCache().size * SCORE_L1_INSTRUCTION_CACHE_PER_1_KB / KB), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuL2Cache,            CPU::getNumberOfCores() * (u64)CpuTest::getLevel2Cache().size * SCORE_L2_CACHE_PER_1_MB / MB),                        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(summaryCpuL3Cache,            (u64)CpuTest::getLevel3Cache().size * SCORE_L3_CACHE_PER_1_MB / MB),                                                  NgosStatus::ASSERTION);



    i64 flagsCount = ARRAY_COUNT(testedFeatures);
    UEFI_LVVV(("flagsCount = %d", flagsCount));

    UEFI_TEST_ASSERT(flagsCount == ARRAY_COUNT(testedFeaturesScores), NgosStatus::ASSERTION);

    for (i64 i = 0; i < flagsCount; ++i)
    {
        UEFI_ASSERT_EXECUTION(addSummaryFeature(testedFeatures[i], testedFeaturesScores[i]), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::focusTabFirstWidget()
{
    UEFI_LT((""));



    switch (sTabWidget->getCurrentPage())
    {
        case TABWIDGET_PAGE_SYSTEM_INFORMATION: return GUI::setFocusedWidget(sRebootButton);
        case TABWIDGET_PAGE_ISSUES:             return GUI::setFocusedWidget(sIssuesTableWidget);
        case TABWIDGET_PAGE_TEST:               return GUI::setFocusedWidget(sStartButton);
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

NgosStatus CpuTestGUI::focusTabLastWidget()
{
    UEFI_LT((""));



    switch (sTabWidget->getCurrentPage())
    {
        case TABWIDGET_PAGE_SYSTEM_INFORMATION: return GUI::setFocusedWidget(sSystemInformationTabButton);
        case TABWIDGET_PAGE_ISSUES:             return GUI::setFocusedWidget(sIssuesTableWidget);
        case TABWIDGET_PAGE_TEST:               return GUI::setFocusedWidget(sTestTableWidget);
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

NgosStatus CpuTestGUI::generateWaitEventList()
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

NgosStatus CpuTestGUI::waitForEvent()
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

NgosStatus CpuTestGUI::terminateAndWaitForApplicationProcessors()
{
    UEFI_LT((""));



    if (sNumberOfRunningProcessors > 0)
    {
        if (!sTerminated)
        {
            sTerminated = true;

            UEFI_ASSERT_EXECUTION(addTestEntry("Terminated by user", ""), NgosStatus::ASSERTION);
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

NgosStatus CpuTestGUI::processKeyboardEvent()
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
        UEFI_LVVV(("state.leftButton        = %s", boolToString(state.leftButton)));
        UEFI_LVVV(("state.rightButton       = %s", boolToString(state.rightButton)));



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
        UEFI_LVVV(("state.currentX      = %u", state.currentX));
        UEFI_LVVV(("state.currentY      = %u", state.currentY));
        UEFI_LVVV(("state.currentZ      = %u", state.currentZ));
        UEFI_LVVV(("state.activeButtons = %s", flagsToFullString(state.activeButtons)));



        UEFI_ASSERT_EXECUTION(GUI::processAbsolutePointerState(pointer, &state), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::processApplicationProcessorEvent(u64 processorId)
{
    UEFI_LT((" | processorId = %u", processorId));



    UEFI_LV(("Application processor %u finished", processorId));



    if (!sTerminated)
    {
        if (
            sDisplayedTest < TestType::MAXIMUM
            &&
            cpuTests[(u64)sDisplayedTest]->isCompleted()
           )
        {
            UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



            UEFI_ASSERT_EXECUTION(putTestScore(), NgosStatus::ASSERTION);

            sDisplayedTest = (TestType)((u64)sDisplayedTest + 1);



            while (
                   sDisplayedTest < sCurrentTest
                   &&
                   cpuTests[(u64)sDisplayedTest]->isCompleted()
                  )
            {
                UEFI_ASSERT_EXECUTION(addTestEntry(), NgosStatus::ASSERTION);

                sDisplayedTest = (TestType)((u64)sDisplayedTest + 1);
            }



            if (sDisplayedTest < TestType::MAXIMUM)
            {
                UEFI_ASSERT_EXECUTION(addTestEntry(), NgosStatus::ASSERTION);
            }



            UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
        }



        if (sCurrentTest < TestType::MAXIMUM)
        {
            TestBase *test = cpuTests[(u64)sCurrentTest];

            if (sMpServices->startupThisAP(sMpServices, test->getProcedure(), processorId, sWaitEvents[sFirstProcessorEventIndex + processorId], 0, test, nullptr) == UefiStatus::SUCCESS)
            {
                UEFI_LV(("Test %s started on processor %u", enumToFullString(sCurrentTest), processorId));



                sCurrentTest = (TestType)((u64)sCurrentTest + 1);
            }
            else
            {
                UEFI_LF(("Failed to start test %s on processor %u", enumToFullString(sCurrentTest), processorId));

                --sNumberOfRunningProcessors;

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
        }
        else
        {
            --sNumberOfRunningProcessors;
        }
    }
    else
    {
        --sNumberOfRunningProcessors;
    }



    if (sNumberOfRunningProcessors == 0)
    {
        UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sStartButton->setContentImage(sStartImage), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sStartButton->setText("Start"),             NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



        if (!sTerminated)
        {
            u64 testTotal = 0;

            for (i64 i = 0; i < (i64)TestType::MAXIMUM; ++i)
            {
                testTotal += cpuTests[i]->getScore();
            }



            char8 *testTotalText = (char8 *)sTestTotalLabelWidget->getText();

            i64 testTotalTextLength = sprintf(testTotalText, "Total: %u", testTotal);
            AVOID_UNUSED(testTotalTextLength);

            UEFI_TEST_ASSERT(testTotalTextLength < TEST_TOTAL_TEXT_LENGTH, NgosStatus::ASSERTION);



            UEFI_ASSERT_EXECUTION(sTestTotalLabelWidget->setText(testTotalText), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestTotalLabelWidget->setVisible(true),       NgosStatus::ASSERTION);



            char8 *summaryTotalText = (char8 *)sSummaryTotalLabelWidget->getText();

            i64 summaryTotalTextLength = sprintf(summaryTotalText, "Total: %u", sSummaryTotal + testTotal);
            AVOID_UNUSED(summaryTotalTextLength);

            UEFI_TEST_ASSERT(summaryTotalTextLength < SUMMARY_TOTAL_TEXT_LENGTH, NgosStatus::ASSERTION);



            UEFI_ASSERT_EXECUTION(sSummaryTotalLabelWidget->setText(summaryTotalText), NgosStatus::ASSERTION);



            LabelWidget *previousTestLabelWidget = (LabelWidget *)sSummaryTableWidget->getCellWidget(0, COLUMN_SCORE);

            UEFI_ASSERT_EXECUTION(free((void *)previousTestLabelWidget->getText()),           NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(previousTestLabelWidget->setText(mprintf("%u", testTotal)), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onRebootButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus CpuTestGUI::onShutdownButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus CpuTestGUI::onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::DOWN:  return focusTabFirstWidget();
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sIssuesTabButton);

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

NgosStatus CpuTestGUI::onIssuesTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::DOWN:  return focusTabFirstWidget();
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sSystemInformationTabButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sTestTabButton);

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
        case UefiInputKeyScanCode::DOWN:  return focusTabFirstWidget();
        case UefiInputKeyScanCode::LEFT:  return GUI::setFocusedWidget(sIssuesTabButton);
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sSummaryTabButton);

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
        case UefiInputKeyScanCode::DOWN: return focusTabFirstWidget();
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sTestTabButton);

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

NgosStatus CpuTestGUI::onIssuesTableWidgetKeyboardEvent(const UefiInputKey &key)
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
        case UefiInputKeyScanCode::UP:   return sTestTableWidget->getSelectedRow() == 0                                   ? GUI::setFocusedWidget(sStartButton)  : NgosStatus::NO_EFFECT;
        case UefiInputKeyScanCode::DOWN: return sTestTableWidget->getSelectedRow() == sTestTableWidget->getRowCount() - 1 ? GUI::setFocusedWidget(sRebootButton) : NgosStatus::NO_EFFECT;

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

NgosStatus CpuTestGUI::onRebootButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(terminateAndWaitForApplicationProcessors(),                                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::COLD, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onShutdownButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(terminateAndWaitForApplicationProcessors(),                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(UEFI::resetSystem(UefiResetType::SHUTDOWN, UefiStatus::SUCCESS, 0, nullptr), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onSystemInformationTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SYSTEM_INFORMATION), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CpuTestGUI::onIssuesTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_ISSUES), NgosStatus::ASSERTION);



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
        if (sNumberOfRunningProcessors == 0)
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
                // TODO: Test on real hardware
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                {
                    UEFI_LVVV(("Processors:"));
                    UEFI_LVVV(("-------------------------------------"));

                    for (i64 i = 0; i < (i64)numberOfProcessors; ++i)
                    {
                        UefiProcessorInformation info;

                        UEFI_ASSERT_EXECUTION(sMpServices->getProcessorInfo(sMpServices, i, &info), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



                        UEFI_LVVV(("info[%d].processorId      = %u", i, info.processorId));
                        UEFI_LVVV(("info[%d].status           = %s", i, flagsToFullString(info.status)));
                        UEFI_LVVV(("info[%d].location.package = %u", i, info.location.package));
                        UEFI_LVVV(("info[%d].location.core    = %u", i, info.location.core));
                        UEFI_LVVV(("info[%d].location.thread  = %u", i, info.location.thread));



                        if (i < (i64)numberOfProcessors - 1)
                        {
                            UEFI_LVVV(("+++++++++++++++++++++++++++++++++++++"));
                        }
                    }

                    UEFI_LVVV(("-------------------------------------"));
                }
#endif



                for (i64 i = 0; i < (i64)TestType::MAXIMUM; ++i)
                {
                    UEFI_ASSERT_EXECUTION(cpuTests[i]->reset(), NgosStatus::ASSERTION);
                }



                sCurrentTest   = (TestType)0;
                sDisplayedTest = (TestType)0;
                sTerminated    = false;



                TestBase *test = cpuTests[0];

                for (i64 i = 0; i < (i64)numberOfProcessors; ++i)
                {
                    if (sMpServices->startupThisAP(sMpServices, test->getProcedure(), i, sWaitEvents[sFirstProcessorEventIndex + i], 0, test, nullptr) == UefiStatus::SUCCESS)
                    {
                        UEFI_LV(("Test %s started on processor %d", enumToFullString(sCurrentTest), i));

                        ++sNumberOfRunningProcessors;



                        sCurrentTest = (TestType)((u64)sCurrentTest + 1);

                        if (sCurrentTest >= TestType::MAXIMUM)
                        {
                            break;
                        }

                        test = cpuTests[(u64)sCurrentTest];
                    }
                }



                if (sNumberOfRunningProcessors > 0)
                {
                    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

                    UEFI_ASSERT_EXECUTION(sStartButton->setContentImage(sStopImage), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(sStartButton->setText("Stop "),            NgosStatus::ASSERTION);

                    UEFI_ASSERT_EXECUTION(sTestTableWidget->setRowCount(0), NgosStatus::ASSERTION);
                    UEFI_ASSERT_EXECUTION(addTestEntry(),                   NgosStatus::ASSERTION);

                    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
                }
                else
                {
                    UEFI_LE(("Failed to start task on any processor"));
                }
            }
            else
            {
                UEFI_LE(("Failed to start task on any application processor since there is only bootstrap processor"));
            }
        }
        else
        {
            if (!sTerminated)
            {
                sTerminated = true;

                UEFI_ASSERT_EXECUTION(addTestEntry("Terminated by user", ""), NgosStatus::ASSERTION);
            }
        }
    }
    else
    {
        UEFI_LE(("UEFI_MP_SERVICES_PROTOCOL not found")); // TODO: Try to do in single thread
    }



    return NgosStatus::OK;
}
