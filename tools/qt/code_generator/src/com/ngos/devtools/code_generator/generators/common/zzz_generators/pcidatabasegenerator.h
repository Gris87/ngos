#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>



typedef QMap<quint16, QString>       PciInterfaces;
typedef QMap<quint16, PciInterfaces> PciSubClasses;
typedef QMap<quint16, PciSubClasses> PciBaseClasses;



class PciDatabaseGenerator: public CommonGenerator
{
public:
    PciDatabaseGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO

private:
    bool prepareDatabase(QStringList &lines); // TEST: NO
    bool parseDatabase(const QStringList &lines, PciBaseClasses &baseClasses); // TEST: NO
    bool generateBaseClasses(const QString &path, const PciBaseClasses &baseClasses); // TEST: NO
    bool generateSubClasses(const QString &path, quint16 baseClassId, const PciSubClasses &subClasses); // TEST: NO
    bool generateBaseClassesFile(const QString &path, const PciBaseClasses &baseClasses); // TEST: NO
    bool generateSubClassesFile(const QString &path, quint16 baseClassId, const PciSubClasses &subClasses); // TEST: NO
    bool generateInterfacesFile(const QString &path, quint16 baseClassId, const QString &baseClassDescription, quint16 subClassId, const PciInterfaces &interfaces); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H
