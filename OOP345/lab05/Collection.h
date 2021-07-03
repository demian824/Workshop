/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week5
*/
/************************************
	* File Name:			Collection.h
	* Included Header/Library
	*	iostream
	*	string
	*	memory
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once
#include <string>
#include <iostream>
#include <memory>

namespace sdds {
	/************************************
		* Class Name:			Collection
		* Member Variable:		m_name, m_item, m_size, m_fcptr
		* Member Variable type: string, T, size_t, void()(const Collection<T>&, const T&);
		* Constructor:			Collection(const std::string& name)
		* Destructor:			defualt
		* Member Function:
		*	isCompatibleWith(const PairSummable<V, K>& b)
		*	 name()
		*	 size()
		*	 setObserver(void (*observer)(const Collection<T>&, const T&))
		* Overloading:			operator+=
		*						operator[]
		************************************/
	template <typename T>
	class Collection {
		std::string m_name;
		T* m_item;
		size_t m_size;
		void(*m_fcptr)(const Collection<T>&, const T&);
	public:
		~Collection() { delete[] m_item; }
		Collection(const std::string& name)
			: m_name(name), m_item(nullptr), m_size(1), m_fcptr(nullptr) {}
		/************************************
		* Function prototype:		const std::string& name() const
		* Function Name:			name
		* Function type:			const std::string&
		* Function Parameter:		NONE
		* Parameter type:			NONE
		* Discription:				return m_name from Collection class
		************************************/
		const std::string& name() const { return m_name; }
		/************************************
		* Function prototype:		size_t size() const
		* Function Name:			size()
		* Function type:			size_t
		* Function Parameter:		NONE
		* Parameter type:			NONE
		* Discription:				return m_size from Collection class
		************************************/
		size_t size() const { return m_size; }
		/************************************
		* Function prototype:		void setObserver(void (*observer)(const Collection<T>&, const T&))
		* Function Name:			setObserver
		* Function type:			void
		* Function Parameter:		NONE
		* Parameter type:			NONE
		* Discription:				Assign function pointer to m_fcptr in Collection class
		************************************/
		void setObserver(void (*observer)(const Collection<T>&, const T&)) { m_fcptr = observer; }
		/************************************
		* Function prototype:		Collection<T>& operator+=(const T& item)
		* Function Name:			operator+=
		* Function type:			Collection<T>&
		* Function Parameter:		item
		* Parameter type:			const T&
		* Default Parameter:		NONE
		* Return value/variable:	*this
		* Discription:				add new data into m_item in Collection class
		************************************/
		Collection<T>& operator+=(const T& item) {
			bool isFound = false;
			size_t index = item.isMovie() == true ? 2 : 3;
			if (!m_item) {
				m_item = new T[m_size];
				m_item[0] = item;
			}
			else {
				for (size_t i = 0; i < m_size && !isFound; i++)
					if (m_item[i].title() == item.title()) 	isFound = true;

				if (!isFound) {
					T* temp = new T[m_size];
					for (size_t i = 0; i < m_size; i++)
						temp[i] = m_item[i];
					delete[] m_item;
					m_item = new T[m_size + 1];
					for (size_t i = 0; i < m_size; i++) 
						m_item[i] = temp[i];
					m_item[m_size++] = item;
					if (m_size - 1 > index)	m_fcptr(*this, m_item[m_size - 1]);
					delete[] temp;
				}
			}
			return *this;
		}
		/************************************
		* Function prototype:		T& operator[](size_t idx) const
		* Function Name:			operator[]
		* Function type:			T&
		* Function Parameter:		idx
		* Parameter type:			size_t
		* Default Parameter:		NONE
		* Return value/variable:	m_item[idx]
		* Discription:				return m_item following by index
		************************************/
		T& operator[](size_t idx) const {
			if (idx >= m_size) 
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			return m_item[idx];
		}
		/************************************
		* Function prototype:		T* operator[](const std::string& title) const
		* Function Name:			operator[]
		* Function type:			T*
		* Function Parameter:		title
		* Parameter type:			const std::string&
		* Default Parameter:		NONE
		* Return value/variable:	m_item[idx]
		* Discription:				search the title in the data and return the address of data.
		************************************/
		T* operator[](const std::string& title) const {
			size_t index = 0;
			for (size_t i = 0; i < m_size; i++) {
				index = m_item[i].title().find(title);
				if (index != std::string::npos) {
					index = i;
					break;
				}
			}
			if (index != std::string::npos) return std::addressof(m_item[index]);
			else return nullptr;
		}
		/************************************
		* Function prototype:		friend std::ostream& operator << (std::ostream& os, const Collection<T>& data)
		* Function Name:			operator <<
		* Function type:			std::ostream&
		* Function Parameter:		os, data
		* Parameter type:			std::ostream&, const Collection<T>&
		* Default Parameter:		NONE
		* Return value/variable:	os
		* Discription:				print m_item.
		************************************/
		friend std::ostream& operator << (std::ostream& os, const Collection<T>& data) {
			for (size_t i = 0; i < data.m_size; i++)
				os << data.m_item[i];
			return os;
		}

	};
}
