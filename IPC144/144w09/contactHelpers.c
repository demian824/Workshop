//==============================================
// Name:           Wonchul Choi
// Student Number: 118362201
// Email:          wchoi28@myseneca.ca
// Section:        IPC144 NHH
// Date:           July.26.2020
//==============================================
// Assignment:     2
// Milestone:      3, 4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"


#define MAXCONTACTS 5
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
//========================================================================================
// CLEAR BUFFER FUNCTION
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
	printf("\n");
}
//========================================================================================
// INPUT FUNCTIONS
// getInt: Empty function definition goes here:
int getInt(void)
{
	int inputNum;		// input number
	int temp_flag = 0;  // while loop condition

	// While Condition : if user inputs numbers, while loop is stop.
	// scanf() will be return the number of input data, if it is successful. 
 	while ((temp_flag = scanf("%d", &inputNum)) != 1)
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
	}
	clearKeyboard();
	return inputNum;
}
// getIntInRange: Empty function definition goes here:
int getIntInRange(const int min, const int max)
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
	char input_arr[10];
	int answer_flag = -1;
	int keepgoing = 1;

	while (keepgoing)
	{
		getString(input_arr, 10, STRING);
		
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
//========================================================================================
// SELECTION FUNCTIONS
// menu: Empty function definition goes here:
int selectionList(void)
{
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

	return getIntInRange(0, 6);
}
// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int selectNum = 0,	// Selection 
	           answer_flag  = -1,	// EXIT flag
	       keepgoing = 1;	// while loop flag
	struct Contact memberList[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
											     { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
												 { "4161112222", "4162223333", "4163334444" } },
											   { { "Maggie", "R.", "Greene" },
												 { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
												 { "9051112222", "9052223333", "9053334444" } },
											   { { "Morgan", "A.", "Jones" },
												 { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
												 { "7051112222", "7052223333", "7053334444" } },
											   { { "Sasha", {'\0'}, "Williams" },
												 { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
												 { "9052223333", "9052223333", "9054445555" } }, };
	while (keepgoing)
	{
		// Call the menu
		selectNum = selectionList();
		// Function task follow by selected number
		switch (selectNum)
		{
		case 1:
			displayContacts(memberList, MAXCONTACTS);
			break;
		case 2:
			addContact(memberList, MAXCONTACTS);
			break;
		case 3:
			updateContact(memberList, MAXCONTACTS);
			break;
		case 4:
			deleteContact(memberList, MAXCONTACTS);
			break;
		case 5:
			searchContacts(memberList, MAXCONTACTS);
			break;
		case 6:
			sortContacts(memberList, MAXCONTACTS);
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			answer_flag = yes();	
		}
		// EXIT option
		if (answer_flag > 0)
		{
			printf("\nContact Management System: terminated\n");
			keepgoing = 0;
		}
		else if (answer_flag < 0)
		{
			printf("\n");
			pause();
		}
		else 
		{
			printf("\n");
			answer_flag = -1;
		}
	}
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 - 4=======    |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+
//========================================================================================
//DISPLAY FUNCTIONS
// displayContactHeader
void displayContactHeader(void)
{
	puts("\n+-----------------------------------------------------------------------------+");
	puts("|                              Contacts Listing                               |");
	puts("+-----------------------------------------------------------------------------+");
}
// displayContactFooter
void displayContactFooter(const int count)
{
	puts("+-----------------------------------------------------------------------------+");
	printf("Total contacts: %d\n", count); // total number
}
// displayContact:
void displayContact(const struct Contact* contact)
{
	// Without middle name
	if (contact->name.middleInitial[0] == '\0')
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	// With middle name
	else
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	// Without #apt
	if (contact->address.apartmentNumber == '\0')
		printf(" %8d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
	// With #apt
	else
		printf(" %8d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	
}
// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int i, count = 0;
	displayContactHeader();

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].name.firstName) != 0)
		{
			displayContact(&contacts[i]);
			count++; // counting data numbers.
		}
	}
	displayContactFooter(count);
}

//========================================================================================
// INPUT | FIND | SEARCH
// get 10 digit numbers
void getTenDigitPhone(char phoneNum[])
{
	int i,				// index
		keepgoing = 1,	// check up flag 1 is true, 0 is false
		needInput = 1;	// while-loop flag

	printf("\nEnter the cell number for the contact: ");
	while (needInput == 1)
	{
		scanf("%10s", phoneNum);
		clearKeyboard();

		// check the length of string and number character
		if (strlen(phoneNum) == 10)
		{
			for (i = 0; i < 10; i++)
				if (phoneNum[i] < 48 || phoneNum[i] > 57)
					keepgoing = 0;
			// every input is number characters
			if (keepgoing)
				needInput = 0;
		}
		// every input is not number characters
		else
			printf("Enter a 10-digit phone number: ");	
	}
}
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i,				// index
		reValue = -1;	// return value
	// compare the number with numbers in the structure
	for (i = 0; i < size; i++)
		if (strcmp(cellNum, contacts[i].numbers.cell) == 0)
			reValue = i;
	// return index number
	return reValue;
}
// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	int indexNum = -1;
	char findNum[11] = { 0 };
	// get 10 digit numbers
	getTenDigitPhone(findNum);
	// find index number which has same 10 digit numbers
	indexNum = findContactIndex(contacts, size, findNum);
	
	// No match
	if (indexNum < 0)
		puts("*** Contact NOT FOUND ***");
	// match
	else
	{
		puts("");
		displayContact(&contacts[indexNum]);
	}
}

//========================================================================================
// ADD | EDIT | DELETE
// addContact:
void addContact(struct Contact contacts[], int size)
{
	int i,			// index 
		inNum = -1;	// index number

	// search empty memory in the array
	for (i = 0; i < size; i++)
		if (strlen(contacts[i].name.firstName) == 0)
			inNum = i;
	// Memory is full
	if (inNum < 0)
		puts("\n*** ERROR: The contact list is full! ***");
	// Memory is not full
	else
	{
		printf("\n");
		getContact(&contacts[inNum]);
		puts("--- New contact added! ---");
	}
}
// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	int indexNum = -1;			// index number
	char findNum[11] = { 0 };	// 10 digit numbers

	getTenDigitPhone(findNum);	// get 10 digit numbers for searching
	indexNum = findContactIndex(contacts, size, findNum);// get index number 

	// No match
	if (indexNum < 0)
		printf("*** Contact NOT FOUND ***\n");
	// Match
	else
	{
		// Display the data 
		puts("\nContact found:");
		displayContact(&contacts[indexNum]);
		// adding Name
		printf("\nDo you want to update the name? (y or n): ");
		if (yes() == 1)
			getName(&contacts[indexNum].name, UPDATE);
		// adding address
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
			getAddress(&contacts[indexNum].address, UPDATE);
		// adding numbers
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
			getNumbers(&contacts[indexNum].numbers, UPDATE);
				
		puts("--- Contact Updated! ---");
	}
}
// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	int indexNum = -1;
	char findNum[11] = { 0 };
	
	getTenDigitPhone(findNum);	// get 10 digit numbers for searching
	indexNum = findContactIndex(contacts, size, findNum);// get index number 
	puts("");
	// No match
	if (indexNum < 0)
		puts("*** Contact NOT FOUND ***");
	// Match
	else
	{
		puts("Contact found:");
		displayContact(&contacts[indexNum]);

		printf("\nCONFIRM: Delete this contact? (y or n): ");

		if (yes() == 1)
		{
			memset(&contacts[indexNum], 0, sizeof(struct Contact));
			puts("--- Contact deleted! ---");
		}
	}

}

//========================================================================================
//Sorting
void sortContacts(struct Contact contacts[], int size)
{
	struct Contact tempArr[MAXCONTACTS] = { { { {0,} } } };
	int i, j;
	
	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
			//bubble sort
			if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0)
			{
				//if str1 is bigger than str2, switch the values between str1 and str2
				tempArr[i] = contacts[i];
				contacts[i] = contacts[j];
				contacts[j] = tempArr[i];
			}
	puts("\n--- Contacts sorted! ---");
}
