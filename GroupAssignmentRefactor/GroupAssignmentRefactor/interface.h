/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - interface.h
*
*  Revision History
*
*      1.0      2023-Nov-15          initial
*      1.1      2023-Dec-04          Refactored
*
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "task.h"

//these functions take no parameters, becasue its given by user

void taskMenu();

//void clear_buffer();

void getInputNum(char* prompt, char* format, void* value);

void getInputAlpha(char* prompt, char* format, void* value);

//void getInputAlpha(char* prompt, char* value, int size);	future implementation for reading spaces

void addTask();

void deleteTask();

void updateTask();

void displaySingleTask();

void displayRangeTask();

void displayAllTasks();

void displayTasksSorted();

void searchForTask();
