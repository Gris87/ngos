#ifndef FILEINFO_H
#define FILEINFO_H



#include <QString>



struct FileInfo
{
    QString downloadName;
    QString filename;
    QString hash;
};

Q_DECLARE_METATYPE(FileInfo *); // TEST: NO



#endif // FILEINFO_H
