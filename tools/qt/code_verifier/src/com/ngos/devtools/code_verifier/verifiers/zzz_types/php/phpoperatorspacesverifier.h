#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPOPERATORSPACESVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPOPERATORSPACESVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class PhpOperatorSpacesVerifier: public BaseCodeVerifier
{
public:
    PhpOperatorSpacesVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPOPERATORSPACESVERIFIER_H
