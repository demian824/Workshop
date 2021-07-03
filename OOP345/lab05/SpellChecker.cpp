/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week5
*/
/************************************
	* File Name:				SpellChecker.cpp
	* Included Header/Library	
	*	SpellChecker.h
	*	fstream
	*	iomanip
	* namespace:				sdds
	************************************/
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
	/************************************
		* Constructor Name:		SpellChecker
		* Discription:			constructor
		************************************/
sdds::SpellChecker::SpellChecker(const char* filename)
{
	std::ifstream file(filename);
	if (!file) throw std::out_of_range("Bad file name!");
	else {
		int i = 0;
		std::string strData;
		size_t index;
		do {
			std::getline(file, strData);
			index = strData.find(' ');
			m_badWord[i] = strData.substr(0, index);
			for (size_t i = index; i < strData.length(); i++) 
				if (strData[i] != 32) {
					index = i;
					break;
				}
			m_goodWord[i++] = strData.substr(index);
			strData.erase();
		} while (file && i < LIMIT);
		file.close();
		for (int i = 0; i < LIMIT; i++) num[i] = 0;
	}	
}
/************************************
	* Function prototype:		void sdds::SpellChecker::operator()(std::string& text)
	* Function Name:			operator()
	* Function type:			void
	* Function Parameter:		text
	* Parameter type:			std::string&
	* Default Parameter:		NONE
	* Return value/variable:	NONE
	* Discription:				Find bad words and replace the good words
	************************************/
void sdds::SpellChecker::operator()(std::string& text)
{	
	for (size_t i = 0; i < LIMIT; i++) {
		size_t count = 0;
		size_t index = 0;
		
		while (true) {			
			index = text.find(m_badWord[i], index);
			if (index == std::string::npos) break;
			else {
				count++;
				text.replace(index, m_badWord[i].length(), m_goodWord[i]);
			}
		}
		num[i] += count;		
	}

}
/************************************
* Function prototype:		void sdds::SpellChecker::showStatistics(std::ostream& out) const
* Function Name:			showStatistics
* Function type:			void
* Function Parameter:		out
* Parameter type:			std::ostream&
* Discription:				Print the total number of replaced words and bad and good words each. 
************************************/
void sdds::SpellChecker::showStatistics(std::ostream& out) const
{
	out << "Spellchecker Statistics" << std::endl;
	for (int i = 0; i < LIMIT; i++) {
		out.setf(std::ios::right);
		out << std::setw(15) << m_badWord[i] << ": ";
		out << num[i] << " replacements" << std::endl;
	}	
}
