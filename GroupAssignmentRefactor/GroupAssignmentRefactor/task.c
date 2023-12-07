/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - tasks.c
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*      1.1      2023-Dec-04          Refactored
*
*/

#include "task.h"

TASK_LIST* CreateTaskList() 
{
    // Allocate memory for the new task list.
    TASK_LIST* new_list = (TASK_LIST*)malloc(sizeof(TASK_LIST));
    if (new_list == NULL) 
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    // Initialize the head of the list to NULL.
    new_list->head = NULL;
    return new_list;
}

void DestroyTaskList(TASK_LIST* list) 
{
    if (list != NULL) 
    {
        TASK temp = list->head;
        // Initialize a temporary pointer to the head of the list.
        while (temp != NULL) 
        {
            // Store the next task in a temporary pointer.
            TASK next = temp->next;
            // Free the memory allocated for the current task.
            DestroyTask(temp);
            temp = next;
        }
        // Free the memory allocated for the list.
        free(list);
    }
}

TASK CreateTask(int taskNum, char* taskName, char* status) 
{
    TASK new_task = (TASK)malloc(sizeof(struct task));
    if (new_task == NULL) 
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    // Set the task number of the new task.
    new_task->taskNum = taskNum;

    // Copy the task name into the new task's taskName field.
    strncpy(new_task->taskName, taskName, MAXNAME);

    // Copy the status into the new task's status field.
    strncpy(new_task->status, status, MAXSTATUS);

    // Initialize the next and previous pointers of the new task to NULL.
    new_task->next = NULL;
    new_task->prev = NULL;
    return new_task;
}

bool CopyTask(TASK dest, const TASK src) {
    if (dest == NULL || src == NULL) {
        return false;
    }
    // Copy the task number, task name, and status from the source task to the destination task.
    dest->taskNum = src->taskNum;
    strncpy(dest->taskName, src->taskName, MAXNAME);
    strncpy(dest->status, src->status, MAXSTATUS);
    return true;
}


bool SetTaskNum(TASK* t, int taskNum) {
    if (t == NULL) {
        return false;
    }
    (*t)->taskNum = taskNum;
    return true;
}

void SetTaskName(TASK* t, char* taskName) {
    if (t != NULL) {
        strncpy((*t)->taskName, taskName, MAXNAME);
    }
}

void SetTaskStatus(TASK* t, char* status) {
    if (t != NULL) {
        strncpy((*t)->status, status, MAXSTATUS);
    }
}

bool GetTaskNum(TASK* t, int* taskNum) {
    if (t == NULL) {
        return false;
    }
    *taskNum = (*t)->taskNum;
    return true;
}

bool GetTaskName(TASK* t, char* taskName) {
    if (t == NULL) {
        return false;
    }
    strncpy(taskName, (*t)->taskName, MAXNAME);
    return true;
}

bool GetTaskStatus(TASK* t, char* status) {
    if (t == NULL) {
        return false;
    }
    strncpy(status, (*t)->status, MAXNAME);
    return true;
}

void DestroyTask(TASK* t) {
    if (t != NULL) {
        free(t);
    }
}



