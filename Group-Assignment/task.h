/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - task.h
*
*  Contributors:
*  - JOSHUA S
*  - HARRIS I
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*/

#pragma once

#include <stdbool.h>
#include <stdio.h>

//preprocessor directives
#define MAX_NAME	100

typedef enum taskStatus {
	COMPLETE = 0,
	INCOMPLETE = 1,
} TASK_STATUS;

// task interface
typedef struct task { 
	int taskNum;
	char taskName[MAX_NAME];
	TASK_STATUS taskStatus;
	struct task* next;
}TASK;

TASK CreateTask(int taskNum, char* taskName);

bool SetTaskNum(TASK* t, int taskNum);

bool CopyTask(TASK* dest, TASK src);

void SetTaskName(TASK* t, char* taskName);

int GetTaskNum(TASK t);

bool GetTaskName(TASK* t, char* taskName);

void DestroyTask(TASK* t);




