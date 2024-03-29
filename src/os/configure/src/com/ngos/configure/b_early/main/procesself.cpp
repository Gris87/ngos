#include "procesself.h"

#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/elf/programheadertableentry.h>
#include <com/ngos/shared/common/elf/rela.h>
#include <com/ngos/shared/common/elf/relocationtype.h>
#include <com/ngos/shared/common/elf/sectionheadertableentry.h>
#include <com/ngos/shared/common/memory/memory.h>



u64 getElfMemorySize(ElfHeader *header)
{
    EARLY_LT((" | header = 0x%p", header));

    EARLY_ASSERT(header, "header is null", 0);



    // Validation
    {
        EARLY_LVVV(("header->identification.signature     = 0x%08X",    header->identification.signature));
        EARLY_LVVV(("header->identification.fileClass     = %s",        enumToFullString(header->identification.fileClass)));
        EARLY_LVVV(("header->identification.fileData      = %s",        enumToFullString(header->identification.fileData)));
        EARLY_LVVV(("header->identification.version       = %s",        enumToFullString(header->identification.version)));
        EARLY_LVVV(("header->identification.osAbi         = %s",        enumToFullString(header->identification.osAbi)));
        EARLY_LVVV(("header->identification.abiVersion    = %u",        header->identification.abiVersion));
        EARLY_LVVV(("header->type                         = %s",        enumToFullString(header->type)));
        EARLY_LVVV(("header->machine                      = %s",        enumToFullString(header->machine)));
        EARLY_LVVV(("header->version                      = %s",        enumToFullString(header->version)));
        EARLY_LVVV(("header->entryPoint                   = 0x%016llX", header->entryPoint));
        EARLY_LVVV(("header->programHeaderTableOffset     = %u",        header->programHeaderTableOffset));
        EARLY_LVVV(("header->sectionHeaderTableOffset     = %u",        header->sectionHeaderTableOffset));
        EARLY_LVVV(("header->flags                        = %s",        flagsToFullString(header->flags)));
        EARLY_LVVV(("header->headerSize                   = %u",        header->headerSize));
        EARLY_LVVV(("header->programHeaderTableEntrySize  = %u",        header->programHeaderTableEntrySize));
        EARLY_LVVV(("header->programHeaderTableEntryCount = %u",        header->programHeaderTableEntryCount));
        EARLY_LVVV(("header->sectionHeaderTableEntrySize  = %u",        header->sectionHeaderTableEntrySize));
        EARLY_LVVV(("header->sectionHeaderTableEntryCount = %u",        header->sectionHeaderTableEntryCount));
        EARLY_LVVV(("header->sectionHeaderTableNamesIndex = %u",        header->sectionHeaderTableNamesIndex));



        EARLY_TEST_ASSERT(header->identification.signature     == ELF_SIGNATURE,                            0);
        EARLY_TEST_ASSERT(header->identification.fileClass     == ElfClass::CLASS_64,                       0);
        EARLY_TEST_ASSERT(header->identification.fileData      == ElfData::LEAST_SIGNIFICANT_BYTE,          0);
        EARLY_TEST_ASSERT(header->identification.version       == ElfFileVersion::CURRENT,                  0);
        EARLY_TEST_ASSERT(header->identification.osAbi         == ElfOsAbi::SYSTEM_V,                       0);
        EARLY_TEST_ASSERT(header->identification.abiVersion    == 0,                                        0);
        EARLY_TEST_ASSERT(header->type                         == ElfType::EXECUTABLE,                      0);
        EARLY_TEST_ASSERT(header->machine                      == ElfMachine::MACHINE_X86_64,               0);
        EARLY_TEST_ASSERT(header->version                      == ElfVersion::CURRENT,                      0);
        EARLY_TEST_ASSERT(header->entryPoint                   == 0xFFFFFFFF80000000,                       0);
        EARLY_TEST_ASSERT(header->programHeaderTableOffset     == 64,                                       0);
        EARLY_TEST_ASSERT(header->sectionHeaderTableOffset     >= 2000000,                                  0);
        EARLY_TEST_ASSERT(header->flags                        == FLAGS(ElfHeaderFlag::NONE),               0);
        EARLY_TEST_ASSERT(header->headerSize                   == sizeof(ElfHeader),                        0);
        EARLY_TEST_ASSERT(header->programHeaderTableEntrySize  == sizeof(ElfProgramHeaderTableEntry),       0);
        EARLY_TEST_ASSERT(header->programHeaderTableEntryCount == 1,                                        0);
        EARLY_TEST_ASSERT(header->sectionHeaderTableEntrySize  == sizeof(ElfSectionHeaderTableEntry),       0);
        EARLY_TEST_ASSERT(header->sectionHeaderTableEntryCount >= 40,                                       0);
        EARLY_TEST_ASSERT(header->sectionHeaderTableEntryCount <= 41,                                       0);
        EARLY_TEST_ASSERT(header->sectionHeaderTableNamesIndex == header->sectionHeaderTableEntryCount - 1, 0);
    }



    u64 res = 0;

    for (good_I64 i = 0; i < header->programHeaderTableEntryCount; ++i)
    {
        ElfProgramHeaderTableEntry *programHeader = (ElfProgramHeaderTableEntry *)((u64)header + header->programHeaderTableOffset + i * header->programHeaderTableEntrySize);

        EARLY_LVVV(("programHeader[%d]->type            = %s",        i, enumToFullString(programHeader->type)));
        EARLY_LVVV(("programHeader[%d]->flags           = %s",        i, flagsToFullString(programHeader->flags)));
        EARLY_LVVV(("programHeader[%d]->offset          = 0x%016llX", i, programHeader->offset));
        EARLY_LVVV(("programHeader[%d]->virtualAddress  = 0x%016llX", i, programHeader->virtualAddress));
        EARLY_LVVV(("programHeader[%d]->physicalAddress = 0x%016llX", i, programHeader->physicalAddress));
        EARLY_LVVV(("programHeader[%d]->fileSize        = %u",        i, programHeader->fileSize));
        EARLY_LVVV(("programHeader[%d]->memorySize      = %u",        i, programHeader->memorySize));
        EARLY_LVVV(("programHeader[%d]->align           = %u",        i, programHeader->align));

        res += programHeader->memorySize;
    }

    return res;
}

NgosStatus loadElfToAddress(ElfHeader *header, u64 address)
{
    EARLY_LT((" | header = 0x%p, address = 0x%p", header, address));

    EARLY_ASSERT(header,  "header is null",  NgosStatus::ASSERTION);
    EARLY_ASSERT(address, "address is null", NgosStatus::ASSERTION);



    for (good_I64 i = 0; i < header->programHeaderTableEntryCount; ++i)
    {
        ElfProgramHeaderTableEntry *programHeader = (ElfProgramHeaderTableEntry *)((u64)header + header->programHeaderTableOffset + i * header->programHeaderTableEntrySize);

        if (programHeader->type == ElfProgramType::LOAD)
        {
            memcpy((void *)(address + programHeader->physicalAddress), (void *)((u64)header + programHeader->offset), programHeader->fileSize);
        }
        else
        {
            EARLY_LVV(("Ignoring program header with the type %s", enumToFullString(programHeader->type)));
        }
    }



    return NgosStatus::OK;
}

NgosStatus handleRelocations(ElfHeader *header, u64 physicalAddress, u64 virtualAddress)
{
    EARLY_LT((" | header = 0x%p, physicalAddress = 0x%p, virtualAddress = 0x%p", header, physicalAddress, virtualAddress));

    EARLY_ASSERT(header,          "header is null",          NgosStatus::ASSERTION);
    EARLY_ASSERT(physicalAddress, "physicalAddress is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(virtualAddress,  "virtualAddress is null",  NgosStatus::ASSERTION);



    // Kernel image compiled to be loaded at 0xFFFFFFFF80000000 virtual address
    // But we are choosing random virtual address in range 0xFFFFFFFF80000000 - 0xFFFFFFFFC0000000
    // We should iterate all RELA entries in order to make them valid for the chosen virtual address
    u64 delta = virtualAddress - 0xFFFFFFFF80000000;

    EARLY_LVVV(("delta = 0x%016llX", delta));

    // If relocation not needed
    if (delta == 0)
    {
        return NgosStatus::OK;
    }



    for (good_I64 i = 0; i < header->sectionHeaderTableEntryCount; ++i)
    {
        ElfSectionHeaderTableEntry *sectionHeader = (ElfSectionHeaderTableEntry *)((u64)header + header->sectionHeaderTableOffset + i * header->sectionHeaderTableEntrySize);

        // EARLY_LVVV(("sectionHeader[%d]->nameOffset     = 0x%08X",    i, sectionHeader->nameOffset));             // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->type           = %s",        i, enumToFullString(sectionHeader->type))); // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->flags          = 0x%016llX", i, sectionHeader->flags));                  // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->virtualAddress = 0x%016llX", i, sectionHeader->virtualAddress));         // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->offset         = 0x%016llX", i, sectionHeader->offset));                 // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->size           = %u",        i, sectionHeader->size));                   // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->link           = %u",        i, sectionHeader->link));                   // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->info           = %u",        i, sectionHeader->info));                   // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->align          = %u",        i, sectionHeader->align));                  // Commented to avoid too frequent logs
        // EARLY_LVVV(("sectionHeader[%d]->entrySize      = %u",        i, sectionHeader->entrySize));              // Commented to avoid too frequent logs



        if (sectionHeader->type == ElfSectionType::RELA)
        {
            ElfRela *relas = (ElfRela *)((u64)header + sectionHeader->offset);

            i64 count = sectionHeader->size / sizeof(ElfRela);
            // EARLY_LVVV(("count = %d", count)); // Commented to avoid too frequent logs

            for (good_I64 j = 0; j < count; ++j)
            {
                ElfRela &rela = relas[j];

                // EARLY_LVVV(("relas[%d].offset = 0x%016llX", j, rela.offset));                 // Commented to avoid too frequent logs
                // EARLY_LVVV(("relas[%d].info   = 0x%016llX", j, rela.info));                   // Commented to avoid too frequent logs
                // EARLY_LVVV(("relas[%d].addend = 0x%016llX", j, rela.addend));                 // Commented to avoid too frequent logs
                // EARLY_LVVV(("relas[%d].type   = %s",        j, enumToFullString(rela.type))); // Commented to avoid too frequent logs

                if (rela.offset >= 0xFFFFFFFF80000000)
                {
                    switch (rela.type)
                    {
                        case ElfRelocationType::D32:
                        {
                            u64 relaAddress = physicalAddress + (rela.offset - 0xFFFFFFFF80000000);

                            EARLY_LVV(("Handling RELA entry(ElfRelocationType::D32)  at 0x%p:         0x%08X =>         0x%08X", relaAddress, *(u32 *)relaAddress, *(u32 *)relaAddress + delta));

                            *(u32 *)relaAddress += delta;
                        }
                        break;

                        case ElfRelocationType::D32S:
                        {
                            u64 relaAddress = physicalAddress + (rela.offset - 0xFFFFFFFF80000000);

                            EARLY_LVV(("Handling RELA entry(ElfRelocationType::D32S) at 0x%p:         0x%08X =>         0x%08X", relaAddress, *(u32 *)relaAddress, *(u32 *)relaAddress + delta));

                            *(u32 *)relaAddress += delta;
                        }
                        break;

                        case ElfRelocationType::D64:
                        {
                            u64 relaAddress = physicalAddress + (rela.offset - 0xFFFFFFFF80000000);

                            EARLY_LVV(("Handling RELA entry(ElfRelocationType::D64)  at 0x%p: 0x%016llX => 0x%016llX", relaAddress, *(u64 *)relaAddress, *(u64 *)relaAddress + delta));

                            *(u64 *)relaAddress += delta;
                        }
                        break;

                        default:
                        {
                            // EARLY_LVV(("Ignoring RELA entry with the type %s", enumToFullString(rela.type))); // Commented to avoid too frequent logs
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            // EARLY_LVV(("Ignoring section header with the type %s", enumToFullString(sectionHeader->type))); // Commented to avoid too frequent logs
        }
    }



    return NgosStatus::OK;
}
