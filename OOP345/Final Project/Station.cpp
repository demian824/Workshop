// Name:					Wonchul Choi
// Seneca Student ID:		118362201
// Seneca email:			wchoi28@myseneca.ca
// Date of completion:		Mar. 09. 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

/************************************
	* File Name:				Station.cpp
	* Included Header/Library
	* Utilities.h
	* iomanip
	* namespace:				sdds
	************************************/
#include <iomanip>
#include "Station.h"

namespace sdds {
	using namespace std;
	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;

	/************************************
	* Constructor Name:		Station
	* Discription:			
	*	set the string until delimiter
	************************************/
	Station::Station(const std::string& str) {		
			bool isMore = false;
			Utilities ut;
			size_t index = 0;
			std::string tempStr;
									
			m_name = ut.extractToken(str, index, isMore);
			if (isMore) {
				m_id = ++id_generator;
				tempStr = ut.extractToken(str, index, isMore);
				m_serial = stoi(tempStr);
				tempStr.erase();
			}
			if (isMore) {
				tempStr = ut.extractToken(str, index, isMore);
				m_qty = stoi(tempStr);
				tempStr.erase();
			}
			if (isMore) {
				if (m_widthField < ut.getFieldWidth()) 					
					m_widthField = ut.getFieldWidth();
				m_desc = ut.extractToken(str, index, isMore);
			}
	}


	/************************************
	* Function prototype:		const std::string& getItemName() const
	* Function Name:			getItemName
	* Function type:			const std::string&
	* Function Parameter:		none
	* Discription:				return m_name
	************************************/
	const std::string& Station::getItemName() const {	return m_name;	}
	/************************************
	* Function prototype:		size_t getNextSerialNumber()
	* Function Name:			getNextSerialNumber
	* Function type:			size_t
	* Function Parameter:		none
	* Discription:				return unique m_serial
	************************************/
	size_t Station::getNextSerialNumber() {	return m_serial++;	}

	/************************************
	* Function prototype:		size_t Station::getQuantity() const
	* Function Name:			getQuantity
	* Function type:			size_t
	* Function Parameter:		none
	* Discription:				remove the space in string
	************************************/
	size_t Station::getQuantity() const {	return m_qty;	}

	/************************************
	* Function prototype:		void updateQuantity()
	* Function Name:			updateQuantity
	* Function type:			void
	* Function Parameter:		none
	* Discription:				decrease m_qty
	************************************/
	void Station::updateQuantity() {	if (m_qty > 0) m_qty--;	}

	/************************************
	* Function prototype:		void display(std::ostream& os, bool full) const
	* Function Name:			display
	* Function type:			void
	* Function Parameter:		os, full
	* Parameter type:			std::ostream&, bool
	* Default Parameter:		desc = false
	* Discription:				desplay data following the format
	************************************/
	void Station::display(std::ostream& os, bool full) const {
		os.fill('0');
		os << "[" << std::setw(3) << m_id << "] Item: ";
		os.setf(std::ios::left);
		os.fill(' ');
		os  << std::setw(m_widthField) << m_name << " [";
		os.unsetf(std::ios::left);
		os.fill('0');
		os << std::setw(6) << m_serial << "]";
		if (full) {
			os.setf(std::ios::left);
			os.fill(' ');
			os << " Quantity: " << std::setw(m_widthField) << m_qty;
			os.unsetf(std::ios::left);
			os << " Description: " << m_desc;
		}
		os << endl;		
	}
}
