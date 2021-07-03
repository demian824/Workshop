#pragma once
#include <vector>
#include "Workstation.h"

namespace sdds {
	class LineManager {
		bool isSorted;
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation = nullptr;
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}