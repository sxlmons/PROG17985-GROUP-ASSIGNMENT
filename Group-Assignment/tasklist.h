#pragma once
#include "task.h"

// Basic linked list struct that contains all the basic data of the list
typedef struct taskList {
	TASK* first;
	TASK* last;
	int count;
} TASKLIST;

TASKLIST* CreateTaskList();

int GetTaskListCount(TASKLIST* taskList);
TASK* GetTaskByNumber(TASKLIST* taskList, int taskNum);
TASK* GetTaskByName(TASKLIST* taskList, char* taskName);

bool AddTaskToList(TASKLIST* taskList, TASK task);
bool RemoveTaskFromList(TASKLIST* taskList, int taskNum);

void DestroyTaskList(TASKLIST* taskList);