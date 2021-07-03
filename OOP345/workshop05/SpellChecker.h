/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week5
*/
/************************************
	* File Name:			SpellChecker.h
	* Included Header/Library
	*	iostream
	*	string
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once
#include <string>
#include <iostream>

namespace sdds {
	const int LIMIT = 6;
	/************************************
		* Class Name:			SpellChecker
		* Member Variable:		num[LIMIT], m_badWord[LIMIT], m_goodWord[LIMIT]
		* Member Variable type: size_t, std::string, std::string;
		* Constructor:			SpellChecker(const char* filename)
		* Destructor:			defualt
		* Member Function:
		*	 showStatistics(std::ostream& out)
		* Overloading:			operator()
		************************************/
	class SpellChecker {
		size_t num[LIMIT];
		std::string m_badWord[LIMIT];
		std::string m_goodWord[LIMIT];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;			
	};
}