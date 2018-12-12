#ifndef CODE_GENERATOR_SRC_GENERATORS_CONFIGURE_CONFIGUREGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_CONFIGURE_CONFIGUREGENERATOR_H



#include "src/generators/generator.h"

#include <QList>



class ConfigureGenerator: public Generator
{
public:
    ConfigureGenerator(); // TEST: NO

    static bool generateAll(const QString &path); // TEST: NO

protected:
    virtual bool generate(const QString &path); // TEST: NO

private:
    static QList<ConfigureGenerator *> sGenerators;
};



#endif // CODE_GENERATOR_SRC_GENERATORS_CONFIGURE_CONFIGUREGENERATOR_H
