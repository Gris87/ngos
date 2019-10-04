#ifndef OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_LIB_LISTELEMENT_H
#define OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_LIB_LISTELEMENT_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/status.h>



template <typename T>
class ListElement
{
public:
    ListElement(const T &data);
    ~ListElement(); // TEST: NO

    const T& getData() const;
    NgosStatus setData(const T &data);

    ListElement<T>* getNext() const;
    NgosStatus setNext(ListElement<T> *next);

    ListElement<T>* getPrevious() const;
    NgosStatus setPrevious(ListElement<T> *previous);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    T               mData;
    ListElement<T> *mNext;
    ListElement<T> *mPrevious;
};



template <typename T>
ListElement<T>::ListElement(const T &data)
    : mData(data)
    , mNext(0)
    , mPrevious(0)
{
    COMMON_LT((" | data = ..."));
}

template <typename T>
ListElement<T>::~ListElement()
{
    COMMON_LT((""));
}

template <typename T>
const T& ListElement<T>::getData() const
{
    COMMON_LT((""));



    return mData;
}

template <typename T>
NgosStatus ListElement<T>::setData(const T &data)
{
    COMMON_LT((" | data = ..."));



    mData = data;



    return NgosStatus::OK;
}

template <typename T>
ListElement<T>* ListElement<T>::getNext() const
{
    COMMON_LT((""));



    return mNext;
}

template <typename T>
NgosStatus ListElement<T>::setNext(ListElement<T> *next)
{
    COMMON_LT((" | next = 0x%p", next));



    mNext = next;



    return NgosStatus::OK;
}

template <typename T>
ListElement<T>* ListElement<T>::getPrevious() const
{
    COMMON_LT((""));



    return mPrevious;
}

template <typename T>
NgosStatus ListElement<T>::setPrevious(ListElement<T> *previous)
{
    COMMON_LT((" | previous = 0x%p", previous));



    mPrevious = previous;



    return NgosStatus::OK;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_LIB_LISTELEMENT_H
