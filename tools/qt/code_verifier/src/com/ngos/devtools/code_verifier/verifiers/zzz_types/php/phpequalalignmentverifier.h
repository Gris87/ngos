#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPEQUALALIGNMENTVERIFIER_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPEQUALALIGNMENTVERIFIER_H



#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>

#include <QRegularExpression>



class PhpEqualAlignmentVerifier: public BaseCodeVerifier
{
public:
    PhpEqualAlignmentVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mEqualExpressionRegExp;
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_PHP_PHPEQUALALIGNMENTVERIFIER_H
