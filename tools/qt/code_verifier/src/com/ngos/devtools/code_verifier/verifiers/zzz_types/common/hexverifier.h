#ifndef CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_HEXVERIFIER_H
#define CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_HEXVERIFIER_H



#include "com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h"

#include <QRegularExpression>



class HexVerifier: public BaseCodeVerifier
{
public:
    HexVerifier(); // TEST: NO

    void verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines) override; // TEST: NO

private:
    QRegularExpression mHexRegExp;
};



#endif // CODE_VERIFIER_SRC_COM_NGOS_DEVTOOLS_CODE_VERIFIER_VERIFIERS_ZZZ_TYPES_COMMON_HEXVERIFIER_H
