// Name:					Wonchul Choi
// Seneca Student ID:		118362201
// Seneca email:			wchoi28@myseneca.ca
// Date of completion:		Apr. 09. 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once

#include <string>
#include <deque>
#include <vector>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;

	class Workstation : public Station{
		std::deque<CustomerOrder> m_order = {};
		Workstation* m_pNextStation = nullptr;
	public:
		Workstation(const std::string str);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		const Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};

}