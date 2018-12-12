#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_BLANKLINESVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_BLANKLINESVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class BlankLinesVerifier: public BaseCodeVerifier
{
public:
    BlankLinesVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_COMMON_BLANKLINESVERIFIER_H
