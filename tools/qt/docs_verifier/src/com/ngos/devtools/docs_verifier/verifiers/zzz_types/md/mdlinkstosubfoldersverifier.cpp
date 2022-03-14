#include "mdlinkstosubfoldersverifier.h"                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QDir>                                                                                                                                                                                          // Colorize: green
#include <QFile>                                                                                                                                                                                         // Colorize: green
#include <QFileInfo>                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h>                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
MdLinksToSubfoldersVerifier::MdLinksToSubfoldersVerifier()                                                                                                                                               // Colorize: green
    : BaseDocsVerifier(DocsVerificationFileType::MD)                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void MdLinksToSubfoldersVerifier::verify(DocsWorkerThread *worker, const QString &path, const QString & /*content*/, const QStringList &lines)                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QString     parentFolder = path.left(path.lastIndexOf('/') + 1);                                                                                                                                     // Colorize: green
    QStringList subFolders   = QDir(parentFolder).entryList(QDir::Dirs | QDir::NoDotAndDotDot);                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    for (qint64 i = 0; i < subFolders.size(); ++i)                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QString subFolder = subFolders.at(i);                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (QFile::exists(parentFolder + '/' + subFolder + "/README.md"))                                                                                                                                // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QString sectionName = subFolder.mid(subFolder.indexOf('.') + 1).trimmed();                                                                                                                   // Colorize: green
            QString sectionLink = subFolder.replace(' ', "%20") + "/README.md";                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            QString search = QString("* [%1](%2)")                                                                                                                                                       // Colorize: green
                                        .arg(sectionName)                                                                                                                                                // Colorize: green
                                        .arg(sectionLink);                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            bool found = false;                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            for (qint64 j = 0; j < lines.size(); ++j)                                                                                                                                                    // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                QString lineTrimmed = lines.at(j).trimmed();                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (lineTrimmed.startsWith(search))                                                                                                                                                      // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    found = true;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    break;                                                                                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (!found)                                                                                                                                                                                  // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                worker->addError(path, -1, QString("Link to subsection not found: %1")                                                                                                                   // Colorize: green
                                                    .arg(search)                                                                                                                                         // Colorize: green
                                 );                                                                                                                                                                      // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
MdLinksToSubfoldersVerifier mdLinksToSubfoldersVerifierInstance;                                                                                                                                         // Colorize: green