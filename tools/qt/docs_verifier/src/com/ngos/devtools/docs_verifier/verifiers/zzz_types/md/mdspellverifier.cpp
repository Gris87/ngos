#include "mdspellverifier.h"

#include <QDir>
#include <QProcess>

#include <com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h>



MdSpellVerifier::MdSpellVerifier()
    : BaseDocsVerifier(DocsVerificationFileType::MD)
{
    // Nothing
}

void MdSpellVerifier::verify(DocsWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &/*lines*/)
{
    QString parentFolder = path;

    do
    {
        parentFolder = parentFolder.left(parentFolder.lastIndexOf('/'));

        if (QDir(parentFolder + "/docs").exists())
        {
            parentFolder = parentFolder + "/docs";

            break;
        }
    } while(true);



    QProcess process;

    process.setWorkingDirectory(parentFolder);
    process.start("mdspell", QStringList() << "--en-us" << "-n" << "-r" << path);
    process.waitForFinished();



    QString output = process.readAllStandardOutput();

    if (output != "")
    {
        QStringList spellLines = output.split('\n');

        for (qint64 i = 0; i < spellLines.length(); ++i)
        {
            QString spellLine = spellLines.at(i);

            qint64 index = spellLine.indexOf('|');

            if (index >= 0)
            {
                worker->addError(path, spellLine.left(index).trimmed().toLongLong() - 1, QString("Spell issue found. Fix it or add an exception to docs/.spelling: %1").arg(spellLine.mid(index + 1).trimmed()));
            }
        }
    }
    else
    {
        worker->addError(path, -1, "mdspell tool not found. Please install it with \"npm i markdown-spellcheck -g\"");
    }
}



MdSpellVerifier mdSpellVerifierInstance;
