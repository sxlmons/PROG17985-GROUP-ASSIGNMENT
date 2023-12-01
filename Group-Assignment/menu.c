/*
*  PROG71985 - F23 - Nov 2023 - Joshua Salmons, Harris Ibrahimi, Chris Hunt
*
*  Assignment Group - Menu.c
*
*  Contributors:
*  - JOSHUA S
*
*  Revision History
*
*      1.0      2023-Nov-28          initial
*/

#include "menu.h"
#include <stdio.h>

void taskMenu() {
	printf("**Task Tracker 2000**\n\n");
	printf(" 1) Add task\n");
	printf(" 2) Display task\n");
	printf(" 3) Edit Task\n");
	printf(" 4) Search for task\n");
	printf(" 5) Clear Tasks\n");
	printf(" 10) exit program\n");			//will change num later to fit in
	printf("\n Selection: ");
}

void menu2() {
	printf("\nHow would you like to search?\n");
	printf("1) by name\n");
	printf("2) by number\n");
	printf("0) to return to main menu\n"); 
}

void editTaskMenu() {
	printf("\nEdit Tasks:\n");
	printf("1) Complete a Task\n");
	printf("2) Rename a Task\n");
	printf("3) Delete a Task\n");
}