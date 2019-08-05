#ifndef SEARCHDEPENDECIESTHREAD_H
#define SEARCHDEPENDECIESTHREAD_H



#include <QThread>

#include <QMap>
#include <QMutex>



class SearchDependenciesThread: public QThread
{
public:
    SearchDependenciesThread(const QString &workingDirectory); // TEST: NO

    static void putSources(const QStringList &sources); // TEST: NO
    static void addSourcesForDependencies(const QStringList &sources); // TEST: NO
    static QString takeSource(); // TEST: NO
    static void addDependencies(const QString &source, const QStringList &dependencies); // TEST: NO
    static QMap<QString, QStringList> buildDependenciesMap(); // TEST: NO

    void addError(const QString &error); // TEST: NO
    const QStringList& getErrors() const; // TEST: NO

    bool handleSource(const QString &source); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    static QStringList                sSources;
    static qint64                     sTotalSources;
    static QMap<QString, QStringList> sDependencies;
    static QMutex                     sSourcesMutex;

    QString     mWorkingDirectory;
    QStringList mErrors;
};



#endif // SEARCHDEPENDECIESTHREAD_H
