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
#include "contacts.h"
#include "contactHelpers.h"
#define END_OF_INPUT '\n'

//print question:
void printQuest(const char string[])
{
    printf("Please enter the contact's %s: ", string);
}
//print Yes or No question
void yesNoQuest(const char string[])
{
    printf("Do you want to enter %s? (y or n): ", string);
}
//========================================================================================
// Edited - adding a parameter flag to input data
// NUMBER = 0 | STRING = 1 | NEW = 2 | UPDATE = 3 
// getName:
void getName(struct Name* name, int flag)
{
    char yesNo;

    printQuest("first name");
    getString(name->firstName, 31, STRING);

    yesNoQuest("a middle initial(s)");
    yesNo = yes();

    if (yesNo == 1)
    {
        printQuest("middle initial(s)");
        getString(name->middleInitial, 7, STRING);
    }
    else
        if (flag == UPDATE)
            memset(&name->middleInitial, 0, sizeof(name->middleInitial));

    printQuest("last name");
    getString(name->lastName, 36, STRING);
}
// getAddress:
void getAddress(struct Address* address, int flag)
{
    char yesNo;
    int keepgoing = 1;

    printQuest("street number");
    while (keepgoing)
    {
        address->streetNumber = getInt();
	
        if (address->streetNumber > 0)
            keepgoing = 0;
        else if (address->streetNumber <= 0)
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        else
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    }
    keepgoing = 1;
    printQuest("street name");
    getString(address->street, 41, STRING);

    yesNoQuest("an apartment number");
    yesNo = yes();

    if (yesNo == 1)
    {
        printQuest("apartment number");
        while (keepgoing)
        {
            address->apartmentNumber = getInt();

            if (address->apartmentNumber > 0)
                keepgoing = 0;
            else if (address->apartmentNumber <= 0)
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            else
                printf("*** INVALID INTEGER *** <Please enter an integer>: ");

        }
    }
    else
        if (flag == UPDATE)
            memset(&address->apartmentNumber, 0, sizeof(address->apartmentNumber));

    printQuest("postal code");
     scanf("%7[^\n]", (*address).postalCode);
    clearKeyboard();
    
       printQuest("city");
    getString(address->city, 41, STRING);
}
// getNumbers:
void getNumbers(struct Numbers* numbers, int flag)
{
    char yesNo;
    printQuest("cell phone number");
    getString(numbers->cell, 11, NUMBER);

    yesNoQuest("a home phone number");
    yesNo = yes();

    if (yesNo == 1)
    {
        printQuest("home phone number");
        getString(numbers->home, 11, NUMBER);
    }
    else
        if (flag == UPDATE)
            memset(&numbers->home, 0, sizeof(numbers->home));

    yesNoQuest("a business phone number");
    yesNo = yes();

    if (yesNo == 1)
    {
        printQuest("business phone number");
        getString(numbers->business, 11, NUMBER);
    }
    else
        if (flag == UPDATE)
            memset(&numbers->business, 0, sizeof(numbers->business));
}
// getContact:
void getContact(struct Contact* contact)
{
    getName(&contact->name, NEW);
    getAddress(&contact->address, NEW);
    getNumbers(&contact->numbers, NEW);
}
//========================================================================================
// Edited - adding a parameter flag to input data
// NUMBER = 0 | STRING = 1
// getSting:
void getString(char* string, int size, int flag)
{
    int input_ch;
    int count = 0;

    while ((input_ch = getchar()) != END_OF_INPUT && count < size)
    {
        string[count++] = input_ch;
        // ONLY number character can be saved 
        if (flag == NUMBER)
            if (input_ch < 48 || input_ch > 57)
            {
                printf("Enter a 10-digit phone number: ");
                clearKeyboard();
                count = 0;
            }  
    }
    // last index is not null terminator
    if (count == size)
    {
        string[size] = '\0';
        clearKeyboard();
    }
    // last index is null terminator
    else if (count < size)
        string[count] = '\0';
}
