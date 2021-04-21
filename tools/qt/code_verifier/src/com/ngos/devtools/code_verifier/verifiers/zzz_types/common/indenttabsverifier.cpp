#include "indenttabsverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



IndentTabsVerifier::IndentTabsVerifier()
    : BaseCodeVerifier(VERIFICATION_INDENT_TABS)
{
    // Nothing
}

void IndentTabsVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);



        for (qint64 j = 0; j < line.length(); ++j)
        {
            QChar ch = line.at(j);

            if (ch != '\t')
            {
                if (ch == ' ')
                {
                    worker->addError(path, i, "Combination of tabs and spaces in indent");
                }

                break;
            }
        }
    }
}



IndentTabsVerifier indentTabsVerifierInstance;
