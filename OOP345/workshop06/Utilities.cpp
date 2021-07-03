/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week6
*/
/************************************
	* File Name:				Utilities.cpp
	* Included Header/Library	
	* Utilities.h
	* sstream
	* string
	* namespace:				sdds
	************************************/
#include <sstream>
#include <string>
#include "Utilities.h"

namespace sdds {
	/************************************
		* Function prototype:		Vehicle* createInstance(std::istream& in)
		* Function Name:			createInstance
		* Function type:			Vehicle*
		* Function Parameter:		in
		* Parameter type:			std::istream&
		* Discription:				create instance of classes follow by category
		************************************/
	Vehicle* createInstance(std::istream& in) {
		std::string str;
		getline(in, str, ',');
		std::stringstream buf(str);
		buf >> str;

		if (toupper(str[0]) == 'C') {
			buf.str("");
			return new Car(in);

		}
		else if (toupper(str[0]) == 'R') {
			buf.str("");
			return new Racecar(in);
		}
		else if (!str.empty()) {
			in.ignore(256, '\n');
			throw std::out_of_range("Unrecognized record type: [" + str + "]");
		}
		else return nullptr;
	}
}