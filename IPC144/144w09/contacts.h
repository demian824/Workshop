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

#ifndef CONTACT
#define CONTACT

#include <stdio.h>
#define NUMBER  0
#define STRING  1
#define NEW     2
#define UPDATE  3
//--------------------------------
// Structure Types
//--------------------------------
// Structure type Name declaration (Milestone 1)
struct Name
{
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};
// Structure type Address declaration (Milestone 1)
struct Address
{
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};
// Structure type Numbers declaration (Milestone 1)
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};
// Structure type Contact declaration (Milestone 3)
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//--------------------------------
// Function Prototypes
//--------------------------------

// Get and store from standard input the values for Name
void getName(struct Name* name, int flag);
// Get and store from standard input the values for Address
void getAddress(struct Address* address, int flag);
// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers, int flag);

// +-------------------------------------------------+
// |    ====== Assignment 2 | Milestone 2 =======    |
// |                                                 |
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function prototypes here...              |
// +-------------------------------------------------+

void getContact(struct Contact* contact);
void getString(char* string, int size, int flag);
void printQuest(const char string[]);
void yesNoQuest(const char string[]);

#endif // !CONTACT