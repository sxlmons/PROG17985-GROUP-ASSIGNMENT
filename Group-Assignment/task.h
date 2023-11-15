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

// task interface
typedef struct task { 
	int taskNum;
	char taskName[MAX_NAME];
	char taskStatus[MAX_NAME];
	struct task* next;
}TASK;

TASK CreateTask(int taskNum, char* taskName, char* taskStatus);

bool SetTaskNum(TASK t, int taskNum);

bool CopyTask(TASK* dest, const TASK src);

void SetTaskName(TASK t, char* taskName);

bool GetTaskNum(TASK t, int* taskNum);

bool GetTaskName(TASK t, char* taskName);

void DestroyName(TASK t);




