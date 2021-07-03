/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Course:         OOP244
    Workshop:	    Week01_p2
*/
#include "File.h"

FILE* fptr;

bool globalFunction::openFile(const char filename[])
{
    fptr = fopen(filename, "r");
    return fptr != NULL;
}
void globalFunction::closeFile()
{
    if (fptr) fclose(fptr);
}

bool globalFunction::readCode(char department[])
{
    return fscanf(fptr, "%s", department) == 1;
}

bool globalFunction::readNumber(char number[])
{
    return fscanf(fptr, " %[^\n] ", number) == 1;
}
