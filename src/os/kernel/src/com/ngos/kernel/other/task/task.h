#ifndef COM_NGOS_KERNEL_OTHER_TASK_TASK_H
#define COM_NGOS_KERNEL_OTHER_TASK_TASK_H



#include <com/ngos/kernel/other/kerneldefines.h>
#include <com/ngos/kernel/other/task/taskstate.h>
#include <com/ngos/kernel/other/task/threadinfo.h>
#include <com/ngos/shared/common/ngos/types.h>



struct Task
{
    ThreadInfo  threadInfo;
    TaskState   state;
    bad_uint8         *stack;
    bad_uint64         stackCanary;
};



extern Task initTask;               // initTask declared in task.cpp file
extern bad_uint8   initStack[THREAD_SIZE]; // initStack declared in task.cpp file



#endif // COM_NGOS_KERNEL_OTHER_TASK_TASK_H
