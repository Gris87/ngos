#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_LINESEPARATORVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_LINESEPARATORVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class LineSeparatorVerifier: public BaseCodeVerifier
{
public:
    LineSeparatorVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_LINESEPARATORVERIFIER_H
