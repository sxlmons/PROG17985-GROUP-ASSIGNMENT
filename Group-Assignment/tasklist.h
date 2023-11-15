#pragma once
#include "task.h"

// Basic linked list struct that contains all the basic data of the list
typedef struct {
	TASK* first;
	TASK* last;
	int count;
} TaskList;

TaskList* CreateTaskList();
int GetTaskListCount(TaskList* list);
bool AddTaskToList(TaskList* list, TASK task);
bool DestroyTaskList(TaskList* list);