#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_ASSETS_ASSETSGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_ASSETS_ASSETSGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/generator.h>

#include <QList>



class AssetsGenerator: public Generator
{
public:
    AssetsGenerator(); // TEST: NO

    static bool generateAll(const QString &path); // TEST: NO

protected:
    virtual bool generate(const QString &path); // TEST: NO

private:
    static QList<AssetsGenerator *> sGenerators;
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_ASSETS_ASSETSGENERATOR_H
