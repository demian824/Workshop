/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Course:         OOP244
    Workshop:	    Week01_p2
*/
#pragma once

#include "File.h"

struct EXT_NUM
{
	char dName[5];
	char dNumber[6];
};

bool loadData();
bool searchNumber(char* dptcode);