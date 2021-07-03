/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week2
*/
#pragma once

/************************************
	* File Name:			StringSet.h
	* Included Header/Library
	*	iostream
	*	string
	*	fstream
	* namespace:			sdds
	* preprocessor:
	*	#pragma once
	************************************/
#pragma once
#include <iostream>
#include <string>
#include <fstream>

namespace sdds {
	/************************************
		* Class Name:			StringSet
		* Member Variable:		m_ele, m_count
		* Member Variable type: char*, char, unsigned int
		* Constructor:			defualt, copy, move
		* Destructor:			defualt
		* Member Function:
		*	size
		* Overloading:			operator =(L-value)
								operator =(R-value)
								operator[]
		************************************/
	class StringSet {
		std::string *m_ele = nullptr;
		size_t m_count = 0ull;
	public:
		//constructor
		StringSet();
		StringSet(const char* filename);
		StringSet(const StringSet& origin);
		StringSet(StringSet&& origin);
		//destructor
		~StringSet();
		//operator
		StringSet& operator=(const StringSet& origin);
		StringSet& operator=(StringSet&& origin);
		std::string operator[](size_t index);		
		//function
		size_t size();
	};
}