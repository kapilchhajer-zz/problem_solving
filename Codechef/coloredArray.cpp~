#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define gc() getchar_unlocked();

int read_int() {
    register char c = gc();
    while(c<'0' || c>'9') c = gc();
    int ret = 0;
    while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
    }
	return  ret;
}
int main()
{

	register int testCases;
	register int noOfColor,noOfCell,maxChangeInColor;
	testCases=read_int();
	while(testCases--)
	{	
		int i,j,maxProfit,maxProfitColor,temp,modification=0;
		int *currentColor,coloringCost,*profit,**coloringRevenue,max=0;
		noOfCell=read_int();
		noOfColor=read_int();
		maxChangeInColor=read_int();
		currentColor=(int *)malloc((noOfCell+1)*sizeof(int));
		coloringRevenue=(int **)malloc((noOfCell+1)*sizeof(int *));
		profit=(int *)malloc((noOfCell+1)*sizeof(int));

		for(i=0;i<=noOfCell;i++)
			coloringRevenue[i]=(int *)malloc((noOfColor+1) * sizeof(int));

		for(i=1;i<=noOfCell;i++)
			currentColor[i]=read_int();

		for(i=1;i<=noOfCell;i++)
		{	
			for(j=1;j<=noOfColor;j++)
				coloringRevenue[i][j]=read_int();
		}
		for(i=1;i<=noOfCell;i++)
		{	
			maxProfit=maxProfitColor=0;	
			for(j=1;j<=noOfColor;j++)
			{
				coloringCost=read_int();
				temp=coloringRevenue[i][j]-coloringCost;
				if(temp>maxProfit)
				{
					maxProfit=temp;
					maxProfitColor=j;
				}
			}

			if(maxProfitColor!=currentColor[i])
			{
				modification++;	
				profit[modification]=maxProfit-coloringRevenue[i][currentColor[i]];
			}
			
				max+=maxProfit;
			
		}
		
		sort(profit+1,profit+modification+1);
		for(i=1;i<=modification;i++)
		{
			if(i<=modification-maxChangeInColor || profit[i]<0)
			{
				max=max-profit[i];
			}
			else
				break;
		}
		
		printf("%d\n",max);
		free(currentColor);
		free(profit);
		for(i=0;i<=noOfCell;i++)
			free(coloringRevenue[i]);

		free(coloringRevenue);
	}
	return 0;

}
