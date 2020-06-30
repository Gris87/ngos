#ifndef CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_GENERATOR_H
#define CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_GENERATOR_H



#include <QByteArray>
#include <QStringList>



class Generator
{
public:
    Generator(); // TEST: NO

protected:
    void addOneBlankLine(QStringList &lines); // TEST: NO
    void addThreeBlankLines(QStringList &lines); // TEST: NO

    bool save(const QString &path, const QStringList &lines); // TEST: NO
    bool save(const QString &path, const QByteArray &bytes); // TEST: NO
};



#endif // CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_GENERATOR_H
