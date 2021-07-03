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
#include "contacts.h"
#include "contactHelpers.h"
#define STOP '\n'

// getName:
void getName(struct Name* name)
{
    char yesNo;

    printQuest("first name");
    getString(name->firstName, 31);

    yesNoQuest("a middle initial(s)");
    yesNo = yes();

    if (yesNo == 1)
    {
        printQuest("middle initial(s)");
        getString(name->middleInitial, 7);
        clearKeyboard();
    }
    printQuest("last name");
    getString(name->lastName, 36);
}
// getAddress:
void getAddress(struct Address* address)
{
    char yesNo;
    int keepgoing = 1;

    printQuest("street number");
    while (keepgoing)
    {
        address->streetNumber = getInt();
        clearKeyboard();
        if (address->streetNumber > 0)
            keepgoing = 0;
        else if (address->streetNumber < 0)
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        else
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
       keepgoing = 1;
       printQuest("street name");
       getString(address->street, 41);
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
            else if (address->apartmentNumber < 0)
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            else
            {
                clearKeyboard();
                printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            }
        }
    }
    printQuest("postal code");
    clearKeyboard();
    getString(address->postalCode, 8);
    clearKeyboard();

    printQuest("city");
    getString(address->city, 41);
}
// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char yesNo;
    printQuest("cell phone number");
    getString(numbers->cell, 11);

    yesNoQuest("a home phone number");
    yesNo = yes();

    if (yesNo == 1)
    {
        printQuest("home phone number");
        getString(numbers->home, 11);
    }

    yesNoQuest("a business phone number");
    yesNo = yes();

    if (yesNo == 1)
    {
        printQuest("business phone number");
        getString(numbers->business, 11);
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
// getSting:
void getString(char* x, int y)
{
    int input_ch;
    int count = 0;

    // getting the character until user input the 'enter key'
    while ((input_ch = getchar()) != STOP && count < (y - 1))
        x[count++] = input_ch;
    x[count] = '\0';
}
//print question:
void printQuest(char x[])
{
    printf("Please enter the contact's %s: ", x);
}
//print Yes or No question
void yesNoQuest(char x[])
{
    printf("Do you want to enter %s? (y or n): ", x);
}
