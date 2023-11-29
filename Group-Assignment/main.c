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
	if (tasks == NULL) {
		fprintf(stderr, "Not enough memory to store tasks\n");
		exit(EXIT_FAILURE);
	}

	TASK t1 = { 1, "Task 1", "Not Done" };
	TASK t2 = { 2, "Task 2", "Not Done" };
	TASK t3 = { 3, "Task 3", "Not Done" };

	AddTaskToList(tasks, t1);
	AddTaskToList(tasks, t2);
	AddTaskToList(tasks, t3);
	RemoveTaskFromList(tasks, 1);
	RemoveTaskFromList(tasks, 2);
	RemoveTaskFromList(tasks, 3);

	TASK* current = tasks->first;
	while (current != NULL) {
		printf("%d %s %s\n", current->taskNum, current->taskName, current->taskStatus);
		current = current->next;
	}

	// if you want i can change this so that it's all in functions I will probabley just move it into a new file to make it look nice
	int input, TaskNum;
	char name[MAX_NAME], status[MAX_NAME];
	while (true)
	{
		printf("Welcome to task tracker 2000\n");
		printf("These are the options you can choose from\n");
		printf("1) Add task\n");
		printf("2) Display task\n");
		printf("3) Delete task\n");
		printf("4) Search for task\n");
		printf("10) exit program\n");			//will change num later to fit in
		printf("Please use the number associated with your choice: \n");
		scanf_s(" %d", &input);
		if (input == 1)
		{
			printf("please input the task number you want to make: \n");
			scanf_s(" %d", &TaskNum);
			printf("Please input the name of the task: \n");
			fgets(name, MAX_NAME, stdin);
			printf("Please input the the status of the task: \n");
			fgets(status, MAX_NAME, stdin);
			TASK NewTask = {*&TaskNum, *name, *status};
			//AddTaskToList(tasks, NewTask);
		}if (input == 2)
		{
			//Display task
		}if (input == 3)
		{
			printf("Input the number for the task you wish to remove: \n");
			scanf_s(" %d", &input);
			RemoveTaskFromList(tasks, &input);
		}if (input == 4)
			printf("How would you like to search?\n");
			printf("1) by name");
			printf("2) by number");
			printf("0) to return to main menu");
			scanf_s(" %d", &input);
			if (input == 1)
			{
				printf("please insert the name of the task: ");
				fgets(name ,MAX_NAME, stdin);
				GetTaskByName(tasks, name);
			}if (input == 2)
			{
				printf("Please enter the num corresponding to the task: ");
				scanf_s(" %d", &input);
				GetTaskByNumber(tasks, input);
			}if (input == 0)
			{
				printf("returning to main menu");
			}
			else
				printf("invalid input, returning to main menu");
		{
		}if (input == 10)		//need to change later if delete is changed
		{
			break;
		}

		else
		{
			printf("Invalid input, re-enter the number");
		}
		
	}

	DestroyTaskList(tasks);
	return 0;
}