#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_BITSSTRUCTURE_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_BITSSTRUCTURE_H



#include <QList>
#include <QString>

#include <com/ngos/devtools/code_generator/other/bitsfield.h>



struct BitsStructure
{
    QString          includePath;
    QString          name;
    quint8           width;
    QList<BitsField> fields;
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_OTHER_BITSSTRUCTURE_H
