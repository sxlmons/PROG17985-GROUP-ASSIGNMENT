/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - interface.c
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*      1.1      2023-Dec-04          Refactored
*
*/

#include "interface.h"
#include <stdbool.h>
#include "task.h"

void taskMenu() {
    printf("\n1. Add a new task\n"); 
    printf("2. Delete an existing task\n");
    printf("3. Update an existing task\n");
    printf("4. Display a single task\n");
    printf("5. Display a range of tasks\n");
    printf("6. Display all tasks\n");
    printf("7. Search for a task\n");
    printf("8. Sort tasks\n");
    printf("9. Exit\n");
}

// function for input validation loop
void getInputNum(char* prompt, char* format, void* value) 
{
    printf(prompt, "%d");
    while (scanf(format, value) != 1) 
    {
        printf("Invalid input. Please enter a valid value: ");
        while (getchar() != '\n');
    }
}

// function for input validation loop
void getInputAlpha(char* prompt, char* format, void* value)
{
	printf("%s", prompt);
	bool first = true;
	while (scanf(format, value) != 1)
	{
		if (!first) {
			printf("Invalid input. Please enter a valid value: ");
		}
		first = false;
		while (getchar() != '\n');
	}
}

void addTask()
{
    int taskNum;
    char taskName[MAXNAME];
    char status[MAXSTATUS];

    // gather input from user; task num, name, and status
    getInputNum("Enter task number: ", "%d", &taskNum);
	getInputAlpha("Enter task name (up to 50 characters): ", "%50[^\n]s", taskName);
	getInputAlpha("Enter task status (up to 20 characters): ", "%20[^\n]s", status);

    // create a new task with given values
    TASK new_task = CreateTask(taskNum, taskName, status);

    // if the head of the list is null assign
    if (head == NULL) 
    {
        head = new_task;
    }
    else 
    {
        // if it not null traverse to the end of the list
        TASK temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        // add the new task to the end of the list and update the previous pointer
        temp->next = new_task;
        new_task->prev = temp;
    }

    printf("Task added successfully!\n");
}

void deleteTask()
{
    int taskNum;

    //gather input from user; task number
    getInputNum("Enter the task number of the task to delete: ", "%d", &taskNum); 

    if (head == NULL) {
        printf("No tasks to delete.\n");
        return;
    }

    TASK temp = head;
    while (temp != NULL && temp->taskNum != taskNum) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found.\n");
    }
    else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        DestroyTask(&temp);
        printf("Task deleted successfully!\n");
    }
}

void updateTask()
{
    int taskNum;
    char taskName[MAXNAME];
    char status[MAXSTATUS];

    getInputNum("Enter the task number of the task to update: ", "%d", &taskNum);

    if (head == NULL) {
        printf("No tasks to update.\n");
        return;
    }

    TASK temp = head;
    while (temp != NULL && temp->taskNum != taskNum) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found.\n");
    }
    else {
        getInputAlpha("Enter new task name (up to 50 characters): ", "%50[^\n]s", taskName);
        taskName[MAXNAME - 1] = '\0';  // ensure null termination     

        getInputAlpha("Enter new task status (up to 20 characters): ", "%20[^\n]s", status);
        status[MAXSTATUS - 1] = '\0';  // ensure null termination 

        SetTaskName(&temp, taskName);
        SetTaskStatus(&temp, status);

        printf("Task updated successfully!\n"); 
    }
}

void displaySingleTask()
{
    int taskNum;
    getInputNum("Enter the task number of the task to display: ", "%d", &taskNum);

    if (head == NULL) {
        printf("No tasks to display.\n");
        return;
    }

    TASK temp = head;
    while (temp != NULL && temp->taskNum != taskNum) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found.\n");
    }
    else {
        printf("Task Number: %d\n", temp->taskNum);
        printf("Task Name: %s\n", temp->taskName);
        printf("Task Status: %s\n", temp->status);
    }
}

void displayRangeTask()
{
    int startTaskNum, endTaskNum;

    getInputNum("Enter the task number of the task to display: ", "%d", &startTaskNum);
    getInputNum("Enter the task number to end displaying at: ", "%d", &endTaskNum);

    if (head == NULL) {
        printf("No tasks to display.\n");
        return;
    }

    TASK temp = head;
    while (temp != NULL && temp->taskNum < startTaskNum) {
        temp = temp->next;
    }

    while (temp != NULL && temp->taskNum <= endTaskNum) {
        printf("Task Number: %d\n", temp->taskNum);
        printf("Task Name: %s\n", temp->taskName);
        printf("Task Status: %s\n", temp->status);
        temp = temp->next;
    }
}

void displayAllTasks() {
    if (head == NULL) {
        printf("No tasks to display.\n");
        return;
    }

    TASK temp = head;
    while (temp != NULL) {
        printf("Task Number: %d\n", temp->taskNum);
        printf("Task Name: %s\n", temp->taskName);
        printf("Task Status: %s\n\n", temp->status);
        temp = temp->next;
    }
}

void searchForTask() {
    int taskNum;
    getInputNum("Enter the task number of the task to search for: ", "%d", &taskNum);

    if (head == NULL) {
        printf("No tasks to search.\n");
        return;
    }

    TASK temp = head;
    while (temp != NULL && temp->taskNum != taskNum) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found.\n");
    }
    else {
        printf("Task Number: %d\n", temp->taskNum);
        printf("Task Name: %s\n", temp->taskName);
        printf("Task Status: %s\n", temp->status);
    }
}

void displayTasksSorted() {
    if (head == NULL) {
        printf("No tasks to display.\n");
        return;
    }

    // Prompt the user for the sort order
    char sortOrder;
    do {
        printf("Enter the sort order ('a' for ascending or 'd' for descending): ");
        scanf(" %c", &sortOrder);  // The space before %c skips any whitespace characters, including '\n'
        while (getchar() != '\n');  // This consumes the '\n' character left in the input buffer by scanf
        if (sortOrder != 'a' && sortOrder != 'd') 
        {
            printf("Invalid input. Please enter 'a' for ascending or 'd' for descending.\n");
        }
    } while (sortOrder != 'a' && sortOrder != 'd');

    bool ascending = sortOrder == 'a';

    // Create a copy of the linked list
    TASK copy = NULL, temp = head;
    while (temp != NULL) {
        TASK new_task = CreateTask(0, "", "");  // Create an empty task
        CopyTask(&new_task, &temp);  // Copy the task
        if (copy == NULL) {
            copy = new_task;
        }
        else {
            TASK copy_temp = copy;
            while (copy_temp->next != NULL) {
                copy_temp = copy_temp->next;
            }
            copy_temp->next = new_task;
            new_task->prev = copy_temp;
        }
        temp = temp->next;
    }

    // Sort the copied linked list
    TASK i, j;
    for (i = copy; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            bool condition = ascending ? i->taskNum > j->taskNum : i->taskNum < j->taskNum;
            if (condition) {
                // Swap tasks
                TASK tempTask = CreateTask(0, "", "");  // Create an empty task
                CopyTask(&tempTask, &i);  // Copy task i to tempTask
                CopyTask(&i, &j);  // Copy task j to i
                CopyTask(&j, &tempTask);  // Copy tempTask to j
                DestroyTask(&tempTask);  // Destroy tempTask
            }
        }
    }

    // Display the sorted tasks
    temp = copy;
    while (temp != NULL) {
        printf("Task Number: %d\n", temp->taskNum);
        printf("Task Name: %s\n", temp->taskName);
        printf("Task Status: %s\n", temp->status);
        printf("\n");
        temp = temp->next;
    }

    // Destroy the copied linked list
    temp = copy;
    while (temp != NULL) {
        TASK next = temp->next;
        DestroyTask(&temp);
        temp = next;
    }
}



