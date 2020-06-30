#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPPUNCTUATIONVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPPUNCTUATIONVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class PhpPunctuationVerifier: public BaseCodeVerifier
{
public:
    PhpPunctuationVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPPUNCTUATIONVERIFIER_H
