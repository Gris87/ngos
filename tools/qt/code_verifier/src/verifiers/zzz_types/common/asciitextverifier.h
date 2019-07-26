#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_ASCIITEXTVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_ASCIITEXTVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class AsciiTextVerifier: public BaseCodeVerifier
{
public:
    AsciiTextVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_ASCIITEXTVERIFIER_H
