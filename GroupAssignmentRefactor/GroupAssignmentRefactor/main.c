/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - Main.c
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*      1.1      2023-Dec-04          Refactored
* 
*/

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "task.h"
#include "interface.h"
#include "data.h"


int main()
{
    // create the task list and laod the tasks
    TASK_LIST* list = CreateTaskList();
    loadTasks(list);

    int choice = 0;

    while (choice != 9)
    {
        taskMenu();

        getInputNum("Selection: ", "%d", &choice);

        switch (choice)
        {
        case 1:
            addTask(list);
            break;
        case 2:
            deleteTask(list);
            break;
        case 3:
            updateTask(list);
            break;
        case 4:
            displaySingleTask(list);
            break;
        case 5:
            displayRangeTask(list);
            break;
        case 6:
            displayAllTasks(list);
            break;
        case 7:
            searchForTask(list);
            break;
        case 8:
            displayTasksSorted(list);
            break;
        case 9:
            // Save tasks to file upon exiting
            saveTasks(list);
            break;
        default:
            printf("\nMust be a Numerical Value. 1 - 9.\n");
        }
    }
    // free memory from the list
    DestroyTaskList(list);
    return 0;
}

