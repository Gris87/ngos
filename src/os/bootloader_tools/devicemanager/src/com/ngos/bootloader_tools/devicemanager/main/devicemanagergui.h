#ifndef DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_MAIN_DEVICEMANAGERGUI_H
#define DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_MAIN_DEVICEMANAGERGUI_H



#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerimage.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagermode.h>
#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/common/gui/widgets/controls/button.h>
#include <com/ngos/shared/common/gui/widgets/controls/tablewidget.h>
#include <com/ngos/shared/common/gui/widgets/controls/tabwidget.h>
#include <com/ngos/shared/common/gui/widgets/controls/treewidget.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerprotocol.h>
#include <com/ngos/shared/common/uefi/uefisimplepointerprotocol.h>



class DeviceManagerGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO

private:
    static NgosStatus fillDevicesTree(); // TEST: NO
    static NgosStatus fillDevicesTreeForDmi(Image *toolButtonNormalImage, Image *toolButtonHoverImage, Image *toolButtonPressedImage, Image *toolButtonNormalResizedImage, Image *toolButtonHoverResizedImage, Image *toolButtonPressedResizedImage, Image *collapsedImage, Image *expandedImage); // TEST: NO
    static NgosStatus fillDevicesTreeForPci(Image *toolButtonNormalImage, Image *toolButtonHoverImage, Image *toolButtonPressedImage, Image *toolButtonNormalResizedImage, Image *toolButtonHoverResizedImage, Image *toolButtonPressedResizedImage, Image *collapsedImage, Image *expandedImage); // TEST: NO
    static NgosStatus fillDevicesTreeForMemoryMap(Image *toolButtonNormalImage, Image *toolButtonHoverImage, Image *toolButtonPressedImage, Image *toolButtonNormalResizedImage, Image *toolButtonHoverResizedImage, Image *toolButtonPressedResizedImage, Image *collapsedImage, Image *expandedImage); // TEST: NO
    static NgosStatus fillDeviceInfoTableWidget(DeviceManagerEntry *entry); // TEST: NO

    static NgosStatus generateWaitEventList(); // TEST: NO
    static NgosStatus waitForEvent(); // TEST: NO
    static NgosStatus processKeyboardEvent(); // TEST: NO
    static NgosStatus processSimplePointerEvent(UefiSimplePointerProtocol *pointer); // TEST: NO
    static NgosStatus processAbsolutePointerEvent(UefiAbsolutePointerProtocol *pointer); // TEST: NO

    static NgosStatus onRebootButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onShutdownButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onDevicesTreeWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onDeviceInfoTableWidgetKeyboardEvent(const UefiInputKey &key); // TEST: NO
    static NgosStatus onModeButtonKeyboardEvent(const UefiInputKey &key); // TEST: NO

    static NgosStatus onRebootButtonPressed(); // TEST: NO
    static NgosStatus onShutdownButtonPressed(); // TEST: NO
    static NgosStatus onModeButtonPressed(); // TEST: NO

    static NgosStatus onDevicesTreeWidgetNodeSelected(TreeNodeWidget *node); // TEST: NO

    static Image* getImage(DeviceManagerImage image); // TEST: NO

    static Button            *sRebootButton;
    static Button            *sShutdownButton;
    static TreeWidget        *sDevicesTreeWidget;
    static TableWidget       *sDeviceInfoTableWidget;
    static Button            *sModeButton;
    static u16                sWaitEventsCount;
    static uefi_event        *sWaitEvents;
    static DeviceManagerMode  sMode;
    static Image*             sImages[(u64)DeviceManagerImage::MAXIMUM];
    static Image*             sModeImages[(u64)DeviceManagerMode::MAXIMUM];
    static const char8*       sImagesPath[(u64)DeviceManagerImage::MAXIMUM];
    static const char8*       sModeImagesPath[(u64)DeviceManagerMode::MAXIMUM];
};



#endif // DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_MAIN_DEVICEMANAGERGUI_H
