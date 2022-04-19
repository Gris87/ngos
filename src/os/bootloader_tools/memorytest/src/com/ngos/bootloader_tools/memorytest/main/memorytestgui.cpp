#include "memorytestgui.h"

#include <com/ngos/bootloader_tools/memorytest/main/memorytest.h>
#include <com/ngos/bootloader_tools/memorytest/tests/testbase.h>
#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/dmi/dmi.h>
#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/gui/gui.h>
#include <com/ngos/shared/common/gui/widgets/misc/labelwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/panelwidget.h>
#include <com/ngos/shared/common/gui/widgets/special/rootwidget.h>
#include <com/ngos/shared/common/gui/widgets/special/screenwidget.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/uefibase/uefi/uefi.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>
#include <com/ngos/shared/uefibase/uefi/uefipointerdevices.h>



#define TABWIDGET_HEIGHT_PERCENT 70

#define TAB_BUTTON_WIDTH_PERCENT  15
#define TAB_BUTTON_HEIGHT_PERCENT 11

#define TAB_PAGE_PROPORTION 2.8

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
#define MEMORY_INFO_REGION_OVERRIDE_HEIGHT_PERCENT     83

#define MEMORY_INFO_LEFT_BUTTON_POSITION_X_PERCENT  0
#define MEMORY_INFO_RIGHT_BUTTON_POSITION_X_PERCENT 95
#define MEMORY_INFO_ARROW_BUTTON_SIZE_PERCENT       5

#define MEMORY_INFO_PAGE_INDICATOR_POSITION_Y_PERCENT 98
#define MEMORY_INFO_PAGE_INDICATOR_SIZE_PERCENT       2

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

#define SUMMARY_MEMORY_TEST_POSITION_X_PERCENT 0
#define SUMMARY_MEMORY_TEST_POSITION_Y_PERCENT 0
#define SUMMARY_MEMORY_TEST_WIDTH_PERCENT      100
#define SUMMARY_MEMORY_TEST_HEIGHT_PERCENT     10

#define TEST_MODE_TEXT_POSITION_X_PERCENT 1
#define TEST_MODE_TEXT_POSITION_Y_PERCENT 2
#define TEST_MODE_TEXT_WIDTH_PERCENT      15
#define TEST_MODE_TEXT_HEIGHT_PERCENT     96

#define TEST_MODE_BUTTON_POSITION_X_PERCENT 16
#define TEST_MODE_BUTTON_POSITION_Y_PERCENT 2
#define TEST_MODE_BUTTON_WIDTH_PERCENT      25
#define TEST_MODE_BUTTON_HEIGHT_PERCENT     96

#define TEST_ALL_BUTTON_POSITION_X_PERCENT 79
#define TEST_ALL_BUTTON_POSITION_Y_PERCENT 2
#define TEST_ALL_BUTTON_WIDTH_PERCENT      20
#define TEST_ALL_BUTTON_HEIGHT_PERCENT     96

#define MEMORY_TEST_REGION_POSITION_X_PERCENT 0
#define MEMORY_TEST_REGION_POSITION_Y_PERCENT 10
#define MEMORY_TEST_REGION_WIDTH_PERCENT      100
#define MEMORY_TEST_REGION_HEIGHT_PERCENT     90

#define MEMORY_TEST_REGION_OVERRIDE_POSITION_X_PERCENT 5
#define MEMORY_TEST_REGION_OVERRIDE_POSITION_Y_PERCENT 10
#define MEMORY_TEST_REGION_OVERRIDE_WIDTH_PERCENT      90
#define MEMORY_TEST_REGION_OVERRIDE_HEIGHT_PERCENT     88

#define MEMORY_TEST_LEFT_BUTTON_POSITION_X_PERCENT  0
#define MEMORY_TEST_RIGHT_BUTTON_POSITION_X_PERCENT 95
#define MEMORY_TEST_ARROW_BUTTON_SIZE_PERCENT       5

#define MEMORY_TEST_PAGE_INDICATOR_POSITION_Y_PERCENT 98
#define MEMORY_TEST_PAGE_INDICATOR_SIZE_PERCENT       2

#define MEMORY_TEST_IMAGE_POSITION_X_PERCENT 1
#define MEMORY_TEST_IMAGE_POSITION_Y_PERCENT 1
#define MEMORY_TEST_IMAGE_SIZE_PERCENT       98

#define MEMORY_TEST_DEVICE_LOCATOR_POSITION_X_PERCENT 2
#define MEMORY_TEST_DEVICE_LOCATOR_POSITION_Y_PERCENT 1
#define MEMORY_TEST_DEVICE_LOCATOR_WIDTH_PERCENT      97
#define MEMORY_TEST_DEVICE_LOCATOR_HEIGHT_PERCENT     14

#define MEMORY_TEST_MANUFACTURER_POSITION_X_PERCENT 2
#define MEMORY_TEST_MANUFACTURER_POSITION_Y_PERCENT 15
#define MEMORY_TEST_MANUFACTURER_WIDTH_PERCENT      97
#define MEMORY_TEST_MANUFACTURER_HEIGHT_PERCENT     14

#define MEMORY_TEST_SERIAL_NUMBER_POSITION_X_PERCENT 2
#define MEMORY_TEST_SERIAL_NUMBER_POSITION_Y_PERCENT 29
#define MEMORY_TEST_SERIAL_NUMBER_WIDTH_PERCENT      97
#define MEMORY_TEST_SERIAL_NUMBER_HEIGHT_PERCENT     14

#define MEMORY_TEST_PART_NUMBER_POSITION_X_PERCENT 2
#define MEMORY_TEST_PART_NUMBER_POSITION_Y_PERCENT 43
#define MEMORY_TEST_PART_NUMBER_WIDTH_PERCENT      97
#define MEMORY_TEST_PART_NUMBER_HEIGHT_PERCENT     14

#define MEMORY_TEST_SIZE_POSITION_X_PERCENT 2
#define MEMORY_TEST_SIZE_POSITION_Y_PERCENT 57
#define MEMORY_TEST_SIZE_WIDTH_PERCENT      97
#define MEMORY_TEST_SIZE_HEIGHT_PERCENT     14

#define MEMORY_TEST_START_BUTTON_POSITION_Y_PERCENT 71
#define MEMORY_TEST_START_BUTTON_HEIGHT_PERCENT     28
#define MEMORY_TEST_START_BUTTON_WIDTH_PROPORTION   4

#define TEST_STOP_BUTTON_POSITION_X_PERCENT 97
#define TEST_STOP_BUTTON_POSITION_Y_PERCENT 0
#define TEST_STOP_BUTTON_SIZE_PERCENT       3

#define TESTING_SIZE_POSITION_X_PERCENT 1
#define TESTING_SIZE_POSITION_Y_PERCENT 1
#define TESTING_SIZE_WIDTH_PERCENT      39
#define TESTING_SIZE_HEIGHT_PERCENT     5

#define TESTING_RANGE_POSITION_X_PERCENT 1
#define TESTING_RANGE_POSITION_Y_PERCENT 6
#define TESTING_RANGE_WIDTH_PERCENT      39
#define TESTING_RANGE_HEIGHT_PERCENT     5

#define TESTING_MODE_POSITION_X_PERCENT 1
#define TESTING_MODE_POSITION_Y_PERCENT 11
#define TESTING_MODE_WIDTH_PERCENT      39
#define TESTING_MODE_HEIGHT_PERCENT     5

#define TESTING_DEVICE_LOCATOR_POSITION_X_PERCENT 40
#define TESTING_DEVICE_LOCATOR_POSITION_Y_PERCENT 1
#define TESTING_DEVICE_LOCATOR_WIDTH_PERCENT      40
#define TESTING_DEVICE_LOCATOR_HEIGHT_PERCENT     5

#define TESTING_MANUFACTURER_POSITION_X_PERCENT 40
#define TESTING_MANUFACTURER_POSITION_Y_PERCENT 6
#define TESTING_MANUFACTURER_WIDTH_PERCENT      40
#define TESTING_MANUFACTURER_HEIGHT_PERCENT     5

#define TESTING_SERIAL_NUMBER_POSITION_X_PERCENT 40
#define TESTING_SERIAL_NUMBER_POSITION_Y_PERCENT 11
#define TESTING_SERIAL_NUMBER_WIDTH_PERCENT      40
#define TESTING_SERIAL_NUMBER_HEIGHT_PERCENT     5

#define TESTING_PART_NUMBER_POSITION_X_PERCENT 40
#define TESTING_PART_NUMBER_POSITION_Y_PERCENT 16
#define TESTING_PART_NUMBER_WIDTH_PERCENT      40
#define TESTING_PART_NUMBER_HEIGHT_PERCENT     5

#define TESTING_TOTAL_TEXT_POSITION_X_PERCENT 80
#define TESTING_TOTAL_TEXT_POSITION_Y_PERCENT 16
#define TESTING_TOTAL_TEXT_WIDTH_PERCENT      19
#define TESTING_TOTAL_TEXT_HEIGHT_PERCENT     5

#define TESTING_PANEL_POSITION_X_PERCENT 0
#define TESTING_PANEL_POSITION_Y_PERCENT 21
#define TESTING_PANEL_WIDTH_PERCENT      100
#define TESTING_PANEL_HEIGHT_PERCENT     79

#define TESTING_TABWIDGET_POSITION_X_PERCENT 0
#define TESTING_TABWIDGET_POSITION_Y_PERCENT 0
#define TESTING_TABWIDGET_WIDTH_PERCENT      100
#define TESTING_TABWIDGET_HEIGHT_PERCENT     100

#define TESTING_TAB_BUTTON_WIDTH_PERCENT  8
#define TESTING_TAB_BUTTON_HEIGHT_PERCENT 18

#define SEQUENTIAL_READ_TEXT_POSITION_X_PERCENT 0
#define SEQUENTIAL_READ_TEXT_POSITION_Y_PERCENT 2
#define SEQUENTIAL_READ_TEXT_WIDTH_PERCENT      45
#define SEQUENTIAL_READ_TEXT_HEIGHT_PERCENT     10

#define SEQUENTIAL_READ_AVERAGE_POSITION_X_PERCENT 45
#define SEQUENTIAL_READ_AVERAGE_POSITION_Y_PERCENT 4
#define SEQUENTIAL_READ_AVERAGE_WIDTH_PERCENT      20
#define SEQUENTIAL_READ_AVERAGE_HEIGHT_PERCENT     8

#define SEQUENTIAL_READ_MAXIMUM_POSITION_X_PERCENT 65
#define SEQUENTIAL_READ_MAXIMUM_POSITION_Y_PERCENT 4
#define SEQUENTIAL_READ_MAXIMUM_WIDTH_PERCENT      20
#define SEQUENTIAL_READ_MAXIMUM_HEIGHT_PERCENT     8

#define SEQUENTIAL_READ_PROGRESS_POSITION_X_PERCENT 85
#define SEQUENTIAL_READ_PROGRESS_POSITION_Y_PERCENT 4
#define SEQUENTIAL_READ_PROGRESS_WIDTH_PERCENT      15
#define SEQUENTIAL_READ_PROGRESS_HEIGHT_PERCENT     8

#define SEQUENTIAL_READ_PROGRESSBAR_POSITION_X_PERCENT 0
#define SEQUENTIAL_READ_PROGRESSBAR_POSITION_Y_PERCENT 15
#define SEQUENTIAL_READ_PROGRESSBAR_WIDTH_PERCENT      100
#define SEQUENTIAL_READ_PROGRESSBAR_HEIGHT_PERCENT     10

#define SEQUENTIAL_WRITE_TEXT_POSITION_X_PERCENT 0
#define SEQUENTIAL_WRITE_TEXT_POSITION_Y_PERCENT 27
#define SEQUENTIAL_WRITE_TEXT_WIDTH_PERCENT      45
#define SEQUENTIAL_WRITE_TEXT_HEIGHT_PERCENT     10

#define SEQUENTIAL_WRITE_AVERAGE_POSITION_X_PERCENT 45
#define SEQUENTIAL_WRITE_AVERAGE_POSITION_Y_PERCENT 29
#define SEQUENTIAL_WRITE_AVERAGE_WIDTH_PERCENT      20
#define SEQUENTIAL_WRITE_AVERAGE_HEIGHT_PERCENT     8

#define SEQUENTIAL_WRITE_MAXIMUM_POSITION_X_PERCENT 65
#define SEQUENTIAL_WRITE_MAXIMUM_POSITION_Y_PERCENT 29
#define SEQUENTIAL_WRITE_MAXIMUM_WIDTH_PERCENT      20
#define SEQUENTIAL_WRITE_MAXIMUM_HEIGHT_PERCENT     8

#define SEQUENTIAL_WRITE_PROGRESS_POSITION_X_PERCENT 85
#define SEQUENTIAL_WRITE_PROGRESS_POSITION_Y_PERCENT 29
#define SEQUENTIAL_WRITE_PROGRESS_WIDTH_PERCENT      15
#define SEQUENTIAL_WRITE_PROGRESS_HEIGHT_PERCENT     8

#define SEQUENTIAL_WRITE_PROGRESSBAR_POSITION_X_PERCENT 0
#define SEQUENTIAL_WRITE_PROGRESSBAR_POSITION_Y_PERCENT 40
#define SEQUENTIAL_WRITE_PROGRESSBAR_WIDTH_PERCENT      100
#define SEQUENTIAL_WRITE_PROGRESSBAR_HEIGHT_PERCENT     10

#define RANDOM_READ_TEXT_POSITION_X_PERCENT 0
#define RANDOM_READ_TEXT_POSITION_Y_PERCENT 52
#define RANDOM_READ_TEXT_WIDTH_PERCENT      45
#define RANDOM_READ_TEXT_HEIGHT_PERCENT     10

#define RANDOM_READ_AVERAGE_POSITION_X_PERCENT 45
#define RANDOM_READ_AVERAGE_POSITION_Y_PERCENT 54
#define RANDOM_READ_AVERAGE_WIDTH_PERCENT      20
#define RANDOM_READ_AVERAGE_HEIGHT_PERCENT     8

#define RANDOM_READ_MAXIMUM_POSITION_X_PERCENT 65
#define RANDOM_READ_MAXIMUM_POSITION_Y_PERCENT 54
#define RANDOM_READ_MAXIMUM_WIDTH_PERCENT      20
#define RANDOM_READ_MAXIMUM_HEIGHT_PERCENT     8

#define RANDOM_READ_PROGRESS_POSITION_X_PERCENT 85
#define RANDOM_READ_PROGRESS_POSITION_Y_PERCENT 54
#define RANDOM_READ_PROGRESS_WIDTH_PERCENT      15
#define RANDOM_READ_PROGRESS_HEIGHT_PERCENT     8

#define RANDOM_READ_PROGRESSBAR_POSITION_X_PERCENT 0
#define RANDOM_READ_PROGRESSBAR_POSITION_Y_PERCENT 65
#define RANDOM_READ_PROGRESSBAR_WIDTH_PERCENT      100
#define RANDOM_READ_PROGRESSBAR_HEIGHT_PERCENT     10

#define RANDOM_WRITE_TEXT_POSITION_X_PERCENT 0
#define RANDOM_WRITE_TEXT_POSITION_Y_PERCENT 77
#define RANDOM_WRITE_TEXT_WIDTH_PERCENT      45
#define RANDOM_WRITE_TEXT_HEIGHT_PERCENT     10

#define RANDOM_WRITE_AVERAGE_POSITION_X_PERCENT 45
#define RANDOM_WRITE_AVERAGE_POSITION_Y_PERCENT 79
#define RANDOM_WRITE_AVERAGE_WIDTH_PERCENT      20
#define RANDOM_WRITE_AVERAGE_HEIGHT_PERCENT     8

#define RANDOM_WRITE_MAXIMUM_POSITION_X_PERCENT 65
#define RANDOM_WRITE_MAXIMUM_POSITION_Y_PERCENT 79
#define RANDOM_WRITE_MAXIMUM_WIDTH_PERCENT      20
#define RANDOM_WRITE_MAXIMUM_HEIGHT_PERCENT     8

#define RANDOM_WRITE_PROGRESS_POSITION_X_PERCENT 85
#define RANDOM_WRITE_PROGRESS_POSITION_Y_PERCENT 79
#define RANDOM_WRITE_PROGRESS_WIDTH_PERCENT      15
#define RANDOM_WRITE_PROGRESS_HEIGHT_PERCENT     8

#define RANDOM_WRITE_PROGRESSBAR_POSITION_X_PERCENT 0
#define RANDOM_WRITE_PROGRESSBAR_POSITION_Y_PERCENT 90
#define RANDOM_WRITE_PROGRESSBAR_WIDTH_PERCENT      100
#define RANDOM_WRITE_PROGRESSBAR_HEIGHT_PERCENT     10

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

#define TESTING_TABWIDGET_PAGE_LIST  0
#define TESTING_TABWIDGET_PAGE_CHART 1

#define COLUMN_NAME  0
#define COLUMN_SCORE 1

#define COLUMN_ICON        0
#define COLUMN_DESCRIPTION 1

#define SCORE_PER_1GB_RAM  125
#define SCORE_PER_100_MHZ  40
#define SCORE_DUAL_CHANNEL 500

#define BLACK_COLOR    0xFF000000
#define DISABLED_COLOR 0xFFB2B2B2

#define TEST_TOTAL_TEXT_LENGTH    14
#define AVERAGE_TEXT_LENGTH       18
#define MAXIMUM_TEXT_LENGTH       18
#define PROGRESS_TEXT_LENGTH      24
#define SUMMARY_TOTAL_TEXT_LENGTH 14

#define QUICK_TEST_SIZE (1 * GB)



Button                                *MemoryTestGUI::sRebootButton;
Button                                *MemoryTestGUI::sShutdownButton;
TabWidget                             *MemoryTestGUI::sTabWidget;
TabButton                             *MemoryTestGUI::sSystemInformationTabButton;
TabButton                             *MemoryTestGUI::sIssuesTabButton;
TabButton                             *MemoryTestGUI::sTestTabButton;
TabButton                             *MemoryTestGUI::sSummaryTabButton;
ArrayList<ArrayList<PanelWidget *> *>  MemoryTestGUI::sInfoPages;
ArrayList<ImageWidget *>               MemoryTestGUI::sInfoPageIndicators;
Image                                 *MemoryTestGUI::sInfoPageIndicatorResizedImage;
Image                                 *MemoryTestGUI::sInfoPageIndicatorSelectedResizedImage;
i64                                    MemoryTestGUI::sInfoCurrentPage;
Button                                *MemoryTestGUI::sInfoLeftButton;
Button                                *MemoryTestGUI::sInfoRightButton;
Image                                 *MemoryTestGUI::sWarningImage;
Image                                 *MemoryTestGUI::sCriticalImage;
TableWidget                           *MemoryTestGUI::sIssuesTableWidget;
WrapperWidget                         *MemoryTestGUI::sTestSettingsWrapperWidget;
Button                                *MemoryTestGUI::sTestModeButton;
Button                                *MemoryTestGUI::sTestAllButton;
ArrayList<ArrayList<PanelWidget *> *>  MemoryTestGUI::sTestPages;
ArrayList<ArrayList<Widget *> *>       MemoryTestGUI::sTestButtonPages;
ArrayList<ImageWidget *>               MemoryTestGUI::sTestPageIndicators;
Image                                 *MemoryTestGUI::sTestPageIndicatorResizedImage;
Image                                 *MemoryTestGUI::sTestPageIndicatorSelectedResizedImage;
i64                                    MemoryTestGUI::sTestCurrentPage;
Button                                *MemoryTestGUI::sTestLeftButton;
Button                                *MemoryTestGUI::sTestRightButton;
WrapperWidget                         *MemoryTestGUI::sTestRunningWrapperWidget;
Image                                 *MemoryTestGUI::sStopImage;
Image                                 *MemoryTestGUI::sCloseImage;
Button                                *MemoryTestGUI::sTestStopButton;
Widget                                *MemoryTestGUI::sLastFocusedWidget;
LabelWidget                           *MemoryTestGUI::sTestingSizeLabelWidget;
LabelWidget                           *MemoryTestGUI::sTestingRangeLabelWidget;
LabelWidget                           *MemoryTestGUI::sTestingModeLabelWidget;
LabelWidget                           *MemoryTestGUI::sTestingDeviceLocatorLabelWidget;
LabelWidget                           *MemoryTestGUI::sTestingManufacturerLabelWidget;
LabelWidget                           *MemoryTestGUI::sTestingSerialNumberLabelWidget;
LabelWidget                           *MemoryTestGUI::sTestingPartNumberLabelWidget;
LabelWidget                           *MemoryTestGUI::sTestingTotalLabelWidget;
TabWidget                             *MemoryTestGUI::sTestingTabWidget;
TabButton                             *MemoryTestGUI::sListTabButton;
TabButton                             *MemoryTestGUI::sChartTabButton;
LabelWidget*                           MemoryTestGUI::sAverageLabelWidgets[(enum_t)TestType::MAXIMUM];
LabelWidget*                           MemoryTestGUI::sMaximumLabelWidgets[(enum_t)TestType::MAXIMUM];
LabelWidget*                           MemoryTestGUI::sProgressLabelWidgets[(enum_t)TestType::MAXIMUM];
ProgressBarWidget*                     MemoryTestGUI::sProgressBarWidgets[(enum_t)TestType::MAXIMUM];
LabelWidget                           *MemoryTestGUI::sSummaryTotalLabelWidget;
TableWidget                           *MemoryTestGUI::sSummaryTableWidget;
i64                                    MemoryTestGUI::sSummaryTotal;
UefiMpServicesProtocol                *MemoryTestGUI::sMpServices;
u16                                    MemoryTestGUI::sWaitEventsCount;
uefi_event                            *MemoryTestGUI::sWaitEvents;
uefi_event                             MemoryTestGUI::sTimerEvent;
u16                                    MemoryTestGUI::sFirstProcessorEventIndex;
TestType                               MemoryTestGUI::sCurrentTest;
i64                                    MemoryTestGUI::sNumberOfRunningProcessors;
bool                                   MemoryTestGUI::sTerminated;
TestType                              *MemoryTestGUI::sProcessorTasks;
TestMode                               MemoryTestGUI::sMode;
Image*                                 MemoryTestGUI::sModeImages[(enum_t)TestMode::MAXIMUM];



const char8* MemoryTestGUI::sModeImagesPath[(enum_t)TestMode::MAXIMUM] =
{
    "images/quick_test.png",    // TestMode::QUICK_TEST
    "images/full_test.png"      // TestMode::FULL_TEST
};



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
    Image *summaryInfoPanelImage;
    Image *memoryInfoPanelImage;
    Image *memoryInfoPanelResizedImage;
    Image *summaryTestPanelImage;
    Image *memoryTestPanelImage;
    Image *memoryTestPanelResizedImage;
    Image *memoryDeviceImage;
    Image *memoryDeviceResizedImage;
    Image *memoryDeviceDisabledImage;
    Image *memoryDeviceDisabledResizedImage;
    Image *arrowLeftImage;
    Image *arrowRightImage;
    Image *pageIndicatorImage;
    Image *pageIndicatorSelectedImage;
    Image *startImage;
    Image *startResizedImage;
    Image *testPanelImage;
    Image *listImage;
    Image *chartImage;
    Image *progressbarBackgroundImage;
    Image *progressbarIndicatorImage;
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
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/summary_info_panel.9.png",        &summaryInfoPanelImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/memory_info_panel.9.png",         &memoryInfoPanelImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/summary_test_panel.9.png",        &summaryTestPanelImage),        NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/memory_test_panel.9.png",         &memoryTestPanelImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/memory_device.png",               &memoryDeviceImage),            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/start.png",                       &startImage),                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/test_panel.9.png",                &testPanelImage),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/list.png",                        &listImage),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/chart.png",                       &chartImage),                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/progressbar_background.9.png",    &progressbarBackgroundImage),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/progressbar_indicator.9.png",     &progressbarIndicatorImage),    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/table_background.9.png",          &tableBackgroundImage),         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/table_header.9.png",              &tableHeaderImage),             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/reboot.png",                      &rebootImage),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/shutdown.png",                    &shutdownImage),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/cursor.png",                      &cursorImage),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/warning.png",                     &sWarningImage),                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/critical.png",                    &sCriticalImage),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/stop.png",                        &sStopImage),                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/close.png",                       &sCloseImage),                  NgosStatus::ASSERTION);

    for (good_I64 i = 0; i < (i64)TestMode::MAXIMUM; ++i)
    {
        UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets(sModeImagesPath[i], &sModeImages[i]), NgosStatus::ASSERTION);
    }



    UEFI_TEST_ASSERT(params->screensCount > 0, NgosStatus::ASSERTION);

    i64 screenWidth  = params->screens[0]->mode->info->horizontalResolution;
    i64 screenHeight = params->screens[0]->mode->info->verticalResolution;



    RootWidget *rootWidget = new RootWidget();

    UEFI_ASSERT_EXECUTION(rootWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(rootWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    ScreenWidget *screenWidget = new ScreenWidget(backgroundImage, params->screens[0], rootWidget);

    UEFI_ASSERT_EXECUTION(screenWidget->setPosition(0, 0),                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(screenWidget->setSize(screenWidth, screenHeight), NgosStatus::ASSERTION);



    i64 allowedWidthForSystemButtons   = screenWidth  * (100 - (GRAPHICAL_CONSOLE_POSITION_X_PERCENT + GRAPHICAL_CONSOLE_WIDTH_PERCENT)) / 100;
    i64 allowedHeighthForSystemButtons = screenHeight * GRAPHICAL_CONSOLE_HEIGHT_PERCENT                                                 / 100 - allowedWidthForSystemButtons * SYSTEM_BUTTON_RESERVED_PROPORTION;

    i64 systemButtonSize = allowedHeighthForSystemButtons / 2;

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
    i64 tabWidgetHeight = screenHeight    * TABWIDGET_HEIGHT_PERCENT  / 100;
    i64 tabButtonHeight = tabWidgetHeight * TAB_BUTTON_HEIGHT_PERCENT / 100;
    i64 tabPageHeight   = tabWidgetHeight - tabButtonHeight;
    // Ignore CppAlignmentVerifier [END]



    i64 tabPageWidth = tabPageHeight * TAB_PAGE_PROPORTION;

    if (tabPageWidth > screenWidth)
    {
        tabPageWidth    = screenWidth;
        tabPageHeight   = tabPageWidth / TAB_PAGE_PROPORTION;
        tabWidgetHeight = tabPageHeight + tabButtonHeight;
    }



    i64 tabWidgetWidth = tabPageWidth;
    i64 tabButtonWidth = tabWidgetWidth * TAB_BUTTON_WIDTH_PERCENT / 100;

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



    i64 summaryMemoryInfoWidth  = tabPageWidth  * SUMMARY_MEMORY_INFO_WIDTH_PERCENT  / 100;
    i64 summaryMemoryInfoHeight = tabPageHeight * SUMMARY_MEMORY_INFO_HEIGHT_PERCENT / 100;



    PanelWidget *summaryMemoryInfoPanelWidget = new PanelWidget(summaryInfoPanelImage, systemInformationTabPageWidget);

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



    i64 memoryInfoRegionPositionX;
    i64 memoryInfoRegionPositionY;
    i64 memoryInfoRegionWidth;
    i64 memoryInfoRegionHeight;

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



    i64 memoryInfoPanelHeight = memoryInfoRegionHeight / 2;
    i64 memoryInfoImageSize   = memoryInfoPanelHeight * MEMORY_INFO_IMAGE_SIZE_PERCENT / 100;



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryDeviceImage, memoryInfoImageSize, memoryInfoImageSize, &memoryDeviceResizedImage), NgosStatus::ASSERTION);

    if (memoryDevices.getSize() > (i64)DMI::getNumberOfInstalledMemoryDevices())
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
        i64 memoryInfoPanelWidth = memoryInfoRegionWidth / 2;

        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryInfoPanelImage, memoryInfoPanelWidth, memoryInfoPanelHeight, &memoryInfoPanelResizedImage), NgosStatus::ASSERTION);



        for (good_I64 i = 0; i < (i64)memoryDevices.getSize(); ++i)
        {
            UEFI_ASSERT_EXECUTION(addMemoryInfoPanel(i / 4, memoryInfoRegionPositionX + (i % 2) * memoryInfoPanelWidth, memoryInfoRegionPositionY + ((i >> 1) % 2) * memoryInfoPanelHeight, memoryInfoPanelWidth, memoryInfoPanelHeight, memoryInfoPanelImage, memoryInfoPanelResizedImage, memoryDeviceImage, memoryDeviceResizedImage, memoryDeviceDisabledImage, memoryDeviceDisabledResizedImage, systemInformationTabPageWidget, memoryDevices.at(i)), NgosStatus::ASSERTION);
        }



        if (sInfoPages.getSize() > 1)
        {
            UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/arrow_left.png",              &arrowLeftImage),             NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/arrow_right.png",             &arrowRightImage),            NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/page_indicator.png",          &pageIndicatorImage),         NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::loadImageFromAssets("images/page_indicator_selected.png", &pageIndicatorSelectedImage), NgosStatus::ASSERTION);



            i64 arrowButtonSize   = tabPageWidth  * MEMORY_INFO_ARROW_BUTTON_SIZE_PERCENT   / 100;
            i64 pageIndicatorSize = tabPageHeight * MEMORY_INFO_PAGE_INDICATOR_SIZE_PERCENT / 100;



            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonNormalImage,          arrowButtonSize,   arrowButtonSize,   &buttonNormalResizedImage),               NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonHoverImage,           arrowButtonSize,   arrowButtonSize,   &buttonHoverResizedImage),                NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonPressedImage,         arrowButtonSize,   arrowButtonSize,   &buttonPressedResizedImage),              NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedImage,         arrowButtonSize,   arrowButtonSize,   &buttonFocusedResizedImage),              NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedHoverImage,    arrowButtonSize,   arrowButtonSize,   &buttonFocusedHoverResizedImage),         NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(pageIndicatorImage,         pageIndicatorSize, pageIndicatorSize, &sInfoPageIndicatorResizedImage),         NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(pageIndicatorSelectedImage, pageIndicatorSize, pageIndicatorSize, &sInfoPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



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



            i64 pageIndicatorPosX = (tabPageWidth - pageIndicatorSize * sInfoPages.getSize()) / 2;
            i64 pageIndicatorPosY = tabPageHeight * MEMORY_INFO_PAGE_INDICATOR_POSITION_Y_PERCENT / 100;



            for (good_I64 i = 0; i < (i64)sInfoPages.getSize(); ++i)
            {
                ImageWidget *pageIndicatorImageWidget;

                if (i == 0)
                {
                    pageIndicatorImageWidget = new ImageWidget(pageIndicatorSelectedImage, sInfoPageIndicatorSelectedResizedImage, systemInformationTabPageWidget);
                }
                else
                {
                    pageIndicatorImageWidget = new ImageWidget(pageIndicatorImage, sInfoPageIndicatorResizedImage, systemInformationTabPageWidget);
                }

                UEFI_ASSERT_EXECUTION(pageIndicatorImageWidget->setPosition(pageIndicatorPosX + i * pageIndicatorSize, pageIndicatorPosY), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(pageIndicatorImageWidget->setSize(pageIndicatorSize, pageIndicatorSize),                             NgosStatus::ASSERTION);



                UEFI_ASSERT_EXECUTION(sInfoPageIndicators.append(pageIndicatorImageWidget), NgosStatus::ASSERTION);
            }
        }
    }
    else
    {
        i64 memoryInfoPanelWidth = memoryInfoRegionWidth;

        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryInfoPanelImage, memoryInfoPanelWidth, memoryInfoPanelHeight, &memoryInfoPanelResizedImage), NgosStatus::ASSERTION);



        for (good_I64 i = 0; i < (i64)memoryDevices.getSize(); ++i)
        {
            UEFI_ASSERT_EXECUTION(addMemoryInfoPanel(0, memoryInfoRegionPositionX, memoryInfoRegionPositionY + i * memoryInfoPanelHeight, memoryInfoPanelWidth, memoryInfoPanelHeight, memoryInfoPanelImage, memoryInfoPanelResizedImage, memoryDeviceImage, memoryDeviceResizedImage, memoryDeviceDisabledImage, memoryDeviceDisabledResizedImage, systemInformationTabPageWidget, memoryDevices.at(i)), NgosStatus::ASSERTION);
        }
    }



    TabPageWidget *issuesTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(issuesTabPageWidget), NgosStatus::ASSERTION);



    i64 issuesTableWidth  = tabPageWidth  * ISSUES_TABLEWIDGET_WIDTH_PERCENT  / 100;
    i64 issuesTableHeight = tabPageHeight * ISSUES_TABLEWIDGET_HEIGHT_PERCENT / 100;



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



    sTestSettingsWrapperWidget = new WrapperWidget(testTabPageWidget);

    UEFI_ASSERT_EXECUTION(sTestSettingsWrapperWidget->setPosition(0, 0),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestSettingsWrapperWidget->setSize(tabPageWidth, tabPageHeight), NgosStatus::ASSERTION);



    i64 summaryMemoryTestWidth  = tabPageWidth  * SUMMARY_MEMORY_TEST_WIDTH_PERCENT  / 100;
    i64 summaryMemoryTestHeight = tabPageHeight * SUMMARY_MEMORY_TEST_HEIGHT_PERCENT / 100;



    RgbaPixel blackColor(BLACK_COLOR);



    PanelWidget *summaryMemoryTestPanelWidget = new PanelWidget(summaryTestPanelImage, sTestSettingsWrapperWidget);

    UEFI_ASSERT_EXECUTION(summaryMemoryTestPanelWidget->setPosition(tabPageWidth * SUMMARY_MEMORY_TEST_POSITION_X_PERCENT / 100, tabPageHeight * SUMMARY_MEMORY_TEST_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(summaryMemoryTestPanelWidget->setSize(summaryMemoryTestWidth, summaryMemoryTestHeight),                                                                               NgosStatus::ASSERTION);



    LabelWidget *testModeLabelWidget = new LabelWidget("Test mode:", summaryMemoryTestPanelWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(testModeLabelWidget->setColor(blackColor),                                                                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(testModeLabelWidget->setPosition(summaryMemoryTestWidth * TEST_MODE_TEXT_POSITION_X_PERCENT / 100, summaryMemoryTestHeight * TEST_MODE_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(testModeLabelWidget->setSize(summaryMemoryTestWidth     * TEST_MODE_TEXT_WIDTH_PERCENT      / 100, summaryMemoryTestHeight * TEST_MODE_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    sMode = TestMode::QUICK_TEST;

    sTestModeButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, sModeImages[(enum_t)sMode], nullptr, enumToHumanString(sMode), summaryMemoryTestPanelWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestModeButton->setColor(blackColor),                                                                                                                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestModeButton->setPosition(summaryMemoryTestWidth * TEST_MODE_BUTTON_POSITION_X_PERCENT / 100, summaryMemoryTestHeight * TEST_MODE_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestModeButton->setSize(summaryMemoryTestWidth     * TEST_MODE_BUTTON_WIDTH_PERCENT      / 100, summaryMemoryTestHeight * TEST_MODE_BUTTON_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestModeButton->setKeyboardEventHandler(onTestModeButtonKeyboardEvent),                                                                                               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestModeButton->setPressEventHandler(onTestModeButtonPressed),                                                                                                        NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    if (DMI::getNumberOfInstalledMemoryDevices() > 1)
    {
        sTestAllButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, startImage, nullptr, "Test all", summaryMemoryTestPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(sTestAllButton->setColor(blackColor),                                                                                                                               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestAllButton->setPosition(summaryMemoryTestWidth * TEST_ALL_BUTTON_POSITION_X_PERCENT / 100, summaryMemoryTestHeight * TEST_ALL_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestAllButton->setSize(summaryMemoryTestWidth     * TEST_ALL_BUTTON_WIDTH_PERCENT      / 100, summaryMemoryTestHeight * TEST_ALL_BUTTON_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestAllButton->setKeyboardEventHandler(onTestAllButtonKeyboardEvent),                                                                                              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestAllButton->setPressEventHandler(onTestAllButtonPressed),                                                                                                       NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
    }



    i64 memoryTestRegionPositionX;
    i64 memoryTestRegionPositionY;
    i64 memoryTestRegionWidth;
    i64 memoryTestRegionHeight;

    if (DMI::getNumberOfInstalledMemoryDevices() > 4)
    {
        memoryTestRegionPositionX = tabPageWidth  * MEMORY_TEST_REGION_OVERRIDE_POSITION_X_PERCENT / 100;
        memoryTestRegionPositionY = tabPageHeight * MEMORY_TEST_REGION_OVERRIDE_POSITION_Y_PERCENT / 100;
        memoryTestRegionWidth     = tabPageWidth  * MEMORY_TEST_REGION_OVERRIDE_WIDTH_PERCENT      / 100;
        memoryTestRegionHeight    = tabPageHeight * MEMORY_TEST_REGION_OVERRIDE_HEIGHT_PERCENT     / 100;
    }
    else
    {
        memoryTestRegionPositionX = tabPageWidth  * MEMORY_TEST_REGION_POSITION_X_PERCENT / 100;
        memoryTestRegionPositionY = tabPageHeight * MEMORY_TEST_REGION_POSITION_Y_PERCENT / 100;
        memoryTestRegionWidth     = tabPageWidth  * MEMORY_TEST_REGION_WIDTH_PERCENT      / 100;
        memoryTestRegionHeight    = tabPageHeight * MEMORY_TEST_REGION_HEIGHT_PERCENT     / 100;
    }



    i64 memoryTestPanelHeight       = memoryTestRegionHeight / 2;
    i64 memoryTestImageSize         = memoryTestPanelHeight * MEMORY_TEST_IMAGE_SIZE_PERCENT / 100;
    i64 memoryTestStartButtonHeight = memoryTestPanelHeight * MEMORY_TEST_START_BUTTON_HEIGHT_PERCENT / 100;
    i64 memoryTestStartButtonWidth  = memoryTestStartButtonHeight * MEMORY_TEST_START_BUTTON_WIDTH_PROPORTION;
    i64 memoryTestStartImageSize    = memoryTestStartButtonHeight;



    patch = buttonNormalImage->getNinePatch();

    if (patch)
    {
        memoryTestStartImageSize -= patch->getPaddingTop() + patch->getPaddingBottom();
    }



    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryDeviceImage, memoryTestImageSize,      memoryTestImageSize,      &memoryDeviceResizedImage), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(Graphics::resizeImage(startImage,        memoryTestStartImageSize, memoryTestStartImageSize, &startResizedImage),        NgosStatus::ASSERTION);



    if (DMI::getNumberOfInstalledMemoryDevices() > 2)
    {
        i64 memoryTestPanelWidth = memoryTestRegionWidth / 2;

        if (memoryTestStartButtonWidth > memoryTestPanelWidth - memoryTestImageSize)
        {
            memoryTestStartButtonWidth = memoryTestPanelWidth - memoryTestImageSize;
        }



        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryTestPanelImage,    memoryTestPanelWidth,       memoryTestPanelHeight,       &memoryTestPanelResizedImage),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonNormalImage,       memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonHoverImage,        memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonPressedImage,      memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedImage,      memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedHoverImage, memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



        for (good_I64 i = 0; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
        {
            UEFI_ASSERT_EXECUTION(addMemoryTestPanel(i / 4, memoryTestRegionPositionX + (i % 2) * memoryTestPanelWidth, memoryTestRegionPositionY + ((i >> 1) % 2) * memoryTestPanelHeight, memoryTestPanelWidth, memoryTestPanelHeight, memoryTestPanelImage, memoryTestPanelResizedImage, memoryDeviceImage, memoryDeviceResizedImage, buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, startImage, startResizedImage, memoryTestStartButtonWidth, memoryTestStartButtonHeight, memoryDevices.at(i)), NgosStatus::ASSERTION);
        }



        if (sTestPages.getSize() > 1)
        {
            i64 arrowButtonSize   = tabPageWidth  * MEMORY_TEST_ARROW_BUTTON_SIZE_PERCENT   / 100;
            i64 pageIndicatorSize = tabPageHeight * MEMORY_TEST_PAGE_INDICATOR_SIZE_PERCENT / 100;



            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonNormalImage,          arrowButtonSize,   arrowButtonSize,   &buttonNormalResizedImage),               NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonHoverImage,           arrowButtonSize,   arrowButtonSize,   &buttonHoverResizedImage),                NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonPressedImage,         arrowButtonSize,   arrowButtonSize,   &buttonPressedResizedImage),              NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedImage,         arrowButtonSize,   arrowButtonSize,   &buttonFocusedResizedImage),              NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedHoverImage,    arrowButtonSize,   arrowButtonSize,   &buttonFocusedHoverResizedImage),         NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(pageIndicatorImage,         pageIndicatorSize, pageIndicatorSize, &sTestPageIndicatorResizedImage),         NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(Graphics::resizeImage(pageIndicatorSelectedImage, pageIndicatorSize, pageIndicatorSize, &sTestPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



            sTestLeftButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, arrowLeftImage, nullptr, "", sTestSettingsWrapperWidget);

            UEFI_ASSERT_EXECUTION(sTestLeftButton->setVisible(false),                                                                                                                                        NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestLeftButton->setPosition(tabPageWidth * MEMORY_TEST_LEFT_BUTTON_POSITION_X_PERCENT / 100, memoryTestRegionPositionY + (memoryTestRegionHeight - arrowButtonSize) / 2), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestLeftButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                                NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestLeftButton->setKeyboardEventHandler(onTestLeftButtonKeyboardEvent),                                                                                                   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestLeftButton->setPressEventHandler(onTestLeftButtonPressed),                                                                                                            NgosStatus::ASSERTION);



            sTestRightButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, arrowRightImage, nullptr, "", sTestSettingsWrapperWidget);

            UEFI_ASSERT_EXECUTION(sTestRightButton->setPosition(tabPageWidth * MEMORY_TEST_RIGHT_BUTTON_POSITION_X_PERCENT / 100, memoryTestRegionPositionY + (memoryTestRegionHeight - arrowButtonSize) / 2), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestRightButton->setSize(arrowButtonSize, arrowButtonSize),                                                                                                                 NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestRightButton->setKeyboardEventHandler(onTestRightButtonKeyboardEvent),                                                                                                   NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestRightButton->setPressEventHandler(onTestRightButtonPressed),                                                                                                            NgosStatus::ASSERTION);



            i64 pageIndicatorPosX = (tabPageWidth - pageIndicatorSize * sTestPages.getSize()) / 2;
            i64 pageIndicatorPosY = tabPageHeight * MEMORY_TEST_PAGE_INDICATOR_POSITION_Y_PERCENT / 100;



            for (good_I64 i = 0; i < (i64)sTestPages.getSize(); ++i)
            {
                ImageWidget *pageIndicatorImageWidget;

                if (i == 0)
                {
                    pageIndicatorImageWidget = new ImageWidget(pageIndicatorSelectedImage, sTestPageIndicatorSelectedResizedImage, sTestSettingsWrapperWidget);
                }
                else
                {
                    pageIndicatorImageWidget = new ImageWidget(pageIndicatorImage, sTestPageIndicatorResizedImage, sTestSettingsWrapperWidget);
                }

                UEFI_ASSERT_EXECUTION(pageIndicatorImageWidget->setPosition(pageIndicatorPosX + i * pageIndicatorSize, pageIndicatorPosY), NgosStatus::ASSERTION);
                UEFI_ASSERT_EXECUTION(pageIndicatorImageWidget->setSize(pageIndicatorSize, pageIndicatorSize),                             NgosStatus::ASSERTION);



                UEFI_ASSERT_EXECUTION(sTestPageIndicators.append(pageIndicatorImageWidget), NgosStatus::ASSERTION);
            }
        }
    }
    else
    {
        i64 memoryTestPanelWidth = memoryTestRegionWidth;

        if (memoryTestStartButtonWidth > memoryTestPanelWidth - memoryTestImageSize)
        {
            memoryTestStartButtonWidth = memoryTestPanelWidth - memoryTestImageSize;
        }



        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(memoryTestPanelImage,    memoryTestPanelWidth,       memoryTestPanelHeight,       &memoryTestPanelResizedImage),    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonNormalImage,       memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonNormalResizedImage),       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonHoverImage,        memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonHoverResizedImage),        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonPressedImage,      memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonPressedResizedImage),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedImage,      memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonFocusedResizedImage),      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(Graphics::resizeImage(buttonFocusedHoverImage, memoryTestStartButtonWidth, memoryTestStartButtonHeight, &buttonFocusedHoverResizedImage), NgosStatus::ASSERTION);



        for (good_I64 i = 0; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
        {
            UEFI_ASSERT_EXECUTION(addMemoryTestPanel(0, memoryTestRegionPositionX, memoryTestRegionPositionY + i * memoryTestPanelHeight, memoryTestPanelWidth, memoryTestPanelHeight, memoryTestPanelImage, memoryTestPanelResizedImage, memoryDeviceImage, memoryDeviceResizedImage, buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, startImage, startResizedImage, memoryTestStartButtonWidth, memoryTestStartButtonHeight, memoryDevices.at(i)), NgosStatus::ASSERTION);
        }
    }



    sTestRunningWrapperWidget = new WrapperWidget(testTabPageWidget);

    UEFI_ASSERT_EXECUTION(sTestRunningWrapperWidget->setVisible(false),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestRunningWrapperWidget->setPosition(0, 0),                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestRunningWrapperWidget->setSize(tabPageWidth, tabPageHeight), NgosStatus::ASSERTION);



    i64 testStopButtonSize = tabPageWidth * TEST_STOP_BUTTON_SIZE_PERCENT / 100;



    sTestStopButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, sStopImage, nullptr, "", sTestRunningWrapperWidget);

    UEFI_ASSERT_EXECUTION(sTestStopButton->setPosition(tabPageWidth * TEST_STOP_BUTTON_POSITION_X_PERCENT / 100, tabPageHeight * TEST_STOP_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestStopButton->setSize(testStopButtonSize, testStopButtonSize),                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestStopButton->setKeyboardEventHandler(onTestStopButtonKeyboardEvent),                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestStopButton->setPressEventHandler(onTestStopButtonPressed),                                                                                    NgosStatus::ASSERTION);



    sTestingSizeLabelWidget = new LabelWidget(strdup(""), sTestRunningWrapperWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestingSizeLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingSizeLabelWidget->setPosition(tabPageWidth * TESTING_SIZE_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_SIZE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingSizeLabelWidget->setSize(tabPageWidth     * TESTING_SIZE_WIDTH_PERCENT      / 100, tabPageHeight * TESTING_SIZE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    sTestingRangeLabelWidget = new LabelWidget(strdup(""), sTestRunningWrapperWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestingRangeLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingRangeLabelWidget->setPosition(tabPageWidth * TESTING_RANGE_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_RANGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingRangeLabelWidget->setSize(tabPageWidth     * TESTING_RANGE_WIDTH_PERCENT      / 100, tabPageHeight * TESTING_RANGE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    sTestingModeLabelWidget = new LabelWidget(strdup(""), sTestRunningWrapperWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestingModeLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingModeLabelWidget->setPosition(tabPageWidth * TESTING_MODE_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_MODE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingModeLabelWidget->setSize(tabPageWidth     * TESTING_MODE_WIDTH_PERCENT      / 100, tabPageHeight * TESTING_MODE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    sTestingDeviceLocatorLabelWidget = new LabelWidget(strdup(""), sTestRunningWrapperWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestingDeviceLocatorLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingDeviceLocatorLabelWidget->setPosition(tabPageWidth * TESTING_DEVICE_LOCATOR_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_DEVICE_LOCATOR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingDeviceLocatorLabelWidget->setSize(tabPageWidth     * TESTING_DEVICE_LOCATOR_WIDTH_PERCENT      / 100, tabPageHeight * TESTING_DEVICE_LOCATOR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    sTestingManufacturerLabelWidget = new LabelWidget(strdup(""), sTestRunningWrapperWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestingManufacturerLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingManufacturerLabelWidget->setPosition(tabPageWidth * TESTING_MANUFACTURER_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_MANUFACTURER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingManufacturerLabelWidget->setSize(tabPageWidth     * TESTING_MANUFACTURER_WIDTH_PERCENT      / 100, tabPageHeight * TESTING_MANUFACTURER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    sTestingSerialNumberLabelWidget = new LabelWidget(strdup(""), sTestRunningWrapperWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestingSerialNumberLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingSerialNumberLabelWidget->setPosition(tabPageWidth * TESTING_SERIAL_NUMBER_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_SERIAL_NUMBER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingSerialNumberLabelWidget->setSize(tabPageWidth     * TESTING_SERIAL_NUMBER_WIDTH_PERCENT      / 100, tabPageHeight * TESTING_SERIAL_NUMBER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    sTestingPartNumberLabelWidget = new LabelWidget(strdup(""), sTestRunningWrapperWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestingPartNumberLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingPartNumberLabelWidget->setPosition(tabPageWidth * TESTING_PART_NUMBER_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_PART_NUMBER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingPartNumberLabelWidget->setSize(tabPageWidth     * TESTING_PART_NUMBER_WIDTH_PERCENT      / 100, tabPageHeight * TESTING_PART_NUMBER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    char8 *testTotalText = (char8 *)malloc(TEST_TOTAL_TEXT_LENGTH);
    UEFI_TEST_ASSERT(testTotalText != nullptr, NgosStatus::ASSERTION);

    testTotalText[0] = 0;



    sTestingTotalLabelWidget = new LabelWidget(testTotalText, testTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sTestingTotalLabelWidget->setVisible(false),                                                                                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingTotalLabelWidget->setPosition(tabPageWidth * TESTING_TOTAL_TEXT_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_TOTAL_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingTotalLabelWidget->setSize(tabPageWidth     * TESTING_TOTAL_TEXT_WIDTH_PERCENT      / 100, tabPageHeight * TESTING_TOTAL_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    i64 testPanelWidth  = tabPageWidth  * TESTING_PANEL_WIDTH_PERCENT  / 100;
    i64 testPanelHeight = tabPageHeight * TESTING_PANEL_HEIGHT_PERCENT / 100;



    PanelWidget *testPanelWidget = new PanelWidget(testPanelImage, sTestRunningWrapperWidget);

    UEFI_ASSERT_EXECUTION(testPanelWidget->setPosition(tabPageWidth * TESTING_PANEL_POSITION_X_PERCENT / 100, tabPageHeight * TESTING_PANEL_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(testPanelWidget->setSize(testPanelWidth, testPanelHeight),                                                                                   NgosStatus::ASSERTION);



    i64 testingTabWidgetWidth  = testPanelWidth  * TESTING_TABWIDGET_WIDTH_PERCENT  / 100;
    i64 testingTabWidgetHeight = testPanelHeight * TESTING_TABWIDGET_HEIGHT_PERCENT / 100;

    tabButtonWidth  = testingTabWidgetWidth  * TESTING_TAB_BUTTON_WIDTH_PERCENT  / 100;
    tabButtonHeight = testingTabWidgetHeight * TESTING_TAB_BUTTON_HEIGHT_PERCENT / 100;

    i64 testingTabPageWidth  = testingTabWidgetWidth;
    i64 testingTabPageHeight = testingTabWidgetHeight - tabButtonHeight;



    patch = tabWidgetPanelImage->getNinePatch();

    if (patch)
    {
        testingTabPageWidth  -= patch->getPaddingLeft() + patch->getPaddingRight();
        testingTabPageHeight -= patch->getPaddingTop()  + patch->getPaddingBottom();
    }



    sTestingTabWidget = new TabWidget(tabWidgetPanelImage, testPanelWidget); // TODO: Should be removed for MemoryTest, but can be reused in HddTest



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



    sListTabButton = new TabButton(tabNormalImage, tabHoverImage, tabPressedImage, tabFocusedImage, tabFocusedHoverImage, selectedTabNormalImage, selectedTabHoverImage, selectedTabPressedImage, selectedTabFocusedImage, selectedTabFocusedHoverImage, tabNormalResizedImage, tabHoverResizedImage, tabPressedResizedImage, tabFocusedResizedImage, tabFocusedHoverResizedImage, selectedTabNormalResizedImage, selectedTabHoverResizedImage, selectedTabPressedResizedImage, selectedTabFocusedResizedImage, selectedTabFocusedHoverResizedImage, listImage, nullptr, "", sTestingTabWidget);

    UEFI_ASSERT_EXECUTION(sListTabButton->setSize(tabButtonWidth, tabButtonHeight),              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sListTabButton->setKeyboardEventHandler(onListTabButtonKeyboardEvent), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sListTabButton->setPressEventHandler(onListTabButtonPressed),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingTabWidget->addTabButton(sListTabButton),                       NgosStatus::ASSERTION);



    sChartTabButton = new TabButton(tabNormalImage, tabHoverImage, tabPressedImage, tabFocusedImage, tabFocusedHoverImage, selectedTabNormalImage, selectedTabHoverImage, selectedTabPressedImage, selectedTabFocusedImage, selectedTabFocusedHoverImage, tabNormalResizedImage, tabHoverResizedImage, tabPressedResizedImage, tabFocusedResizedImage, tabFocusedHoverResizedImage, selectedTabNormalResizedImage, selectedTabHoverResizedImage, selectedTabPressedResizedImage, selectedTabFocusedResizedImage, selectedTabFocusedHoverResizedImage, chartImage, nullptr, "", sTestingTabWidget);

    UEFI_ASSERT_EXECUTION(sChartTabButton->setSize(tabButtonWidth, tabButtonHeight),               NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sChartTabButton->setKeyboardEventHandler(onChartTabButtonKeyboardEvent), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sChartTabButton->setPressEventHandler(onChartTabButtonPressed),          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingTabWidget->addTabButton(sChartTabButton),                        NgosStatus::ASSERTION);



    TabPageWidget *listTabPageWidget = new TabPageWidget(sTestingTabWidget);

    UEFI_ASSERT_EXECUTION(sTestingTabWidget->addTabPage(listTabPageWidget), NgosStatus::ASSERTION);



    char8 *sequentialReadAverageText   = (char8 *)malloc(AVERAGE_TEXT_LENGTH);
    char8 *sequentialReadMaximumText   = (char8 *)malloc(MAXIMUM_TEXT_LENGTH);
    char8 *sequentialReadProgressText  = (char8 *)malloc(PROGRESS_TEXT_LENGTH);
    char8 *sequentialWriteAverageText  = (char8 *)malloc(AVERAGE_TEXT_LENGTH);
    char8 *sequentialWriteMaximumText  = (char8 *)malloc(MAXIMUM_TEXT_LENGTH);
    char8 *sequentialWriteProgressText = (char8 *)malloc(PROGRESS_TEXT_LENGTH);
    char8 *randomReadAverageText       = (char8 *)malloc(AVERAGE_TEXT_LENGTH);
    char8 *randomReadMaximumText       = (char8 *)malloc(MAXIMUM_TEXT_LENGTH);
    char8 *randomReadProgressText      = (char8 *)malloc(PROGRESS_TEXT_LENGTH);
    char8 *randomWriteAverageText      = (char8 *)malloc(AVERAGE_TEXT_LENGTH);
    char8 *randomWriteMaximumText      = (char8 *)malloc(MAXIMUM_TEXT_LENGTH);
    char8 *randomWriteProgressText     = (char8 *)malloc(PROGRESS_TEXT_LENGTH);

    UEFI_TEST_ASSERT(sequentialReadAverageText   != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(sequentialReadMaximumText   != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(sequentialReadProgressText  != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(sequentialWriteAverageText  != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(sequentialWriteMaximumText  != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(sequentialWriteProgressText != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(randomReadAverageText       != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(randomReadMaximumText       != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(randomReadProgressText      != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(randomWriteAverageText      != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(randomWriteMaximumText      != nullptr, NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(randomWriteProgressText     != nullptr, NgosStatus::ASSERTION);

    sequentialReadAverageText[0]   = 0;
    sequentialReadMaximumText[0]   = 0;
    sequentialReadProgressText[0]  = 0;
    sequentialWriteAverageText[0]  = 0;
    sequentialWriteMaximumText[0]  = 0;
    sequentialWriteProgressText[0] = 0;
    randomReadAverageText[0]       = 0;
    randomReadMaximumText[0]       = 0;
    randomReadProgressText[0]      = 0;
    randomWriteAverageText[0]      = 0;
    randomWriteMaximumText[0]      = 0;
    randomWriteProgressText[0]     = 0;



    LabelWidget *sequentialReadLabelWidget = new LabelWidget("Sequential read with 1 MB block", listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialReadLabelWidget->setColor(blackColor),                                                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadLabelWidget->setPosition(testingTabPageWidth * SEQUENTIAL_READ_TEXT_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_READ_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadLabelWidget->setSize(testingTabPageWidth     * SEQUENTIAL_READ_TEXT_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_READ_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *sequentialReadAverageLabelWidget = new LabelWidget(sequentialReadAverageText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialReadAverageLabelWidget->setColor(blackColor),                                                                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadAverageLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadAverageLabelWidget->setPosition(testingTabPageWidth * SEQUENTIAL_READ_AVERAGE_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_READ_AVERAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadAverageLabelWidget->setSize(testingTabPageWidth     * SEQUENTIAL_READ_AVERAGE_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_READ_AVERAGE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *sequentialReadMaximumLabelWidget = new LabelWidget(sequentialReadMaximumText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialReadMaximumLabelWidget->setColor(blackColor),                                                                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadMaximumLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                                  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadMaximumLabelWidget->setPosition(testingTabPageWidth * SEQUENTIAL_READ_MAXIMUM_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_READ_MAXIMUM_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadMaximumLabelWidget->setSize(testingTabPageWidth     * SEQUENTIAL_READ_MAXIMUM_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_READ_MAXIMUM_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *sequentialReadProgressLabelWidget = new LabelWidget(sequentialReadProgressText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialReadProgressLabelWidget->setColor(blackColor),                                                                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadProgressLabelWidget->setHorizontalAlignment(HorizontalAlignment::RIGHT_JUSTIFIED),                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadProgressLabelWidget->setPosition(testingTabPageWidth * SEQUENTIAL_READ_PROGRESS_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_READ_PROGRESS_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadProgressLabelWidget->setSize(testingTabPageWidth     * SEQUENTIAL_READ_PROGRESS_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_READ_PROGRESS_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    ProgressBarWidget *sequentialReadProgressBarWidget = new ProgressBarWidget(progressbarBackgroundImage, progressbarIndicatorImage, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialReadProgressBarWidget->setColor(blackColor),                                                                                                                                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadProgressBarWidget->setPosition(testingTabPageWidth * SEQUENTIAL_READ_PROGRESSBAR_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_READ_PROGRESSBAR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialReadProgressBarWidget->setSize(testingTabPageWidth     * SEQUENTIAL_READ_PROGRESSBAR_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_READ_PROGRESSBAR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *sequentialWriteLabelWidget = new LabelWidget("Sequential write with 1 MB block", listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialWriteLabelWidget->setColor(blackColor),                                                                                                                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                              NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteLabelWidget->setPosition(testingTabPageWidth * SEQUENTIAL_WRITE_TEXT_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_WRITE_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteLabelWidget->setSize(testingTabPageWidth     * SEQUENTIAL_WRITE_TEXT_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_WRITE_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *sequentialWriteAverageLabelWidget = new LabelWidget(sequentialWriteAverageText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialWriteAverageLabelWidget->setColor(blackColor),                                                                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteAverageLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteAverageLabelWidget->setPosition(testingTabPageWidth * SEQUENTIAL_WRITE_AVERAGE_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_WRITE_AVERAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteAverageLabelWidget->setSize(testingTabPageWidth     * SEQUENTIAL_WRITE_AVERAGE_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_WRITE_AVERAGE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *sequentialWriteMaximumLabelWidget = new LabelWidget(sequentialWriteMaximumText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialWriteMaximumLabelWidget->setColor(blackColor),                                                                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteMaximumLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteMaximumLabelWidget->setPosition(testingTabPageWidth * SEQUENTIAL_WRITE_MAXIMUM_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_WRITE_MAXIMUM_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteMaximumLabelWidget->setSize(testingTabPageWidth     * SEQUENTIAL_WRITE_MAXIMUM_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_WRITE_MAXIMUM_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *sequentialWriteProgressLabelWidget = new LabelWidget(sequentialWriteProgressText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialWriteProgressLabelWidget->setColor(blackColor),                                                                                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteProgressLabelWidget->setHorizontalAlignment(HorizontalAlignment::RIGHT_JUSTIFIED),                                                                                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteProgressLabelWidget->setPosition(testingTabPageWidth * SEQUENTIAL_WRITE_PROGRESS_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_WRITE_PROGRESS_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteProgressLabelWidget->setSize(testingTabPageWidth     * SEQUENTIAL_WRITE_PROGRESS_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_WRITE_PROGRESS_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    ProgressBarWidget *sequentialWriteProgressBarWidget = new ProgressBarWidget(progressbarBackgroundImage, progressbarIndicatorImage, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(sequentialWriteProgressBarWidget->setColor(blackColor),                                                                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteProgressBarWidget->setPosition(testingTabPageWidth * SEQUENTIAL_WRITE_PROGRESSBAR_POSITION_X_PERCENT / 100, testingTabPageHeight * SEQUENTIAL_WRITE_PROGRESSBAR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sequentialWriteProgressBarWidget->setSize(testingTabPageWidth     * SEQUENTIAL_WRITE_PROGRESSBAR_WIDTH_PERCENT      / 100, testingTabPageHeight * SEQUENTIAL_WRITE_PROGRESSBAR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *randomReadLabelWidget = new LabelWidget("Random read with 1 MB block", listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomReadLabelWidget->setColor(blackColor),                                                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                    NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadLabelWidget->setPosition(testingTabPageWidth * RANDOM_READ_TEXT_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_READ_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadLabelWidget->setSize(testingTabPageWidth     * RANDOM_READ_TEXT_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_READ_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *randomReadAverageLabelWidget = new LabelWidget(randomReadAverageText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomReadAverageLabelWidget->setColor(blackColor),                                                                                                                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadAverageLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadAverageLabelWidget->setPosition(testingTabPageWidth * RANDOM_READ_AVERAGE_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_READ_AVERAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadAverageLabelWidget->setSize(testingTabPageWidth     * RANDOM_READ_AVERAGE_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_READ_AVERAGE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *randomReadMaximumLabelWidget = new LabelWidget(randomReadMaximumText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomReadMaximumLabelWidget->setColor(blackColor),                                                                                                                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadMaximumLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                          NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadMaximumLabelWidget->setPosition(testingTabPageWidth * RANDOM_READ_MAXIMUM_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_READ_MAXIMUM_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadMaximumLabelWidget->setSize(testingTabPageWidth     * RANDOM_READ_MAXIMUM_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_READ_MAXIMUM_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *randomReadProgressLabelWidget = new LabelWidget(randomReadProgressText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomReadProgressLabelWidget->setColor(blackColor),                                                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadProgressLabelWidget->setHorizontalAlignment(HorizontalAlignment::RIGHT_JUSTIFIED),                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadProgressLabelWidget->setPosition(testingTabPageWidth * RANDOM_READ_PROGRESS_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_READ_PROGRESS_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadProgressLabelWidget->setSize(testingTabPageWidth     * RANDOM_READ_PROGRESS_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_READ_PROGRESS_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    ProgressBarWidget *randomReadProgressBarWidget = new ProgressBarWidget(progressbarBackgroundImage, progressbarIndicatorImage, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomReadProgressBarWidget->setColor(blackColor),                                                                                                                                         NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadProgressBarWidget->setPosition(testingTabPageWidth * RANDOM_READ_PROGRESSBAR_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_READ_PROGRESSBAR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomReadProgressBarWidget->setSize(testingTabPageWidth     * RANDOM_READ_PROGRESSBAR_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_READ_PROGRESSBAR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *randomWriteLabelWidget = new LabelWidget("Random write with 1 MB block", listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomWriteLabelWidget->setColor(blackColor),                                                                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteLabelWidget->setPosition(testingTabPageWidth * RANDOM_WRITE_TEXT_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_WRITE_TEXT_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteLabelWidget->setSize(testingTabPageWidth     * RANDOM_WRITE_TEXT_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_WRITE_TEXT_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *randomWriteAverageLabelWidget = new LabelWidget(randomWriteAverageText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomWriteAverageLabelWidget->setColor(blackColor),                                                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteAverageLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteAverageLabelWidget->setPosition(testingTabPageWidth * RANDOM_WRITE_AVERAGE_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_WRITE_AVERAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteAverageLabelWidget->setSize(testingTabPageWidth     * RANDOM_WRITE_AVERAGE_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_WRITE_AVERAGE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *randomWriteMaximumLabelWidget = new LabelWidget(randomWriteMaximumText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomWriteMaximumLabelWidget->setColor(blackColor),                                                                                                                                   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteMaximumLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                            NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteMaximumLabelWidget->setPosition(testingTabPageWidth * RANDOM_WRITE_MAXIMUM_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_WRITE_MAXIMUM_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteMaximumLabelWidget->setSize(testingTabPageWidth     * RANDOM_WRITE_MAXIMUM_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_WRITE_MAXIMUM_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    LabelWidget *randomWriteProgressLabelWidget = new LabelWidget(randomWriteProgressText, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomWriteProgressLabelWidget->setColor(blackColor),                                                                                                                                     NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteProgressLabelWidget->setHorizontalAlignment(HorizontalAlignment::RIGHT_JUSTIFIED),                                                                                             NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteProgressLabelWidget->setPosition(testingTabPageWidth * RANDOM_WRITE_PROGRESS_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_WRITE_PROGRESS_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteProgressLabelWidget->setSize(testingTabPageWidth     * RANDOM_WRITE_PROGRESS_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_WRITE_PROGRESS_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    ProgressBarWidget *randomWriteProgressBarWidget = new ProgressBarWidget(progressbarBackgroundImage, progressbarIndicatorImage, listTabPageWidget);

    // Ignore CppAlignmentVerifier [BEGIN]
    UEFI_ASSERT_EXECUTION(randomWriteProgressBarWidget->setColor(blackColor),                                                                                                                                           NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteProgressBarWidget->setPosition(testingTabPageWidth * RANDOM_WRITE_PROGRESSBAR_POSITION_X_PERCENT / 100, testingTabPageHeight * RANDOM_WRITE_PROGRESSBAR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(randomWriteProgressBarWidget->setSize(testingTabPageWidth     * RANDOM_WRITE_PROGRESSBAR_WIDTH_PERCENT      / 100, testingTabPageHeight * RANDOM_WRITE_PROGRESSBAR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    sAverageLabelWidgets[(enum_t)TestType::SEQUENTIAL_READ]  = sequentialReadAverageLabelWidget;
    sMaximumLabelWidgets[(enum_t)TestType::SEQUENTIAL_READ]  = sequentialReadMaximumLabelWidget;
    sProgressLabelWidgets[(enum_t)TestType::SEQUENTIAL_READ] = sequentialReadProgressLabelWidget;
    sProgressBarWidgets[(enum_t)TestType::SEQUENTIAL_READ]   = sequentialReadProgressBarWidget;

    sAverageLabelWidgets[(enum_t)TestType::SEQUENTIAL_WRITE]  = sequentialWriteAverageLabelWidget;
    sMaximumLabelWidgets[(enum_t)TestType::SEQUENTIAL_WRITE]  = sequentialWriteMaximumLabelWidget;
    sProgressLabelWidgets[(enum_t)TestType::SEQUENTIAL_WRITE] = sequentialWriteProgressLabelWidget;
    sProgressBarWidgets[(enum_t)TestType::SEQUENTIAL_WRITE]   = sequentialWriteProgressBarWidget;

    sAverageLabelWidgets[(enum_t)TestType::RANDOM_READ]  = randomReadAverageLabelWidget;
    sMaximumLabelWidgets[(enum_t)TestType::RANDOM_READ]  = randomReadMaximumLabelWidget;
    sProgressLabelWidgets[(enum_t)TestType::RANDOM_READ] = randomReadProgressLabelWidget;
    sProgressBarWidgets[(enum_t)TestType::RANDOM_READ]   = randomReadProgressBarWidget;

    sAverageLabelWidgets[(enum_t)TestType::RANDOM_WRITE]  = randomWriteAverageLabelWidget;
    sMaximumLabelWidgets[(enum_t)TestType::RANDOM_WRITE]  = randomWriteMaximumLabelWidget;
    sProgressLabelWidgets[(enum_t)TestType::RANDOM_WRITE] = randomWriteProgressLabelWidget;
    sProgressBarWidgets[(enum_t)TestType::RANDOM_WRITE]   = randomWriteProgressBarWidget;



    TabPageWidget *chartTabPageWidget = new TabPageWidget(sTestingTabWidget);

    UEFI_ASSERT_EXECUTION(sTestingTabWidget->addTabPage(chartTabPageWidget), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sTestingTabWidget->setPosition(testPanelWidth * TESTING_TABWIDGET_POSITION_X_PERCENT / 100, testPanelHeight * TESTING_TABWIDGET_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingTabWidget->setSize(testingTabWidgetWidth, testingTabWidgetHeight),                                                                                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestingTabWidget->setCurrentPage(TESTING_TABWIDGET_PAGE_LIST),                                                                                            NgosStatus::ASSERTION);



    TabPageWidget *summaryTabPageWidget = new TabPageWidget(sTabWidget);

    UEFI_ASSERT_EXECUTION(sTabWidget->addTabPage(summaryTabPageWidget), NgosStatus::ASSERTION);



    i64 summaryTableWidth  = tabPageWidth  * SUMMARY_TABLEWIDGET_WIDTH_PERCENT  / 100;
    i64 summaryTableHeight = tabPageHeight * SUMMARY_TABLEWIDGET_HEIGHT_PERCENT / 100;



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



        sProcessorTasks = (TestType *)malloc(numberOfProcessors * sizeof(TestType));
        UEFI_TEST_ASSERT(sProcessorTasks != nullptr, NgosStatus::ASSERTION);
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

NgosStatus MemoryTestGUI::addMemoryInfoPanel(i64 pageIndex, i64 posX, i64 posY, i64 width, i64 height, Image *memoryInfoPanelImage, Image *memoryInfoPanelResizedImage, Image *memoryDeviceImage, Image *memoryDeviceResizedImage, Image *memoryDeviceDisabledImage, Image *memoryDeviceDisabledResizedImage, TabPageWidget *tabPageWidget, const DmiMemoryDevice &memoryDevice)
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



    i64 memoryImageSize = height * MEMORY_INFO_IMAGE_SIZE_PERCENT / 100;
    i64 allowedWidth    = width - memoryImageSize;



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

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setColor(disabledColor),                                                                                                                                         NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_DEVICE_LOCATOR_POSITION_X_PERCENT / 100, height * MEMORY_INFO_DEVICE_LOCATOR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_DEVICE_LOCATOR_WIDTH_PERCENT      / 100, height * MEMORY_INFO_DEVICE_LOCATOR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memoryNotInstalledLabelWidget = new LabelWidget("Not installed", memoryInfoPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryNotInstalledLabelWidget->setColor(disabledColor),                                                                                                                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryNotInstalledLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_NOT_INSTALLED_POSITION_X_PERCENT / 100, height * MEMORY_INFO_NOT_INSTALLED_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryNotInstalledLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_NOT_INSTALLED_WIDTH_PERCENT      / 100, height * MEMORY_INFO_NOT_INSTALLED_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
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

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setColor(blackColor),                                                                                                                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_DEVICE_LOCATOR_POSITION_X_PERCENT / 100, height * MEMORY_INFO_DEVICE_LOCATOR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_DEVICE_LOCATOR_WIDTH_PERCENT      / 100, height * MEMORY_INFO_DEVICE_LOCATOR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memoryManufacturerLabelWidget = new LabelWidget(memoryDevice.manufacturer != nullptr ? memoryDevice.manufacturer : "---", memoryInfoPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setColor(blackColor),                                                                                                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_MANUFACTURER_POSITION_X_PERCENT / 100, height * MEMORY_INFO_MANUFACTURER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_MANUFACTURER_WIDTH_PERCENT      / 100, height * MEMORY_INFO_MANUFACTURER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memorySerialNumberLabelWidget = new LabelWidget(memoryDevice.serialNumber != nullptr ? memoryDevice.serialNumber : "---", memoryInfoPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setColor(blackColor),                                                                                                                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_SERIAL_NUMBER_POSITION_X_PERCENT / 100, height * MEMORY_INFO_SERIAL_NUMBER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_SERIAL_NUMBER_WIDTH_PERCENT      / 100, height * MEMORY_INFO_SERIAL_NUMBER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memoryPartNumberLabelWidget = new LabelWidget(memoryDevice.partNumber != nullptr ? memoryDevice.partNumber : "---", memoryInfoPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setColor(blackColor),                                                                                                                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_PART_NUMBER_POSITION_X_PERCENT / 100, height * MEMORY_INFO_PART_NUMBER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_PART_NUMBER_WIDTH_PERCENT      / 100, height * MEMORY_INFO_PART_NUMBER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memorySizeLabelWidget = new LabelWidget(memorySize, memoryInfoPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setColor(blackColor),                                                                                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_SIZE_POSITION_X_PERCENT / 100, height * MEMORY_INFO_SIZE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_SIZE_WIDTH_PERCENT      / 100, height * MEMORY_INFO_SIZE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memoryTypeLabelWidget = new LabelWidget(mprintf("Type: %s", enumToHumanString(memoryDevice.memoryType)), memoryInfoPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryTypeLabelWidget->setColor(blackColor),                                                                                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTypeLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                 NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTypeLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_TYPE_POSITION_X_PERCENT / 100, height * MEMORY_INFO_TYPE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTypeLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_TYPE_WIDTH_PERCENT      / 100, height * MEMORY_INFO_TYPE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memorySpeedLabelWidget = new LabelWidget(memorySpeed, memoryInfoPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memorySpeedLabelWidget->setColor(blackColor),                                                                                                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySpeedLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED),                                                                                   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySpeedLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_INFO_SPEED_POSITION_X_PERCENT / 100, height * MEMORY_INFO_SPEED_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySpeedLabelWidget->setSize(allowedWidth                       * MEMORY_INFO_SPEED_WIDTH_PERCENT      / 100, height * MEMORY_INFO_SPEED_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]
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



    i64 row = sIssuesTableWidget->getRowCount();

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

    for (good_I64 i = 0; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
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

        for (good_I64 i = 1; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
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

NgosStatus MemoryTestGUI::addMemoryTestPanel(i64 pageIndex, i64 posX, i64 posY, i64 width, i64 height, Image *memoryTestPanelImage, Image *memoryTestPanelResizedImage, Image *memoryDeviceImage, Image *memoryDeviceResizedImage, Image *buttonNormalImage, Image *buttonHoverImage, Image *buttonPressedImage, Image *buttonFocusedImage, Image *buttonFocusedHoverImage, Image *buttonNormalResizedImage, Image *buttonHoverResizedImage, Image *buttonPressedResizedImage, Image *buttonFocusedResizedImage, Image *buttonFocusedHoverResizedImage, Image *startImage, Image *startResizedImage, i64 memoryTestStartButtonWidth, i64 memoryTestStartButtonHeight, const DmiMemoryDevice &memoryDevice)
{
    UEFI_LT((" | pageIndex = %u, posX = %u, posY = %u, width = %u, height = %u, memoryTestPanelImage = 0x%p, memoryTestPanelResizedImage = 0x%p, memoryDeviceImage = 0x%p, memoryDeviceResizedImage = 0x%p, buttonNormalImage = 0x%p, buttonHoverImage = 0x%p, buttonPressedImage = 0x%p, buttonFocusedImage = 0x%p, buttonFocusedHoverImage = 0x%p, buttonNormalResizedImage = 0x%p, buttonHoverResizedImage = 0x%p, buttonPressedResizedImage = 0x%p, buttonFocusedResizedImage = 0x%p, buttonFocusedHoverResizedImage = 0x%p, startImage = 0x%p, startResizedImage = 0x%p, memoryTestStartButtonWidth = %u, memoryTestStartButtonHeight = %u, memoryDevice = ...", pageIndex, posX, posY, width, height, memoryTestPanelImage, memoryTestPanelResizedImage, memoryDeviceImage, memoryDeviceResizedImage, buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, startImage, startResizedImage, memoryTestStartButtonWidth, memoryTestStartButtonHeight));

    UEFI_ASSERT(width > 0,                       "width is zero",                          NgosStatus::ASSERTION);
    UEFI_ASSERT(height > 0,                      "height is zero",                         NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryTestPanelImage,            "memoryTestPanelImage is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryTestPanelResizedImage,     "memoryTestPanelResizedImage is null",    NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryDeviceImage,               "memoryDeviceImage is null",              NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryDeviceResizedImage,        "memoryDeviceResizedImage is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonNormalImage,               "buttonNormalImage is null",              NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonHoverImage,                "buttonHoverImage is null",               NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonPressedImage,              "buttonPressedImage is null",             NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonFocusedImage,              "buttonFocusedImage is null",             NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonFocusedHoverImage,         "buttonFocusedHoverImage is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonNormalResizedImage,        "buttonNormalResizedImage is null",       NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonHoverResizedImage,         "buttonHoverResizedImage is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonPressedResizedImage,       "buttonPressedResizedImage is null",      NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonFocusedResizedImage,       "buttonFocusedResizedImage is null",      NgosStatus::ASSERTION);
    UEFI_ASSERT(buttonFocusedHoverResizedImage,  "buttonFocusedHoverResizedImage is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(startImage,                      "startImage is null",                     NgosStatus::ASSERTION);
    UEFI_ASSERT(startResizedImage,               "startResizedImage is null",              NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryTestStartButtonWidth > 0,  "memoryTestStartButtonWidth is zero",     NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryTestStartButtonHeight > 0, "memoryTestStartButtonHeight is zero",    NgosStatus::ASSERTION);



    i64 memoryImageSize = height * MEMORY_TEST_IMAGE_SIZE_PERCENT / 100;
    i64 allowedWidth    = width - memoryImageSize;



    PanelWidget *memoryTestPanelWidget = new PanelWidget(memoryTestPanelImage, memoryTestPanelResizedImage, sTestSettingsWrapperWidget);

    if (pageIndex > 0)
    {
        UEFI_ASSERT_EXECUTION(memoryTestPanelWidget->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(memoryTestPanelWidget->setPosition(posX, posY), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(memoryTestPanelWidget->setSize(width, height),  NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(memoryDevice.size != 0, NgosStatus::ASSERTION);



    Button *memoryTestStartButton;

    // Add widgets in memoryTestPanelWidget
    {
        RgbaPixel blackColor(BLACK_COLOR);



        const char8 *memorySize;

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
        }



        ImageWidget *memoryImageWidget = new ImageWidget(memoryDeviceImage, memoryDeviceResizedImage, memoryTestPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryImageWidget->setPosition(width * MEMORY_TEST_IMAGE_POSITION_X_PERCENT / 100, height * MEMORY_TEST_IMAGE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryImageWidget->setSize(memoryImageSize, memoryImageSize),                                                                            NgosStatus::ASSERTION);



        LabelWidget *memoryDeviceLocatorLabelWidget = new LabelWidget(memoryDevice.deviceLocator != nullptr ? memoryDevice.deviceLocator : "---", memoryTestPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setColor(blackColor),                                                                                                                                            NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_TEST_DEVICE_LOCATOR_POSITION_X_PERCENT / 100, height * MEMORY_TEST_DEVICE_LOCATOR_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryDeviceLocatorLabelWidget->setSize(allowedWidth                       * MEMORY_TEST_DEVICE_LOCATOR_WIDTH_PERCENT      / 100, height * MEMORY_TEST_DEVICE_LOCATOR_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memoryManufacturerLabelWidget = new LabelWidget(memoryDevice.manufacturer != nullptr ? memoryDevice.manufacturer : "---", memoryTestPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setColor(blackColor),                                                                                                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_TEST_MANUFACTURER_POSITION_X_PERCENT / 100, height * MEMORY_TEST_MANUFACTURER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryManufacturerLabelWidget->setSize(allowedWidth                       * MEMORY_TEST_MANUFACTURER_WIDTH_PERCENT      / 100, height * MEMORY_TEST_MANUFACTURER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memorySerialNumberLabelWidget = new LabelWidget(memoryDevice.serialNumber != nullptr ? memoryDevice.serialNumber : "---", memoryTestPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setColor(blackColor),                                                                                                                                          NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_TEST_SERIAL_NUMBER_POSITION_X_PERCENT / 100, height * MEMORY_TEST_SERIAL_NUMBER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySerialNumberLabelWidget->setSize(allowedWidth                       * MEMORY_TEST_SERIAL_NUMBER_WIDTH_PERCENT      / 100, height * MEMORY_TEST_SERIAL_NUMBER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memoryPartNumberLabelWidget = new LabelWidget(memoryDevice.partNumber != nullptr ? memoryDevice.partNumber : "---", memoryTestPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setColor(blackColor),                                                                                                                                      NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_TEST_PART_NUMBER_POSITION_X_PERCENT / 100, height * MEMORY_TEST_PART_NUMBER_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryPartNumberLabelWidget->setSize(allowedWidth                       * MEMORY_TEST_PART_NUMBER_WIDTH_PERCENT      / 100, height * MEMORY_TEST_PART_NUMBER_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        LabelWidget *memorySizeLabelWidget = new LabelWidget(memorySize, memoryTestPanelWidget);

        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setColor(blackColor),                                                                                                                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setPosition(memoryImageSize + allowedWidth * MEMORY_TEST_SIZE_POSITION_X_PERCENT / 100, height * MEMORY_TEST_SIZE_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memorySizeLabelWidget->setSize(allowedWidth                       * MEMORY_TEST_SIZE_WIDTH_PERCENT      / 100, height * MEMORY_TEST_SIZE_HEIGHT_PERCENT     / 100), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        memoryTestStartButton = new Button(buttonNormalImage, buttonHoverImage, buttonPressedImage, buttonFocusedImage, buttonFocusedHoverImage, buttonNormalResizedImage, buttonHoverResizedImage, buttonPressedResizedImage, buttonFocusedResizedImage, buttonFocusedHoverResizedImage, startImage, startResizedImage, nullptr, "Start test", memoryTestPanelWidget);

        UEFI_ASSERT_EXECUTION(memoryTestStartButton->setColor(blackColor),                                                                                                                       NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTestStartButton->setPosition(memoryImageSize + (allowedWidth - memoryTestStartButtonWidth) / 2, height * MEMORY_TEST_START_BUTTON_POSITION_Y_PERCENT / 100), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTestStartButton->setSize(memoryTestStartButtonWidth, memoryTestStartButtonHeight),                                                                           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTestStartButton->setKeyboardEventHandler(onTestStartButtonKeyboardEvent),                                                                                    NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(memoryTestStartButton->setPressEventHandler(onTestStartButtonPressed),                                                                                             NgosStatus::ASSERTION);
    }



    // Add memoryTestPanelWidget to last page
    {
        ArrayList<PanelWidget *> *page;

        if (pageIndex >= sTestPages.getSize())
        {
            UEFI_TEST_ASSERT(pageIndex == sTestPages.getSize(), NgosStatus::ASSERTION);



            page = new ArrayList<PanelWidget *>();

            UEFI_ASSERT_EXECUTION(sTestPages.append(page), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(pageIndex == sTestPages.getSize() - 1, NgosStatus::ASSERTION);



            page = sTestPages.last();
        }



        UEFI_ASSERT_EXECUTION(page->append(memoryTestPanelWidget), NgosStatus::ASSERTION);

        UEFI_TEST_ASSERT(page->getSize() <= 4, NgosStatus::ASSERTION);
    }



    // Add memoryTestStartButton to last page
    {
        ArrayList<Widget *> *page;

        if (pageIndex >= sTestButtonPages.getSize())
        {
            UEFI_TEST_ASSERT(pageIndex == sTestButtonPages.getSize(), NgosStatus::ASSERTION);



            page = new ArrayList<Widget *>();

            UEFI_ASSERT_EXECUTION(sTestButtonPages.append(page), NgosStatus::ASSERTION);
        }
        else
        {
            UEFI_TEST_ASSERT(pageIndex == sTestButtonPages.getSize() - 1, NgosStatus::ASSERTION);



            page = sTestButtonPages.last();
        }



        UEFI_ASSERT_EXECUTION(page->append(memoryTestStartButton), NgosStatus::ASSERTION);

        UEFI_TEST_ASSERT(page->getSize() <= 4, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::addSummaryEntry(const char8 *name, i64 score)
{
    UEFI_LT((" | name = 0x%p, score = %u", name, score));

    UEFI_ASSERT(name, "name is null", NgosStatus::ASSERTION);



    RgbaPixel blackColor(BLACK_COLOR);



    i64 row = sSummaryTableWidget->getRowCount();

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



    u32             minimumSpeed = 0xFFFFFFFF;
    ArrayList<bool> dualChannelPairs;



    const ArrayList<DmiMemoryDevice> &memoryDevices = DMI::getMemoryDevices();

    for (good_I64 i = 0; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
    {
        const DmiMemoryDevice &memoryDevice = memoryDevices.at(i);



        if (memoryDevice.speed > 0)
        {
            if (memoryDevice.speed < minimumSpeed)
            {
                minimumSpeed = memoryDevice.speed;
            }
        }



        UEFI_ASSERT_EXECUTION(dualChannelPairs.append(false), NgosStatus::ASSERTION);
    }



    if (minimumSpeed == 0xFFFFFFFF)
    {
        minimumSpeed = 0;
    }



    i64 dualChannelNumberOfPairs = 0;

    for (good_I64 i = 1; i < (i64)DMI::getNumberOfInstalledMemoryDevices(); ++i)
    {
        const DmiMemoryDevice &memoryDevice = memoryDevices.at(i);



        for (good_I64 j = 0; j < i; ++j)
        {
            if (!dualChannelPairs.at(j))
            {
                const DmiMemoryDevice &anotherMemoryDevice = memoryDevices.at(j);

                if (
                    anotherMemoryDevice.memoryType == memoryDevice.memoryType
                    &&
                    anotherMemoryDevice.speed == memoryDevice.speed
                    &&
                    anotherMemoryDevice.size == memoryDevice.size
                   )
                {
                    ++dualChannelNumberOfPairs;

                    dualChannelPairs[i] = true;
                    dualChannelPairs[j] = true;

                    break;
                }
            }
        }
    }



    const char8 *totalMemoryCapacity = mprintf("Total memory capacity: %s", bytesToString(DMI::getTotalAmountOfMemory()));
    const char8 *memorySpeed         = mprintf("Memory speed: %u MHz",      minimumSpeed);
    const char8 *dualChannel;

    if (dualChannelNumberOfPairs > 0)
    {
        dualChannel = mprintf("%u x Dual channel", dualChannelNumberOfPairs);
    }
    else
    {
        dualChannel = "No dual channel";
    }



    UEFI_ASSERT_EXECUTION(addSummaryEntry("Previous test results", 0),                                                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(totalMemoryCapacity,     DMI::getTotalAmountOfMemory() * SCORE_PER_1GB_RAM / GB), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(memorySpeed,             minimumSpeed * SCORE_PER_100_MHZ / 100),                 NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(addSummaryEntry(dualChannel,             dualChannelNumberOfPairs * SCORE_DUAL_CHANNEL),          NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::focusTabFirstWidget()
{
    UEFI_LT((""));



    switch (sTabWidget->getCurrentPage())
    {
        case TABWIDGET_PAGE_SYSTEM_INFORMATION: return GUI::setFocusedWidget(sInfoLeftButton != nullptr ? (sInfoLeftButton->isVisible() ? (Widget *)sInfoLeftButton : (Widget *)sInfoRightButton) : (Widget *)sRebootButton);
        case TABWIDGET_PAGE_ISSUES:             return GUI::setFocusedWidget(sIssuesTableWidget);
        case TABWIDGET_PAGE_TEST:               return GUI::setFocusedWidget(sTestRunningWrapperWidget->isVisible() ? (Widget *)sTestStopButton : (Widget *)sTestModeButton);
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

        case TABWIDGET_PAGE_TEST:
        {
            if (sTestRunningWrapperWidget->isVisible())
            {
                return focusTestingTabLastWidget();
            }

            if (!sTestButtonPages.isEmpty())
            {
                return GUI::setFocusedWidget(sTestButtonPages.at(sTestCurrentPage)->last());
            }

            return GUI::setFocusedWidget(sTestModeButton);
        }
        break;

        case TABWIDGET_PAGE_SUMMARY: return GUI::setFocusedWidget(sSummaryTableWidget);

        default:
        {
            UEFI_LF(("Unknown tab page: %d, %s:%u", sTabWidget->getCurrentPage(), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::focusTestingTabFirstWidget()
{
    UEFI_LT((""));



    switch (sTestingTabWidget->getCurrentPage())
    {
        case TESTING_TABWIDGET_PAGE_LIST:  return GUI::setFocusedWidget(sRebootButton);
        case TESTING_TABWIDGET_PAGE_CHART: return GUI::setFocusedWidget(sRebootButton);

        default:
        {
            UEFI_LF(("Unknown tab page: %d, %s:%u", sTestingTabWidget->getCurrentPage(), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::focusTestingTabLastWidget()
{
    UEFI_LT((""));



    switch (sTestingTabWidget->getCurrentPage())
    {
        case TESTING_TABWIDGET_PAGE_LIST:  return GUI::setFocusedWidget(sListTabButton);
        case TESTING_TABWIDGET_PAGE_CHART: return GUI::setFocusedWidget(sChartTabButton);

        default:
        {
            UEFI_LF(("Unknown tab page: %d, %s:%u", sTestingTabWidget->getCurrentPage(), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::focusTestingTab()
{
    UEFI_LT((""));



    switch (sTestingTabWidget->getCurrentPage())
    {
        case TESTING_TABWIDGET_PAGE_LIST:  return GUI::setFocusedWidget(sListTabButton);
        case TESTING_TABWIDGET_PAGE_CHART: return GUI::setFocusedWidget(sChartTabButton);

        default:
        {
            UEFI_LF(("Unknown tab page: %d, %s:%u", sTestingTabWidget->getCurrentPage(), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::showFirstInfoPage()
{
    UEFI_LT((""));



    if (sInfoCurrentPage <= 0)
    {
        return NgosStatus::NO_EFFECT;
    }



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    ArrayList<PanelWidget *> *page = sInfoPages.at(sInfoCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sInfoPageIndicators.at(sInfoCurrentPage)->setResizedImage(sInfoPageIndicatorResizedImage), NgosStatus::ASSERTION);



    sInfoCurrentPage = 0;



    page = sInfoPages.first();

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sInfoPageIndicators.first()->setResizedImage(sInfoPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sInfoRightButton->setVisible(true), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sInfoLeftButton->setVisible(false), NgosStatus::ASSERTION);

    if (sInfoLeftButton->isFocused())
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sInfoRightButton), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::showLastInfoPage()
{
    UEFI_LT((""));



    if (sInfoCurrentPage >= sInfoPages.getSize() - 1)
    {
        return NgosStatus::NO_EFFECT;
    }



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    ArrayList<PanelWidget *> *page = sInfoPages.at(sInfoCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sInfoPageIndicators.at(sInfoCurrentPage)->setResizedImage(sInfoPageIndicatorResizedImage), NgosStatus::ASSERTION);



    sInfoCurrentPage = sInfoPages.getSize() - 1;



    page = sInfoPages.last();

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sInfoPageIndicators.last()->setResizedImage(sInfoPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sInfoLeftButton->setVisible(true),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sInfoRightButton->setVisible(false), NgosStatus::ASSERTION);

    if (sInfoRightButton->isFocused())
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sInfoLeftButton), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::showFirstTestPage()
{
    UEFI_LT((""));



    if (sTestCurrentPage <= 0)
    {
        return NgosStatus::NO_EFFECT;
    }



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    i64 index = sTestButtonPages.at(sTestCurrentPage)->indexOf(GUI::getFocusedWidget());



    ArrayList<PanelWidget *> *page = sTestPages.at(sTestCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sTestPageIndicators.at(sTestCurrentPage)->setResizedImage(sTestPageIndicatorResizedImage), NgosStatus::ASSERTION);



    sTestCurrentPage = 0;



    page = sTestPages.first();

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sTestPageIndicators.first()->setResizedImage(sTestPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



    if (index >= 0)
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestButtonPages.first()->first()), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sTestRightButton->setVisible(true), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestLeftButton->setVisible(false), NgosStatus::ASSERTION);

    if (sTestLeftButton->isFocused())
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestRightButton), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::showLastTestPage()
{
    UEFI_LT((""));



    if (sTestCurrentPage >= sTestPages.getSize() - 1)
    {
        return NgosStatus::NO_EFFECT;
    }



    i64 index = sTestButtonPages.at(sTestCurrentPage)->indexOf(GUI::getFocusedWidget());



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    ArrayList<PanelWidget *> *page = sTestPages.at(sTestCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sTestPageIndicators.at(sTestCurrentPage)->setResizedImage(sTestPageIndicatorResizedImage), NgosStatus::ASSERTION);



    sTestCurrentPage = sTestPages.getSize() - 1;



    page = sTestPages.last();

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sTestPageIndicators.last()->setResizedImage(sTestPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



    if (index >= 0)
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestButtonPages.last()->first()), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sTestLeftButton->setVisible(true),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestRightButton->setVisible(false), NgosStatus::ASSERTION);

    if (sTestRightButton->isFocused())
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestLeftButton), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::startTest(i64 id)
{
    UEFI_LT((" | id = %d", id));

    UEFI_ASSERT(id >= -1, "id is invalid", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sTestSettingsWrapperWidget->setVisible(false), NgosStatus::ASSERTION);



    sLastFocusedWidget = GUI::getFocusedWidget();
    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestStopButton), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sTestStopButton->setContentImage(sStopImage), NgosStatus::ASSERTION);



    address_t start;
    address_t end;
    i64       testSize;



    UEFI_ASSERT_EXECUTION(free((void *)sTestingSizeLabelWidget->getText()),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(free((void *)sTestingRangeLabelWidget->getText()), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(free((void *)sTestingModeLabelWidget->getText()),  NgosStatus::ASSERTION);

    if (id >= 0)
    {
        UEFI_ASSERT_EXECUTION(free((void *)sTestingDeviceLocatorLabelWidget->getText()), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(free((void *)sTestingManufacturerLabelWidget->getText()),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(free((void *)sTestingSerialNumberLabelWidget->getText()),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(free((void *)sTestingPartNumberLabelWidget->getText()),    NgosStatus::ASSERTION);



        const DmiMemoryDevice &memoryDevice = DMI::getMemoryDevices().at(id);



        start = memoryDevice.start;
        end   = memoryDevice.end;

        switch (sMode)
        {
            case TestMode::QUICK_TEST: testSize = MIN(memoryDevice.size, QUICK_TEST_SIZE); break;
            case TestMode::FULL_TEST:  testSize = memoryDevice.size;                       break;

            case TestMode::MAXIMUM:
            {
                UEFI_LF(("Unexpected test mode %s, %s:%u", enumToFullString(sMode), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                UEFI_LF(("Unknown test mode %s, %s:%u", enumToFullString(sMode), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }



        char8 startBuffer[11];
        char8 endBuffer[11];

        UEFI_ASSERT_EXECUTION(bytesToString(start, startBuffer, sizeof(startBuffer)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(bytesToString(end,   endBuffer,   sizeof(endBuffer)),   NgosStatus::ASSERTION);



        // Ignore CppAlignmentVerifier [BEGIN]
        UEFI_ASSERT_EXECUTION(sTestingSizeLabelWidget->setText( mprintf("Size:      %s",      bytesToString(memoryDevice.size))), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingRangeLabelWidget->setText(mprintf("Range:     %s - %s", startBuffer, endBuffer)),           NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingModeLabelWidget->setText( mprintf("Test mode: %s",      enumToHumanString(sMode))),         NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sTestingDeviceLocatorLabelWidget->setText(mprintf("Location:     %s", memoryDevice.deviceLocator != nullptr ? memoryDevice.deviceLocator : "---")), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingManufacturerLabelWidget->setText( mprintf("Manufacturer: %s", memoryDevice.manufacturer  != nullptr ? memoryDevice.manufacturer  : "---")), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingSerialNumberLabelWidget->setText( mprintf("S/N:          %s", memoryDevice.serialNumber  != nullptr ? memoryDevice.serialNumber  : "---")), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingPartNumberLabelWidget->setText(   mprintf("Part number:  %s", memoryDevice.partNumber    != nullptr ? memoryDevice.partNumber    : "---")), NgosStatus::ASSERTION);
        // Ignore CppAlignmentVerifier [END]



        UEFI_ASSERT_EXECUTION(sTestingDeviceLocatorLabelWidget->setVisible(true), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingManufacturerLabelWidget->setVisible(true),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingSerialNumberLabelWidget->setVisible(true),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingPartNumberLabelWidget->setVisible(true),    NgosStatus::ASSERTION);
    }
    else
    {
        start = 0;
        end   = DMI::getTotalAmountOfMemory();

        switch (sMode)
        {
            case TestMode::QUICK_TEST: testSize = MIN(end, QUICK_TEST_SIZE); break;
            case TestMode::FULL_TEST:  testSize = end;                       break;

            case TestMode::MAXIMUM:
            {
                UEFI_LF(("Unexpected test mode %s, %s:%u", enumToFullString(sMode), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                UEFI_LF(("Unknown test mode %s, %s:%u", enumToFullString(sMode), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }



        char8 bytesBuffer[11];

        UEFI_ASSERT_EXECUTION(bytesToString(end, bytesBuffer, sizeof(bytesBuffer)), NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(sTestingSizeLabelWidget->setText( mprintf("Size:      %s",       bytesBuffer)),              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingRangeLabelWidget->setText(mprintf("Range:     0 B - %s", bytesBuffer)),              NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingModeLabelWidget->setText( mprintf("Test mode: %s",       enumToHumanString(sMode))), NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(sTestingDeviceLocatorLabelWidget->setVisible(false), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingManufacturerLabelWidget->setVisible(false),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingSerialNumberLabelWidget->setVisible(false),  NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sTestingPartNumberLabelWidget->setVisible(false),    NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sTestingTotalLabelWidget->setVisible(false), NgosStatus::ASSERTION);



    char8 *sequentialReadProgressText = (char8 *)sProgressLabelWidgets[0]->getText();

    i64 progressTextLength = sprintf(sequentialReadProgressText, "0 B / %s", bytesToString(testSize));
    UEFI_TEST_ASSERT(progressTextLength < PROGRESS_TEXT_LENGTH, NgosStatus::ASSERTION);



    for (good_I64 i = 0; i < (i64)TestType::MAXIMUM; ++i)
    {
        char8 *averageText  = (char8 *)sAverageLabelWidgets[i]->getText();
        char8 *maximumText  = (char8 *)sMaximumLabelWidgets[i]->getText();
        char8 *progressText = (char8 *)sProgressLabelWidgets[i]->getText();



        averageText[0] = 0;
        maximumText[0] = 0;

        if (i > 0)
        {
            memcpy(progressText, sequentialReadProgressText, (progressTextLength + 1) * sizeof(char8));
        }



        UEFI_ASSERT_EXECUTION(sAverageLabelWidgets[i]->setText(averageText),   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sMaximumLabelWidgets[i]->setText(maximumText),   NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sProgressLabelWidgets[i]->setText(progressText), NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(sProgressBarWidgets[i]->setValue(0),               NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sProgressBarWidgets[i]->setMaximumValue(testSize), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sProgressBarWidgets[i]->setVisible(true),          NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sTestRunningWrapperWidget->setVisible(true), NgosStatus::ASSERTION);



    UEFI_TEST_ASSERT(sNumberOfRunningProcessors == 0,       NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(sTimerEvent                == nullptr, NgosStatus::ASSERTION);



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
            // TODO: Test on real hardware
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            {
                UEFI_LVVV(("Processors:"));
                UEFI_LVVV(("-------------------------------------"));

                for (good_I64 i = 0; i < (i64)numberOfProcessors; ++i)
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



            for (good_I64 i = 0; i < (i64)TestType::MAXIMUM; ++i)
            {
                UEFI_ASSERT_EXECUTION(memoryTests[i]->reset(start, end, testSize), NgosStatus::ASSERTION);
            }



            sCurrentTest = (TestType)0;
            sTerminated  = false;



            TestBase *test = memoryTests[0];

            for (good_I64 i = 0; i < (i64)numberOfProcessors; ++i)
            {
                if (sMpServices->startupThisAP(sMpServices, test->getProcedure(), i, sWaitEvents[sFirstProcessorEventIndex + i], 0, test, nullptr) == UefiStatus::SUCCESS)
                {
                    UEFI_ASSERT_EXECUTION(test->setStartTsc(AsmUtils::rdtsc()), NgosStatus::ASSERTION);

                    UEFI_LV(("Test %s started on processor %d", enumToFullString(sCurrentTest), i));

                    ++sNumberOfRunningProcessors;



                    sProcessorTasks[i] = sCurrentTest;



                    sCurrentTest = (TestType)((enum_t)sCurrentTest + 1);

                    if (sCurrentTest >= TestType::MAXIMUM)
                    {
                        break;
                    }

                    test = memoryTests[(enum_t)sCurrentTest];
                }
            }



            if (sNumberOfRunningProcessors > 0)
            {
                UEFI_ASSERT_EXECUTION(enableTimerEvent(), NgosStatus::ASSERTION);
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
        UEFI_LE(("UEFI_MP_SERVICES_PROTOCOL not found")); // TODO: Try to do in single thread
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::updateTest(TestType testType, i64 tsc)
{
    UEFI_LT((" | testType = %u, tsc = %u", testType, tsc));

    UEFI_ASSERT(testType < TestType::MAXIMUM, "testType is invalid", NgosStatus::ASSERTION);



    TestBase *test = memoryTests[(enum_t)testType];

    i64 progress = test->getProgress();



    i64 averageSpeed;
    i64 speed;

    if (!test->isCompleted())
    {
        averageSpeed = progress                                * MemoryTest::getCpuSpeed() / (tsc - test->getStartTsc());
        speed        = (progress - test->getHandledProgress()) * MemoryTest::getCpuSpeed() / (tsc - test->getIntermediateTsc());
    }
    else
    {
        averageSpeed = test->getAverageSpeed();
        speed        = averageSpeed;
    }



    char8 *averageText = (char8 *)sAverageLabelWidgets[(enum_t)testType]->getText();

    i64 averageTextLength = sprintf(averageText, "Avg: %s/s", bytesToString(averageSpeed));
    UEFI_TEST_ASSERT(averageTextLength < AVERAGE_TEXT_LENGTH, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sAverageLabelWidgets[(enum_t)testType]->setText(averageText), NgosStatus::ASSERTION);



    if (speed > test->getMaximumSpeed())
    {
        UEFI_ASSERT_EXECUTION(test->setMaximumSpeed(speed), NgosStatus::ASSERTION);



        char8 *maximumText = (char8 *)sMaximumLabelWidgets[(enum_t)testType]->getText();

        i64 maximumTextLength = sprintf(maximumText, "Max: %s/s", bytesToString(speed));
        UEFI_TEST_ASSERT(maximumTextLength < MAXIMUM_TEXT_LENGTH, NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(sMaximumLabelWidgets[(enum_t)testType]->setText(maximumText), NgosStatus::ASSERTION);
    }



    if (!test->isCompleted())
    {
        char8 startBuffer[11];
        char8 endBuffer[11];

        UEFI_ASSERT_EXECUTION(bytesToString(progress,            startBuffer, sizeof(startBuffer)), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(bytesToString(test->getTestSize(), endBuffer,   sizeof(endBuffer)),   NgosStatus::ASSERTION);



        char8 *progressText = (char8 *)sProgressLabelWidgets[(enum_t)testType]->getText();

        i64 progressTextLength = sprintf(progressText, "%s / %s", startBuffer, endBuffer);
        UEFI_TEST_ASSERT(progressTextLength < PROGRESS_TEXT_LENGTH, NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(sProgressLabelWidgets[(enum_t)testType]->setText(progressText), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sProgressBarWidgets[(enum_t)testType]->setValue(progress),      NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(test->setHandledProgress(progress), NgosStatus::ASSERTION);
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



    i64 size = (sWaitEventsCount + 1) * sizeof(uefi_event); // "+ 1" = one more element for timer event



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&sWaitEvents) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for wait events", size));

        return NgosStatus::OUT_OF_MEMORY;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for wait events", sWaitEvents, size));



    sWaitEvents[0] = UEFI::getSystemTable()->stdin->waitForKey;
    u16 eventId    = 1;



    for (good_I64 i = 0; i < UefiPointerDevices::getSimplePointersCount(); ++i)
    {
        sWaitEvents[eventId] = UefiPointerDevices::getSimplePointer(i)->waitForInput;

        ++eventId;
    }



    for (good_I64 i = 0; i < UefiPointerDevices::getAbsolutePointersCount(); ++i)
    {
        sWaitEvents[eventId] = UefiPointerDevices::getAbsolutePointer(i)->waitForInput;

        ++eventId;
    }



    for (good_I64 i = eventId; i < sWaitEventsCount; ++i)
    {
        UEFI_ASSERT_EXECUTION(UEFI::createEvent(UefiEventType::NONE, UefiTpl::NONE, nullptr, nullptr, &sWaitEvents[i]), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
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



    if (sWaitEvents[eventIndex] == sTimerEvent)
    {
        return processTimerEvent();
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
        UEFI_TEST_ASSERT(sTerminated == false, NgosStatus::ASSERTION);

        sTerminated = true;



        while (sNumberOfRunningProcessors > 0)
        {
            u64 eventIndex;

            UEFI_ASSERT_EXECUTION(UEFI::waitForEvent(sWaitEventsCount, sWaitEvents, &eventIndex), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

            UEFI_LVVV(("eventIndex = %u", eventIndex));



            if (eventIndex >= sFirstProcessorEventIndex && sWaitEvents[eventIndex] != sTimerEvent)
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

    if (UEFI::getSystemTable()->stdin->readKeyStroke(UEFI::getSystemTable()->stdin, &key) == UefiStatus::SUCCESS)
    {
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
                status = onKeyboardEvent(key);

                if (status == NgosStatus::NO_EFFECT)
                {
                    status = GUI::processKeyboardEvent(key);
                }
            }
        }

        UEFI_TEST_ASSERT(status == NgosStatus::OK
                        ||
                        status == NgosStatus::NO_EFFECT, NgosStatus::ASSERTION);
    }



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

NgosStatus MemoryTestGUI::processApplicationProcessorEvent(i64 processorId)
{
    UEFI_LT((" | processorId = %u", processorId));



    UEFI_LV(("Application processor %u finished", processorId));



    if (!sTerminated)
    {
        TestType testType = sProcessorTasks[processorId];

        UEFI_TEST_ASSERT(testType < TestType::MAXIMUM, NgosStatus::ASSERTION);



        TestBase *test = memoryTests[(enum_t)testType];

        UEFI_TEST_ASSERT(test->isCompleted(), NgosStatus::ASSERTION);



        if (test->getProgress() != test->getHandledProgress())
        {
            UEFI_ASSERT_EXECUTION(updateTest(testType, AsmUtils::rdtsc()), NgosStatus::ASSERTION);
        }



        char8 *progressText = (char8 *)sProgressLabelWidgets[(enum_t)testType]->getText();

        i64 progressTextLength = sprintf(progressText, "Score: %u", test->getScore());
        UEFI_TEST_ASSERT(progressTextLength < PROGRESS_TEXT_LENGTH, NgosStatus::ASSERTION);



        UEFI_ASSERT_EXECUTION(sProgressLabelWidgets[(enum_t)testType]->setText(progressText), NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(sProgressBarWidgets[(enum_t)testType]->setVisible(false),       NgosStatus::ASSERTION);



        if (sCurrentTest < TestType::MAXIMUM)
        {
            TestBase *test = memoryTests[(enum_t)sCurrentTest];

            if (sMpServices->startupThisAP(sMpServices, test->getProcedure(), processorId, sWaitEvents[sFirstProcessorEventIndex + processorId], 0, test, nullptr) == UefiStatus::SUCCESS)
            {
                UEFI_ASSERT_EXECUTION(test->setStartTsc(AsmUtils::rdtsc()), NgosStatus::ASSERTION);

                UEFI_LV(("Test %s started on processor %u", enumToFullString(sCurrentTest), processorId));



                sProcessorTasks[processorId] = sCurrentTest;



                sCurrentTest = (TestType)((enum_t)sCurrentTest + 1);
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
        if (!sTerminated)
        {
            UEFI_ASSERT_EXECUTION(sTestStopButton->setContentImage(sCloseImage), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(disableTimerEvent(),                           NgosStatus::ASSERTION);



            i64 testTotal = 0;

            for (good_I64 i = 0; i < (i64)TestType::MAXIMUM; ++i)
            {
                testTotal += memoryTests[i]->getScore();
            }



            char8 *testTotalText = (char8 *)sTestingTotalLabelWidget->getText();

            i64 testTotalTextLength = sprintf(testTotalText, "Total: %u", testTotal);
            AVOID_UNUSED(testTotalTextLength);

            UEFI_TEST_ASSERT(testTotalTextLength < TEST_TOTAL_TEXT_LENGTH, NgosStatus::ASSERTION);



            UEFI_ASSERT_EXECUTION(sTestingTotalLabelWidget->setText(testTotalText), NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(sTestingTotalLabelWidget->setVisible(true),       NgosStatus::ASSERTION);



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

NgosStatus MemoryTestGUI::processTimerEvent()
{
    UEFI_LT((""));



    for (good_I64 i = 0; i < (i64)sCurrentTest; ++i)
    {
        TestBase *test = memoryTests[i];

        if (!test->isCompleted() && test->getProgress() != test->getHandledProgress())
        {
            i64 tsc = AsmUtils::rdtsc();

            UEFI_ASSERT_EXECUTION(updateTest((TestType)i, tsc), NgosStatus::ASSERTION);

            UEFI_ASSERT_EXECUTION(test->setIntermediateTsc(tsc), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::enableTimerEvent()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sTimerEvent == nullptr, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(UEFI::createEvent(UefiEventType::TIMER, UefiTpl::NONE, nullptr, nullptr, &sTimerEvent), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Created timer event(0x%p)", sTimerEvent));



    UEFI_ASSERT_EXECUTION(UEFI::setTimer(sTimerEvent, UefiTimerDelay::PERIODIC, UEFI_TIMER_SECOND), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Setup timer(0x%p) completed", sTimerEvent));



    sWaitEvents[sWaitEventsCount] = sTimerEvent;
    ++sWaitEventsCount;



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::disableTimerEvent()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sTimerEvent != nullptr, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(UEFI::closeEvent(sTimerEvent), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_LVV(("Closed timer event(0x%p)", sTimerEvent));

    sTimerEvent = nullptr;
    --sWaitEventsCount;



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

NgosStatus MemoryTestGUI::onIssuesTabButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus MemoryTestGUI::onTestTabButtonKeyboardEvent(const UefiInputKey &key)
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

NgosStatus MemoryTestGUI::onSummaryTabButtonKeyboardEvent(const UefiInputKey &key)
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
            if (sInfoRightButton->isVisible())
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

        case UefiInputKeyScanCode::LEFT:
        {
            if (sInfoLeftButton->isVisible())
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

        case UefiInputKeyScanCode::RIGHT: return onInfoRightButtonPressed();

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

NgosStatus MemoryTestGUI::onTestModeButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sTestTabButton);
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(!sTestButtonPages.isEmpty() ? (Widget *)sTestButtonPages.at(sTestCurrentPage)->first() : (Widget *)sRebootButton);

        case UefiInputKeyScanCode::RIGHT:
        {
            if (sTestAllButton != nullptr)
            {
                return GUI::setFocusedWidget(sTestAllButton);
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
        case KEY_TAB:
        {
            if (sTestAllButton != nullptr)
            {
                return GUI::setFocusedWidget(sTestAllButton);
            }

            return GUI::setFocusedWidget(!sTestButtonPages.isEmpty() ? (Widget *)sTestButtonPages.first()->first() : (Widget *)sRebootButton);
        }
        break;

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onTestAllButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sTestTabButton);
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(!sTestButtonPages.isEmpty() ? (Widget *)sTestButtonPages.at(sTestCurrentPage)->first() : (Widget *)sRebootButton);
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sTestModeButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB:
        {
            if (
                sTestLeftButton != nullptr
                &&
                sTestLeftButton->isVisible()
               )
            {
                UEFI_ASSERT_EXECUTION(showFirstTestPage(), NgosStatus::ASSERTION);
            }

            return GUI::setFocusedWidget(!sTestButtonPages.isEmpty() ? (Widget *)sTestButtonPages.first()->first() : (Widget *)sRebootButton);
        }
        break;

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onTestLeftButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sTestModeButton);
        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sRebootButton);
        case UefiInputKeyScanCode::LEFT: return onTestLeftButtonPressed();

        case UefiInputKeyScanCode::RIGHT:
        {
            if (sTestRightButton->isVisible())
            {
                if (sTestCurrentPage < sTestPages.getSize() - 2)
                {
                    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestRightButton), NgosStatus::ASSERTION);
                }

                return onTestRightButtonPressed();
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
        case KEY_TAB: return GUI::setFocusedWidget(sTestRightButton->isVisible() ? sTestRightButton : sRebootButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onTestRightButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:
        {
            if (sTestAllButton != nullptr)
            {
                return GUI::setFocusedWidget(sTestAllButton);
            }

            return GUI::setFocusedWidget(sTestModeButton);
        }
        break;

        case UefiInputKeyScanCode::DOWN: return GUI::setFocusedWidget(sRebootButton);

        case UefiInputKeyScanCode::LEFT:
        {
            if (sTestLeftButton->isVisible())
            {
                if (sTestCurrentPage > 1)
                {
                    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestLeftButton), NgosStatus::ASSERTION);
                }

                return onTestLeftButtonPressed();
            }

            return NgosStatus::NO_EFFECT;
        }
        break;

        case UefiInputKeyScanCode::RIGHT: return onTestRightButtonPressed();

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

NgosStatus MemoryTestGUI::onTestStartButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    ArrayList<Widget *> *page  = sTestButtonPages.at(sTestCurrentPage);
    i64                  index = page->indexOf(GUI::getFocusedWidget());



    if (DMI::getNumberOfInstalledMemoryDevices() > 2)
    {
        UEFI_TEST_ASSERT(index >= 0 && index < 4, NgosStatus::ASSERTION);



        switch (key.scanCode)
        {
            case UefiInputKeyScanCode::UP:
            {
                if (index >= 2)
                {
                    return GUI::setFocusedWidget(page->at(index - 2));
                }

                return GUI::setFocusedWidget(sTestModeButton);
            }
            break;

            case UefiInputKeyScanCode::DOWN:
            {
                if (index < 2)
                {
                    if (page->getSize() == 3)
                    {
                        return GUI::setFocusedWidget(page->at(2));
                    }
                    else
                    {
                        if (index + 2 < (i64)page->getSize())
                        {
                            return GUI::setFocusedWidget(page->at(index + 2));
                        }
                    }
                }

                return GUI::setFocusedWidget(sRebootButton);
            }
            break;

            case UefiInputKeyScanCode::LEFT:
            {
                if (
                    index == 0
                    ||
                    index == 2
                   )
                {
                    if (sTestLeftButton && sTestLeftButton->isVisible())
                    {
                        UEFI_ASSERT_EXECUTION(onTestLeftButtonPressed(), NgosStatus::ASSERTION);

                        return GUI::setFocusedWidget(sTestButtonPages.at(sTestCurrentPage)->at(index + 1));
                    }

                    return NgosStatus::NO_EFFECT;
                }
                else
                {
                    return GUI::setFocusedWidget(page->at(index - 1));
                }
            }
            break;

            case UefiInputKeyScanCode::RIGHT:
            {
                if (
                    index == 1
                    ||
                    index == 3
                   )
                {
                    if (sTestRightButton && sTestRightButton->isVisible())
                    {
                        UEFI_ASSERT_EXECUTION(onTestRightButtonPressed(), NgosStatus::ASSERTION);

                        page = sTestButtonPages.at(sTestCurrentPage);

                        if (index - 1 < (i64)page->getSize())
                        {
                            return GUI::setFocusedWidget(page->at(index - 1));
                        }

                        return GUI::setFocusedWidget(page->first());
                    }

                    return NgosStatus::NO_EFFECT;
                }
                else
                {
                    if (index + 1 < (i64)page->getSize())
                    {
                        return GUI::setFocusedWidget(page->at(index + 1));
                    }

                    return NgosStatus::NO_EFFECT;
                }
            }
            break;

            default:
            {
                // Nothing
            }
            break;
        }
    }
    else
    {
        UEFI_TEST_ASSERT(index >= 0 && index < 2, NgosStatus::ASSERTION);



        switch (key.scanCode)
        {
            case UefiInputKeyScanCode::UP:
            {
                if (index == 1)
                {
                    return GUI::setFocusedWidget(page->first());
                }

                return GUI::setFocusedWidget(sTestModeButton);
            }
            break;

            case UefiInputKeyScanCode::DOWN:
            {
                if (index == 0)
                {
                    if (page->getSize() == 2)
                    {
                        return GUI::setFocusedWidget(page->last());
                    }
                }

                return GUI::setFocusedWidget(sRebootButton);
            }
            break;

            default:
            {
                // Nothing
            }
            break;
        }
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB:
        {
            if (index + 1 < (i64)page->getSize())
            {
                return GUI::setFocusedWidget(page->at(index + 1));
            }

            if (sTestRightButton && sTestRightButton->isVisible())
            {
                UEFI_ASSERT_EXECUTION(onTestRightButtonPressed(), NgosStatus::ASSERTION);

                return GUI::setFocusedWidget(sTestButtonPages.at(sTestCurrentPage)->first());
            }

            return GUI::setFocusedWidget(sRebootButton);
        }
        break;

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onTestStopButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sTestTabButton);
        case UefiInputKeyScanCode::DOWN: return focusTestingTab();

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sListTabButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onListTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:    return GUI::setFocusedWidget(sTestStopButton);
        case UefiInputKeyScanCode::DOWN:  return focusTestingTabFirstWidget();
        case UefiInputKeyScanCode::RIGHT: return GUI::setFocusedWidget(sChartTabButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return GUI::setFocusedWidget(sChartTabButton);

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus MemoryTestGUI::onChartTabButtonKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:   return GUI::setFocusedWidget(sTestStopButton);
        case UefiInputKeyScanCode::DOWN: return focusTestingTabFirstWidget();
        case UefiInputKeyScanCode::LEFT: return GUI::setFocusedWidget(sListTabButton);

        default:
        {
            // Nothing
        }
        break;
    }



    switch (key.unicodeChar)
    {
        case KEY_TAB: return focusTestingTabFirstWidget();

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

NgosStatus MemoryTestGUI::onKeyboardEvent(const UefiInputKey &key)
{
    UEFI_LT((" | key = ..."));



    switch (sTabWidget->getCurrentPage())
    {
        case TABWIDGET_PAGE_SYSTEM_INFORMATION:
        {
            if (sInfoPages.getSize() > 1)
            {
                switch (key.scanCode)
                {
                    case UefiInputKeyScanCode::HOME: return showFirstInfoPage();
                    case UefiInputKeyScanCode::END:  return showLastInfoPage();

                    case UefiInputKeyScanCode::PAGE_UP:
                    {
                        if (sInfoLeftButton->isVisible())
                        {
                            return onInfoLeftButtonPressed();
                        }

                        return NgosStatus::NO_EFFECT;
                    }
                    break;

                    case UefiInputKeyScanCode::PAGE_DOWN:
                    {
                        if (sInfoRightButton->isVisible())
                        {
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
            }
        }
        break;

        case TABWIDGET_PAGE_TEST:
        {
            if (sTestPages.getSize() > 1)
            {
                switch (key.scanCode)
                {
                    case UefiInputKeyScanCode::HOME: return showFirstTestPage();
                    case UefiInputKeyScanCode::END:  return showLastTestPage();

                    case UefiInputKeyScanCode::PAGE_UP:
                    {
                        if (sTestLeftButton->isVisible())
                        {
                            return onTestLeftButtonPressed();
                        }

                        return NgosStatus::NO_EFFECT;
                    }
                    break;

                    case UefiInputKeyScanCode::PAGE_DOWN:
                    {
                        if (sTestRightButton->isVisible())
                        {
                            return onTestRightButtonPressed();
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
            }
        }
        break;

        case TABWIDGET_PAGE_ISSUES:
        case TABWIDGET_PAGE_SUMMARY:
        {
            // Nothing
        }
        break;

        default:
        {
            UEFI_LF(("Unknown tab page: %d, %s:%u", sTabWidget->getCurrentPage(), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
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

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sInfoPageIndicators.at(sInfoCurrentPage)->setResizedImage(sInfoPageIndicatorResizedImage), NgosStatus::ASSERTION);



    --sInfoCurrentPage;



    page = sInfoPages.at(sInfoCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sInfoPageIndicators.at(sInfoCurrentPage)->setResizedImage(sInfoPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sInfoRightButton->setVisible(true), NgosStatus::ASSERTION);

    if (sInfoCurrentPage <= 0)
    {
        UEFI_ASSERT_EXECUTION(sInfoLeftButton->setVisible(false), NgosStatus::ASSERTION);

        if (sInfoLeftButton->isFocused())
        {
            UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sInfoRightButton), NgosStatus::ASSERTION);
        }
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

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sInfoPageIndicators.at(sInfoCurrentPage)->setResizedImage(sInfoPageIndicatorResizedImage), NgosStatus::ASSERTION);



    ++sInfoCurrentPage;



    page = sInfoPages.at(sInfoCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sInfoPageIndicators.at(sInfoCurrentPage)->setResizedImage(sInfoPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sInfoLeftButton->setVisible(true), NgosStatus::ASSERTION);

    if (sInfoCurrentPage >= sInfoPages.getSize() - 1)
    {
        UEFI_ASSERT_EXECUTION(sInfoRightButton->setVisible(false), NgosStatus::ASSERTION);

        if (sInfoRightButton->isFocused())
        {
            UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sInfoLeftButton), NgosStatus::ASSERTION);
        }
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onTestModeButtonPressed()
{
    UEFI_LT((""));



    sMode = (TestMode)((enum_t)sMode + 1);

    if ((enum_t)sMode >= (enum_t)TestMode::MAXIMUM)
    {
        sMode = TestMode::QUICK_TEST;
    }



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(sTestModeButton->setContentImage(sModeImages[(enum_t)sMode]), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sTestModeButton->setText(enumToHumanString(sMode)),           NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onTestAllButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(startTest(-1), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onTestLeftButtonPressed()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sTestCurrentPage > 0, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    i64 index = sTestButtonPages.at(sTestCurrentPage)->indexOf(GUI::getFocusedWidget());



    ArrayList<PanelWidget *> *page = sTestPages.at(sTestCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sTestPageIndicators.at(sTestCurrentPage)->setResizedImage(sTestPageIndicatorResizedImage), NgosStatus::ASSERTION);



    --sTestCurrentPage;



    page = sTestPages.at(sTestCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sTestPageIndicators.at(sTestCurrentPage)->setResizedImage(sTestPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



    if (index >= 0)
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestButtonPages.at(sTestCurrentPage)->first()), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sTestRightButton->setVisible(true), NgosStatus::ASSERTION);

    if (sTestCurrentPage <= 0)
    {
        UEFI_ASSERT_EXECUTION(sTestLeftButton->setVisible(false), NgosStatus::ASSERTION);

        if (sTestLeftButton->isFocused())
        {
            UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestRightButton), NgosStatus::ASSERTION);
        }
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onTestRightButtonPressed()
{
    UEFI_LT((""));



    UEFI_TEST_ASSERT(sTestCurrentPage < sTestPages.getSize() - 1, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    i64 index = sTestButtonPages.at(sTestCurrentPage)->indexOf(GUI::getFocusedWidget());



    ArrayList<PanelWidget *> *page = sTestPages.at(sTestCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(false), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sTestPageIndicators.at(sTestCurrentPage)->setResizedImage(sTestPageIndicatorResizedImage), NgosStatus::ASSERTION);



    ++sTestCurrentPage;



    page = sTestPages.at(sTestCurrentPage);

    for (good_I64 i = 0; i < (i64)page->getSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(page->at(i)->setVisible(true), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sTestPageIndicators.at(sTestCurrentPage)->setResizedImage(sTestPageIndicatorSelectedResizedImage), NgosStatus::ASSERTION);



    if (index >= 0)
    {
        UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestButtonPages.at(sTestCurrentPage)->first()), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sTestLeftButton->setVisible(true), NgosStatus::ASSERTION);

    if (sTestCurrentPage >= sTestPages.getSize() - 1)
    {
        UEFI_ASSERT_EXECUTION(sTestRightButton->setVisible(false), NgosStatus::ASSERTION);

        if (sTestRightButton->isFocused())
        {
            UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sTestLeftButton), NgosStatus::ASSERTION);
        }
    }



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onTestStartButtonPressed()
{
    UEFI_LT((""));



    i64 index = sTestButtonPages.at(sTestCurrentPage)->indexOf(GUI::getFocusedWidget());

    UEFI_TEST_ASSERT(index >= 0 && index < 4, NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(startTest(sTestCurrentPage * 4 + index), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onTestStopButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    if (sTimerEvent != nullptr)
    {
        UEFI_TEST_ASSERT(sNumberOfRunningProcessors >  0,     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(sTerminated                == false, NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(disableTimerEvent(),                        NgosStatus::ASSERTION);
        UEFI_ASSERT_EXECUTION(terminateAndWaitForApplicationProcessors(), NgosStatus::ASSERTION);
    }



    UEFI_ASSERT_EXECUTION(sTestRunningWrapperWidget->setVisible(false), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(GUI::setFocusedWidget(sLastFocusedWidget), NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(sTestSettingsWrapperWidget->setVisible(true), NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onListTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTestingTabWidget->setCurrentPage(TESTING_TABWIDGET_PAGE_LIST), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryTestGUI::onChartTabButtonPressed()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sTestingTabWidget->setCurrentPage(TESTING_TABWIDGET_PAGE_CHART), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
