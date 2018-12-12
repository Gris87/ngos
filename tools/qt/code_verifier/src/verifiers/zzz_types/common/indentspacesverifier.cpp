#include "indentspacesverifier.h"

#include "src/other/codeverificationfiletype.h"



#define SPACE_INDENT 4



IndentSpacesVerifier::IndentSpacesVerifier()
    : BaseCodeVerifier(VERIFICATION_INDENT_SPACES)
{
    // Nothing
}

void IndentSpacesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);



        for (qint64 j = 0; j < line.length(); ++j)
        {
            QChar ch = line.at(j);

            if (ch != ' ')
            {
                if (ch == '\t')
                {
                    worker->addError(path, i, "Combination of tabs and spaces in indent");
                }
                else
                {
                    if (j % SPACE_INDENT) // j % SPACE_INDENT != 0
                    {
                        worker->addError(path, i, "Invalid indentation");
                    }
                }

                break;
            }
        }
    }
}



IndentSpacesVerifier indentSpacesVerifierInstance;
