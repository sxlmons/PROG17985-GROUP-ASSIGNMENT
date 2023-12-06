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

void saveTasks() {
    FILE* file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }

    int count = 0;

    TASK temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    fprintf(file, "%d\n", count);

    temp = head;
    while (temp != NULL) {
        fprintf(file, "%d\n", temp->taskNum);
        fprintf(file, "%s\n", temp->taskName);
        fprintf(file, "%s\n", temp->status);
        temp = temp->next;
    }

    fclose(file);
    printf("Tasks saved successfully!\n");
}

void loadTasks() {
    const int TASKNAME_MAXCHARS = 49;
    const int TASKSTATUS_MAXCHARS = 19;

    FILE* file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Unable to open file for reading.\n");
        return;
    }

    int count;
    fscanf(file, "%d\n", &count);

    int taskNum;
    char taskName[MAXNAME];
    char status[MAXSTATUS];

    for (int i = 0; i < count; i++) {
        fscanf(file, "%d\n", &taskNum);
        fgets(taskName, TASKNAME_MAXCHARS, file);
        fgets(status, TASKSTATUS_MAXCHARS, file);

        // Removing trailing new lines that the strings get from fgets
        strtok(taskName, "\n");
        strtok(status, "\n");

        TASK new_task = CreateTask(taskNum, taskName, status);

        if (head == NULL) {
            head = new_task;
        }
        else {
            TASK temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_task;
            new_task->prev = temp;
        }
    }

    fclose(file);
    printf("Tasks loaded successfully!\n");
}
