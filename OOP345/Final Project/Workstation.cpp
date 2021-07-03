// Name:					Wonchul Choi
// Seneca Student ID:		118362201
// Seneca email:			wchoi28@myseneca.ca
// Date of completion:		Apr. 09. 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include "Workstation.h"

namespace sdds {

	using namespace std;
	deque<CustomerOrder> pending = {};
	deque<CustomerOrder> completed = {};
	deque<CustomerOrder> incomplete = {};

	Workstation::Workstation(const std::string str)
		: Station(str)	{}
	void Workstation::fill(std::ostream& os) {
		if (!pending.empty()) 
			if (!pending[0].isItemFilled(this->getItemName())) 
				pending[0].fillItem(*this, os);		
	}
	
	bool Workstation::attemptToMoveOrder(){
		bool isMoved = true;
		bool isCompleteMoved = false;
		bool isIncompleteMoved = false;
		vector<size_t> compIndex;
		vector<size_t> incompIndex;

		if (m_order.empty()) {
			m_order.resize(pending.size());
			m_order = std::move(pending);
		}
		compIndex.reserve(m_order.size());
		incompIndex.reserve(m_order.size());
		for (size_t i = 0; i < m_order.size(); i++) {
			if (!m_pNextStation) {
				if (m_order[i].isFilled()) {
					//completed[i] = std::move(m_order[i]);
					compIndex.push_back(i);
					isCompleteMoved = true;
				}
				else if (!m_order[i].isFilled()) {
					//incomplete[i] = std::move(m_order[i]);
					incompIndex.push_back(i);
					isIncompleteMoved = true;
				}
			}
		
		}
		if (isCompleteMoved && !isIncompleteMoved) {
			if(compIndex.size() == m_order.size())
				for(size_t i =0; i < m_order.size() && (&m_order[i]); i++)
					completed[i] = std::move(m_order[i]);				
		}
		else if (!isCompleteMoved && isIncompleteMoved) {
			if (incompIndex.size() == m_order.size())
				incomplete = std::move(m_order);
		}
		else if (isCompleteMoved && isIncompleteMoved) {
			if ((compIndex.size() + incompIndex.size()) == m_order.size()) {
				for (size_t i = 0; i < compIndex.size(); i++) {
					completed[i] = std::move(m_order[compIndex[i]]);
				}
				for (size_t i = 0; i < incompIndex.size(); i++) {
					incomplete[i] = std::move(m_order[incompIndex[i]]);
				}
			}
		}
		else {
				pending = std::move(m_order);
				isMoved = false;
			}

		return isMoved;
	}
	void Workstation::setNextStation(Workstation* station){
		if (station == nullptr) m_pNextStation = nullptr;
		else m_pNextStation = station;
	}
	const Workstation* Workstation::getNextStation() const{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const{
		if (m_pNextStation == nullptr) {
			os << getItemName() << " --> End of Line" << std::endl;
		}
		else {
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		}

	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
		m_order.push_back(newOrder);
		return *this;
	}
}