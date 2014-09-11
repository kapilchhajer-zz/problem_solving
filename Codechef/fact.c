#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr,temp,input1,input,testCases,i,j;
	
	scanf("%d",&testCases);

	while(testCases--)
	{
		arr=(int *)calloc(200,sizeof(int));
		scanf("%d",&input);
		if(input==0||input==1) 
		{
			printf("1\n");
			free(arr);
			continue;
		}
		i=0;
		input1=input;
		while(input1)
		{
			arr[i]=input1%10;
			input1=input1/10;
			i++;
		}

		input--;
		while(input!=1)
		{
			temp=0;
			for(j=0;j<i;j++)
			{	
				temp+=arr[j]*input;
				arr[j]=temp%10;
				temp=temp/10;
			}
			while(temp)
			{
				i++;
				arr[j]=temp%10;	
				j++;
				temp=temp/10;
			}
			input--;
		}

		for(j=i;j>0;j--)
			printf("%d",arr[j-1]);
		printf("\n");	
		free(arr);
	}
	return 0;
}
