// Name:					Wonchul Choi
// Seneca Student ID:		118362201
// Seneca email:			wchoi28@myseneca.ca
// Date of completion:		Mar. 09. 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

/************************************
	* File Name:				Utilities.cpp
	* Included Header/Library
	* Utilities.h
	* namespace:				sdds
	************************************/

#include "Utilities.h"

namespace sdds {
	using namespace std;	
	char Utilities::m_delimiter = '\0';
	
	/************************************
	* Function prototype:		void Utilities::setFieldWidth(size_t newWidth)
	* Function Name:			getItemName
	* Function type:			const std::string&
	* Function Parameter:		newWidth
	* Parameter type:			size_t
	* Discription:				set new value of m_widthField 
	************************************/
	void Utilities::setFieldWidth(size_t newWidth) {	m_widthField = newWidth;	}

	/************************************
	* Function prototype:		size_t getFieldWidth() const
	* Function Name:			getFieldWidth
	* Function type:			size_t
	* Function Parameter:		none
	* Discription:				return m_widthField
	************************************/
	size_t Utilities::getFieldWidth() const {	return m_widthField;	}

	/************************************
	* Function prototype:		char getDelimiter()
	* Function Name:			getDelimiter
	* Function type:			char
	* Function Parameter:		none
	* Discription:				return m_delimiter
	************************************/
	char Utilities::getDelimiter() { return m_delimiter; }

	/************************************
	* Function prototype:		void setDelimiter(char newDelimiter)
	* Function Name:			setDelimiter
	* Function type:			void
	* Function Parameter:		newDelimiter
	* Parameter type:			char
	* Discription:				set new value of m_delimiter
	************************************/
	void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

	/************************************
	* Function prototype:		std::string extractToken(const std::string& str, size_t& next_pos, bool& more)
	* Function Name:			extractToken
	* Function type:			std::string
	* Function Parameter:		str, next_pos, more
	* Parameter type:			const std::string&, size_t&, bool&
	* Discription:				get the data from string
	************************************/
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string copyStr = str.substr(next_pos);
		size_t indexFirst = copyStr.find(m_delimiter);
		
		if (copyStr[0] == m_delimiter) { 
			more = false;
			throw -1; 
		}
		else {
			if (indexFirst == std::string::npos) {
				copyStr = copyStr.substr(0);
				more = false;
			}
			else {
				more = true;
				copyStr = copyStr.substr(0, indexFirst);
				next_pos = next_pos + indexFirst + 1;
			}
			if (copyStr.length() > m_widthField)
				m_widthField = copyStr.length();
		}
		return copyStr;
	}	
}