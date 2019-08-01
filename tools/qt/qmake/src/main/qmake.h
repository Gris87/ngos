#ifndef QMAKE_SRC_MAIN_QMAKE_H
#define QMAKE_SRC_MAIN_QMAKE_H



#include <QString>



class QMake
{
public:
    QMake(const QString &pathToProFile); // TEST: NO

    qint64 process(); // TEST: NO

private:
    QString mPathToProFile;
};



#endif // QMAKE_SRC_MAIN_QMAKE_H
