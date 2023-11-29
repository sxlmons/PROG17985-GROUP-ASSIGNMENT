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
	printf(" 3) Delete task\n");
	printf(" 4) Search for task\n");
	printf(" 5) Delete list\n");
	printf(" 10) exit program\n");			//will change num later to fit in
	printf("\n Selection: ");
}

void menu2() {
	printf("How would you like to search?\n");
	printf("1) by name");
	printf("2) by number");
	printf("0) to return to main menu"); 
}