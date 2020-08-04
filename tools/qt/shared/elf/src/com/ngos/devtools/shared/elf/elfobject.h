#ifndef COM_NGOS_DEVTOOLS_SHARED_ELF_ELFOBJECT_H
#define COM_NGOS_DEVTOOLS_SHARED_ELF_ELFOBJECT_H



#include <QHash>
#include <QList>
#include <QString>

#include <com/ngos/shared/common/elf/header.h>
#include <com/ngos/shared/common/elf/programheadertableentry.h>
#include <com/ngos/shared/common/elf/sectionheadertableentry.h>
#include <com/ngos/shared/common/elf/symbol.h>



class ElfObject
{
public:
    ElfObject(); // TEST: NO

    bool read(const QString &path, bool *isRunning = 0); // TEST: NO

    const QByteArray& getProgramBytes() const; // TEST: NO
    quint64 getFileSize() const; // TEST: NO
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
    QHash<QString, ElfSectionHeaderTableEntry *>  mNameToSectionMap;
    QHash<QString, ElfSymbol *>                   mNameToSymbolMap;
};



#endif // COM_NGOS_DEVTOOLS_SHARED_ELF_ELFOBJECT_H
