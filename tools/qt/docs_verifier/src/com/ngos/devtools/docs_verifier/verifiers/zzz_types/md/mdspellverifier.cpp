#include "mdspellverifier.h"                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QDir>                                                                                                                                                                                          // Colorize: green
#include <QProcess>                                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h>                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
MdSpellVerifier::MdSpellVerifier()                                                                                                                                                                       // Colorize: green
    : BaseDocsVerifier(DocsVerificationFileType::MD)                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void MdSpellVerifier::verify(DocsWorkerThread *worker, const QString &path, const QString & /*content*/, const QStringList &/*lines*/)                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QString output = runMdSpell(getDocsFolder(path), path);                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (output != "")                                                                                                                                                                                    // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QStringList spellLines = output.split('\n');                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (qint64 i = 0; i < spellLines.size(); ++i)                                                                                                                                                   // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QString spellLine = spellLines.at(i);                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            qint64 index = spellLine.indexOf('|');                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (index >= 0)                                                                                                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                worker->addError(path, spellLine.left(index).trimmed().toLongLong() - 1, QString("Spell issue found. Fix it or add an exception to docs/.spelling: %1")                                  // Colorize: green
                                                                                                    .arg(spellLine.mid(index + 1).trimmed())                                                             // Colorize: green
                                 );                                                                                                                                                                      // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    else                                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        worker->addError(path, -1, "mdspell tool not found. Please install it with \"npm i markdown-spellcheck -g\"");                                                                                   // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString MdSpellVerifier::getDocsFolder(const QString &path) const                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QString docsFolder = path;                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    do                                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        docsFolder = docsFolder.left(docsFolder.lastIndexOf('/'));                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (QDir(docsFolder + "/docs").exists())                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            docsFolder = docsFolder + "/docs";                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    } while(true);                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return docsFolder;                                                                                                                                                                                   // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString MdSpellVerifier::runMdSpell(const QString &workingDir, const QString &path) const                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QProcess process;                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    process.setWorkingDirectory(workingDir);                                                                                                                                                             // Colorize: green
    process.start("mdspell", QStringList() << "--en-us" << "-n" << "-r" << path);                                                                                                                        // Colorize: green
    process.waitForFinished(-1);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return process.readAllStandardOutput();                                                                                                                                                              // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
MdSpellVerifier mdSpellVerifierInstance;                                                                                                                                                                 // Colorize: green
