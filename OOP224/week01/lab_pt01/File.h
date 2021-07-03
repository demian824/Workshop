/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Course:         OOP244
    Workshop:	    Week01
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
}


bool readGenres(char genres[][11]);
bool readConsumerRating(float* rating);