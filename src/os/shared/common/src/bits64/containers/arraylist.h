#ifndef OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_ARRAYLIST_H
#define OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_ARRAYLIST_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>



#define ARRAY_LIST_DEFAULT_CAPACITY 4



template<typename T>
class ArrayList
{
public:
    ArrayList();
    ~ArrayList(); // TEST: NO

    NgosStatus append(const T &value);
    NgosStatus prepend(const T &value);

    NgosStatus sort();

    const T& at(u64 index) const;

    u64 getSize() const;

    NgosStatus setCapacity(u64 capacity);
    u64 getCapacity() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    NgosStatus extendCapacity();
    NgosStatus quickSort(i64 left, i64 right);

    u64  mCapacity;
    u64  mSize;
    T   *mValues;
};



template<typename T>
ArrayList<T>::ArrayList()
    : mCapacity(0)
    , mSize(0)
    , mValues(nullptr)
{
    COMMON_LT((""));
}

template<typename T>
ArrayList<T>::~ArrayList()
{
    COMMON_LT((""));



    if (mValues)
    {
        COMMON_ASSERT_EXECUTION(free(mValues));
    }
}

template<typename T>
NgosStatus ArrayList<T>::append(const T &value)
{
    COMMON_LT((" | value = ..."));



    COMMON_ASSERT_EXECUTION(extendCapacity(), NgosStatus::ASSERTION);

    mValues[mSize] = value;

    ++mSize;



    return NgosStatus::OK;
}

template<typename T>
NgosStatus ArrayList<T>::prepend(const T &value)
{
    COMMON_LT((" | value = ..."));



    COMMON_ASSERT_EXECUTION(extendCapacity(), NgosStatus::ASSERTION);

    for (i64 i = mSize; i > 0; --i)
    {
        mValues[i] = mValues[i - 1];
    }

    mValues[0] = value;

    ++mSize;



    return NgosStatus::OK;
}

template<typename T>
NgosStatus ArrayList<T>::sort()
{
    COMMON_LT((""));



    if (mSize < 2)
    {
        return NgosStatus::OK;
    }



    return quickSort(0, mSize - 1);
}

template<typename T>
const T& ArrayList<T>::at(u64 index) const
{
    COMMON_LT((" | index = %u", index));

    COMMON_ASSERT(index < mSize, "index is invalid", mValues[index]);



    return mValues[index];
}

template<typename T>
u64 ArrayList<T>::getSize() const
{
    COMMON_LT((""));



    return mSize;
}

template<typename T>
NgosStatus ArrayList<T>::setCapacity(u64 capacity)
{
    COMMON_LT((" | capacity = %u", capacity));



    if (capacity > mCapacity)
    {
        if (mCapacity) // mCapacity > 0
        {
            mValues = (T *)realloc(mValues, mCapacity * sizeof(T), capacity * sizeof(T));
        }
        else
        {
            mValues = (T *)malloc(capacity * sizeof(T));
        }

        mCapacity = capacity;
    }
    else
    if (capacity < mCapacity)
    {
        mCapacity = capacity;

        if (mCapacity) // mCapacity > 0
        {
            if (mSize > mCapacity)
            {
                mSize = mCapacity;
            }
        }
        else
        {
            COMMON_TEST_ASSERT(mValues, NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(free(mValues), NgosStatus::ASSERTION);
            mValues = nullptr;

            mSize = 0;
        }
    }



    return NgosStatus::OK;
}

template<typename T>
u64 ArrayList<T>::getCapacity() const
{
    COMMON_LT((""));



    return mCapacity;
}

template<typename T>
NgosStatus ArrayList<T>::extendCapacity()
{
    COMMON_LT((""));



    if (mSize >= mCapacity)
    {
        if (mCapacity) // mCapacity > 0
        {
            u64 oldSize =   mCapacity * sizeof(T);
            mCapacity   <<= 1;
            u64 newSize =   mCapacity * sizeof(T);

            mValues = (T *)realloc(mValues, oldSize, newSize);
        }
        else
        {
            mCapacity = ARRAY_LIST_DEFAULT_CAPACITY;

            mValues = (T *)malloc(mCapacity * sizeof(T));
        }
    }



    return NgosStatus::OK;
}

template<typename T>
NgosStatus ArrayList<T>::quickSort(i64 left, i64 right)
{
    COMMON_LT((" | left = %d, right = %d", left, right));

    COMMON_ASSERT(left  < (i64)mSize, "left is invalid",  NgosStatus::ASSERTION);
    COMMON_ASSERT(right < (i64)mSize, "right is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(left  < right,      "left is invalid",  NgosStatus::ASSERTION);



    if (left + 1 == right)
    {
        if (mValues[right] < mValues[left])
        {
            T temp         = mValues[left];
            mValues[left]  = mValues[right];
            mValues[right] = temp;
        }
    }
    else
    {
        i64 i = left;
        i64 j = right;

        T pivot = mValues[(left + right) >> 1]; // ">> 1" == "/ 2"



        while (i <= j)
        {
            while (mValues[i] < pivot)
            {
                ++i;
            }

            while (pivot < mValues[j])
            {
                --j;
            }

            if (i <= j)
            {
                if (i != j)
                {
                    T temp     = mValues[i];
                    mValues[i] = mValues[j];
                    mValues[j] = temp;
                }

                ++i;
                --j;
            }
        }



        if (left < j)
        {
            COMMON_ASSERT_EXECUTION(quickSort(left, j), NgosStatus::ASSERTION);
        }

        if (i < right)
        {
            COMMON_ASSERT_EXECUTION(quickSort(i, right), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_ARRAYLIST_H