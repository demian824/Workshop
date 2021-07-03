/*
	Student Name:		Wonchul Choi
	Student Nubmer:		118362201
	Student ID:	   	wchoi28
	Student e-mail: 	wchoi28@myseneca.ca
	Course:         	OOP244
	Workshop:	    	Week02_DIY
*/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_

namespace sdds {
	struct ACCOUNTINFO
	{
		unsigned int account;
		double balance;
	};
	bool load(const char* filename);
	bool loadAccount(unsigned int* account);
	bool loadBalance(double* balance);
	void sort();
	void display();
	void deallocateMemory();}
#endif // SDDS_ACCOUNT_