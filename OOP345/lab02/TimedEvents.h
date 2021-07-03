/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week2
*/
/************************************
	* File Name:			TimedEvents.h
	* Included Header/Library
	*	iostream
	*	chrono
	*	string
	*	iomanip
	* namespace:			sdds
	* preprocessor:
	*	#pragma once
	************************************/
#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>

namespace sdds {
	/************************************
		* Name: maxNum
		* Value: 10
		* Type:
		*	int
		*	const
		************************************/
	const int maxNum(10);
	/************************************
		* Class Name:			TimedEvents
		* Member Variable:		m_recordNum, m_startTime, m_stopTime, m_event[maxNum]
		* Member Variable type: int, char, std::chrono::steady_clock::time_point, std::chrono::steady_clock::time_point, struct
		* Constructor:			defualt
		* Member Function:
		*	startClock
		*	stopClock
		*	addEvent
		*	print
		* Overloading:			operator <<
		************************************/
	class TimedEvents{
		int m_recordNum;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_stopTime;
		struct {
			const char* m_eventName;
			const char* m_timeUnit;
			std::chrono::steady_clock::duration m_durEvent;
		} m_event[maxNum];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char *str);
		std::ostream& print(std::ostream& os) const;
		friend std::ostream& operator << (std::ostream& os, TimedEvents& te);
		
	};
}