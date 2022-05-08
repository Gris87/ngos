#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_CPUMODELGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_CPUMODELGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>

#include <QRegularExpression>

#include <com/ngos/devtools/code_generator/other/cpumodel.h>



class CpuModelGenerator: public CommonGenerator
{
public:
    CpuModelGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO

private:
    bool generateVendorModels(const QString &vendor, const QString &path, const QString &url, const QString &searchStartLine, const QString &searchEndLine); // TEST: NO
    bool prepareDatabase(const QString &url, QStringList &lines); // TEST: NO
    bool parseDatabase(const QString &vendor, const QStringList &lines, const QString &searchStartLine, const QString &searchEndLine, QList<CpuModel> &models); // TEST: NO
    bool generateModels(const QString &vendor, const QString &path, const QList<CpuModel> &models); // TEST: NO

    QRegularExpression mFamilyRegExp;
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_CPUMODELGENERATOR_H
