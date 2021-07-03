/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week08
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* string, int length);
		~Line();
		void getSpecs(std::istream& in);
		void draw(std::ostream& os);
	};
}
#endif // !SDDS_LINE_H