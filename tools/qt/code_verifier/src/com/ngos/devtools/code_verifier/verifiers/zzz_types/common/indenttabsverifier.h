#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_INDENTTABSVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_INDENTTABSVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class IndentTabsVerifier: public BaseCodeVerifier
{
public:
    IndentTabsVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_INDENTTABSVERIFIER_H
