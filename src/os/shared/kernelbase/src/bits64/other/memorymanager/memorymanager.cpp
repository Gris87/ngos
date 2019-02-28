#include "memorymanager.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/utils.h>



MemoryBlock       MemoryManager::sMemoryBlock;
MemoryBlockRegion MemoryManager::sMemoryRegions[INIT_MEMORYBLOCK_REGIONS];
MemoryBlockRegion MemoryManager::sReservedRegions[INIT_MEMORYBLOCK_REGIONS];



NgosStatus MemoryManager::init()
{
    COMMON_LT((""));



    sMemoryBlock.memory.count     = 0;
    sMemoryBlock.memory.max       = INIT_MEMORYBLOCK_REGIONS;
    sMemoryBlock.memory.totalSize = 0;
    sMemoryBlock.memory.regions   = sMemoryRegions;

    sMemoryBlock.reserved.count     = 0;
    sMemoryBlock.reserved.max       = INIT_MEMORYBLOCK_REGIONS;
    sMemoryBlock.reserved.totalSize = 0;
    sMemoryBlock.reserved.regions   = sReservedRegions;



    // Validation
    {
        COMMON_LVVV(("sizeof(sMemoryBlock)     = %u", sizeof(sMemoryBlock)));
        COMMON_LVVV(("sizeof(sMemoryRegions)   = %u", sizeof(sMemoryRegions)));
        COMMON_LVVV(("sizeof(sReservedRegions) = %u", sizeof(sReservedRegions)));



        COMMON_TEST_ASSERT(sizeof(sMemoryBlock)     == 64,   NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sizeof(sMemoryRegions)   == 3072, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sizeof(sReservedRegions) == 3072, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus MemoryManager::add(u64 start, u64 size)
{
    COMMON_LT((" | start = 0x%016lX, size = 0x%016lX", start, size));

    COMMON_ASSERT(size > 0, "size is zero", NgosStatus::ASSERTION);



    return addRange(&sMemoryBlock.memory, start, size, (memory_block_region_flags)MemoryBlockRegionFlag::NONE, MAX_NUMNODES);
}

NgosStatus MemoryManager::reserve(u64 start, u64 size)
{
    COMMON_LT((" | start = 0x%016lX, size = 0x%016lX", start, size));

    COMMON_ASSERT(size > 0, "size is zero", NgosStatus::ASSERTION);



    return addRange(&sMemoryBlock.reserved, start, size, (memory_block_region_flags)MemoryBlockRegionFlag::NONE, MAX_NUMNODES);
}

NgosStatus MemoryManager::insertRegion(MemoryBlockType *type, u64 index, u64 start, u64 size, memory_block_region_flags flags, memory_block_region_node_id nodeId)
{
    COMMON_LT((" | type = 0x%p, index = %u, start = 0x%016lX, size = 0x%016lX, flags = 0x%02X, nodeId = 0x%04X", type, index, start, size, flags, nodeId));

    COMMON_ASSERT(type,                    "type is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(type->count < type->max, "type is full",      NgosStatus::ASSERTION);
    COMMON_ASSERT(index <= type->count,    "index is invalid",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,                "size is zero",      NgosStatus::ASSERTION);
    COMMON_ASSERT(start + size > start,    "size is invalid",   NgosStatus::ASSERTION);
    COMMON_ASSERT(nodeId <= MAX_NUMNODES,  "nodeId is invalid", NgosStatus::ASSERTION);



    memmove(&type->regions[index + 1], &type->regions[index], (type->count - index) * sizeof(MemoryBlockRegion));



    MemoryBlockRegion &region = type->regions[index];

    region.start  = start;
    region.size   = size;
    region.flags  = flags;
    region.nodeId = nodeId;

    ++type->count;
    type->totalSize += size;



    return NgosStatus::OK;
}

NgosStatus MemoryManager::removeRegion(MemoryBlockType *type, u64 index)
{
    COMMON_LT((" | type = 0x%p, index = %u", type, index));

    COMMON_ASSERT(type,                "type is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(type->count > 0,     "type is empty",    NgosStatus::ASSERTION);
    COMMON_ASSERT(index < type->count, "index is invalid", NgosStatus::ASSERTION);



    type->totalSize -= type->regions[index].size;

    memmove(&type->regions[index], &type->regions[index + 1], (type->count - (index + 1)) * sizeof(MemoryBlockRegion));

    --type->count;



    COMMON_ASSERT((type->count > 0 && type->totalSize > 0) || (type->count == 0 && type->totalSize == 0), "type is broken", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryManager::removeRegions(MemoryBlockType *type, u64 index, u64 count)
{
    COMMON_LT((" | type = 0x%p, index = %u, count = %u", type, index, count));

    COMMON_ASSERT(type,                                      "type is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(type->count > 0,                           "type is empty",    NgosStatus::ASSERTION);
    COMMON_ASSERT(index < type->count,                       "index is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0 && count <= type->count - index, "count is invalid", NgosStatus::ASSERTION);



    for (i64 i = 0; i < (i64)count; ++i)
    {
        type->totalSize -= type->regions[index + i].size;
    }

    memmove(&type->regions[index], &type->regions[index + count], (type->count - (index + count)) * sizeof(MemoryBlockRegion));

    type->count -= count;



    COMMON_ASSERT((type->count > 0 && type->totalSize > 0) || (type->count == 0 && type->totalSize == 0), "type is broken", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus MemoryManager::mergeRegions(MemoryBlockType *type)
{
    COMMON_LT((" | type = 0x%p", type));

    COMMON_ASSERT(type, "type is null", NgosStatus::ASSERTION);



    i64 i = 1;

    while (i < (i64)type->count)
    {
        MemoryBlockRegion &previousRegion = type->regions[i - 1];
        MemoryBlockRegion &currentRegion  = type->regions[i];



        if (
            previousRegion.end() == currentRegion.start
            &&
            previousRegion.flags == currentRegion.flags
            &&
            previousRegion.nodeId == currentRegion.nodeId
           )
        {
            previousRegion.size += currentRegion.size;

            memmove(&type->regions[i], &type->regions[i + 1], (type->count - (i + 1)) * sizeof(MemoryBlockRegion));

            --type->count;
        }
        else
        {
            COMMON_TEST_ASSERT(previousRegion.end() <= currentRegion.start, NgosStatus::ASSERTION);

            ++i;
        }
    }



    return NgosStatus::OK;
}

NgosStatus MemoryManager::addRange(MemoryBlockType *type, u64 start, u64 size, memory_block_region_flags flags, memory_block_region_node_id nodeId)
{
    COMMON_LT((" | type = 0x%p, start = 0x%016lX, size = 0x%016lX, flags = 0x%02X, nodeId = 0x%04X", type, start, size, flags, nodeId));

    COMMON_ASSERT(type,                   "type is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,               "size is zero",      NgosStatus::ASSERTION);
    COMMON_ASSERT(start + size > start,   "size is invalid",   NgosStatus::ASSERTION);
    COMMON_ASSERT(nodeId <= MAX_NUMNODES, "nodeId is invalid", NgosStatus::ASSERTION);



    if (!type->count) // type->count == 0
    {
        COMMON_TEST_ASSERT(type->totalSize == 0, NgosStatus::ASSERTION);



        MemoryBlockRegion &region = type->regions[0];

        region.start  = start;
        region.size   = size;
        region.flags  = flags;
        region.nodeId = nodeId;

        type->count     = 1;
        type->totalSize = size;



        return NgosStatus::OK;
    }



    u64 end = start + size;

    u64 left  = 0;
    u64 right = type->count;



    // Special case when we do insertion at the beginning or at the end
    {
        if (
            end < type->regions[left].start
            ||
            (
             end == type->regions[left].start
             &&
             (
              flags != type->regions[left].flags
              ||
              nodeId != type->regions[left].nodeId
             )
            )
           )
        {
            COMMON_ASSERT_EXECUTION(insertRegion(type, left, start, size, flags, nodeId), NgosStatus::ASSERTION);

            return NgosStatus::OK;
        }

        if (
            start > type->regions[right - 1].end()
            ||
            (
             start == type->regions[right - 1].end()
             &&
             (
              flags != type->regions[right - 1].flags
              ||
              nodeId != type->regions[right - 1].nodeId
             )
            )
           )
        {
            COMMON_ASSERT_EXECUTION(insertRegion(type, right, start, size, flags, nodeId), NgosStatus::ASSERTION);

            return NgosStatus::OK;
        }
    }



    while (left < right)
    {
        u64 middle = (left + right) >> 1; // ">> 1" == "/ 2"

        MemoryBlockRegion &region = type->regions[middle];



        if (start <= region.end())
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

    COMMON_TEST_ASSERT(left == right,      NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(left < type->count, NgosStatus::ASSERTION);

    MemoryBlockRegion &region    = type->regions[left];
    u64                regionEnd = region.end();



    // Special case when we do insertion between two memory blocks
    {
        if (
            left > 0
            &&
            (
             start > type->regions[left - 1].end()
             ||
             (
              start == type->regions[left - 1].end()
              &&
              (
               flags != type->regions[left - 1].flags
               ||
               nodeId != type->regions[left - 1].nodeId
              )
             )
            )
            &&
            (
             end < region.start
             ||
             (
              end == region.start
              &&
              (
               flags != region.flags
               ||
               nodeId != region.nodeId
              )
             )
            )
           )
        {
            COMMON_ASSERT_EXECUTION(insertRegion(type, left, start, size, flags, nodeId), NgosStatus::ASSERTION);

            return NgosStatus::OK;
        }



        if (
            left < type->count - 1
            &&
            (
             end < type->regions[left + 1].start
             ||
             (
              end == type->regions[left + 1].start
              &&
              (
               flags != type->regions[left + 1].flags
               ||
               nodeId != type->regions[left + 1].nodeId
              )
             )
            )
            &&
            (
             start > regionEnd
             ||
             (
              start == regionEnd
              &&
              (
               flags != region.flags
               ||
               nodeId != region.nodeId
              )
             )
            )
           )
        {
            COMMON_ASSERT_EXECUTION(insertRegion(type, left + 1, start, size, flags, nodeId), NgosStatus::ASSERTION);

            return NgosStatus::OK;
        }
    }



    COMMON_TEST_ASSERT(end    >= region.start,  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(start  <= regionEnd,     NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(flags  == region.flags,  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(nodeId == region.nodeId, NgosStatus::ASSERTION);



    // Collect amount of regions that we can absorb with the new region
    while (
           right < type->count
           &&
           end >= type->regions[right].start
          )
    {
        COMMON_TEST_ASSERT(flags  == type->regions[right].flags,  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(nodeId == type->regions[right].nodeId, NgosStatus::ASSERTION);

        ++right;
    }



    // Remove absorbed regions
    if (right > left + 1)
    {
        regionEnd = type->regions[right - 1].end();

        COMMON_ASSERT_EXECUTION(removeRegions(type, left + 1, right - left - 1), NgosStatus::ASSERTION);
    }



    // Update region location and size
    //
    start = MIN(start, region.start);
    end   = MAX(end,   regionEnd);

    u64 newSize     =  end - start;
    type->totalSize += newSize - region.size;

    region.start = start;
    region.size  = newSize;



    return NgosStatus::OK;
}
