#pragma once
#include <string>
#include <iostream>
#include <typeinfo>

namespace sdds {
	template <typename T>
	class Collection {
		std::string m_name;
		T* m_item;
		size_t m_size;
		void(*m_fcptr)(const Collection<T>&, const T&);
		
	public:
		~Collection() { delete[] m_item;  }
		Collection(const std::string& name)
			: m_name(name), m_item(nullptr), m_size(1), m_fcptr(nullptr) {}
		const std::string& name() const { return m_name; }
		size_t size() const { return m_size; }
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			if (m_fcptr != observer) 
				m_fcptr = observer;
		}
		Collection<T>& operator+=(const T& item){
			bool isFound = false;
			size_t index = item.isMovie() ? 2 : 3 ;
						
			if (!m_item) {
				m_item = new T[m_size];
				m_item[0] = item;
			}
			else {
				for (size_t i = 0; i < m_size && !isFound; i++)
					if (m_item[i].title() == item.title()) 	isFound = true;

				if (!isFound) {
					T* temp = new T[m_size];
					for (size_t i = 0; i < m_size; i++) {
						temp[i] = m_item[i];
					}

					delete[] m_item;
					m_item = new T[m_size + 1];
					for (size_t i = 0; i < m_size; i++) {
						m_item[i] = temp[i];
					}

					m_item[m_size] = item;
					if (m_size> index)
						m_fcptr(*this, m_item[m_size]);
					m_size++;
					delete[] temp;
				}
				
			
			}
			return *this;
		}

		T& displayItem() { return m_item; }
		T& operator[](size_t idx) const { 
			if (idx >= m_size) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}
			return m_item[idx]; 
		}
		T* operator[](const std::string& title) const{
			size_t index = 0;

			for (size_t i = 0; i < m_size; i++) {
				index = m_item[i].title().find(title);
				if (index != std::string::npos) {
					index = i;
					break;
				}
			}

			if (index == std::string::npos) return nullptr;
			else return &m_item[index];
		}
		friend std::ostream& operator << (std::ostream& os, const Collection<T>& data) {
			for(size_t i = 0; i < data.m_size; i++)
				os << data.m_item[i] << std::endl;

			return os;
		}

	};
}
