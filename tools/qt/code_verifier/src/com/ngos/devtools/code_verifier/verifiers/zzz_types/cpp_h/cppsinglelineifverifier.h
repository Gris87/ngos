#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSINGLELINEIFVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSINGLELINEIFVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>



class CppSingleLineIfVerifier: public BaseCodeVerifier
{
public:
    CppSingleLineIfVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSINGLELINEIFVERIFIER_H
