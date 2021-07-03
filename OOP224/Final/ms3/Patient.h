#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Final project:  MS3
*/
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {
	const int MIN = 100000000;
	const int MAX = 999999999;
	class Patient : public Ticket{
		bool m_ioFlag;
		char* m_patientName;
		int m_ohipNum;
	public:
		Patient(const int ticket, const bool flag);
		~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(const bool flag);
		bool operator ==(char ch)const;
		bool operator ==(const Patient& pt)const;
		operator Time() const;
		int number()const;
		void setArrivalTime();
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_PATIENT_H_