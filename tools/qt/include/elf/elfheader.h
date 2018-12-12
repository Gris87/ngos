#ifndef ELF_ELFHEADER_H
#define ELF_ELFHEADER_H



#include "elfheaderidentification.h"
#include "elfmachine.h"
#include "elftype.h"
#include "elfversion.h"



struct ElfHeader
{
    ElfHeaderIdentification identification;
    ElfType                 type;
    ElfMachine              machine;
    ElfVersion              version;
    quint64                 entryPoint;
    quint64                 programHeaderTableOffset;
    quint64                 sectionHeaderTableOffset;
    quint32                 flags;
    quint16                 headerSize;
    quint16                 programHeaderTableEntrySize;
    quint16                 programHeaderTableEntryCount;
    quint16                 sectionHeaderTableEntrySize;
    quint16                 sectionHeaderTableEntryCount;
    quint16                 sectionHeaderTableNamesIndex;
};



#endif // ELF_ELFHEADER_H
