#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSEMICOLONVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSEMICOLONVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>



class CppSemicolonVerifier: public BaseCodeVerifier
{
public:
    CppSemicolonVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSEMICOLONVERIFIER_H
