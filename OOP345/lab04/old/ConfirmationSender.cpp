#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
	typedef ConfirmationSender CF;
	using namespace std;
	const int BASE_CAPACITY = 4;
	CF::~ConfirmationSender() { if(m_res) delete[] m_res; }
	CF::ConfirmationSender(){
		m_size = 0;
		m_capacity = BASE_CAPACITY;
		m_res = new Reservation * [m_capacity];
	}
	CF::ConfirmationSender(const ConfirmationSender& cf) { *this = cf; }
	CF::ConfirmationSender(ConfirmationSender&& cf) noexcept { *this = std::move(cf); }
	ConfirmationSender& CF::operator = (const ConfirmationSender& cf) {
		if (this != &cf) {
			m_size = cf.m_size;
			m_capacity = cf.m_capacity;
			if (m_size == 0 || m_size > m_capacity) m_res = nullptr;
			else {
				resize(m_capacity);
				for (int i = 0; i < m_size; i++)
					m_res[i] = (Reservation*)(cf.m_res[i]);
			}
		}
		return *this;
	}
	ConfirmationSender& CF::operator = (ConfirmationSender&& cf) noexcept {
		if (this != &cf && cf.m_res) {
			m_capacity = cf.m_capacity;
			m_size = cf.m_size;
			m_res = cf.m_res;
			cf.m_res = nullptr;
			cf.m_capacity = 0;
			cf.m_size = 0;
		}
		return *this;
	}
	bool CF::resize(const int& size) {
		if (size > 0) {
			if(m_res)delete[] m_res;
			m_capacity = size;
			m_res = new Reservation * [size];
		}
		else m_capacity = 0;
		return m_res ? true : false;
	}
	bool CF::searchData(const Reservation& res) const {
		bool isFind = false;
		if (m_res) 
			for (int i = 0; i < m_capacity && !isFind; i++)
				if (m_res[i] == &res) isFind = true;
		return isFind;
	}
	ConfirmationSender& CF::operator+=(const Reservation& res){
		bool isFind = searchData(res);
		bool isNull = res.isEmpty();
	
		
		if (m_size == 0 && isNull)
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
		}
		return *this;
	}
	ConfirmationSender& CF::operator-=(const Reservation& res){
		bool isFind = searchData(res);
		int indexNum = 0;
		if (isFind) {
			for (int i = 0; i < m_size; i++)
				if (m_res[i] == &res) indexNum = i;
			Reservation** tempData = new Reservation * [m_size];
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
					if (tempData[i] != nullptr) m_res[j++] = tempData[i];
			}
			delete[] tempData;
			--m_size;
		}
		return *this;
	}
	ostream& operator << (std::ostream& os, const ConfirmationSender& cf){
		os << "--------------------------" << endl
			<< "Confirmations to Send" << endl
			<< "--------------------------" << endl;
		if (cf.m_size == 0) os << "There are no confirmations to send!" << endl;
		else {
			for(int i = 0; i < cf.m_size; i++)
			os << *cf.m_res[i];
		}
		os << "--------------------------" << endl;
		return os;
		
	}
}