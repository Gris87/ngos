#ifndef ELF_ELFOBJECT_H
#define ELF_ELFOBJECT_H



#include <QHash>
#include <QList>
#include <QString>

#include "elfheader.h"
#include "elfprogramheadertableentry.h"
#include "elfsectionheadertableentry.h"
#include "elfsymbol.h"



class ElfObject
{
public:
    ElfObject(); // TEST: NO

    bool read(const QString &path, bool *isRunning = 0); // TEST: NO

    const QByteArray& getProgramBytes() const; // TEST: NO
    quint64 getFileSize() const; // TEST: NO
    quint64 getMemorySize() const; // TEST: NO
    const QList<ElfSectionHeaderTableEntry *>& getSections() const; // TEST: NO
    const QHash<QString, ElfSectionHeaderTableEntry *>& getSectionsMap() const; // TEST: NO
    ElfSectionHeaderTableEntry* getSection(QString name); // TEST: NO
    const QHash<QString, ElfSymbol *>& getSymbolMap() const; // TEST: NO
    ElfSymbol* getSymbol(QString name); // TEST: NO

private:
    bool verifyHeader(); // TEST: NO

    QByteArray                                    mBytes;
    ElfHeader                                    *mHeader;
    QList<ElfProgramHeaderTableEntry *>           mProgramHeaderTableEntries;
    QList<ElfSectionHeaderTableEntry *>           mSectionHeaderTableEntries;
    QByteArray                                    mProgramBytes;
    quint64                                       mMemorySize;
    QHash<QString, ElfSectionHeaderTableEntry *>  mNameToSectionMap;
    QHash<QString, ElfSymbol *>                   mNameToSymbolMap;
};



#endif // ELF_ELFOBJECT_H
