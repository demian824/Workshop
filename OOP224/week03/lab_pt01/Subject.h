/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	Week04_PT1
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


namespace sdds {
	class Subject
	{
	private:
		char m_code[7]; // holds the subject code (exactly 6 characters)
		int m_mark;     // the mark out of 100
		char grade()const;
	public:
		Subject();
		~Subject();
		void setEmpty();
		void set(const char* code, int mark);
		float scale4()const;
		bool isValid()const;
	};
};