#ifndef QMAKE_SRC_MAIN_QMAKE_H
#define QMAKE_SRC_MAIN_QMAKE_H



#include <QRegularExpression>



class QMake
{
public:
    QMake(const QString &pathToProFile); // TEST: NO

    qint64 process(); // TEST: NO

private:
    qint64 processInWorkingDirectory(const QString &workingDirectory, const QString &proFilename); // TEST: NO
    qint64 processLines(const QString &workingDirectory, const QStringList &lines); // TEST: NO
    bool parseEntry(const QString &workingDirectory, const QString &entryName, const QString &entryOperator, const QString &entryValue); // TEST: NO
    qint64 generateMakefile(const QString &workingDirectory); // TEST: NO
    qint64 generateSubdirsMakefile(const QString &workingDirectory); // TEST: NO
    qint64 generateApplicationMakefile(const QString &workingDirectory, const QString &templateValue); // TEST: NO
    qint64 addApplicationObjectsDefinitions(const QString &workingDirectory, QStringList &lines); // TEST: NO
    qint64 addApplicationBuildTargets(const QString &workingDirectory, const QString &templateValue, QStringList &lines); // TEST: NO
    qint64 addResourcesBuildTargets(const QString &workingDirectory, QStringList &lines); // TEST: NO
    qint64 save(const QString &workingDirectory, const QStringList &lines, const QString &phony = ""); // TEST: NO

    QString                    mPathToProFile;
    QRegularExpression         mCommentRegexp;
    QRegularExpression         mEntryRegexp;
    QRegularExpression         mEntryValueRegexp;
    QRegularExpression         mIncludeRegexp;
    QMap<QString, QStringList> mEntries;
    QMap<QString, QString>     mSourceToObjectMap;
    QStringList                mMakefileDependencies;
};



#endif // QMAKE_SRC_MAIN_QMAKE_H
