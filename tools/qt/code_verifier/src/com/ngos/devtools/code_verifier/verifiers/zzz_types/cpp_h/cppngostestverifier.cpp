#include "cppngostestverifier.h"

#include <QDir>
#include <QFileInfo>
#include <QQueue>

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppNgosTestVerifier::CppNgosTestVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mTestSectionRegExp("^.*\\/test\\/.*\\/sections\\/(section\\d+)\\/.*$")
{
    // Nothing
}

void CppNgosTestVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines)
{
    if (
        !path.contains("/test/")
        ||
        !path.contains("/section")
       )
    {
        return;
    }



    QRegularExpressionMatch match = mTestSectionRegExp.match(path);

    if (!match.hasMatch())
    {
        worker->addError(path, -1, "Invalid project structure for tests");

        return;
    }



    QString section = match.captured(1);



    if (content.contains("CALL_TEST_CASES("))
    {
        QString     expectedContent = "\n\n\n    INIT_TEST_SECTION();\n\n";
        QStringList callTestLines;



        QString parentFolder = path.left(path.lastIndexOf('/') + 1);

        QQueue<QFileInfo> files;
        files.enqueue(QFileInfo(parentFolder));

        while (!files.isEmpty())
        {
            QFileInfo file = files.dequeue();

            QString filePath = file.absoluteFilePath();



            if (file.isDir())
            {
                QFileInfoList filesInfo = QDir(filePath).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

                for (qint64 i = 0; i < filesInfo.length(); ++i)
                {
                    files.enqueue(filesInfo.at(i));
                }
            }
            else
            {
                if (filePath.endsWith(".h") && filePath != path && !filePath.contains("/asm_"))
                {
                    QString expectedPath = filePath.mid(filePath.lastIndexOf("/test/") + 6);

                    qint64 index = expectedPath.indexOf("sections/");

                    if (index >= 0)
                    {
                        expectedPath = expectedPath.mid(expectedPath.indexOf('/', index + 9) + 1);
                    }

                    if (expectedPath.endsWith(".h"))
                    {
                        expectedPath.remove(expectedPath.length() - 2, 2);
                    }

                    expectedPath = expectedPath.replace('/', '_');



                    callTestLines.append("    CALL_TEST_CASES(" + section + ", " + expectedPath + ");");
                }
            }
        }



        callTestLines.sort();
        expectedContent.append(callTestLines.join('\n'));

        expectedContent += "\n\n    SUMMARY_TEST_SECTION();\n}\n\n\n\n#endif\n\n\n\n#endif //";



        if (!content.contains(expectedContent))
        {
            worker->addError(path, -1, QString("Expected lines not found:\n%1").arg(expectedContent));
        }
    }
    else
    {
        for (qint64 i = 0; i < lines.length(); ++i)
        {
            QString line = lines.at(i);
            VERIFIER_IGNORE(line, "// Ignore CppNgosTestVerifier");
            removeComments(line);



            if (line.startsWith("TEST_CASES("))
            {
                QString expectedPath = path.mid(path.lastIndexOf("/test/") + 6);

                qint64 index = expectedPath.indexOf("sections/");

                if (index >= 0)
                {
                    expectedPath = expectedPath.mid(expectedPath.indexOf('/', index + 9) + 1);
                }

                if (expectedPath.endsWith(".h"))
                {
                    expectedPath.remove(expectedPath.length() - 2, 2);
                }

                expectedPath = expectedPath.replace('/', '_');



                QString expectedLine = "TEST_CASES(" + section + ", " + expectedPath + ");";

                if (line != expectedLine)
                {
                    worker->addError(path, i, QString("Expected line: %1").arg(expectedLine));
                }



                break;
            }
        }
    }
}



CppNgosTestVerifier cppNgosTestVerifierInstance;
