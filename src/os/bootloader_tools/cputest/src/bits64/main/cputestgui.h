#ifndef CPUTEST_SRC_BITS64_MAIN_CPUTESTGUI_H
#define CPUTEST_SRC_BITS64_MAIN_CPUTESTGUI_H



#include <bootparams/bootparams.h>
#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/controls/tabwidget.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefisimplepointerprotocol.h>



class CpuTestGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO

private:
    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSystemInformationTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onTestTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onSummaryTabButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO
    static NgosStatus onSystemInformationTabButtonPressed(); // TEST: NO
    static NgosStatus onTestTabButtonPressed(); // TEST: NO
    static NgosStatus onSummaryTabButtonPressed(); // TEST: NO

    static Button     *sRebootButton;
    static Button     *sShutdownButton;
    static TabWidget  *sTabWidget;
    static Button     *sSystemInformationTabButton;
    static Button     *sTestTabButton;
    static Button     *sSummaryTabButton;
    static u16         sWaitEventsCount;
    static uefi_event *sWaitEvents;
};



#endif // CPUTEST_SRC_BITS64_MAIN_CPUTESTGUI_H
