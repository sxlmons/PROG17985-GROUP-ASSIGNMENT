/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - Main.c
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*/

#include <stdio.h>
#include <stdlib.h>
#include "tasklist.h"

int main(void) {
	TASKLIST* tasks = CreateTaskList();
	TASK t1 = { 1, "Task 1", "Status 1" };
	TASK t21 = { 21, "Task 21", "Status 21" };
	TASK t24 = { 24, "Task 24", "Status 24" };
	AddTaskToList(tasks, t1);
	AddTaskToList(tasks, t21);
	AddTaskToList(tasks, t24);

	TASK* t = GetTaskByName(tasks, "TAsSK 21");
	if (t != NULL) {
		printf("%d %s %s\n", t->taskNum, t->taskName, t->taskStatus);
	}

	DestroyTaskList(tasks);
	return 0;
}