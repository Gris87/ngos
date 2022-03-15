#include "mdheadersverifier.h"                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QDir>                                                                                                                                                                                          // Colorize: green
#include <QFile>                                                                                                                                                                                         // Colorize: green
#include <QFileInfo>                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h>                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
MdHeadersVerifier::MdHeadersVerifier()                                                                                                                                                                   // Colorize: green
    : BaseDocsVerifier(DocsVerificationFileType::MD)                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void MdHeadersVerifier::verify(DocsWorkerThread *worker, const QString &path, const QString & /*content*/, const QStringList &lines)                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    for (qint64 i = 0; i < lines.size(); ++i)                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QString line = lines.at(i);                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            line.startsWith('=')                                                                                                                                                                         // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            line.startsWith('-')                                                                                                                                                                         // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            bool isHeader = true;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (qint64 j = 1; j < line.length(); ++j)                                                                                                                                            // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (line.at(j) != line.at(0))                                                                                                                                              // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    isHeader = false;                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (isHeader)                                                                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                QString sectionName = i > 0 ? lines.at(i - 1) : "";                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (sectionName != "")                                                                                                                                                                   // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    QString sectionHeader(sectionName.length(), line.at(0));                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (line != sectionHeader)                                                                                                                                                           // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        worker->addError(path, i, QString("Invalid line. Expected: %1")                                                                                                                  // Colorize: green
                                                            .arg(sectionHeader)                                                                                                                          // Colorize: green
                        );                                                                                                                                                              // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    QString nextLine = i + 1 < lines.size() ? lines.at(i + 1) : "";                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (nextLine == "")                                                                                                                                                                  // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        ++i;                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                        continue;                                                                                                                                                                        // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                    else                                                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        worker->addWarning(path, i + 1, "Expected blank line after section");                                                                                                            // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                else                                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    worker->addWarning(path, i, "Section name not found");                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
MdHeadersVerifier mdHeadersVerifierInstance;                                                                                                                                                             // Colorize: green
