/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week07
*/
#include <iostream>
#include "Truck.h"
using namespace std;
namespace sdds {
	typedef Truck t;
	
	t::Truck(const char* string, int year, int capacity, const char* address) {
		Vehicle::init(string, year, "Factory");
		Vehicle::moveTo(address);
		m_capWeight = (double)capacity;
		m_curWeight = 0;
	}
	t::~Truck() {}
	bool t::addCargo(double cargo) {
		bool pass = true;
		if (m_curWeight < m_capWeight) {
			m_curWeight += cargo;

			if (m_curWeight > m_capWeight)
				m_curWeight = m_capWeight;
		}
		else
			pass = false;

		return pass;

	}
	bool t::unloadCargo() {
		bool pass = true;
		
		if (m_curWeight > 0)
			m_curWeight = 0;
		else
			pass = false;

		return pass;
	}
	ostream& operator<<(ostream& os, Truck& t) {
		t.write(os);
		return os;
	}
	ostream& t::write(std::ostream& os) {
		
		Vehicle::write(os);
		if(m_curWeight > m_capWeight)
			os << " | " << m_capWeight << "/" << m_capWeight;
		else
			os << " | " << m_curWeight << "/" << m_capWeight;

		return os;
	}
	istream& operator>>(istream& in, Truck& t) {
		t.read(in);
		return in;
	}
	istream& t::read(std::istream& in) {
		char tempPlate[9];
		char tempAddress[64];
		int tempYear;
		double tempMax;
		double tempCur;

		cout << "Built year: ";
		in >> tempYear;
		cout << "License plate: ";
		in >> tempPlate;
		cout << "Current location: ";
		in >> tempAddress;
		cout << "Capacity: ";
		in >> tempMax;
		cout << "Cargo: ";
		in >> tempCur;

		Vehicle::init(tempPlate, tempYear, tempAddress);
		m_capWeight = tempMax;
		m_curWeight = tempCur;

		return in;
	}
}