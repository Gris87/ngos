#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_LIST_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_LIST_H



#include <com/ngos/shared/common/containers/lib/listelement.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/malloc.h>



template<typename T>
class List
{
public:
    typedef bool (*element_comparator) (const T &first, const T &second);

    List();
    ~List(); // TEST: NO

    NgosStatus append(const T &value);
    NgosStatus prepend(const T &value);

    NgosStatus remove(const T &value);

    NgosStatus clear();

    NgosStatus moveToEnd(const T &value);
    NgosStatus sort();
    NgosStatus sort(element_comparator comparator);

    bool isEmpty() const;

    ListElement<T>* getHead() const;
    ListElement<T>* getTail() const;

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
    : mHead(nullptr)
    , mTail(nullptr)
{
    COMMON_LT((""));
}

template<typename T>
List<T>::~List()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(clear());
}

template<typename T>
NgosStatus List<T>::append(const T &value)
{
    // COMMON_LT((" | value = ...")); // Commented to avoid too frequent logs



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
    // COMMON_LT((" | value = ...")); // Commented to avoid too frequent logs



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

template<typename T>
NgosStatus List<T>::remove(const T &value)
{
    COMMON_LT((" | value = ..."));



    if (mHead)
    {
        if (mTail->getData() == value)
        {
            if (mHead == mTail)
            {
                delete mHead;

                mHead = nullptr;
                mTail = nullptr;
            }
            else
            {
                ListElement<T> *temp = mTail;

                mTail = mTail->getPrevious();
                COMMON_ASSERT_EXECUTION(mTail->setNext(nullptr), NgosStatus::ASSERTION);

                delete temp;
            }
        }
        else
        if (mHead->getData() == value)
        {
            ListElement<T> *temp = mHead;

            mHead = mHead->getNext();
            COMMON_ASSERT_EXECUTION(mHead->setPrevious(nullptr), NgosStatus::ASSERTION);

            delete temp;
        }
        else
        {
            ListElement<T> *element = mHead->getNext();

            while (element != mTail)
            {
                if (element->getData() == value)
                {
                    COMMON_ASSERT_EXECUTION(element->getPrevious()->setNext(element->getNext()),     NgosStatus::ASSERTION);
                    COMMON_ASSERT_EXECUTION(element->getNext()->setPrevious(element->getPrevious()), NgosStatus::ASSERTION);

                    delete element;

                    break;
                }

                element = element->getNext();
            }
        }
    }



    return NgosStatus::OK;
}

template<typename T>
NgosStatus List<T>::clear()
{
    COMMON_LT((""));



    ListElement<T> *element = mHead;

    while (element)
    {
        ListElement<T> *temp = element;

        element = element->getNext();

        delete temp;
    }

    mHead = nullptr;
    mTail = nullptr;



    return NgosStatus::OK;
}

template<typename T>
NgosStatus List<T>::moveToEnd(const T &value)
{
    COMMON_LT((" | value = ..."));



    if (mHead != mTail)
    {
        if (mHead->getData() == value)
        {
            ListElement<T> *newHead = mHead->getNext();

            COMMON_ASSERT_EXECUTION(newHead->setPrevious(nullptr), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(mTail->setNext(mHead),         NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(mHead->setPrevious(mTail),     NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(mHead->setNext(nullptr),       NgosStatus::ASSERTION);

            mTail = mHead;
            mHead = newHead;
        }
        else
        {
            ListElement<T> *element = mHead->getNext();

            while (element != mTail)
            {
                if (element->getData() == value)
                {
                    COMMON_TEST_ASSERT(element->getPrevious() != nullptr, NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(element->getNext()     != nullptr, NgosStatus::ASSERTION);

                    COMMON_ASSERT_EXECUTION(element->getPrevious()->setNext(element->getNext()),     NgosStatus::ASSERTION);
                    COMMON_ASSERT_EXECUTION(element->getNext()->setPrevious(element->getPrevious()), NgosStatus::ASSERTION);

                    COMMON_ASSERT_EXECUTION(mTail->setNext(element),     NgosStatus::ASSERTION);
                    COMMON_ASSERT_EXECUTION(element->setPrevious(mTail), NgosStatus::ASSERTION);
                    COMMON_ASSERT_EXECUTION(element->setNext(nullptr),   NgosStatus::ASSERTION);

                    mTail = element;

                    break;
                }

                element = element->getNext();
            }
        }
    }



    return NgosStatus::OK;
}

template<typename T>
NgosStatus List<T>::sort()
{
    COMMON_LT((""));



    ListElement<T> *cur = mHead;

    while (cur)
    {
        ListElement<T> *min  = cur;
        ListElement<T> *cur2 = cur->getNext();

        while (cur2)
        {
            if (cur2->getData() < min->getData())
            {
                min = cur2;
            }

            cur2 = cur2->getNext();
        }



        if (cur != min)
        {
            if (min->getPrevious())
            {
                min->getPrevious()->setNext(min->getNext());
            }

            if (min->getNext())
            {
                min->getNext()->setPrevious(min->getPrevious());
            }

            if (cur->getPrevious())
            {
                cur->getPrevious()->setNext(min);
            }
            else
            {
                mHead = min;
            }

            min->setPrevious(cur->getPrevious());
            min->setNext(cur);
            cur->setPrevious(min);
        }
        else
        {
            mTail = cur;
            cur   = cur->getNext();
        }
    }



    return NgosStatus::OK;
}

template<typename T>
NgosStatus List<T>::sort(element_comparator comparator)
{
    COMMON_LT((" | comparator = 0x%p", comparator));

    COMMON_ASSERT(comparator, "comparator is null", NgosStatus::ASSERTION);



    ListElement<T> *cur = mHead;

    while (cur)
    {
        ListElement<T> *min  = cur;
        ListElement<T> *cur2 = cur->getNext();

        while (cur2)
        {
            if (comparator(cur2->getData(), min->getData()))
            {
                min = cur2;
            }

            cur2 = cur2->getNext();
        }



        if (cur != min)
        {
            if (min->getPrevious())
            {
                min->getPrevious()->setNext(min->getNext());
            }

            if (min->getNext())
            {
                min->getNext()->setPrevious(min->getPrevious());
            }

            if (cur->getPrevious())
            {
                cur->getPrevious()->setNext(min);
            }
            else
            {
                mHead = min;
            }

            min->setPrevious(cur->getPrevious());
            min->setNext(cur);
            cur->setPrevious(min);
        }
        else
        {
            mTail = cur;
            cur   = cur->getNext();
        }
    }



    return NgosStatus::OK;
}

template<typename T>
bool List<T>::isEmpty() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mHead == nullptr;
}

template<typename T>
ListElement<T>* List<T>::getHead() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mHead;
}

template<typename T>
ListElement<T>* List<T>::getTail() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mTail;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_LIST_H
