/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - tasks.c
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*      1.1      2023-Dec-04          Refactored
*
*/

#include "task.h"

TASK head = NULL;

TASK CreateTask(int taskNum, char* taskName, char* status) 
{
    TASK new_task = (TASK)malloc(sizeof(struct task));
    if (new_task == NULL) 
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_task->taskNum = taskNum;
    strncpy(new_task->taskName, taskName, MAXNAME);
    strncpy(new_task->status, status, MAXSTATUS);
    new_task->next = NULL;
    new_task->prev = NULL;
    return new_task;
}

bool CopyTask(TASK* dest, const TASK* src) {
    if (dest == NULL || src == NULL) {
        return false;
    }
    (*dest)->taskNum = (*src)->taskNum;
    strncpy((*dest)->taskName, (*src)->taskName, MAXNAME);
    strncpy((*dest)->status, (*src)->status, MAXSTATUS);
    return true;
}

bool SetTaskNum(TASK* t, int taskNum) {
    if (t == NULL) {
        return false;
    }
    (*t)->taskNum = taskNum;
    return true;
}

void SetTaskName(TASK* t, char* taskName) {
    if (t != NULL) {
        strncpy((*t)->taskName, taskName, MAXNAME);
    }
}

void SetTaskStatus(TASK* t, char* status) {
    if (t != NULL) {
        strncpy((*t)->status, status, MAXSTATUS);
    }
}

bool GetTaskNum(TASK* t, int* taskNum) {
    if (t == NULL) {
        return false;
    }
    *taskNum = (*t)->taskNum;
    return true;
}

bool GetTaskName(TASK* t, char* taskName) {
    if (t == NULL) {
        return false;
    }
    strncpy(taskName, (*t)->taskName, MAXNAME);
    return true;
}

bool GetTaskStatus(TASK* t, char* status) {
    if (t == NULL) {
        return false;
    }
    strncpy(status, (*t)->status, MAXNAME);
    return true;
}

void DestroyTask(TASK* t) {
    if (t != NULL) {
        free(*t);
    }
}



