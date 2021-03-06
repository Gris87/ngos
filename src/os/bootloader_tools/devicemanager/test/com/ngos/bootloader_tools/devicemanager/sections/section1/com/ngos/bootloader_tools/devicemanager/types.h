#ifndef COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_TYPES_H
#define COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_TYPES_H



#include <buildconfig.h>
#include <com/ngos/bootloader_tools/devicemanager/main/devicemanager.h>
#include <com/ngos/bootloader_tools/devicemanager/main/devicemanagergui.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentry.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrydmi.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentrypci.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerentryrecord.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagerimage.h>
#include <com/ngos/bootloader_tools/devicemanager/other/devicemanagermode.h>
#include <com/ngos/bootloader_tools/devicemanager/sources/devicemanagerdmi.h>
#include <com/ngos/bootloader_tools/devicemanager/sources/devicemanagermemorymap.h>
#include <com/ngos/bootloader_tools/devicemanager/sources/devicemanagerpci.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_bootloader_tools_devicemanager_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(DeviceManager),            1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerDMI),         1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerEntry),       48);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerEntryDMI),    56);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerEntryPCI),    72);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerEntryRecord), 24);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerGUI),         1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerImage),       1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerMemoryMap),   1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerMode),        1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerPci),         1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_TYPES_H
