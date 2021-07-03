/*
+--------------------------------------------------------*
|           2  0  2  0  ~  S  U  M  M  E  R
|                 I  P  C  :  B  T  P
|                 1  4  4  :  1  0  0
|                 ASSIGNMENT #2 MS# 2
|
|   S  E  N  E  C  A               C  O  L  L  E  G  E
|   ========  =======  =====  ========  ======  ======
|      ==     ==      ==        ==     ==      ==   ==
|     ==     ====     ====     ==     ====    ======
|    ==     ==          ==    ==     ==      == ==
|   ==     ======  =====     ==     ======  ==   ==
|
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
|  !!!   DO NOT ALTER THE CONTENTS OF THIS FILE   !!!
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
+--------------------------------------------------------*/


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

void printSectionHeader(const char*);

int main(void)
{
    struct Contact contact = { { { '\0' } } };
    int tstInteger = 0;

    //--------------------------------------------------------
    printSectionHeader("Yes()");
    printf("Please enter 'Y' > ");
    printf("    Result: %d\n", yes());
    printf("Please enter 'y' > ");
    printf("    Result: %d\n", yes());
    printf("Please enter 'N' > ");
    printf("    Result: %d\n", yes());
    printf("Please enter 'yes', then 'no', then 'n' > ");
    printf("    Result: %d\n", yes());

    //--------------------------------------------------------
    printSectionHeader("pause()");
    pause();

    //--------------------------------------------------------
    printSectionHeader("getInt()");
    printf("Enter 'ipc', then '144' > ");
    tstInteger = getInt();
    printf("    Integer entered: %d\n", tstInteger);

    //--------------------------------------------------------
    printSectionHeader("getIntInRange(int,int)");
    printf("Enter 'seneca', then '99', then '501', then '250' > ");
    tstInteger = getIntInRange(100, 500);
    printf("    Integer entered: %d\n\n", tstInteger);
    printf("Enter '100' > ");
    tstInteger = getIntInRange(100, 500);
    printf("    Integer entered: %d\n", tstInteger);
    printf("Enter '500' > ");
    tstInteger = getIntInRange(100, 500);
    printf("    Integer entered: %d\n", tstInteger);

    //--------------------------------------------------------
    printSectionHeader("getContact(struct Contact *)");
    getContact(&contact);
    printf("\nValues Entered:\n");
    printf("Name: %s %s %s\n", contact.name.firstName, contact.name.middleInitial, contact.name.lastName);
    printf("Address: %d|%s|%d|%s|%s\n", contact.address.streetNumber, contact.address.street,
        contact.address.apartmentNumber, contact.address.postalCode, contact.address.city);
    printf("Numbers: %s|%s|%s\n", contact.numbers.cell, contact.numbers.home, contact.numbers.business);

    //--------------------------------------------------------
    printSectionHeader("contactManagerSystem()");
    contactManagerSystem();

    //--------------------------------------------------------
    printSectionHeader("Assign#2 - MS #2 test completed");

    return 0;
}

// Display specified test section header
void printSectionHeader(const char* testName)
{
    printf("\n");
    printf("------------------------------------------\n");
    printf("Testing: %s\n", testName);
    printf("------------------------------------------\n");
}

