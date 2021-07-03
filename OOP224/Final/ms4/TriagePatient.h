/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Final project:  MS4
*/
#ifndef SDDS_TRIAGE_H
#define SDDS_TIRAGE_H
#include <iostream>
#include "utils.h"
#include "Patient.h"
namespace sdds {
	class TriagePatient : public Patient {
		char* m_symptom;
	public:
		TriagePatient();
		~TriagePatient();
		char type() const override;
		std::ostream& csvWrite(std::ostream& ostr)const override;
		std::istream& csvRead(std::istream& istr) override;
		std::ostream& write(std::ostream& ostr)const override;
		std::istream& read(std::istream& istr) override;

	};

}
#endif // !SDDS_