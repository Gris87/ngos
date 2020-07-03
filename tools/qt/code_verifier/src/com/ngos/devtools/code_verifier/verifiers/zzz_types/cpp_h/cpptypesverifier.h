#ifndef CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPTYPESVERIFIER_H
#define CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPTYPESVERIFIER_H



#include "com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class CppTypesVerifier: public BaseCodeVerifier
{
public:
    CppTypesVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mDefinitionRegExp;
};



#endif // CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPTYPESVERIFIER_H
