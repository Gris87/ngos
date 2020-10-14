#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>

#include <QRegularExpression>

#include <com/ngos/devtools/code_generator/other/bitsstructure.h>



class BitsTestGenerator: public CommonGenerator
{
public:
    BitsTestGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO

private:
    bool generateTests(const QString &path, const QString &destinationFilePath); // TEST: NO
    bool obtainBitsFromFolder(const QString &path, QList<BitsStructure> &bits); // TEST: NO
    bool obtainBitsFromFile(const QString &path, QList<BitsStructure> &bits); // TEST: NO

    QRegularExpression mDefinitionRegExp;
    QRegularExpression mBitsDefinitionRegExp;
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H
