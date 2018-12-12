#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPENUMVALUESVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPENUMVALUESVERIFIER_H



#include "src/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class CppEnumValuesVerifier: public BaseCodeVerifier
{
public:
    CppEnumValuesVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mDefinitionRegExp;
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPENUMVALUESVERIFIER_H
