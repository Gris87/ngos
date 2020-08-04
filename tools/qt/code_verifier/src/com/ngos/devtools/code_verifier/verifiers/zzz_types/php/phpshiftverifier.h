#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPSHIFTVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPSHIFTVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>

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



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPSHIFTVERIFIER_H
