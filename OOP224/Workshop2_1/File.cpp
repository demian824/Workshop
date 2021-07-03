#define _CRT_SECURE_NO_WARNINGS
/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week02
*/
#include <cstdio>
#include "File.h"

namespace sdds
{
    FILE* fptr;

    bool openFile(const char filename[]) 
    {
        fptr = fopen(filename, "r");
        return fptr;
    }
    int noOfRecords() 
    {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) 
        {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() 
    {
        if (fptr) fclose(fptr);
        fptr = nullptr;
    }
     bool readSname(char* name)
    {
        return fscanf(fptr, "%[^,],", name);//%s
    }
    bool readSnumb(unsigned int* snumber) {
        return fscanf(fptr, "%d,", snumber);
    }
    bool readSgpa(double* score) {
        return fscanf(fptr, "%lf ", score);
    }

}