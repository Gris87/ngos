#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_TASK_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_TASK_H



#include <com/ngos/kernel/other/kerneldefines.h>
#include <com/ngos/kernel/other/task/taskstate.h>
#include <com/ngos/kernel/other/task/threadinfo.h>
#include <com/ngos/shared/common/ngos/types.h>



struct Task
{
    ThreadInfo  threadInfo;
    TaskState   state;
    u8         *stack;
    u64         stackCanary;
};



extern Task initTask;               // initTask declared in task.cpp file
extern u8   initStack[THREAD_SIZE]; // initStack declared in task.cpp file



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_TASK_TASK_H
