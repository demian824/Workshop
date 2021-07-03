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
#include "contacts.h"

//--------------------------------
// Function Prototypes
//--------------------------------
// +-------------------------------------------------+
// |    ====== Assignment 2 | Milestone 2 =======    |
// |                                                 |
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function prototypes here...              |
// +-------------------------------------------------+
//========================================================================================
// Clear the standard input buffer
void clearKeyboard(void);
// pause:
void pause(void);
// getInt:
int getInt(void);
// getIntInRange:
int getIntInRange(const int min, const int max);
// yes:
int yes(void);
// menu:
int selectionList(void);
// contactManagerSystem:
void contactManagerSystem(void);
// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 - 4=======    |
// +-------------------------------------------------+
//========================================================================================
//DISPLAY FUNCTIONS
// displayContactHeader
void displayContactHeader(void);
// displayContactFooter
void displayContactFooter(const int count);
// displayContact:
void displayContact(const struct Contact* contact);
// displayContacts:
void displayContacts(const struct Contact contacts[], int size);
//========================================================================================
// SEARCH FUNCTIONS
// get 10 digit numbers
void getTenDigitPhone(char phoneNum[]);
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);
// searchContacts:
void searchContacts(const struct Contact contacts[], int size);
//========================================================================================
// EDITING FUNCTIONS
// addContact:
void addContact(struct Contact contacts[], int size);
// updateContact:
void updateContact(struct Contact contacts[], int size);
// deleteContact:
void deleteContact(struct Contact contacts[], int size);
//========================================================================================
//Sorting
void sortContacts(struct Contact contacts[], int size);