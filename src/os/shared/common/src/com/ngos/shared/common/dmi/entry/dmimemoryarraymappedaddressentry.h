#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemoryarraymappedaddressrange.h>



#define DMI_MEMORY_ARRAY_MAPPED_ADDRESS_STARTING_ADDRESS_NEED_TO_EXTEND 0xFFFFFFFF
#define DMI_MEMORY_ARRAY_MAPPED_ADDRESS_ENDING_ADDRESS_NEED_TO_EXTEND   0xFFFFFFFF



struct DmiMemoryArrayMappedAddressEntry
{
    DmiEntryHeader                   header;
    DmiMemoryArrayMappedAddressRange startingAddress;
    DmiMemoryArrayMappedAddressRange endingAddress;
    bad_uint16                              memoryArrayHandle;
    bad_uint8                               partitionWidth;
} __attribute__((packed));



struct DmiMemoryArrayMappedAddressEntryV27: public DmiMemoryArrayMappedAddressEntry
{
    bad_uint64 extendedStartingAddress;
    bad_uint64 extendedEndingAddress;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYARRAYMAPPEDADDRESSENTRY_H
