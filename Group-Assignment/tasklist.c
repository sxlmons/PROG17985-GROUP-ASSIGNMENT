#define _CRT_SECURE_NO_WARNINGS
#include "tasklist.h"
#include <stdlib.h>
#include <string.h>

// Method that mallocs a new list and sets the default values 
TASKLIST* CreateTaskList() {
	TASKLIST* taskList = malloc(sizeof(TASKLIST));
	if (taskList == NULL) {
		return NULL;
	}

	taskList->first = NULL;
	taskList->last = NULL;
	taskList->count = 0;
	return taskList;
}

// Method that returns the amount of elements a task list has
int GetTaskListCount(TASKLIST* taskList) {
	return taskList->count;
}

TASK* GetTaskByNumber(TASKLIST* taskList, int taskNum) {
	if (taskList == NULL) {
		return NULL;
	}

	bool found = false;
	TASK* current = taskList->first;
	TASK* prev = current;
	while (!found && current != NULL) {
		prev = current;
		if (current->taskNum == taskNum) {
			found = true;
		}
		current = current->next;
	}

	if (!found) {
		return NULL;
	}

	return prev;
}

TASK* GetTaskByName(TASKLIST* taskList, char* taskName) {
	if (taskList == NULL) {
		return NULL;
	}

	bool found = false;
	TASK* current = taskList->first;
	TASK* prev = current;
	while (!found && current != NULL) {
		prev = current;
		if (_stricmp(taskName, current->taskName) == 0) {
			found = true;
		}
		current = current->next;
	}

	if (!found) {
		return NULL;
	}

	return prev;
}

// Method that adds a task to the task list
bool AddTaskToList(TASKLIST* taskList, TASK task) {
	if (taskList == NULL) {
		return false;
	}

	TASK* newTask = malloc(sizeof(TASK));
	if (newTask == NULL) {
		return false;
	}

	newTask->taskNum = task.taskNum;
	strncpy(newTask->taskName, task.taskName, MAX_NAME);
	strncpy(newTask->taskStatus, task.taskStatus, MAX_NAME);
	newTask->next = NULL;

	// This code will only run if there are 0 elements in the list
	if (GetTaskListCount(taskList) <= 0) {
		taskList->first = newTask;
		taskList->last = newTask;
		taskList->count++;
		return true;
	}

	// This code will only run if there is more than 1 element in the list
	taskList->last->next = newTask;
	taskList->last = newTask;
	taskList->count++;
	return true;
}

// Method that destroys all elements in a list and then the list itself at the end
void DestroyTaskList(TASKLIST* taskList) {
	TASK* current = taskList->first;
	while (current != NULL) {
		TASK* temp = current;
		current = current->next;
		free(temp);
	}
	
	free(taskList);
}
