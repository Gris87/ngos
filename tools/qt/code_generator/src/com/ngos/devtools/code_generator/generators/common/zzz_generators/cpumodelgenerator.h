#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_CPUMODELGENERATOR_H                                                                                                            // Colorize: green
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_CPUMODELGENERATOR_H                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QRegularExpression>                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/code_generator/other/cpumodel.h>                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class CpuModelGenerator: public CommonGenerator                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    CpuModelGenerator(); // TEST: NO                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    bool generate(const QString &path) override; // TEST: NO                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    bool generateVendorModels(const QString &vendor, const QString &path, const QString &url, const QString &searchStartLine, const QString &searchEndLine); // TEST: NO                                 // Colorize: green
    bool prepareDatabase(const QString &url, QStringList &lines); // TEST: NO                                                                                                                            // Colorize: green
    bool parseDatabase(const QString &vendor, const QStringList &lines, const QString &searchStartLine, const QString &searchEndLine, QList<CpuModel> &models); // TEST: NO                              // Colorize: green
    bool generateModels(const QString &vendor, const QString &path, const QString &url, const QList<CpuModel> &models); // TEST: NO                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QRegularExpression mFamilyRegExp;                                                                                                                                                                    // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_CPUMODELGENERATOR_H                                                                                                          // Colorize: green