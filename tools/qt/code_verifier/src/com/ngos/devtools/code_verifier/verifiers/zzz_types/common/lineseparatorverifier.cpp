#include "lineseparatorverifier.h"

#include "com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"



LineSeparatorVerifier::LineSeparatorVerifier()
    : BaseCodeVerifier(VERIFICATION_ANY_FILE_TYPE)
{
    // Nothing
}

void LineSeparatorVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &/*lines*/)
{
    if (content.contains('\r'))
    {
        worker->addError(path, -1, "Incorrect line separator detected");
    }
}



LineSeparatorVerifier lineSeparatorVerifierInstance;
