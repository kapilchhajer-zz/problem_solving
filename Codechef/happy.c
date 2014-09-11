#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int num1, int num2) 
{
   /* local variable declaration */
 
   if (num1 > num2)
      return num1;
   else
      return num2;
}
int main()
{
	int *array,*distance,num,arraySize,i,result,temp,temp1;
	result=INT_MAX;
	scanf("%d%d",&arraySize,&num);
	array=(int *)malloc(arraySize*sizeof(int));
	distance=(int *)malloc(1000001*sizeof(int));

	for(i=0;i<1000001;i++)
		distance[i]=INT_MAX;
	for(i=0;i<arraySize;i++)
	{
		scanf("%d",&array[i]);
		temp=array[i];
		if(i+1>arraySize-i)
		{
			if(distance[temp]>arraySize-i)
				distance[temp]=arraySize-i;
		}
		else
		{
			if(distance[temp]>i+1)
				distance[temp]=i+1;
		}
	}

	for(i=0;i<arraySize;i++)
	{
		temp=array[i];
		if(temp<num && temp!=num/2.0)
		{
			temp1=max(distance[temp],distance[num-temp]);
			if(temp1<result)
				result=temp1;
		}
	}
	if(result!=INT_MAX)
		printf("%d\n",result);
	else
		printf("-1\n");
	return 0;
}
