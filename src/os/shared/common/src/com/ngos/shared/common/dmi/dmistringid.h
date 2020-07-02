#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMISTRINGID_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMISTRINGID_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



struct DmiStringId
{
    DmiStringId()
        : id(0)
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs
    }

    inline DmiStringId& operator=(const DmiStringId &another)
    {
        id = another.id;

        return *this;
    }

    inline DmiStringId& operator++()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs

        ++id;

        return *this;
    }

    inline bool operator==(const DmiStringId &another) const
    {
        // COMMON_LT(("another = ...")); // Commented to avoid too frequent logs



        return id == another.id;
    }



    u8 id;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMISTRINGID_H
