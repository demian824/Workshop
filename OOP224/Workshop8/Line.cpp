/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week08
*/
#include <iostream>
#include <string>
#include <limits>
#include "Line.h"
using namespace std;

namespace sdds {
	typedef Line l;
	l::Line() : m_length(0) {}
	l::Line(const char* string, int length)
		: LblShape(string), m_length(length){}
	l::~Line(){}
	void l::getSpecs(istream& in) {
		string temp;
		getline(in,temp, ',');
		init(temp.c_str());
		in >> m_length;
		in.ignore(2147483647, '\n');
	}
	void l::draw(ostream& os){
		if(label())
			if (m_length > 0) {
				os << label() << endl;
				for (int i = 0; i < m_length; i++)
					os << "=";
			}
	}
}