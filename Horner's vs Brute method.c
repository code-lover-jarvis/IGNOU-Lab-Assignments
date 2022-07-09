#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int i, j, x, deg, coeff[20], result = 0, no_of_mul = 0, no_of_add = 0, pro;
    system("cls");
    printf("Enter the value of x :\t");
    scanf("%d", &x);
    printf("\nEnter the degree of polynomial :\t");
    scanf("%d", &deg);
    printf("\nEnter the coefficients :\t");
    for(i = 0 ; i <= deg; i++)
    {
        scanf("%d", &coeff[i]);
        //Horner's Method
        result = result*x + coeff[i];
        ++no_of_add;
        ++no_of_mul;
    }
    printf("\n\tUsing Horner's Method\nResult is : %d\nNumber of Addition = %d\nNumber of Multiplication = %d", result, no_of_add, no_of_mul);

    // Brute force Method

    result = 0;
    no_of_mul = 0;
    no_of_add = 0;

    for(i = 0; i <= deg; i++)
    {
        pro = coeff[i];
        for(j = deg; j > i; j--)
        {
            pro *= x;
            ++no_of_mul;
        }
        result = result + pro;
        ++no_of_add;
    }
    printf("\n\n\tUsing Brute Force Method\nResult is : %d\nNumber of Addition = %d\nNumber of Multiplication = %d", result, no_of_add, no_of_mul);
    getch();
    return(0);
}
