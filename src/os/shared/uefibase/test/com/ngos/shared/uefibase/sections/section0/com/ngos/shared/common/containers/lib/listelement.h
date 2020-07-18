#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_LISTELEMENT_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_LISTELEMENT_H



#include <buildconfig.h>
#include <com/ngos/shared/common/containers/lib/listelement.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_containers_lib_listelement);
{
    TEST_CASE("ListElement()");
    {
        ListElement<u8> temp(5);
        ListElement<u8> temp2(10);

        TEST_ASSERT_EQUALS(temp.mData,     5);
        TEST_ASSERT_EQUALS(temp.mNext,     0);
        TEST_ASSERT_EQUALS(temp.mPrevious, 0);

        TEST_ASSERT_EQUALS(temp2.mData,     10);
        TEST_ASSERT_EQUALS(temp2.mNext,     0);
        TEST_ASSERT_EQUALS(temp2.mPrevious, 0);
    }
    TEST_CASE_END();



    TEST_CASE("getData()/setData()");
    {
        ListElement<u8> temp(3);

        TEST_ASSERT_EQUALS(temp.mData,     3);
        TEST_ASSERT_EQUALS(temp.getData(), 3);

        TEST_ASSERT_EQUALS(temp.setData(100), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mData,     100);
        TEST_ASSERT_EQUALS(temp.getData(), 100);
    }
    TEST_CASE_END();



    TEST_CASE("getNext()/setNext()");
    {
        ListElement<u8> temp(7);
        ListElement<u8> temp2(6);

        TEST_ASSERT_EQUALS(temp.mNext,     0);
        TEST_ASSERT_EQUALS(temp.getNext(), 0);

        TEST_ASSERT_EQUALS(temp.setNext(&temp2), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mNext,     &temp2);
        TEST_ASSERT_EQUALS(temp.getNext(), &temp2);
    }
    TEST_CASE_END();



    TEST_CASE("getPrevious()/setPrevious()");
    {
        ListElement<u8> temp(7);
        ListElement<u8> temp2(6);

        TEST_ASSERT_EQUALS(temp.mPrevious,     0);
        TEST_ASSERT_EQUALS(temp.getPrevious(), 0);

        TEST_ASSERT_EQUALS(temp.setPrevious(&temp2), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mPrevious,     &temp2);
        TEST_ASSERT_EQUALS(temp.getPrevious(), &temp2);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_LISTELEMENT_H