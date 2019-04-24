#ifndef CODE_GENERATOR_SRC_GENERATORS_GDB_DEBUG_GDBDEBUGGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_GDB_DEBUG_GDBDEBUGGENERATOR_H



#include "src/generators/generator.h"

#include <QList>



class GdbDebugGenerator: public Generator
{
public:
    GdbDebugGenerator(); // TEST: NO

    static bool generateAll(const QString &path); // TEST: NO

protected:
    virtual bool generate(const QString &path); // TEST: NO

private:
    static QList<GdbDebugGenerator *> sGenerators;
};



#endif // CODE_GENERATOR_SRC_GENERATORS_GDB_DEBUG_GDBDEBUGGENERATOR_H
