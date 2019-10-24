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

#define TABWIDGET_POSITION_X_PERCENT 2
#define TABWIDGET_POSITION_Y_PERCENT 0
#define TABWIDGET_WIDTH_PERCENT      96
#define TABWIDGET_HEIGHT_PERCENT     70

#define TAB_BUTTON_WIDTH_PERCENT   25
#define TAB_BUTTON_HEIGHT_PERCENT  7

#define CPU_IMAGE_POSITION_X_PERCENT 0
#define CPU_IMAGE_POSITION_Y_PERCENT 0
#define CPU_IMAGE_SIZE_PERCENT       20

#define CPU_MODEL_NAME_POSITION_X_PERCENT 1
#define CPU_MODEL_NAME_POSITION_Y_PERCENT 0
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
#define CPU_FAMILY_POSITION_Y_PERCENT 59
#define CPU_FAMILY_WIDTH_PERCENT      49
#define CPU_FAMILY_HEIGHT_PERCENT     20

#define CPU_MODEL_POSITION_X_PERCENT 50
#define CPU_MODEL_POSITION_Y_PERCENT 59
#define CPU_MODEL_WIDTH_PERCENT      49
#define CPU_MODEL_HEIGHT_PERCENT     20

#define CPU_STEPPING_POSITION_X_PERCENT 1
#define CPU_STEPPING_POSITION_Y_PERCENT 79
#define CPU_STEPPING_WIDTH_PERCENT      49
#define CPU_STEPPING_HEIGHT_PERCENT     20

#define CPU_REVISION_POSITION_X_PERCENT 50
#define CPU_REVISION_POSITION_Y_PERCENT 79
#define CPU_REVISION_WIDTH_PERCENT      49
#define CPU_REVISION_HEIGHT_PERCENT     20

#define FEATURE_PANEL_POSITION_X_PERCENT 2
#define FEATURE_PANEL_WIDTH_PERCENT      16
#define FEATURE_PANEL_HEIGHT_PERCENT     6

#define FEATURE_TEXT_POSITION_X_PERCENT 5
#define FEATURE_TEXT_POSITION_Y_PERCENT 5
#define FEATURE_TEXT_WIDTH_PERCENT      90
#define FEATURE_TEXT_HEIGHT_PERCENT     90

#define CPU_CLOCKS_PANEL_POSITION_X_PERCENT 0
#define CPU_CLOCKS_PANEL_WIDTH_PERCENT      49

#define CPU_CLOCKS_TEXT_POSITION_X_PERCENT 2
#define CPU_CLOCKS_TEXT_POSITION_Y_PERCENT 2
#define CPU_CLOCKS_TEXT_WIDTH_PERCENT      30
#define CPU_CLOCKS_TEXT_HEIGHT_PERCENT     15

#define CPU_CACHE_PANEL_POSITION_X_PERCENT 51
#define CPU_CACHE_PANEL_WIDTH_PERCENT      49

#define CPU_CACHE_TEXT_POSITION_X_PERCENT 2
#define CPU_CACHE_TEXT_POSITION_Y_PERCENT 2
#define CPU_CACHE_TEXT_WIDTH_PERCENT      30
#define CPU_CACHE_TEXT_HEIGHT_PERCENT     15

#define SYSTEM_BUTTON_SIZE_PERCENT 5
#define CURSOR_SIZE_PERCENT        2

#define TABWIDGET_PAGE_SYSTEM_INFORMATION 0
#define TABWIDGET_PAGE_TEST               1
#define TABWIDGET_PAGE_SUMMARY            2



Button     *CpuTestGUI::sRebootButton;
Button     *CpuTestGUI::sShutdownButton;
TabWidget  *CpuTestGUI::sTabWidget;
TabButton  *CpuTestGUI::sSystemInformationTabButton;
TabButton  *CpuTestGUI::sTestTabButton;
TabButton  *CpuTestGUI::sSummaryTabButton;
u16         CpuTestGUI::sWaitEventsCount;
uefi_event *CpuTestGUI::sWaitEvents;

X86Feature gTestedFeatures[] = {
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
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/reboot.png",                      &rebootImage),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/shutdown.png",                    &shutdownImage),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/cursor.png",                      &cursorImage),                  NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(params->screensCount > 0, NgosStatus::ASSERTION);

    u64 screenWidth  = params->screens[0]->mode->info->horizontalResolution;
    u64 screenHeight = params->screens[0]->mode->info->verticalResolution;



    u64 tabButtonWidth   = screenWidth  * TAB_BUTTON_WIDTH_PERCENT   / 100;
    u64 tabButtonHeight  = screenHeight * TAB_BUTTON_HEIGHT_PERCENT  / 100;
    u64 tabWidgetWidth   = screenWidth  * TABWIDGET_WIDTH_PERCENT    / 100;
    u64 tabWidgetHeight  = screenHeight * TABWIDGET_HEIGHT_PERCENT   / 100;
    u64 systemButtonSize = screenWidth  * SYSTEM_BUTTON_SIZE_PERCENT / 100;
    u64 cursorSize       = screenWidth  * CURSOR_SIZE_PERCENT        / 100;



    u64 tabPageWidth  = tabWidgetWidth;
    u64 tabPageHeight = tabWidgetHeight - tabButtonHeight;

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



    u64 cpuImageSize = tabPageWidth * CPU_IMAGE_SIZE_PERCENT / 100;



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

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(featurePanelImage, featurePanelWidth, featurePanelHeight, &featurePanelResizedImage), NgosStatus::ASSERTION);



    i64 flagsCount = ARRAY_COUNT(gTestedFeatures);
    COMMON_LVVV(("flagsCount = %d", flagsCount));

    for (i64 i = 0; i < flagsCount; ++i)
    {
        if (featurePanelPositionX + featurePanelWidth > tabPageWidth)
        {
            featurePanelPositionX =  featurePanelLeft;
            featurePanelPositionY += featurePanelHeight;
        }

        UEFI_ASSERT_EXECUTION(addFeaturePanel(gTestedFeatures[i], featurePanelPositionX, featurePanelPositionY, featurePanelWidth, featurePanelHeight, featurePanelImage, featurePanelResizedImage, systemInformationTabPageWidget), NgosStatus::ASSERTION);

        featurePanelPositionX += featurePanelWidth;
    }



    u64 cpuPanelPositionY = featurePanelPositionY + featurePanelHeight;
    u64 cpuPanelHeight    = tabPageHeight - cpuPanelPositionY;



    u64 cpuClocksWidth  = tabPageWidth  * CPU_CLOCKS_PANEL_WIDTH_PERCENT  / 100;
    u64 cpuClocksHeight = cpuPanelHeight;

    PanelWidget *cpuClocksPanelWidget = new PanelWidget(infoPanelImage, systemInformationTabPageWidget);

    UEFI_ASSERT_EXECUTION(cpuClocksPanelWidget->setPosition(tabPageWidth * CPU_CLOCKS_PANEL_POSITION_X_PERCENT / 100, cpuPanelPositionY), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuClocksPanelWidget->setSize(cpuClocksWidth, cpuClocksHeight),                                                 NgosStatus::ASSERTION);



    LabelWidget *cpuClocksLabelWidget = new LabelWidget("Clocks", cpuClocksPanelWidget);

    UEFI_ASSERT_EXECUTION(cpuClocksLabelWidget->setPosition(cpuClocksWidth * CPU_CLOCKS_TEXT_POSITION_X_PERCENT / 100, cpuClocksHeight * CPU_CLOCKS_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuClocksLabelWidget->setSize(cpuClocksWidth     * CPU_CLOCKS_TEXT_WIDTH_PERCENT      / 100, cpuClocksHeight * CPU_CLOCKS_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    u64 cpuCacheWidth  = tabPageWidth  * CPU_CACHE_PANEL_WIDTH_PERCENT  / 100;
    u64 cpuCacheHeight = cpuPanelHeight;

    PanelWidget *cpuCachePanelWidget = new PanelWidget(infoPanelImage, systemInformationTabPageWidget);

    UEFI_ASSERT_EXECUTION(cpuCachePanelWidget->setPosition(tabPageWidth * CPU_CACHE_PANEL_POSITION_X_PERCENT / 100, cpuPanelPositionY), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuCachePanelWidget->setSize(cpuCacheWidth, cpuCacheHeight),                                                  NgosStatus::ASSERTION);



    LabelWidget *cpuCacheLabelWidget = new LabelWidget("Cache ", cpuCachePanelWidget);

    UEFI_ASSERT_EXECUTION(cpuCacheLabelWidget->setPosition(cpuCacheWidth * CPU_CACHE_TEXT_POSITION_X_PERCENT / 100, cpuCacheHeight * CPU_CACHE_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(cpuCacheLabelWidget->setSize(cpuCacheWidth     * CPU_CACHE_TEXT_WIDTH_PERCENT      / 100, cpuCacheHeight * CPU_CACHE_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);



    TabPageWidget *testTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(testTabPageWidget), NgosStatus::ASSERTION);



    TabPageWidget *summaryTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(summaryTabPageWidget), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sTabWidget->setPosition(screenWidth * TABWIDGET_POSITION_X_PERCENT / 100, screenHeight * TABWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->setSize(tabWidgetWidth, tabWidgetHeight),                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTabWidget->setCurrentPage(TABWIDGET_PAGE_SYSTEM_INFORMATION),                                                                NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sSystemInformationTabButton), NgosStatus::ASSERTION);



    CursorWidget *cursorWidget = new CursorWidget(cursorImage, rootWidget);

    UEFI_ASSERT_EXECUTION(cursorWidget->setPosition(GUI::getFocusedWidget()->getGlobalPositionX() + (GUI::getFocusedWidget()->getWidth() >> 1), GUI::getFocusedWidget()->getGlobalPositionY() + (GUI::getFocusedWidget()->getHeight() >> 1)), NgosStatus::ASSERTION); // ">> 1" == "/ 2"
    UEFI_ASSERT_EXECUTION(cursorWidget->setSize(cursorSize, cursorSize),                                                                                                                                                                      NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::init(rootWidget, screenWidget, cursorWidget), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(),                              NgosStatus::ASSERTION);

    UEFI_TEST_ASSERT(GUI::isUpdatesEnabled(), NgosStatus::ASSERTION);



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
