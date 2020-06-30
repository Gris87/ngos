#include "cppsinglecharverifier.h"

#include <console/console.h>

#include "src/other/codeverificationfiletype.h"



#define MODE_NORMAL   0
#define MODE_IN_QUOTE 1



CppSingleCharVerifier::CppSingleCharVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppSingleCharVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppSingleCharVerifier");
        removeComments(line);



        if (!line.contains("asm volatile"))
        {
            quint8 mode       = MODE_NORMAL;
            qint64 startQuote = -1;

            for (qint64 j = 0; j < line.length(); ++j)
            {
                if (line.at(j) == '\"')
                {
                    qint64 escapeCount = 0;

                    while (j - escapeCount - 1 >= 0 && line.at(j - escapeCount - 1) == '\\')
                    {
                        ++escapeCount;
                    }

                    if (escapeCount % 2 == 0)
                    {
                        switch (mode)
                        {
                            case MODE_NORMAL:
                            {
                                mode       = MODE_IN_QUOTE;
                                startQuote = j;
                            }
                            break;

                            case MODE_IN_QUOTE:
                            {
                                mode = MODE_NORMAL;

                                if (
                                    line.trimmed() != "\"\\n\" \\"
                                    &&
                                    !line.contains("extern \"C\"") // Ignore CppExternDeclaredVerifier
                                   )
                                {
                                    if (
                                        j - startQuote == 2
                                        ||
                                        (
                                         j - startQuote == 3
                                         &&
                                         line.at(startQuote + 1) == '\\'
                                        )
                                       )
                                    {
                                        worker->addWarning(path, i, "Quote can be converted to the single char");
                                    }
                                }
                            }
                            break;

                            default:
                            {
                                Console::err(QString("Unknown mode %1").arg((qint64)mode));
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}



CppSingleCharVerifier cppSingleCharVerifierInstance;
