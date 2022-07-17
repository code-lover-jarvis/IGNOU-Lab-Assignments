#include<stdio.h>
#include<conio.h>
struct item
{
	int id,w,p;
	float value;
};
void main()
{
	int i,j,w,p,tw=0,capacity,itemcount;
	float tv=0,partp;
	struct item K[50];
	clrscr();
	printf("\nenter count of items [maximum 50] and the maximum capacity of the bag \t");
	scanf("%d%d",&itemcount,&capacity);
	printf("enter,row-wise [one line per item],the serial number,the weight and the profit for each of the %d items \n",itemcount);
	for(i=0;i<itemcount;i++)
	scanf("%d%d%d",&K[i].id,&K[i].w,&K[i].p);
	for(i=0;i<itemcount;i++)
		K[i].value=(float)K[i].p/K[i].w;
	struct item KK;
	for(i=0;i<itemcount-1;i++)
	{
		for(j=0;j<itemcount-1-i;j++)
		{
			if(K[j+1].value>K[j].value)
			{
				KK=K[j+1];
				K[j+1]=K[j];
				K[j]=KK;
			}
		}
	}
	printf("The %d items arranged in nondescending order of the ratio Value=[Profit/Weight]is as under \n",itemcount);
	printf("\n\tValue\titem serial number \t Weight\tProfit\n");
	for(i=0;i<itemcount;i++)
		printf("\n\t%%0.2f \t\t %d \t\t %d \n",K[i].value,K[i].id,K[i].w,K[i].p);
		printf("\n");
		printf("The solution to the fractional knapsack problem\n\n");
		for(i=0;i<itemcount;i++)
		{
			if(K[i].w+tw<=capacity)
			{
				tw+=K[i].w;tv+=K[i].p;
				printf("\nSelected item %d [whole]\t\tWeight %d\t Profit %d\t\tCumulative Weight\t%d\tCumulative Value\t%0.2f\n\n",K[i].id,K[i].w,K[i].p,tw,tv);
			}
			else
			{
				w=capacity-tw;
				partp=(float)w*(float)K[i].p/(float)K[i].w;
				tw+=w;
				tv+=partp;
				printf("\nSelected item %d [part]\t\tWeight%d \t Profit %0.2f \t\tCumulative weight\t%d\tCumulative value \t%0.2f\n\n",K[i].id,w,partp,tw,tv);
				break;
			}
		}
	printf("\nThus the knapsack with a capacity of %d can hold items worth a Cumulative Total Value of \t%0.2f\n\n",tw,tv);
	printf("\n");
	getch();
}