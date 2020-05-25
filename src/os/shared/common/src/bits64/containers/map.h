#ifndef OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_MAP_H
#define OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_MAP_H



#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/containers/lib/mapelement.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



template <typename Key, typename Value>
class Map
{
public:
    Map();
    ~Map(); // TEST: NO

    NgosStatus insert(const Key &key, const Value &value);
    NgosStatus remove(const Key &key);

    NgosStatus clear();

    bool contains(const Key &key) const;
    const Value& value(const Key &key, const Value &defaultValue) const;

    bool isEmpty() const;

    const ArrayList<MapElement<Key, Value>>& getPairs() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    ArrayList<MapElement<Key, Value>> mPairs;
};



template <typename Key, typename Value>
Map<Key, Value>::Map()
    : mPairs()
{
    COMMON_LT((""));
}

template <typename Key, typename Value>
Map<Key, Value>::~Map()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(clear());
}

template <typename Key, typename Value>
NgosStatus Map<Key, Value>::insert(const Key &key, const Value &value)
{
    // COMMON_LT((" | key = ..., value = ...")); // Commented to avoid too frequent logs



    if (
        mPairs.isEmpty()
        ||
        key > mPairs.last().getKey()
       )
    {
        return mPairs.append(MapElement(key, value));
    }

    if (key < mPairs.first().getKey())
    {
        return mPairs.prepend(MapElement(key, value));
    }



    u64 left  = 0;
    u64 right = mPairs.getSize();

    while (left < right)
    {
        u64 middle = (left + right) / 2;

        if (key <= mPairs.at(middle).getKey())
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }



    // COMMON_LVVV(("left  = %u", left));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("right = %u", right)); // Commented to avoid too frequent logs

    COMMON_TEST_ASSERT(left == right,           NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(left < mPairs.getSize(), NgosStatus::ASSERTION);



    MapElement<Key, Value> &element = mPairs[left];

    if (element.getKey() == key)
    {
        COMMON_ASSERT_EXECUTION(element.setValue(value), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_ASSERT_EXECUTION(mPairs.insert(left, MapElement(key, value)), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

template <typename Key, typename Value>
NgosStatus Map<Key, Value>::remove(const Key &key)
{
    COMMON_LT((" | key = ..."));



    if (
        mPairs.isEmpty()
        ||
        key < mPairs.first().getKey()
        ||
        key > mPairs.last().getKey()
       )
    {
        return NgosStatus::NOT_FOUND;
    }



    u64 left  = 0;
    u64 right = mPairs.getSize();

    while (left < right)
    {
        u64 middle = (left + right) / 2;

        if (key <= mPairs.at(middle).getKey())
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }



    // COMMON_LVVV(("left  = %u", left));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("right = %u", right)); // Commented to avoid too frequent logs

    COMMON_TEST_ASSERT(left == right,           NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(left < mPairs.getSize(), NgosStatus::ASSERTION);



    if (mPairs.at(left).getKey() == key)
    {
        COMMON_ASSERT_EXECUTION(mPairs.removeAt(left), NgosStatus::ASSERTION);

        return NgosStatus::OK;
    }



    return NgosStatus::NOT_FOUND;
}

template <typename Key, typename Value>
NgosStatus Map<Key, Value>::clear()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(mPairs.clear(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

template <typename Key, typename Value>
bool Map<Key, Value>::contains(const Key &key) const
{
    COMMON_LT((" | key = ..."));



    if (
        mPairs.isEmpty()
        ||
        key < mPairs.first().getKey()
        ||
        key > mPairs.last().getKey()
       )
    {
        return false;
    }



    u64 left  = 0;
    u64 right = mPairs.getSize();

    while (left < right)
    {
        u64 middle = (left + right) / 2;

        if (key <= mPairs.at(middle).getKey())
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }



    // COMMON_LVVV(("left  = %u", left));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("right = %u", right)); // Commented to avoid too frequent logs

    COMMON_TEST_ASSERT(left == right,           false);
    COMMON_TEST_ASSERT(left < mPairs.getSize(), false);



    return mPairs.at(left).getKey() == key;
}

template <typename Key, typename Value>
const Value& Map<Key, Value>::value(const Key &key, const Value &defaultValue) const
{
    // COMMON_LT((" | key = ..., defaultValue = ...")); // Commented to avoid too frequent logs



    if (
        mPairs.isEmpty()
        ||
        key < mPairs.first().getKey()
        ||
        key > mPairs.last().getKey()
       )
    {
        return defaultValue;
    }



    u64 left  = 0;
    u64 right = mPairs.getSize();

    while (left < right)
    {
        u64 middle = (left + right) / 2;

        if (key <= mPairs.at(middle).getKey())
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }



    // COMMON_LVVV(("left  = %u", left));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("right = %u", right)); // Commented to avoid too frequent logs

    COMMON_TEST_ASSERT(left == right,           defaultValue);
    COMMON_TEST_ASSERT(left < mPairs.getSize(), defaultValue);



    const MapElement<Key, Value> &element = mPairs.at(left);

    if (element.getKey() == key)
    {
        return element.getValue();
    }



    return defaultValue;
}

template <typename Key, typename Value>
bool Map<Key, Value>::isEmpty() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPairs.isEmpty();
}

template <typename Key, typename Value>
const ArrayList<MapElement<Key, Value>>& Map<Key, Value>::getPairs() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPairs;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CONTAINERS_MAP_H
