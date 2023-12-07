/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - data.c
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*      1.1      2023-Dec-04          Refactored
*
*/

#include "data.h"
#include "task.h"

void saveTasks(TASK_LIST* list)
{
    // open the file
    FILE* file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }

    int count = 0;

    // count the tasks
    TASK temp = list->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // write to file
    fprintf(file, "%d\n", count);

    temp = list->head;
    while (temp != NULL) {
        fprintf(file, "%d\n", temp->taskNum);
        fprintf(file, "%s\n", temp->taskName);
        fprintf(file, "%s\n", temp->status);
        temp = temp->next;
    }

    // close the file
    fclose(file);
    printf("Tasks saved successfully!\n");
}

void loadTasks(TASK_LIST* list)
{
    // open the file
    FILE* file = fopen("tasks.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open file for reading.\n");
        return;
    }

    // count the tasks
    int count;
    if (fscanf(file, "%d\n", &count) == EOF) 
    {
        printf("Failed to read task count from file.\n"); 
        return;
    }

    int taskNum;
    char taskName[MAXNAME];
    char status[MAXSTATUS];

    for (int i = 0; i < count; i++)
    {
        // read tasks
        if (fscanf(file, "%d\n", &taskNum) == EOF) 
        {
            printf("Failed to read task number from file.\n"); 
            return;
        }
        fgets(taskName, MAXNAME, file);
        fgets(status, MAXSTATUS, file);

        // Removing trailing new lines that the strings get from fgets    
        // strtok’s return value is stored in result. If result is not NULL,
        // it’s copied back into taskName or status
        char* result;

        result = strtok(taskName, "\n"); 
        if (result != NULL) { 
            strcpy(taskName, result); 
        }

        result = strtok(status, "\n"); 
        if (result != NULL) { 
            strcpy(status, result);
        }

        // create and add tasks
        TASK new_task = CreateTask(taskNum, taskName, status);
        if (new_task == NULL)
        {
            printf("Failed to create new task.\n");
            return;
        }

        if (list->head == NULL)
        {
            list->head = new_task;
        }
        else
        {
            TASK temp = list->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_task;
            new_task->prev = temp;
        }
    }

    // close the file
    fclose(file);
    printf("Tasks loaded successfully!\n");
}

