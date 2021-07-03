/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Final project:  MS4
*/
#include "CovidPatient.h"
using namespace std;
namespace sdds {
	int nextCovidTicket = 1;
	
	typedef CovidPatient cp;

	cp::CovidPatient() 
		: Patient(nextCovidTicket++) {	}
	char cp::type() const {	return 'C';	}
	ostream& cp::csvWrite(ostream& ostr)const {
		return cp::Patient::csvWrite(ostr);
	}
	istream& cp::csvRead(istream& istr) {
		cp::Patient::csvRead(istr);
		nextCovidTicket = number() + 1;
		return istr;
	}
	ostream& cp::write(ostream& ostr)const {
		if (fileIO())
			cp::Patient::csvWrite(ostr);
		else {
			cout << "COVID TEST" << endl;
			cp::Patient::write(ostr);
			cout << endl;
		}
		return ostr;
	}
	istream& cp::read(istream& istr) {
		if (fileIO())
			csvRead(istr);
		else
			cp::Patient::read(istr);
		return istr;
	}

}