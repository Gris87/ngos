#ifndef CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPBLOCKDEFINITIONVERIFIER_H
#define CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPBLOCKDEFINITIONVERIFIER_H



#include "com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h"



class PhpBlockDefinitionVerifier: public BaseCodeVerifier
{
public:
    PhpBlockDefinitionVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPBLOCKDEFINITIONVERIFIER_H
