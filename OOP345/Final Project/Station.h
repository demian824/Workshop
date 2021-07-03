// Name:					Wonchul Choi
// Seneca Student ID:		118362201
// Seneca email:			wchoi28@myseneca.ca
// Date of completion:		Mar. 09. 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#pragma once

#include"Utilities.h"

namespace sdds {
	/************************************
		* Class Name:			Station
		* Member Variable:		m_id, m_name, m_desc, m_serial, m_qty, m_widthField, id_generator
		* Member Variable type: int, std::string, std::string, size_t, size_t, static size_t, static int
		* Member Function:
		*	 Station(std::string& str)
		*	 const std::string& getItemName() const
		*	 size_t getNextSerialNumber()
		*    size_t getQuantity() const
		*	 void updateQuantity()
		*	 void display(std::ostream& os, bool full) const
		************************************/
	class Station {
		int	m_id = 0;
		std::string m_name = {};
		std::string m_desc = {};
		size_t		m_serial = 0;
		size_t		m_qty = 0;
		static size_t m_widthField; 
		static int id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}