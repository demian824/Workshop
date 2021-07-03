/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week6
*/
/************************************
	* File Name:			Autoshop.h
	* Included Header/Library
	*	list
	*	vector
	*	Vehicle.h
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once

#include <list>
#include <vector>
#include "Vehicle.h"

namespace sdds {
	/************************************
		* Class Name:			Autoshop
		* Member Variable:		m_vehicles
		* Member Variable type: std::vector<Vehicle*>;
		* Constructor:			
		* Destructor:			~Autoshop()
		* Member Function:
		*	 void display(std::ostream& out) const
		*	 Autoshop& operator +=(Vehicle* theVehicle)
		*	 Vehicle* operator[](const size_t index)
		*	 void select(T test, std::list<const Vehicle*>& vehicles)
		************************************/
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		~Autoshop();
		void display(std::ostream& out) const;
		Autoshop& operator +=(Vehicle* theVehicle);	
		/************************************
		* Function prototype:		void select(T test, std::list<const Vehicle*>& vehicles)
		* Function Name:			select
		* Function type:			void
		* Function Parameter:		test, vehicles
		* Parameter type:			T, std::list<const Vehicle*>&
		* Discription:				assign the data to parameter of list type
		************************************/
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (size_t i = 0; i < m_vehicles.size(); i++) {
				if (test(m_vehicles[i]))
					vehicles.push_back(m_vehicles[i]);
			}
		}

	};
}