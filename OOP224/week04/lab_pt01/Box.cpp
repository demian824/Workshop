/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week04_PT1
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Box.h"

namespace sdds {
	
	using namespace std;
	typedef Box b;
	//private member functions
	void b::setName(const char* Cstr) {
		if (Cstr != nullptr) {
			int size = strlen(Cstr) + 1;
			m_contentName = new char[size];
			if (m_contentName == nullptr) {
				cout << "fail to memory allocation" << endl;
				exit(1);
			}
			strcpy(m_contentName, Cstr);
			if (strcmp(m_contentName, Cstr) != 0) {
				cout << "fail to copy string" << endl;
				exit(1);
			}
		}
		else
			m_contentName = nullptr;
	}
	void b::setUnusable() {
		if (!m_contentName) {
			delete[] m_contentName;
		}
		m_contentName = nullptr;
		m_height = -1;
		m_width = -1;
		m_length = -1;
		m_contentVolume = -1;
	}
	bool b::isUnusable()const {
		bool ok = false;
		if ((m_contentName == nullptr) && (m_contentVolume == -1))
			if ((m_height == -1) && (m_width == -1) && (m_length == -1))
				ok = true;
		return ok;
	}
	bool b::hasContent()const {
		bool ok = false;
		int maxCa = capacity();
		if (maxCa >= m_contentVolume && m_contentVolume >= 0)
			ok = true;
		return ok;
	}
	//public member functions
	b::Box(int sideLength, const char* contentName)
		: m_contentName(nullptr), m_width(sideLength), m_height(sideLength), m_length(sideLength), m_contentVolume(0)
	{
		
		if (sideLength < 5 || sideLength > 36)
			setUnusable();
	
		setName(contentName);
	
	}
	b::Box(int width, int height, int length, const char* contentName)
		: m_contentName(nullptr), m_width(width), m_height(height), m_length(length), m_contentVolume(0)
	{  
		setName(contentName);

		if (width < 5 || width > 36)
			setUnusable();
		else if (height < 5 || height > 36)
			setUnusable();
		else if (length < 5 || length > 36) 
			setUnusable();
	}
	b::~Box() {
		delete[] m_contentName;
		m_contentName = nullptr;
	}
	int b::capacity() const {
		return m_width * m_height * m_length;
	}
	int b::quantity()const {
		return m_contentVolume;
	}
	Box& b::setContent(const char* contentName) {
		if(m_contentName != NULL)
			delete[] m_contentName;
		setName(contentName);
		return *this;
	}
	Box& b::add(int quantity) {
		m_contentVolume = quantity;
		return *this;
	}
	Box& b::add(Box& B) {
		if (m_contentName == nullptr || quantity() == 0) 
			setContent(B.m_contentName);
		
		if (strcmp(m_contentName, B.m_contentName) == 0) {
			if (quantity() + B.quantity() <= capacity()) {
				add(B.quantity());
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
				m_contentVolume = capacity();
			}
		}
		else {
			if (quantity() + B.quantity() <= capacity()) 
				B.m_contentVolume = 0;
			else 
				B.m_contentVolume -= (capacity() - quantity());
			
			setUnusable();
		}
		return *this;
	}
	std::ostream& b::display()const {
		bool ok = isUnusable();
		bool quan = hasContent();
		
		if(!quan)
			return cout << "Unusable box, discard the content, and recycle.";
		else if (!ok) {
			if (m_contentName == NULL)
			{
				return cout << left << setw(30) << setfill('.') << "Empty box" << "  "
					<< right << setw(2) << setfill('0') << m_width << "x" << setw(2) << m_height << "x" << setw(2) << m_length << "  "
					<< right << setw(6) << setfill(' ') << quantity() << "/" << capacity() << " C.I.";
			}
			else {
				return cout << left << setw(30) << setfill('.') << m_contentName << "  "
					<< right << setw(2) << setfill('0') << m_width << "x" << setw(2) << m_height << "x" << setw(2) << m_length << "  "
					<< right << setw(6) << setfill(' ') << quantity() << "/" << capacity() << " C.I.";
			}
		}
		else
			return cout << "Unusable box, discard the content, and recycle.";
	}
}; 