#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPSWITCHVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPSWITCHVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class PhpSwitchVerifier: public BaseCodeVerifier
{
public:
    PhpSwitchVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPSWITCHVERIFIER_H
