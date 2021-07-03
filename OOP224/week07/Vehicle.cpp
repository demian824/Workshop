/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week07
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Vehicle.h"

using namespace std;
namespace sdds {
	typedef Vehicle v;
	v::Vehicle(const char* string, const int& year, const char* address){
		memset(m_plateNum, 0, sizeof(m_plateNum));
		memset(m_addressVeh, 0, sizeof(m_addressVeh));
		init(string, year, address);
	}
	v::~Vehicle(){}

	void v::init(const char*string, const int year, const char*address) {
			strcpy(m_plateNum, string);
			strcpy(m_addressVeh, address);
			m_year = year;
	}

	void v::moveTo(const char* address){
		cout << "|" << setw(8)  << m_plateNum << "|";
		cout << " |" << setw(20) << m_addressVeh;
		cout << " ---> ";
		cout.setf(ios::left);
		cout << setw(20) <<  address  << "|" << endl;
				
		memset(m_addressVeh, 0, sizeof(m_addressVeh));

		strcpy(m_addressVeh, address);

		cout.unsetf(ios::left);
	}

	ostream& v::write(ostream& os){
		os << "| " << m_year << " | " << m_plateNum << " | " << m_addressVeh;
		return os;
	}

	ostream& operator<<(ostream& out, Vehicle vh) {
		vh.write(out);
		return out;
	}

	istream& v::read(istream& in){
		int temp_year;
		char temp_arr1[9];
		char temp_arr2[64];
		cout << "Built year: ";
		in >> temp_year;
		cout << "License plate: ";
		in >> temp_arr1;
		cout << "Current location: ";
		in >> temp_arr2;

		memset(m_plateNum, 0, sizeof(m_plateNum));
		memset(m_addressVeh, 0, sizeof(m_addressVeh));

		strcpy(m_plateNum, temp_arr1);
		strcpy(m_addressVeh, temp_arr2);
		this->m_year = temp_year;
		
		return in;
	}

	istream& operator >> (istream& in, Vehicle& vh) {
		vh.read(in);
		return in;
	}
}