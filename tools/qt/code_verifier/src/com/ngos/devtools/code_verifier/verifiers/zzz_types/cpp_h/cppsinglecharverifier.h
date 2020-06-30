#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSINGLECHARVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSINGLECHARVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class CppSingleCharVerifier: public BaseCodeVerifier
{
public:
    CppSingleCharVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSINGLECHARVERIFIER_H
