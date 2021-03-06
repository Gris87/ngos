#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_CONFIGURE_CONFIGUREGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_CONFIGURE_CONFIGUREGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/generator.h>

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



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_CONFIGURE_CONFIGUREGENERATOR_H
