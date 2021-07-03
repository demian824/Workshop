#define _CRT_SECURE_NO_WARNINGS
#include "Bar.h"

using namespace std;

namespace sdds
{
	typedef Bar b;

	bool b::isValid() {
		bool valid = false;
		
		if (m_size <= 100 && m_size >= 0)
			valid = true;
		else
			cout << "Input Wrong Number" << endl;

		return valid;
	}

	void b::set(const char* string, const char &ch, const int &size){
		
		m_list = new char[20]{0,};
		m_size = size;
		m_ch = ch;

		if (m_list == nullptr) {
			cout << "fail to memery allocation" << endl;
			exit(1);
		}
 		strcpy(m_list, string);
	}

	void b::draw(){
		
		int e_strLen = 20 - strlen(m_list);
		if (isValid()) {
			cout << m_list;
			printResult(e_strLen, '.');
			cout << "|";
			printResult(m_size / 2, m_ch);
			cout << endl;
		}
		deallocate();
	}

	void b::printResult(int size, char ch){
		for (int i = 0; i < size; i++)
			cout << ch;
	}

	void b::deallocate() {
		delete[] m_list;
		m_list = nullptr;
	}

};