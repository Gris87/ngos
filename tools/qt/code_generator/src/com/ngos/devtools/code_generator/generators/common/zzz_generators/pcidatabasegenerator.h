#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>

#include <com/ngos/devtools/code_generator/other/pcibaseclass.h>
#include <com/ngos/devtools/code_generator/other/pcivendor.h>



typedef QMap<quint8,  PciBaseClass> PciBaseClasses;
typedef QMap<quint16, PciVendor>    PciVendors;



class PciDatabaseGenerator: public CommonGenerator
{
public:
    PciDatabaseGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO

private:
    bool prepareDatabase(QStringList &lines); // TEST: NO
    bool parseDatabase(const QStringList &lines, PciBaseClasses &baseClasses, PciVendors &vendors); // TEST: NO
    bool generateBaseClasses(const QString &path, const PciBaseClasses &baseClasses); // TEST: NO
    bool generateSubClasses(const QString &path, quint8 baseClassId, const PciBaseClass &baseClass); // TEST: NO
    bool generateVendors(const QString &path, const PciVendors &vendors); // TEST: NO
    bool generateDevices(const QString &path, quint16 vendorId, const PciVendor &vendor); // TEST: NO
    bool generateBaseClassesFile(const QString &path, const PciBaseClasses &baseClasses); // TEST: NO
    bool generateSubClassesFile(const QString &path, quint8 baseClassId, const PciBaseClass &baseClass); // TEST: NO
    bool generateInterfacesFile(const QString &path, quint8 baseClassId, const QString &baseClassDescription, quint8 subClassId, const PciSubClass &subClass); // TEST: NO
    bool generateVendorsFile(const QString &path, const PciVendors &vendors); // TEST: NO
    bool generateDevicesFile(const QString &path, quint16 vendorId, const PciVendor &vendor); // TEST: NO
    bool generateSubDevicesFile(const QString &path, quint16 vendorId, quint16 deviceId, const PciDevice &device); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_PCIDATABASEGENERATOR_H
