#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_DMI_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_DMI_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/dmi/dmi.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



u8 testAmount;

NgosStatus testCountEntry(DmiEntryHeader *header)
{
    UEFI_LT((" | header = 0x%p", header));

    UEFI_ASSERT(header, "header is null", NgosStatus::ASSERTION);



    if (header->type == DmiEntryType::SYSTEM)
    {
        ++testAmount;
    }



    return NgosStatus::OK;
}



TEST_CASES(section0, __shared_common_bits64_dmi_dmi);
{
    TEST_CASE("DMI_VERSION()");
    {
        TEST_ASSERT_EQUALS(DMI_VERSION(2,    7),   0x00020700);
        TEST_ASSERT_EQUALS(DMI_VERSION(3,    1),   0x00030100);
        TEST_ASSERT_EQUALS(DMI_VERSION(9,    67),  0x00094300);
        TEST_ASSERT_EQUALS(DMI_VERSION(3202, 927), 0x0C829F00);
    }
    TEST_CASE_END();



    TEST_CASE("DMI_VERSION_3()");
    {
        TEST_ASSERT_EQUALS(DMI_VERSION_3(2,    7,   0),   0x00020700);
        TEST_ASSERT_EQUALS(DMI_VERSION_3(3,    1,   2),   0x00030102);
        TEST_ASSERT_EQUALS(DMI_VERSION_3(9,    67,  56),  0x00094338);
        TEST_ASSERT_EQUALS(DMI_VERSION_3(3202, 927, 619), 0x0C829F6B);
    }
    TEST_CASE_END();



    TEST_CASE("iterateDmiEntries()");
    {
        u8 buf[] =
        {
            1, 10, 0x00, 0x11,
            0x11, 0x22, 0x33, 0x44, 0x55, 0x66,
            'T', 'e', 's', 't', 0,
            'B', 'l', 'a', 'h', 0,
            0,

            1, 12, 0x00, 0x12,
            0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
            'H', 'i', 0,
            'g', 'u', 'y', 's', 0,
            0,

            2, 13, 0x00, 0x13,
            0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99,
            'M', 'e', 'g', 'a', 0,
            'B', 'o', 'm', 'b', 0,
            0,

            1, 5, 0x00, 0x14,
            0x11,
            'W', 'h', 'e', 'r', 'e', 0,
            'i', 's', 0,
            'm', 'y', 0,
            'p', 'i', 'z', 'z', 'a', 0,
            0,

            127, 4, 0x00, 0x15,
            0,
            0
        };



        testAmount = 0;

        TEST_ASSERT_EQUALS(DMI::iterateDmiEntries(buf, testCountEntry), NgosStatus::OK);
        TEST_ASSERT_EQUALS(testAmount,                                  3);
    }
    TEST_CASE_END();



    TEST_CASE("checksum()");
    {
        u8 temp1[10] = { 5, 98, 31, 24, 18, 23, 67, 71, 82, 93 };
        u8 temp2[10] = { 7, 82, 94, 37, 16, 79, 98, 46, 37, 16 };
        u8 temp3[10] = { 9, 69, 58, 94, 31, 67, 34, 21, 34, 95 };

        TEST_ASSERT_EQUALS(DMI::checksum(temp1, sizeof(temp1), temp1[4]), temp1[4]);
        TEST_ASSERT_EQUALS(DMI::checksum(temp2, sizeof(temp2), temp2[6]), temp2[6]);
        TEST_ASSERT_EQUALS(DMI::checksum(temp3, sizeof(temp3), temp3[1]), temp3[1]);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_DMI_H
