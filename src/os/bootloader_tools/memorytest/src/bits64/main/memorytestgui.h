#ifndef MEMORYTEST_SRC_BITS64_MAIN_MEMORYTESTGUI_H
#define MEMORYTEST_SRC_BITS64_MAIN_MEMORYTESTGUI_H



#include <bootparams/bootparams.h>
#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/dmi/dmimemorydevice.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/controls/tablewidget.h>
#include <common/src/bits64/gui/widgets/controls/tabwidget.h>
#include <common/src/bits64/gui/widgets/misc/panelwidget.h>
#include <common/src/bits64/gui/widgets/misc/progressbarwidget.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefimpservicesprotocol.h>
#include <uefi/uefisimplepointerprotocol.h>

#include "src/bits64/other/memorytestmode.h"
#include "src/bits64/other/memorytesttype.h"



class MemoryTestGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO

    static inline bool isTerminated() // TEST: NO
    {
        // UEFI_LT(("")); // Commented to avoid bad looking logs



        return sTerminated;
    }

private:
    static NgosStatus addMemoryInfoPanel(u64 pageIndex, u64 posX, u64 posY, u64 width, u64 height, Image *memoryInfoPanelImage, Image *memoryInfoPanelResizedImage, Image *memoryDeviceImage, Image *memoryDeviceResizedImage, Image *memoryDeviceDisabledImage, Image *memoryDeviceDisabledResizedImage, TabPageWidget *tabPageWidget, const DmiMemoryDevice &memoryDevice); // TEST: NO
    static NgosStatus addIssueEntry(Image *icon, const char8 *description); // TEST: NO
    static NgosStatus fillIssuesTable(); // TEST: NO
    static NgosStatus addMemoryTestPanel(u64 pageIndex, u64 posX, u64 posY, u64 width, u64 height, Image *memoryTestPanelImage, Image *memoryTestPanelResizedImage, Image *memoryDeviceImage, Image *memoryDeviceResizedImage, Image *buttonNormalImage, Image *buttonHoverImage, Image *buttonPressedImage, Image *buttonFocusedImage, Image *buttonFocusedHoverImage, Image *buttonNormalResizedImage, Image *buttonHoverResizedImage, Image *buttonPressedResizedImage, Image *buttonFocusedResizedImage, Image *buttonFocusedHoverResizedImage, Image *startImage, Image *startResizedImage, u64 memoryTestStartButtonWidth, u64 memoryTestStartButtonHeight, const DmiMemoryDevice &memoryDevice); // TEST: NO
    static NgosStatus addSummaryEntry(const char8 *name, u64 score); // TEST: NO
    static NgosStatus fillSummaryTable(); // TEST: NO

    static NgosStatus focusTabFirstWidget(); // TEST: NO
    static NgosStatus focusTabLastWidget(); // TEST: NO
    static NgosStatus focusTestingTabFirstWidget(); // TEST: NO
    static NgosStatus focusTestingTabLastWidget(); // TEST: NO
    static NgosStatus focusTestingTab(); // TEST: NO

    static NgosStatus showFirstInfoPage(); // TEST: NO
    static NgosStatus showLastInfoPage(); // TEST: NO
    static NgosStatus showFirstTestPage(); // TEST: NO
    static NgosStatus showLastTestPage(); // TEST: NO

    static NgosStatus startTest(i64 id); // TEST: NO

    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus terminateAndWaitForApplicationProcessors(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO
    static NgosStatus processApplicationProcessorEvent(u64 processorId); // TEST: NO
    static NgosStatus processTimerEvent(); // TEST: NO
    static NgosStatus enableTimerEvent(); // TEST: NO
    static NgosStatus disableTimerEvent(); // TEST: NO

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onIssuesTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSummaryTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onInfoLeftButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onInfoRightButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onIssuesTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestModeButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestAllButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestLeftButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestRightButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestStartButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestStopButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onListTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onChartTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSummaryTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO
    static NgosStatus onSystemInformationTabButtonPressed(); // TEST: NO
    static NgosStatus onIssuesTabButtonPressed(); // TEST: NO
    static NgosStatus onTestTabButtonPressed(); // TEST: NO
    static NgosStatus onSummaryTabButtonPressed(); // TEST: NO
    static NgosStatus onInfoLeftButtonPressed(); // TEST: NO
    static NgosStatus onInfoRightButtonPressed(); // TEST: NO
    static NgosStatus onTestModeButtonPressed(); // TEST: NO
    static NgosStatus onTestAllButtonPressed(); // TEST: NO
    static NgosStatus onTestLeftButtonPressed(); // TEST: NO
    static NgosStatus onTestRightButtonPressed(); // TEST: NO
    static NgosStatus onTestStartButtonPressed(); // TEST: NO
    static NgosStatus onTestStopButtonPressed(); // TEST: NO
    static NgosStatus onListTabButtonPressed(); // TEST: NO
    static NgosStatus onChartTabButtonPressed(); // TEST: NO

    static Button                                *sRebootButton;
    static Button                                *sShutdownButton;
    static TabWidget                             *sTabWidget;
    static TabButton                             *sSystemInformationTabButton;
    static TabButton                             *sIssuesTabButton;
    static TabButton                             *sTestTabButton;
    static TabButton                             *sSummaryTabButton;
    static ArrayList<ArrayList<PanelWidget *> *>  sInfoPages;
    static ArrayList<ImageWidget *>               sInfoPageIndicators;
    static Image                                 *sInfoPageIndicatorResizedImage;
    static Image                                 *sInfoPageIndicatorSelectedResizedImage;
    static u64                                    sInfoCurrentPage;
    static Button                                *sInfoLeftButton;
    static Button                                *sInfoRightButton;
    static Image                                 *sWarningImage;
    static Image                                 *sCriticalImage;
    static TableWidget                           *sIssuesTableWidget;
    static WrapperWidget                         *sTestSettingsWrapperWidget;
    static Button                                *sTestModeButton;
    static Button                                *sTestAllButton;
    static ArrayList<ArrayList<PanelWidget *> *>  sTestPages;
    static ArrayList<ArrayList<Widget *> *>       sTestButtonPages;
    static ArrayList<ImageWidget *>               sTestPageIndicators;
    static Image                                 *sTestPageIndicatorResizedImage;
    static Image                                 *sTestPageIndicatorSelectedResizedImage;
    static u64                                    sTestCurrentPage;
    static Button                                *sTestLeftButton;
    static Button                                *sTestRightButton;
    static WrapperWidget                         *sTestRunningWrapperWidget;
    static Image                                 *sStopImage;
    static Image                                 *sCloseImage;
    static Button                                *sTestStopButton;
    static Widget                                *sLastFocusedWidget;
    static LabelWidget                           *sTestingSizeLabelWidget;
    static LabelWidget                           *sTestingRangeLabelWidget;
    static LabelWidget                           *sTestingModeLabelWidget;
    static LabelWidget                           *sTestingDeviceLocatorLabelWidget;
    static LabelWidget                           *sTestingManufacturerLabelWidget;
    static LabelWidget                           *sTestingSerialNumberLabelWidget;
    static LabelWidget                           *sTestingPartNumberLabelWidget;
    static LabelWidget                           *sTestingTotalLabelWidget;
    static TabWidget                             *sTestingTabWidget;
    static TabButton                             *sListTabButton;
    static TabButton                             *sChartTabButton;
    static LabelWidget                           *sSequentialReadAverageLabelWidget;
    static LabelWidget                           *sSequentialReadMaximumLabelWidget;
    static LabelWidget                           *sSequentialReadProgressLabelWidget;
    static ProgressBarWidget                     *sSequentialReadProgressBarWidget;
    static LabelWidget                           *sSequentialWriteAverageLabelWidget;
    static LabelWidget                           *sSequentialWriteMaximumLabelWidget;
    static LabelWidget                           *sSequentialWriteProgressLabelWidget;
    static ProgressBarWidget                     *sSequentialWriteProgressBarWidget;
    static LabelWidget                           *sRandomReadAverageLabelWidget;
    static LabelWidget                           *sRandomReadMaximumLabelWidget;
    static LabelWidget                           *sRandomReadProgressLabelWidget;
    static ProgressBarWidget                     *sRandomReadProgressBarWidget;
    static LabelWidget                           *sRandomWriteAverageLabelWidget;
    static LabelWidget                           *sRandomWriteMaximumLabelWidget;
    static LabelWidget                           *sRandomWriteProgressLabelWidget;
    static ProgressBarWidget                     *sRandomWriteProgressBarWidget;
    static LabelWidget                           *sSummaryTotalLabelWidget;
    static TableWidget                           *sSummaryTableWidget;
    static u64                                    sSummaryTotal;
    static UefiMpServicesProtocol                *sMpServices;
    static u16                                    sWaitEventsCount;
    static uefi_event                            *sWaitEvents;
    static uefi_event                             sTimerEvent;
    static u16                                    sFirstProcessorEventIndex;
    static MemoryTestType                         sCurrentTest;
    static u64                                    sNumberOfRunningProcessors;
    static bool                                   sTerminated;
    static MemoryTestMode                         sMode;
    static Image*                                 sModeImages[(u64)MemoryTestMode::MAXIMUM];
    static const char8*                           sModeImagesPath[(u64)MemoryTestMode::MAXIMUM];
};



#endif // MEMORYTEST_SRC_BITS64_MAIN_MEMORYTESTGUI_H
