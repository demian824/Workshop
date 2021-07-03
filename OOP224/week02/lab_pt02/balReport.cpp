// Workshop 2: 
// Version: 0.9
// Date: 09/25/2020
// Author: Fardad Soleimanloo
// Reviewed by: Michael Huang
// Description:
// This file tests the DIY section of your workshop
// Do not modify your code
/////////////////////////////////////////////
/*
    Student Name:		Wonchul Choi
    Student Nubmer:		118362201
    Student ID:	   	 	wchoi28
    Student e-mail: 		wchoi28@myseneca.ca
    Course:         		OOP244
    Workshop:	    		Week02_DIY
*/

#include "Account.h"
#define FILENAME "accounts_prof.csv"
using namespace sdds;
int main() {
    if (load(FILENAME)) {
        display();
    }
    deallocateMemory();
    return 0;
}