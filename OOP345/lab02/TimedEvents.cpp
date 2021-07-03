/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week2
*/

/************************************
	* File Name:				TimedEvents.cpp
	* Included Header/Library	TimedEvents.h
	* namespace:				sdds
	************************************/
#include "TimedEvents.h"

namespace sdds {
	using namespace std;
	typedef TimedEvents TD;
	const char* UNIT ("nanoseconds");
	/************************************
	* Constructor Name:		Event
	* Discription:			default constructor
	************************************/
	TD::TimedEvents() {
		m_recordNum = 0;
		m_startTime = std::chrono::steady_clock::now();
		m_stopTime = std::chrono::steady_clock::now();
		for (int i = 0; i < maxNum; i++) {
			m_event[i].m_eventName = nullptr;
			m_event[i].m_timeUnit = UNIT;
			m_event[i].m_durEvent = static_cast<std::chrono::steady_clock::duration>(0ll);
		}
	}
	/************************************
	* Function prototype:		void startClock()
	* Function Name:			startClock
	* Function type:			void
	* Function Parameter:		NONE
	* Return value/variable:	NONE
	* Discription:				set m_startTime
	* Overloaded Function:
	*	std::chrono::steady_clock::now()
	************************************/
	void TD::startClock() { m_startTime = std::chrono::steady_clock::now(); }
	/************************************
	* Function prototype:		void stopClock()
	* Function Name:			stopClock
	* Function type:			void
	* Function Parameter:		NONE
	* Return value/variable:	NONE
	* Discription:				set m_stopTime
	* Overloaded Function:
	*	std::chrono::steady_clock::now()
	************************************/
	void TD::stopClock() { m_stopTime = std::chrono::steady_clock::now(); }
	/************************************
	* Function prototype:		void addEvent(const char* str)
	* Function Name:			addEvent
	* Function type:			void
	* Function Parameter:		str
	* Parameter type:			const char*
	* Return value/variable:	NONE
	* Discription:				set event name and duration
	************************************/
	void TD::addEvent(const char* str) {
		m_event[m_recordNum].m_eventName = str;
		m_event[m_recordNum].m_durEvent = static_cast<std::chrono::steady_clock::duration>(m_stopTime - m_startTime);
		if (m_recordNum < maxNum) m_recordNum++;
		else cout << "full" << endl;
	}
	/************************************
	* Function prototype:		ostream& print(ostream& os) const
	* Function Name:			print
	* Function type:			ostream&
	* Function Parameter:		os
	* Parameter type:			ostream&
	* Return value/variable:	os
	* Discription:				print formatted values
	* Overloaded Function:
	*	setf()
	*	setw()
	*	unsetf()
	************************************/
	ostream& TD::print(ostream& os) const {
		int index = 0;
		for (index = 0; index < m_recordNum; index++) {
			os.setf(ios::left);
			os << "  " << std::setw(23) << m_event[index].m_eventName << std::setw(10);
			os.setf(ios::right);
			os << std::chrono::duration_cast<std::chrono::nanoseconds>(m_event[index].m_durEvent).count()
				<< " " << m_event[index].m_timeUnit << endl;
			os.unsetf(ios::right);
		}
		return os;
	}
	/************************************
	* Operator prototype:		std::ostream& operator << (std::ostream& os, TimedEvents& te)
	* Overloading operator:		operator <<
	* Operator type:			std::ostream&
	* Operator Parameter:		os, te
	* Parameter type:			std::ostream&, TimedEvents& 
	* Return value/variable:	os
	* Discription:				print format / chaining
	* Overloaded Function:
	*	ostream& print(ostream& os) const
	************************************/
	std::ostream& operator << (std::ostream& os, TimedEvents& te) {
		os << "--------------------------" << endl
			<< "Execution Times:" << endl
			<< "--------------------------" << endl;
		te.print(os);
		os << "--------------------------" << endl;
		return os;
	}
}