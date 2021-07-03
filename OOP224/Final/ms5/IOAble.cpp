/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Final project:  MS2
*/
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	IOAble::~IOAble() {}
	ostream& operator << (ostream& os, const IOAble& io) {
		io.write(os);
		return os;
	}
	istream& operator >> (istream& in, IOAble& io) {
		io.read(in);
		return in;
	}
}
