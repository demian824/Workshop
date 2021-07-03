/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	Week04_PT1
*/


#include "Transcript.h"
using namespace sdds;
int main() {
	Transcript T;
	T.init("Fred Soley", 5);
	T.add("EAC150", 65);
	T.add("DBS211", 85);
	T.add("DCF255", 75);
	T.add("OOP244", 95);
	// Premature call to display will result an error
	T.display();
	T.add("WEB222", 100);
	// Proper and timely call to display transcript
	T.display();
	T.deallocate();
	return 0;
}