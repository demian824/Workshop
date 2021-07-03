#include <stdio.h>
#define NUMS 4

struct numbers // structure
{
	int init_hnum[NUMS]; // high temperature array
	int init_lnum[NUMS]; // low temperature array

	int input_num1; // high temperature value
	int input_num2; // low temperature value
};

void print_avrg(int x[], int y[], int z); //print Function
void comp_temp(int x[], int y[], int z); //print max and min temperature
int reinput_htemp(int x, int y); // re-input high temperature function
int reinput_ltemp(int x, int y); // re-input high temperature function

int main()
{
	struct numbers nbs; // make instance of structure
	int count = 0; // count variable

	puts("---=== IPC Temperature Analyzer ===---");

	while (count != NUMS)// while loop
	{

		printf("Enter the high value for day %d: ", count + 1);
		scanf("%d", &nbs.input_num1); //get input value high temperature


		printf("\nEnter the low value for day %d: ", count + 1);
		scanf("%d", &nbs.input_num2); //low input value high temperature
		
		printf("\n");
		if (nbs.input_num1 > nbs.input_num2)
		{
			if (nbs.input_num1 > 40 || nbs.input_num1 < -40) // Check the input_num1 and save in to array
			{
				reinput_htemp(nbs.input_num1, count);// re-type input numbers if it is not feet on condition.
				nbs.init_hnum[count] = nbs.input_num1;
			}
			else
				nbs.init_hnum[count] = nbs.input_num1;



			if (nbs.input_num2 > 40 || nbs.input_num2 < -40)// Check the input_num and2 save in to array
			{
				reinput_ltemp(nbs.input_num2, count); //re-type input numbers if it is not feet on condition.
				nbs.init_lnum[count] = nbs.input_num2;
			}
			else
				nbs.init_lnum[count] = nbs.input_num2;

		}
		else if(nbs.input_num1 < nbs.input_num2)
		{
			int x = 0;
			while (x == 0)
			{
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");

				printf("Enter the high value for day %d: ", count + 1);
				scanf("%d", &nbs.input_num1); //get input value high temperature

				printf("\nEnter the low value for day %d: ", count + 1);
				scanf("%d", &nbs.input_num2); //low input value high temperature
				
				if (nbs.input_num1 > nbs.input_num2)
				{
					if (nbs.input_num1 > 40 || nbs.input_num1 < -40) // Check the input_num1 and save in to array
					{
						reinput_htemp(nbs.input_num1, count);// re-type input numbers if it is not feet on condition.
						nbs.init_hnum[count] = nbs.input_num1;
					}
					else
						nbs.init_hnum[count] = nbs.input_num1;
					if (nbs.input_num2 > 40 || nbs.input_num2 < -40)// Check the input_num and2 save in to array
					{
						reinput_ltemp(nbs.input_num2, count); //re-type input numbers if it is not feet on condition.
						nbs.init_lnum[count] = nbs.input_num2;
					}
					else
						nbs.init_lnum[count] = nbs.input_num2;
					printf("\n");
					x = 1;
				}
				else continue;
			}
		}
		count++; // increasment

	}

	print_avrg(nbs.init_hnum, nbs.init_lnum, count);
	comp_temp(nbs.init_hnum, nbs.init_lnum, count);


	return 0;
}


int reinput_htemp(int x, int y)
{
	while (x > 40 || x < -40)
	{

		printf("Incorrect value, temperatures must be in the range -40 to 40, high must be greater than low\n");

		printf("Enter the high value for day %d: ", y + 1);
		scanf("%d", &x);
	}

	return x;
}

int reinput_ltemp(int x, int y)
{
	while (x > 40 || x < -40)
	{

		printf("Incorrect value, temperatures must be in the range -40 to 40, high must be greater than low\n");

		printf("Enter the low value for day %d: ", y + 1);
		scanf("%d", &x);
	}

	return x;
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

	printf("The average (mean) LOW temperature was: %.2f\n", lavrg / NUMS);// average of low temparature
	printf("The average (mean) HIGH temperature was: %.2f\n", havrg / NUMS);// average of high temparature
	printf("The average (mean) temperature was: %.2f\n", (havrg + lavrg) / (NUMS * 2));// // average temparture


}

void comp_temp(int x[], int y[], int z)
{
	int max = 0;
	int min = 40;
	int day = 0;

	for (z = 0; z < NUMS; z++)
	{
		if (x[z] > max)// Highest temperatrue
		{
			max = x[z];
			day = z + 1;
		}
	}
	printf("The highest temperature was %d, on day %d\n", max, day);

	for (z = 0; z < NUMS; z++)// Lowest temperature
	{
		if (y[z] < min)
		{
			min = y[z];
			day = z + 1;
		}
	}
	printf("The lowest temperature was %d, on day %d\n", min, day);

}

