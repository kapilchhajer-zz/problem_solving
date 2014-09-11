#include<stdio.h>

int main(){
	
	int num,i,total,count;
	scanf("%d",&count);

	while(count--)
	{
		total=0;
		scanf("%d",&num);
		while(num)
		{
			total+=num/5;
			num=num/5;
		}
		printf("%d\n",total);
	}

	return 0;
}
