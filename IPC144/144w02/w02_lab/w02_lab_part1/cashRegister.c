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
    // I used float instead of double. double more accurate than float.
    // However, I want to make small size of program. That is why I use it.

    float input_Num;
    float decimal_Num, num;

    printf("Please enter the amount to be paid: $");
    scanf("%f", &input_Num);

    decimal_Num = input_Num - (int)input_Num;
    num = decimal_Num / 0.25;

    printf("\nLoonies required: %d, balance owing $%.2f", (int)input_Num, decimal_Num);
   
    decimal_Num = decimal_Num - ((int)num * 0.25);
    printf("\nQuartes required: %d, balance owing $%.2f", (int)num, decimal_Num);

    return 0;
}