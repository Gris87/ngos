#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_MAPELEMENT_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_MAPELEMENT_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>



template <typename Key, typename Value>
class MapElement
{
public:
    MapElement(const Key &key, const Value &value);
    ~MapElement(); // TEST: NO

    const Key& getKey() const;
    NgosStatus setKey(const Key &key);

    const Value& getValue() const;
    NgosStatus setValue(const Value &value);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    Key   mKey;
    Value mValue;
};



template <typename Key, typename Value>
MapElement<Key, Value>::MapElement(const Key &key, const Value &value)
    : mKey(key)
    , mValue(value)
{
    COMMON_LT((" | key = ..., value = ..."));
}

template <typename Key, typename Value>
MapElement<Key, Value>::~MapElement()
{
    COMMON_LT((""));
}

template <typename Key, typename Value>
const Key& MapElement<Key, Value>::getKey() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mKey;
}

template <typename Key, typename Value>
NgosStatus MapElement<Key, Value>::setKey(const Key &key)
{
    // COMMON_LT((" | key = ...")); // Commented to avoid too frequent logs



    mKey = key;



    return NgosStatus::OK;
}

template <typename Key, typename Value>
const Value& MapElement<Key, Value>::getValue() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mValue;
}

template <typename Key, typename Value>
NgosStatus MapElement<Key, Value>::setValue(const Value &value)
{
    // COMMON_LT((" | value = ...")); // Commented to avoid too frequent logs



    mValue = value;



    return NgosStatus::OK;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONTAINERS_LIB_MAPELEMENT_H
