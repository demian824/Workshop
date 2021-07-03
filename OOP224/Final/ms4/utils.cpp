/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Final project:  MS3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <limits>
#include<string>
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


    bool copyString(const char* origin, char*& member) {
        bool success = true;
        
        int size = strlen(origin);

        if (size >= 51)
            size = 51;

        delete[] member;

        member = new char[size + 1];

        if (!member)
            success = false;
        else {
            for (int i = 0; i < size; i++)
                member[i] = origin[i];
            member[size] = '\0';           
        }
        
        return success;
    }

    bool numRange(const int& min, const int& max, const int& value) {
        if (value >= min && value <= max)
            return true;
        else {
            cout << "Invalid value enterd, retry[" << min << " <= value <= " << max << "]: ";
            return false;
        }
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
            else if (string[2] == ':' ) {
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

    int getTime(istream& is) {
        bool flag = false;
        int hour;
        int min;

        while (!flag) {
            is >> hour;
            if (!is) {
                cout << "Bad time entry, retry (HH:MM): ";
                is.clear();
                is.ignore(numeric_limits<int>::max(), '\n');
            }
            else {
                is.ignore(numeric_limits<int>::max(), ':');
                is >> min;
                if ((hour < 0 || hour > 24) || (min < 0 || min > 60))
                    cout << "Bad time entry, retry (HH:MM): ";
                else
                    flag = true;
            }
        }
        return (hour * 60) + min;
    }
}