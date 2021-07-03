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