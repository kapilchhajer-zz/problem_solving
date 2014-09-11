#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *arr,i,arraySize,temp,noOfQuery,number,count,result;

	scanf("%d",&arraySize);
	arr=(int *)malloc(arraySize*sizeof(int));

	for(i=0;i<arraySize;i++)
		scanf("%d",&arr[i]);

	scanf("%d",&noOfQuery);
	
	while(noOfQuery--)
	{
		temp=count=result=0;
		scanf("%d",&number);
		
		for(i=0;i<arraySize;i++)
		{
			if(arr[i]>number)
			{
				count++;
				result+=temp;
			}
			else if(arr[i]<number)
			{
				temp=count=0;
			}
			else
			{
				count++;
				temp+=count;
				result+=temp;		
				count=0;
			}

		}
		printf("%d\n",result);
	}

	return 0;
}
