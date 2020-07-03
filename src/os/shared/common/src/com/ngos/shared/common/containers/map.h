#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_MAP_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_MAP_H



#include <common/src/com/ngos/shared/common/containers/arraylist.h>
#include <common/src/com/ngos/shared/common/containers/lib/mapelement.h>
#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>



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

    u64 getSize() const;
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



    // Special cases to improve performance
    {
        // If there is no any pair then simply insert first one
        {
            if (mPairs.isEmpty())
            {
                return mPairs.append(MapElement(key, value));
            }
        }



        // Compare key with the last key
        {
            const MapElement<Key, Value> &lastElement = mPairs.last();
            const Key                    &lastKey     = lastElement.getKey();

            if (key > lastKey)
            {
                return mPairs.append(MapElement(key, value));
            }

            if (key == lastKey)
            {
                COMMON_ASSERT_EXECUTION(mPairs[mPairs.getSize() - 1].setValue(value), NgosStatus::ASSERTION);

                return NgosStatus::OK;
            }
        }



        // Compare key with the first key
        {
            const MapElement<Key, Value> &firstElement = mPairs.first();
            const Key                    &firstKey     = firstElement.getKey();

            if (key < firstKey)
            {
                return mPairs.prepend(MapElement(key, value));
            }

            if (key == firstKey)
            {
                COMMON_ASSERT_EXECUTION(mPairs[0].setValue(value), NgosStatus::ASSERTION);

                return NgosStatus::OK;
            }
        }
    }



    u64 left  = 0;
    u64 right = mPairs.getSize();

    // Binary search for the element or for position for insertion
    {
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
    }



    // COMMON_LVVV(("left  = %u", left));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("right = %u", right)); // Commented to avoid too frequent logs

    COMMON_TEST_ASSERT(left == right,           NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(left < mPairs.getSize(), NgosStatus::ASSERTION);



    // Check for the element at found position and update its value or insert new element
    {
        MapElement<Key, Value> &element = mPairs[left];

        if (element.getKey() == key)
        {
            COMMON_ASSERT_EXECUTION(element.setValue(value), NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_ASSERT_EXECUTION(mPairs.insert(left, MapElement(key, value)), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

template <typename Key, typename Value>
NgosStatus Map<Key, Value>::remove(const Key &key)
{
    COMMON_LT((" | key = ..."));



    // Special cases to improve performance
    {
        // If there is no any pair then there is no required entry
        {
            if (mPairs.isEmpty())
            {
                return NgosStatus::NOT_FOUND;
            }
        }



        // Compare key with the last key
        {
            const MapElement<Key, Value> &lastElement = mPairs.last();
            const Key                    &lastKey     = lastElement.getKey();

            if (key > lastKey)
            {
                return NgosStatus::NOT_FOUND;
            }

            if (key == lastKey)
            {
                COMMON_ASSERT_EXECUTION(mPairs.removeAt(mPairs.getSize() - 1), NgosStatus::ASSERTION);

                return NgosStatus::OK;
            }
        }



        // Compare key with the first key
        {
            const MapElement<Key, Value> &firstElement = mPairs.first();
            const Key                    &firstKey     = firstElement.getKey();

            if (key < firstKey)
            {
                return NgosStatus::NOT_FOUND;
            }

            if (key == firstKey)
            {
                COMMON_ASSERT_EXECUTION(mPairs.removeAt(0), NgosStatus::ASSERTION);

                return NgosStatus::OK;
            }
        }
    }



    u64 left  = 0;
    u64 right = mPairs.getSize();

    // Binary search for the element
    {
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
    }



    // COMMON_LVVV(("left  = %u", left));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("right = %u", right)); // Commented to avoid too frequent logs

    COMMON_TEST_ASSERT(left == right,           NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(left < mPairs.getSize(), NgosStatus::ASSERTION);



    // If found element is the required element then remove it
    {
        if (mPairs.at(left).getKey() == key)
        {
            COMMON_ASSERT_EXECUTION(mPairs.removeAt(left), NgosStatus::ASSERTION);

            return NgosStatus::OK;
        }
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



    // Special cases to improve performance
    {
        // If there is no any pair then there is no required entry
        {
            if (mPairs.isEmpty())
            {
                return false;
            }
        }



        // Compare key with the last key
        {
            const MapElement<Key, Value> &lastElement = mPairs.last();
            const Key                    &lastKey     = lastElement.getKey();

            if (key > lastKey)
            {
                return false;
            }

            if (key == lastKey)
            {
                return true;
            }
        }



        // Compare key with the first key
        {
            const MapElement<Key, Value> &firstElement = mPairs.first();
            const Key                    &firstKey     = firstElement.getKey();

            if (key < firstKey)
            {
                return false;
            }

            if (key == firstKey)
            {
                return true;
            }
        }
    }



    u64 left  = 0;
    u64 right = mPairs.getSize();

    // Binary search for the element
    {
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



    // Special cases to improve performance
    {
        // If there is no any pair then there is no required entry
        {
            if (mPairs.isEmpty())
            {
                return defaultValue;
            }
        }



        // Compare key with the last key
        {
            const MapElement<Key, Value> &lastElement = mPairs.last();
            const Key                    &lastKey     = lastElement.getKey();

            if (key > lastKey)
            {
                return defaultValue;
            }

            if (key == lastKey)
            {
                return lastElement.getValue();
            }
        }



        // Compare key with the first key
        {
            const MapElement<Key, Value> &firstElement = mPairs.first();
            const Key                    &firstKey     = firstElement.getKey();

            if (key < firstKey)
            {
                return defaultValue;
            }

            if (key == firstKey)
            {
                return firstElement.getValue();
            }
        }
    }



    u64 left  = 0;
    u64 right = mPairs.getSize();

    // Binary search for the element
    {
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
    }



    // COMMON_LVVV(("left  = %u", left));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("right = %u", right)); // Commented to avoid too frequent logs

    COMMON_TEST_ASSERT(left == right,           defaultValue);
    COMMON_TEST_ASSERT(left < mPairs.getSize(), defaultValue);



    // If found element is the required element then return its value
    {
        const MapElement<Key, Value> &element = mPairs.at(left);

        if (element.getKey() == key)
        {
            return element.getValue();
        }
    }



    return defaultValue;
}

template <typename Key, typename Value>
u64 Map<Key, Value>::getSize() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPairs.getSize();
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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_MAP_H
