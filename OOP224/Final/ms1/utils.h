/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    	wchoi28
    Student e-mail: 	wchoi28@myseneca.ca
    Course:         	OOP244
    Final project:  	MS1
*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
    int getInt();
    int getTime(); // returns the time of day in minutes
    bool numRange(int& num, int& max);
    bool strTotime(const char* string, int& hour, int& min);
    extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                       // all the files which include: "utils.h" 
                       //(you will learn this in detail in oop345)
}
#endif // !SDDS_UTILS_H_