/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Lab1
*/

/************************************
	* File Name:				event.cpp
	* Included Header/Library	event.h
	* namespace:				sdds
	* preprocessor:
	*	#define _CRT_SECURE_NO_WARNINGS
	*	#pragma oncevoid
	************************************/
#include "event.h"

namespace sdds {
	using namespace std;
	
	typedef Event E;
	//global variable in namespace
	unsigned int g_sysClock(0u);

	/************************************
	* Constructor Name:		Event
	* Discription:			Initialize memeber variables
	************************************/
	E::Event() : m_eventDesc(nullptr), m_flag('E'), m_time(0u){}

	/************************************
	* Constructor Name:		Event
	* Discription:			default destructor
	* Overloaded Function:	
	*	memoryDeallocation()
	************************************/
	E::~Event() { if (m_flag == 'A') memoryDeallcoation(); }

	/************************************
	* Function prototype:		void set(char* description)
	* Function Name:			set(char* description)
	* Function type:			void
	* Function Parameter:		description
	* Parameter type:			char*
	* Default Parameter:		nullptr
	* Return value/variable:	NONE
	* Discription:				set member variables
	* Overloaded Function:	
	*	strlen()
	*	strcmp()
	*	memoryDeallocation()
	************************************/
	void E::set(char* description) {
		if (description != nullptr) {
			if (m_flag != 'A') {
				m_time = g_sysClock;
				m_flag = 'S';
			}
			memoryDeallcoation();
			int m_length(strlen(description));
			m_eventDesc = new char[m_length + 1];
			strcpy(m_eventDesc, description);
			if (strcmp(description, m_eventDesc) != 0) { std::cout << "Failed to copy string" << std::endl; }
		}
		else {
			m_flag = 'E';
			memoryDeallcoation();
		}
	}	

	/************************************
	* Function prototype:		void memoryDeallcoation()
	* Function Name:			memoryDeallcoation()
	* Function type:			void
	* Function Parameter:		NONE
	* Parameter type:			NONE
	* Default Parameter:		NONE
	* Return value/variable:	NONE
	* Discription:				Deallocate allocated memory
	************************************/
	void E::memoryDeallcoation() {
		delete[] m_eventDesc;
		m_eventDesc = nullptr;
	}

	/************************************
	* Function prototype:		void memoryDeallcoation()
	* Function Name:			operator =
	* Function type:			Event&
	* Function Parameter:		origin
	* Parameter type:			Event& 
	* Default Parameter:		NONE
	* Return value/variable:	*this(reference of class instance)
	* Discription:				Overload assign operator '=' to copy the data from original data
	* Overloaded Function:		set()
	************************************/
	Event& E::operator = (Event& origin) {
		if (this == &origin) return *this;
		m_time = origin.m_time;
		m_flag = 'A';
		set(origin.m_eventDesc);
		
		return *this;
	}

	/************************************
	* Function prototype:		void printFormat(const int hours, const int mins, const int secs, const char* description) const
	* Function Name:			printFormat
	* Function type:			void
	* Function Parameter:		hours, mins, secs, description
	* Parameter type:			const int, const int, const int, const char*
	* Default Parameter:		NONE
	* Return value/variable:	NONE
	* Discription:				Print values following format to user
	* Overloaded Function:		NONE
	************************************/
	void E::printFormat(const int hours, const int mins, const int secs, const char* description) const {
		cout << std::setfill('0') << std::setw(2) << hours << ":" <<
			std::setfill('0') << std::setw(2) << mins << ":" <<
			std::setfill('0') << std::setw(2) << secs << " => " << description << endl;
	}

	/************************************
	* Function prototype:		void display()
	* Function Name:			display
	* Function type:			void
	* Function Parameter:		NONE
	* Parameter type:			NONE
	* Default Parameter:		NONE
	* Return value/variable:	NONE
	* Discription:				calculate the time from seconds
	*							if m_eventDesc is nullptr, it will print it;'| No Event |'.
	*							if m_eventDesc is not null call the function printFormat.
	*							if m_flag is 'A', it will call the function memoryDeallocation
	* Overloaded Function:
	*	setfill()
	*	setw()
	*	printFormat()
	************************************/
	void E::display() {
		static int count(1);
		int hour(m_time / 3600);
		int min((m_time / 60) - (hour * 60));
		int sec((m_time % 60));

		cout << std::setfill(' ') << std::setw(2) << count++ << ". ";
		if (!m_eventDesc) cout << "| No Event |" << endl;
		else printFormat(hour, min, sec, m_eventDesc);		
	}
}