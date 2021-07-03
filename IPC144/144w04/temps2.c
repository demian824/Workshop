//==============================================
// Name:           Wonchul Choi
// Student Number: 118362201
// Email:          wchoi28@myseneca.ca
// Section:        Week02
// Workshop:       4 (at_Lab)
//==============================================


#include <stdio.h>

//structure
struct Temp
{
	int input_highNum;
	int input_lowNum;
};

struct Temp date_temp[10]; // array of instance of structure

//forward declatations
void print_result(int x, int y);

int main()
{
	int day;
	int count = 0;
	int swit_num = 1;

	puts("---=== IPC Temperature Calculator V2.0 ===---");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	
	//get day's value
	scanf("%d", &day);
	
	//condition1. 3 <= day <= 10
	while (day < 3 || day > 10)
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &day);
	}
		
	printf("\n");
	do
	{
		//Input variables High temperature and Low temparaure
		printf("Day %d - High: ", count + 1);
		scanf("%d", &date_temp[count].input_highNum);

		printf("Day %d - Low: ", count + 1);
		scanf("%d", &date_temp[count].input_lowNum);

		//condition2. -40 < High_temp, low_temp < 40
		if ((date_temp[count].input_highNum < -40 || date_temp[count].input_highNum >40) || (date_temp[count].input_lowNum < -40 || date_temp[count].input_lowNum >40))
		{
			while (swit_num)
			{
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low");
				printf("Day %d - High: ", count + 1);
				scanf("%d", &date_temp[count].input_highNum);

				printf("Day %d - Low: ", count + 1);
				scanf("%d", &date_temp[count].input_lowNum);

				if ((date_temp[count].input_highNum > -40 || date_temp[count].input_highNum < 40) || (date_temp[count].input_lowNum > -40 || date_temp[count].input_lowNum < 40))
					break;
				else
					continue;
			}
		}

		//condition3. High temp > low temp
		if (date_temp[count].input_highNum < date_temp[count].input_lowNum)
		{
			while (swit_num)
			{
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low");
				printf("\nDay %d - High: ", count + 1);
				scanf("%d", &date_temp[count].input_highNum);

				printf("Day %d - Low: ", count + 1);
				scanf("%d", &date_temp[count].input_lowNum);

				if ((date_temp[count].input_highNum > -40 || date_temp[count].input_highNum < 40) || (date_temp[count].input_lowNum > -40 || date_temp[count].input_lowNum < 40))
					swit_num = 0;
				else
					continue;
			}
		}
	count++; // increase count 
	} while (count != day); //do...while() condition

	//Call print value function
	print_result(count, day);

	return 0;
}


void print_result(int x, int y)
{
	puts("\nDay  Hi  Low");
	for (x = 0; x < y; x++)
		printf("%d    %d    %d\n", x + 1, date_temp[x].input_highNum, date_temp[x].input_lowNum);
}