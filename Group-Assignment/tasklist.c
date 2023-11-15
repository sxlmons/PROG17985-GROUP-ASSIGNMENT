#include "tasklist.h"
#include <stdlib.h>

// Method that mallocs a new list and sets the default values 
TaskList* CreateTaskList() {
	TaskList* taskList = malloc(sizeof(TaskList));
	if (taskList == NULL) {
		return NULL;
	}

	taskList->first = NULL;
	taskList->last = NULL;
	taskList->count = 0;
	return taskList;
}

// Method that returns the amount of elements a task list has
int GetTaskListCount(TaskList* list) {
	return list->count;
}

// Method that adds a task to the task list
bool AddTaskToList(TaskList* list, TASK task) {
	if (list == NULL) {
		return false;
	}

	TASK* newTask = malloc(sizeof(TASK));
	if (newTask == NULL) {
		return false;
	}

	CopyTask(newTask, task);

	// This code will only run if there are 0 elements in the list
	if (GetTaskListCount(list) <= 0) {
		list->first = newTask;
		list->last = newTask;
		list->count++;
		return true;
	}

	// This code will only run if there is more than 1 element in the list
	list->last->next = newTask;
	list->last = newTask;
	list->count++;
	return true;
}

// Method that destroys all elements in a list and then the list itself at the end
bool DestroyTaskList(TaskList* list) {
	if (list == NULL) {
		return false;
	}

	TASK* current = list->first;
	while (current != NULL) {
		TASK* temp = current;
		current = current->next;
		free(temp);
	}
	
	free(list);
	return true;
}
