//==============================================
// Name:           Wonchul Choi
// Student Number: 118362201
// Email:          wchoi28@myseneca.ca
// Section:        Week05
// Workshop:       5 (at_Lab)
//==============================================

#include <stdio.h>
#include <stdlib.h>

#define SIZE 2

struct emp
{
	int id_num;
	int age;
	float salary;
};

struct emp emp_arr[SIZE];

void print_emp(struct emp x[])
{
	int count = 0;
	int temp = 0;

	for (count = 0; count < SIZE; count++)
	{
		if (x[count].id_num == 0)
		{
			temp = 0;
			break;
		}
		else
			temp = 1;
		
	}

	if (temp == 0)
	{
		puts("\nEMP ID  EMP AGE EMP SALARY");
		puts("======  ======= ==========");
	}
	if (temp != 0)
	{
		puts("\nEMP ID  EMP AGE EMP SALARY");
		puts("======  ======= ==========");
		for (count = 0; count < SIZE; count++)
		{
			printf("%6d  %7d %10.2f\n", emp_arr[count].id_num, emp_arr[count].age, emp_arr[count].salary);
		}
	}
}

void input_info(struct emp x[])
{
	int count = 0;
	int temp = 0;

	for (count = 0; count < SIZE; count++)
	{
		if (emp_arr[count].id_num == '\0')
		{
			temp = count;
			break;
		}

		else
			temp = count;
	}

	
	puts("\nAdding Employee");
	puts("===============");

	if (emp_arr[temp].id_num == '\0')
	{
		printf("Enter Employee ID: ");
		scanf("%d", &emp_arr[temp].id_num);
		printf("Enter Employee Age: ");
		scanf("%d", &emp_arr[temp].age);
		printf("Enter Employee Salary: ");
		scanf("%f", &emp_arr[temp].salary);
	}

	else
		puts("ERROR!!! Maximum Number of Employees Reached");
}


int main()
{
	int input_num1 = 0;
	

	puts("---=== EMPLOYEE DATA ===---");

	while (1)
	{
		puts("\n1. Display Employee Information");
		puts("2. Add Employee");
		puts("0. Exit");

		printf("\nPlease select from the above options: ");
		scanf("%d", &input_num1);

		switch (input_num1)
		{
		case 1:
			print_emp(emp_arr);
			continue;
		case 2:
			input_info(emp_arr);
			continue;
		case 0:
			puts("\nExiting Employee Data Program. Good Bye!!!");
			exit(1);
			break;
		default:
			puts("\nERROR: Incoreect Option: Try Again");
			continue;
		}

	}

	return (0);
}

