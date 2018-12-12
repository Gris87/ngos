#ifndef ELF_ELFSYMBOL_H
#define ELF_ELFSYMBOL_H



#include <Qt>

#include "elfsymbolbind.h"
#include "elfsymboltype.h"
#include "elfsymbolvisibility.h"



#define ELF_SYMBOL_BIND(info)        ((info) >> 4)                      // TEST: NO
#define ELF_SYMBOL_TYPE(info)        ((info) & 0x0F)                    // TEST: NO
#define ELF_SYMBOL_INFO(bind, type)  (((bind) << 4) + ((type) & 0x0F))  // TEST: NO

#define ELF_SYMBOL_VISIBILITY(other) ((other) & 0x03)   // TEST: NO



struct ElfSymbol
{
    quint32 nameOffset;
    quint8  info;
    quint8  other;
    quint16 sectionIndex;
    quint64 value;
    quint64 size;
};



#endif // ELF_ELFSYMBOL_H
