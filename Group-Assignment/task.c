/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - task.c
* 
*  Contributors:
*  - JOSHUA S
*  - HARRIS I
* 
*  Revision History
*
*      1.0      2023-Nov-15          initial
*/

#define _CRT_SECURE_NO_WARNINGS

#include "task.h"
#include <stdio.h>
#include <string.h>

TASK CreateTask(int taskNum, char* taskName)
{
	TASK t = { 0 };		//if you wish to get rid of the reminder that struct is not initialized (set to known/default values)
	t.taskNum = taskNum;
	strncpy(t.taskName, taskName, MAX_NAME);     
	return t;
}  

bool SetTaskNum(TASK t, int taskNum) {

}

bool CopyTask(TASK* dest, const TASK src) {

}

void SetTaskName(TASK t, char* taskName) {

}

bool GetTaskNum(TASK t, int* taskNum) {

}

bool GetTaskName(TASK t, char* taskName) {

}

void DestroyName(TASK t) {

}