#pragma once
#include <iostream>
#include <cstring>
#include "Bar.h"

namespace sdds
{
	class BarChart
	{
		Bar*	m_bar;
		char*	m_title;
		char	m_ch;
		int		m_size;
		int		m_indexNum;
	public:
		void init(const char* title, const int noOfSampels, const char fill);
		void add(const char* bar_title, const int value);
		void draw()const;
		void printBar()const;
		void deallocate();
	};
};