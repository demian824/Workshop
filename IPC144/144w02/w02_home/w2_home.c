//==============================================
// Name:           Wonchul Choi
// Student Number: 118362201
// Email:          wchoi28@myseneca.ca
// Section:        Week02
// Workshop:       2 (at_home)
//==============================================


#include <stdio.h>

int main()
{
	FILE* fp = fopen("reflect.txt", "w");

	fprintf(fp, "\nNOTE:'");
	fprintf(fp, "\nFollowing the lecture I leared about variable type and simple calcuation");
	fprintf(fp, "\nAlso, I learned of comparison operators such as <, >, <=, >=, == ");
	fprintf(fp, "\nIn simple Arithmetic: +, -, *, /, %");
	fprintf(fp, "\nLearned change variable type that put ('typename') in front value where you want to change the type");
	fprintf(fp, "\nThe most important thing I think is address(&) operator in this lecture");
	fprintf(fp, "\nThe reason is that variable saved as address and address has strong relation with 'Array' and 'Pointer'");

	fclose(fp);

	return 0;
}

