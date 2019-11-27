#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_UEFI_UEFI_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_UEFI_UEFI_H



#include <buildconfig.h>
#include <common/src/bits64/memory/malloc.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/string.h>
#include <uefibase/src/bits64/uefi/uefi.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_uefibase_bits64_uefi_uefi);
{
    TEST_CASE("parentDirectory()");
    {
        char16 *res1 = UEFI::parentDirectory(u"\\EFI\\BOOT\\bootx64.efi");
        char16 *res2 = UEFI::parentDirectory(u"\\EFI\\BOOT\\images\\background.jpg");

        TEST_ASSERT_EQUALS(strcmp(res1, u"\\EFI\\BOOT"),         0);
        TEST_ASSERT_EQUALS(strcmp(res2, u"\\EFI\\BOOT\\images"), 0);

        TEST_ASSERT_EQUALS(free(res1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(res2), NgosStatus::OK);
    }
    TEST_CASE_END();



    TEST_CASE("nextDevicePathNode()");
    {
        u8 buffer[10];
        memzero(buffer, sizeof(buffer));



        UefiDevicePath *path = (UefiDevicePath *)buffer;

        path->type    = UefiDevicePathType::MEDIA_DEVICE_PATH;
        path->subType = UefiDevicePathSubType::MEDIA_HARDDRIVE_DP;
        path->length  = 4;

        TEST_ASSERT_EQUALS(UEFI::nextDevicePathNode(path), (UefiDevicePath *)&buffer[4]);
    }
    TEST_CASE_END();



    TEST_CASE("setDevicePathEndNode()");
    {
        u8 buffer[10];
        memzero(buffer, sizeof(buffer));



        UefiDevicePath *path = (UefiDevicePath *)buffer;

        path->type    = UefiDevicePathType::MEDIA_DEVICE_PATH;
        path->subType = UefiDevicePathSubType::MEDIA_HARDDRIVE_DP;
        path->length  = 4;

        UefiDevicePath *path2 = UEFI::nextDevicePathNode(path);
        TEST_ASSERT_EQUALS(UEFI::setDevicePathEndNode(path2), NgosStatus::OK);

        TEST_ASSERT_EQUALS(buffer[0], 4);
        TEST_ASSERT_EQUALS(buffer[1], 1);
        TEST_ASSERT_EQUALS(buffer[2], 4);
        TEST_ASSERT_EQUALS(buffer[3], 0);
        TEST_ASSERT_EQUALS(buffer[4], 127);
        TEST_ASSERT_EQUALS(buffer[5], 255);
        TEST_ASSERT_EQUALS(buffer[6], 4);
        TEST_ASSERT_EQUALS(buffer[7], 0);
        TEST_ASSERT_EQUALS(buffer[8], 0);
        TEST_ASSERT_EQUALS(buffer[9], 0);
    }
    TEST_CASE_END();



    TEST_CASE("isDevicePathEndType()");
    {
        u8 buffer[10];
        memzero(buffer, sizeof(buffer));



        UefiDevicePath *path = (UefiDevicePath *)buffer;

        path->type    = UefiDevicePathType::MEDIA_DEVICE_PATH;
        path->subType = UefiDevicePathSubType::MEDIA_HARDDRIVE_DP;
        path->length  = 4;

        UefiDevicePath *path2 = UEFI::nextDevicePathNode(path);
        TEST_ASSERT_EQUALS(UEFI::setDevicePathEndNode(path2), NgosStatus::OK);

        TEST_ASSERT_EQUALS(UEFI::isDevicePathEndType(path),  false);
        TEST_ASSERT_EQUALS(UEFI::isDevicePathEndType(path2), true);
    }
    TEST_CASE_END();



    TEST_CASE("getDevicePathSize()");
    {
        u8 buffer[25];
        memzero(buffer, sizeof(buffer));



        UefiDevicePath *path = (UefiDevicePath *)buffer;

        path->type    = UefiDevicePathType::MEDIA_DEVICE_PATH;
        path->subType = UefiDevicePathSubType::MEDIA_HARDDRIVE_DP;
        path->length  = 4;

        UefiDevicePath *path2 = UEFI::nextDevicePathNode(path);

        path2->type    = UefiDevicePathType::MEDIA_DEVICE_PATH;
        path2->subType = UefiDevicePathSubType::MEDIA_FILEPATH_DP;
        path2->length  = 6;

        UefiDevicePath *path3 = UEFI::nextDevicePathNode(path2);

        path3->type    = UefiDevicePathType::MEDIA_DEVICE_PATH;
        path3->subType = UefiDevicePathSubType::MEDIA_FILEPATH_DP;
        path3->length  = 8;

        UefiDevicePath *path4 = UEFI::nextDevicePathNode(path3);
        TEST_ASSERT_EQUALS(UEFI::setDevicePathEndNode(path4), NgosStatus::OK);

        TEST_ASSERT_EQUALS(UEFI::getDevicePathSize(path),  18);
        TEST_ASSERT_EQUALS(UEFI::getDevicePathSize(path2), 14);
        TEST_ASSERT_EQUALS(UEFI::getDevicePathSize(path3), 8);
        TEST_ASSERT_EQUALS(UEFI::getDevicePathSize(path4), 0);
    }
    TEST_CASE_END();



    TEST_CASE("memoryMapHasHeadroom()");
    {
        TEST_ASSERT_EQUALS(UEFI::memoryMapHasHeadroom(3000, 1000, 48), true);
        TEST_ASSERT_EQUALS(UEFI::memoryMapHasHeadroom(1000, 3000, 48), false);
        TEST_ASSERT_EQUALS(UEFI::memoryMapHasHeadroom(3000, 2616, 48), true);
        TEST_ASSERT_EQUALS(UEFI::memoryMapHasHeadroom(3000, 2617, 48), false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_UEFI_UEFI_H
