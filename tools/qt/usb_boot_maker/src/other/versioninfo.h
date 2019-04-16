#ifndef VERSIONINFO_H
#define VERSIONINFO_H



#include <QString>



struct VersionInfo
{
    quint64 id;
    quint64 version;
    QString hash;
    QString server;
    qint64  delay;
};



#endif // VERSIONINFO_H
