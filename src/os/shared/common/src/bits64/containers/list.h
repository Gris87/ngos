#ifndef OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_LIST_H
#define OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_LIST_H



#include <common/src/bits64/containers/lib/listelement.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>



template<typename T>
class List
{
public:
    List();
    ~List(); // TEST: NO

    NgosStatus append(const T &value);
    NgosStatus prepend(const T &value);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    ListElement<T> *mHead;
    ListElement<T> *mTail;
};



template<typename T>
List<T>::List()
    : mHead(0)
    , mTail(0)
{
    COMMON_LT((""));
}

template<typename T>
List<T>::~List()
{
    COMMON_LT((""));
}

template<typename T>
NgosStatus List<T>::append(const T &value)
{
    COMMON_LT((" | value = ..."));



    ListElement<T> *element = new ListElement<T>(value);

    if (mHead)
    {
        COMMON_ASSERT_EXECUTION(mTail->setNext(element),     NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(element->setPrevious(mTail), NgosStatus::ASSERTION);
    }
    else
    {
        mHead = element;
    }

    mTail = element;



    return NgosStatus::OK;
}

template<typename T>
NgosStatus List<T>::prepend(const T &value)
{
    COMMON_LT((" | value = ..."));



    ListElement<T> *element = new ListElement<T>(value);

    if (mHead)
    {
        COMMON_ASSERT_EXECUTION(mHead->setPrevious(element), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(element->setNext(mHead),     NgosStatus::ASSERTION);
    }
    else
    {
        mTail = element;
    }

    mHead = element;



    return NgosStatus::OK;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_LIST_H
