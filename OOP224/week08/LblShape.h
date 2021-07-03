/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week08
*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
	class LblShape : public Shape {
		char* m_label;
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		void init(const char* label);
		void getSpecs(std::istream& in);
		//std::ostream& operator << (LblShape& ls);
	};
}
#endif // !SDDS_LBLSHAPE_H