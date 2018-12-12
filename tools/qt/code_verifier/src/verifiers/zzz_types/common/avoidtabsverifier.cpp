#include "avoidtabsverifier.h"

#include "src/other/codeverificationfiletype.h"



AvoidTabsVerifier::AvoidTabsVerifier()
    : BaseCodeVerifier(VERIFICATION_AVOID_TABS)
{
    // Nothing
}

void AvoidTabsVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (line.contains('\t'))
        {
            worker->addError(path, i, "Tab found");
        }
    }
}



AvoidTabsVerifier avoidTabsVerifierInstance;
