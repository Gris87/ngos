#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPEQUALALIGNMENTVERIFIER_H                                                                                                            // Colorize: green
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPEQUALALIGNMENTVERIFIER_H                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QRegularExpression>                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
class CppEqualAlignmentVerifier: public BaseCodeVerifier                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
public:                                                                                                                                                                                                  // Colorize: green
    CppEqualAlignmentVerifier(); // TEST: NO                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
private:                                                                                                                                                                                                 // Colorize: green
    QRegularExpression mEqualExpressionRegExp;                                                                                                                                                           // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPEQUALALIGNMENTVERIFIER_H                                                                                                          // Colorize: green
