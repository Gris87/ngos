#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPFORVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPFORVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>

#include <QRegularExpression>



class PhpForVerifier: public BaseCodeVerifier
{
public:
    PhpForVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO
    qint64 verifyCycleFor(CodeWorkerThread *worker, const QString &path, const QStringList &lines, qint64 row, QStringList &variablesStack); // TEST: NO

private:
    QRegularExpression mInitRegexp;
    QRegularExpression mConditionRegexp;
    QRegularExpression mStepRegexp;
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPFORVERIFIER_H
