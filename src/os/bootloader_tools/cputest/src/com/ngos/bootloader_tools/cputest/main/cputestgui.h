#ifndef CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTESTGUI_H
#define CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTESTGUI_H



#include <common/src/com/ngos/shared/common/bootparams/bootparams.h>
#include <common/src/com/ngos/shared/common/containers/arraylist.h>
#include <common/src/com/ngos/shared/common/cpu/x86feature.h>
#include <common/src/com/ngos/shared/common/gui/widgets/controls/button.h>
#include <common/src/com/ngos/shared/common/gui/widgets/controls/tablewidget.h>
#include <common/src/com/ngos/shared/common/gui/widgets/controls/tabwidget.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointerprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefimpservicesprotocol.h>
#include <common/src/com/ngos/shared/common/uefi/uefisimplepointerprotocol.h>

#include "src/com/ngos/bootloader_tools/cputest/other/testtype.h"



class CpuTestGUI
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
    static NgosStatus addFeaturePanel(X86Feature flag, u64 posX, u64 posY, u64 width, u64 height, Image *featurePanelImage, Image *featurePanelResizedImage, TabPageWidget *tabPageWidget); // TEST: NO
    static NgosStatus addIssueEntry(Image *icon, const char8 *description); // TEST: NO
    static NgosStatus fillIssuesTable(); // TEST: NO
    static NgosStatus addTestEntry(const char8 *name, const char8 *score); // TEST: NO
    static NgosStatus addTestEntry(); // TEST: NO
    static NgosStatus putTestScore(); // TEST: NO
    static NgosStatus addSummaryEntry(const char8 *name, u64 score); // TEST: NO
    static NgosStatus addSummaryFeature(X86Feature flag, u64 score); // TEST: NO
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
    static NgosStatus onIssuesTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onStartButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSummaryTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO
    static NgosStatus onSystemInformationTabButtonPressed(); // TEST: NO
    static NgosStatus onIssuesTabButtonPressed(); // TEST: NO
    static NgosStatus onTestTabButtonPressed(); // TEST: NO
    static NgosStatus onSummaryTabButtonPressed(); // TEST: NO
    static NgosStatus onStartButtonPressed(); // TEST: NO

    static Button                 *sRebootButton;
    static Button                 *sShutdownButton;
    static TabWidget              *sTabWidget;
    static TabButton              *sSystemInformationTabButton;
    static TabButton              *sIssuesTabButton;
    static TabButton              *sTestTabButton;
    static TabButton              *sSummaryTabButton;
    static Image                  *sWarningImage;
    static Image                  *sCriticalImage;
    static TableWidget            *sIssuesTableWidget;
    static Button                 *sStartButton;
    static Image                  *sStartImage;
    static Image                  *sStopImage;
    static LabelWidget            *sTestTotalLabelWidget;
    static TableWidget            *sTestTableWidget;
    static LabelWidget            *sSummaryTotalLabelWidget;
    static TableWidget            *sSummaryTableWidget;
    static u64                     sSummaryTotal;
    static UefiMpServicesProtocol *sMpServices;
    static u16                     sWaitEventsCount;
    static uefi_event             *sWaitEvents;
    static u16                     sFirstProcessorEventIndex;
    static TestType                sCurrentTest;
    static TestType                sDisplayedTest;
    static u64                     sNumberOfRunningProcessors;
    static bool                    sTerminated;
};



#endif // CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTESTGUI_H
