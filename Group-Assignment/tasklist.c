#define _CRT_SECURE_NO_WARNINGS
#include "tasklist.h"
#include <stdio.h>
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

	TASK* current = taskList->first;
	while (current != NULL) {
		if (current->taskNum == taskNum) {
			return current;
		}
		current = current->next;
	}

	return NULL;
}

TASK* GetTaskByName(TASKLIST* taskList, char* taskName) {
	if (taskList == NULL) 
	{
		return NULL;
	}

	TASK* current = taskList->first;
	while (current != NULL) {
		if (_stricmp(taskName, current->taskName) == 0) 
		{
			return current;
		}
		current = current->next;
	}

	return NULL;
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

	CopyTask(newTask, task);
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

bool RemoveTaskFromList(TASKLIST* taskList, int taskNum) {
	if (taskList == NULL) 
	{
		return false;
	}

	TASK* current = taskList->first;
	TASK* prev = NULL;
	while (current != NULL) {
		if (current->taskNum == taskNum) {
			if (prev != NULL) {
				prev->next = current->next;
			}

			if (taskList->first == current) {
				taskList->first = current->next;
			}

			if (taskList->last == current) {
				taskList->last = prev;
			}

			free(current);
			return true;
		}
		prev = current;
		current = current->next;
	}

	return false;
}

bool SaveTaskList(TASKLIST* taskList) {
	if (taskList == NULL) {
		return false;
	}

	FILE* fp = fopen("tasks.txt", "w");
	if (fp == NULL) {
		return false;
	}

	fprintf(fp, "%d\n", GetTaskListCount(taskList));

	TASK* current = taskList->first;
	while (current != NULL) {
		fprintf(fp, "%d\n", GetTaskNum(*current));
		fprintf(fp, "%s", current->taskName);
		fprintf(fp, "%d\n", current->taskStatus);
		current = current->next;
	}

	fclose(fp);

	return true;
}

bool LoadTaskList(TASKLIST* taskList) {
	if (taskList == NULL) {
		return false;
	}

	FILE* fp = fopen("tasks.txt", "r");
	if (fp == NULL) {
		return false;
	}

	int taskCount;
	fscanf(fp, "%d\n", &taskCount);

	for (int i = 0; i < taskCount; i++) {
		int taskNumber;
		char taskName[MAX_NAME];
		int taskStatus;

		fscanf(fp, "%d\n", &taskNumber);
		fscanf(fp, "%[^\n]s\n", taskName);
		fscanf(fp, "%d\n", &taskStatus);
	}

	fclose(fp);
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
