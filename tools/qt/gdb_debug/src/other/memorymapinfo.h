#ifndef GDB_DEBUG_SRC_OTHER_MEMORYMAPINFO_H
#define GDB_DEBUG_SRC_OTHER_MEMORYMAPINFO_H



#include <QBrush>



struct MemoryMapInfo
{
    MemoryMapInfo(QBrush *brush, qint64 count) // TEST: NO
    {
        this->brush = brush;
        this->count = count;
    }



    QBrush *brush;
    qint64  count;
};



#endif // GDB_DEBUG_SRC_OTHER_MEMORYMAPINFO_H
