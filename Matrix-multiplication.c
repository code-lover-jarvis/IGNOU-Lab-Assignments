#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int row1, col1, row2, col2, a[10][10], b[10][10], result[10][10], i, j, k, pro = 0, res = 0, //
    no_of_mul = 0, innermost_loop = 0, outermost_loop = 0;
    system("cls");
    printf("Enter the number of Rows of first Matrix: ");
    scanf("%d", &row1);
    printf("Enter the number of Columns of first Matrix: ");
    scanf("%d", &col1);
    printf("Enter the number of Rows of second Matrix: ");
    scanf("%d", &row2);
    printf("Enter the number of Columns of second Matrix: ");
    scanf("%d", &col2);
    if (col1 != row2)
    {
        printf("Column of First matrix and Row of Second Matrix are not equal.");
        getch();
        return(0);
    }
    printf("Enter the elements of first Matrix : ");
    for( i = 0; i < row1; i++)
    {
        for( j = 0; j < col1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("First matrix you entered is : \n");
    for( i = 0; i < row1; i++)
    {
        for( j = 0; j < col1; j++)
        {
            printf("\t%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("Enter the elements of Second Matrix : ");
    for( i = 0; i < row2; i++)
    {
        for( j = 0; j < col2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    printf("Second matrix you entered is : \n");
    for( i = 0; i < row2; i++)
    {
        for( j = 0; j < col2; j++)
        {
            printf("\t%d\t", b[i][j]);
        }
        printf("\n");
    }
    for( i = 0; i < row1; i++)
    {
        ++outermost_loop;
        for( j = 0; j < col2; j++)
        {
            for( k = 0; k < row2; k++)
            {
                ++innermost_loop;
                res += a[i][k] * b[k][j];
                ++no_of_mul;
            }
            result[i][j] = res;
            res = 0;
        }
    }
     printf("\n\nProduct matrix is : \n");
    for( i = 0; i < row2; i++)
    {
        for( j = 0; j < col2; j++)
        {
            printf("\t%d\t", result[i][j]);
        }
        printf("\n");
    }
    printf("\n\nNumber of Addition and Multiplication : %d\nInnermost loop count : %d\nOutermost loop count : %d\n", no_of_mul, innermost_loop, outermost_loop);
    getch();
    return(0);
}
