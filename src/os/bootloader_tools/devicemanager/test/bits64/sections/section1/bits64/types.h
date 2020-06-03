#ifndef DEVICEMANAGER_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
#define DEVICEMANAGER_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/bits64/main/devicemanager.h"
#include "src/bits64/main/devicemanagergui.h"
#include "src/bits64/other/devicemanagerentry.h"
#include "src/bits64/other/devicemanagerentrydmi.h"
#include "src/bits64/other/devicemanagerentryrecord.h"
#include "src/bits64/other/devicemanagerimage.h"
#include "src/bits64/other/devicemanagermode.h"
#include "src/bits64/sources/dmi/devicemanagerdmi.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(DeviceManager),            1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerDMI),         1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerEntry),       48);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerEntryDMI),    56);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerEntryRecord), 24);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerGUI),         1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerImage),       1);
        TEST_ASSERT_EQUALS(sizeof(DeviceManagerMode),        1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // DEVICEMANAGER_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
