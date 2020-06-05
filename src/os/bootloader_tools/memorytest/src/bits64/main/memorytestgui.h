#ifndef MEMORYTEST_SRC_BITS64_MAIN_MEMORYTESTGUI_H
#define MEMORYTEST_SRC_BITS64_MAIN_MEMORYTESTGUI_H



#include <bootparams/bootparams.h>
#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/dmi/dmimemorydevice.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/controls/tablewidget.h>
#include <common/src/bits64/gui/widgets/controls/tabwidget.h>
#include <common/src/bits64/gui/widgets/misc/panelwidget.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefimpservicesprotocol.h>
#include <uefi/uefisimplepointerprotocol.h>



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
    static NgosStatus addSummaryEntry(const char8 *name, u64 score); // TEST: NO
    static NgosStatus fillSummaryTable(); // TEST: NO

    static NgosStatus focusTabFirstWidget(); // TEST: NO
    static NgosStatus focusTabLastWidget(); // TEST: NO

    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus terminateAndWaitForApplicationProcessors(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO
    static NgosStatus processApplicationProcessorEvent(u64 processorId); // TEST: NO

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onIssuesTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSummaryTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onInfoLeftButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onInfoRightButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onIssuesTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSummaryTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO
    static NgosStatus onSystemInformationTabButtonPressed(); // TEST: NO
    static NgosStatus onIssuesTabButtonPressed(); // TEST: NO
    static NgosStatus onTestTabButtonPressed(); // TEST: NO
    static NgosStatus onSummaryTabButtonPressed(); // TEST: NO
    static NgosStatus onInfoLeftButtonPressed(); // TEST: NO
    static NgosStatus onInfoRightButtonPressed(); // TEST: NO

    static Button                                *sRebootButton;
    static Button                                *sShutdownButton;
    static TabWidget                             *sTabWidget;
    static TabButton                             *sSystemInformationTabButton;
    static TabButton                             *sIssuesTabButton;
    static TabButton                             *sTestTabButton;
    static TabButton                             *sSummaryTabButton;
    static ArrayList<ArrayList<PanelWidget *> *>  sInfoPages;
    static u64                                    sInfoCurrentPage;
    static Button                                *sInfoLeftButton;
    static Button                                *sInfoRightButton;
    static Image                                 *sWarningImage;
    static Image                                 *sCriticalImage;
    static TableWidget                           *sIssuesTableWidget;
    static Image                                 *sStartImage;
    static Image                                 *sStopImage;
    static LabelWidget                           *sSummaryTotalLabelWidget;
    static TableWidget                           *sSummaryTableWidget;
    static u64                                    sSummaryTotal;
    static UefiMpServicesProtocol                *sMpServices;
    static u16                                    sWaitEventsCount;
    static uefi_event                            *sWaitEvents;
    static u16                                    sFirstProcessorEventIndex;
    static u64                                    sNumberOfRunningProcessors;
    static bool                                   sTerminated;
};



#endif // MEMORYTEST_SRC_BITS64_MAIN_MEMORYTESTGUI_H
