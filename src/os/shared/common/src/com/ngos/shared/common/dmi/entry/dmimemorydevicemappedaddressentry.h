#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicemappedaddressrange.h>



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
    u16                               memoryDeviceHandle;
    u16                               memoryArrayMappedAddressHandle;
    u8                                partitionRowPosition;
    u8                                interleavePosition;
    u8                                interleavedDataDepth;
} __attribute__((packed));



struct DmiMemoryDeviceMappedAddressEntryV27: public DmiMemoryDeviceMappedAddressEntry
{
    u64 extendedStartingAddress;
    u64 extendedEndingAddress;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEMAPPEDADDRESSENTRY_H
