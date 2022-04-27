#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_LISTELEMENT_H                                                                                                   // Colorize: green
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_LISTELEMENT_H                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <buildconfig.h>                                                                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/containers/lib/listelement.h>                                                                                                                                           // Colorize: green
#include <com/ngos/shared/uefibase/testengine.h>                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_TEST_MODE == OPTION_YES                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
TEST_CASES(section0, com_ngos_shared_common_containers_lib_listelement);                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    TEST_CASE("ListElement()");                                                                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        ListElement<good_U8> temp(5);                                                                                                                                                                    // Colorize: green
        ListElement<good_U8> temp2(10);                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.mData,     5);                                                                                                                                                           // Colorize: green
        TEST_ASSERT_EQUALS(temp.mNext,     nullptr);                                                                                                                                                     // Colorize: green
        TEST_ASSERT_EQUALS(temp.mPrevious, nullptr);                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp2.mData,     10);                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp2.mNext,     nullptr);                                                                                                                                                    // Colorize: green
        TEST_ASSERT_EQUALS(temp2.mPrevious, nullptr);                                                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    TEST_CASE_END();                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    TEST_CASE("getData()/setData()");                                                                                                                                                                    // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        ListElement<good_U8> temp(3);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.mData,     3);                                                                                                                                                           // Colorize: green
        TEST_ASSERT_EQUALS(temp.getData(), 3);                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.setData(100), NgosStatus::OK);                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.mData,     100);                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.getData(), 100);                                                                                                                                                         // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    TEST_CASE_END();                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    TEST_CASE("getNext()/setNext()");                                                                                                                                                                    // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        ListElement<good_U8> temp(7);                                                                                                                                                                    // Colorize: green
        ListElement<good_U8> temp2(6);                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.mNext,     nullptr);                                                                                                                                                     // Colorize: green
        TEST_ASSERT_EQUALS(temp.getNext(), nullptr);                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.setNext(&temp2), NgosStatus::OK);                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.mNext,     &temp2);                                                                                                                                                      // Colorize: green
        TEST_ASSERT_EQUALS(temp.getNext(), &temp2);                                                                                                                                                      // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    TEST_CASE_END();                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    TEST_CASE("getPrevious()/setPrevious()");                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        ListElement<good_U8> temp(7);                                                                                                                                                                    // Colorize: green
        ListElement<good_U8> temp2(6);                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.mPrevious,     nullptr);                                                                                                                                                 // Colorize: green
        TEST_ASSERT_EQUALS(temp.getPrevious(), nullptr);                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.setPrevious(&temp2), NgosStatus::OK);                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.mPrevious,     &temp2);                                                                                                                                                  // Colorize: green
        TEST_ASSERT_EQUALS(temp.getPrevious(), &temp2);                                                                                                                                                  // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    TEST_CASE_END();                                                                                                                                                                                     // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
TEST_CASES_END();                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_LISTELEMENT_H                                                                                                 // Colorize: green
