/*
	Student Name:		Wonchul Choi
	Student Nubmer:		118362201
	Student ID:	   	wchoi28
	Student e-mail: 	wchoi28@myseneca.ca
	Course:         	OOP244
	Workshop:	    	Week02_DIY
*/

#include <iostream>
#include <cstdio>
#include "Account.h"
#include "File.h"

using namespace std;
namespace sdds 
{
	int numOfdata;
	ACCOUNTINFO* info;

	bool load(const char* filename)
	{
		bool succes = false;
		if (!openFile(filename))
		{
			cout << "Failed to open the file" << endl;
			exit(1);
		}
		else
		{
			numOfdata = noOfRecords();
			if (numOfdata <= 0)
			{
				cout << "Failed to count the data" << endl;
				exit(1);
			}
			else
				info = new ACCOUNTINFO[numOfdata];


			for (int i = 0; i < numOfdata; i++)
			{
				if (!loadAccount(&info[i].account))
				{
					cout << "failed to load data" << endl;
					exit(1);
				}
				else
				{
					if (!loadBalance(&info[i].balance))
					{
						cout << "failed to load data" << endl;
						exit(1);
					}
					else
						succes = true;
				}
			}
			closeFile();
			return succes;
		}
	}

	bool loadAccount(unsigned int* accNum)
	{
		bool succes = false;

		if (!readAccount(accNum))
		{
			cout << "failed the load account" << endl;
			exit(1);
		}
		else
			succes = true;

		return succes;

	}

	bool loadBalance(double* balance)
	{
		bool succes = false;

		if (!readBalance(balance))
			cout << "failed the load Number" << endl;
		else
			succes = true;
		return succes;
	}

	void sort()
	{
		int i, j;
		ACCOUNTINFO temp;
		for (i = numOfdata - 1; i > 0; i--)
			for (j = 0; j < i; j++)
				if (info[j].balance > info[j + 1].balance)
				{
					temp = info[j];
					info[j] = info[j + 1];
					info[j + 1] = temp;
				}
	}

	void display()
	{
		sort();
		cout << "Account#: Balance" << endl;
		for (int i = 0; i < numOfdata; i++)
			printf("%d: %u:  %g\n", i + 1, info[i].account, info[i].balance);	
	}
	void deallocateMemory()
	{
		delete[] info;
	}

}