#include<stdio.h>
#include<conio.h>
void main()
{
int i, j, temp, count = 0;
clrscr();
printf("\nEnter first numbers : \t\n");
scanf("%d",&i);
printf("Enter Second number : \t\n");
scanf("%d",&j);
while(i>j && j != 0)
{
count += 1;
temp = i%j;
i = j;
j = temp;
}
printf("\nGCD is %d", i);
printf("\nNumber of mode %d\nand Assignment operation %d", count, count*2);
getch();
}