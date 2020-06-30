#ifndef CODE_GENERATOR_SRC_GENERATORS_ASSETS_ASSETSGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_ASSETS_ASSETSGENERATOR_H



#include "src/generators/generator.h"

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



#endif // CODE_GENERATOR_SRC_GENERATORS_ASSETS_ASSETSGENERATOR_H
