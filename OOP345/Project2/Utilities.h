// Name:					Wonchul Choi
// Seneca Student ID:		118362201
// Seneca email:			wchoi28@myseneca.ca
// Date of completion:		Mar. 09. 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#pragma once
#include <iostream>
#include <string>

namespace sdds {
	/************************************
		* Class Name:			Utilities
		* Member Variable:		m_delimiter, m_widthField
		* Member Variable type: static char, size_t
		* Member Function:
		*	 void setFieldWidth(size_t newWidth)
		*	 static char getDelimiter()
		*	 static void setDelimiter(char newDelimiter)
		*    size_t getFieldWidth() const
		*	 std::string extractToken(const std::string& str, size_t& next_pos, bool& more)
		************************************/
	class Utilities {
		static char m_delimiter;
		size_t m_widthField = 1;
	public:
		void setFieldWidth(size_t newWidth);
		static char getDelimiter();
		static void setDelimiter(char newDelimiter);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	};

}