#include "qtqrcverifier.h"

#include <QDir>
#include <QQueue>

#include "src/other/codeverificationfiletype.h"



QtQrcVerifier::QtQrcVerifier()
    : BaseCodeVerifier(VerificationFileType::QRC)
{
    // Nothing
}

void QtQrcVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &/*lines*/)
{
    QString parentFolder = path.left(path.lastIndexOf('/') + 1);



    QString assetsFolder = parentFolder + "/assets";

    if (!QDir(assetsFolder).exists())
    {
        worker->addError(path, -1, "All Qt resources should be located in assets folder");

        return;
    }



    QString expectedContent;

    expectedContent.append("<RCC>\n");
    expectedContent.append("    <qresource prefix=\"/\">\n"); // Ignore CppAlignmentVerifier // Ignore CppOperatorSpacesVerifier



    QQueue<QFileInfo> files;
    files.enqueue(QFileInfo(assetsFolder));

    while (!files.isEmpty())
    {
        QFileInfo file = files.dequeue();

        QString path = file.absoluteFilePath();



        if (file.isDir())
        {
            QFileInfoList filesInfo = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

            for (qint64 i = 0; i < filesInfo.length(); ++i)
            {
                files.enqueue(filesInfo.at(i));
            }
        }
        else
        {
            if (!path.endsWith(".ts"))
            {
                expectedContent.append(QString("        <file>%1</file>\n").arg(path.mid(parentFolder.length()))); // Ignore CppAlignmentVerifier
            }
        }
    }



    expectedContent.append("    </qresource>\n"); // Ignore CppAlignmentVerifier
    expectedContent.append("</RCC>\n");



    if (content != expectedContent)
    {
        worker->addError(path, -1, QString("Expected file content:\n%1").arg(expectedContent));
    }
}



QtQrcVerifier qtQrcVerifierInstance;
