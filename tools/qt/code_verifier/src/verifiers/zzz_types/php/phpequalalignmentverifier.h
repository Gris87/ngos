#ifndef CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPEQUALALIGNMENTVERIFIER_H
#define CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPEQUALALIGNMENTVERIFIER_H



#include "src/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class PhpEqualAlignmentVerifier: public BaseCodeVerifier
{
public:
    PhpEqualAlignmentVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mEqualExpressionRegExp;
};



#endif // CODE_VERIFIER_SRC_VERIFIERS_ZZZ_TYPES_PHP_PHPEQUALALIGNMENTVERIFIER_H
