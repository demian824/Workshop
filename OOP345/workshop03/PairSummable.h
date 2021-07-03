/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week3
*/
/************************************
	* File Name:			StringSet.h
	* Included Header/Library
	*	Pair.h
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once
#include "Pair.h"

namespace sdds {
	/************************************
		* Class Name:			PairSummable
		* Bass Class:			Pair<V, K>
		* Member Variable:		m_init, m_minWidth
		* Member Variable type: V, size_t
		* Constructor:			defualt, PairSummable(const K& key, const V& value = m_init)
		* Destructor:			defualt
		* Member Function:
		*	isCompatibleWith(const PairSummable<V, K>& b)
		*	display(std::ostream& os) - Virtual
		* Overloading:			operator+=
		************************************/
	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V m_init;
		static size_t m_minWidth;
	public:
		PairSummable() {}
		PairSummable(const K& key, const V& value = m_init)
			: Pair<V, K>(key, value) {
			if (m_minWidth < key.size())
				m_minWidth = key.size();
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const {	
			return this->key() == b.key() ? true : false; 	}
		PairSummable<V, K>& operator += (const PairSummable<V, K>& data) {
			const_cast<V&>(this->value()) += data.value();
			return *this;
		}
		void display(std::ostream& os) const override {
			os.setf(std::ios::left);
			os.m_widthField(m_minWidth);
			PairSummable<V, K>::Pair::display(os);
		}		
	};	
	
	template <typename V, typename K>
	V PairSummable<V, K>::m_init{};
	template <typename V, typename K>
	size_t PairSummable<V, K>::m_minWidth{};
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+= (const PairSummable<std::string, std::string>& data) {
		if (value() == m_init)  const_cast<std::string&>(value()) += data.value();
		else const_cast<std::string&>(value()) += ", " + data.value();
		return *this;
	}

}