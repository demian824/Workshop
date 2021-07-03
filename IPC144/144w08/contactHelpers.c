//==============================================
// Name:           Wonchul Choi
// Student Number: 118362201
// Email:          wchoi28@myseneca.ca
// Section:        IPC144 NHH
// Date:           July.17.2020
//==============================================
// Assignment:     2
// Milestone:      1, 2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 1 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
	int inputNum;
	int temp_flag = 0;

	// While Condition : if user inputs numbers, while loop is stop.
	// scanf() will be return the number of input data, if it is successful. 
	while ((temp_flag = scanf("%d", &inputNum)) != 1)
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
	}
	return inputNum;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int inputNum;
	int temp_flag = 0;
	int keepgoing = 1;

	while (keepgoing)
	{
		temp_flag = scanf("%d", &inputNum);
		clearKeyboard();

		//If user inputs the data which is not integer numbers
		if (temp_flag == 0)
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		//If user inputs integer number
		else
		{
			// If input number is feet on the range
			if (inputNum >= min && inputNum <= max)
				keepgoing = 0;
			// If input number is smaller or bigger than range
			else if (inputNum <= min || inputNum >= max)
				printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	}
	return inputNum;
}

// yes: Empty function definition goes here:
int yes(void)
{
	char input_arr[4];
	int answer_flag = -1;
	int keepgoing = 1;

	while (keepgoing)
	{
		scanf("%3[^\n]%*c", input_arr);
		
		if (strcmp(input_arr, "Y") == 0 || strcmp(input_arr, "y") == 0)
		{
			answer_flag = 1;
			keepgoing = 0;
		}
		else if (strcmp(input_arr, "N") == 0 || strcmp(input_arr, "n") == 0)
		{
			answer_flag = 0;
			keepgoing = 0;
		}
		else
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
	}

	return answer_flag;
}

// print Function message
void printFunc(int x)
{
	printf("\n<<< Feature %d is unavailable >>>\n", x);
	printf("\n");
}

// menu: Empty function definition goes here:
int menu(void)
{
	int inputNum = 0;
	int keepgoing = 1;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");

	while (keepgoing)
	{
		inputNum = getInt();
		clearKeyboard();
		//if input the right range of number
		if (inputNum >= 0 && inputNum < 7)
			keepgoing = 0;
		// if input numbers out of range
		else
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
	}
	return inputNum;
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int selectNum = 0;
	int keepgoing = 1;
	while (keepgoing)
	{
		// Call the menu
		selectNum = menu();
		// Function task follow by selected number
		if (selectNum == 1)
		{
			printFunc(selectNum);
			pause();
		}
		else if (selectNum == 2)
		{
			printFunc(selectNum);
			pause();
		}
		else if (selectNum == 3)
		{
			printFunc(selectNum);
			pause();
		}
		else if (selectNum == 4)
		{
			printFunc(selectNum);
			pause();
		}
		else if (selectNum == 5)
		{
			printFunc(selectNum);
			pause();
		}
		else if (selectNum == 6)
		{
			printFunc(selectNum);
			pause();
		}
		else if (selectNum == 0)
		{
			printf("\nExit the program? (Y)es/(N)o: ");
			if (yes() == 1)
			{
				printf("\nContact Management System: terminated\n");
				keepgoing = 0;
			}
		}
		
		if (keepgoing != 0)
			printf("\n");
	}
}