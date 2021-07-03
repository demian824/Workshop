/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week6
*/
/************************************
	* File Name:				Autoshop.cpp
	* Included Header/Library	
	* Autoshop.h
	* algorithm
	* namespace:				sdds
	************************************/
#include <algorithm>
#include "Autoshop.h"

namespace sdds {
	using namespace std;
	/************************************
	* Constructor Name:		Autoshop
	* Discription:			default constructor
	************************************/
	Autoshop::~Autoshop() {
		for (size_t i = 0; i < m_vehicles.size(); i++)	
			delete m_vehicles[i];
	}
	/************************************
	* Function prototype:		Autoshop& operator +=(Vehicle* theVehicle)
	* Function Name:			operator +=
	* Function type:			Autoshop&
	* Function Parameter:		theVehicle
	* Parameter type:			Vehicle*
	* Return value/variable:	this
	* Discription:				assign parameter data into m_vehicles
	************************************/
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	/************************************
	* Function prototype:		void display(std::ostream& out) const
	* Function Name:			display
	* Function type:			void
	* Function Parameter:		out
	* Parameter type:			std::ostream&
	* Discription:				print the value of m_vehicles
	************************************/
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		for (size_t i = 0; i < m_vehicles.size(); i++) {
			m_vehicles[i]->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;
	}
	
}
