
#include <iomanip>
#include "CustomerOrder.h"

namespace sdds {
	using namespace std;
	size_t CustomerOrder::m_widthField = 0;
	
	CustomerOrder::~CustomerOrder() { 
		for (size_t i = 0; i < m_cntItem; i++) 
			if(m_lstItem[i]) 
				delete m_lstItem[i];
		delete[] m_lstItem; 
	}

	CustomerOrder::CustomerOrder(){}
	CustomerOrder::CustomerOrder(const std::string& str){
		bool isMore = false;
		size_t index = 0;
		size_t wordCount = 1;
		Utilities ut;
		m_name = ut.extractToken(str, index, isMore);
		m_product = ut.extractToken(str, index, isMore);
		if (m_widthField < ut.getFieldWidth())
			m_widthField = ut.getFieldWidth();

		for (size_t i = index; i < str.length(); i++) 
			if (str[i] == ut.getDelimiter()) wordCount++;
		
		m_cntItem = wordCount;

		if (m_lstItem != nullptr) delete m_lstItem;
		m_lstItem = new Item * [m_cntItem];

		if (!m_lstItem) cout << "Failed to memory allocation" << endl;
		else {
			for (size_t i = 0; i < m_cntItem && isMore; i++) {
				m_lstItem[i] = new Item(ut.extractToken(str, index, isMore));
				if (m_widthField < ut.getFieldWidth())
					m_widthField = ut.getFieldWidth();
			}
		}
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& origin){
		throw 0;
	}
	
	CustomerOrder::CustomerOrder(CustomerOrder&& origin) noexcept { *this = std::move(origin); }
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& origin) noexcept {
		if (this != &origin) {
			for (size_t i = 0; i < m_cntItem; i++) {
				if (m_lstItem[i])
					delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_name = origin.m_name;
			m_product = origin.m_product;
			m_cntItem = origin.m_cntItem;
			m_lstItem = origin.m_lstItem;
			

			origin.m_name.erase();
			origin.m_product.erase();
			origin.m_cntItem = 0;
			origin.m_lstItem = nullptr;
		
		}
		return *this;
	}
	bool CustomerOrder::isFilled() const{
		static size_t index = 0;
		bool isPass = false;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == true) {
				if (index != i) {
					index = i;
					isPass = true;
				}
				else
					isPass = false;
			}				
			else {
				isPass = false;
				break;
			}
		}
		return isPass;
	}	
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool isPass = false;

		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				isPass = m_lstItem[i]->m_isFilled;
			}
				
		}

		return isPass;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os){
		bool isFound = false;
		static size_t index = 0;
		
		
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
				isFound = true;
				if (index != i) {
					index = i;
					break;
				}
			}
		}
		if (station.getQuantity() > 0 && isFound) {
			if (!m_lstItem[index]->m_isFilled) {
				m_lstItem[index]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[index]->m_isFilled = true;	
				station.updateQuantity();
			}		
			if(m_lstItem[index]->m_isFilled)
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[index]->m_itemName << "]" << endl;
		}
		else if (!m_lstItem[index]->m_isFilled && station.getQuantity() < 1) {
			os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[index]->m_itemName << "]" << endl;
		}
	}
	void CustomerOrder::display(std::ostream& os) const{
		if(!m_name.empty()){
		os << m_name << " - " << m_product << std::endl;

		for (size_t i = 0; i < m_cntItem; i++) {
			os.fill('0');
			os << "[" << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
			os.fill(' ');
			os.setf(std::ios::left);
			os << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			os.unsetf(std::ios::left);
			if (m_lstItem[i]->m_isFilled)
				os << "FILLED";
			else
				os << "TO BE FILLED";
			os << endl;
		}
		}

	}
	int CustomerOrder::countItemNum(const std::string& str) {
		int count = 0; 
		for (size_t i = 0; i < m_cntItem; i++)
			if (m_lstItem[i]->m_itemName == str)
				count++;
		return count;
	}

	bool CustomerOrder::isItemOnList(const std::string& str) {
		int flag = false;
		static size_t index = 0;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == str) {
				if (i != index) 
					index = i;
				flag = true;
				break;
			}
			
		}
		return flag;
	}
}