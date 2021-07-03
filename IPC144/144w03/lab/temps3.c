//==============================================
// Name:           Wonchul Choi
// Student Number: 118362201
// Email:          wchoi28@myseneca.ca
// Section:        Week02
// Workshop:       2 (at_lab)
//==============================================

#define NUMS 3
#include <stdio.h>
struct numbers
{
	int init_hnum[NUMS];
	int init_lnum[NUMS];

	int input_num1;
	int input_num2;
};

void print_avrg(int x[], int y[], int z);

int main()
{
	struct numbers nbs;
	int count = 0;

	puts("---=== IPC Temperature Analyzer ===---");

	while (count != NUMS)
	{
		printf("\nEnter the high value for day %d : ", count + 1);
		scanf("%d", &nbs.input_num1);

		if (nbs.input_num1 > 40 || nbs.input_num1 < -40)
		{
			while (nbs.input_num1 > 40 || nbs.input_num1 < -40)
			{
				printf("Incorrect value, temperatures must be in the range -40 to 40, high must be greater than low\n");
				printf("\nEnter the high value for day %d : ", count + 1);
				scanf("%d", &nbs.input_num1);
			}
			nbs.init_hnum[count] = nbs.input_num1;
		}
		else
			nbs.init_hnum[count] = nbs.input_num1;

		printf("\nEnter the low value for day %d : ", count + 1);
		scanf("%d", &nbs.input_num2);

		if (nbs.input_num2 > 40 || nbs.input_num2 < -40)
		{
			while (nbs.input_num2 > 40 || nbs.input_num2 < -40)
			{
				printf("Incorrect value, temperatures must be in the range -40 to 40, high must be greater than low\n");
				printf("\nEnter the low value for day %d : ", count + 1);
				scanf("%d", &nbs.input_num2);
			}
			nbs.init_lnum[count] = nbs.input_num2;
		}
		else
			nbs.init_lnum[count] = nbs.input_num2;

		count++;

	}

	print_avrg(nbs.init_hnum, nbs.init_lnum, count);


	return 0;
}

void print_avrg(int x[], int y[], int z)
{
	float havrg = 0;
	float lavrg = 0;

	for (z = 0; z < NUMS; z++)
	{
		havrg += x[z];
		lavrg += y[z];
	}
	printf("The average (mean) temperature was : %.2f                             \n", (havrg + lavrg) / (NUMS*2));

}
