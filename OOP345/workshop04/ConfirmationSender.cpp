#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
	typedef ConfirmationSender CF;
	using namespace std;
	CF::ConfirmationSender() : m_res(nullptr), m_capacity(0ull), m_size(0ull){}
	CF::~ConfirmationSender() { delete[] m_res; }
	CF::ConfirmationSender(const ConfirmationSender& cf) { *this = cf; }
	CF::ConfirmationSender(ConfirmationSender&& cf) noexcept { *this = std::move(cf); }
	ConfirmationSender& CF::operator = (const ConfirmationSender& cf) {
		if (this != &cf) {
			if (cf.m_res) {
				m_capacity = cf.m_capacity;
				delete[] m_res;
				m_res = new const Reservation * [cf.m_capacity];
				for (size_t i = 0; i < m_capacity; i++) {
					m_res[i] = cf.m_res[i];
					m_size = i + 1;
				}
			}
		}
		return *this;
	}
	ConfirmationSender& CF::operator = (ConfirmationSender&& cf) noexcept {
		if (this != &cf && cf.m_res) {
			delete[] m_res;
			m_res = cf.m_res;
			cf.m_res = nullptr;
			m_capacity = cf.m_capacity;
			cf.m_capacity = 0;
			m_size = cf.m_size;
			cf.m_size = 0;
		}
		return *this;
	}
	
	bool CF::searchData(const Reservation& res) const {
		bool isFind = false;
		if (m_res) 
			for (size_t i = 0; i < m_capacity && !isFind; i++)
				if (m_res[i] == &res) isFind = true;
		return isFind;
	}
	ConfirmationSender& CF::operator+=(const Reservation& res){
		bool isFind = searchData(res);
		//bool isNullptr = res.isEmpty();
	
		if (!isFind) {
			if (!m_res) {
				m_capacity = 0;
				m_size = 0;
			}
			if (m_size == m_capacity) {
				ConfirmationSender temp;
				temp = *this;
				delete m_res;
				m_res = new const Reservation * [m_capacity + 1];

				for (size_t i = 0ull; i < m_capacity; i++) {
					m_res[i] = temp.m_res[i];
				}
				m_res[m_capacity] = new Reservation(res);
				m_res[m_capacity] = (Reservation*)&res;
				m_capacity++;
				m_size++;
			}

		}
		/*if (m_size == 0 && isNull)
			m_res[m_size++] = (Reservation*)&res;
		else if (!isFind && isNull){
			if (m_size < m_capacity) m_res[m_size++] = (Reservation*)&res;
			else if(m_size == m_capacity)
			{
				Reservation** tempData = new Reservation * [m_capacity];
				for (int i = 0; i < m_capacity && m_res[i]; i++)
					tempData[i] = m_res[i];
				resize(m_capacity + 1);
				for (int i = 0; i < m_capacity - 1  && tempData[i]; i++)
					m_res[i] = tempData[i];
				
				m_res[m_size++] = const_cast<Reservation*>(&res);
	
							
			}
		}*/
		return *this;
	}
	ConfirmationSender& CF::operator-=(const Reservation& res){
		bool isFind = searchData(res);
		ConfirmationSender temp;
		int indexNum = 0;
		if (isFind) {
			for (size_t i = 0; i < m_size; i++) {
				if (m_res[i] == &res) {
					m_res[i] = nullptr;
					indexNum = i;
					break;
				}
			}
			temp.m_res = new const Reservation * [m_capacity - 1];
			for (size_t i = 0, j = 0; i < m_capacity && j < (m_capacity - 1); i++) {
				if (i != (size_t)indexNum) {
					temp.m_res[j++] = m_res[i];
					m_size = j;
				}
 			}
			m_capacity--;
			delete[] m_res;
			m_res = new const Reservation * [m_capacity];

			for (size_t i = 0; i < m_capacity; i++)
				m_res[i] = (Reservation*)temp.m_res[i];
 			/*Reservation** tempData = new Reservation * [m_size];
			for (int i = 0; i < m_size; i++) {
				if (i == indexNum) tempData[i] = nullptr;
				else tempData[i] = m_res[i];
			}
			if (m_size < m_capacity) {
				for (int i = 0, j = 0; i < m_size && j < m_size - 1; i++)
					if (tempData[i] != nullptr) m_res[j++] = tempData[i];	
			}
			else {
				resize(--m_capacity);
				
				for (int i = 0, j = 0; i < m_size && j < m_size - 1; i++)
					if (tempData[i] != nullptr) m_res[j++] = tempData[i];*/
					
		}
		return *this;
	}
	ostream& operator << (std::ostream& os, const ConfirmationSender& cf){
		os << "--------------------------" << endl
			<< "Confirmations to Send" << endl
			<< "--------------------------" << endl;
		if (cf.m_size == 0) os << "There are no confirmations to send!" << endl;
		else {
			for(size_t i = 0; i < cf.m_size; i++)
			os << *cf.m_res[i];
		}
		os << "--------------------------" << endl;
		return os;
		
	}
}