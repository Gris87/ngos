#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>

#include <QRegularExpression>

#include <com/ngos/devtools/code_generator/other/bitsstructure.h>
#include <com/ngos/shared/common/ngos/types.h>



class BitsTestGenerator: public CommonGenerator
{
public:
    BitsTestGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO

private:
    bool generateTests(const QString &path, const QString &destinationFilePath); // TEST: NO
    bool addBitsStructureLines(QStringList &lines, const BitsStructure &structure, bool useValue = false, qint64 value = 0); // TEST: NO
    bool obtainBitsFromFolder(const QString &path, QList<BitsStructure> &bits); // TEST: NO
    bool obtainBitsFromFile(const QString &path, QList<BitsStructure> &bits); // TEST: NO

    static const char8 *sFieldShortcuts;
    QRegularExpression  mDefinitionRegExp;
    QRegularExpression  mBitsDefinitionRegExp;
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H
