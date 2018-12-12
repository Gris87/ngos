#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPBLOCKDEFINITIONVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPBLOCKDEFINITIONVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class CppBlockDefinitionVerifier: public BaseCodeVerifier
{
public:
    CppBlockDefinitionVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPBLOCKDEFINITIONVERIFIER_H
