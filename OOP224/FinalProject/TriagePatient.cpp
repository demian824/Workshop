/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Final project:  MS4
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "TriagePatient.h"
using namespace std;
namespace sdds {
	typedef TriagePatient tp;
	int nextTriageTicket = 1;

	tp::TriagePatient() : Patient(nextTriageTicket++), m_symptom(nullptr) {}
	tp::~TriagePatient() { delete[] m_symptom; }
	char tp::type() const { return 'T'; }
	ostream& tp::csvWrite(ostream& ostr)const {
		tp::Patient::csvWrite(ostr);
		ostr << "," << m_symptom;
		return ostr;
	}
	istream& tp::csvRead(istream& istr) {
		char temp[512];
		tp::Patient::csvRead(istr);
		istr.ignore(1, ',');
		istr.get(temp, 511);
		copyString(temp, m_symptom, 511);
		nextTriageTicket = tp::Patient::number() + 1;
		return istr;
	}	
	ostream& tp::write(ostream& ostr)const {
		if (fileIO()) csvWrite(ostr);
		else {
			ostr << "TRIAGE" << endl;
			tp::Patient::write(ostr);
			ostr << endl << "Symptoms: " << m_symptom << endl;
		}
		return ostr;
	}
	istream& tp::read(istream& istr) {
		char temp[512];
		if (fileIO()) csvRead(istr);
		else {
			tp::Patient::read(istr);
			cout << "Symptoms: ";
			istr.getline(temp, 511);
			copyString(temp, m_symptom, 511);
		}
		return istr;
	}
}