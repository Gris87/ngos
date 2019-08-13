#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIST_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIST_H



#include <buildconfig.h>
#include <common/src/bits64/containers/list.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_containers_list);
{
    TEST_CASE("List()");
    {
        List<u8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_EQUALS(temp.mTail, 0);
    }
    TEST_CASE_END();



    TEST_CASE("append()");
    {
        List<u8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_EQUALS(temp.mTail, 0);



        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, 0);
        TEST_ASSERT_EQUALS(temp.mHead,     temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),     1);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),     0);
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(), 0);



        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mHead, temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),     1);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),     temp.mTail);
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(), 0);
        TEST_ASSERT_EQUALS(temp.mTail->getData(),     7);
        TEST_ASSERT_EQUALS(temp.mTail->getNext(),     0);
        TEST_ASSERT_EQUALS(temp.mTail->getPrevious(), temp.mHead);



        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mHead, temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),                1);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),                temp.mTail->getPrevious());
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(),            0);
        TEST_ASSERT_EQUALS(temp.mTail->getData(),                9);
        TEST_ASSERT_EQUALS(temp.mTail->getNext(),                0);
        TEST_ASSERT_EQUALS(temp.mTail->getPrevious(),            temp.mHead->getNext());
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getData(),     7);
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getNext(),     temp.mTail);
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getPrevious(), temp.mHead);
    }
    TEST_CASE_END();



    TEST_CASE("prepend()");
    {
        List<u8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_EQUALS(temp.mTail, 0);



        TEST_ASSERT_EQUALS(temp.prepend(1), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, 0);
        TEST_ASSERT_EQUALS(temp.mHead,     temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),     1);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),     0);
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(), 0);



        TEST_ASSERT_EQUALS(temp.prepend(7), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mHead, temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),     7);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),     temp.mTail);
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(), 0);
        TEST_ASSERT_EQUALS(temp.mTail->getData(),     1);
        TEST_ASSERT_EQUALS(temp.mTail->getNext(),     0);
        TEST_ASSERT_EQUALS(temp.mTail->getPrevious(), temp.mHead);



        TEST_ASSERT_EQUALS(temp.prepend(9), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, 0);
        TEST_ASSERT_NOT_EQUALS(temp.mHead, temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),                9);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),                temp.mTail->getPrevious());
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(),            0);
        TEST_ASSERT_EQUALS(temp.mTail->getData(),                1);
        TEST_ASSERT_EQUALS(temp.mTail->getNext(),                0);
        TEST_ASSERT_EQUALS(temp.mTail->getPrevious(),            temp.mHead->getNext());
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getData(),     7);
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getNext(),     temp.mTail);
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getPrevious(), temp.mHead);
    }
    TEST_CASE_END();



    TEST_CASE("getHead()/getTail()");
    {
        List<u8> temp;

        TEST_ASSERT_EQUALS(temp.getHead(), 0);
        TEST_ASSERT_EQUALS(temp.getTail(), 0);



        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.getHead(), 0);
        TEST_ASSERT_NOT_EQUALS(temp.getTail(), 0);
        TEST_ASSERT_EQUALS(temp.getHead(),     temp.getTail());
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIST_H
