#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
   int a[20], n, i, j, cho, temp;
   system("cls");
   printf("Enter the number of Elemnts : ");
   scanf("%d", &n);
   printf("Enter the Elemnts : ");
   for(i = 0; i < n; i++)
   {
    scanf("%d", &a[i]);
   }
   printf("Choose\n1. Ascending\n2. Descending\n");
   scanf("%d", &cho);
   for(i = 0; i < n - 1; i++)
   {
    for(j = 0; j < n - i - 1; j++)
    {
        if(cho == 1)
        {
            if( a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        else
        {
            if( a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
   }
   printf("\n\nSorted array is : ");
   for(i = 0; i < n; i++)
   {
    printf("%d\t", a[i]);
   }
   getch();
   return(0);
}
