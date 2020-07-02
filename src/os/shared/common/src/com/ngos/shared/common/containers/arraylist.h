#ifndef OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_ARRAYLIST_H
#define OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_ARRAYLIST_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/memory/malloc.h>



#define ARRAY_LIST_DEFAULT_CAPACITY 4



template<typename T>
class ArrayList
{
public:
    typedef bool (*element_comparator) (const T &first, const T &second);

    ArrayList();
    ~ArrayList(); // TEST: NO

    NgosStatus append(const T &value);
    NgosStatus prepend(const T &value);
    NgosStatus insert(u64 index, const T &value);
    NgosStatus removeAt(u64 index);

    NgosStatus clear();

    NgosStatus sort();
    NgosStatus sort(element_comparator comparator);

    i64 indexOf(const T &value) const;

    const T& first() const;
    const T& last() const;
    const T& at(u64 index) const;
    T& operator[](u64 index);

    u64 getSize() const;
    bool isEmpty() const;

    NgosStatus setCapacity(u64 capacity);
    u64 getCapacity() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    NgosStatus extendCapacity();
    NgosStatus quickSort(i64 left, i64 right);
    NgosStatus quickSort(i64 left, i64 right, element_comparator comparator);

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
    // COMMON_LT((" | value = ...")); // Commented to avoid too frequent logs



    COMMON_ASSERT_EXECUTION(extendCapacity(), NgosStatus::ASSERTION);

    mValues[mSize] = value;

    ++mSize;



    return NgosStatus::OK;
}

template<typename T>
NgosStatus ArrayList<T>::prepend(const T &value)
{
    // COMMON_LT((" | value = ...")); // Commented to avoid too frequent logs



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
NgosStatus ArrayList<T>::insert(u64 index, const T &value)
{
    // COMMON_LT((" | index = %u, value = ...", index)); // Commented to avoid too frequent logs



    if (index >= mSize)
    {
        return append(value);
    }

    if (index <= 0)
    {
        return prepend(value);
    }



    COMMON_ASSERT_EXECUTION(extendCapacity(), NgosStatus::ASSERTION);

    for (i64 i = mSize; i > (i64)index; --i)
    {
        mValues[i] = mValues[i - 1];
    }

    mValues[index] = value;

    ++mSize;



    return NgosStatus::OK;
}

template<typename T>
NgosStatus ArrayList<T>::removeAt(u64 index)
{
    // COMMON_LT((" | index = %u", index)); // Commented to avoid too frequent logs



    if (
        index >= 0
        &&
        index < mSize
       )
    {
        if (mSize == 1)
        {
            COMMON_ASSERT_EXECUTION(clear(), NgosStatus::ASSERTION);

            return NgosStatus::OK;
        }



        for (i64 i = index + 1; i < (i64)mSize; ++i)
        {
            mValues[i - 1] = mValues[i];
        }

        --mSize;



        return NgosStatus::OK;
    }



    return NgosStatus::NO_EFFECT;
}

template<typename T>
NgosStatus ArrayList<T>::clear()
{
    COMMON_LT((""));



    if (mValues)
    {
        COMMON_TEST_ASSERT(mCapacity > 0, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(mSize     > 0, NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(free(mValues), NgosStatus::ASSERTION);

        mCapacity = 0;
        mSize     = 0;
        mValues   = nullptr;
    }



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
NgosStatus ArrayList<T>::sort(element_comparator comparator)
{
    COMMON_LT((" | comparator = 0x%p", comparator));

    COMMON_ASSERT(comparator, "comparator is null", NgosStatus::ASSERTION);



    if (mSize < 2)
    {
        return NgosStatus::OK;
    }



    return quickSort(0, mSize - 1, comparator);
}

template<typename T>
i64 ArrayList<T>::indexOf(const T &value) const
{
    COMMON_LT((" | value = ..."));



    for (i64 i = 0; i < (i64)mSize; ++i)
    {
        if (mValues[i] == value)
        {
            return i;
        }
    }



    return -1;
}

template<typename T>
const T& ArrayList<T>::first() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs

    COMMON_ASSERT(!isEmpty(), "list is empty", mValues[0]);



    return mValues[0];
}

template<typename T>
const T& ArrayList<T>::last() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs

    COMMON_ASSERT(!isEmpty(), "list is empty", mValues[0]);



    return mValues[mSize - 1];
}

template<typename T>
const T& ArrayList<T>::at(u64 index) const
{
    // COMMON_LT((" | index = %u", index)); // Commented to avoid too frequent logs

    COMMON_ASSERT(index < mSize, "index is invalid", mValues[index]);



    return mValues[index];
}

template<typename T>
T& ArrayList<T>::operator[](u64 index)
{
    // COMMON_LT((" | index = %u", index)); // Commented to avoid too frequent logs

    COMMON_ASSERT(index < mSize, "index is invalid", mValues[index]);



    return mValues[index];
}

template<typename T>
u64 ArrayList<T>::getSize() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mSize;
}

template<typename T>
bool ArrayList<T>::isEmpty() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mSize == 0;
}

template<typename T>
NgosStatus ArrayList<T>::setCapacity(u64 capacity)
{
    COMMON_LT((" | capacity = %u", capacity));



    if (capacity > mCapacity)
    {
        if (mCapacity > 0)
        {
            mValues = (T *)realloc(mValues, mCapacity * sizeof(T), capacity * sizeof(T));
            COMMON_TEST_ASSERT(mValues != nullptr, NgosStatus::ASSERTION);
        }
        else
        {
            mValues = (T *)malloc(capacity * sizeof(T));
            COMMON_TEST_ASSERT(mValues != nullptr, NgosStatus::ASSERTION);
        }

        mCapacity = capacity;
    }
    else
    if (capacity < mCapacity)
    {
        mCapacity = capacity;

        if (mCapacity > 0)
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
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mCapacity;
}

template<typename T>
NgosStatus ArrayList<T>::extendCapacity()
{
    COMMON_LT((""));



    if (mSize >= mCapacity)
    {
        if (mCapacity > 0)
        {
            u64 oldSize =   mCapacity * sizeof(T);
            mCapacity   <<= 1;
            u64 newSize =   mCapacity * sizeof(T);

            mValues = (T *)realloc(mValues, oldSize, newSize);
            COMMON_TEST_ASSERT(mValues != nullptr, NgosStatus::ASSERTION);
        }
        else
        {
            mCapacity = ARRAY_LIST_DEFAULT_CAPACITY;

            mValues = (T *)malloc(mCapacity * sizeof(T));
            COMMON_TEST_ASSERT(mValues != nullptr, NgosStatus::ASSERTION);
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

        T pivot = mValues[(left + right) / 2];



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

template<typename T>
NgosStatus ArrayList<T>::quickSort(i64 left, i64 right, element_comparator comparator)
{
    COMMON_LT((" | left = %d, right = %d, comparator = 0x%p", left, right, comparator));

    // Ignore CppAlignmentVerifier [BEGIN]
    COMMON_ASSERT(left  < (i64)mSize, "left is invalid",    NgosStatus::ASSERTION);
    COMMON_ASSERT(right < (i64)mSize, "right is invalid",   NgosStatus::ASSERTION);
    COMMON_ASSERT(left  < right,      "left is invalid",    NgosStatus::ASSERTION);
    COMMON_ASSERT(comparator,         "comparator is null", NgosStatus::ASSERTION);
    // Ignore CppAlignmentVerifier [END]



    if (left + 1 == right)
    {
        if (comparator(mValues[right], mValues[left]))
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

        T pivot = mValues[(left + right) / 2];



        while (i <= j)
        {
            while (comparator(mValues[i], pivot))
            {
                ++i;
            }

            while (comparator(pivot, mValues[j]))
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
            COMMON_ASSERT_EXECUTION(quickSort(left, j, comparator), NgosStatus::ASSERTION);
        }

        if (i < right)
        {
            COMMON_ASSERT_EXECUTION(quickSort(i, right, comparator), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_ARRAYLIST_H
