#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_GENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_GENERATOR_H



#include <QByteArray>
#include <QStringList>



class Generator
{
public:
    Generator(); // TEST: NO

    static qint64 getNumberOfGeneratedFiles(); // TEST: NO

protected:
    void addThreeBlankLines(QStringList &lines); // TEST: NO

    bool save(const QString &path, const QStringList &lines); // TEST: NO
    bool save(const QString &path, const QByteArray &bytes); // TEST: NO

private:
    static qint64 sNumberOfGeneratedFiles;
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_GENERATOR_H
