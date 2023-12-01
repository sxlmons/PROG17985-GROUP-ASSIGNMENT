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
#include <stdbool.h>
#include "tasklist.h"
#include "task.h"
#include "menu.h"

int main(void) {
	TASKLIST* tasks = CreateTaskList();
	if (tasks == NULL) 
	{
		fprintf(stderr, "Not enough memory to store tasks, download more memory\n");
		exit(EXIT_FAILURE);
	}

	// if you want i can change this so that it's all in functions I will probabley just move it into a new file to make it look nice
	int choice2, choice3, TaskNum, choice;
	char name[MAX_NAME], status[MAX_NAME]; 
	 
	bool exited = false;

	do { 

		taskMenu(); 
		scanf_s("%d", &choice); 
		(void)getchar();     

		switch (choice) 
		{
		//creating task
		case 1:
			printf("\nTask Number: ");
			scanf_s(" %d", &TaskNum);

			//eat newline
			(void)getchar();

			printf("\nTask Name: ");
			fgets(name, MAX_NAME, stdin);
			AddTaskToList(tasks, CreateTask(TaskNum, name));
			break;

		case 2:
			// Display task
			break;
		case 3:
			editTaskMenu();   
			scanf_s(" %d", &choice2);

			if (choice2 == 1) 
			{
				// 
			}
			else if (choice2 == 2)
			{
				//rename
			}
			else if (choice2 == 3)
			{
				int removeTag;
				printf("\nEnter the Task Number: ");
				scanf_s("%d", &removeTag);
				RemoveTaskFromList(tasks, removeTag);      
			}
			 

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
				scanf_s("%d", &choice3);
				TASK* foundTask = GetTaskByNumber(tasks, choice3);
				printf("Found Task!\n Task Number:%d\nTask Name: %s\nTask Status: %s\n", foundTask->taskNum,
				foundTask->taskName, foundTask->taskStatus == INCOMPLETE ? "Incomplete" : "Complete");
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
			exited = true;
			break;

		default:
			printf("Invalid input, re-enter the number");
			break;
		}
		
		/*int c;
		while ((c = getchar()) != '\n' && c != EOF);*/
	} while (choice != 10);  

	printf("Saving tasks...\n");
	if (!SaveTaskList(tasks)) {
		printf("dang you failed to save, sucks to be you");
	}

	DestroyTaskList(tasks);

	return 0;
}