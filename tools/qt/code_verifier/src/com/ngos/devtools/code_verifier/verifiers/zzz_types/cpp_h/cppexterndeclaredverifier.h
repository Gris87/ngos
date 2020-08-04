#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPEXTERNDECLAREDVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPEXTERNDECLAREDVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>



class CppExternDeclaredVerifier: public BaseCodeVerifier
{
public:
    CppExternDeclaredVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_CPP_H_CPPEXTERNDECLAREDVERIFIER_H
