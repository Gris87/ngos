#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>
#include <com/ngos/devtools/code_generator/other/bitstestmetadata.h>



class BitsTestGenerator: public CommonGenerator
{
public:
    BitsTestGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO

private:
    bool generateTests(const QString &path, const QString &destinationFilePath); // TEST: NO
    bool obtainBitsFromFolder(const QString &path, QList<BitsTestMetadata> &bits); // TEST: NO
    bool obtainBitsFromFile(const QString &path, QList<BitsTestMetadata> &bits); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_BITSTESTGENERATOR_H
