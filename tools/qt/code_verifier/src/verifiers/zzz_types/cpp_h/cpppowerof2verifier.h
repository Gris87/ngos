#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPPOWEROF2VERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPPOWEROF2VERIFIER_H



#include "src/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class CppPowerOf2Verifier: public BaseCodeVerifier
{
public:
    CppPowerOf2Verifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mPowerOf2Regexp;
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPPOWEROF2VERIFIER_H
