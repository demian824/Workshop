/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week04_PT2
*/
#define _CRT_SECURE_NO_WARNINGS
#include "NameTag.h"

namespace sdds {
	using namespace std;
	typedef NameTag nt;

	nt::NameTag(const char* name, const int number) {
		m_empName = new char[41]{ 0, };
		if (!m_empName) {
			cout << "Fail to memory allcation" << endl;
			exit(1);
		}
		m_extNum = -1;
		init(name, number);
	}
	nt::~NameTag() {
		delete[] m_empName;
		m_empName = nullptr;
	}
	void nt::init(const char* name, const int &number) {
		if (!name) 
			strcpy(m_empName, "empty");
		else {
			int size = checkSize(name);
			setName(name, size);
		}
		setNumber(number);
	}	
	void nt::setName(const char* name, const int size) {
		int i = 0;
		memset(m_empName, 0, 41);
		for (; i < size - 1; i++)
			m_empName[i] = name[i];
		m_empName[i] = '\0';
	}
	void nt::setNumber(const int& number) {
		if (number >= 10000 && number <= 99999)
			m_extNum = number;
		else 
			m_extNum = -1;
	}
	int nt::checkSize(const char* name) {
		int size = 0;
		if (name) {
			size = strlen(name) + 1;
			if (size > 41)
				size = 41;
		}
		return size;
	}
	bool nt::isValid()
	{
		bool isOk = true;
		if (m_empName == nullptr)
			isOk = false;
		else if (m_extNum < 10000 && m_extNum > 100000)
			isOk = false;			
		return isOk;
	}
	void nt::print() const {
		if ((strcmp(m_empName, "empty") == 0) || (strcmp(m_empName, "Bad number") == 0))
			cout << "EMPTY NAMETAG!" << endl;
		else {
			int size = strlen(m_empName);
			if (size > 0 && size <= 20) {
				size = 20;
				printStar(size);
				printSpace(size);
				cout << "* " << left << setw(size) << m_empName << " *" << endl;
				printSpace(size);
				printNum(size);
				printSpace(size);
				printStar(size);
			}
			else if (size <= 41 && size > 20) {
				printStar(size);
				printSpace(size);
				cout << "* " << m_empName << " *" << endl;
				printSpace(size);
				printNum(size);
				printSpace(size);
				printStar(size);
			}
		}
	}

	void nt::printStar(int size) const {
		for (int i = 0; i < size + 4; i++)
			cout << "*";
		cout << endl;
	}
	void nt::printSpace(int size) const {
		cout << "*";
		for (int i = 0; i < size + 2; i++)
			cout << " ";
		cout << "*" << endl;
	}
	void nt::printNum(int size) const {
		if (m_extNum == -1)
			cout << "* " << left << setw(size) << "Extension: N/A";
		else {
			int spaceWidth = size - 11;
			cout << "* " << "Extension: " << left << setw(spaceWidth) << m_extNum;
		}
		cout << " *" << endl;
	}
	NameTag& nt::read() {
		inputName();
		if (yesNo())
			inputNum();
		else
			m_extNum = -1;
		return *this;
	}
	void nt::inputName() {
		char	tempName[100];
		int		tempSize = 0,
				index = 0;
		cout << "Please enter the name: ";
		for (; index < 40; index++) {
			cin.get(tempName[index]);
			if (tempName[index] == '\n')
				break;
		}
		tempName[index] = '\0';
		if(index >=  40)
			cin.ignore(32767, '\n');
		tempSize = checkSize(tempName);
		setName(tempName, tempSize);
	}

	void nt::inputNum() {
		bool ok = false;
		int tempNum;
		cout << "Please enter a 5 digit phone extension: ";
		while (!ok) {
			cin >> tempNum;
			if (tempNum >= 10000 && tempNum <= 99999) {
				m_extNum = tempNum;
				ok = true;
				cin.ignore();
			}
			else
				cout << "Invalid value [10000<=value<=99999]: ";
		}
	}
	bool nt::yesNo() {
		bool ok = false;
		char	answer;
		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		while (true) {
			cin.get(answer);
			cin.ignore(32767, '\n');
			if (tolower(answer) == 'y') {
				ok = true;
				break;
			}
			else if (tolower(answer) == 'n')
				break;
			else
				cout << "input wrong character. Please input (Y)es / (N)o : ";
		}
		return ok;
	}
}