#include <stdio.h>

int main()
{
	FILE* fp = fopen("reflect.txt", "w");

	fprintf(fp, "\nNOTE: I learn how to make a file");
	fprintf(fp, "\nAnd then see what keyword we used for it such as 'w' : write in file ");
	fprintf(fp, "\nAlso, I learned how to do input some value in the new file");
	fprintf(fp, "\nHence, I can look forward how to work of function from this exercise");

	fclose(fp);

	return 0;
}

