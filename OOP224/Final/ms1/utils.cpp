/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    	wchoi28
    Student e-mail: 	wchoi28@myseneca.ca
    Course:         	OOP244
    Final project:  	MS1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt() {
        int value;
        bool badEntry;
        char nextChar;
        do {
            badEntry = false;
            cin >> value;
            if (cin.fail()) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(3000, '\n');
                badEntry = true;
            }
            else {
                nextChar = cin.get();
                if (nextChar != '\n') {
                    cout << "Only enter an integer, try again: ";
                    cin.ignore(3000, '\n');
                    badEntry = true;
                }
            }
        } while (badEntry);
        return value;
    }

    bool numRange(int& num, int& max) {
        bool pass = true;
        if (num < 0 || max < num) {
            cout << "Invalid value enterd, retry[0 <= value <= 3]: ";
            pass = false;
        }
        return pass;
    }

    bool strTotime(const char* string, int& hour, int& min) {
        bool pass = false;
        int length = strlen(string);
        for (int i = 0; i < length; i++) {
            if (i < 2) {
                if (string[i] >= 48 && string[i] <= 57)
                    hour = (hour * 10) + (string[i] - 48);
                else
                    break;
            }
            else if (i > 2) {
                if (string[i] >= 48 && string[i] <= 57) {
                    min = (min * 10) + (string[i] - 48);
                    pass = true;
                }
                else
                    pass = false;
            }

        }
        return pass;
    }
}