#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
   int a[20], n, i, j, cho, temp, xchange_count = 0, comparison_count = 0, inner_loop = 0, outer_loop = 0;
   system("cls");
   printf("Enter the number of Elemnts : ");
   scanf("%d", &n);
   printf("Enter the Elements : ");
   for(i = 0; i < n; i++)
   {
    scanf("%d", &a[i]);
   }
   printf("Choose\n1. Ascending\n2. Descending\n");
   scanf("%d", &cho);
   for(i = 0; i < n - 1; i++)
   {
    ++outer_loop;
    for(j = 0; j < n - i - 1; j++)
    {
        ++inner_loop;
        if(cho == 1)
        {
            if( a[j] > a[j + 1])
            {
                ++comparison_count;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                xchange_count += 3;
            }
        }
        else
        {
            if( a[j] < a[j + 1])
            {
                ++comparison_count;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                xchange_count += 3;
            }
        }
    }
   }
   printf("\n\nSorted array is : ");
   for(i = 0; i < n; i++)
   {
    printf("%d\t", a[i]);
   }
   printf("\nNumber of Exchange Operation : %d\nNumber of Comparison Operation : %d\nInner Loop : %d\nOuter Loop : %d", xchange_count, comparison_count, inner_loop, outer_loop);
   getch();
   return(0);
}
