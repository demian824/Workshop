/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Course:         OOP244
    Workshop:	    Week01_p2
*/
#include <iostream>
#include "School.h"

using namespace std;
using namespace globalFunction;

void flushkeys();
bool yes();

int main() 
{
    bool done = false;
    bool search = false;
    char inputCode[5];

    if (!loadData())
        cout << "fail to open the file." << endl;
    
    cout << "Seneca School Extension search." << endl;

    while (!done) 
    {
        cout << "Enter the School code: ";
        cin >> inputCode;
        flushkeys();
        
        search = searchNumber(inputCode);

        if (!search)
            cout << inputCode << " School code not found!" << endl;

        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}

// flushes the keyboard
void flushkeys() {
    while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
    char ch = cin.get();
    flushkeys();
    return ch == 'y' || ch == 'Y';
}