//==============================================
// Name:           Wonchul Choi
// Student Number: 118362201
// Email:          wchoi28@myseneca.ca
// Section:        Week02
// Workshop:       4 (at_home)
//==============================================


#include <stdio.h>

#define YES 1
#define NO 0

//structure
struct Temp
{
	int input_highNum;
	int input_lowNum;
};

struct Temp date_temp[10]; // array of instance of structure

//forward declatations
void print_result(int x, int y);
void minmax_temp(int x, int y);
int print_avrg(int x);
void inputAvrgtemp(int x);

int main()
{
	int day;
	int count = 0;
	int swit_num = YES;

	puts("---=== IPC Temperature Calculator V2.0 ===---");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	
	while (1)
	{
		scanf("%d", &day);//get day's value

		if (day < 3 || day > 10)
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		else
			break;
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
					swit_num = NO;
				else
					continue;
			}
		}
	count++; // increase count 
	} while (count != day); //do...while() condition

	//Call print value function
	print_result(count, day);
	minmax_temp(count, day);
	inputAvrgtemp(day);

	return 0;
}


void print_result(int x, int y)
{
	puts("\nDay  Hi  Low");
	for (x = 0; x < y; x++)
		printf("%d    %d    %d\n", x + 1, date_temp[x].input_highNum, date_temp[x].input_lowNum);
}

void minmax_temp(int x, int y)
{
	int max = 0;
	int min = 40;
	int date = 0;

	for (x = 0; x < y; x++)
	{
		if (date_temp[x].input_highNum > max)// Highest temperatrue
		{
			max = date_temp[x].input_highNum;
			date = x + 1;
		}
	}
	printf("\nThe highest temperature was %d, on day %d\n", max, date);

	for (x = 0; x < y; x++)// Lowest temperature
	{
		if (date_temp[x].input_lowNum < min)
		{
			min = date_temp[x].input_lowNum;
			date = x + 1;
		}
	}
	printf("The lowest temperature was %d, on day %d\n", min, date);

}

void inputAvrgtemp(int x)
{
	int date;
	int swit_num1 = YES;
	
	while (swit_num1)
	{
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", x);
		scanf("%d", &date);
		
		if (date > 0 && date <= x)
		{
			print_avrg(date);
		}

		else if (date == 0 || date > x)
		{
			while (1)
			{
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", x);
				scanf("%d", &date);

				if (date > 0 && date < x)
				{
					print_avrg(date);
					break;
				}

				else if (date == 0)
					continue;

				else
					continue;
			}
		}

		else
			break;
	}

	printf("\nGoodbye!\n");
	
}

int print_avrg(int x)
{
	int count = 0;
	float havrg = 0;
	float lavrg = 0;

	for (count = 0; count < x; count++)
	{
		havrg += date_temp[count].input_highNum;
		lavrg += date_temp[count].input_lowNum;
	}

	
	printf("\nThe average temperature up to day %d is: %.2f\n", x, (havrg + lavrg) / (x * 2));// // average temparture

	return x;
}
