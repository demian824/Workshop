/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week2
*/

/************************************
	* File Name:				StringSet.cpp
	* Included Header/Library	StringSet.h
	* namespace:				sdds
	************************************/
#include "StringSet.h"

namespace sdds{
	typedef StringSet SS;
	using namespace std;
	
	/************************************
	* Constructor Name:		Event
	* Discription:			default constructor
	************************************/
	SS::StringSet():m_ele(nullptr), m_count(0ull){}
	/************************************
	* Constructor Name:		Event
	* Discription:			constructor
	************************************/
	SS::StringSet(const char* filename) {
		ifstream ifs;
		if (!filename) m_count = 0u;
		else{
			std::string temp;
			ifs.open(filename);
			if (ifs.is_open()) {
				while (std::getline(ifs, temp, ' ')) m_count++;
				ifs.close();
			}
			else  cout << "Failed to open the file";

			if (m_ele) delete m_ele;
			m_ele = new string[m_count];
			if (!m_ele) cout << "Failed to memeory allocation" << endl;
			
			ifs.open(filename);
			if (ifs.is_open()) {
				size_t index(0ull);
				while (std::getline(ifs, temp, ' ')) {
					m_ele[index++] = temp;
					if (index >= m_count) break;
				}
				ifs.close();
			}
			else  cout << "Failed to open the file";
		}
	}
	/************************************
	* Constructor Name:		Event
	* Discription:			copy constructor
	************************************/
	SS::StringSet(const StringSet& origin) { *this = origin; }
	/************************************
	* Constructor Name:		Event
	* Discription:			move constructor
	************************************/
	SS::StringSet(StringSet&& origin) { *this = std::move(origin); }
	std::string SS::operator[](size_t index) {
		if (index < m_count && m_ele != nullptr)	return m_ele[index];
		else return "";		
	}
	/************************************
	* Destructor Name:		~StringSet
	* Discription:			deallocate memory
	************************************/
	SS::~StringSet() { delete[] m_ele; }
	/************************************
	* Function prototype:		StringSet& SS::operator=(const StringSet& origin)
	* Function Name:			operator =
	* Function type:			StringSet&
	* Function Parameter:		origin
	* Parameter type:			const StringSet& 
	* Default Parameter:		NONE
	* Return value/variable:	*this(reference of class instance)
	* Discription:				Overload assign operator '=' to copy the data from original data
	************************************/
	StringSet& SS::operator=(const StringSet& origin){
		if (this != &origin) {
			m_count = origin.m_count;
			//m_ele = origin.m_ele; //shallow copy

			if (m_ele) delete[] m_ele;
			m_ele = new std::string[m_count];
			for (size_t i = 0; i < m_count; i++)//deep copy
				m_ele[i] = origin.m_ele[i];
		}
				return *this;
	}
	/************************************
	* Function prototype:		StringSet& SS::operator=(StringSet&& origin)
	* Function Name:			operator =
	* Function type:			StringSet&
	* Function Parameter:		origin
	* Parameter type:			StringSet&&
	* Default Parameter:		NONE
	* Return value/variable:	*this(reference of class instance)
	* Discription:				Overload assign operator '=' to move the data from original data
	************************************/
	StringSet& SS::operator=(StringSet&& origin){
		if (this != &origin) {
			m_count = origin.m_count;
			if (m_ele) delete[] m_ele;
			m_ele = origin.m_ele;
			origin.m_ele = nullptr;
		}
		return *this;
	}
	/************************************
	* Function prototype:		size_t SS::size()
	* Function Name:			size
	* Function type:			size_t
	* Function Parameter:		NONE
	* Return value/variable:	m_count
	* Discription:				return m_count
	************************************/
	size_t SS::size() { return m_count; }
}