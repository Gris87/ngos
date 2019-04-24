#ifndef CODE_GENERATOR_SRC_GENERATORS_GDB_DEBUG_ZZZ_GENERATORS_HEXARRAYSGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_GDB_DEBUG_ZZZ_GENERATORS_HEXARRAYSGENERATOR_H



#include "src/generators/gdb_debug/gdbdebuggenerator.h"



class HexArraysGenerator: public GdbDebugGenerator
{
public:
    HexArraysGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_GENERATORS_GDB_DEBUG_ZZZ_GENERATORS_HEXARRAYSGENERATOR_H
