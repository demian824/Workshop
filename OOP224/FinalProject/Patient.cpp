/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Final project:  MS3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <limits>
#include <string>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {

	typedef Patient p;

	p::Patient(int ticketNum, const bool flag)
		: Ticket(ticketNum), m_ioFlag(flag), m_patientName(nullptr), m_ohipNum(0) {}
	p::~Patient() {	delete[] m_patientName;	}
	bool p::fileIO() const {	return m_ioFlag;	}
	void p::fileIO(const bool flag) {	this->m_ioFlag = flag;	}
	bool p::operator ==(char ch)const { return type() == ch ? true : false;	}
	bool p::operator ==(const Patient& pt)const { return this->type() == pt.type() ? true : false; }
	void p::setArrivalTime(){ resetTime(); }
	p::operator Time() const {	return p::Ticket::operator sdds::Time();	}
	int p::number()const {	return Ticket::number();	}
	ostream& p::csvWrite(ostream& ostr)const {
		ostr << type() << "," << m_patientName << ',' << m_ohipNum << ',';
		Ticket::csvWrite(ostr);
		return ostr;
	}
	istream& p::csvRead(istream& istr) {
		int tempOhip;
		char tempStr[51];
		istr.getline(tempStr, 50,',');
		//istr.ignore(1, ',');
		//getline(istr, tempStr, ',');
		if (tempStr[0] != NULL) {
			//copyString(tempStr.c_str(), m_patientName);
			copyString(tempStr, m_patientName);
			istr >> tempOhip;
			istr.ignore(numeric_limits<int>::max(), ',');
			if (numRange(MIN, MAX, tempOhip)) {
				m_ohipNum = tempOhip;
				Patient::Ticket::csvRead(istr);
			}
		}
		return istr;
	}
	ostream& p::write(ostream& ostr)const {
		Patient::Ticket::write(ostr);
		ostr << endl << m_patientName << ", OHIP: " << m_ohipNum;		
		return ostr;
	}
	istream& p::read(istream& istr) {
		bool isWork = true;
		char string[51];
		cout << "Name: ";
		istr.getline(string, 51);
		if (copyString(string, m_patientName)) {
			cout << "OHIP: ";
			while (isWork) {
				m_ohipNum = getInt();
				if (numRange(MIN, MAX, m_ohipNum))
					isWork = false;
			}
		}
		return istr;
	}
}