#ifndef QMAKE_SRC_MAIN_QMAKE_H
#define QMAKE_SRC_MAIN_QMAKE_H



#include <QRegularExpression>



class QMake
{
public:
    QMake(const QString &pathToProFile); // TEST: NO

    qint64 process(); // TEST: NO

private:
    qint64 processInWorkingDirectory(const QString &workingDirectory, const QString &pathToProFile); // TEST: NO
    qint64 processLines(const QString &workingDirectory, const QStringList &lines); // TEST: NO
    bool parseEntry(const QString &workingDirectory, const QString &entryName, const QString &entryOperator, const QString &entryValue); // TEST: NO
    qint64 generateMakefile(const QString &workingDirectory); // TEST: NO
    qint64 generateSubdirsMakefile(const QString &workingDirectory); // TEST: NO
    qint64 generateApplicationMakefile(const QString &workingDirectory); // TEST: NO
    qint64 generateLibraryMakefile(const QString &workingDirectory); // TEST: NO

    QString                    mPathToProFile;
    QRegularExpression         mCommentRegexp;
    QRegularExpression         mEntryRegexp;
    QRegularExpression         mEntryValueRegexp;
    QMap<QString, QStringList> mEntries;
};



#endif // QMAKE_SRC_MAIN_QMAKE_H
