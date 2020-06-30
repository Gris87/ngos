#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_H_CPPHDEFINESVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_H_CPPHDEFINESVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class CppHDefinesVerifier: public BaseCodeVerifier
{
public:
    CppHDefinesVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_H_CPPHDEFINESVERIFIER_H
