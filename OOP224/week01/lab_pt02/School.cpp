/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Course:         OOP244
    Workshop:	    Week01_p2
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include "School.h"

using namespace std;
using namespace globalFunction;

EXT_NUM dptNums[24];

bool loadData() 
{
    EXT_NUM ext_num;
    int count = 0; // number of movies read
    bool ok = true;
    if (openFile("schools.dat")) 
    {
        while (ok && count < 24) 
        {
            ok = readCode(ext_num.dName) && readNumber(ext_num.dNumber);
            if (ok) 
                dptNums[count++] = ext_num;
        }
        closeFile();
    }
    return count == 24;
}

bool searchNumber(char* dptcode)
{
    bool find = false;

    for (int i = 0; i < 24; i++)
        if ((strcmp(dptcode, dptNums[i].dName) == 0))
        {
            cout << "416 491 5050 x " << dptNums[i].dNumber << endl;
            find = true;
            break;
        }
    
    return find;
}