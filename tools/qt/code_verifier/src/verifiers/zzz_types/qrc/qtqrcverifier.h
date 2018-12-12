#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_QRC_QTQRCVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_QRC_QTQRCVERIFIER_H



#include "src/verifiers/basecodeverifier.h"



class QtQrcVerifier: public BaseCodeVerifier
{
public:
    QtQrcVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_QRC_QTQRCVERIFIER_H
