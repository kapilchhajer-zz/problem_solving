#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *input,count,number;
	scanf("%d",&count);

	input=(int *)calloc(1000001,sizeof(int));
	while(count--)
	{
		scanf("%d",&number);
		input[number]++;
	}

	count=0;
	for(count=0;count<1000001;count++)
	{
		while(input[count]--)
			printf("%d\n",count);
	}


	return 0;
}
