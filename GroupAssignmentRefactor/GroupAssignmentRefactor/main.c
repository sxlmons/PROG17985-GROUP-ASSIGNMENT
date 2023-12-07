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
    loadTasks();  

    int choice;

    while (1) 
    {
        taskMenu(); 

        getInputNum("Selection: ", "%d", &choice);  

        switch (choice) 
        {
        case 1:
            addTask();
            break;
        case 2:
            deleteTask();             
            break;
        case 3:
            updateTask();
            break;
        case 4:
            displaySingleTask(); 
            break;
        case 5:
            displayRangeTask(); 
            break;
        case 6:
            displayAllTasks();    
            break;
        case 7:
            searchForTask();
            break;
        case 8:
            displayTasksSorted();
            break;
        case 9:
            // Save tasks to file upon exiting
            saveTasks();
            exit(EXIT_SUCCESS); 
        default:
            printf("\nMust be a Numerical Value. 1 - 9.\n");
        }
    }
    return 0;
}