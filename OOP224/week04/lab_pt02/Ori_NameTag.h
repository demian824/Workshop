/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week04_PT2
*/
#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>


namespace sdds {
	class NameTag {
		char* m_empName;
		int m_extNum;

	public:
		//constructor & destructor
		NameTag(const char* name = "empty", const int number = -1);
		~NameTag();
		//initialization function
		void init(const char* name, int number);
		//conditional functnios
		void setName(const char* name, const int size);
		void setNumber(const int &number);
		int checkSize(const char* name);
		bool isValid(const char* name, int size);
		//print functions
		void print() const;
		void printStar(int size) const;
		void printNum(int size) const;
		void printSpace(int size) const;
		NameTag& read();
		void inputName();
		void inputNum();
		void copyName(const char* name, const int size);
		bool yesNo();
	};
}