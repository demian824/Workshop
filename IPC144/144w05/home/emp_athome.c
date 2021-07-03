//==============================================
// Name:           Wonchul Choi
// Student Number: 118362201
// Email:          wchoi28@myseneca.ca
// Section:        Week05
// Workshop:       5 (at_home)
//==============================================


#include <stdio.h>
#include <stdlib.h>

#define SIZE 4


struct emp//structure emp
{
	int id_num;
	int age;
	float salary;
};


struct emp emp_arr[SIZE];//struct instance array
int count = 0;

void print_emp(struct emp x[])//print value function
{	
	puts("\nEMP ID  EMP AGE EMP SALARY");
	puts("======  ======= ==========");
	for (count = 0; count < SIZE; count++)
	{
		if (emp_arr[count].id_num != 0) //print data all
		{	
			printf("%6d  %7d %10.2f\n", emp_arr[count].id_num, emp_arr[count].age, emp_arr[count].salary);
		}

		else if (emp_arr[count].id_num == 0)
			continue;
				
	}
}
void add_emp(struct emp x[])//add function
{
	int next_index = 0;

	for (count = 0; count < SIZE; count++)
	{
		if (emp_arr[count].id_num == '\0')// check the array's memory
		{
			next_index = count;
			break;
		}

		else
			next_index = count;
	}

	puts("\nAdding Employee");
	puts("===============");

	if (emp_arr[next_index].id_num == '\0') // Left the memory
	{
		printf("Enter Employee ID: ");
		scanf("%d", &emp_arr[next_index].id_num);
		printf("Enter Employee Age: ");
		scanf("%d", &emp_arr[next_index].age);
		printf("Enter Employee Salary: ");
		scanf("%f", &emp_arr[next_index].salary);
	}

	else // fulfill memory
		puts("ERROR!!! Maximum Number of Employees Reached");
}


int update_salary(struct emp x[])//edit-salary function
{
	int index_num = 0;
	int flag = 0;
	int input_num1 = 0;
	float input_num2 = 0;

	puts("\nUpdate Employee Salary");
	puts("======================");
	do
	{
		printf("Enter Employee ID: ");
		scanf("%d", &input_num1);
		
		for (count = 0; count < SIZE; count++) // search id_num
		{
			if (x[count].id_num == input_num1)
			{
				flag = 1;
				break;
			}
		}

		if(flag == 0) // NO match any id_num
			puts("*** ERROR: Employee ID not found! ***");
		else
		{
			for (count = 0; count < SIZE; count++) // save array index
			{
				if (x[count].id_num == input_num1)
				{
					index_num = count;
					break;
				}
			}
		}
		
	} while(x[count].id_num != input_num1);

	printf("The current salary is %.2f", x[index_num].salary);
	printf("\nEnter Employee New Salary: ");
	scanf("%f", &input_num2);

	x[index_num].salary = input_num2; // change to new data

	return x[index_num].salary;
}

void remove_emp(struct emp x[])//delete information function
{
	int input_num = 0;
	int flag = 0;
	int index_num = 0;

	puts("\nRemove Employee");
	puts("===============");
	do
	{
		printf("Enter Employee ID: ");
		scanf("%d", &input_num);

		for (count = 0; count < SIZE; count++) // search the id_num
		{
			if (x[count].id_num != input_num)
				flag = 0;
			else if (x[count].id_num == input_num)
			{
				flag = 1;
				break;
			}
		}

		if(flag == 0) // NO match id
			puts("*** ERROR: Employee ID not found! ***");

		else
		{
			for (count = 0; count < SIZE; count++)
			{
				if (x[count].id_num == input_num)
				{
					index_num = count;
					break;
				}
			}
		}

	} while (x[count].id_num != input_num);
	
	printf("Employee %d will be removed\n", input_num);
	
	x[index_num].id_num = 0;
	x[index_num].age = 0;
	x[index_num].salary = 0;
}


int main()
{
	int selection = 0;

	puts("---=== EMPLOYEE DATA ===---");

	while (1)
	{
		//main menu
		puts("\n1. Display Employee Information");
		puts("2. Add Employee");
		puts("3. Update Employee Salary");
		puts("4. Remove Employee");
		puts("0. Exit");

		printf("\nPlease select from the above options: ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			print_emp(emp_arr);
			continue;
		case 2:
			add_emp(emp_arr);
			continue;
		case 3:
			update_salary(emp_arr);
			continue;
		case 4:
			remove_emp(emp_arr);
			continue;
		case 0:
			puts("\nExiting Employee Data Program. Good Bye!!!");
			exit(1);
			
		default:
			puts("\nERROR: Incorrect Option: Try Again");
			continue;
		}

	}

	return (0);
}

