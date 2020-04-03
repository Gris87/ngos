#ifndef DEVICEMANAGER_SRC_BITS64_MAIN_DEVICEMANAGERGUI_H
#define DEVICEMANAGER_SRC_BITS64_MAIN_DEVICEMANAGERGUI_H



#include <bootparams/bootparams.h>
#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/controls/tablewidget.h>
#include <common/src/bits64/gui/widgets/controls/tabwidget.h>
#include <common/src/bits64/gui/widgets/controls/treewidget.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefisimplepointerprotocol.h>

#include "src/bits64/main/other/devicemanagerimage.h"



class DeviceManagerGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO

private:
    static NgosStatus fillDevicesTree(); // TEST: NO
    static NgosStatus fillDevicesTreeForDmi(Image *toolButtonNormalImage, Image *toolButtonHoverImage, Image *toolButtonPressedImage, Image *toolButtonNormalResizedImage, Image *toolButtonHoverResizedImage, Image *toolButtonPressedResizedImage, Image *collapsedImage, Image *expandedImage); // TEST: NO
    static NgosStatus addDeviceInfoEntry(const char8 *name, const char8 *value); // TEST: NO

    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onDevicesTreeWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onDeviceInfoTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO

    static Image* getImage(DeviceManagerImage image); // TEST: NO

    static Button      *sRebootButton;
    static Button      *sShutdownButton;
    static TreeWidget  *sDevicesTreeWidget;
    static TableWidget *sDeviceInfoTableWidget;
    static u16          sWaitEventsCount;
    static uefi_event  *sWaitEvents;
    static RgbaPixel    sBlackColor;
    static Image*       sImages[(u64)DeviceManagerImage::MAXIMUM];
    static const char8* sImagesPath[(u64)DeviceManagerImage::MAXIMUM];
};



#endif // DEVICEMANAGER_SRC_BITS64_MAIN_DEVICEMANAGERGUI_H
