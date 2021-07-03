/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week08
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual ~Shape();
		virtual void draw(std::ostream& os) = 0;
		virtual void getSpecs(std::istream& in) = 0;
	};
	std::ostream& operator << (std::ostream& out, Shape& sh);
	std::istream& operator >> (std::istream& in, Shape& sh);
}

#endif // !SDDS_SHAPE_H