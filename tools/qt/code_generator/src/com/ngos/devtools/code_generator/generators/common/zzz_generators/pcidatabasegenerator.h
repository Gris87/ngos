#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>

#include <QRegularExpression>



typedef QMap<quint16, QString>       PciInterfaces;
typedef QMap<quint16, PciInterfaces> PciSubClasses;
typedef QMap<quint16, PciSubClasses> PciBaseClasses;



class PciDatabaseGenerator: public CommonGenerator
{
public:
    PciDatabaseGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO

private:
    bool obtainBaseClasses(PciBaseClasses &baseClasses); // TEST: NO
    bool prepareSpecification(QStringList &lines); // TEST: NO
    bool parseSpecification(const QStringList &lines, PciBaseClasses &baseClasses); // TEST: NO
    bool parseBaseClass(const QStringList &lines, qint64 start, qint64 end, PciBaseClasses &baseClasses); // TEST: NO
    bool parseBaseClassFallback(const QStringList &lines, qint64 start, qint64 end, PciBaseClasses &baseClasses); // TEST: NO
    bool generateBaseClasses(const QString &path, const PciBaseClasses &baseClasses); // TEST: NO
    bool generateSubClasses(const QString &path, quint16 baseClassId, const PciSubClasses &subClasses); // TEST: NO
    bool generateBaseClassesFile(const QString &path, const PciBaseClasses &baseClasses); // TEST: NO
    bool generateSubClassesFile(const QString &path, quint16 baseClassId, const PciSubClasses &subClasses); // TEST: NO
    bool generateInterfacesFile(const QString &path, quint16 baseClassId, quint16 subClassId, const PciInterfaces &interfaces); // TEST: NO

    QRegularExpression mBaseClassTitleRegExp;
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H
