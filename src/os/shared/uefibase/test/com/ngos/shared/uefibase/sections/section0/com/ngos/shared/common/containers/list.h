#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIST_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIST_H



#include <buildconfig.h>
#include <com/ngos/shared/common/containers/list.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_containers_list);
{
    TEST_CASE("List()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mTail, nullptr);
    }
    TEST_CASE_END();



    TEST_CASE("append()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mTail, nullptr);



        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, nullptr);
        TEST_ASSERT_EQUALS(temp.mHead,     temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),     1);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),     nullptr);
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(), nullptr);



        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mHead, temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),     1);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),     temp.mTail);
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(), nullptr);
        TEST_ASSERT_EQUALS(temp.mTail->getData(),     7);
        TEST_ASSERT_EQUALS(temp.mTail->getNext(),     nullptr);
        TEST_ASSERT_EQUALS(temp.mTail->getPrevious(), temp.mHead);



        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mHead, temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),                1);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),                temp.mTail->getPrevious());
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(),            nullptr);
        TEST_ASSERT_EQUALS(temp.mTail->getData(),                9);
        TEST_ASSERT_EQUALS(temp.mTail->getNext(),                nullptr);
        TEST_ASSERT_EQUALS(temp.mTail->getPrevious(),            temp.mHead->getNext());
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getData(),     7);
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getNext(),     temp.mTail);
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getPrevious(), temp.mHead);
    }
    TEST_CASE_END();



    TEST_CASE("prepend()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mTail, nullptr);



        TEST_ASSERT_EQUALS(temp.prepend(1), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, nullptr);
        TEST_ASSERT_EQUALS(temp.mHead,     temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),     1);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),     nullptr);
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(), nullptr);



        TEST_ASSERT_EQUALS(temp.prepend(7), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mHead, temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),     7);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),     temp.mTail);
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(), nullptr);
        TEST_ASSERT_EQUALS(temp.mTail->getData(),     1);
        TEST_ASSERT_EQUALS(temp.mTail->getNext(),     nullptr);
        TEST_ASSERT_EQUALS(temp.mTail->getPrevious(), temp.mHead);



        TEST_ASSERT_EQUALS(temp.prepend(9), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mHead, temp.mTail);

        TEST_ASSERT_EQUALS(temp.mHead->getData(),                9);
        TEST_ASSERT_EQUALS(temp.mHead->getNext(),                temp.mTail->getPrevious());
        TEST_ASSERT_EQUALS(temp.mHead->getPrevious(),            nullptr);
        TEST_ASSERT_EQUALS(temp.mTail->getData(),                1);
        TEST_ASSERT_EQUALS(temp.mTail->getNext(),                nullptr);
        TEST_ASSERT_EQUALS(temp.mTail->getPrevious(),            temp.mHead->getNext());
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getData(),     7);
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getNext(),     temp.mTail);
        TEST_ASSERT_EQUALS(temp.mHead->getNext()->getPrevious(), temp.mHead);
    }
    TEST_CASE_END();



    TEST_CASE("remove()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mTail, nullptr);



        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);



        ListElement<bad_uint8> *el1 = temp.mHead;
        ListElement<bad_uint8> *el2 = el1->mNext;
        ListElement<bad_uint8> *el3 = el2->mNext;
        ListElement<bad_uint8> *el4 = el3->mNext;
        ListElement<bad_uint8> *el5 = el4->mNext;

        TEST_ASSERT_EQUALS(el1,            temp.mHead);
        TEST_ASSERT_EQUALS(el1->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el1->mNext,     el2);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el2->mPrevious, el1);
        TEST_ASSERT_EQUALS(el2->mNext,     el3);
        TEST_ASSERT_EQUALS(el2->mData,     9);

        TEST_ASSERT_EQUALS(el3->mPrevious, el2);
        TEST_ASSERT_EQUALS(el3->mNext,     el4);
        TEST_ASSERT_EQUALS(el3->mData,     3);

        TEST_ASSERT_EQUALS(el4->mPrevious, el3);
        TEST_ASSERT_EQUALS(el4->mNext,     el5);
        TEST_ASSERT_EQUALS(el4->mData,     1);

        TEST_ASSERT_EQUALS(el5,            temp.mTail);
        TEST_ASSERT_EQUALS(el5->mPrevious, el4);
        TEST_ASSERT_EQUALS(el5->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el5->mData,     7);



        TEST_ASSERT_EQUALS(temp.remove(7), NgosStatus::OK);



        TEST_ASSERT_EQUALS(el1,            temp.mHead);
        TEST_ASSERT_EQUALS(el1->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el1->mNext,     el2);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el2->mPrevious, el1);
        TEST_ASSERT_EQUALS(el2->mNext,     el3);
        TEST_ASSERT_EQUALS(el2->mData,     9);

        TEST_ASSERT_EQUALS(el3->mPrevious, el2);
        TEST_ASSERT_EQUALS(el3->mNext,     el4);
        TEST_ASSERT_EQUALS(el3->mData,     3);

        TEST_ASSERT_EQUALS(el4,            temp.mTail);
        TEST_ASSERT_EQUALS(el4->mPrevious, el3);
        TEST_ASSERT_EQUALS(el4->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el4->mData,     1);



        TEST_ASSERT_EQUALS(temp.remove(3), NgosStatus::OK);



        TEST_ASSERT_EQUALS(el1,            temp.mHead);
        TEST_ASSERT_EQUALS(el1->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el1->mNext,     el2);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el2->mPrevious, el1);
        TEST_ASSERT_EQUALS(el2->mNext,     el4);
        TEST_ASSERT_EQUALS(el2->mData,     9);

        TEST_ASSERT_EQUALS(el4,            temp.mTail);
        TEST_ASSERT_EQUALS(el4->mPrevious, el2);
        TEST_ASSERT_EQUALS(el4->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el4->mData,     1);



        TEST_ASSERT_EQUALS(temp.remove(9), NgosStatus::OK);



        TEST_ASSERT_EQUALS(el1,            temp.mHead);
        TEST_ASSERT_EQUALS(el1->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el1->mNext,     el4);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el4,            temp.mTail);
        TEST_ASSERT_EQUALS(el4->mPrevious, el1);
        TEST_ASSERT_EQUALS(el4->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el4->mData,     1);



        TEST_ASSERT_EQUALS(temp.remove(5), NgosStatus::OK);



        TEST_ASSERT_EQUALS(el4,            temp.mHead);
        TEST_ASSERT_EQUALS(el4,            temp.mTail);
        TEST_ASSERT_EQUALS(el4->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el4->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el4->mData,     1);



        TEST_ASSERT_EQUALS(temp.remove(1), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mTail, nullptr);
    }
    TEST_CASE_END();



    TEST_CASE("clear()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mTail, nullptr);



        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.mTail, nullptr);



        TEST_ASSERT_EQUALS(temp.clear(), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mHead, nullptr);
        TEST_ASSERT_EQUALS(temp.mTail, nullptr);
    }
    TEST_CASE_END();



    TEST_CASE("moveToEnd()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);



        ListElement<bad_uint8> *el1 = temp.mHead;
        ListElement<bad_uint8> *el2 = el1->mNext;
        ListElement<bad_uint8> *el3 = el2->mNext;
        ListElement<bad_uint8> *el4 = el3->mNext;
        ListElement<bad_uint8> *el5 = el4->mNext;

        TEST_ASSERT_EQUALS(el1,            temp.mHead);
        TEST_ASSERT_EQUALS(el1->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el1->mNext,     el2);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el2->mPrevious, el1);
        TEST_ASSERT_EQUALS(el2->mNext,     el3);
        TEST_ASSERT_EQUALS(el2->mData,     9);

        TEST_ASSERT_EQUALS(el3->mPrevious, el2);
        TEST_ASSERT_EQUALS(el3->mNext,     el4);
        TEST_ASSERT_EQUALS(el3->mData,     3);

        TEST_ASSERT_EQUALS(el4->mPrevious, el3);
        TEST_ASSERT_EQUALS(el4->mNext,     el5);
        TEST_ASSERT_EQUALS(el4->mData,     1);

        TEST_ASSERT_EQUALS(el5,            temp.mTail);
        TEST_ASSERT_EQUALS(el5->mPrevious, el4);
        TEST_ASSERT_EQUALS(el5->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el5->mData,     7);



        TEST_ASSERT_EQUALS(temp.moveToEnd(5), NgosStatus::OK);



        TEST_ASSERT_EQUALS(el1,            temp.mTail);
        TEST_ASSERT_EQUALS(el1->mPrevious, el5);
        TEST_ASSERT_EQUALS(el1->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el2,            temp.mHead);
        TEST_ASSERT_EQUALS(el2->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el2->mNext,     el3);
        TEST_ASSERT_EQUALS(el2->mData,     9);

        TEST_ASSERT_EQUALS(el3->mPrevious, el2);
        TEST_ASSERT_EQUALS(el3->mNext,     el4);
        TEST_ASSERT_EQUALS(el3->mData,     3);

        TEST_ASSERT_EQUALS(el4->mPrevious, el3);
        TEST_ASSERT_EQUALS(el4->mNext,     el5);
        TEST_ASSERT_EQUALS(el4->mData,     1);

        TEST_ASSERT_EQUALS(el5->mPrevious, el4);
        TEST_ASSERT_EQUALS(el5->mNext,     el1);
        TEST_ASSERT_EQUALS(el5->mData,     7);



        TEST_ASSERT_EQUALS(temp.moveToEnd(3), NgosStatus::OK);



        TEST_ASSERT_EQUALS(el1->mPrevious, el5);
        TEST_ASSERT_EQUALS(el1->mNext,     el3);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el2,            temp.mHead);
        TEST_ASSERT_EQUALS(el2->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el2->mNext,     el4);
        TEST_ASSERT_EQUALS(el2->mData,     9);

        TEST_ASSERT_EQUALS(el3,            temp.mTail);
        TEST_ASSERT_EQUALS(el3->mPrevious, el1);
        TEST_ASSERT_EQUALS(el3->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el3->mData,     3);

        TEST_ASSERT_EQUALS(el4->mPrevious, el2);
        TEST_ASSERT_EQUALS(el4->mNext,     el5);
        TEST_ASSERT_EQUALS(el4->mData,     1);

        TEST_ASSERT_EQUALS(el5->mPrevious, el4);
        TEST_ASSERT_EQUALS(el5->mNext,     el1);
        TEST_ASSERT_EQUALS(el5->mData,     7);



        TEST_ASSERT_EQUALS(temp.moveToEnd(3), NgosStatus::OK);



        TEST_ASSERT_EQUALS(el1->mPrevious, el5);
        TEST_ASSERT_EQUALS(el1->mNext,     el3);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el2,            temp.mHead);
        TEST_ASSERT_EQUALS(el2->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el2->mNext,     el4);
        TEST_ASSERT_EQUALS(el2->mData,     9);

        TEST_ASSERT_EQUALS(el3,            temp.mTail);
        TEST_ASSERT_EQUALS(el3->mPrevious, el1);
        TEST_ASSERT_EQUALS(el3->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el3->mData,     3);

        TEST_ASSERT_EQUALS(el4->mPrevious, el2);
        TEST_ASSERT_EQUALS(el4->mNext,     el5);
        TEST_ASSERT_EQUALS(el4->mData,     1);

        TEST_ASSERT_EQUALS(el5->mPrevious, el4);
        TEST_ASSERT_EQUALS(el5->mNext,     el1);
        TEST_ASSERT_EQUALS(el5->mData,     7);
    }
    TEST_CASE_END();



    TEST_CASE("sort()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);



        ListElement<bad_uint8> *el1 = temp.mHead;
        ListElement<bad_uint8> *el2 = el1->mNext;
        ListElement<bad_uint8> *el3 = el2->mNext;
        ListElement<bad_uint8> *el4 = el3->mNext;
        ListElement<bad_uint8> *el5 = el4->mNext;

        TEST_ASSERT_EQUALS(el1,            temp.mHead);
        TEST_ASSERT_EQUALS(el1->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(el1->mNext,     el2);
        TEST_ASSERT_EQUALS(el1->mData,     5);

        TEST_ASSERT_EQUALS(el2->mPrevious, el1);
        TEST_ASSERT_EQUALS(el2->mNext,     el3);
        TEST_ASSERT_EQUALS(el2->mData,     9);

        TEST_ASSERT_EQUALS(el3->mPrevious, el2);
        TEST_ASSERT_EQUALS(el3->mNext,     el4);
        TEST_ASSERT_EQUALS(el3->mData,     3);

        TEST_ASSERT_EQUALS(el4->mPrevious, el3);
        TEST_ASSERT_EQUALS(el4->mNext,     el5);
        TEST_ASSERT_EQUALS(el4->mData,     1);

        TEST_ASSERT_EQUALS(el5,            temp.mTail);
        TEST_ASSERT_EQUALS(el5->mPrevious, el4);
        TEST_ASSERT_EQUALS(el5->mNext,     nullptr);
        TEST_ASSERT_EQUALS(el5->mData,     7);



        TEST_ASSERT_EQUALS(temp.sort(), NgosStatus::OK);



        ListElement<bad_uint8> *newEl1 = temp.mHead;
        ListElement<bad_uint8> *newEl2 = newEl1->mNext;
        ListElement<bad_uint8> *newEl3 = newEl2->mNext;
        ListElement<bad_uint8> *newEl4 = newEl3->mNext;
        ListElement<bad_uint8> *newEl5 = newEl4->mNext;

        TEST_ASSERT_EQUALS(newEl1,            temp.mHead);
        TEST_ASSERT_EQUALS(newEl1->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(newEl1->mNext,     newEl2);
        TEST_ASSERT_EQUALS(newEl1->mData,     1);
        TEST_ASSERT_EQUALS(newEl1,            el4);

        TEST_ASSERT_EQUALS(newEl2->mPrevious, newEl1);
        TEST_ASSERT_EQUALS(newEl2->mNext,     newEl3);
        TEST_ASSERT_EQUALS(newEl2->mData,     3);
        TEST_ASSERT_EQUALS(newEl2,            el3);

        TEST_ASSERT_EQUALS(newEl3->mPrevious, newEl2);
        TEST_ASSERT_EQUALS(newEl3->mNext,     newEl4);
        TEST_ASSERT_EQUALS(newEl3->mData,     5);
        TEST_ASSERT_EQUALS(newEl3,            el1);

        TEST_ASSERT_EQUALS(newEl4->mPrevious, newEl3);
        TEST_ASSERT_EQUALS(newEl4->mNext,     newEl5);
        TEST_ASSERT_EQUALS(newEl4->mData,     7);
        TEST_ASSERT_EQUALS(newEl4,            el5);

        TEST_ASSERT_EQUALS(newEl5,            temp.mTail);
        TEST_ASSERT_EQUALS(newEl5->mPrevious, newEl4);
        TEST_ASSERT_EQUALS(newEl5->mNext,     nullptr);
        TEST_ASSERT_EQUALS(newEl5->mData,     9);
        TEST_ASSERT_EQUALS(newEl5,            el2);



        TEST_ASSERT_EQUALS(temp.sort([](const bad_uint8 &first, const bad_uint8 &second)
        {
            UEFI_LT((" | first = %u, second = %u", first, second));



            return first > second;
        }), NgosStatus::OK);



        newEl1 = temp.mHead;
        newEl2 = newEl1->mNext;
        newEl3 = newEl2->mNext;
        newEl4 = newEl3->mNext;
        newEl5 = newEl4->mNext;

        TEST_ASSERT_EQUALS(newEl1,            temp.mHead);
        TEST_ASSERT_EQUALS(newEl1->mPrevious, nullptr);
        TEST_ASSERT_EQUALS(newEl1->mNext,     newEl2);
        TEST_ASSERT_EQUALS(newEl1->mData,     9);
        TEST_ASSERT_EQUALS(newEl1,            el2);

        TEST_ASSERT_EQUALS(newEl2->mPrevious, newEl1);
        TEST_ASSERT_EQUALS(newEl2->mNext,     newEl3);
        TEST_ASSERT_EQUALS(newEl2->mData,     7);
        TEST_ASSERT_EQUALS(newEl2,            el5);

        TEST_ASSERT_EQUALS(newEl3->mPrevious, newEl2);
        TEST_ASSERT_EQUALS(newEl3->mNext,     newEl4);
        TEST_ASSERT_EQUALS(newEl3->mData,     5);
        TEST_ASSERT_EQUALS(newEl3,            el1);

        TEST_ASSERT_EQUALS(newEl4->mPrevious, newEl3);
        TEST_ASSERT_EQUALS(newEl4->mNext,     newEl5);
        TEST_ASSERT_EQUALS(newEl4->mData,     3);
        TEST_ASSERT_EQUALS(newEl4,            el3);

        TEST_ASSERT_EQUALS(newEl5,            temp.mTail);
        TEST_ASSERT_EQUALS(newEl5->mPrevious, newEl4);
        TEST_ASSERT_EQUALS(newEl5->mNext,     nullptr);
        TEST_ASSERT_EQUALS(newEl5->mData,     1);
        TEST_ASSERT_EQUALS(newEl5,            el4);
    }
    TEST_CASE_END();



    TEST_CASE("isEmpty()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.isEmpty(), true);

        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.isEmpty(), false);

        TEST_ASSERT_EQUALS(temp.clear(), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.isEmpty(), true);
    }
    TEST_CASE_END();



    TEST_CASE("getHead()/getTail()");
    {
        List<bad_uint8> temp;

        TEST_ASSERT_EQUALS(temp.getHead(), nullptr);
        TEST_ASSERT_EQUALS(temp.getTail(), nullptr);



        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);

        TEST_ASSERT_NOT_EQUALS(temp.getHead(), nullptr);
        TEST_ASSERT_NOT_EQUALS(temp.getTail(), nullptr);
        TEST_ASSERT_EQUALS(temp.getHead(),     temp.getTail());
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_CONTAINERS_LIST_H
