#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSHIFTVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSHIFTVERIFIER_H



#include "src/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class CppShiftVerifier: public BaseCodeVerifier
{
public:
    CppShiftVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
    bool isPowerOf2(const QString &number); // TEST: NO

private:
    QRegularExpression mShiftRegexp;
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_CPP_H_CPPSHIFTVERIFIER_H
