#pragma once
#include <iostream>
#include <cstring>
#//include"BarChart.h"

namespace sdds
{
	class Bar {
		char*	m_list	= nullptr;
		char	m_ch	= 0;
		int		m_size	= 0;

	public:
		bool isValid();
		void set(const char* string, const char &ch, const int &size);
		void draw();
		void printResult(int size, char ch);
		void deallocate();
	};
};