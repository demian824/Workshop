/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week08
*/
#include <string>
#include <cstring>
#include <limits>
#include "Rectangle.h"
using namespace std;
namespace sdds {
	typedef Rectangle ra;

	ra::Rectangle() : m_width(0), m_height(0) {	}
	ra::Rectangle(const char* string, int width, int height )
		: LblShape(string), m_width(width), m_height(height) {
		int lengthSize = (strlen(label()) + 2);
		if (m_height < 3 || lengthSize > m_width) {
			m_width = 0;
			m_height = 0;
		}

	}

	ra::~Rectangle() {}
	void ra::getSpecs(istream& in) {
		string temp;
		getline(in, temp, ',');
		init(temp.c_str());
		in >> m_width;
		in.ignore(std::numeric_limits<int>::max(), ',');
		in >> m_height;
		in.ignore(std::numeric_limits<int>::max(), '\n');
	}
	void ra::draw(ostream& os) {
		int spWitdth = m_width - 2;
		os << "+";
		for (int i = 0; i < spWitdth; i++)
			os << "-";
		os << "+" << endl;
				
		os << "|" << label();
		int spWitdth2 = spWitdth - strlen(label());
		for (int i = 0; i < spWitdth2; i++)
			os << " ";
		os << "|" << endl;
		if (m_height > 3) {
			for (int i = 0; i < (m_height - 3); i++) {
				os << "|";
				for (int j = 0; j < spWitdth; j++)
					os << " ";
				os << "|" << endl;
			}
		}
		os << "+";
		for (int i = 0; i < spWitdth; i++)
			os << "-";
		os << "+";
	}
}