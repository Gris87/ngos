#ifndef CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_COMMONGENERATOR_H
#define CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_COMMONGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/generator.h>

#include <QList>



class CommonGenerator: public Generator
{
public:
    CommonGenerator(); // TEST: NO

    static bool generateAll(const QString &path); // TEST: NO

protected:
    virtual bool generate(const QString &path); // TEST: NO

private:
    static QList<CommonGenerator *> sGenerators;
};



#endif // CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_COMMONGENERATOR_H
