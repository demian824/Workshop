/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week04_PT2
*/
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
		//NameTag();
		NameTag(const char* name = "Bad number", const int number = -1);
		~NameTag();
		//initialization function
		void init(const char* name, const int &number);
		//conditional functnios
		void setName(const char* name, const int size);
		void setNumber(const int& number);
		int checkSize(const char* name);
		bool isValid();
		//print functions
		void print() const;
		void printStar(int size) const;
		void printNum(int size) const;
		void printSpace(int size) const;
		NameTag& read();
		void inputName();
		void inputNum();
		bool yesNo();
	};
}