#include<stdio.h>
#include<string.h>
int main()
{
	char arr[200];
	int i,testCases,length,count;

	scanf("%d",&testCases);

	while(testCases--)
	{
		count=0;
		scanf("%s",arr);
		length=strlen(arr);
		for(i=0;i<length;i++)
		{

			if(arr[i]=='A'||arr[i]=='D'||arr[i]=='O'||arr[i]=='P'|| arr[i]=='Q'||arr[i]=='R')
				count+=1;
			else if(arr[i]=='B')
				count+=2;


		}
		printf("%d\n",count);

	}
	return 0;
}
