/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week08
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* string, int width, int height);
		~Rectangle();
		void getSpecs(std::istream& in);
		void draw(std::ostream& os);
	};
}
#endif