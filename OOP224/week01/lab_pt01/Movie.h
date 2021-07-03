/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Course:         OOP244
    Workshop:	    Week01
*/

#pragma once

#include <iostream>
#include <cstring>
#include <cstdio>
#include "File.h"

struct Movie {
	char m_title[128];
	int m_year;
	char m_rating[6];
	int m_duration;
	char m_genres[10][11];
	float m_consumerRating;
};

bool loadMovies();
bool hasGenre(const Movie* mvp, const char genre[]);
void displayMovie(const Movie* mvp);
void displayMoviesWithGenre(const char genre[]);
