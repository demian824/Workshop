/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week08
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
	typedef LblShape lbl;

	const char* lbl::label() const {	return m_label;	}
	lbl::LblShape(){
		m_label = nullptr;
	}
	lbl::LblShape(const char* label)
		: m_label(nullptr) {
		init(label);
	}
	lbl::~LblShape() {
		delete[] m_label;
	}
	void lbl::init(const char* label) {
		if (label) {
			delete[] m_label;
			m_label = new char[strlen(label) + 1];

			if (!m_label)
				cout << "fail to memory allocation at constructor" << endl;
			strcpy(m_label, label);
		}
	}

	void lbl::getSpecs(istream& in) {
		bool ok = false;
		char tempArr[21];
		int count = 0;

		while (!ok && count < 21) {
			in.get(tempArr[count]);
			if (tempArr[count] == ';')
				ok = true;
			count++;
		}
		in.ignore(21, ';');

		if (m_label)
			delete[] m_label;
		int size = strlen(tempArr) + 1;
		m_label = new char[size];
		strcpy(m_label, tempArr);
	}

}