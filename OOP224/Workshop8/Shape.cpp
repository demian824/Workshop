/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week08
*/
#include "Shape.h"
namespace sdds {
	Shape::~Shape() {}
	std::ostream& operator << (std::ostream& out, Shape& sh) {
		sh.draw(out);
		return out;
	}

	std::istream& operator >> (std::istream& in, Shape& sh) {
		sh.getSpecs(in);
		return in;
	}
}