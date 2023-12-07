/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - task.h
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*      1.1      2023-Dec-04          Refactored
*
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXNAME     51
#define MAXSTATUS      21

typedef struct task {
    int taskNum;
    char taskName[MAXNAME];
    char status[MAXSTATUS];
    struct task* next;
    struct task* prev;
} *TASK;

// initailly we had a globally scoped variable here but replaced it with TASK_LIST
typedef struct task_list {
    TASK head;
} TASK_LIST;

TASK_LIST* CreateTaskList();

void DestroyTaskList(TASK_LIST* list);

TASK CreateTask(int taskNum, char* taskName, char* status);

bool CopyTask(TASK* dest, const TASK* src); 

bool SetTaskNum(TASK* t, int taskNum);   

void SetTaskName(TASK* t, char* taskName);

void SetTaskStatus(TASK* t, char* status);

bool GetTaskNum(TASK* t, int* taskNum);

bool GetTaskName(TASK* t, char* taskName);

bool GetTaskStatus(TASK* t, char* status);

void DestroyTask(TASK* t);
