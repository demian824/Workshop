/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Final project:  MS3
*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size) {
        delete array[index];
        for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
        }
        size--;
    }
    int getInt();
    int getTime(); // returns the time of day in minutes
    bool copyString(const char* orgin, char*&member, int max = 50);
    bool numRange(const int &min = 0, const int &max = 0, const int &value = 0);
    bool strTotime(const char* string, int& hour, int& min);
    int getTime(std::istream& is);
    extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                       // all the files which include: "utils.h" 
                       //(you will learn this in detail in oop345)
}
#endif // !SDDS_UTILS_H_