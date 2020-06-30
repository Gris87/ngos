#ifndef CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_INDENTSPACESVERIFIER_H
#define CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_INDENTSPACESVERIFIER_H



#include "src/com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h"



class IndentSpacesVerifier: public BaseCodeVerifier
{
public:
    IndentSpacesVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_INDENTSPACESVERIFIER_H
