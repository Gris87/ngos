#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicemappedaddressrange.h>



#define DMI_MEMORY_DEVICE_MAPPED_ADDRESS_STARTING_ADDRESS_NEED_TO_EXTEND        0xFFFFFFFF
#define DMI_MEMORY_DEVICE_MAPPED_ADDRESS_ENDING_ADDRESS_NEED_TO_EXTEND          0xFFFFFFFF
#define DMI_MEMORY_DEVICE_MAPPED_ADDRESS_PARTITION_ROW_POSITION_UNKNOWN         0xFF
#define DMI_MEMORY_DEVICE_MAPPED_ADDRESS_INTERLEAVE_POSITION_NON_INTERLEAVED    0x00
#define DMI_MEMORY_DEVICE_MAPPED_ADDRESS_INTERLEAVE_POSITION_UNKNOWN            0xFF
#define DMI_MEMORY_DEVICE_MAPPED_ADDRESS_INTERLEAVED_DATA_DEPTH_NON_INTERLEAVED 0x00
#define DMI_MEMORY_DEVICE_MAPPED_ADDRESS_INTERLEAVED_DATA_DEPTH_UNKNOWN         0xFF



struct DmiMemoryDeviceMappedAddressEntry
{
    DmiEntryHeader                    header;
    DmiMemoryDeviceMappedAddressRange startingAddress;
    DmiMemoryDeviceMappedAddressRange endingAddress;
    bad_uint16                               memoryDeviceHandle;
    bad_uint16                               memoryArrayMappedAddressHandle;
    bad_uint8                                partitionRowPosition;
    bad_uint8                                interleavePosition;
    bad_uint8                                interleavedDataDepth;
} __attribute__((packed));



struct DmiMemoryDeviceMappedAddressEntryV27: public DmiMemoryDeviceMappedAddressEntry
{
    bad_uint64 extendedStartingAddress;
    bad_uint64 extendedEndingAddress;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H
