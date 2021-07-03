// Name:					Wonchul Choi
// Seneca Student ID:		118362201
// Seneca email:			wchoi28@myseneca.ca
// Date of completion:		Apr. 09. 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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