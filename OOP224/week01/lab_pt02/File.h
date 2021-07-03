/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Course:         OOP244
    Workshop:	    Week01_p2
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>

namespace globalFunction
{
	bool openFile(const char filename[]);
	void closeFile();
	bool readCode(char department[]);
	bool readNumber(char number[]);
}