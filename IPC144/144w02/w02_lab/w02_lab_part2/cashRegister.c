////==============================================
//// Name:           Wonchul Choi
//// Student Number: 118362201
//// Email:          wchoi28@myseneca.ca
//// Section:        Week02
//// Workshop:       2 (at_home)
////==============================================

#include <stdio.h>

int main()
{
    //This time, I used double instead of float because I made previous one with float

    double input_Num;
    double decimal_Num;
    double qua_Num;
    double dim_Num;
    double nic_Num;
    double pen_Num;

    printf("Please enter the amount to be paid: $");
    scanf("%lf", &input_Num);

    input_Num = (input_Num * 1.13) + .005;
    decimal_Num = input_Num - (int)input_Num;
    
  

    printf("\nGST: 1.13");
    printf("\nLoonies required: %d, balance owing $%.2lf", (int)input_Num, decimal_Num);

    qua_Num = decimal_Num / .25;
    decimal_Num = decimal_Num - ((int)qua_Num * 0.25);
    printf("\nQuartes required: %d, balance owing $%.2lf", (int)qua_Num, decimal_Num);

    dim_Num = decimal_Num / .1;
    decimal_Num = decimal_Num - ((int)dim_Num * 0.1);
    printf("\nDimes required: %d, balance owing $%.2lf", (int)dim_Num, decimal_Num);

    nic_Num = decimal_Num / .05;
    decimal_Num = decimal_Num - ((int)nic_Num *.05);
    printf("\nNickles required: %d, balance owing $%.2lf", (int)nic_Num, decimal_Num);

    pen_Num = decimal_Num / .01;
    printf("\nPennies required: %d, balance owing 0\n", (int)pen_Num);

    return 0;
}