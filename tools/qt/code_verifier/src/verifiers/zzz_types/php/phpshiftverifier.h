#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPSHIFTVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPSHIFTVERIFIER_H



#include "src/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class PhpShiftVerifier: public BaseCodeVerifier
{
public:
    PhpShiftVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
    bool isPowerOf2(const QString &number); // TEST: NO

private:
    QRegularExpression mShiftRegexp;
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPSHIFTVERIFIER_H