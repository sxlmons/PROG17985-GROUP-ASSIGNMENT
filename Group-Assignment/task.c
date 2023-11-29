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

bool SetTaskNum(TASK* t, int taskNum) 
{
	if (t == NULL)
		return false;

	t->taskNum = taskNum;
		return true;
}

bool CopyTask(TASK* dest, const TASK* src) 
{
	if (dest == NULL || src == NULL)
		return false;
	dest->taskNum = src->taskNum;
	strncpy(dest->taskName, src->taskName, MAX_NAME);
		return true;
}



void SetTaskName(TASK* t, char* taskName) {
	if (t != NULL) 
	{
		strncpy(t->taskName, taskName, MAX_NAME);
	}
}

bool GetTaskNum(TASK* t, int* taskNum) {
	if (t == NULL || taskNum == NULL) 
		return false;
	*taskNum = t->taskNum; 
		return true;
}

bool GetTaskName(TASK* t, char* taskName) {
	if (t == NULL || taskName == NULL) 
		return false;
	strncpy(taskName, t->taskName, MAX_NAME); 
		return true;
}

void DestroyTask(TASK* t) {

}