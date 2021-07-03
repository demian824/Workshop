/*
    Student Name:		Wonchul Choi
    Student Nubmer:	    118362201
    Student ID:	   	    wchoi28
    Student e-mail: 	wchoi28@myseneca.ca
    Course:         	OOP244
    Workshop:	    	Week02_DIY
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool readAccount(unsigned int * account)
    {
        return fscanf(fptr, "%d,", account);
    }

    bool readBalance(double* balance)
    {
        return fscanf(fptr, "%lf ", balance);
    }

}