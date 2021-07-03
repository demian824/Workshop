/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Lab1
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma once
/************************************
	* File Name:			event.h
	* Included Header/Library
	*	iostream
	*	cstring
	*	iomanip
	* namespace:			sdds
	* preprocessor:
	*	#define _CRT_SECURE_NO_WARNINGS
	*	#pragma oncevoid
	************************************/
#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds {
	/************************************
		* Variable Name: g_sysClock
		* Variable type: 
		*	unsigned int
		*	global 
		************************************/
	extern unsigned int g_sysClock;
	/************************************
		* Class Name:			Event
		* Member Variable:		m_eventDesc, m_flag, m_time
		* Member Variable type: char*, char, unsigned int
		* Constructor:			defualt
		* Desstructor:			defualt
		* Member Function: 
		*	printFormat
		*	display
		*	set
		* Overloading:			operator =
		************************************/
	class Event {
		char* m_eventDesc;
		char m_flag;
		unsigned int m_time;
	public:
		Event();
		~Event();
		void printFormat(const int hours, const int mins, const int secs, const char* description) const;
		void display();
		void set(char* description = nullptr);
		void memoryDeallcoation();
		Event& operator = (Event& origin);
	};
};