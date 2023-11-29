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
#include "menu.h"

int main(void) {
	TASKLIST* tasks = CreateTaskList();
	if (tasks == NULL) 
	{
		fprintf(stderr, "Not enough memory to store tasks\n");
		exit(EXIT_FAILURE);
	}

	// if you want i can change this so that it's all in functions I will probabley just move it into a new file to make it look nice
	int choice, choice2, choice3, TaskNum;
	char name[MAX_NAME], status[MAX_NAME];
	 
	do { 

		taskMenu(); 
		scanf_s(" %d", &choice); 
		getchar();    

		switch (choice) {
		case 1:
			printf("please input the task number you want to make: \n");
			scanf_s(" %d", &TaskNum);
			getchar();

			printf("Please input the name of the task: \n");
			fgets(name, MAX_NAME, stdin);

			printf("Please input the the status of the task: \n");
			fgets(status, MAX_NAME, stdin);

			TASK NewTask = { TaskNum, name, status }; 

			AddTaskToList(tasks, NewTask);
			break;
		case 2:
			// Display task
			break;
		case 3:
			printf("Input the number for the task you wish to remove: \n");
			scanf_s(" %d", &choice2);
			RemoveTaskFromList(tasks, &choice2);
			break;
		case 4:
			printf("How would you like to search?\n");
			printf("1) by name\n");
			printf("2) by number\n");
			printf("0) to return to main menu\n");
			printf("Selection: ");

			scanf_s("%d", &choice3);
			getchar();

			if (choice3 == 1)
			{
				printf("please insert the name of the task: ");
				fgets(name, MAX_NAME, stdin);
				printf(GetTaskByName(tasks, name));
			}
			else if (choice3 == 2)
			{
				printf("Please enter the num corresponding to the task: ");
				scanf_s(" %d", &choice3);
				GetTaskByNumber(tasks, choice3);
			}
			else if (choice3 == 0)
			{
				printf("returning to main menu");
			}
			else
				printf("invalid input, returning to main menu");

			break;

		case 5:
			printf("are you sure you wish to delete the list Y/N: ");
			fgets(name, MAX_NAME, stdin);
			if (name == "Y" || name == "y") {
				DestroyTaskList(tasks);
			}
			else
			{
				printf("Returning to main menu");
			}
			break;

		case 10:
			break;

		default:
			printf("Invalid input, re-enter the number");
			break;
		}
	} while (true);

	DestroyTaskList(tasks);

	return 0;
}