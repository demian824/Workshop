#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "PreTriage.h"
#include "utils.h"
using namespace std;
using namespace sdds;
void displayFile(const char* fname) {
	ifstream fin(fname);
	char ch;
	cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
	while (fin.get(ch)) cout << ch;
	cout << "***************************************************" << endl << endl;
}
void fp1tester() {
	sdds::debug = true;
	PreTriage P("data.csv");
	P.run();
}
void fp2tester() {
	sdds::debug = true;
	PreTriage P("smalldata.csv");
	P.run();
}
void fp3tester() {
	sdds::debug = true;
	PreTriage P("bigdata.csv");
	P.run();
	cout<<"" << endl;
}
int main() {
	//_CrtSetBreakAlloc(1284);
	//
	//fp1tester();
	//displayFile("data.csv");
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*fp3tester();
	displayFile("bigdata.csv");
	*/
	fp2tester();
	displayFile("smalldata.csv");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	return 0;
	
}