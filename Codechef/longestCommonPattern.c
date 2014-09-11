#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char strA[10001],strB[10001];
	int testCases,lengthA,lengthB,i,count,*record;

	scanf("%d",&testCases);

	while(testCases--)
	{
		count=0;
		record=(int *)calloc(256,sizeof(int));
		scanf("%s",strA);
		scanf("%s",strB);
		lengthA=strlen(strA);
		lengthB=strlen(strB);

		for(i=0;i<lengthA;i++)
			record[strA[i]]++;
		
		for(i=0;i<lengthB;i++)
		{
			if(record[strB[i]]-->0)	
				count++;
		}
		printf("%d\n",count);
		free(record);
	}

	return 0;
}
