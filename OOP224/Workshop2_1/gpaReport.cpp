// Workshop 2: 
// Version: 0.9
// Date: 09/25/2020
// Author: Fardad Soleimanloo
// Reviewed by: Michael Huang
// Description:
// This file tests the lab section of your workshop
// Do not modify your code
/////////////////////////////////////////////
/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week02
*/

#include <crtdbg.h>
#include "Student.h"


using namespace sdds;
int main()
{
    using namespace std;
  
    if (load()) 
        display();
    deallocateMemory();
    _CrtDumpMemoryLeaks();
  
    return 0;
}
