#include "mdnewlineverifier.h"

#include "src/com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h"



MdNewLineVerifier::MdNewLineVerifier()
    : BaseDocsVerifier(DocsVerificationFileType::MD)
{
    // Nothing
}

void MdNewLineVerifier::verify(DocsWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);



        if (line.startsWith("```"))
        {
            do
            {
                ++i;
            } while(i < lines.length() && lines.at(i) != "```");

            continue;
        }



        QString lineTrimmed = line.trimmed();

        bool shouldEndsWithBr = false;



        if (
            line != ""
            &&
            (
             !lineTrimmed.startsWith('<')
             ||
             !lineTrimmed.endsWith('>')
            )
            &&
            i + 1 < lines.length()
            &&
            lines.at(i + 1) != ""
            &&
            !lines.at(i + 1).trimmed().startsWith("* ")
            &&
            !lines.at(i + 1).trimmed().startsWith("- ")
            &&
            !lines.at(i + 1).startsWith("==")
            &&
            !lines.at(i + 1).startsWith("--")
            &&
            !lines.at(i + 1).startsWith("| ")
           )
        {
            shouldEndsWithBr = true;
        }



        if (shouldEndsWithBr)
        {
            if (line.contains("<br/>"))
            {
                if (!line.endsWith("<br/>"))
                {
                    worker->addWarning(path, i, "Single new line means nothing for MD. You have to use <br/>");
                }
            }
            else
            {
                worker->addWarning(path, i, "Single new line means nothing for MD. You have to use <br/>");
            }
        }
        else
        {
            if (line.contains("<br/>"))
            {
                worker->addWarning(path, i, "<br/> should be removed");
            }
        }
    }
}



MdNewLineVerifier mdNewLineVerifierInstance;
